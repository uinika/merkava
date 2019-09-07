#ifndef __UASRT
#define __UASRT

#include <stdio.h>
#include "stm32f10x.h"

void USART_Init(void);
void USART_Send_Byte();
void USART_Send_String();
void USART_SendHalfWord();

#endif /* __UASRT */
