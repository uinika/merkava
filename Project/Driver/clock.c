#include "clock.h"
#include "stm32f10x_rcc.h"

/**
 * @brief   将 HSE 作为时钟源，并经过 PLL 倍频后作为系统时钟
 * @details 系统时钟 SYSCLK, AHB 总线时钟 HCLK, APB2 总线时钟 PCLK2, APB1 总线时钟 PCLK1
 *          PCLK2 = HCLK = SYSCLK
 *          PCLK1 = HCLK/2，最高 36MHz
 * @param   pllmul -- PLL倍频因子
 *          HSE_Clock_Init(RCC_PLLMul_9);  设置系统时钟为 8MHz * 9 = 72MHz
 *          HSE_Clock_Init(RCC_PLLMul_16); 设置系统时钟为 8MHz * 16 = 128MHz
 */
void HSE_Clock_Init(uint32_t pllmul) {
  __IO uint32_t StartUpCounter = 0, HSEStartUpStatus = 0;

  RCC_DeInit();                               // 重置 RCC 时钟配置为默认状态
  RCC_HSEConfig(RCC_HSE_ON);                  // 使能 HSE 启用 8MHz 外部晶振
  HSEStartUpStatus = RCC_WaitForHSEStartUp(); // 获取 HSE 启动状态

  /* HSE 工作稳定之后开始进一步处理 */
  if (HSEStartUpStatus == SUCCESS) {
    FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable); // 使能 Flash 预存取缓冲区

    /*
     * 设置 SYSCLK 与 Flash 访问时间的比例，此处设置为 2，即使 SYSCLK 小于 48MHz 也可以工作，如果设置为 0 或 1，则如果 SYSCLK 配置超出范围，程序会发生错误
     * 0：0 < SYSCLK <= 24M
     * 1：24< SYSCLK <= 48M
     * 2：48< SYSCLK <= 72M
     */
    FLASH_SetLatency(FLASH_Latency_2);

    RCC_HCLKConfig(RCC_SYSCLK_Div1); // 设置 AHB 预分频因子为 1，即 HCLK = SYSCLK
    RCC_PCLK2Config(RCC_HCLK_Div1);  // 设置 APB2 预分频因子为 1，即 PCLK2 = HCLK
    RCC_PCLK1Config(RCC_HCLK_Div2);  // 设置 APB1 预分频因子为 1，即 PCLK1 = HCLK/2

    RCC_PLLConfig(RCC_PLLSource_HSE_Div1, pllmul); // 设置 PLL 时钟源和倍频因子
    RCC_PLLCmd(ENABLE);                            // 使能 PLL

    while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET) {
      // 等待 PLL 工作稳定
    };

    RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK); // PLL 工作稳定之后，将 PLL 时钟设置为系统时钟 SYSCLK

    while (RCC_GetSYSCLKSource() != 0x08) {
      // 根据时钟切换状态位，确保 PLLCLK 已经被正确的设置为系统时钟
    };

  } else {
    while (1) {
      // 如果 HSE 启动失败，可以在此处添加错误代码
    }
  }
}

/**
 * @brief   将 HSI 作为时钟源，并经过 PLL 倍频后作为系统时钟，HSI 作为 PLL 时钟源时，必须经过二分频 HSI/2 以后才可以使用，并且 PLL 倍频因子最大只能选择 16
 * @details 系统时钟 SYSCLK, AHB 总线时钟 HCLK, APB2 总线时钟 PCLK2, APB1 总线时钟 PCLK1
 *          PCLK2 = HCLK = SYSCLK
 *          PCLK1 = HCLK/2，最高 36MHz
 * @param   pllmul -- PLL倍频因子
 *          HSI_Clock_Init(RCC_PLLMul_9);  设置系统时钟为 8MHz/2 * 9 = 36MHz
 *          HSI_Clock_Init(RCC_PLLMul_16); 设置系统时钟为 8MHz/2 * 16 = 64MHz
 */
void HSI_Clock_Init(uint32_t pllmul) {
  __IO uint32_t HSIStartUpStatus = 0;

  RCC_DeInit();                               // 重置 RCC 时钟配置为默认状态
  RCC_HSICmd(ENABLE);                         // 使能 HSI
  HSIStartUpStatus = RCC->CR & RCC_CR_HSIRDY; // 获取 HSI 启动状态

  /* HSI 工作稳定之后开始进一步处理 */
  if (HSIStartUpStatus == RCC_CR_HSIRDY) {
    FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable); // 使能 Flash 预存取缓冲区

    /*
     * 设置 SYSCLK 与 Flash 访问时间的比例，此处设置为 2，即使 SYSCLK 小于 48MHz 也可以工作，如果设置为 0 或 1，则如果 SYSCLK 配置超出范围，程序会发生错误
     * 0：0 < SYSCLK <= 24M
     * 1：24< SYSCLK <= 48M
     * 2：48< SYSCLK <= 72M
     */
    FLASH_SetLatency(FLASH_Latency_2);

    RCC_HCLKConfig(RCC_SYSCLK_Div1); // 设置 AHB 预分频因子为 1，即 HCLK = SYSCLK
    RCC_PCLK2Config(RCC_HCLK_Div1);  // 设置 APB2 预分频因子为 1，即 PCLK2 = HCLK
    RCC_PCLK1Config(RCC_HCLK_Div2);  // 设置 APB1 预分频因子为 1，即 PCLK1 = HCLK/2

    RCC_PLLConfig(RCC_PLLSource_HSI_Div2, pllmul); // 设置 PLL 时钟源和倍频因子
    RCC_PLLCmd(ENABLE);                            // 使能 PLL

    while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET) {
      // 等待 PLL 工作稳定
    }

    RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK); // PLL 工作稳定之后，将 PLL 时钟设置为系统时钟 SYSCLK

    while (RCC_GetSYSCLKSource() != 0x08) {
      // 根据时钟切换状态位，确保 PLLCLK 已经被正确的设置为系统时钟
    }
  } else {
    while (1) {
      // 如果 HSI 启动失败，可以向此处添加错误代码
    }
  }
}
