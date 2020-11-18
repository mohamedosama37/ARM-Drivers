#ifndef Sys_private_h
#define Sys_private_h


typedef struct
{
	
	u32 STK_CTRL;
	u32 STK_LOAD;
	u32 STK_VAL;
	u32 STK_CALIB;	
	
	
}ARM_Systk;

#define systk ((ARM_Systk *) 0xE000E010)























#endif