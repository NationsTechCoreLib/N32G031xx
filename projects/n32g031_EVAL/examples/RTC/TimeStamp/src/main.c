/*****************************************************************************
 * Copyright (c) 2019, Nations Technologies Inc.
 *
 * All rights reserved.
 * ****************************************************************************
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Nations' name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY NATIONS "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL NATIONS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ****************************************************************************/

/**
 * @file main.c
 * @author Nations
 * @version v1.0.0
 *
 * @copyright Copyright (c) 2019, Nations Technologies Inc. All rights reserved.
 */
#include "main.h"
#include <stdio.h>
#include <stdint.h>
#include "log.h"
#include "n32g031_rtc.h"
#include "n32g031.h"
/** @addtogroup RTC_Calendar
 * @{
 */
RTC_DateType RTC_DateStructure;
RTC_DateType RTC_DateDefault;
RTC_TimeType RTC_TimeStructure;
RTC_TimeType RTC_TimeDefault;
RTC_InitType RTC_InitStructure;

RTC_DateType RTC_TimeStampDateStructure;
RTC_TimeType RTC_TimeStampStructure;
uint32_t SynchPrediv, AsynchPrediv;

void LedBlink(GPIO_Module* GPIOx, uint16_t Pin);
void LEDInit(void);
void LedOn(uint16_t Pin);
void LedOff(uint16_t Pin);
void RTC_CLKSourceConfig(uint8_t ClkSrc, uint8_t FirstLastCfg, uint8_t RstBKP);
ErrorStatus RTC_TimeInitialValueSet(void);
ErrorStatus RTC_DateInitialValueSet(void);
void RTC_DateAndTimeDefaultVale(void);
static void RTC_PrescalerSet(void);
void EXTI_PB7_TimeStamp_Configuration(uint32_t TSEdgeSel);
void RTC_TimeShow(void);
void RTC_DateShow(void);
void RTC_TimeStampShow(void);
void SysTick_Delay_Ms(__IO uint32_t ms);
void EXTI19_TAMPER_IRQn_Configuration(FunctionalState NewState,uint32_t TSEdgeSel);

/**
 * @brief  Calendar initialization configuration.
 */
ErrorStatus RTC_CalendarInitialize(FunctionalState delay_cmd)
{
    /* Configure the RTC PRE, Date amd Time register */
    if (RTC_ConfigCalendar(RTC_FORMAT_BIN, &RTC_InitStructure, &RTC_DateStructure, &RTC_TimeStructure, delay_cmd) == ERROR)
    {
        log_info("\n\r>> !! RTC Calendar Configure failed. !! <<\n\r");
        return ERROR;
    }
    else
    {
        log_info("\n\r>> !! RTC Calendar Configure success. !! <<\n\r");
		RTC_DateShow();
        RTC_TimeShow();
        return SUCCESS;
    }
}

/**
 * @brief  Main program.
 */
int main(void)
{
    /*!< At this stage the microcontroller clock setting is already configured,
         this is done through SystemInit() function which is called from startup
         file (startup_n32g031_xx.s) before to branch to application main.
         To reconfigure the default setting of SystemInit() function, refer to
         system_n32g031.c file
       */
    /* Initialize LEDs on n32g031-EVAL board */
    LEDInit();
    LedOff(LED1_PIN);
    /* Initialize USART,TX: PA9 RX: PA10*/
    log_init();
    log_info("RTC Init");
    /* RTC date and time default value*/
    RTC_DateAndTimeDefaultVale();
    /* RTC clock source select 1:HSE/128 2:LSE 3:LSI*/
    RTC_CLKSourceConfig(3, 0, 1);

    /* RTC prescaler, date and time initial value set*/
	RTC_PrescalerSet();
    RTC_DateInitialValueSet();
    RTC_TimeInitialValueSet();
	
	/* RTC calendar Initialize*/
	/* Disable the function of delay 1 second*/
	RTC_CalendarInitialize(DISABLE);

    /* Configure EXTI PB7 pin  connected to RTC TimeStamp
    (while externally feeding PB7 with 1HZ signal output from PC13)
    */
    EXTI_PB7_TimeStamp_Configuration(1);
    EXTI19_TAMPER_IRQn_Configuration(ENABLE,1);
    RTC_ClrFlag(RTC_FLAG_TISF);
    RTC_ClrFlag(RTC_FLAG_TISOVF);
    /* RTC time stamp config and enable */
    RTC_EnableTimeStamp(RTC_TIMESTAMP_EDGE_RISING, ENABLE);
    RTC_ConfigInt(RTC_INT_TS,ENABLE);
    while (1)
    {
        /* Every interval delay (1s) displays calendar and clock stamp register contents*/
        if (RTC_GetITStatus(RTC_INT_TS) != RESET)
        {
            RTC_DateShow();
            RTC_TimeShow();
            RTC_TimeStampShow();
            RTC_ClrFlag(RTC_FLAG_TISF);
        }
        SysTick_Delay_Ms(1000);
    }
}
/**
 * @brief  Configure the system tick clock.
 */
uint32_t DBG_SysTick_Config(uint32_t ticks)
{
    if (ticks > SysTick_LOAD_RELOAD_Msk)
        return (1); /* Reload value impossible */

    SysTick->LOAD = (ticks & SysTick_LOAD_RELOAD_Msk) - 1;       /* set reload register */
    NVIC_SetPriority(SysTick_IRQn, (1 << __NVIC_PRIO_BITS) - 1); /* set Priority for Cortex-M0 System Interrupts */
    SysTick->VAL  = 0;                                           /* Load the SysTick Counter Value */
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk; /* Enable SysTick IRQ and SysTick Timer */
    SysTick->CTRL &= ~SysTick_CTRL_TICKINT_Msk;
    return (0); /* Function successful */
}
/**
 * @brief  Use the system tick clock to delay.
 */
void SysTick_Delay_Ms(__IO uint32_t ms)
{
    uint32_t i;
    RCC_ClocksType RCC_Clocks;

    RCC_GetClocksFreqValue(&RCC_Clocks);
    DBG_SysTick_Config(RCC_Clocks.SysclkFreq / 1000);

    for (i = 0; i < ms; i++)
    {
        /* When the value of the counter is reduced to 0, the bit 16 of the CRTL register is set to 1.
           When set to 1, the bit  will cleared to 0 with read
        */
        while (!((SysTick->CTRL) & (1 << 16)))
            ;
    }
    // Disable SysTick timer
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}

/**
 * @brief  EXTI PB7 I/O config and use the EXTI interrupt to trigger time stamp.
 */
void EXTI_PB7_TimeStamp_Configuration(uint32_t TSEdgeSel)
{
    GPIO_InitType GPIO_InitStructure;
    //EXTI_InitType EXTI_InitStructure;

    GPIO_InitStruct(&GPIO_InitStructure);

    RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOB | RCC_APB2_PERIPH_AFIO, ENABLE);

    /* Configure PB15 in alternate function mode */
    GPIO_InitStructure.Pin = GPIO_PIN_7;
    GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_INPUT;
    GPIO_InitStructure.GPIO_Pull = GPIO_PULL_DOWN;
    GPIO_InitPeripheral(GPIOB, &GPIO_InitStructure);

    /* Connect PB7 to RTC_AF1 */
    EXTI_RTCTimeStampSel(EXTI_TSSEL_LINE7);

    /* Connect EXTI15 Line to PB15 pin */
    GPIO_ConfigEXTILine(GPIOB_PORT_SOURCE, GPIO_PIN_SOURCE7);
}
/**
 * @brief  Toggles the selected Led.
 * @param Led Specifies the Led to be toggled.
 *   This parameter can be one of following parameters:
 *     @arg LED1
 *     @arg LED2
 *     @arg LED3
 */
void LedBlink(GPIO_Module* GPIOx, uint16_t Pin)
{
    GPIOx->POD ^= Pin;
}
/**
 * @brief  Turns selected Led on.
 * @param Led Specifies the Led to be set on.
 *   This parameter can be one of following parameters:
 *     @arg LED1
 *     @arg LED2
 *     @arg LED3
 */
void LedOn(uint16_t Pin)
{
    GPIOB->PBSC = Pin;
}
/**
 * @brief  Turns selected Led Off.
 * @param Led Specifies the Led to be set off.
 *   This parameter can be one of following parameters:
 *     @arg LED1
 *     @arg LED2
 *     @arg LED3
 */
void LedOff(uint16_t Pin)
{
    GPIOB->PBC = Pin;
}
/**
 * @brief  Configures LED GPIO.
 * @param Led Specifies the Led to be configured.
 *   This parameter can be one of following parameters:
 *     @arg LED1
 *     @arg LED2
 */
void LEDInit(void)
{
    GPIO_InitType GPIO_InitStructure;

    GPIO_InitStruct(&GPIO_InitStructure);
    
    /* Enable the GPIO_LED Clock */
    RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOB, ENABLE);

    /* Configure the GPIO_LED pin */
    GPIO_InitStructure.Pin        = LED1_PIN;
    GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_OUTPUT_PP;

    GPIO_InitPeripheral(LED1_PORT, &GPIO_InitStructure);
}
/**
 * @brief  Display the current TimeStamp (time and date) on the Hyperterminal.
 */
void RTC_TimeStampShow(void)
{
    /* Get the current TimeStamp */
    RTC_GetTimeStamp(RTC_FORMAT_BIN, &RTC_TimeStampStructure, &RTC_TimeStampDateStructure);
    printf("\n\r //=========TimeStamp Display (Time and Date)============// \n\r");
    printf("\n\r The current time stamp time (Hour-Minute-Second) is :  %0.2d:%0.2d:%0.2d \n\r",
           RTC_TimeStampStructure.Hours,
           RTC_TimeStampStructure.Minutes,
           RTC_TimeStampStructure.Seconds);
    printf("\n\r The current timestamp date (WeekDay-Date-Month) is :  %0.2d-%0.2d-%0.2d \n\r",
           RTC_TimeStampDateStructure.WeekDay,
           RTC_TimeStampDateStructure.Date,
           RTC_TimeStampDateStructure.Month);
}
/**
 * @brief  Display the current Date on the Hyperterminal.
 */
void RTC_DateShow(void)
{
    /* Get the current Date */
    RTC_GetDate(RTC_FORMAT_BIN, &RTC_DateStructure);
    log_info("\n\r //=========== Current Date Display ==============// \n\r");
    log_info("\n\r The current date (WeekDay-Date-Month-Year) is :  %0.2d-%0.2d-%0.2d-%0.2d \n\r",
             RTC_DateStructure.WeekDay,
             RTC_DateStructure.Date,
             RTC_DateStructure.Month,
             RTC_DateStructure.Year);
}

/**
 * @brief  Display the current time on the Hyperterminal.
 */
void RTC_TimeShow(void)
{
    /* Get the current Time and Date */
    RTC_GetTime(RTC_FORMAT_BIN, &RTC_TimeStructure);
    log_info("\n\r //============ Current Time Display ===============// \n\r");
    log_info("\n\r The current time (Hour-Minute-Second) is :  %0.2d:%0.2d:%0.2d \n\r",
             RTC_TimeStructure.Hours,
             RTC_TimeStructure.Minutes,
             RTC_TimeStructure.Seconds);
    /* Unfreeze the RTC DAT Register */
    (void)RTC->DATE;
}
/**
 * @brief  RTC initalize default value.
 */
void RTC_DateAndTimeDefaultVale(void)
{ // Date
    RTC_DateDefault.WeekDay = 3;
    RTC_DateDefault.Date    = 20;
    RTC_DateDefault.Month   = 11;
    RTC_DateDefault.Year    = 19;
    // Time
    RTC_TimeDefault.H12     = RTC_AM_H12;
    RTC_TimeDefault.Hours   = 4;
    RTC_TimeDefault.Minutes = 5;
    RTC_TimeDefault.Seconds = 1;
}

/**
 * @brief  RTC date initial value set with the default value.
 */
ErrorStatus RTC_DateInitialValueSet(void)
{
    uint32_t tmp_hh = 0xFF, tmp_mm = 0xFF, tmp_ss = 0xFF;
    log_info("\n\r //=============Date Settings================// \n\r");

    log_info("\n\r Please Set WeekDay (01-07) \n\r");
    tmp_hh = RTC_DateDefault.WeekDay;
    if (tmp_hh == 0xff)
    {
        return ERROR;
    }
    else
    {
        RTC_DateStructure.WeekDay = tmp_hh;
    }
    log_info(": %0.2d\n\r", tmp_hh);

    tmp_hh = 0xFF;
    log_info("\n\r Please Set Date (01-31) \n\r");
    tmp_hh = RTC_DateDefault.Date;
    if (tmp_hh == 0xff)
    {
        return ERROR;
    }
    else
    {
        RTC_DateStructure.Date = tmp_hh;
    }
    log_info(": %0.2d\n\r", tmp_hh);

    log_info("\n\r Please Set Month (01-12)\n\r");
    tmp_mm = RTC_DateDefault.Month;
    if (tmp_mm == 0xff)
    {
        return ERROR;
    }
    else
    {
        RTC_DateStructure.Month = tmp_mm;
    }
    log_info(": %0.2d\n\r", tmp_mm);

    log_info("\n\r Please Set Year (00-99)\n\r");
    tmp_ss = RTC_DateDefault.Year;
    if (tmp_ss == 0xff)
    {
        return ERROR;
    }
    else
    {
        RTC_DateStructure.Year = tmp_ss;
    }
    log_info(": %0.2d\n\r", tmp_ss);

	return SUCCESS;
}
/**
 * @brief  RTC time initial value set with the default value.
 */
ErrorStatus RTC_TimeInitialValueSet(void)
{
    uint32_t tmp_hh = 0xFF, tmp_mm = 0xFF, tmp_ss = 0xFF;
    log_info("\n\r //==============Time Settings=================// \n\r");

    RTC_TimeStructure.H12 = RTC_TimeDefault.H12;

    log_info("\n\r Please Set Hours \n\r");
    tmp_hh = RTC_TimeDefault.Hours;
    if (tmp_hh == 0xff)
    {
        return ERROR;
    }
    else
    {
        RTC_TimeStructure.Hours = tmp_hh;
    }
    log_info(": %0.2d\n\r", tmp_hh);

    log_info("\n\r Please Set Minutes \n\r");
    tmp_mm = RTC_TimeDefault.Minutes;
    if (tmp_mm == 0xff)
    {
        return ERROR;
    }
    else
    {
        RTC_TimeStructure.Minutes = tmp_mm;
    }
    log_info(": %0.2d\n\r", tmp_mm);

    log_info("\n\r Please Set Seconds \n\r");
    tmp_ss = RTC_TimeDefault.Seconds;
    if (tmp_ss == 0xff)
    {
        return ERROR;
    }
    else
    {
        RTC_TimeStructure.Seconds = tmp_ss;
    }
    log_info(": %0.2d\n\r", tmp_ss);

	return SUCCESS;
}

/**
 * @brief  RTC prescaler set.
 */
static void RTC_PrescalerSet(void)
{
    /* Init the RTC prescaler */
    RTC_InitStructure.RTC_AsynchPrediv = AsynchPrediv;
    RTC_InitStructure.RTC_SynchPrediv  = SynchPrediv;
    RTC_InitStructure.RTC_HourFormat   = RTC_24HOUR_FORMAT;
}

/**
 * @brief  Configures RTC.
 *   Configure the RTC peripheral by selecting the clock source
 */

void RTC_CLKSourceConfig(uint8_t ClkSrc, uint8_t FirstLastCfg, uint8_t RstBKP)
{
    /* Enable the PWR clock */
    RCC_EnableAPB1PeriphClk(RCC_APB1_PERIPH_PWR, ENABLE);
    RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_AFIO, ENABLE);

    /* Disable RTC clock */
    RCC_EnableRtcClk(DISABLE);

    if (ClkSrc == 0x01)
    {
        log_info("\r\n RTC_ClkSrc Is Set HSE128! \r\n");
        if (FirstLastCfg == 0)
        {
            /* Enable HSE */
            RCC_EnableLsi(DISABLE);
            RCC_ConfigHse(RCC_HSE_ENABLE);
            while (RCC_WaitHseStable() == ERROR)
            {
            }

            RCC_ConfigRtcClk(RCC_RTCCLK_SRC_HSE_DIV128);
        }
        else
        {
            RCC_EnableLsi(DISABLE);
            RCC_ConfigRtcClk(RCC_RTCCLK_SRC_HSE_DIV128);

            /* Enable HSE */
            RCC_ConfigHse(RCC_HSE_ENABLE);

            while (RCC_WaitHseStable() == ERROR)
            {
            }
        }

        SynchPrediv  = 0x1E8; // 8M/128 = 62.5KHz
        AsynchPrediv = 0x7F;  // value range: 0-7F
    }
    else if (ClkSrc == 0x02)
    {
        log_info("\r\n RTC_ClkSrc Is Set LSE! \r\n");

        if (FirstLastCfg == 0)
        {
            /* Enable the LSE OSC32_IN PC14 */
            RCC_EnableLsi(DISABLE); // LSI is turned off here to ensure that only one clock is turned on

#if (_TEST_LSE_BYPASS_)
            RCC_ConfigLse(RCC_LSE_BYPASS,0x01);
#else
            RCC_ConfigLse(RCC_LSE_ENABLE,0x01);
#endif

            while (RCC_GetFlagStatus(RCC_LSCTRL_FLAG_LSERD) == RESET)
            {
            }

            RCC_ConfigRtcClk(RCC_RTCCLK_SRC_LSE);
        }
        else
        {
            /* Enable the LSE OSC32_IN PC14 */
            RCC_EnableLsi(DISABLE);
            RCC_ConfigRtcClk(RCC_RTCCLK_SRC_LSE);

#if (_TEST_LSE_BYPASS_)
            RCC_ConfigLse(RCC_LSE_BYPASS,0x01);
#else
            RCC_ConfigLse(RCC_LSE_ENABLE,0x01);
#endif

            while (RCC_GetFlagStatus(RCC_LSCTRL_FLAG_LSERD) == RESET)
            {
            }
        }

        SynchPrediv  = 0xFF; // 32.768KHz
        AsynchPrediv = 0x7F; // value range: 0-7F
    }
    else if (ClkSrc == 0x03)
    {
        log_info("\r\n RTC_ClkSrc Is Set LSI! \r\n");
        if (FirstLastCfg == 0)
        {
            /* Enable the LSI OSC */
            RCC_EnableLsi(ENABLE);

            while (RCC_GetFlagStatus(RCC_LSCTRL_FLAG_LSIRD) == RESET)
            {
            }

            RCC_ConfigRtcClk(RCC_RTCCLK_SRC_LSI);
        }
        else
        {
            RCC_ConfigRtcClk(RCC_RTCCLK_SRC_LSI);

            /* Enable the LSI OSC */
            RCC_EnableLsi(ENABLE);

            while (RCC_GetFlagStatus(RCC_LSCTRL_FLAG_LSIRD) == RESET)
            {
            }
        }

        SynchPrediv  = 0xEA; // 30KHz
        AsynchPrediv = 0x7F;  // value range: 0-7F
    }
    else
    {
        log_info("\r\n RTC_ClkSrc Value is error! \r\n");
    }

    /* Enable the RTC Clock */
    RCC_EnableRtcClk(ENABLE);
    RTC_WaitForSynchro();
}
void EXTI19_TAMPER_IRQn_Configuration(FunctionalState NewState,uint32_t TSEdgeSel)
{
    //GPIO_InitType GPIO_InitStructure;
    EXTI_InitType EXTI_InitStructure;
    NVIC_InitType NVIC_InitStructure;
    
    EXTI_ClrITPendBit(EXTI_LINE19);
    EXTI_InitStructure.EXTI_Line                          = EXTI_LINE19;
    EXTI_InitStructure.EXTI_Mode                          = EXTI_Mode_Interrupt;
    //EXTI_InitStructure.EXTI_Trigger                       = EXTI_Trigger_Rising; 
    if(TSEdgeSel == 0x01)
        EXTI_InitStructure.EXTI_Trigger   = EXTI_Trigger_Rising;  
    else if(TSEdgeSel == 0x02)
        EXTI_InitStructure.EXTI_Trigger   = EXTI_Trigger_Falling;
    else
        printf("\r\n The TSEdgeSel value is error! \r\n");
    EXTI_InitStructure.EXTI_LineCmd                       = ENABLE;
    EXTI_InitPeripheral(&EXTI_InitStructure);
    
    /* Enable the RTC Alarm Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel                    = RTC_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPriority  = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd                 = NewState;
    NVIC_Init(&NVIC_InitStructure);
}
