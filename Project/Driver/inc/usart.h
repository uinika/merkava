#ifndef __UASRT
#define __UASRT

#include "stm32f10x.h"
#include <stdio.h>

void USART1_Init(void);
void USART_Send_Byte(USART_TypeDef *pUSARTx, uint8_t ch);
void USART_Send_String(USART_TypeDef *pUSARTx, char *str);
void USART_Send_HalfWord(USART_TypeDef *pUSARTx, uint16_t ch);

#endif /* __UASRT */
