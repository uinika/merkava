#include "led.h"

/**
  * @brief 初始化控制LED的IO
  */
void LED_GPIO_Config(void) {
  GPIO_InitTypeDef GPIO_InitStructure;                           // 定义一个GPIO_InitTypeDef类型的结构体
  RCC_APB2PeriphClockCmd(LED2_GPIO_CLK | LED3_GPIO_CLK, ENABLE); // 开启LED相关的GPIO外设时钟

  GPIO_InitStructure.GPIO_Pin = LED2_GPIO_PIN;      // 选择 GPIO 引脚
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // 设置引脚模式为 通用推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // 设置引脚速率为 50MHz
  GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStructure);   // 调用库函数初始化 GPIO

  GPIO_InitStructure.GPIO_Pin = LED3_GPIO_PIN;    // 选择 GPIO 引脚
  GPIO_Init(LED3_GPIO_PORT, &GPIO_InitStructure); // 调用库函数初始化 GPIO
	
	GPIO_SetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);
	GPIO_SetBits(LED3_GPIO_PORT, LED3_GPIO_PIN);
}

void LED2_GPIO_Off(void) {
  GPIO_SetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);
}

void LED2_GPIO_On(void) {
  GPIO_ResetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);
}

void LED3_GPIO_Off(void) {
  GPIO_SetBits(LED3_GPIO_PORT, LED3_GPIO_PIN);
}

void LED3_GPIO_On(void) {
  GPIO_ResetBits(LED3_GPIO_PORT, LED3_GPIO_PIN);
}
