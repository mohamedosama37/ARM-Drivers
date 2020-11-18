#ifndef armRCC_private_h
#define armRCC_private_h





typedef struct
{
	
	u32 RCC_CR ;
	u32 RCC_CFGR;
	u32 RCC_CIR ;
	u32 RCC_APB2RSTR;
	u32 RCC_APB1RSTR;
    u32 RCC_AHBENR;
	u32 RCC_APB2ENR;
	u32 RCC_APB1ENR;
    u32 RCC_BDCR;
		
	
}ARM_RCC;


#define ADD_RCC   ((ARM_RCC *) 0x40021000)
ARM_RCC * RCC = ADD_RCC ;









#endif