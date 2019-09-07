#include "led.h"
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"

/** brief  初始化控制 LED 的 GPIO */
void Car_Init(void) {
  GPIO_InitTypeDef GPIO_InitStructure;                  // 定义 GPIO_InitTypeDef 类型结构体
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE); // 开启 LED 相关的 GPIO 外设时钟

  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // 设置引脚模式为 推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // 设置引脚速率为 50MHz
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;

  GPIO_Init(GPIOD, &GPIO_InitStructure);
}

void Forward(void) {
  /* 第 4 号车轮 */
  GPIO_SetBits(GPIOD, GPIO_Pin_1);
  GPIO_ResetBits(GPIOD, GPIO_Pin_0);
  /* 第 3 号车轮 */
  GPIO_SetBits(GPIOD, GPIO_Pin_3);
  GPIO_ResetBits(GPIOD, GPIO_Pin_2);
  /* 第 2 号车轮 */
  GPIO_SetBits(GPIOD, GPIO_Pin_4);
  GPIO_ResetBits(GPIOD, GPIO_Pin_5);
  /* 第 1 号车轮 */
  GPIO_SetBits(GPIOD, GPIO_Pin_6);
  GPIO_ResetBits(GPIOD, GPIO_Pin_7);
}

void Backward(void) {
  /* 第 4 号车轮 */
  GPIO_SetBits(GPIOD, GPIO_Pin_0);
  GPIO_ResetBits(GPIOD, GPIO_Pin_1);
  /* 第 3 号车轮 */
  GPIO_SetBits(GPIOD, GPIO_Pin_2);
  GPIO_ResetBits(GPIOD, GPIO_Pin_3);
  /* 第 2 号车轮 */
  GPIO_ResetBits(GPIOD, GPIO_Pin_4);
  GPIO_SetBits(GPIOD, GPIO_Pin_5);
  /* 第 1 号车轮 */
  GPIO_ResetBits(GPIOD, GPIO_Pin_6);
  GPIO_SetBits(GPIOD, GPIO_Pin_7);
}

void Left(void) {
  /* 第 4 号车轮 */
  GPIO_ResetBits(GPIOD, GPIO_Pin_0);
  GPIO_SetBits(GPIOD, GPIO_Pin_1);
  /* 第 3 号车轮 */
  GPIO_SetBits(GPIOD, GPIO_Pin_2);
  GPIO_ResetBits(GPIOD, GPIO_Pin_3);
  /* 第 2 号车轮 */
  GPIO_SetBits(GPIOD, GPIO_Pin_4);
  GPIO_ResetBits(GPIOD, GPIO_Pin_5);
  /* 第 1 号车轮 */
  GPIO_ResetBits(GPIOD, GPIO_Pin_6);
  GPIO_SetBits(GPIOD, GPIO_Pin_7);
}

void Right(void) {
  /* 第 4 号车轮 */
  GPIO_SetBits(GPIOD, GPIO_Pin_0);
  GPIO_ResetBits(GPIOD, GPIO_Pin_1);
  /* 第 3 号车轮 */
  GPIO_ResetBits(GPIOD, GPIO_Pin_2);
  GPIO_SetBits(GPIOD, GPIO_Pin_3);
  /* 第 2 号车轮 */
  GPIO_ResetBits(GPIOD, GPIO_Pin_4);
  GPIO_SetBits(GPIOD, GPIO_Pin_5);
  /* 第 1 号车轮 */
  GPIO_SetBits(GPIOD, GPIO_Pin_6);
  GPIO_ResetBits(GPIOD, GPIO_Pin_7);
}
