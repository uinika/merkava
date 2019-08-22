#include "key.h"
#include "led.h"
#include "key_exti.h"

int main(void) {
  LED_Init();      // 初始化 LED
  Key_Init();      // 初始化 按键
  Key_EXTI_Init(); // 初始化 EXTI

  while (1) {
  }
}
