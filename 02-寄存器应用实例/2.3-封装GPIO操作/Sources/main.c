/** ----- main.c ----- */
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"

int main(void) {
  RCC->APB2ENR |= ((1) << 3); // 使能 GPIOB 时钟

  /* 配置 PB0 为输出速度为 10MHz 的推挽输出模式 */
  GPIOB->CRL &= ~((0x0F) << (4 * 0));
  GPIOB->CRL |= ((1) << (4 * 0));

  GPIO_SetBits(GPIOB, GPIO_Pin_0);    // 设置为高电平
  GPIO_ResetBits(GPIOB, GPIO_Pin_0);  // 设置为低电平
}

/* 启动文件当中默认会调用该函数用于配置系统时钟，这里声明为空函数 */
void SystemInit(void) {
  // STM32F103ZET6 缺省将内部振荡器提供的 HSI = 8MHz 作为系统时钟
}
