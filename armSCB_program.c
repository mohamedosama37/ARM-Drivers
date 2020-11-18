#include "STD_TYPES.h"
#include "SCB_private.h"
#include "SCB_interface.h"


u8 SCB_Enable_exception( u8 Copy_Exception)
{
	
	u8 LocalErrorState =0;
	
	switcn (Copy_Exception)
	{
		
		
     case DIVBYZERO       : SCB ->SCB_CCR    |= ENABLE_EXCEPT_DIVBYZERO; break;
	 case EXCEPT_USGFAULT : SCB -> SCB_SHCSR |= EXCEPT_USGFAULT;break;
	 case EXCEPT_BUSFAULT : SCB -> SCB_SHCSR |= EXCEPT_BUSFAULT;break;
     case EXCEPT_MEMFAULT :	SCB -> SCB_SHCSR |= EXCEPT_MEMFAULT; break;
		
	}
	
	return LocalErrorState;
	
}

u8 SCB_Disable_exception( u8 Copy_Exception)
{
	
	u8 LocalErrorState =0;
	
	switcn (Copy_Exception)
	{
		
		
     case DIVBYZERO       : SCB -> SCB_CCR   &= DISABLE_EXCEPT_DIVBYZERO ;break;
	 case EXCEPT_USGFAULT : SCB -> SCB_SHCSR &= DISABLE_EXCEPT_USGFAULT  ; break;
	 case EXCEPT_BUSFAULT : SCB -> SCB_SHCSR &= DISABLE_EXCEPT_BUSFAULT  ; break;
     case EXCEPT_MEMFAULT :	SCB -> SCB_SHCSR &= DISABLE_EXCEPT_MEMFAULT  ; break;
		
	}
	
	return LocalErrorState;
	
}



u8 SCB_Enable_Pending ( u8 Copy_Exception)
{
	
	u8 LocalErrorState =0;
	
		switcn (Copy_Exception)
	{
		
		
     case  EXCEPT_NMI    :    SCB -> SCB_ICSR |=ENABLE_PENDING_NMI ;   break;
	 case  EXCEPT_PENDSV :    SCB -> SCB_ICSR |=ENABLE_PENDING_PENDSV;  break;
	 case  EXCEPT_SYSTIK :    SCB -> SCB_ICSR |=ENABLE_PENDING_SYSTIK ; break;
	}
	
  return LocalErrorState;
}


u8 SCB_Disable_Pending ( u8 Copy_Exception)
{
	
	u8 LocalErrorState =0;
	
		switcn (Copy_Exception)
	{
		
	 case  EXCEPT_PENDSV :    SCB -> SCB_ICSR |=DISABLE_PENDING_PENDSV;  break;
	 case  EXCEPT_SYSTIK :    SCB -> SCB_ICSR |=DISABLE_PENDING_SYSTIK; break;
	}
	
  return LocalErrorState;
}



u8 SCB_setPirority (u8 Copy_Exception ,u8 Copy_Group , u8 Copy_SubGroup)
{
	
	
	
	SCB ->  SCB_AIRCR=  0xFA050005;
  	
	
	
	if ( Copy_Exception == EXCEPT_PENDSV)
	{
		
		if ( Copy_Group == GROUP_ZERO )
		{
			
			     swicth ( Copy_SubGroup)
		     	{
					case SUBGROUP_ZERO  : SCB -> SCB_SHPR3 |= 0x00000000;
					case SUBGROUP_ONE   : SCB -> SCB_SHPR3 |= 0x10000000; 
					case SUBGROUP_TWO   : SCB -> SCB_SHPR3 |= 0x20000000; 
					case SUBGROUP_THREE : SCB -> SCB_SHPR3 |= 0x30000000;
			
				}			
		}else if  ( Copy_Group == GROUP_ONE )
		{
			
			
			  swicth ( Copy_SubGroup)
		     	{
					case SUBGROUP_ZERO  : SCB -> SCB_SHPR3 |= 0x40000000;
					case SUBGROUP_ONE   : SCB -> SCB_SHPR3 |= 0x50000000; 
					case SUBGROUP_TWO   : SCB -> SCB_SHPR3 |= 0x60000000; 
					case SUBGROUP_THREE : SCB -> SCB_SHPR3 |= 0x70000000;
			
				}
			
			
		}else if  ( Copy_Group == GROUP_TWO)
		{
			
			
			  swicth ( Copy_SubGroup)
		     	{
					case SUBGROUP_ZERO  : SCB -> SCB_SHPR3 |= 0x80000000;
					case SUBGROUP_ONE   : SCB -> SCB_SHPR3 |= 0x90000000; 
					case SUBGROUP_TWO   : SCB -> SCB_SHPR3 |= 0xa0000000; 
					case SUBGROUP_THREE : SCB -> SCB_SHPR3 |= 0xb0000000;
			
				}
			
			
		}else
		       {
			
			
			   swicth ( Copy_SubGroup)
		     	{
					case SUBGROUP_ZERO  : SCB -> SCB_SHPR3 |= 0xc0000000;
					case SUBGROUP_ONE   : SCB -> SCB_SHPR3 |= 0xd0000000; 
					case SUBGROUP_TWO   : SCB -> SCB_SHPR3 |= 0xe0000000; 
					case SUBGROUP_THREE : SCB -> SCB_SHPR3 |= 0xf0000000;
			
				}
			
			
			
			
			
			
		       }
			  
			
		
		
		
		
		
		
	}else
	{
		
				if ( Copy_Group == GROUP_ZERO )
		{
			
			     swicth ( Copy_SubGroup)
		     	{
					case SUBGROUP_ZERO  : SCB -> SCB_SHPR3 |= 0x00000000;
					case SUBGROUP_ONE   : SCB -> SCB_SHPR3 |= 0x00100010; 
					case SUBGROUP_TWO   : SCB -> SCB_SHPR3 |= 0x00200020; 
					case SUBGROUP_THREE : SCB -> SCB_SHPR3 |= 0x00300030;
			
				}			
		}else if  ( Copy_Group == GROUP_ONE )
		{
			
			
			  swicth ( Copy_SubGroup)
		     	{
					case SUBGROUP_ZERO  : SCB -> SCB_SHPR3 |= 0x00400000;
					case SUBGROUP_ONE   : SCB -> SCB_SHPR3 |= 0x00500000; 
					case SUBGROUP_TWO   : SCB -> SCB_SHPR3 |= 0x00600000; 
					case SUBGROUP_THREE : SCB -> SCB_SHPR3 |= 0x00700000;
			
				}
			
			
		}else if  ( Copy_Group == GROUP_TWO)
		{
			
			
			  swicth ( Copy_SubGroup)
		     	{
					case SUBGROUP_ZERO  : SCB -> SCB_SHPR3 |= 0x00800000;
					case SUBGROUP_ONE   : SCB -> SCB_SHPR3 |= 0x00900000; 
					case SUBGROUP_TWO   : SCB -> SCB_SHPR3 |= 0x00a00000; 
					case SUBGROUP_THREE : SCB -> SCB_SHPR3 |= 0x00b00000;
			
				}
			
			
		}else
		       {
			
			
			   swicth ( Copy_SubGroup)
		     	{
					case SUBGROUP_ZERO  : SCB -> SCB_SHPR3 |= 0x00c0000;
					case SUBGROUP_ONE   : SCB -> SCB_SHPR3 |= 0x00d00000; 
					case SUBGROUP_TWO   : SCB -> SCB_SHPR3 |= 0x00e00000; 
					case SUBGROUP_THREE : SCB -> SCB_SHPR3 |= 0x00f00000;
			
				}
			
			
			
	
	
			
			
		       }
			  
		
		
		
		
	}
	
	
	
	
	
	
	
	
	
}