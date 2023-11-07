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

/** @addtogroup LPTIM_PWM
 * @{
 */
void LPTIM_OutputIoInit(void);
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
//**********************************************************
    /* Enable the LSI source */
    RCC_EnableLsi(ENABLE);
    RCC_ConfigLPTIMClk(RCC_LPTIMCLK_SRC_LSI);  
    RCC_EnableAPB1PeriphClk(RCC_APB1_PERIPH_LPTIM  | RCC_APB1_PERIPH_LPTIMPCLK,ENABLE); 
    /* Init output IO */
    LPTIM_OutputIoInit();
    /* Init lptim module */ 
    LPTIM->INTEN = 0x7F;
    LPTIM_Disable(LPTIM);
    LPTIM_SetWaveform(LPTIM,LPTIM_OUTPUT_WAVEFORM_PWM); 
    /* output wave */ 
    LPTIM_SetPolarity(LPTIM,LPTIM_OUTPUT_POLARITY_REGULAR);  
    /* config the prescaler */ 
    LPTIM_SetPrescaler(LPTIM,LPTIM_PRESCALER_DIV1);          
    LPTIM_EnableIT_CMPOK(LPTIM);
    LPTIM_Enable(LPTIM);
    /* config ARR ande compare register */ 
    LPTIM_SetAutoReload(LPTIM,600);        
    LPTIM_SetCompare(LPTIM,300);
    LPTIM_StartCounter(LPTIM,LPTIM_OPERATING_MODE_CONTINUOUS);  
    while (1)
    {    
    }
}
/**
 * @brief  output IO Initaliza.
 * @param NONE.
 *   This parameter can be one of following parameters:
 *     @arg NONE
 */
void LPTIM_OutputIoInit(void)
{
    GPIO_InitType GPIO_InitStructure;
    GPIO_InitStruct(&GPIO_InitStructure);
    /* Enable the GPIO Clock */
    RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_AFIO  | RCC_APB2_PERIPH_GPIOA, ENABLE);

    /* Configure the GPIO pin */
    GPIO_InitStructure.Pin        = GPIO_PIN_9;
    GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_AF_PP;
    GPIO_InitStructure.GPIO_Alternate = GPIO_AF9_LPTIM;
    GPIO_InitPeripheral(GPIOA, &GPIO_InitStructure);
}
