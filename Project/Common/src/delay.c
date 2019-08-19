#include "delay.h"

static __IO u32 DelayTime;

/* 初始化延时函数 */
void Delay_Init(void) {
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


void DecreaseDelayTime(void) {
  if (DelayTime != 0x00) {
    DelayTime--;
  }
}
