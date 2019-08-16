#ifndef __Common_Delay
#define __Common_Delay

#include "stm32f10x.h"

void Delay_Init(void); // 延时初始化

void Delay_us(__IO u32 us); // 延时微秒

void Delay_ms(us) Delay_us(1000 * x); // 延时毫秒

#endif /* Common_Delay */