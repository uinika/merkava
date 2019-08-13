/** ----- stm32f10x.h ----- */
#ifndef __STM32F10X_H
#define __STM32F10X_H

/* 片上外设基地址 */
#define PERIPH_BASE ((unsigned int)0x40000000)
/* APB1 总线基地址 */
#define APB1PERIPH_BASE PERIPH_BASE
/* APB2 总线基地址 */
#define APB2PERIPH_BASE (PERIPH_BASE + 0x10000)
/* AHB 总线基地址 */
#define AHBPERIPH_BASE (PERIPH_BASE + 0x20000)

/* RCC 外设基地址 */
#define RCC_BASE (AHBPERIPH_BASE + 0x1000)
/* RCC 上的 AHB1 时钟使能寄存器地址 */
#define RCC_APB2ENR *(unsigned int *)(RCC_BASE + 0x18)

/* GPIO 外设基地址 */
#define GPIOB_BASE (APB2PERIPH_BASE + 0x0C00)

typedef unsigned int uint32_t;
typedef unsigned short uint16_t;

/* 定义 GPIO 寄存器结构体 */
typedef struct {
  uint32_t CRL;
  uint32_t CRH;
  uint32_t IDR;
  uint32_t ODR;
  uint32_t BSRR;
  uint32_t BRR;
  uint32_t LCKR;
} GPIO_TypeDef;

/* 定义 RCC 寄存器结构体 */
typedef struct {
  uint32_t CR;
  uint32_t CFGR;
  uint32_t CIR;
  uint32_t APB2RSTR;
  uint32_t APB1RSTR;
  uint32_t AHBENR;
  uint32_t APB2ENR;
  uint32_t APB1ENR;
  uint32_t BDCR;
  uint32_t CSR;
} RCC_TypeDef;

/* 强制将 GPIOB 和 RCC 的外设基地址转换为 GPIO_TypeDef、RCC_TypeDef 结构体类型指针 */
#define RCC ((RCC_TypeDef *)RCC_BASE)
#define GPIOB ((GPIO_TypeDef *)GPIOB_BASE)

#endif
