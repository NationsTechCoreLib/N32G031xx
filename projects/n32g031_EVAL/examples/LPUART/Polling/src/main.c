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

/** @addtogroup LPUART_Polling
 * @{
 */

#define TxBufferSize1 (countof(TxBuffer1))
#define TxBufferSize2 (countof(TxBuffer2))

#define countof(a) (sizeof(a) / sizeof(*(a)))

LPUART_InitType LPUART_InitStructure;
USART_InitType USART_InitStructure;
uint8_t TxBuffer1[] = "Buffer Send from LPUARTy to USARTz using Flags";
uint8_t RxBuffer1[TxBufferSize1];
uint8_t TxBuffer2[] = "Buffer Send from USARTz to LPUARTy using Flags";
uint8_t RxBuffer2[TxBufferSize2];
__IO uint8_t TxCounter1 = 0, RxCounter1 = 0;
__IO uint8_t TxCounter2 = 0, RxCounter2 = 0;
volatile TestStatus TransferStatus1 = FAILED, TransferStatus2 = FAILED;

/**
 * @brief  Main program
 */
int main(void)
{
    /* Configure the GPIO ports */
    GPIO_Configuration();

    /* System Clocks Configuration */
    RCC_Configuration(RCC_LPUARTCLK_SRC_SYSCLK);

    /* LPUARTy and USARTz configuration ------------------------------------------------------*/
    
    USART_DeInit(USARTz);
    USART_InitStructure.BaudRate            = 115200;
    USART_InitStructure.WordLength          = USART_WL_8B;
    USART_InitStructure.StopBits            = USART_STPB_1;
    USART_InitStructure.Parity              = USART_PE_NO;
    USART_InitStructure.HardwareFlowControl = USART_HFCTRL_NONE;
    USART_InitStructure.Mode                = USART_MODE_RX | USART_MODE_TX;
    /* Configure USARTz */
    USART_Init(USARTz, &USART_InitStructure);
    /* Enable the USARTz */
    USART_Enable(USARTz, ENABLE);

    /* Wait for some delay */
    Delay(0x2FFFF);

    LPUART_DeInit();
    LPUART_InitStructure.BaudRate            = 115200;
    LPUART_InitStructure.Parity              = LPUART_PE_NO;
    LPUART_InitStructure.RtsThreshold        = LPUART_RTSTH_FIFOFU;
    LPUART_InitStructure.HardwareFlowControl = LPUART_HFCTRL_NONE;
    LPUART_InitStructure.Mode                = LPUART_MODE_RX | LPUART_MODE_TX;    
    /* Configure LPUARTy */
    LPUART_Init(&LPUART_InitStructure);

    while (TxCounter1 < TxBufferSize1)
    {
        /* Send one byte from LPUARTy to USARTz */
        LPUART_SendData(TxBuffer1[TxCounter1++]);

        /* Loop until USARTy DAT register is empty */
        while (LPUART_GetFlagStatus(LPUART_FLAG_TXC) == RESET)
        {
        }
        LPUART_ClrFlag(LPUART_FLAG_TXC); 

        /* Loop until the USARTz Receive Data Register is not empty */
        while (USART_GetFlagStatus(USARTz, USART_FLAG_RXDNE) == RESET)
        {
        }        
        /* Store the received byte in RxBuffer */
        RxBuffer2[RxCounter2++] = USART_ReceiveData(USARTz);
    }     
   
    while (TxCounter2 < TxBufferSize1)
    {
        /* Send one byte from USARTz to LPUARTy */
        USART_SendData(USARTz, TxBuffer2[TxCounter2++]);
        /* Loop until USARTz DAT register is empty */
        while (USART_GetFlagStatus(USARTz, USART_FLAG_TXDE) == RESET)
        {
        }

        /* Loop until the LPUARTy Receive Data Register is not empty */
        while (LPUART_GetFlagStatus(LPUART_FLAG_FIFO_NE) == RESET)
        {
        }
        /* Store the received byte in RxBuffer */
        RxBuffer1[RxCounter1++] = LPUART_ReceiveData();
    }

    /* Check the received data with the send ones */
    /* TransferStatus = PASSED, if the data transmitted from LPUARTy and
       received by USARTz are the same */
    /* TransferStatus = FAILED, if the data transmitted from LPUARTy and
       received by USARTz are different */
    TransferStatus1 = Buffercmp(TxBuffer1, RxBuffer2, TxBufferSize1);

    /* Check the received data with the send ones */
    /* TransferStatus = PASSED, if the data transmitted from USARTz and
       received by LPUARTy are the same */
    /* TransferStatus = FAILED, if the data transmitted from USARTz and
       received by LPUARTy are different */
    TransferStatus2 = Buffercmp(TxBuffer2, RxBuffer1, TxBufferSize2);

    while (1)
    {
    }
}

/**
 * @brief  Configures the different system clocks.
 * @param  LPUART_CLK_SRC: specifies the LPUARTy clock source.
 */
void RCC_Configuration(uint32_t LPUART_CLK_SRC)
{
    /* Enable GPIO clock */
    RCC_EnableAPB2PeriphClk(LPUARTy_GPIO_CLK | USARTz_GPIO_CLK, ENABLE);

    switch(LPUART_CLK_SRC)
    {
        case RCC_LPUARTCLK_SRC_HSI:
        {
            /* Configures the High Speed Internal RC clock (HSI) */
            RCC_EnableHsi(ENABLE);
            while (RCC_WaitHsiStable() != SUCCESS)
            {
            }
            /* Specifies the LPUARTy clock source, HSI selected as LPUART clock */
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
            /* Specifies the LPUARTy clock source, HSE selected as LPUARTy clock */
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
            /* Specifies the LPUARTy clock source, LSI selected as LPUARTy clock */
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
            /* Specifies the LPUARTy clock source, LSE selected as LPUARTy clock */
            RCC_ConfigLPUARTClk(RCC_LPUARTCLK_SRC_LSE);
        }
        break;        
        case RCC_LPUARTCLK_SRC_SYSCLK:
        {
            /* Specifies the LPUARTy clock source, SYSCLK selected as LPUARTy clock */
            RCC_ConfigLPUARTClk(RCC_LPUARTCLK_SRC_SYSCLK);
        }
        break;
        default:
        {
            /* Specifies the LPUARTy clock source, APB1 selected as LPUARTy clock */
            RCC_ConfigLPUARTClk(RCC_LPUARTCLK_SRC_APB1);
        }
        break;
    }    
    
    /* Enable LPUARTy Clock */
    RCC_EnableAPB1PeriphClk(LPUARTy_RCC_CLK, ENABLE);
    /* Enable USARTz Clock */
    USARTz_APBxClkCmd(USARTz_CLK, ENABLE);
}

/**
 * @brief  Configures the different GPIO ports.
 */
void GPIO_Configuration(void)
{
    GPIO_InitType GPIO_InitStructure;

    /* Enable GPIO clock */
    RCC_EnableAPB2PeriphClk(LPUARTy_GPIO_CLK | USARTz_GPIO_CLK, ENABLE);

    /* Initialize GPIO_InitStructure */
    GPIO_InitStruct(&GPIO_InitStructure);    

    /* Configure LPUARTy Tx as alternate function push-pull */
    GPIO_InitStructure.Pin            = LPUARTy_TxPin;
    GPIO_InitStructure.GPIO_Mode      = GPIO_MODE_AF_PP;
    GPIO_InitStructure.GPIO_Alternate = LPUARTy_Tx_GPIO_AF;
    GPIO_InitPeripheral(LPUARTy_GPIO, &GPIO_InitStructure);

    /* Configure USARTz Tx as alternate function push-pull */
    GPIO_InitStructure.Pin            = USARTz_TxPin;
    GPIO_InitStructure.GPIO_Alternate = USARTz_Tx_GPIO_AF;
    GPIO_InitPeripheral(USARTz_GPIO, &GPIO_InitStructure);    

    /* Configure LPUARTy Rx as alternate function push-pull and pull-up */
    GPIO_InitStructure.Pin            = LPUARTy_RxPin;  
    GPIO_InitStructure.GPIO_Pull      = GPIO_PULL_UP;  
    GPIO_InitStructure.GPIO_Alternate = LPUARTy_Rx_GPIO_AF;
    GPIO_InitPeripheral(LPUARTy_GPIO, &GPIO_InitStructure);

    /* Configure USARTz Rx as alternate function push-pull and pull-up */
    GPIO_InitStructure.Pin            = USARTz_RxPin;
    GPIO_InitStructure.GPIO_Alternate = USARTz_Rx_GPIO_AF;
    GPIO_InitPeripheral(USARTz_GPIO, &GPIO_InitStructure); 
}    

/**
 * @brief  Compares two buffers.
 * @param  pBuffer1, pBuffer2: buffers to be compared.
 * @param BufferLength buffer's length
 * @return PASSED: pBuffer1 identical to pBuffer2
 *         FAILED: pBuffer1 differs from pBuffer2
 */
TestStatus Buffercmp(uint8_t* pBuffer1, uint8_t* pBuffer2, uint16_t BufferLength)
{
    while (BufferLength--)
    {
        if (*pBuffer1 != *pBuffer2)
        {
            return FAILED;
        }

        pBuffer1++;
        pBuffer2++;
    }

    return PASSED;
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
