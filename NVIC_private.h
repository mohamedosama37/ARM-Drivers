#ifndef NVIC_private_h
#define NVIC_private_h


#define ISER  ((u32*)0xE000E100)
#define ICER  ((u32*)0xE000E180)
#define ISPR  ((u32*)0xE000E200)
#define ICPR  ((u32*)0xE000E280)
#define IPR   ((u8*) 0xE000E400)
#define AIRCR ((u32*)0xE000ED0C)

#define  INT0    6
#define  TIM1    27
#define  TIM2    28
#define  TIM3    29
#define  TIM4    30
#endif