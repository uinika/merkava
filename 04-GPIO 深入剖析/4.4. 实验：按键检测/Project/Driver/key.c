#include "key.h"

void Key_GPIO_Init(void) {
  RCC_APB2PeriphClockCmd(KEY_S1_GPIO_CLK | KEY_S2_GPIO_CLK | KEY_S3_GPIO_CLK | KEY_S4_GPIO_CLK, ENABLE);

  GPIO_InitTypeDef GPIO_InitStructure;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;

  GPIO_InitStructure.GPIO_Pin = KEY_S1_GPIO_PIN;
  GPIO_Init(KEY_S1_GPIO_PORT, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = KEY_S2_GPIO_PIN;
  GPIO_Init(KEY_S2_GPIO_PORT, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = KEY_S3_GPIO_PIN;
  GPIO_Init(KEY_S3_GPIO_PORT, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = KEY_S4_GPIO_PIN;
  GPIO_Init(KEY_S4_GPIO_PORT, &GPIO_InitStructure);
}

/** 按键扫描函数 */

uint8_t Key_S1_Scan(void) {
  /* 读取GPIO状态，判断是否有按键按下 */
  if (GPIO_ReadInputDataBit(KEY_S1_GPIO_PORT, KEY_S1_GPIO_PIN) == 0) {
    return KEY_DOWN;
  } else {
    return KEY_UP;
  }
}

uint8_t Key_S2_Scan(void) {
  /* 读取GPIO状态，判断是否有按键按下 */
  if (GPIO_ReadInputDataBit(KEY_S2_GPIO_PORT, KEY_S2_GPIO_PIN) == 0) {
    return KEY_DOWN;
  } else {
    return KEY_UP;
  }
}

uint8_t Key_S3_Scan(void) {
  /* 读取GPIO状态，判断是否有按键按下 */
  if (GPIO_ReadInputDataBit(KEY_S3_GPIO_PORT, KEY_S3_GPIO_PIN) == 0) {
    return KEY_DOWN;
  } else {
    return KEY_UP;
  }
}

uint8_t Key_S4_Scan(void) {
  /* 读取GPIO状态，判断是否有按键按下 */
  if (GPIO_ReadInputDataBit(KEY_S4_GPIO_PORT, KEY_S4_GPIO_PIN) == 1) {
    return KEY_DOWN;
  } else {
    return KEY_UP;
  }
}
