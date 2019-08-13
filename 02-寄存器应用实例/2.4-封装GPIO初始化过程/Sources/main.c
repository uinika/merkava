/** ----- main.c ----- */
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"

/* 延时函数 */
void Delay(uint32_t count) {
  for (; count != 0; count--);
}

int main(void) {
  GPIO_InitTypeDef GPIO_InitStructure; // 定义 GPIO_InitTypeDef 类型的结构体

  RCC->APB2ENR |= ((1) << 3); // 开启 GPIO 时钟

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;         // 选择要控制的 GPIO
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // 设置为通用推挽输出模式
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // 设置速度为 50 MHz
  GPIO_Init(GPIOB, &GPIO_InitStructure);            // 初始化 GPIO

  while (1) {
    GPIO_SetBits(GPIOB, GPIO_Pin_0);   // GPIO 输出低电平 0 点亮 LED
    Delay(0xFFFFF);                     // 调用延时函数
    GPIO_ResetBits(GPIOB, GPIO_Pin_0); // GPIO 输出高电平 1 熄灭 LED
    Delay(0xFFFFF);                     // 调用延时函数
  }
}

/* 启动文件当中默认会调用该函数用于配置系统时钟，这里声明为空函数 */
void SystemInit(void) {
  // STM32F103ZET6 缺省将内部振荡器提供的 HSI = 8MHz 作为系统时钟
}
