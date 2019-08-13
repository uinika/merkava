/** ----- stm32f10x_gpio.h----- */
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

/*  GPIO 输出速率枚举类型 */
typedef enum {
  GPIO_Speed_2MHz,      // 2  MHz  10
  GPIO_Speed_10MHz = 1, // 10 MHz  01
  GPIO_Speed_50MHz      // 50 MHz  11
} GPIOSpeed_TypeDef;

/* GPIO 工作模式枚举类型 */
typedef enum {
  GPIO_Mode_AIN = 0x0,          // 模拟输入    0000 0000
  GPIO_Mode_IN_FLOATING = 0x04, // 浮空输入    0000 0100
  GPIO_Mode_IPD = 0x28,         // 下拉输入    0010 1000
  GPIO_Mode_IPU = 0x48,         // 上拉输入    0100 1000
  GPIO_Mode_Out_OD = 0x14,      // 开漏输出    0001 0100
  GPIO_Mode_Out_PP = 0x10,      // 推挽输出    0001 0000
  GPIO_Mode_AF_OD = 0x1C,       // 复用开漏输出 0001 1100
  GPIO_Mode_AF_PP = 0x18        // 复用推挽输出 0001 1000
} GPIOMode_TypeDef;

/* GPIO 初始化参数结构体 */
typedef struct {
  uint16_t GPIO_Pin;            // 需要配置的 GPIO 引脚
  GPIOMode_TypeDef GPIO_Mode;   // 该 GPIO 引脚的工作模式，为 GPIO 工作模式枚举类型
  GPIOSpeed_TypeDef GPIO_Speed; // 该 GPIO 引脚的工作速率，为 GPIO 输出速率枚举类型
} GPIO_InitTypeDef;

/* 声明封装后的 GPIO 操作与初始化函数 */
void GPIO_SetBits(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void GPIO_ResetBits(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_InitStruct);

#endif
