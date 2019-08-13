/** ----- main.c ----- */
#include "stm32f10x.h"

int main(void) {
  RCC_APB2ENR |= (1 << 3);         // 使能 GPIOB 时钟

  /* 配置 PB0 为输出速度为 10MHz 的推挽输出模式 */
  GPIOB_CRL &= ~(0x0F << (4 * 0));
  GPIOB_CRL |= (1 << 4 * 0);

  GPIOB_ODR |= (0 << 0);           // PB0 输出 低电平
  while (1);
}

/* 启动文件当中默认会调用该函数用于配置系统时钟，这里声明为空函数 */
void SystemInit(void) {
  // STM32F103ZET6 缺省将内部振荡器提供的 HSI = 8MHz 作为系统时钟
}
