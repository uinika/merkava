#include "delay.h"
#include "core_cm3.h"
#include "misc.h"

static __IO u32 DelayTime;

/* 初始化延时函数，启动系统节拍定时器 SysTick */
void Delay_Init(void) {
  /*
   * SystemFrequency / 1000 1ms 中断一次
   * SystemFrequency / 100000 10us 中断一次
   * SystemFrequency / 1000000 1us 中断一次
   */
  if (SysTick_Config(SystemCoreClock / 1000000)) {
    while (1)
      ;
  }
};

/* 初始化微秒数 */
void Delay_us(__IO u32 us) {
  DelayTime = us;
  while (DelayTime != 0)
    ;
};

void DelayDecrease(void) {
  if (DelayTime != 0x00) {
    DelayTime--;
  }
}

/*----- 更为简洁的延时函数实现 -----*/

/* 延时参数指定的微秒数 */
void Delay_Elegant_us(__IO uint32_t us) {
  uint32_t i;
  SysTick_Config(SystemCoreClock / 1000000);

  for (i = 0; i < us; i++) {
    /* 当 Systick 的计数值减小至 0 时，CRTL 寄存器的第 16 位置 1，并在读取后自动清 0 */
    while (!((SysTick->CTRL) & (1 << 16)))
      ;
  }

  SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk; // 关闭 SysTick 定时器
}

/* 延时参数指定的毫秒数 */
void Delay_Elegant_ms(__IO uint32_t ms) {
  uint32_t i;
  SysTick_Config(SystemCoreClock / 1000);

  for (i = 0; i < ms; i++) {
    /* 当 Systick 的计数值减小至 0 时，CRTL 寄存器的第 16 位置 1，并在读取后自动清 0 */
    while (!((SysTick->CTRL) & (1 << 16)))
      ;
  }

  SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk; // 关闭SysTick定时器
}
