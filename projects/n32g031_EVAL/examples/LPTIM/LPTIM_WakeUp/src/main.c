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
#include "n32g031_lptim.h"
/** @addtogroup PWR_PVD
 * @{
 */

/**
 * @brief  Main program.
 */
int main(void)
{
    /*!< At this stage the microcontroller clock setting is already configured,
         this is done through SystemInit() function which is called from startup
         file (startup_n32g031.s) before to branch to application main.
         To reconfigure the default setting of SystemInit() function, refer to
         system_N32G031.c file
       */
    /* Enable PWR Clock */
    RCC_EnableAPB1PeriphClk(RCC_APB1_PERIPH_PWR, ENABLE);
    /* Init LED GPIO */
    LedInit(PORT_GROUP, LED1);
    /* Enable the LSI source */
    RCC_EnableLsi(ENABLE);
    LPTIMNVIC_Config(ENABLE);
    RCC_ConfigLPTIMClk(RCC_LPTIMCLK_SRC_LSI);  
    RCC_EnableAPB1PeriphClk(RCC_APB1_PERIPH_LPTIM | RCC_APB1_PERIPH_LPTIMPCLK,ENABLE); 
    /* Enable interrupt   */
    LPTIM_SetPrescaler(LPTIM,LPTIM_PRESCALER_DIV1);
    LPTIM_EnableIT_CMPM(LPTIM);
    /* config lptim ARR and compare register */ 
    LPTIM_Enable(LPTIM);   
    LPTIM_SetAutoReload(LPTIM,65000);
    LPTIM_SetCompare(LPTIM,60000);    
    LPTIM_StartCounter(LPTIM,LPTIM_OPERATING_MODE_CONTINUOUS);              
    DBG_ConfigPeriph(DBG_STOP, ENABLE);
    while (1)
    {
        PWR_EnterSTOPMode(PWR_STOPENTRY_WFI);
        LedBlink(PORT_GROUP, LED1);
        delay(30);
    }
}

/**
 * @brief  Turns selected Led on.
 * @param GPIOx x can be A to G to select the GPIO port.
 * @param Pin This parameter can be GPIO_PIN_0~GPIO_PIN_15.
 */
void LedOn(GPIO_Module *GPIOx, uint16_t Pin)
{
    GPIO_SetBits(GPIOx, Pin);
}

/**
 * @brief  Turns selected Led Off.
 * @param GPIOx x can be A to G to select the GPIO port.
 * @param Pin This parameter can be GPIO_PIN_0~GPIO_PIN_15.
 */
void LedOff(GPIO_Module* GPIOx, uint16_t Pin)
{
    GPIO_ResetBits(GPIOx, Pin);
}

/**
 * @brief  Toggles the selected Led.
 * @param GPIOx x can be A to G to select the GPIO port.
 * @param Pin This parameter can be GPIO_PIN_0~GPIO_PIN_15.
 */
void LedBlink(GPIO_Module* GPIOx, uint16_t Pin)
{
    GPIO_TogglePin(GPIOx, Pin);
}

/**
 * @brief  Configures LED GPIO.
 * @param GPIOx x can be A to G to select the GPIO port.
 * @param Pin This parameter can be GPIO_PIN_0~GPIO_PIN_15.
 */
void LedInit(GPIO_Module* GPIOx, uint16_t Pin)
{
    GPIO_InitType GPIO_InitStructure;

    /* Check the parameters */
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));

    /* Enable the GPIO Clock */
    if (GPIOx == GPIOA)
    {
        RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOA, ENABLE);
    }
    else if (GPIOx == GPIOB)
    {
        RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOB, ENABLE);
    }
    else if (GPIOx == GPIOC)
    {
        RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOC, ENABLE);
    }
    else if (GPIOx == GPIOF)
    {
        RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOF, ENABLE);
    }
    else
    {
        return;
    }
    GPIO_InitStruct(&GPIO_InitStructure);
    GPIO_InitStructure.Pin = Pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitPeripheral(GPIOx, &GPIO_InitStructure);
}

void delay(vu32 nCount)
{
    vu32 index = 0;
    for (index = (34000 * nCount); index != 0; index--)
    {
    }
}
/**
 * @brief LPTIM Interrupt.
 * @param Cmd Interrupt enable or disable
 */
void LPTIMNVIC_Config(FunctionalState Cmd)
{
    EXTI_InitType EXTI_InitStructure;
    NVIC_InitType NVIC_InitStructure;

    EXTI_ClrITPendBit(EXTI_LINE23);
    EXTI_InitStructure.EXTI_Line = EXTI_LINE23;
#ifdef __TEST_SEVONPEND_WFE_NVIC_DIS__
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Event;
#else
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
#endif
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_InitPeripheral(&EXTI_InitStructure);

    /* Enable the RTC Alarm Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel                   = LPTIM_TIM6_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPriority           = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd                = Cmd;
    NVIC_Init(&NVIC_InitStructure);
}
/**
 * @brief  Configures system clock after wake-up from low power mode: enable HSE, PLL
 *         and select PLL as system clock source.
 */

void SYSCLKConfig(uint32_t RCC_PLLMULL)
{
    __IO uint32_t StartUpCounter = 0, HSEStartUpStatus = 0;

    // reset RCC with the default values
    RCC_DeInit();

    RCC_ConfigHse(RCC_HSE_ENABLE);
    HSEStartUpStatus = RCC_WaitHseStable();

    if (HSEStartUpStatus == SUCCESS)
    {
//----------------------------------------------------------------------//
        //The following two steps are required to operate flash 
        FLASH_PrefetchBufSet(FLASH_PrefetchBuf_EN);        
        FLASH_SetLatency(FLASH_LATENCY_2);
//----------------------------------------------------------------------//
        
        // set different clock trees frequency division
        RCC_ConfigHclk(RCC_SYSCLK_DIV1);        
        RCC_ConfigPclk2(RCC_HCLK_DIV2); 
        RCC_ConfigPclk1(RCC_HCLK_DIV4);
    
//-------------------the main frequence-------------------//
        // set PLLclock resource from HSE and the PLL factor
        // PLLCLK = 8MHz * pllmul
        RCC_ConfigPll(RCC_PLL_SRC_HSE, RCC_PLLMULL,RCC_PLL_PRE_2,RCC_PLLOUT_DIV_2);
//--------------------------------------------------------------------//

        RCC_EnablePll(ENABLE);
        while (RCC_GetFlagStatus(RCC_CTRL_FLAG_PLLRDF) == RESET)
        {
        }

        RCC_ConfigSysclk(RCC_SYSCLK_SRC_PLLCLK);
        while (RCC_GetSysclkSrc() != 0x0C)
        {
        }
    }
    else
    { 
        // if HSE enable to fail ,the process will come here.Then the MCU clock resoure is HSI
        while(1)
        {}
    }
}
