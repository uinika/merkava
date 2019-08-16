#include "led.h"

/** brief  初始化控制 LED 的 GPIO */
void LED_Init(void) {
  GPIO_InitTypeDef GPIO_InitStructure;                  // 定义 GPIO_InitTypeDef 类型结构体
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE); // 开启 LED 相关的 GPIO 外设时钟
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // 设置引脚模式为 推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // 设置引脚速率为 50MHz

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5; // 两个 LED 分别连接至 GPIOB 和 GPIOE 的 GPIO_Pin_5

  GPIO_Init(GPIOB, &GPIO_InitStructure); // 初始化 GPIOB
  GPIO_Init(GPIOE, &GPIO_InitStructure); // 初始化 GPIOE

  /* 用户 LED 默认处于关闭状态 */
  LED2_OFF;
  LED3_OFF;
}
