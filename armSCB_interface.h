#ifndef armSCB_h
#define armSCB_h

#define EXCEPT_DIVBYZERO  0
#define EXCEPT_USGFAULT   1
#define EXCEPT_BUSFAULT   2
#define EXCEPT_MEMFAULT   3
#define EXCEPT_NMI        4
#define EXCEPT_PENDSV     5
#define EXCEPT_SYSTIC     6


#define GROUP_ZERO         0 
#define GROUP_ONE          1
#define GROUP_TWO          2
#defien GROUP_THREE        3


#define SUBGROUP_ZERO        0
#define SUBGROUP_ONE         1
#define SUBGROUP_TWO         2
#defien SUBGROUP_THREE       3

#define ENABLE_EXCEPT_DIVBYZERO   0x00000010
#define ENABLE_EXCEPT_USGFAULT    0x00040000
#define ENABLE_EXCEPT_BUSFAULT    0x00020000
#define ENABLE_EXCEPT_MEMFAULT    0x00010000


#define DISABLE_EXCEPT_DIVBYZERO  0xffffffef
#define DISABLE_EXCEPT_USGFAULT   0xfffbffff
#define DISABLE_EXCEPT_BUSFAULT   0xfffdffff
#define DISABLE_EXCEPT_MEMFAULT   0xfffeffff


#define ENABLE_PENDING_NMI        0x00000001
#define ENABLE_PENDING_PENDSV     0X00000008
#define DISABLE_PENDING_NMI       0xfffffffe
#define DISABLE_PENDING_PENDSV    0X08000000
#define DISABLE_PENDING_SYSTIK    0X02000000

u8 SCB_Enable_exception( u8 Copy_Exception);
u8 SCB_Disable_exception ( u8 Copy_Exception);

u8 SCB_Enable_Pending ( u8 Copy_Pending);
u8 SCB_Disable_Pending (u8 Copy_Pending);


u8 SCB_setPirority (u8 Copy_Exception ,u8 Copy_Group , u8 Copy_SubGroup);













#endif