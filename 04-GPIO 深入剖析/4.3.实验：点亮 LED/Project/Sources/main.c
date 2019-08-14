#include "led.h"
#include "stm32f10x.h"

/* ����ʱ���� */
void Delay(volatile uint32_t count) {
  for (; count != 0; count--)
    ;
}

int main(void) {
  LED_GPIO_Config(); // �����Զ��� LED ��ʼ������

  while (1) {
    LED2_GPIO_On();
		LED3_GPIO_On();
    Delay(0x0FFFFF);
		
    LED2_GPIO_Off();
		LED3_GPIO_Off();
    Delay(0x0FFFFF);
  }
}
