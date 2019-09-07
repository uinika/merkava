/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"
#include "usart.h"
#include "delay.h"
#include "led.h"

extern void DecreaseDelayTime(void);

/** @brief  SysTick 中断服务函数 */
void SysTick_Handler(void) {
  DelayDecrease();
}

/** @brief  EXTI4 中断服务函数 */
void EXTI4_IRQHandler(void) {
  /* 确认 EXTI 已经产生了中断 */
  if (EXTI_GetITStatus(EXTI_Line4) != RESET) {
    LED2_ON;                            // 点亮 LED2
    EXTI_ClearITPendingBit(EXTI_Line4); // 清除中断标志位
  }
}

/** @brief  EXTI3 中断服务函数 */
void EXTI3_IRQHandler(void) {
  /* 确认 EXTI 已经产生了中断 */
  if (EXTI_GetITStatus(EXTI_Line3) != RESET) {
    LED2_OFF;                           // 关闭 LED2
    EXTI_ClearITPendingBit(EXTI_Line3); // 清除中断标志位
  }
}

/** @brief  EXTI2 中断服务函数 */
void EXTI2_IRQHandler(void) {
  /* 确认 EXTI 已经产生了中断 */
  if (EXTI_GetITStatus(EXTI_Line2) != RESET) {
    LED3_ON;                            // 点亮 LED3
    EXTI_ClearITPendingBit(EXTI_Line2); // 清除中断标志位
  }
}

/** @brief  EXTI0 中断服务函数 */
void EXTI0_IRQHandler(void) {
  /* 确认 EXTI 已经产生了中断 */
  if (EXTI_GetITStatus(EXTI_Line0) != RESET) {
    LED3_OFF;                           // 关闭 LED3
    EXTI_ClearITPendingBit(EXTI_Line0); // 清除中断标志位
  }
}

/** @brief  USART2 中断服务函数 */
void USART1_IRQHandler(void) {
  uint8_t data;
  if(USART_GetITStatus(USART1,USART_IT_RXNE) != RESET) {
    data = USART_ReceiveData(USART1);
    USART_SendData(USART1,data);
  }
}

/** @brief  USART2 中断服务函数 */
void USART2_IRQHandler(void) {
  uint8_t data;
  if(USART_GetITStatus(USART2,USART_IT_RXNE) != RESET) {
    data = USART_ReceiveData(USART2);
    USART_SendData(USART2,data);
  }
}

/** @addtogroup STM32F10x_StdPeriph_Template
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void) {
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void) {
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1) {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void) {
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1) {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void) {
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1) {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void) {
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1) {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void) {
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void) {
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void) {
}

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
