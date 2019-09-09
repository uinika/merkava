#include "delay.h"
#include "dma.h"
#include "led.h"
#include "stm32f10x.h"

int main(void) {
  /* 定义存放比较结果变量 */
  uint8_t TransferStatus;

  LED_Init();     // 初始化 LED
  Delay_Init();   // 初始化 延时
  Delay_ms(10000); // 延时 1 秒
  DMA_Config();   // 初始化 DMA

  /* 等待DMA传输完成 */
  while (DMA_GetFlagStatus(DMA1_FLAG_TC6) == RESET) {
  }

  /* 比较源数据与传输后数据 */
  TransferStatus = Compare(Flash_Buffer, SRAM_Buffer, BUFFER_SIZE);

  /* 判断 DMA 传输结果，并通过 LED 的亮灭来指示状态 */
  if (TransferStatus == 0) {
    LED2_ON; // 当 Flash 和 SRAM 中的数据相等时，点亮 LED2
  } else {
    /* 源数据与传输后数据相等时RGB彩色灯显示蓝色 */
    LED3_ON; // 当 Flash 和 SRAM 中的数据相等时，点亮 LED3
  }

  while (1) {
  }
}
