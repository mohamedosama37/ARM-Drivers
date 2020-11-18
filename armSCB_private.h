#ifndef armSCB_private_h
#define armSCB_private_h



typedef struct 
{

   u32 SCB_CPUID ;
   u32 SCB_ICSR  ;
   u32 SCB_VTOR  ;
   u32 SCB_AIRCR ;
   u32 SCB_SCR   ;
   u32 SCB_CCR   ;
   u32 SCB_SHPR1 ;
   u32 SCB_SHPR2 ;
   u32 SCB_SHPR3 ;
   u32 SCB_SHCRS ;
   u32 SCB_CFSR  ;
   u32 SCB_HFSR  ;
   u32 SCB_MMAR  ;
   u32 SCB_BFAR  ;   
	
}ARM_SCB;

#define ADD_SCB   ((ARM_SCB *)  0xE000ED00)
ARM_SCB * SCB  = ADD_SCB	 ;



#endif