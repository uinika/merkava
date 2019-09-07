#include "stm32f10x.h"
#include "usart.h"

int main(void) {
  USART1_Init();

  USART_Send_String(USART1, "Hello World!\n");
  printf("Hello Hank!\n");

  while (1) {
  }
}
