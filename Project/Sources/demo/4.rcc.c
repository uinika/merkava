#include "clock.h"
#include "led.h"
#include "mco.h"
#include "stm32f10x.h"

/* 简单延时函数，采用 HSI 和 HSE 系统时钟所得到的延时效果不相同 */
void SimpleDelay(__IO uint32_t count) {
  for (; count != 0; count--)
    ;
}

/* 程序执行流程到达 main() 函数时，汇编启动文件 statup_stm32f10x_hd.s 已经调用 system_stm32f10x.c 文件中定义的 SystemInit() 函数，将系统时钟初始化为 72MHz */
int main(void) {
  LED_Init(); // 初始化 LED
  MCO_Init(); // 初始化 MCO

  // HSE_Clock_Init(RCC_PLLMul_9);  // 使用 HSE 作为系统时钟，SYSCLK = 8MHz * RCC_PLLMul_x，最高可达 128MHz
  HSI_Clock_Init(RCC_PLLMul_16); // 使用 HSI 作为系统时钟，SYSCLK = 8MHz/2 * RCC_PLLMul_x，最高只能达到 64MHz

  /* 配置 MCO 引脚的时钟源，可以将 PLLCLK/2 作为 MCO 引脚时钟，从而检测系统时钟是否配置正确 */
  RCC_MCOConfig(RCC_MCO_SYSCLK); // 可选择 RCC_MCO_SYSCLK、RCC_MCO_HSE、RCC_MCO_HSI、RCC_MCO_PLLCLK_Div2

  while (1) {
    /* LED2 和 LED3 交替闪烁*/
    LED2_ON;
    LED3_ON;
    SimpleDelay(0x0FFFFF);
    LED2_OFF;
    LED3_OFF;
    SimpleDelay(0x0FFFFF);
  }
}