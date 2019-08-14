#include "led.h"
#include "stm32f10x.h"

/* 简单延时函数 */
void Delay(volatile uint32_t count) {
  for (; count != 0; count--);
}

int main(void) {
  LED_GPIO_Config(); // 初始化 LED 相关的 GPIO

  while (1) {
    /* 点亮 LED2 和 LED3 以后延时 */
    LED2_GPIO_On();
    LED3_GPIO_On();
    Delay(0x0FFFFF);

    /* 熄灭 LED2 和 LED3 以后延时 */
    LED2_GPIO_Off();
    LED3_GPIO_Off();
    Delay(0x0FFFFF);
  }
}
