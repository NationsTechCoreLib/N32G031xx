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
/** @addtogroup LPTIM
 * @{
 */


uint16_t tempCNT;
/**
 * @brief  Main program.
 */
int main(void)
{
    
    /*!< At this stage the microcontroller clock setting is already configured,
         this is done through SystemInit() function which is called from startup
         file (startup_n32g031.s) before to branch to application main.
         To reconfigure the default setting of SystemInit() function, refer to
         system_n32g031.c file
       */
  /* Init LED GPIO */
    LedInit(PORT_GROUP, LED1);
    /* Enable the LSI source */
    RCC_EnableLsi(ENABLE);
    RCC_ConfigLPTIMClk(RCC_LPTIMCLK_SRC_LSI);  
    RCC_EnableAPB1PeriphClk(RCC_APB1_PERIPH_LPTIM | RCC_APB1_PERIPH_LPTIMPCLK,ENABLE); 
    /* LPTIM input1 IO Init */
    LPTIM_SetPrescaler(LPTIM,LPTIM_PRESCALER_DIV1);
    LPTIM_InputIoInit();

    //PWR_EnterSTOP2Mode(PWR_STOPENTRY_WFI);
    /* config timer    CKSEL:0  COUNTMODE:1 */
    LPTIM_Disable(LPTIM);   
    LPTIM_SetCounterMode(LPTIM,LPTIM_COUNTER_MODE_EXTERNAL);
    /* config the rising polarity */
    LPTIM_ConfigClock(LPTIM,LPTIM_CLK_FILTER_NONE,LPTIM_CLK_POLARITY_RISING);    
    LPTIM_Enable(LPTIM); 
    LPTIM_SetAutoReload(LPTIM,60000);  
    LPTIM_StartCounter(LPTIM,LPTIM_OPERATING_MODE_CONTINUOUS);  //start with the continue mode  
    /* Great 10 square waves ,and tempCNT should be equal to 10*/
    delay(10);
    PWM_Out(LED1,10);
    tempCNT = LPTIM->CNT;
    
    //In order to make tempcnt visible in the watch window of debugging interface
    if(10 == tempCNT)
    {
        delay(10);
    }
   
    while (1)
    {
   
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
 * @brief  Great square  waves.
* @param count: the number of waves.
 *   This parameter can be PB0 and PB1.
 */
void PWM_Out(uint16_t Pin,uint8_t cnt)
{
    uint8_t i;
    for (i = 0; i< cnt;i++)
    {
        LedOn(PORT_GROUP, Pin);
        delay(10);
        LedOff(PORT_GROUP, Pin);    
        delay(10);
    }


}
/**
 * @brief  lptim input IO Initaliza.
 * @param NONE.
 *   This parameter can be one of following parameters:
 *     @arg NONE
 */
void LPTIM_InputIoInit(void)
{
    GPIO_InitType GPIO_InitStructure;
    GPIO_InitStruct(&GPIO_InitStructure);
    /* Enable the GPIOClock */
    RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOA, ENABLE);

    /* Configure the GPIO pin */
    GPIO_InitStructure.Pin        = GPIO_PIN_0;
    GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_AF_PP;
    GPIO_InitStructure.GPIO_Alternate = GPIO_AF7_LPTIM;
    GPIO_InitPeripheral(GPIOA, &GPIO_InitStructure);
}



