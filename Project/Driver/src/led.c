#include "led.h"

/** brief  初始化控制 LED 的 GPIO */
void LED_GPIO_Init(void) {
  GPIO_InitTypeDef GPIO_InitStructure;                           // 定义 GPIO_InitTypeDef 类型结构体
  RCC_APB2PeriphClockCmd(LED2_GPIO_CLK | LED3_GPIO_CLK, ENABLE); // 开启 LED 相关的 GPIO 外设时钟

  GPIO_InitStructure.GPIO_Pin = LED2_GPIO_PIN;      // 选择 GPIO 引脚
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // 设置引脚模式为 推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // 设置引脚速率为 50MHz
  GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStructure);   // 调用库函数初始化 GPIO

  GPIO_InitStructure.GPIO_Pin = LED3_GPIO_PIN;    // 选择 GPIO 引脚
  GPIO_Init(LED3_GPIO_PORT, &GPIO_InitStructure); // 调用库函数初始化 GPIO

  /* GPIO 默认输出高电平，将 LED 初始为熄灭状态 */
  GPIO_SetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);
  GPIO_SetBits(LED3_GPIO_PORT, LED3_GPIO_PIN);
}

/* 点亮 LED2 */
void LED2_GPIO_On(void) {
  GPIO_ResetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);
}

/* 熄灭 LED2 */
void LED2_GPIO_Off(void) {
  GPIO_SetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);
}

/* 点亮 LED3 */
void LED3_GPIO_Off(void) {
  GPIO_SetBits(LED3_GPIO_PORT, LED3_GPIO_PIN);
}

/* 熄灭 LED3 */
void LED3_GPIO_On(void) {
  GPIO_ResetBits(LED3_GPIO_PORT, LED3_GPIO_PIN);
}
