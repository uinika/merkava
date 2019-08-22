#include "key_exti.h"

/* 嵌套向量中断控制器 NVIC 配置 */
static void Key_NVIC_Init(void) {
  NVIC_InitTypeDef NVIC_InitStructure;

  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);           // 配置 NVIC 为优先级分组 1
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1; // 设置抢占优先级为 1
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;        // 设置子优先级为 1
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;           // 使能中断通道通道

  /* 设置按键 S1 的中断请求通道为 EXTI4_IRQn 并且初始化 */
  NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;
  NVIC_Init(&NVIC_InitStructure);
  /* 设置按键 S2 的中断请求通道为 EXTI3_IRQn 并且初始化*/
  NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;
  NVIC_Init(&NVIC_InitStructure);
  /* 设置按键 S3 的中断请求通道为 EXTI2_IRQn 并且初始化*/
  NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;
  NVIC_Init(&NVIC_InitStructure);
  /* 设置按键 S4 的中断请求通道为 EXTI0_IRQn 并且初始化*/
  NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
  NVIC_Init(&NVIC_InitStructure);
}

/** 配置 GPIO 为 EXTI 中断事件输入线，并且设置优先级 */
void Key_EXTI_Init(void) {
  EXTI_InitTypeDef EXTI_InitStructure;

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE); // 开启按键相关的 GPIO 外设时钟
  Key_NVIC_Init();                                     // 调用上面定义的 NVIC 配置函数

  /* 配置按键 S1 对应的中断/事件线 EXTI_Line4 */
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource4); // 选择 GPIO 分组上的哪只引脚作为 EXTI 信号源
  EXTI_InitStructure.EXTI_Line = EXTI_Line4;                  // 选择 EXTI 中断/事件线为 EXTI_Line4
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;         // 配置 EXTI 为中断生成模式
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;     // 设置 EXTI 的触发事件为下降沿触发
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;                   // 使能 EXTI 中断/事件线
  EXTI_Init(&EXTI_InitStructure);
  /* 配置按键 S2 对应的中断/事件线 EXTI_Line3 */
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource3); // 选择 GPIO 分组上的哪只引脚作为 EXTI 信号源
  EXTI_InitStructure.EXTI_Line = EXTI_Line3;                  // 选择 EXTI 中断/事件线为 EXTI_Line3
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;         // 配置 EXTI 为中断生成模式
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;     // 设置 EXTI 的触发事件为下降沿触发
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;                   // 使能 EXTI 中断/事件线
  EXTI_Init(&EXTI_InitStructure);
  /* 配置按键 S3 对应的中断/事件线 EXTI_Line2 */
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource2); // 选择 GPIO 分组上的哪只引脚作为 EXTI 信号源
  EXTI_InitStructure.EXTI_Line = EXTI_Line2;                  // 选择 EXTI 中断/事件线为 EXTI_Line2
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;         // 配置 EXTI 为中断生成模式
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;     // 设置 EXTI 的触发事件为下降沿触发
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;                   // 使能 EXTI 中断/事件线
  EXTI_Init(&EXTI_InitStructure);
  /* 配置按键 S4 对应的中断/事件线 EXTI_Line0 */
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0); // 选择 GPIO 分组上的哪只引脚作为 EXTI 信号源
  EXTI_InitStructure.EXTI_Line = EXTI_Line0;                  // 选择 EXTI 中断/事件线为 EXTI_Line10
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;         // 配置 EXTI 为中断生成模式
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;      // 设置 EXTI 的触发事件为上升沿触发
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;                   // 使能 EXTI 中断/事件线
  EXTI_Init(&EXTI_InitStructure);
}
