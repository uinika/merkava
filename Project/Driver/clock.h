#ifndef __CLOCK
#define __CLOCK

#include "stm32f10x.h"

void HSE_Clock_Init(uint32_t pllmul);
void HSI_Clock_Init(uint32_t pllmul);

#endif /* __CLOCK */
