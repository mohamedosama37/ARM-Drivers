#ifndef Sys_interface_h
#define Sys_interface_h



#define ENABLE_SYSTK          0x00000001
#define ENABLE_INTERRUPT      0x00000002
#define ENABLE_PRESCAL        0x00000004








void Sys_initailze (void);
void Sys_writeLoad( u32 Copy_Load);
void Sys_writeValue (u32 Copy_Value); 
void SetCallBackFn (void (*Copy_pvidCallBack)(void)) ;











#endif