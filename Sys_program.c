#include "STD_TYPES.h"
#include "Sys_interface.h"
#define  NULL 0
static void (*ptr1)(void)=NULL;



void Sys_initailze (void)
{
	
   systk ->STK_CTRL |=ENABLE_SYSTK;
   systk -> STK_CTRL|=ENABLE_INTERRUPT;  
   systk -> STK_CTRL|=ENABLE_PRESCAL ;  
	
		
}


void Sys_writeLoad( u32 Copy_Load)
{
	
	systk ->STK_LOAD = Copy_Load;
		
}

void Sys_writeValue (u32 Copy_Value)
{
	systk ->STK_VAL =Copy_Value;
	
}

void SetCallBackFn (void (*Copy_pvidCallBack)(void))
{
	
	
	ptr1= Copy_pvidCallBack;
	
	
	
	
}


void SysTick_Handler(void)
{
	ptr1();
	
}