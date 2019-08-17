#include "car.h"
#include "delay.h"
#include "key.h"
#include "led.h"
#include "stm32f10x.h"

int main(void) {
  LED_Init();   // 初始化 LED
  Key_Init();   // 初始化 按键
  Delay_Init(); // 初始化 延时
  Car_Init();

  while (1) {

    /* 控制按键 S1 */
    if (!KEY_S1) {
      Delay_ms(10);
      if (!KEY_S1) {
        while (!KEY_S1)
          ; // 等待按键弹起
        Forward();
      }
    }

    /* 控制按键 S2 */
    if (!KEY_S2) {
      Delay_ms(10);
      if (!KEY_S2) {
        while (!KEY_S2)
          ; // 等待按键弹起
        Backward();
      }
    }

    /* 控制按键 S1 */
    if (!KEY_S3) {
      Delay_ms(10);
      if (!KEY_S3) {
        while (!KEY_S3)
          ; // 等待按键弹起
        Left();
      }
    }

    /* 控制按键 S4，按下时 LED 闪烁，放开后 LED 熄灭，注意判断条件与按键 S123 相反*/
    if (KEY_S4) {
      Delay_ms(10);
      if (KEY_S4) {
        while (KEY_S4)
          ; // 等待按键弹起
        Right();
      }
    }
  }
}
