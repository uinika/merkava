#ifndef Driver_LED
#define Driver_LED

#include "stm32f10x.h"

/* LED 2 */
#define LED2_GPIO_PORT GPIOE               // GPIO 组
#define LED2_GPIO_CLK RCC_APB2Periph_GPIOE // GPIO 时钟
#define LED2_GPIO_PIN GPIO_Pin_5           // GPIO 引脚

/* LED 3 */
#define LED3_GPIO_PORT GPIOB               // GPIO 组
#define LED3_GPIO_CLK RCC_APB2Periph_GPIOB // GPIO 时钟
#define LED3_GPIO_PIN GPIO_Pin_5           // GPIO 引脚

void LED_GPIO_Config(void);

void LED2_GPIO_On(void);
void LED2_GPIO_Off(void);

void LED3_GPIO_On(void);
void LED3_GPIO_Off(void);
#endif /* Driver_LED */
