#ifndef Common_Delay
#define Common_Delay

#include "stm32f10x.h"

void Delay_Init(void);
void DelayDecrease(void);
void Delay_us(__IO u32 nTime);

#define Delay_ms(us) Delay_us(1000 * us);

#endif /* Common_Delay */
