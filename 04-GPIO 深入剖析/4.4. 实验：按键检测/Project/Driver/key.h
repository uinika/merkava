#ifndef Driver_KEY
#define Driver_KEY

#include "stm32f10x.h"

/* KEY_S1 */
#define KEY_S1_GPIO_PORT GPIOE               // 选择 GPIO 分组
#define KEY_S1_GPIO_CLK RCC_APB2Periph_GPIOE // 选择 GPIO 时钟
#define KEY_S1_GPIO_PIN GPIO_Pin_4           // 选择 GPIO 引脚

/* KEY_S2 */
#define KEY_S2_GPIO_PORT GPIOE               // 选择 GPIO 分组
#define KEY_S2_GPIO_CLK RCC_APB2Periph_GPIOE // 选择 GPIO 时钟
#define KEY_S2_GPIO_PIN GPIO_Pin_3           // 选择 GPIO 引脚

/* KEY_S3 */
#define KEY_S3_GPIO_PORT GPIOE               // 选择 GPIO 分组
#define KEY_S3_GPIO_CLK RCC_APB2Periph_GPIOE // 选择 GPIO 时钟
#define KEY_S3_GPIO_PIN GPIO_Pin_2           // 选择 GPIO 引脚

/* KEY_S4 */
#define KEY_S4_GPIO_PORT GPIOA               // 选择 GPIO 分组
#define KEY_S4_GPIO_CLK RCC_APB2Periph_GPIOA // 选择 GPIO 时钟
#define KEY_S4_GPIO_PIN GPIO_Pin_0           // 选择 GPIO 引脚

#define KEY_UP 0
#define KEY_DOWN 1

void Key_GPIO_Init(void);
uint8_t Key_S1_Scan(void);
uint8_t Key_S2_Scan(void);
uint8_t Key_S3_Scan(void);
uint8_t Key_S4_Scan(void);
#endif /* Driver_KEY */
