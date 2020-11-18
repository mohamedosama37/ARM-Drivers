#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "NVIC_private.h"
#include "NVIC_interface.h"



u8  NVIC_EnableInterrupt (u8 ID)
{
	u8 LocalErrorState=0;
	if (!( ID >=0) && ( ID<=43))
	{
		LocalErrorState=1;
	}else
	{		
	u8 LocalRegID=ID/32;
	u8 LocalBitID = ID%32;
	
	ISER [LocalRegID]=(1<<LocalBitID);
	}
	
	return LocalErrorState;
}


u8  NVIC_DisabelInterrupt (u8 ID)
{
	
	u8 LocalErrorState=0;
	if (!( ID >=0) && ( ID<=43))
	{
		LocalErrorState=1;
	}else
	{		
	u8 LocalRegID=ID/32;
	u8 LocalBitID = ID%32;
	
	ICER [LocalRegID]=(1<<LocalBitID);
	}
	
	return LocalErrorState;
	
	
	
	
}


u8 NVIC_setPendingFlag (u8 ID)
{
	
		u8 LocalErrorState=0;
	if (!( ID >=0) && ( ID<=43))
	{
		LocalErrorState=1;
	}else
	{		
	u8 LocalRegID=ID/32;
	u8 LocalBitID = ID%32;
	
	ISPR [LocalRegID]=(1<<LocalBitID);
	}
	
	return LocalErrorState;
	
}





u8 NVIC_clearPrndingFlag (u8 ID)
{
	
	u8 LocalErrorState=0;
	if (!( ID >=0) && ( ID<=43))
	{
		LocalErrorState=1;
	}else
	{		
	u8 LocalRegID=ID/32;
	u8 LocalBitID = ID%32;
	
	ICPR [LocalRegID]=(1<<LocalBitID);
	}
	
	return LocalErrorState;
}




u8 setPirority   (u8 Interrupt ,u8 Group ,u8 Subgroup)
{
	
	u8 LocalErrorState=0;
	AIRCR= 0x05FA0500;
	
	if (group == 0)
	{
		switch ( Subgroup)
		{
			case 0: IPR[Interrupt]= 0x00;break;
			case 1: IPR[Interrupt]=0X10;break;
			case 2:IPR[Interrupt]=0X20;break;
			case 2:IPR[Interrupt]=0X30;break;
			
		}
	}else if (group == 1)
	{
		switch ( Subgroup)
		{
			case 0: IPR[Interrupt]= 0x40;break;
			case 1: IPR[Interrupt]=0X50;break;
			case 2:IPR[Interrupt]=0X60;break;
			case 2:IPR[Interrupt]=0X70;break;
			
		}
		
	}else if (group == 2)
	{
			case 0: IPR[Interrupt]= 0x80;break;
			case 1: IPR[Interrupt]=0X90;break;
			case 2:IPR[Interrupt]=0XA0;break;
			case 2:IPR[Interrupt]=0XB0;break;
	}else
	{
					case 0: IPR[Interrupt]= 0xc0;break;
			case 1: IPR[Interrupt]=0XD0;break;
			case 2:IPR[Interrupt]=0XE0;break;
			case 2:IPR[Interrupt]=0XB0;break;
		
	}
	
	
	
	
	
	return LocalErrorState;
	
}