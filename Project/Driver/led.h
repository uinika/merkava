#ifndef Driver_LED
#define Driver_LED

#include "stm32f10x.h"

/* LED 2 */
#define LED2_OFF GPIO_SetBits(GPIOE, GPIO_Pin_5)
#define LED2_ON GPIO_ResetBits(GPIOE, GPIO_Pin_5)
#define LED2_TOGGLE GPIO_WriteBit(GPIOE, GPIO_Pin_5, (BitAction)(1 - (GPIO_ReadOutputDataBit(GPIOE, GPIO_Pin_5))))

/* LED 3 */
#define LED3_OFF GPIO_SetBits(GPIOB, GPIO_Pin_5)
#define LED3_ON GPIO_ResetBits(GPIOB, GPIO_Pin_5)
#define LED3_TOGGLE GPIO_WriteBit(GPIOB, GPIO_Pin_5, (BitAction)(1 - (GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_5))))

void LED_Init(void);

#endif /* Driver_LED */
