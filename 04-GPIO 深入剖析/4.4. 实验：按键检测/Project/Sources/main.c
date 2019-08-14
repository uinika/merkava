#include "key.h"
#include "led.h"
#include "stm32f10x.h"

int main(void) {
  LED_GPIO_Config(); // 初始化 LED
  Key_GPIO_Init();   // 初始化 按键

  while (1) {

    if (Key_S1_Scan() == KEY_DOWN) {
      LED2_GPIO_On();
    }

    if (Key_S2_Scan() == KEY_DOWN) {
      LED2_GPIO_Off();
    }

    if (Key_S3_Scan() == KEY_DOWN) {
      LED3_GPIO_On();
    }

    if (Key_S4_Scan() == KEY_DOWN) {
      LED3_GPIO_Off();
    }

    /* 点亮 LED2 和 LED3 以后延时 */
    // LED2_GPIO_On();
    // LED3_GPIO_On();
    // Delay(0x0FFFFF);

    /* 熄灭 LED2 和 LED3 以后延时 */
    // LED2_GPIO_Off();
    // LED3_GPIO_Off();
    // Delay(0x0FFFFF);
  }
}
