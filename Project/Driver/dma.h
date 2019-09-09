#ifndef __DMA
#define __DMA
#include "stm32f10x.h"

#define BUFFER_SIZE 32 // 通过 DMA 传输的数据大小
extern const uint32_t Flash_Buffer[BUFFER_SIZE];
extern uint32_t SRAM_Buffer[BUFFER_SIZE];

void DMA_Config(void);
uint8_t Compare(const uint32_t *Flash_Buffer,
                uint32_t *SRAM_Buffer, uint16_t BufferLength);

#endif /* __DMA */
