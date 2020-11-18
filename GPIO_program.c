
/***************************************************************************************************************************************************/
/*AUTHOR   : MOHAMED OSAMA                                                                                                                          */
/*DATE     : 21 FEB 2019                                                                                                                             */
/*VERSION  : V01                                                                                                                                    */
/***************************************************************************************************************************************************/
/* DESCRIPTION                                                                                                                                       */
/*------------                                                                                                                                       */
/* this filedefines the implementation of both private and public functions                                                                          */
/*****************************************************************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "GPIO_interface.h"
#include "GPIO_config.h"
#include "GPIO_private.h"


u8 DIO_u8SetPinValue (u8 Copy_u8PinId , u8 Copy_u8PinValue)
{
	
	u8 Local_u8Result=0;
	switch (Copy_u8PinValue)
	{
		case INPUT_HIGH : Local_u8Result = u8SetPinValue( Copy_u8PinId); break;
		case INPUT_LOW  : Local_u8Result = u8RstPinValue( Copy_u8PinId); break;
		default         : Local_u8Result=1;
	}	
	return  Local_u8Result;
	
}

static u8 u8SetPinValue(u8 Copy_u8PinId) 
{
    u8 Local_u8Result = 0;
	u8 Local_u8ActualPort = Copy_u8PinId / 16;
	u8 Local_u8ActualPin = Copy_u8PinId % 16;
	
	switch ( Local_u8ActualPort)
	{
		case DIO_u8PORT0 : DIO_GPIOA->BSRR.ByteAccess = (1 << Local_u8ActualPin);break;
		case DIO_u8PORT1 : DIO_GPIOB->BSRR.ByteAccess = (1 << Local_u8ActualPin);break;
		case DIO_u8PORT2 : DIO_GPIOC->BSRR.ByteAccess = (1 << Local_u8ActualPin);break;
		case DIO_u8PORT3 : DIO_GPIOD->BSRR.ByteAccess = (1 << Local_u8ActualPin);break;
		default : Local_u8Result=1;
		
	}	
 return Local_u8Result;
}	




static u8 u8RstPinValue( u8 Copy_u8PinId)
{
	u8 Local_u8Result = 0;
	u8 Local_u8ActualPort = Copy_u8PinId / 16;
	u8 Local_u8ActualPin = Copy_u8PinId % 16;
	
	switch ( Local_u8ActualPort)
	{
		case DIO_u8PORT0 : DIO_GPIOA->BRR.ByteAccess = (1 << Local_u8ActualPin);break;
		case DIO_u8PORT1 : DIO_GPIOB->BRR.ByteAccess = (1 << Local_u8ActualPin);break;
		case DIO_u8PORT2 : DIO_GPIOC->BRR.ByteAccess = (1 << Local_u8ActualPin);break;
		case DIO_u8PORT3 : DIO_GPIOD->BRR.ByteAccess = (1 << Local_u8ActualPin);break;
		default : Local_u8Result=1;
		
	}	
 return Local_u8Result;
	
}	
u8 DIO_u8GetPinValue ( u8 Copy_u8PinId , u8 * Copy_u8Variable)
{
	  u8 Local_u8ErrorState = 0;
      u8 Local_u8PortNo;
      u8 Local_u8PinNo;
	  
	     if (  Copy_u8PinId >= DIO_u8_PINSNUMBERS )
            {
                Local_u8ErrorState = 1;
            }else 
            {
	            Local_u8ErrorState=0;
            } 
	
  
		 Local_u8PinNo = Copy_u8PinId %  DIO_u8_PINSPERPORT  ;
         Local_u8PortNo= Copy_u8PinId /  DIO_u8_PINSPERPORT  ;	
         			
	         switch (Local_u8PortNo)
                   {
	   
	   
	                 case DIO_u8PORT0 :
					 
	                        * Copy_u8Variable = get_bit(  GPIO_u32_IDRA, Local_u8PinNo );
					                break;
       					 
                     case DIO_u8PORT1 :
	                    	* Copy_u8Variable = get_bit(  GPIO_u32_IDRB, Local_u8PinNo );        
					               break;
					 case DIO_u8PORT2 :
	                    	* Copy_u8Variable = get_bit(  GPIO_u32_IDRC, Local_u8PinNo );        
					               break;
					 case DIO_u8PORT3 :
	                    	* Copy_u8Variable = get_bit(  GPIO_u32_IDRD, Local_u8PinNo );        
					               break;			   
								   
                 }
				 
		
	return Local_u8ErrorState;
	
}



u8 DIO_u8SetPortValue (u8 Copy_u8PortId , u16 Copy_u16PortValue)
	{
		u8 Local_u8Result=0;
		switch (Copy_u8PortId)
		{
			case DIO_u8PORT0 : DIO_GPIOA->ODR.ByteAccess = Copy_u16PortValue; break;
			case DIO_u8PORT1 : DIO_GPIOB->ODR.ByteAccess = Copy_u16PortValue; break;
			case DIO_u8PORT2 : DIO_GPIOC->ODR.ByteAccess = Copy_u16PortValue; break;
			case DIO_u8PORT3 : DIO_GPIOD->ODR.ByteAccess = Copy_u16PortValue; break;
			default : Local_u8Result =1;
		}
return 	Local_u8Result;
	}	
			
			
u8 DIO_u8SetPinDir (u8 Copy_u8PinId , u8 Copy_u8Mode)
{
	u8 Local_u8Result = 0;
	u8 Local_u8ActualPort = Copy_u8PinId / 16;
	u8 Local_u8ActualPin = Copy_u8PinId % 16;
	if ( Copy_u8Mode == DIO_u8_INPUT_PULLDOWN)
	{
		Copy_u8Mode = DIO_u8_INPUT_PULLUP;
		u8RstPinValue(Copy_u8PinId);
	}	
	if ( Copy_u8Mode == DIO_u8_INPUT_PULLUP)
		{
			Copy_u8Mode = DIO_u8_INPUT_PULLUP;
			u8SetPinValue(Copy_u8PinId);
		}
	if (Local_u8ActualPin < 8)
	{
		switch (Local_u8ActualPort)
		{
			case DIO_u8PORT0 : ASSIGN_NIBBLE (DIO_GPIOA-> CRL.ByteAccess ,Local_u8ActualPin ,Copy_u8Mode); break;
			case DIO_u8PORT1 : ASSIGN_NIBBLE (DIO_GPIOB-> CRL.ByteAccess ,Local_u8ActualPin ,Copy_u8Mode); break;
			case DIO_u8PORT2 : ASSIGN_NIBBLE (DIO_GPIOC-> CRL.ByteAccess ,Local_u8ActualPin ,Copy_u8Mode); break;
			case DIO_u8PORT3 : ASSIGN_NIBBLE (DIO_GPIOD-> CRL.ByteAccess ,Local_u8ActualPin ,Copy_u8Mode); break;
			default       : Local_u8Result =1;
		}	
	}	
	else 
	{
		Local_u8ActualPin=Local_u8ActualPin-8;
		 switch (Local_u8ActualPort)
		{   
			case DIO_u8PORT0 : ASSIGN_NIBBLE (DIO_GPIOA-> CRH.ByteAccess ,Local_u8ActualPin ,Copy_u8Mode); break;
			case DIO_u8PORT1 : ASSIGN_NIBBLE (DIO_GPIOB-> CRH.ByteAccess ,Local_u8ActualPin ,Copy_u8Mode); break;
			case DIO_u8PORT2 : ASSIGN_NIBBLE (DIO_GPIOC-> CRH.ByteAccess ,Local_u8ActualPin ,Copy_u8Mode); break;
			case DIO_u8PORT3 : ASSIGN_NIBBLE (DIO_GPIOD-> CRH.ByteAccess ,Local_u8ActualPin ,Copy_u8Mode); break;
			default       : Local_u8Result =1;
		}	
	}	
	return  Local_u8Result;
}	


void DIO_voidInitialize (void)
{
	DIO_u8SetPinDir (DIO_u8_PIN_0  , 0b0010 );
	DIO_u8SetPinDir (DIO_u8_PIN_1  , 0b0010 );
	DIO_u8SetPinDir (DIO_u8_PIN_2  , 0b0010 );
	DIO_u8SetPinDir (DIO_u8_PIN_3  , 0b0010 );
	DIO_u8SetPinDir (DIO_u8_PIN_4  , 0b0010 );
	DIO_u8SetPinDir (DIO_u8_PIN_5  , 0b0010 );
	DIO_u8SetPinDir (DIO_u8_PIN_6  , 0b0010 );
	DIO_u8SetPinDir (DIO_u8_PIN_7  , 0b0010 );
	DIO_u8SetPinDir (DIO_u8_PIN_8  , 0b0010 );
	DIO_u8SetPinDir (DIO_u8_PIN_9  , 0b0010 );
	DIO_u8SetPinDir (DIO_u8_PIN_10 , 0b0010 );
	DIO_u8SetPinDir (DIO_u8_PIN_11 , 0b0010 );
	DIO_u8SetPinDir (DIO_u8_PIN_12 , 0b0010 );
	DIO_u8SetPinDir (DIO_u8_PIN_13 , 0b0010 );
	DIO_u8SetPinDir (DIO_u8_PIN_14 , 0b0010 );
	DIO_u8SetPinDir (DIO_u8_PIN_15 , 0b0010 );
	DIO_u8SetPinDir (DIO_u8_PIN_16 , 0b0010 );
	DIO_u8SetPinDir (DIO_u8_PIN_17 , 0b0010 );
	DIO_u8SetPinDir (DIO_u8_PIN_18 , 0b0010 );
	DIO_u8SetPinDir (DIO_u8_PIN_19 , 0b0010 );
	DIO_u8SetPinDir (DIO_u8_PIN_20 , 0b0010 );
	DIO_u8SetPinDir (DIO_u8_PIN_21 , 0b0010 );
	DIO_u8SetPinDir (DIO_u8_PIN_22 , 0b0010 );
	DIO_u8SetPinDir (DIO_u8_PIN_23 , 0b0010 );
	DIO_u8SetPinDir (DIO_u8_PIN_24 , 0b0010 );
	DIO_u8SetPinDir (DIO_u8_PIN_25 , 0b0010 );
	DIO_u8SetPinDir (DIO_u8_PIN_26 , 0b0010 );
	DIO_u8SetPinDir (DIO_u8_PIN_27 , 0b0010 );
	DIO_u8SetPinDir (DIO_u8_PIN_28 , 0b0010 );
	DIO_u8SetPinDir (DIO_u8_PIN_29 , 0b0010 );
	DIO_u8SetPinDir (DIO_u8_PIN_30 , 0b0010 );
	DIO_u8SetPinDir (DIO_u8_PIN_31 , 0b0010 );
	DIO_u8SetPinDir (DIO_u8_PIN_32 , 0b0010 );
	DIO_u8SetPinDir (DIO_u8_PIN_33 , 0b0010 );
	DIO_u8SetPinDir (DIO_u8_PIN_34 , 0b0010 );
	DIO_u8SetPinDir (DIO_u8_PIN_35 , 0b0010 );
	DIO_u8SetPinDir (DIO_u8_PIN_36  , 0b0010 );
}
	
	