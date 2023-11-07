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
 * @file main.h
 * @author ..\readme.txt
 * @version v1.0.0
 *
 * @copyright Copyright (c) 2019, ..\readme.txt Technologies Inc. All rights reserved.
 */
#ifndef __MAIN_H__
#define __MAIN_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "n32g031.h"

#define _USART1_SPI1_

#ifdef _USART1_SPI1_
#define USARTy              USART1
#define USARTy_CLK          RCC_APB2_PERIPH_USART1
#define USARTy_GPIO         GPIOA
#define USARTy_GPIO_CLK     RCC_APB2_PERIPH_GPIOA
#define USARTy_RxPin        GPIO_PIN_10
#define USARTy_TxPin        GPIO_PIN_9
#define USARTy_ClkPin       GPIO_PIN_8
#define USARTy_Rx_GPIO_AF   GPIO_AF4_USART1
#define USARTy_Tx_GPIO_AF   GPIO_AF4_USART1
#define USARTy_Clk_GPIO_AF  GPIO_AF4_USART1
#define USARTy_APBxClkCmd   RCC_EnableAPB2PeriphClk

#define SPIy                SPI1
#define SPIy_CLK            RCC_APB2_PERIPH_SPI1
#define SPIy_GPIO           GPIOA
#define SPIy_GPIO_CLK       RCC_APB2_PERIPH_GPIOA
#define SPIy_SCKPin         GPIO_PIN_5
#define SPIy_MISOPin        GPIO_PIN_6
#define SPIy_MOSIPin        GPIO_PIN_7
#define SPIy_SCK_GPIO_AF    GPIO_AF0_SPI1
#define SPIy_MISO_GPIO_AF   GPIO_AF0_SPI1
#define SPIy_MOSI_GPIO_AF   GPIO_AF0_SPI1
#define SPIy_APBxClkCmd     RCC_EnableAPB2PeriphClk
#endif

typedef enum
{
    FAILED = 0,
    PASSED = !FAILED
} TestStatus;

void RCC_Configuration(void);
void GPIO_Configuration(void);
void SPI_Configuration(void);
TestStatus Buffercmp(uint8_t* pBuffer1, uint8_t* pBuffer2, uint16_t BufferLength);

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H__ */
