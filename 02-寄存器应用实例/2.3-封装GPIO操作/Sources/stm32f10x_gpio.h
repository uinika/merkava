/** ----- stm32f10x_gpio.h ----- */
#ifndef __STM32F10X_GPIO_H
#define __STM32F10X_GPIO_H

#include "stm32f10x.h"

/* 将 GPIO 的 16 个引脚定义为宏 */
#define GPIO_Pin_0 ((uint16_t)0x0001)   // 选择 GPIO 第 0 引脚  00000000 00000001
#define GPIO_Pin_1 ((uint16_t)0x0002)   // 选择 GPIO 第 1 引脚  00000000 00000010
#define GPIO_Pin_2 ((uint16_t)0x0004)   // 选择 GPIO 第 2 引脚  00000000 00000100
#define GPIO_Pin_3 ((uint16_t)0x0008)   // 选择 GPIO 第 3 引脚  00000000 00001000
#define GPIO_Pin_4 ((uint16_t)0x0010)   // 选择 GPIO 第 4 引脚  00000000 00010000
#define GPIO_Pin_5 ((uint16_t)0x0020)   // 选择 GPIO 第 5 引脚  00000000 00100000
#define GPIO_Pin_6 ((uint16_t)0x0040)   // 选择 GPIO 第 6 引脚  00000000 01000000
#define GPIO_Pin_7 ((uint16_t)0x0080)   // 选择 GPIO 第 7 引脚  00000000 10000000
#define GPIO_Pin_8 ((uint16_t)0x0100)   // 选择 GPIO 第 8 引脚  00000001 00000000
#define GPIO_Pin_9 ((uint16_t)0x0200)   // 选择 GPIO 第 9 引脚  00000010 00000000
#define GPIO_Pin_10 ((uint16_t)0x0400)  // 选择 GPIO 第 10 引脚 00000100 00000000
#define GPIO_Pin_11 ((uint16_t)0x0800)  // 选择 GPIO 第 11 引脚 00001000 00000000
#define GPIO_Pin_12 ((uint16_t)0x1000)  // 选择 GPIO 第 12 引脚 00010000 00000000
#define GPIO_Pin_13 ((uint16_t)0x2000)  // 选择 GPIO 第 13 引脚 00100000 00000000
#define GPIO_Pin_14 ((uint16_t)0x4000)  // 选择 GPIO 第 14 引脚 01000000 00000000
#define GPIO_Pin_15 ((uint16_t)0x8000)  // 选择 GPIO 第 15 引脚 10000000 00000000
#define GPIO_Pin_All ((uint16_t)0xFFFF) // 选择 GPIO 所有引脚   11111111 11111111

/* 声明封装的 GPIO 操作函数 */
void GPIO_SetBits(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void GPIO_ResetBits(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

#endif
