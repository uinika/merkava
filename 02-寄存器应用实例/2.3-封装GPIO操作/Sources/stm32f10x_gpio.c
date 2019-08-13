/** ----- stm32f10x_gpio.c ----- */
#include "stm32f10x_gpio.h"

/* 设置指定引脚为高电平 1 */
void GPIO_SetBits(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin) {
  GPIOx->BSRR |= GPIO_Pin;
}

/* 设置指定引脚为低电平 0 */
void GPIO_ResetBits(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin) {
  GPIOx->BRR |= GPIO_Pin;
}
