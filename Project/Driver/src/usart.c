#include "stm32f10x.h"

/** 配置嵌套向量中断控制器 NVIC */
static void NVIC_Config(void) {
  NVIC_InitTypeDef NVIC_InitStructure;

  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);           // 配置 NVIC 为优先级分组 2
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;         // 配置 USART1 为中断源
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1; // 设置抢占式优先级
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;        // 设置子优先级
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;           // 使能中断通道

  NVIC_Init(&NVIC_InitStructure); // 初始化 NVIC 配置
}

/** 配置 USART 相关的 GPIO 引脚 */
void USART_Init(void) {
  GPIO_InitTypeDef GPIO_InitStructure;
  USART_InitTypeDef USART_InitStructure;

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);  // 打开串口GPIO的时钟
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE); // 打开串口外设的时钟

  /* 把 USART 的 Tx 引脚对应的 GPIO 配置为复用推挽输出模式 */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  /* 把 USART 的 Rx 引脚对应的 GPIO 配置为浮空输入模式 */
  GPIO_InitStructure.GPIO_Pin = DEBUG_USART_RX_GPIO_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  /* 配置 USART 工作参数 */
  USART_InitStructure.USART_BaudRate = 115200;                                    // 设置波特率为 115200
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;                     // 设置数据帧长度
  USART_InitStructure.USART_StopBits = USART_StopBits_1;                          // 设置停止位
  USART_InitStructure.USART_Parity = USART_Parity_No;                             // 设置为无奇偶校验
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // 失能硬件流控制模式
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;                 // 设置 USART 工作模式为可接可发
  USART_Init(DEBUG_USARTx, &USART_InitStructure);                                 // 初始化 USART 配置

  NVIC_Config();                                 // 调用嵌套向量中断控制器 NVIC 配置函数
  USART_ITConfig(USART1, USART_IT_RXNE, ENABLE); // 使能 USART 中断
  USART_Cmd(USART1, ENABLE);                     // 使能 USART 外设
}

/** 通过 USART 发送 1 个字节 */
void USART_Send_Byte(USART_TypeDef *pUSARTx, uint8_t ch) {
  USART_SendData(pUSARTx, ch); // 通过 USARTx 发送 1 字节数据
  while (USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET)
    ; // 检查 USART 标志位状态，判断发送是否完成
}

/** 通过 USART 发送 1 个字符串 */
void Usart_SendString(USART_TypeDef *pUSARTx, char *str) {
  unsigned int i = 0;
  do {
    Usart_SendByte(pUSARTx, *(str + i));
    i++;
  } while (*(str + i) != '\0');

  while (USART_GetFlagStatus(pUSARTx, USART_FLAG_TC) == RESET)
    ; // 检查 USART 标志位状态，判断发送是否完成
}

/** 通过 USART 发送 16 位的半字 */
void Usart_SendHalfWord(USART_TypeDef *pUSARTx, uint16_t ch) {
  uint8_t temp_h, temp_l;

  temp_h = (ch & 0XFF00) >> 8; // 获取高 8 位
  temp_l = ch & 0XFF;          // 获取低 8 位

  USART_SendData(pUSARTx, temp_h); // 发送高 8 位
  while (USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET)
    ;

  USART_SendData(pUSARTx, temp_l); // 发送低 8 位
  while (USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET)
    ;
}

/* ----- 下面代码用于重写 Keil MicroLIB ----- */

/** 重写 Keil MicroLIB 提供的 printf() 函数 */
int fputc(int ch, FILE *f) {
  /* 发送一个字节数据到串口 */
  USART_SendData(DEBUG_USARTx, (uint8_t)ch);

  while (USART_GetFlagStatus(DEBUG_USARTx, USART_FLAG_TXE) == RESET)
    ; // 检查 USART 标志位状态，判断发送是否已经完成

  return (ch);
}

/** 重写 Keil MicroLIB 提供的 scanf() 与 getchar() 函数 */
int fgetc(FILE *f) {
  while (USART_GetFlagStatus(DEBUG_USARTx, USART_FLAG_RXNE) == RESET)
    ; // 检查 USART 标志位状态，判断串口是否输入数据

  return (int)USART_ReceiveData(DEBUG_USARTx);
}