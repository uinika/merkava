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

/* GPIO 初始化函数，参数 GPIOx 为指向 GPIO 的地址指针，参数 GPIO_InitTypeDef 为指向初始化变量的结构体指针 */
void GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_InitStruct) {
  uint32_t currentmode = 0x00, currentpin = 0x00, pinpos = 0x00, pos = 0x00;
  uint32_t tmpreg = 0x00, pinmask = 0x00;

  /* GPIO 模式配置 */
  currentmode = ((uint32_t)GPIO_InitStruct->GPIO_Mode) & ((uint32_t)0x0F); // 将参数 GPIO_Mode 的低 4 位暂存至 currentmode

  /* 通过 bit4 是 1 还是 0 来判断当前为输入还是输出模式 */
  if ((((uint32_t)GPIO_InitStruct->GPIO_Mode) & ((uint32_t)0x10)) != 0x00) {
    currentmode |= (uint32_t)GPIO_InitStruct->GPIO_Speed;   // 如果是输出模式，那么需要设置输出速度
  }

  /* 配置 GPIO 的 CRL 寄存器，该寄存器用于控制低 8 位 GPIO */
  if (((uint32_t)GPIO_InitStruct->GPIO_Pin & ((uint32_t)0x00FF)) != 0x00) {
    tmpreg = GPIOx->CRL; // 备份 CRL 寄存器的状态

    /* 从第 0 引脚开始循环进行匹配 */
    for (pinpos = 0x00; pinpos < 0x08; pinpos++) {
      pos = ((uint32_t)0x01) << pinpos;
      currentpin = (GPIO_InitStruct->GPIO_Pin) & pos;  // 让 pos 与参数 GPIO_PIN 进行位与运算，为后续判断进行准备

      /* 如果 currentpin = pos 说明找到目标引脚 */
      if (currentpin == pos) {
        pos = pinpos << 2;                 // 由于 4 个位的寄存器配置 1 个引脚，所以 pinpos 左移 2 位，相当于乘以 4
        pinmask = ((uint32_t)0x0F) << pos; // 清零控制该引脚的 4 个寄存器位
        tmpreg &= ~pinmask;
        tmpreg |= (currentmode << pos);    // 向寄存器写入 GPIO 配置模式

        /* 判断下拉输入模式 */
        if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IPD) {
          GPIOx->BRR = (((uint32_t)0x01) << pinpos);  // 下拉输入模式，通过对寄存器 BRR 置 1，将 GPIO 引脚设置为 0
        }
        /* 判断上拉输入模式 */
        if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IPU) {
          GPIOx->BSRR = (((uint32_t)0x01) << pinpos); // 上拉输入模式，通过对寄存器 BSRR 置 1，将 GPIO 引脚设置为 1
        }
      }
    }

    GPIOx->CRL = tmpreg;  // 回写前面备份的 CRL 寄存器状态
  }

  /* 配置 GPIO 的 CRH 寄存器，该寄存器用于控制高 8 位 GPIO */
  if (GPIO_InitStruct->GPIO_Pin > 0x00FF) {
    tmpreg = GPIOx->CRH; // 备份 CRH 寄存器的状态

    /* 从第 0 引脚开始循环进行匹配 */
    for (pinpos = 0x00; pinpos < 0x08; pinpos++) {
      pos = (((uint32_t)0x01) << (pinpos + 0x08));
      currentpin = ((GPIO_InitStruct->GPIO_Pin) & pos);  // 让 pos 与参数 GPIO_PIN 进行位与运算，为后续判断进行准备

      /* 如果 currentpin = pos 说明找到目标引脚 */
      if (currentpin == pos) {
        pos = pinpos << 2;                 // 由于 4 个位的寄存器配置 1 个引脚，所以 pinpos 左移 2 位，相当于乘以 4
        pinmask = ((uint32_t)0x0F) << pos; // 清零控制该引脚的 4 个寄存器位
        tmpreg &= ~pinmask;
        tmpreg |= (currentmode << pos);    // 向寄存器写入 GPIO 配置模式

        /* 判断下拉输入模式 */
        if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IPD) {
          GPIOx->BRR = (((uint32_t)0x01) << (pinpos + 0x08));  // 下拉输入模式，通过对寄存器 BRR 置 1，将 GPIO 引脚设置为 0
        }
        /* 判断上拉输入模式 */
        if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IPU) {
          GPIOx->BSRR = (((uint32_t)0x01) << (pinpos + 0x08)); // 上拉输入模式，通过对寄存器 BSRR 置 1，将 GPIO 引脚设置为 1
        }
      }
    }

    GPIOx->CRH = tmpreg;  // 回写前面备份的 CRH 寄存器状态
  }
}
