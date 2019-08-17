#ifndef Common_Bit_Band
#define Common_Bit_Band

/* 将位带区地址和位序号转换为别名区地址 */
#define BITBAND(addr, bitnum) ((addr & 0xF0000000) + 0x02000000 + ((addr & 0x00FFFFFF) << 5) + (bitnum << 2))
#define MEM_ADDR(addr) *((volatile unsigned long *)(addr))     // 将一个地址转换为指针
#define BIT_ADDR(addr, bitnum) MEM_ADDR(BITBAND(addr, bitnum)) // 将位带别名区地址转换成指针

/* GPIO 的 ODR 寄存器地址映射 */
#define GPIOA_ODR_Addr (GPIOA_BASE + 12) // 0x4001080C
#define GPIOB_ODR_Addr (GPIOB_BASE + 12) // 0x40010C0C
#define GPIOC_ODR_Addr (GPIOC_BASE + 12) // 0x4001100C
#define GPIOD_ODR_Addr (GPIOD_BASE + 12) // 0x4001140C
#define GPIOE_ODR_Addr (GPIOE_BASE + 12) // 0x4001180C
#define GPIOF_ODR_Addr (GPIOF_BASE + 12) // 0x40011A0C
#define GPIOG_ODR_Addr (GPIOG_BASE + 12) // 0x40011E0C
/* GPIO 的 IDR 寄存器地址映射 */
#define GPIOA_IDR_Addr (GPIOA_BASE + 8) // 0x40010808
#define GPIOB_IDR_Addr (GPIOB_BASE + 8) // 0x40010C08
#define GPIOC_IDR_Addr (GPIOC_BASE + 8) // 0x40011008
#define GPIOD_IDR_Addr (GPIOD_BASE + 8) // 0x40011408
#define GPIOE_IDR_Addr (GPIOE_BASE + 8) // 0x40011808
#define GPIOF_IDR_Addr (GPIOF_BASE + 8) // 0x40011A08
#define GPIOG_IDR_Addr (GPIOG_BASE + 8) // 0x40011E08

/* 通过位段区操作 GPIO 的指定 pin 引脚，参数 pin 表示引脚编号，取值范围 0 ~ 16 */
#define PAout(pin) BIT_ADDR(GPIOA_ODR_Addr, pin) // GPIOA 的 pin 引脚输出
#define PAin(pin) BIT_ADDR(GPIOA_IDR_Addr, pin)  // GPIOA 的 pin 引脚输入
#define PBout(pin) BIT_ADDR(GPIOB_ODR_Addr, pin) // GPIOB 的 pin 引脚输出
#define PBin(pin) BIT_ADDR(GPIOB_IDR_Addr, pin)  // GPIOB 的 pin 引脚输入
#define PCout(pin) BIT_ADDR(GPIOC_ODR_Addr, pin) // GPIOC 的 pin 引脚输出
#define PCin(pin) BIT_ADDR(GPIOC_IDR_Addr, pin)  // GPIOC 的 pin 引脚输入
#define PDout(pin) BIT_ADDR(GPIOD_ODR_Addr, pin) // GPIOD 的 pin 引脚输出
#define PDin(pin) BIT_ADDR(GPIOD_IDR_Addr, pin)  // GPIOD 的 pin 引脚输入
#define PEout(pin) BIT_ADDR(GPIOE_ODR_Addr, pin) // GPIOE 的 pin 引脚输出
#define PEin(pin) BIT_ADDR(GPIOE_IDR_Addr, pin)  // GPIOE 的 pin 引脚输入
#define PFout(pin) BIT_ADDR(GPIOF_ODR_Addr, pin) // GPIOF 的 pin 引脚输出
#define PFin(pin) BIT_ADDR(GPIOF_IDR_Addr, pin)  // GPIOF 的 pin 引脚输入
#define PGout(pin) BIT_ADDR(GPIOG_ODR_Addr, pin) // GPIOG 的 pin 引脚输出
#define PGin(pin) BIT_ADDR(GPIOG_IDR_Addr, pin)  // GPIOG 的 pin 引脚输入

#endif /* Common_Bit_Band */
