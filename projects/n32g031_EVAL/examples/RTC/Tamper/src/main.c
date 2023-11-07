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
/** @addtogroup RTC_TAMPER
 * @{
 */
 
RTC_DateType RTC_DateStructure;
RTC_TimeType RTC_TimeStructure;
RTC_InitType RTC_InitStructure;
uint32_t SynchPrediv, AsynchPrediv;

void RTC_CLKSourceConfig(uint8_t ClkSrc, uint8_t FirstLastCfg, uint8_t RstBKP);
static void RTC_PrescalerSet(void);
void TAMPER_INT_Configuration(FunctionalState cmd);
void TamperInputIoInit(void);

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
 * @brief  Calendar initialization configuration.
 */
ErrorStatus RTC_CalendarInitialize(FunctionalState delay_cmd)
{
    /* Configure the RTC PRE, Date amd Time register */
    if (RTC_ConfigCalendar(RTC_FORMAT_BIN, &RTC_InitStructure, NULL, NULL, delay_cmd) == ERROR)
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
    /* Initialize USART,TX: PA9*/
    log_init();
    log_info(" RTC Init");
    /* RTC clock source select 1:HSE/128 2:LSE 3:LSI*/
    RTC_CLKSourceConfig(3, 0, 1);
    RTC_PrescalerSet();
	/* RTC calendar Initialize*/
	/* Disable the function of delay 1 second*/
	RTC_CalendarInitialize(DISABLE);
    /*Tamper GPIO Initialize,PC13*/
    TamperInputIoInit();
    /*Configure Tamper GPIO trigger mode*/
    RTC_TamperTriggerConfig(RTC_TAMPER_1, RTC_TamperTrigger_RisingEdge);
    /*Configure the valib number of scanning times*/
    RTC_TamperFilterConfig(RTC_TamperFilter_Disable);
    /*Configure scanning frequence*/
    RTC_TamperSamplingFreqConfig(RTC_TamperSamplingFreq_RTCCLK_Div256);
    /*Configure precharge duration time*/
    RTC_TamperPinsPrechargeDuration(RTC_TamperPrechargeDuration_1RTCCLK);
    /*Configure tamper interruput,EXTI_LINE19*/
    TAMPER_INT_Configuration(ENABLE);
    /*Enable tamper interruput*/
    RTC_TamperIECmd(RTC_TAMPER1_INT, ENABLE);
    /*Enable tamper1 */
    RTC_TamperCmd(RTC_TAMPER_1, ENABLE);                    
    while (1)
    {
    }
}

/**
 * @brief  Configure the tamper interruput,EXTI19.
 */
 void TAMPER_INT_Configuration(FunctionalState cmd)
{
    EXTI_InitType EXTI_InitStructure;
    NVIC_InitType NVIC_InitStructure;
    
    EXTI_ClrITPendBit(EXTI_LINE19);
    EXTI_InitStructure.EXTI_Line                          = EXTI_LINE19;
    EXTI_InitStructure.EXTI_Mode                          = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger                       = EXTI_Trigger_Rising; 

    EXTI_InitStructure.EXTI_LineCmd                       = ENABLE;
    EXTI_InitPeripheral(&EXTI_InitStructure);
    
    /* Enable the RTC Alarm Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel                    = RTC_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPriority  = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd                 = cmd;
    NVIC_Init(&NVIC_InitStructure);
}

/**
 * @brief  Configures Tamper Input GPIO.
 */
void TamperInputIoInit(void)
{
    GPIO_InitType GPIO_InitStructure;

    GPIO_InitStruct(&GPIO_InitStructure);

    /* Enable the GPIO_LED Clock */
    RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOC|RCC_APB2_PERIPH_AFIO, ENABLE);

    /* Configure the GPIO_LED pin */
    GPIO_InitStructure.Pin        = GPIO_PIN_13;
    GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_AF_PP;
    GPIO_InitStructure.GPIO_Alternate = GPIO_AF2_RTC;
    GPIO_InitPeripheral(GPIOC, &GPIO_InitStructure);
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
//    assert_param(IS_CLKSRC_VALUE(ClkSrc));
//    assert_param(IS_FLCFG_VALUE(FirstLastCfg));

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
