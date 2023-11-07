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
#include "n32g031.h"
#include "log.h"

GPIO_InitType GPIO_InitStructure;
RCC_ClocksType RCC_ClockFreq;
ErrorStatus HSEStartUpStatus;
ErrorStatus HSIStartUpStatus;

void NVIC_Configuration(void);



#define SYSCLK_USE_HSI     0
#define SYSCLK_USE_HSE     1
#define SYSCLK_USE_HSI_PLL 2
#define SYSCLK_USE_HSE_PLL 3
#define SYSCLK_USE_LSE     4
#define SYSCLK_USE_LSI     5


void SetSysClockToHSI(void);
void SetSysClockToHSE(void);
void SetSysClockToPLL(uint32_t freq, uint8_t src);
void SetSysClock_LSI(void);
void SetSysClock_LSE(void);
void DumpClock(const char* msg)
{
    log_init(); // should reinit after sysclk changed
    log_info("--------------------------------\n");
    log_info("%s:\n", msg);
    RCC_GetClocksFreqValue(&RCC_ClockFreq);
    log_info("SYSCLK: %d\n", RCC_ClockFreq.SysclkFreq);
    log_info("HCLK: %d\n", RCC_ClockFreq.HclkFreq);
    log_info("PCLK1: %d\n", RCC_ClockFreq.Pclk1Freq);
    log_info("PCLK2: %d\n", RCC_ClockFreq.Pclk2Freq);
}

int main(void)
{

      DumpClock("After reset");
	
///*** Select one of the following configuration methods ***///
  /* Method 1  */	
//    SetSysClockToHSI();
//    DumpClock("HSI, 8MHz");

  /* Method 2  */		
//    SetSysClockToHSE();
//    DumpClock("HSE, 8MHz");

	/* Method 3  */	
//    SetSysClock_LSI();
//    DumpClock("LSI, 30K");

	/* Method 4  */	
//    SetSysClock_LSE();
//    DumpClock("LSE, 32.768K");

  /* Method 5  */	
    SetSysClockToPLL(32000000, SYSCLK_USE_HSE);
    DumpClock("HSE->PLL, 32M");
		
  /* Method 6  */	
//    SetSysClockToPLL(48000000, SYSCLK_USE_HSI);
//    DumpClock("HSE->PLL, 48M");

    /* Enable Clock Security System(CSS): this will generate an NMI exception
       when HSE clock fails */
    RCC_EnableClockSecuritySystem(ENABLE);

    /* NVIC configuration
     * ------------------------------------------------------*/
    NVIC_Configuration();

    /* Output HSE clock on MCO pin
     * ---------------------------------------------*/
    RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOA, ENABLE);

    GPIO_InitStruct(&GPIO_InitStructure);
    GPIO_InitStructure.Pin             = GPIO_PIN_8;
    GPIO_InitStructure.GPIO_Mode       = GPIO_MODE_AF_PP;
    GPIO_InitStructure.GPIO_Alternate  = GPIO_AF5_MCO;
    GPIO_InitPeripheral(GPIOA, &GPIO_InitStructure);

    RCC_ConfigMcoClkPre(RCC_MCO_CLK_DIV8);
///*** Select the corresponding MCO clock source ***///
    RCC_ConfigMco(RCC_MCO_PLLCLK_PRES);

    while (1);
}

/**
 * @brief  Selects HSI as System clock source and configure HCLK, PCLK2
 *         and PCLK1 prescalers.
 */
void SetSysClockToHSI(void)
{
    RCC_DeInit();

    RCC_EnableHsi(ENABLE);

    /* Wait till HSI is ready */
    HSIStartUpStatus = RCC_WaitHsiStable();

    if (HSIStartUpStatus == SUCCESS)
    {
        /* Enable Prefetch Buffer */
        FLASH_PrefetchBufSet(FLASH_PrefetchBuf_EN);

        /* Flash 0 wait state */
        FLASH_SetLatency(FLASH_LATENCY_0);

        /* HCLK = SYSCLK */
        RCC_ConfigHclk(RCC_SYSCLK_DIV1);

        /* PCLK2 = HCLK */
        RCC_ConfigPclk2(RCC_HCLK_DIV1);

        /* PCLK1 = HCLK */
        RCC_ConfigPclk1(RCC_HCLK_DIV1);

        /* Select HSI as system clock source */
        RCC_ConfigSysclk(RCC_SYSCLK_SRC_HSI);
           
        /* Wait till HSI is used as system clock source */
        while (RCC_GetSysclkSrc() != RCC_CFG_SCLKSTS_HSI)
        {
        }
    }
    else
    {
        /* If HSI fails to start-up, the application will have wrong clock
           configuration. User can add here some code to deal with this error */

        /* Go to infinite loop */
        while (1)
        {
        }
    }
}

/**
 * @brief  Selects HSE as System clock source and configure HCLK, PCLK2
 *         and PCLK1 prescalers.
 */
void SetSysClockToHSE(void)
{
    /* SYSCLK, HCLK, PCLK2 and PCLK1 configuration
     * -----------------------------*/
    /* RCC system reset(for debug purpose) */
    RCC_DeInit();

    /* Enable HSE */
    RCC_ConfigHse(RCC_HSE_ENABLE);

    /* Wait till HSE is ready */
    HSEStartUpStatus = RCC_WaitHseStable();

    if (HSEStartUpStatus == SUCCESS)
    {
        /* Enable Prefetch Buffer */
        FLASH_PrefetchBufSet(FLASH_PrefetchBuf_EN);

        if (HSE_Value <= 18000000)
        {
            /* Flash 0 wait state */
            FLASH_SetLatency(FLASH_LATENCY_0);
        }
        else
        {
            /* Flash 1 wait state */
            FLASH_SetLatency(FLASH_LATENCY_1);
        }

        /* HCLK = SYSCLK */
        RCC_ConfigHclk(RCC_SYSCLK_DIV1);

        /* PCLK2 = HCLK */
        RCC_ConfigPclk2(RCC_HCLK_DIV1);

        /* PCLK1 = HCLK */
        RCC_ConfigPclk1(RCC_HCLK_DIV1);

        /* Select HSE as system clock source */
        RCC_ConfigSysclk(RCC_SYSCLK_SRC_HSE);
       
        /* Wait till HSE is used as system clock source */
        while (RCC_GetSysclkSrc() != RCC_CFG_SCLKSTS_HSE)
        {
        }
    }
    else
    {
        /* If HSE fails to start-up, the application will have wrong clock
           configuration. User can add here some code to deal with this error */

        /* Go to infinite loop */
        while (1)
        {
        }
    }
}

/**
 * @brief  Selects PLL clock as System clock source and configure HCLK, PCLK2
 *         and PCLK1 prescalers.
* @note FIN/N must be set in 4MHz to 20MHz.
 *       FIN/N*M must be set in 48MHz to 72MHz
 */
void SetSysClockToPLL(uint32_t freq, uint8_t src)
{
    uint32_t pllmul;
    uint32_t plldiv = RCC_PLLOUT_DIV_1;
    uint32_t latency;
    uint32_t pclk1div, pclk2div;

    if ((src == SYSCLK_USE_HSE)&&(HSE_VALUE != 8000000))
    {
        /* HSE_VALUE == 8000000 is needed in this project! */
        while (1);
    }

    /* SYSCLK, HCLK, PCLK2 and PCLK1 configuration
     * -----------------------------*/
    /* RCC system reset(for debug purpose) */
    RCC_DeInit();

    if (src == SYSCLK_USE_HSI) 
    {
        /* Enable HSI */
        RCC_ConfigHsi(RCC_HSI_ENABLE);

        /* Wait till HSI is ready */
        HSIStartUpStatus = RCC_WaitHsiStable();

        if (HSIStartUpStatus != SUCCESS)
        {
            /* If HSI fails to start-up, the application will have wrong clock
               configuration. User can add here some code to deal with this
               error */

            /* Go to infinite loop */
            while (1);
        }

    }
    else if (src == SYSCLK_USE_HSE) 
    {
        /* Enable HSE */
        RCC_ConfigHse(RCC_HSE_ENABLE);

        /* Wait till HSE is ready */
        HSEStartUpStatus = RCC_WaitHseStable();

        if (HSEStartUpStatus != SUCCESS)
        {
            /* If HSE fails to start-up, the application will have wrong clock
               configuration. User can add here some code to deal with this
               error */

            /* Go to infinite loop */
            while (1);
        }

    }

    switch (freq)
    {
        case 32000000:
            latency  = FLASH_LATENCY_1;
            pllmul = RCC_PLL_MUL_16;
            pclk1div = RCC_HCLK_DIV2;
            pclk2div = RCC_HCLK_DIV1;
            plldiv = RCC_PLLOUT_DIV_2;
            break;
        case 48000000:
            latency  = FLASH_LATENCY_2;
		    pllmul = RCC_PLL_MUL_12;
            pclk1div = RCC_HCLK_DIV2;
            pclk2div = RCC_HCLK_DIV1;
		    plldiv = RCC_PLLOUT_DIV_1;
            break;
        default:
            while (1);
    }

    FLASH_SetLatency(latency);

    /* HCLK = SYSCLK */
    RCC_ConfigHclk(RCC_SYSCLK_DIV1);

    /* PCLK2 = HCLK */
    RCC_ConfigPclk2(pclk2div);

    /* PCLK1 = HCLK */
    RCC_ConfigPclk1(pclk1div);
    if(src == SYSCLK_USE_HSE)
    {
        RCC_ConfigPll(RCC_PLL_SRC_HSE,pllmul, RCC_PLL_PRE_2, plldiv);
    }
    else
    {
        RCC_ConfigPll(RCC_PLL_SRC_HSI,pllmul, RCC_PLL_PRE_2, plldiv);
    }

    /* Enable PLL */
    RCC_EnablePll(ENABLE);

    /* Wait till PLL is ready */
   // while (RCC_GetFlagStatus(RCC_CTRL_FLAG_PLLRDF) == RESET);
     /* Wait till PLL is ready */
    while ((RCC->CTRL & RCC_CTRL_PLLRDF) == 0)
    {
    }
    /* Select PLL as system clock source */
    RCC_ConfigSysclk(RCC_SYSCLK_SRC_PLLCLK);

    /* Wait till PLL is used as system clock source */
    while (RCC_GetSysclkSrc() != RCC_CFG_SCLKSTS_PLL);
}
void SetSysClock_LSI(void)
{
    RCC_DeInit();
    RCC_EnableLsi(ENABLE);
    while(RCC_GetFlagStatus(RCC_LSCTRL_FLAG_LSIRD) == RESET)
    {
    }

//-----------------set systems clock-------------------//
    /* HCLK = SYSCLK */
    RCC_ConfigHclk(RCC_SYSCLK_DIV1);

    /* PCLK2 = HCLK */
    RCC_ConfigPclk2(RCC_HCLK_DIV1);

    /* PCLK1 = HCLK */
    RCC_ConfigPclk1(RCC_HCLK_DIV1);
//----------------------------------------------------------------------//
    FLASH_SetLatency(FLASH_LATENCY_0);
    RCC_ConfigSysclk(RCC_SYSCLK_SRC_LSI);
    while (RCC_GetSysclkSrc() != RCC_CFG_SCLKSTS_LSI)
    {

    }
}

void SetSysClock_LSE(void)
{
    RCC_DeInit();
    RCC_ConfigLse(RCC_LSE_ENABLE,0x01);
    while(RCC_GetFlagStatus(RCC_LSCTRL_FLAG_LSERD) == RESET)
    {
    }
//-----------------set systems clock-------------------//
    /* HCLK = SYSCLK */
    RCC_ConfigHclk(RCC_SYSCLK_DIV1);

    /* PCLK2 = HCLK */
    RCC_ConfigPclk2(RCC_HCLK_DIV1);

    /* PCLK1 = HCLK */
    RCC_ConfigPclk1(RCC_HCLK_DIV1);
//----------------------------------------------------------------------//
    FLASH_SetLatency(FLASH_LATENCY_0);
    RCC_ConfigSysclk(RCC_SYSCLK_SRC_LSE);
    while (RCC_GetSysclkSrc() != RCC_CFG_SCLKSTS_LSE)
    {

    }
}

void NVIC_Configuration(void)
{
    NVIC_InitType NVIC_InitStructure;

    /* Enable and configure RCC global IRQ channel */
    NVIC_InitStructure.NVIC_IRQChannel                   = RCC_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPriority           = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

//#ifdef USE_FULL_ASSERT

///**
// * @brief  Reports the name of the source file and the source line number
// *         where the assert_param error has occurred.
// * @param file pointer to the source file name
// * @param line assert_param error line source number
// */
//void assert_failed(const uint8_t* expr, const uint8_t* file, uint32_t line)
//{
//    /* User can add his own implementation to report the file name and line
//       number, ex: printf("Wrong parameters value: file %s on line %d\r\n",
//       file, line) */

//    /* Infinite loop */
//    while (1)
//    {
//    }
//}

//#endif

/**
 * @}
 */

/**
 * @}
 */
