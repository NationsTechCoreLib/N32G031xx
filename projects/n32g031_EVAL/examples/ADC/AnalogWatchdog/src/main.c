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

/** @addtogroup ADC_AnalogWatchdog
 * @{
 */

ADC_InitType ADC_InitStructure;
uint32_t gCnt = 0;

void RCC_Configuration(void);
void GPIO_Configuration(void);
void NVIC_Configuration(void);

/**
 * @brief   Main program
 */
int main(void)
{
    /* System clocks configuration ---------------------------------------------*/
    RCC_Configuration();

    /* NVIC configuration ------------------------------------------------------*/
    NVIC_Configuration();

    /* GPIO configuration ------------------------------------------------------*/
    GPIO_Configuration();

    /* ADC Configuration ------------------------------------------------------*/
    ADC_InitStructure.MultiChEn      = DISABLE;
    ADC_InitStructure.ContinueConvEn = ENABLE;
    ADC_InitStructure.ExtTrigSelect  = ADC_EXT_TRIGCONV_NONE;
    ADC_InitStructure.DatAlign       = ADC_DAT_ALIGN_R;
    ADC_InitStructure.ChsNumber      = 1;
    ADC_Init(ADC, &ADC_InitStructure);

    /* ADC regular channel1 configuration */
    ADC_ConfigRegularChannel(ADC, ADC_CH_4_PA4, 1, ADC_SAMP_TIME_14CYCLES5);

    /* Configure high and low analog watchdog thresholds */
    ADC_ConfigAnalogWatchdogThresholds(ADC, 0x0B00, 0x0300);
    /* Configure channel1 as the single analog watchdog guarded channel */
    ADC_ConfigAnalogWatchdogSingleChannel(ADC, ADC_CH_4_PA4);
    /* Enable analog watchdog on one regular channel */
    ADC_ConfigAnalogWatchdogWorkChannelType(ADC, ADC_ANALOG_WTDG_SINGLEREG_ENABLE);

    /* Enable AWD interrupt */
    ADC_ConfigInt(ADC, ADC_INT_AWD, ENABLE);

    /* Enable ADC */
    ADC_Enable(ADC, ENABLE);
    
    /*wait ADC is ready to use*/
    while(!ADC_GetFlagStatusNew(ADC, ADC_FLAG_RDY))
        ;
    /*wait ADC is powered on*/
    while(ADC_GetFlagStatusNew(ADC, ADC_FLAG_PD_RDY))
        ;
    
    /* Start ADC Software Conversion */
    ADC_EnableSoftwareStartConv(ADC, ENABLE);

    /*test ADC converse finish flag*/
    while (!ADC_GetFlagStatus(ADC, ADC_FLAG_ENDC))
        ;
    ADC_ClearFlag(ADC, ADC_FLAG_ENDC);
    
    while (1)
    {
        gCnt++;
    }
}

/**
 * @brief  Configures the different system clocks.
 */
void RCC_Configuration(void)
{
    ErrorStatus HSIStartUpStatus;
    /* Enable peripheral clocks ------------------------------------------------*/
    /* Enable GPIOA clocks */
    RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOA, ENABLE);
    /* Enable ADC clocks */
    RCC_EnableAHBPeriphClk(RCC_AHB_PERIPH_ADC, ENABLE);

    /* RCC_ADCHCLK_DIV16*/
    ADC_ConfigClk(ADC_CTRL3_CKMOD_AHB, RCC_ADCHCLK_DIV16);

    /* enable ADC1M clock */
    RCC_EnableHsi(ENABLE);
    
    /* Wait til1 HSI is ready*/
    HSIStartUpStatus = RCC_WaitHsiStable(); 
    if(HSIStartUpStatus == SUCCESS)
    {
    }
    else
    {
        /* If HSI fails to start-up, the application will have wrong clock configuration. User can add here some code to deal with this error*/
        /* Go to infinital 1oop*/
        while(1)
        {
        }
    }
    RCC_ConfigAdc1mClk(RCC_ADC1MCLK_SRC_HSI, RCC_ADC1MCLK_DIV8);
}

/**
 * @brief  Configures the different GPIO ports.
 */
void GPIO_Configuration(void)
{
    GPIO_InitType GPIO_InitStructure;

    GPIO_InitStruct(&GPIO_InitStructure);
    /* Configure PA.04 (ADC Channel4) as analog input -------------------------*/
    GPIO_InitStructure.Pin       = GPIO_PIN_4;
    GPIO_InitStructure.GPIO_Mode = GPIO_MODE_ANALOG;
    GPIO_InitPeripheral(GPIOA, &GPIO_InitStructure);
}

/**
 * @brief  Configures NVIC and Vector Table base location.
 */
void NVIC_Configuration(void)
{
    NVIC_InitType NVIC_InitStructure;

    NVIC_InitStructure.NVIC_IRQChannel                   = ADC_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPriority           = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

#ifdef USE_FULL_ASSERT

/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param file pointer to the source file name
 * @param line assert_param error line source number
 */
void assert_failed(const uint8_t* expr, const uint8_t* file, uint32_t line)
{
    /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

    /* Infinite loop */
    while (1)
    {
    }
}

#endif

/**
 * @}
 */

/**
 * @}
 */
