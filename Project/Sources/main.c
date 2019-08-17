#include "bit_band.h"
#include "car.h"
#include "delay.h"
#include "key.h"
#include "led.h"
#include "stm32f10x.h"

int main(void) {
  LED_Init();   // 初始化 LED
  Delay_Init(); // 初始化 延时

  while (1) {
    /* LED2 和 LED3 交替闪烁*/
    PBout(5) = 0;
    PEout(5) = 1;
    Delay_ms(1000);
    PBout(5) = 1;
    PEout(5) = 0;
    Delay_ms(1000);
  }
}
