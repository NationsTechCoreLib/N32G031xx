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
 * @file n32g031x_it.c
 * @author Nations
 * @version v1.0.0
 *
 * @copyright Copyright (c) 2019, Nations Technologies Inc. All rights reserved.
 */
#include "n32g031_it.h"
#include "n32g031.h"
#include "main.h"
#include "log.h"
/** @addtogroup n32g031X_StdPeriph_Template
 * @{
 */

uint8_t Delay_100Ms_Cnt = 0;
extern volatile uint32_t RTC_Delay_Flag;

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

#ifdef RTC_DELAY_USE_TIM6
/**
 * @brief  This function handles TIM6 global interrupt request.
 */
void LPTIM_TIM6_IRQHandler(void)
{
    if (TIM_GetIntStatus(TIM6, TIM_INT_UPDATE) != RESET)
    {
		Delay_100Ms_Cnt++;

		if(Delay_100Ms_Cnt == 11)
		{
			RTC_Delay_Flag = 1;
			Delay_100Ms_Cnt = 0;
			/* Disable the TIM6 Counter */
			TIM6->CTRL1 &= (uint32_t)(~((uint32_t)TIM_CTRL1_CNTEN));
		}
        TIM_ClrIntPendingBit(TIM6, TIM_INT_UPDATE);
    }
}
#else
/**
 * @brief  This function handles SysTick Handler.
 */
void SysTick_Handler(void)
{	
	Delay_100Ms_Cnt++;
	if(Delay_100Ms_Cnt == 11)
	{
		RTC_Delay_Flag = 1;
		Delay_100Ms_Cnt = 0;
		/* Disable the SysTick Counter */
		SysTick->CTRL &= (~SysTick_CTRL_ENABLE_Msk);
	}
}
#endif

/**
 * @brief  This function handles RTC WakeUp interrupt request.
 */

void RTC_IRQHandler(void)
{
    EXTI_ClrITPendBit(EXTI_LINE20);
    printf("\r\n I am in rtc_wkup!!! \r\n");
    RTC_TimeShow();
    if (RTC_GetITStatus(RTC_INT_WUT) != RESET)
    {
        RTC_ClrIntPendingBit(RTC_INT_WUT);
    }
}
/******************************************************************************/
/*                 n32g031X Peripherals Interrupt Handlers                     */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_n32g031x.s).                                                 */
/******************************************************************************/

/**
 * @brief  This function handles PPP interrupt request.
 */
/*void PPP_IRQHandler(void)
{
}*/

/**
 * @}
 */
