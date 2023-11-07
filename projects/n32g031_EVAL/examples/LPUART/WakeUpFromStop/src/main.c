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
#include <stdio.h>
#include "main.h"

/** @addtogroup N32G031_StdPeriph_Examples
 * @{
 */

/** @addtogroup LPUART_WakeUpFromStop
 * @{
 */

LPUART_InitType LPUART_InitStructure;

/* Buffer used for confirmation messages transmission */
uint8_t TxBuffer1[] = "Start bit detection wake-up successful";
uint8_t TxBuffer2[] = "RXNE detection wake-up successful";
uint8_t TxBuffer3[] = "A configurable received byte match wake-up successful";
uint8_t TxBuffer4[] = "A programmed 4-Byte frame match wake-up successful";
uint32_t WakeUpTrigger[] = {0x5A, 0x1E2D3C4B}; // Wake-Up Data: 5A or 4B3C2D1E

/**
 * @brief  Main program
 */
int main(void)
{
    /* Keep Debugger Connection during STOP Mode */
    RCC_EnableAPB1PeriphClk(RCC_APB1_PERIPH_PWR, ENABLE);
    DBG_ConfigPeriph(DBG_STOP, ENABLE);

    /* Configure the GPIO ports */
    GPIO_Configuration();

    /* System Clocks Configuration */
    RCC_Configuration(RCC_LPUARTCLK_SRC_LSE);

    /* Configure EXTI Line 22 */
    EXTI_Configuration();

    /* LPUART configuration ------------------------------------------------------*/
    LPUART_DeInit();
    LPUART_InitStructure.BaudRate            = 9600;
    LPUART_InitStructure.Parity              = LPUART_PE_NO;
    LPUART_InitStructure.RtsThreshold        = LPUART_RTSTH_FIFOFU;
    LPUART_InitStructure.HardwareFlowControl = LPUART_HFCTRL_NONE;
    LPUART_InitStructure.Mode                = LPUART_MODE_RX | LPUART_MODE_TX;

    /* Configure LPUARTx */
    LPUART_Init(&LPUART_InitStructure);

    /*##-1- Wake Up second step  ###############################################*/
    printf("\n\r##-1-Start Bit Detection Wake-Up##\n\r");
    /* Set the Wake-Up Event: specify wake-up on start bit */
    LPUART_ConfigWakeUpMethod(LPUART_WUSTP_STARTBIT);
    /* Enable the LPUARTx Wake UP from STOP Mode Interrupt */
    LPUART_ConfigInt(LPUART_INT_WUF, ENABLE);
    /* Enable MCU Wake-up by LPUARTx */
    LPUART_EnableWakeUpStop(ENABLE);
    /* Enter STOP Mode */
    PWR_EnterSTOPMode(PWR_STOPENTRY_WFI);
    /* ... STOP Mode ... */
    /* Wake Up based on Start Bit Detection successful */
    LPUART_EnableWakeUpStop(DISABLE);
    /* Output a message on Hyperterminal using printf function */
    printf("\n\rStart bit detection wake-up successful\n\r");

    /* Configures the System clock frequency */
    RCC_SetSysClock();
    /* Configure LPUARTx */
    LPUART_Init(&LPUART_InitStructure);

    /*##-2- Wake Up second step  ###############################################*/
    printf("\n\r##-2-RXNE Detection Wake-Up##\n\r");
    /* Set the Wake-Up Event: specify wake-up on RXNE flag */
    LPUART_ConfigWakeUpMethod(LPUART_WUSTP_RXNE);
    /* Enable the LPUART Wake UP from STOP Mode Interrupt */
    LPUART_ConfigInt(LPUART_INT_WUF, ENABLE);
    /* Enable MCU Wake-Up by LPUARTx */
    LPUART_EnableWakeUpStop(ENABLE);
    /* Enter STOP Mode */
    PWR_EnterSTOPMode(PWR_STOPENTRY_WFI);
    /* ... STOP Mode ... */
    /* Wake Up based on RXNE Detection successful */
    LPUART_EnableWakeUpStop(DISABLE);
    /* Output a message on Hyperterminal using printf function */
    printf("\n\rRXNE detection wake-up successful\n\r");

    /* Configures the System clock frequency */
    RCC_SetSysClock();
    /* Configure LPUARTx */
    LPUART_Init(&LPUART_InitStructure);

    /*##-3- Wake Up second step  ###############################################*/
    printf("\n\r##-3-A Configurable Received Byte Match Wake-Up##\n\r");
    /* Set the Wake-Up Event: specify wake-up on a configurable received byte match */
    LPUART_ConfigWakeUpMethod(LPUART_WUSTP_BYTE);
    /* Set the Wake-Up Data */
    LPUART_ConfigWakeUpData((uint8_t)WakeUpTrigger[0]);
    /* Enable the LPUARTx Wake UP from STOP mode Interrupt */
    LPUART_ConfigInt(LPUART_INT_WUF, ENABLE);
    /* Enable MCU Wake-Up by LPUARTx */
    LPUART_EnableWakeUpStop(ENABLE);
    /* Enter STOP Mode */
    PWR_EnterSTOPMode(PWR_STOPENTRY_WFI);
    /* ... STOP Mode ... */
    /* Wake Up based on a Configurable Received Byte Match successful */
    LPUART_EnableWakeUpStop(DISABLE);
    /* Output a message on Hyperterminal using printf function */
    printf("\n\rA configurable received byte match wake-up successful\n\r");

    /* Configures the System clock frequency */
    RCC_SetSysClock();
    /* Configure LPUARTx */
    LPUART_Init(&LPUART_InitStructure);

    /*##-4- Wake Up second step  ###############################################*/
    printf("\n\r##-4-A Programmed 4-Byte Frame Match Wake-Up##\n\r");
    /* Set the Wake-Up Event: specify wake-up on a programmed 4-Byte frame */
    LPUART_ConfigWakeUpMethod(LPUART_WUSTP_FRAME);
    /* Set the Wake-Up Data */
    LPUART_ConfigWakeUpData(WakeUpTrigger[1]);
    /* Enable the LPUARTx Wake UP from STOP mode Interrupt */
    LPUART_ConfigInt(LPUART_INT_WUF, ENABLE);
    /* Enable MCU Wake-Up by LPUARTx */
    LPUART_EnableWakeUpStop(ENABLE);
    /* Enter STOP Mode */
    PWR_EnterSTOPMode(PWR_STOPENTRY_WFI);
    /* ... STOP Mode ... */
    /* Wake Up based on a Programmed 4-Byte Frame Match successful */
    LPUART_EnableWakeUpStop(DISABLE);    
    /* Output a message on Hyperterminal using printf function */
    printf("\n\rA programmed 4-Byte frame match wake-up successful\n\r");

    while (1)
    {
    }
}

/**
 * @brief Configures the System clock frequency.
 * 
 */
void RCC_SetSysClock(void)
{
    /* Configures the PLL clock source and multiplication factor(SYSCLK_USE_HSI_PLL), SYSCLK_FREQ = 48MHz */
    RCC_ConfigPll(RCC_PLL_SRC_HSI, RCC_PLL_MUL_6, RCC_PLL_PRE_1, RCC_PLLOUT_DIV_1);

    /* Configures the system clock */
    RCC_ConfigSysclk(RCC_SYSCLK_SRC_PLLCLK);    
}

/**
 * @brief  Configures the different system clocks.
 * @param  LPUART_CLK_SRC: specifies the LPUARTx clock source.
 */
void RCC_Configuration(uint32_t LPUART_CLK_SRC)
{
    /* Enable GPIO clock */
    RCC_EnableAPB2PeriphClk(LPUARTx_GPIO_CLK, ENABLE);

    switch(LPUART_CLK_SRC)
    {
        case RCC_LPUARTCLK_SRC_HSI:
        {
            /* Configures the High Speed Internal RC clock (HSI) */
            RCC_EnableHsi(ENABLE);
            while (RCC_WaitHsiStable() != SUCCESS)
            {
            }
            /* Specifies the LPUARTx clock source, HSI selected as LPUARTx clock */
            RCC_ConfigLPUARTClk(RCC_LPUARTCLK_SRC_HSI);
        }
        break;
        case RCC_LPUARTCLK_SRC_HSE:
        {
            /* Configures the External High Speed oscillator (HSE) */
            RCC_ConfigHse(RCC_HSE_ENABLE);
            while (RCC_WaitHseStable() != SUCCESS)
            {
            }
            /* Specifies the LPUARTx clock source, HSE selected as LPUARTx clock */
            RCC_ConfigLPUARTClk(RCC_LPUARTCLK_SRC_HSE);
        }
        break;
        case RCC_LPUARTCLK_SRC_LSI:
        {
            /* Enables the Internal Low Speed oscillator (LSI) */
            RCC_EnableLsi(ENABLE);
            while (RCC_GetFlagStatus(RCC_LSCTRL_FLAG_LSIRD) == RESET)
            {
            }
            /* Specifies the LPUARTx clock source, LSI selected as LPUARTx clock */
            RCC_ConfigLPUARTClk(RCC_LPUARTCLK_SRC_LSI);
        }
        break;
        case RCC_LPUARTCLK_SRC_LSE:
        {  
            /* Configures the External Low Speed oscillator (LSE) */
            RCC_ConfigLse(RCC_LSE_ENABLE,0x01);
            while (RCC_GetFlagStatus(RCC_LSCTRL_FLAG_LSERD) == RESET)
            {
            }
            /* Specifies the LPUARTx clock source, LSE selected as LPUARTx clock */
            RCC_ConfigLPUARTClk(RCC_LPUARTCLK_SRC_LSE);
        }
        break;        
        case RCC_LPUARTCLK_SRC_SYSCLK:
        {
            /* Specifies the LPUARTx clock source, SYSCLK selected as LPUART clock */
            RCC_ConfigLPUARTClk(RCC_LPUARTCLK_SRC_SYSCLK);
        }
        break;
        default:
        {
            /* Specifies the LPUART clock source, APB1 selected as LPUART clock */
            RCC_ConfigLPUARTClk(RCC_LPUARTCLK_SRC_APB1);
        }
        break;
    }    
    
    /* Enable LPUARTx Clock */
    RCC_EnableAPB1PeriphClk(LPUARTx_RCC_CLK, ENABLE);
}

/**
 * @brief  Configures the different GPIO ports.
 */
void GPIO_Configuration(void)
{
    GPIO_InitType GPIO_InitStructure;

    /* Enable GPIO clock */
    RCC_EnableAPB2PeriphClk(LPUARTx_GPIO_CLK | RCC_APB2_PERIPH_AFIO, ENABLE);       

    /* Initialize GPIO_InitStructure */
    GPIO_InitStruct(&GPIO_InitStructure);

    /* Configure LPUARTx Tx as alternate function push-pull */
    GPIO_InitStructure.Pin            = LPUARTx_TxPin;
    GPIO_InitStructure.GPIO_Mode      = GPIO_MODE_AF_PP;
    GPIO_InitStructure.GPIO_Alternate = LPUARTx_Tx_GPIO_AF;
    GPIO_InitPeripheral(LPUARTx_GPIO, &GPIO_InitStructure);

    /* Configure LPAURTx Rx as alternate function push-pull and pull-up */
    GPIO_InitStructure.Pin            = LPUARTx_RxPin;  
    GPIO_InitStructure.GPIO_Pull      = GPIO_PULL_UP;
    GPIO_InitStructure.GPIO_Alternate = LPUARTx_Rx_GPIO_AF;    
    GPIO_InitPeripheral(LPUARTx_GPIO, &GPIO_InitStructure);
}

/**
 * @brief  Configures the nested vectored interrupt controller.
 */
void NVIC_Configuration(void)
{
    NVIC_InitType NVIC_InitStructure;

    /* Enable the LPUARTx Wakeup Interrupt through EXTI line 22 */
    NVIC_InitStructure.NVIC_IRQChannel                   = LPUART_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPriority           = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

/**
 * @brief  Configure EXTI_LINE23 as EXTI_Line and set the Priority.
 */
void EXTI_Configuration(void)
{    
    EXTI_InitType EXTI_InitStructure;

    /* Configure NVIC */
    NVIC_Configuration();
    
    EXTI_InitStructure.EXTI_Line    = EXTI_LINE22;
    EXTI_InitStructure.EXTI_Mode    = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_InitPeripheral(&EXTI_InitStructure);
}

/**
 * @brief  Inserts a delay time.
 * @param nCount specifies the delay time length.
 */
void Delay(__IO uint32_t nCount)
{
    /* Decrement nCount value */
    for (; nCount != 0; nCount--)
        ;
}

/* retarget the C library printf function to the LPUART */
int fputc(int ch, FILE* f)
{
    LPUART_SendData((uint8_t)ch);
    while (LPUART_GetFlagStatus(LPUART_FLAG_TXC) == RESET)
        ;
    LPUART_ClrFlag(LPUART_FLAG_TXC);      

    return (ch);
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
