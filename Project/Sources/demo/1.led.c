#include "delay.h"
#include "key.h"
#include "led.h"
#include "stm32f10x.h"

int main(void) {
  LED_Init();   // 初始化 LED
  Key_Init();   // 初始化 按键
  Delay_Init(); // 初始化 延时

  while (1) {
    LED2_ON;
    LED3_ON;
    Delay_ms(1000);
    LED2_OFF;
    LED3_OFF;
    Delay_ms(1000);
  }
}
