#ifndef Driver_KEY
#define Driver_KEY

#include "stm32f10x.h"

#define KEY_S1 GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4)
#define KEY_S2 GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_3)
#define KEY_S3 GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_2)
#define KEY_S4 GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)

void Key_Init(void);

#endif /* Driver_KEY */
