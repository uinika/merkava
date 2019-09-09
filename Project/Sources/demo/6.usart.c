#include "stm32f10x.h"
#include "usart.h"

int main(void) {
  USART1_Init();
  USART2_Init();

  USART_Send_String(USART1, "Hello USART 1 !\n");
  USART_Send_String(USART2, "Hello USART 2 !\n");

  printf("Hello Hank!\n");

  while (1) {
  }
}
