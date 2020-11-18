#include "STD_TYPES.h"
#include "BIT_calc.h"
#include "armRCC_private.h"
#include "armRCC_config.h"
#include "armRCC_interface.h"


u8 RCC_setPLLClk ( u8 Copy_PLL_Status, u8 Copy_Select_Clk )
{
	u8 Local_ErrorState=0;
	u16 Local_Timeout=0;
	/* to check if the status is not on or off */
	if ( (Copy_PLL_Status != RCC_PLL_OFF) && (Copy_PLL_Status != RCC_PLL_ON))
	{
		
		Local_ErrorState=1;
	}
	/* to check if the selected clk argument correct               */
	else if  	( (Copy_Select_Clk != RCC_ENABLE_HSI) && (Copy_Select_Clk != RCC_ENABLE_HSE))
	
	{	
	
	   Local_ErrorState=1;
	}
	
	else
		
	{
		/* in case turn on the pll clk8*/
		if  ( Copy_PLL_Status == RCC_PLL_ON)
			
			{
		                   /* disable the PLL clk    */
						   
						   /*by anding RCC_CR with the  bit 24 ((u32)feff ffff)   */
						   RCC->RCC_CR  &=  RCC_PLL_UNENABLE;
								
						   
		
			              /* if the HSI is selected to be the PLL input clk */
			              if ( Copy_Select_Clk == RCC_ENABLE_HSI)
			              {
				          /* set the HSI/2 As the input PLL clk */
						  /*by clearing the bit 16  by anding RCC-> RCC_CFGR  with ((u32)fffeffff)  */
							 RCC-> RCC_CFGR &= RCC_ENABLE_HSI_SRC;
				              
			              }	 else
					      /* set the HSE AS the input PLL clk		  */
						  {
							  /*select the HSE without being  DIVISION  by 2" 
							  by CLEARING the bit'17' of RCC_CFGR  by anding with ((u32)fffdffff)   */
							  RCC-> RCC_CFGR  &= RCC_NOTENABLE_HSE_DIV;
							  
							  /* select the HSE as PLL src */
							  /*by oring RCC_CFGR  with the  bit 16 ((u32)00010000)*/
							   RCC-> RCC_CFGR  |= RCC_ENABLE_HSE_SRC;
			
			              }
						
						   

                           /* set the PLL clk on */
					      /*by oring the RCC_CR with the  bit '24' ((u32)01000000)*/
					       RCC->RCC_CR  |= RCC_PLL_ENABLE;
						   
						   while ( (Local_Timeout <500 ) && ( !(RCC->RCC_CR & RCC_PLLRDY )))
						   {
							   
							   
							   Local_Timeout++;
							   
						   } 

                            if (	Local_Timeout >= 500)
							{
                                Local_ErrorState=1;

                            }
			}
                 else
				 
	                     {
		                     /* disable the PLL clk    */
						   
	                         /*by anding RCC_CR with the  bit 24 ((u32)feff ffff)   */
	                         RCC->RCC_CR &=  RCC_PLL_UNENABLE;
	                     }
					 

			
                            
	


}
	return Local_ErrorState;
}

u8 RCC_setHSIClk ( u8 Copy_HSI_Status)
{
	
	u8 Local_ErrorState=0;
	u16 Local_Timeout=0;
	/* to check if the status is not on or off */
	if ( (Copy_HSI_Status != RCC_HSIOFF) && (Copy_HSI_Status != RCC_HSION))
	{
		
		Local_ErrorState=1;
	}else
	{
                   /* to check if status is on */
	               if ( Copy_HSI_Status  == RCC_HSION) 
				   {
                   	
                                /* set the HSI Clk by oring  RCC_CR WITH ((u32)0000 0001))  */	
                     					
                                RCC->RCC_CR  |= RCC_HSI_ENABLE;
								
						          /* wait until the  HSI IS STABLE                                */
	                             /* stay in while loop until timeout  is 500  or HSi flag is one  */
                                while ( (Local_Timeout < 500) && ( !(RCC->RCC_CR & RCC_HSIRDY)))
			                      {
				                          Local_Timeout++;
			                      }
                                   /* to check if local_time is 500 or more     */	
								   
			                      if ( Local_Timeout >= 500)
			                      {
                                        Local_ErrorState=1;
		
			                       }			
							
								
				   }
	               else{
	                /* clearing the HSI Clk by anding  RCC_CR WITH ((u32)ffff fffe))  */
	                         RCC->RCC_CR &= RCC_HSI_UNENABLE;
	                   }
	
	}
	
	return Local_ErrorState;
	
}	


u8 RCC_setHSEClk ( u8 Copy_HSE_Status)

{
	u8 Local_ErrorState=0;
	u16 Local_Timeout=0;
	/* to check if the status is not on or off */
	if (( Copy_HSE_Status != RCC_HSEON) &&  ( Copy_HSE_Status != RCC_HSEOFF))
	{
		Local_ErrorState=1;
	}

	else {
		
		                      if ( Copy_HSE_Status == RCC_HSEON)
		                       {

		                    	  RCC->RCC_CR |= RCC_HSEENABLE;
								 
								 
				                              /* wait until the  HSE IS STABLE                                */
	                                         /* stay in while loop until timeout  is 500  or HSE flag is one  */
	                                      while (  (Local_Timeout < 500) &&  ( !(RCC->RCC_CR & RCC_HSERDY) ) )
			                               {
				                               Local_Timeout++;
			                               }
                                                 /* to check if local_time is 500 or more     */
								   
			                               if ( Local_Timeout >= 500)
			                              {
                                                Local_ErrorState=1;
		
			                              }
				
                              }
		                      else
		                        /* if the HSE STATUS IS OFF                              */
		                       {
			                    RCC-> RCC_CR |= RCC_HSEUNENABLE ;
		                        }
		
		
	     }
	
	return Local_ErrorState;	
	
}	






u8 RCC_setHseBYpassClk ( u8 Copy_HSE_Status)

{
	u8 Local_ErrorState=0;
	u16 Local_Timeout=0;
	/* to check if the status is not on or off */
	if (( Copy_HSE_Status != RCC_HSEON) &&  ( Copy_HSE_Status != RCC_HSEOFF))
	{
		Local_ErrorState=1;
	}else 
	{
		
		 if ( Copy_HSE_Status == RCC_HSEON)
		 {
			 
			     /* CLEAR the HSEON BIT BY andING WITH RCC_CR WITH ((u32)fffe ffff)) */
      		       RCC->RCC_CR &= RCC_HSEUNENABLE;
			      /* set the HSEbypassON BIT BY ORING WITH RCC_CR WITH ((u32)0000 0100)) */
			    	RCC->RCC_CR |= RCC_HSEBYPASSENABLE;
				
	             /* set the HSEON BIT BY ORING WITH RCC_CR WITH ((u32)0001 0000)) */
				    RCC->RCC_CR |= RCC_HSEENABLE;
				
				
	              /* wait until the  HSE IS STABLE                                */
	              /* stay in while loop until timeout  is 500  or HSE flag is one  */
	            while ( (Local_Timeout < 500) && ( !(RCC->RCC_CR & RCC_HSERDY)))
			     {
				     Local_Timeout ++;
			     }
                  /* to check if local_time is 500 or more     */
			     if ( Local_Timeout >= 500)
			     {
                      Local_ErrorState=1;
		
			     }
	   }
		         /* if the HSE STATUS IS OFF                              */
		 else  {
	             /* CLEAR the HSEON BIT BY andING WITH RCC_CR WITH ((u32)fffe ffff)) */ 			
      		     RCC->RCC_CR &= RCC_HSEUNENABLE;
		         }
		
		
	}	
	
	return Local_ErrorState;	
	
}	

void RCC_setAHB_Prescaler (u8 Prescaler)
{
	switch (Prescaler)
	{
		/* NOT PRESCALOR */ 
		/*by clearing 7:4 bit */
	 case UN_PRESCALAR: RCC->RCC_CFGR &=AHB_UNDIV ;break;
	    /* PRESCAL BY 2  */    
	 case  PRESCAL_2  :  RCC->RCC_CFGR &=AHB_UNDIV ;
	                     RCC->RCC_CFGR |=AHB_DIV_2 ;
						 break;
	   /* PRESCAL BY 4  */    
	 case  PRESCAL_4 : RCC->RCC_CFGR &=AHB_UNDIV ;
                       RCC->RCC_CFGR |=AHB_DIV_4 ;
					   break;
	    /* PRESCAL BY 8  */    
	 case  PRESCAL_8 : RCC->RCC_CFGR &=AHB_UNDIV ;
	                   RCC->RCC_CFGR |=AHB_DIV_8 ;
					   break;
	   /* PRESCAL BY 16  */    
	 case  PRESCAL_16 : RCC->RCC_CFGR &=AHB_UNDIV ;
                    	RCC->RCC_CFGR |=AHB_DIV_16 ;
						break;
	    /* PRESCAL BY 64  */    
	 case  PRESCAL_64 : RCC->RCC_CFGR &=AHB_UNDIV ;
	                    RCC->RCC_CFGR |=AHB_DIV_64 ;
						break;
	 	/* PRESCAL BY 128 */    
	 case  PRESCAL_128 : RCC->RCC_CFGR &=AHB_UNDIV ;
	                     RCC->RCC_CFGR |=AHB_DIV_128;
						 break;
	 	/* PRESCAL BY 256 */    
	 case  PRESCAL_256 : RCC->RCC_CFGR &=AHB_UNDIV ;
	                     RCC->RCC_CFGR |=AHB_DIV_256 ;
						 break;
		
		
		
		
	}	
	
}	
             

void 	RCC_setAPB1_Prescaler (u8 Prescaler)
{		 
    switch (Prescaler)
	{
		/* NOT PRESCALOR */ 
		/*by clearing the 10:8   */
		/*By anding with ((u32)ffffff8ff)*/
	 case UN_PRESCALAR: RCC->RCC_CFGR &=APB1_UNDIV;break;
	 
	    /* PRESCAL BY 2  */    
	 case  PRESCAL_2  : RCC->RCC_CFGR &=APB1_UNDIV;
                    	RCC->RCC_CFGR |=APB1_DIV2 ;
						break;
	   /* PRESCAL BY 4  */    
	 case  PRESCAL_4 : RCC->RCC_CFGR &=APB1_UNDIV;
	                   RCC->RCC_CFGR |=APB1_DIV4 ;
					   break;
	    /* PRESCAL BY 8  */    
	 case  PRESCAL_8 : RCC->RCC_CFGR &=APB1_UNDIV;
	                   RCC->RCC_CFGR |=APB1_DIV8 ;
					   break;
	   /* PRESCAL BY 16  */    
	 case  PRESCAL_16 : RCC->RCC_CFGR &=APB1_UNDIV;
	                    RCC->RCC_CFGR |=APB1_DIV16 ;
						break;
			
		
	}

}

void 	RCC_setAPB2_Prescaler (u8 Prescaler)
{		 
    switch (Prescaler)
	{
		/* NOT PRESCALOR */ 
	 case UN_PRESCALAR: RCC->RCC_CFGR &=APB2_UNDIV;break;
	    /* PRESCAL BY 2  */    
	 case  PRESCAL_2  : RCC->RCC_CFGR &=APB2_UNDIV;
	                    RCC->RCC_CFGR |=APB2_DIV2  ;
						break;
	   /* PRESCAL BY 4  */    
	 case  PRESCAL_4 : RCC->RCC_CFGR &=APB2_UNDIV;
	                   RCC->RCC_CFGR |=APB2_DIV4 ;
					   break;
	    /* PRESCAL BY 8  */    
	 case  PRESCAL_8 : RCC->RCC_CFGR &=APB2_UNDIV;
	                   RCC->RCC_CFGR |=APB2_DIV8 ;
					   break;
	   /* PRESCAL BY 16  */    
	 case  PRESCAL_16 : RCC->RCC_CFGR &=APB2_UNDIV;
                    	RCC->RCC_CFGR |=APB2_DIV16;
						break;
			
		
	}

}





u8  RCC_SwitchtSystemClk (u8 Copy_RCC_Clk)
{
	
	u8 Local_u8ErrorState =0;
	/* to check if the selected clk argument correct               */
	if ( ( Copy_RCC_Clk != RCC_ENABLE_HSI) && ( Copy_RCC_Clk != RCC_ENABLE_HSE) && ( Copy_RCC_Clk != RCC_ENABLE_PLL))
	{
		Local_u8ErrorState=1;
		
	}else
	
	{
		
		             /* to check if the selected  clk is HSI */
					 if ( Copy_RCC_Clk == RCC_ENABLE_HSI)
					 {
					 /* select the HSI CLK                  */
					 /*by clearing the bit '0'  by anding with ((u32)fffffffe))*/
					     RCC->RCC_CFGR &=((u32)0xfffffffC);
						 RCC->RCC_CFGR &= RCC_HSI_SELECTED;
						 
					 } else if  ( Copy_RCC_Clk == RCC_ENABLE_HSE)
					/* to check if the selected clk is HSE                 */		 
		             {
						 
					 /* select the HSE CLK                  */	
					 	 /*by clearing the bit '0' by oring with ((u32)00000001))*/
						RCC->RCC_CFGR &=((u32)0xfffffffC);
		                RCC->RCC_CFGR |= RCC_HSE_SELECTED; 
		            
		             }else
					
					{	
					
						/* select the PLL CLK                  */	
                        /*by clearing the  bit '1'  by oring with ((u32)00000002))*/
                        RCC->RCC_CFGR &=((u32)0xfffffffC);						
						RCC->RCC_CFGR |= RCC_PLL_SELECTED;  
					 
		            }
		
		
		
	}	
		
	return Local_u8ErrorState;
	
	
}	


u8   RCC_setSystemClk (u8 Copy_RCC_clk)
{
  u8 Local_ErrorState=0;

  	/* to check if the selected clk argument correct               */
     if ( ( Copy_RCC_clk != RCC_ENABLE_HSI) && ( Copy_RCC_clk != RCC_ENABLE_HSE) && ( Copy_RCC_clk != RCC_ENABLE_PLL))
	{
		Local_ErrorState=1;

	}else
	{
		        /* if the selected clk is HSE */
		        if ( Copy_RCC_clk == RCC_ENABLE_HSE)
		       {
			          /* set the HSEclk on*/
			         RCC_setHSEClk ( RCC_HSEON);

					/* select the HSE clk */
					 RCC_SwitchtSystemClk ( RCC_ENABLE_HSE);

					 /* turn off the HSI clk */
					 RCC_setHSIClk (RCC_HSIOFF );
					 /* turn off the PLL clk*/
					  RCC_setPLLClk (  RCC_PLL_OFF, RCC_ENABLE_HSE );


		       }


                /* if the selected clk is PLL */
				else if ( Copy_RCC_clk == RCC_ENABLE_PLL)
				{
					/* set the PLLCLK ON */
					RCC_setPLLClk (  RCC_PLL_ON, RCC_ENABLE_HSE );

					/* select the HSE clk */
					 RCC_SwitchtSystemClk ( RCC_ENABLE_PLL);

					 /* turn off the HSI clk */
					 RCC_setHSIClk (RCC_HSIOFF );

					  /* set the HSEclk off*/
			         RCC_setHSEClk ( RCC_HSEOFF);

                }	else

				{

						 /* set the HSIclk on*/
			         RCC_setHSIClk ( RCC_HSION);
					 /* select the HSI clk */
					 RCC_SwitchtSystemClk ( RCC_ENABLE_HSI);
					   /* set the HSEclk off*/
			         RCC_setHSEClk ( RCC_HSEOFF);
					  /* turn off the PLL clk*/
					  RCC_setPLLClk (  RCC_PLL_OFF, RCC_ENABLE_HSE );





				}


    }
	return Local_ErrorState;
}



void RCC_setFreq(u8 Copy_u8Freq)
{

		 /* set the HSIclk on*/
	     RCC_setHSIClk ( RCC_HSION);

		 /* select the HSI clk */
	     RCC_SwitchtSystemClk ( RCC_ENABLE_HSI);

		 /*set off the PLL clk */
    	RCC_setPLLClk (RCC_PLL_OFF, RCC_ENABLE_HSE );

		/*swicth the  required freq */
		switch (Copy_u8Freq)
		{

		/*enable the mult by 2 */
       /* by clearing  the 21:18 bit */
	    case 16: RCC ->RCC_CFGR  &= ((u32) 0xffc3ffff);  break;
		 /*enable the mult by 3 */
         /* by clearing  the 21:19 bit */
         /* by setting   the bit 18 */
		case 24:   RCC ->RCC_CFGR  &= ((u32) 0xffc3ffff);
		           RCC ->RCC_CFGR |= ((u32) 0x00040000);
				   break;

		/*enable the mult by 4 */
        /* by clearing  the 21 20 18 bit */
        /* by setting   the   bit 19*/

		case 32:  RCC ->RCC_CFGR  &= ((u32) 0xffc3ffff);
		          RCC ->RCC_CFGR |= ((u32) 0x00080000);
				  break;

		 /*enable the mult by 5 */
         /* by clearing  the 21 20  bit */
         /* by setting   the  19 18 bit */
		case 40: RCC ->RCC_CFGR  &= ((u32) 0xffc3ffff);
		         RCC ->RCC_CFGR |= ((u32) 0x000C0000);
				 break;

	      /*enable the mult by 6 */
          /* by clearing  the 21 19 18  bit */
         /* by setting   the  20 bit */
		case 48: RCC ->RCC_CFGR  &= ((u32) 0xffc3ffff);
          	     RCC ->RCC_CFGR |= ((u32) 0x00100000 );
				 break;

	    /*enable the mult by 7 */
        /* by clearing  the 21 18   bit */
        /* by setting   the  20 19 bit */

		case 56: RCC ->RCC_CFGR  &= ((u32) 0xffc3ffff);
		        RCC ->RCC_CFGR  |= ((u32) 0x00140000);
				break;
		 	 /*enable the mult by 8 */
               /* by clearing  the 21 18   bit */
             /* by setting   the  20 19 bit */
		case 64:RCC ->RCC_CFGR  &= ((u32) 0xffc3ffff);
		        RCC ->RCC_CFGR  |= ((u32) 0x00180000);
				break;

		     /*enable the mult by 9 */
            /* by clearing  the 21    bit */
             /* by setting   the   18 20 19 bit */
		case 72: RCC ->RCC_CFGR  &= ((u32) 0xffc3ffff);
		         RCC ->RCC_CFGR  |= ((u32) 0x001C0000);
				 break;



	    }

		 /*set on the PLL clk */
    	RCC_setPLLClk (RCC_PLL_ON , RCC_ENABLE_HSE );
		/* select the PLL clk */
		RCC_SwitchtSystemClk ( RCC_ENABLE_PLL);
	   /* set the HSIclk off*/
	     RCC_setHSIClk ( RCC_HSIOFF);


}

u8 RCC_u8Perpherial(u8 Copy_u8Perpherial, u8 Copy_State)
{

	u8 LocalErrorState=0;
	if ((Copy_State !=PERPHERIAL_OFF)&&(Copy_State !=PERPHERIAL_ON))
	{
		LocalErrorState=1;
	}else
    {
		 if  ( Copy_State == PERPHERIAL_ON)
		 {

			switch ( Copy_u8Perpherial)
			{

			case TIMER11: RCC->RCC_APB2ENR  |= TIMER11CLK_ENABLE ;break;
			case TIMER10: RCC->RCC_APB2ENR  |= TIMER10CLK_ENABLE ;break;
			case USART1:  RCC->RCC_APB2ENR  |= USART1CLK_ENABLE ;break;
			case SPI1x  :  RCC->RCC_APB2ENR  |= SPI1CLK_ENABLE  ; break;
			case TIMER1:  RCC->RCC_APB2ENR  |=TIMER1CLK_ENABLE  ;break;
			case ADC2:    RCC->RCC_APB2ENR  |= ADC2CLK_ENABLE  ;break;
			case ADC1:    RCC->RCC_APB2ENR  |= ADC1CLK_ENABLE  ; break;
            case GPIOAx:   RCC->RCC_APB2ENR  |= GPIOACLK_ENABLE ;break;
            case GPIOBx:   RCC->RCC_APB2ENR  |= GPIOBCLK_ENABLE ;break;
            case GPIOC:   RCC->RCC_APB2ENR  |= GPIOCCLK_ENABLE ;break;
            case GPIOD:   RCC->RCC_APB2ENR  |= GPIODCLK_ENABLE ; break;
            case AFIOENX: RCC->RCC_APB2ENR  |= 0x00000001 ; break;
            case I2C2x :   RCC->RCC_APB1ENR  |= i2C2CLK_ENABLE  ;  break;
            case I2C1x :   RCC->RCC_APB1ENR  |= i2C1CLK_ENABLE  ; break;
            case UART5:   RCC->RCC_APB1ENR  |= UART5CLK_EANBLE ;break;
            case UART4:   RCC->RCC_APB1ENR  |= UART4CLK_ENABLE;break;
            case SPI3:    RCC->RCC_APB1ENR  |= SPI3CLK_ENABLE; break;
            case WWDG:    RCC->RCC_APB1ENR  |= WWDGCLK_ENABLE; break;





			}


		 }else
		 {

		 	switch ( Copy_u8Perpherial)
			{

			case TIMER11: RCC->RCC_APB2ENR  &= ~TIMER11CLK_ENABLE ;break;
			case TIMER10: RCC->RCC_APB2ENR  &= ~TIMER10CLK_ENABLE ;break;
			case USART1:  RCC->RCC_APB2ENR  &= ~USART1CLK_ENABLE ;break;
			case SPI1  :  RCC->RCC_APB2ENR  &= ~SPI1CLK_ENABLE  ; break;
			case TIMER1:  RCC->RCC_APB2ENR  &=~TIMER1CLK_ENABLE  ;break;
			case ADC2:    RCC->RCC_APB2ENR  &= ~ADC2CLK_ENABLE  ;break;
			case ADC1:    RCC->RCC_APB2ENR  &= ~ADC1CLK_ENABLE  ; break;
            case GPIOA:   RCC->RCC_APB2ENR  &= ~GPIOACLK_ENABLE ;break;
            case GPIOB:   RCC->RCC_APB2ENR  &= ~GPIOBCLK_ENABLE ;break;
            case GPIOC:   RCC->RCC_APB2ENR  &= ~GPIOCCLK_ENABLE ;break;
            case GPIOD:   RCC->RCC_APB2ENR  &= ~GPIODCLK_ENABLE ;break;
            case I2C2 :   RCC->RCC_APB1ENR  &= ~i2C2CLK_ENABLE  ; break;
            case I2C1 :   RCC->RCC_APB1ENR  &= ~i2C1CLK_ENABLE  ; break;
            case UART5:   RCC->RCC_APB1ENR  &= ~UART5CLK_EANBLE ;break;
            case UART4:   RCC->RCC_APB1ENR  &= ~UART4CLK_ENABLE;break;
            case SPI3:    RCC->RCC_APB1ENR  &= ~SPI3CLK_ENABLE; break;
            case WWDG:    RCC->RCC_APB1ENR  &= ~WWDGCLK_ENABLE; break;





			}






		 }

    }





	return LocalErrorState;

}

u8 RCC_setBusPrescal (u8 Copy_SelectBus , u8 Copy_SelectPrescal )
{
	u8 LocalErrorState=0;
	/* to check on the selected BUS */
	if ( (Copy_SelectBus !=RCC_AHB ) &&   (Copy_SelectBus !=RCC_APB1 ) &&(Copy_SelectBus !=RCC_APB2 ))
	{
		LocalErrorState=1;
	}else
    {
             /* if the selected bus is AHB*/
             if ( Copy_SelectBus == RCC_AHB)
			 {
				RCC_setAHB_Prescaler ( Copy_SelectPrescal);
			 }

			 /* if the selected bus is APB1*/
             else if ( Copy_SelectBus == RCC_APB1)
			 {
                   	RCC_setAPB1_Prescaler (Copy_SelectPrescal)	;
             }

			 else
			 {

                  RCC_setAPB2_Prescaler (Copy_SelectPrescal)	;
             }










	}



 return LocalErrorState;


}


