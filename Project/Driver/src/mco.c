#include "mco.h"
#include "stm32f10x_rcc.h"

/**
 * @brief   初始化 MCO 引脚 PA8
 * @details STM32F1xx 系列只拥有 1 个 MCO 引脚，而STM32F4xx系列拥有 2 个 MCO 引脚
 */
void MCO_Init(void) {
  GPIO_InitTypeDef GPIO_InitStructure;

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); // 开启 GPIOA 时钟

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;         // 选择 GPIO 引脚
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;   // 配置为复用功能推挽输出模式
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // 设置 GPIO 输出速率为 50MHz

  GPIO_Init(GPIOA, &GPIO_InitStructure); // 初始化 GPIOA8
}
