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
 * @version v1.0.1
 *
 * @copyright Copyright (c) 2019, Nations Technologies Inc. All rights reserved.
 */
#define BIT0                     ((uint32_t)1 << 0)
#define BIT1                     ((uint32_t)1 << 1)
#define BIT2                     ((uint32_t)1 << 2)
#define BIT3                     ((uint32_t)1 << 3)
#define BIT4                     ((uint32_t)1 << 4)
#define BIT5                     ((uint32_t)1 << 5)
#define BIT6                     ((uint32_t)1 << 6)
#define BIT7                     ((uint32_t)1 << 7)
#define BIT8                     ((uint32_t)1 << 8)
#define BIT9                     ((uint32_t)1 << 9)
#define BIT10                    ((uint32_t)1 << 10)
#define BIT11                    ((uint32_t)1 << 11)
#define BIT12                    ((uint32_t)1 << 12)
#define BIT13                    ((uint32_t)1 << 13)
#define BIT14                    ((uint32_t)1 << 14)
#define BIT15                    ((uint32_t)1 << 15)
#define BIT16                    ((uint32_t)1 << 16)
#define BIT17                    ((uint32_t)1 << 17)
#define BIT18                    ((uint32_t)1 << 18)
#define BIT19                    ((uint32_t)1 << 19)
#define BIT20                    ((uint32_t)1 << 20)
#define BIT21                    ((uint32_t)1 << 21)
#define BIT22                    ((uint32_t)1 << 22)
#define BIT23                    ((uint32_t)1 << 23)
#define BIT24                    ((uint32_t)1 << 24)
#define BIT25                    ((uint32_t)1 << 25)
#define BIT26                    ((uint32_t)1 << 26)
#define BIT27                    ((uint32_t)1 << 27)
#define BIT28                    ((uint32_t)1 << 28)
#define BIT29                    ((uint32_t)1 << 29)
#define BIT30                    ((uint32_t)1 << 30)
#define BIT31                    ((uint32_t)1 << 31)
#define SetBitMsk(reg, bit, msk) ((reg) = ((reg) & ~(msk) | (bit)))
#define ClrBit(reg, bit)         ((reg) &= ~(bit))
#define SetBit(reg, bit)         ((reg) |= (bit))
#define GetBit(reg, bit)         ((reg) & (bit))

#include "main.h"

/** @addtogroup ADC_3ADCs_DMA
 * @{
 */

void RCC_Configuration(void);
void GPIO_Configuration(void);
void COMP_Configuratoin(void);
void ChangeVmVp(void);
/**
 * @brief COMP Interrupt.
 * @param Cmd Interrupt enable or disable
 */
void COMPNVIC_Config(FunctionalState Cmd)
{
    
    EXTI_InitType EXTI_InitStructure;
    NVIC_InitType NVIC_InitStructure;

    EXTI_ClrITPendBit(EXTI_LINE18);
    EXTI_InitStructure.EXTI_Line = EXTI_LINE18;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_InitPeripheral(&EXTI_InitStructure);

    /* Enable the RTC Alarm Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel                   = COMP_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPriority           = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd                = Cmd;
    NVIC_Init(&NVIC_InitStructure);
}
/**
 * @brief   Main program
 */
int main(void)
{
    /* System clocks configuration ---------------------------------------------*/
    RCC_Configuration();

    /* GPIO configuration ------------------------------------------------------*/
    GPIO_Configuration();

    /* COMP configuration ------------------------------------------------------*/
    COMP_Configuratoin();
	
	/* interrupt configuration ------------------------------------------------------*/
    COMP_ClrIntStatus(COMP_INTSTS_CMP1IS_STATUS);
	COMPNVIC_Config(ENABLE);
	
    while (1)
    {
        ChangeVmVp();
    }
}

/**
 * @brief  Self Generate Puls ,by skip line connect to vp and vm if need.
 */
void ChangeVmVp(void)
{
    GPIO_SetBits(GPIOA, GPIO_PIN_2);
    GPIO_ResetBits(GPIOA, GPIO_PIN_3);
    {
        uint32_t i = 0;
        while (i++ < 1000)
            ;
    }
    GPIO_ResetBits(GPIOA, GPIO_PIN_2);
    GPIO_SetBits(GPIOA, GPIO_PIN_3);
    {
        uint32_t i = 0;
        while (i++ < 1000)
            ;
    }
}
/**
 * @brief  Configures the comp module.
 */
void COMP_Configuratoin(void)
{
    COMP_InitType COMP_Initial;

    /*Initial comp*/
    COMP_StructInit(&COMP_Initial);
    COMP_Initial.InpSel     = COMP_CTRL_INPSEL_PA1;
    COMP_Initial.InmSel     = COMP_CTRL_INMSEL_PA0;
    COMP_Initial.SampWindow = COMPX_FILC_SAMPW_30;
    COMP_Initial.Thresh     = COMPX_FILC_THRESH_16;
    COMP_Init( &COMP_Initial);
	COMP_ConfigInt(COMP_INTEN_CMP1IEN_CFG, ENABLE);
    COMP_Enable( COMP_CTRL_EN_ENABLE);
}

/**
 * @brief  Configures the different system clocks.
 */
void RCC_Configuration(void)
{
    /* Enable COMPE clocks */
    RCC_EnableAPB1PeriphClk(RCC_APB1_PERIPH_COMP | RCC_APB1_PERIPH_COMPFILT, ENABLE);
    /* Enable GPIOA, GPIOB, GPIOC and GPIOD clocks */
    RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOA ,ENABLE);
}

/**
 * @brief  Configures the different GPIO ports.
 */
void GPIO_Configuration(void)
{
    GPIO_InitType GPIO_InitStructure;
    
    GPIO_InitStruct(&GPIO_InitStructure);
    // INP
    GPIO_InitStructure.Pin            = GPIO_PIN_1;
    GPIO_InitStructure.GPIO_Mode      = GPIO_MODE_ANALOG;
    GPIO_InitStructure.GPIO_Current   = GPIO_DC_LOW;
    GPIO_InitPeripheral(GPIOA, &GPIO_InitStructure);
    // INM
    GPIO_InitStructure.Pin = GPIO_PIN_0;
    GPIO_InitPeripheral(GPIOA, &GPIO_InitStructure);

    // OutSel
    // PA6
    GPIO_InitStructure.GPIO_Mode      = GPIO_MODE_AF_PP;
    GPIO_InitStructure.Pin            = GPIO_PIN_6;
    GPIO_InitStructure.GPIO_Alternate = GPIO_AF8_COMP;
    GPIO_InitPeripheral(GPIOA, &GPIO_InitStructure);
    
    // GPIO PA2 PA3
    GPIO_InitStructure.Pin            = GPIO_PIN_2 | GPIO_PIN_3;
    GPIO_InitStructure.GPIO_Mode      = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStructure.GPIO_Current   = GPIO_DC_LOW;
    GPIO_InitPeripheral(GPIOA, &GPIO_InitStructure);
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
