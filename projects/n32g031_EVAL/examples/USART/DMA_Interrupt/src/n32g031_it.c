/*****************************************************************************
 * Copyright (c) 2019, ..\readme.txt Technologies Inc.
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
 * ..\readme.txt' name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ..\readme.txt "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ..\readme.txt BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ****************************************************************************/

/**
 * @file n32g031_it.c
 * @author ..\readme.txt
 * @version v1.0.0
 *
 * @copyright Copyright (c) 2019, ..\readme.txt Technologies Inc. All rights reserved.
 */
#include "n32g031_it.h"
#include "main.h"

/** @addtogroup N32G031_StdPeriph_Template
 * @{
 */

extern __IO uint8_t USARTy_Tx_Done, USARTy_Rx_Done;
extern __IO uint8_t USARTz_Tx_Done, USARTz_Rx_Done;

/******************************************************************************/
/*            Cortex-M0 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
 * @brief  This function handles NMI exception.
 */
void NMI_Handler(void)
{
}

/**
 * @brief  This function handles Hard Fault exception.
 */
void HardFault_Handler(void)
{
    /* Go to infinite loop when Hard Fault exception occurs */
    while (1)
    {
    }
}

/**
 * @brief  This function handles SVCall exception.
 */
void SVC_Handler(void)
{
}

/**
 * @brief  This function handles PendSV_Handler exception.
 */
void PendSV_Handler(void)
{
}

/**
 * @brief  This function handles SysTick Handler.
 */
void SysTick_Handler(void)
{
}

/******************************************************************************/
/*                 N32G031 Peripherals Interrupt Handlers                     */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_n32g031.s).                                                 */
/******************************************************************************/

/**
 * @brief  This function handles USARTy_Tx or USARTz_Rx DMA global interrupt request.
 */
void DMA_Channel3_4_IRQHandler(void)
{
    if(DMA_GetIntStatus(USARTy_Tx_DMA_INT, DMA) != RESET)
    {
        USARTy_Tx_Done = 1;

        DMA_ConfigInt(USARTy_Tx_DMA_Channel, DMA_INT_TXC, DISABLE);
        DMA_ClrIntPendingBit(USARTy_Tx_DMA_INT, DMA);         
    }   

    if(DMA_GetIntStatus(USARTz_Rx_DMA_INT, DMA) != RESET)
    {
        USARTz_Rx_Done = 1;

        DMA_ConfigInt(USARTz_Rx_DMA_Channel, DMA_INT_TXC, DISABLE);
        DMA_ClrIntPendingBit(USARTz_Rx_DMA_INT, DMA);         
    }     
}

/**
 * @brief  This function handles USARTy_Rx DMA global interrupt request.
 */
void USARTy_Rx_DMA_IRQHandler(void)
{
   if(DMA_GetIntStatus(USARTy_Rx_DMA_INT, DMA) != RESET)
   {
       USARTy_Rx_Done = 1;

       DMA_ConfigInt(USARTy_Rx_DMA_Channel, DMA_INT_TXC, DISABLE);
       DMA_ClrIntPendingBit(USARTy_Rx_DMA_INT, DMA);         
   }     
}

/**
 * @brief  This function handles USARTz_Tx DMA global interrupt request.
 */
void USARTz_Tx_DMA_IRQHandler(void)
{
    if(DMA_GetIntStatus(USARTz_Tx_DMA_INT, DMA) != RESET)
    {
        USARTz_Tx_Done = 1;

        DMA_ConfigInt(USARTz_Tx_DMA_Channel, DMA_INT_TXC, DISABLE);
        DMA_ClrIntPendingBit(USARTz_Tx_DMA_INT, DMA);         
    }     
}

/**
 * @brief  This function handles PPP interrupt request.
 */
/*void PPP_IRQHandler(void)
{
}*/

/**
 * @}
 */
