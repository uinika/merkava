#include "dma.h"
#include "stm32f10x.h"

uint32_t SRAM_Buffer[BUFFER_SIZE]; // 定义DMA传输目标存储器存储在内部的 SRAM 当中

/** DMA 传输的数据源，使用 const 关键字将其保存至 Flash */
const uint32_t Flash_Buffer[BUFFER_SIZE] = {
    0x01020304, 0x05060708, 0x090A0B0C, 0x0D0E0F10,
    0x11121314, 0x15161718, 0x191A1B1C, 0x1D1E1F20,
    0x21222324, 0x25262728, 0x292A2B2C, 0x2D2E2F30,
    0x31323334, 0x35363738, 0x393A3B3C, 0x3D3E3F40,
    0x41424344, 0x45464748, 0x494A4B4C, 0x4D4E4F50,
    0x51525354, 0x55565758, 0x595A5B5C, 0x5D5E5F60,
    0x61626364, 0x65666768, 0x696A6B6C, 0x6D6E6F70,
    0x71727374, 0x75767778, 0x797A7B7C, 0x7D7E7F80};

/** DMA 初始化配置函数 */
void DMA_Config(void) {
  DMA_InitTypeDef DMA_InitStructure;

  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);                      // 开启 DMA 时钟
  DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)Flash_Buffer;      // 外设地址
  DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)SRAM_Buffer;           // 存储器地址
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;                      // DMA 传输方向
  DMA_InitStructure.DMA_BufferSize = BUFFER_SIZE;                         // DMA 缓冲区空间大小
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Enable;         // 外设地址增量模式
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;                 // 存储器地址增量模式
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Word; // 外设数据宽度
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Word;         // 存储器数据宽度
  DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;                           // DMA 模式选择
  DMA_InitStructure.DMA_Priority = DMA_Priority_High;                     // 设置 DMA 通道优先级为高
  DMA_InitStructure.DMA_M2M = DMA_M2M_Enable;                             // 使能 DMA 存储器到存储器传输
  DMA_Init(DMA1_Channel6, &DMA_InitStructure);                            // 初始化 DMA 通道
  DMA_ClearFlag(DMA1_FLAG_TC6);                                           // 清除 DMA 数据传输完成标志位
  DMA_Cmd(DMA1_Channel6, ENABLE);                                         // 使能 DMA 通道
}

/** 判断指定长度的两个数据源是否相等，完全相等返回 1，否则返回 0 */
uint8_t Compare(const uint32_t *Flash_Buffer,
                uint32_t *SRAM_Buffer, uint16_t BufferLength) {
  /* 数据长度递减 */
  while (BufferLength--) {
    /* 如果对应的数据不相等 */
    if (*Flash_Buffer != *SRAM_Buffer) {
      return 0; // 返回 0
    }

    /* 两个数据源地址指针自增 1 */
    Flash_Buffer++;
    SRAM_Buffer++;
  }

  return 1; // 判断正确返回 1
}
