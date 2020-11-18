#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "armRCC_interface.h"
#include "armRCC_private.h"
#include "armRCC_config.h"
#include  "armRCC_handler.h"



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
			case SPI1  :  RCC->RCC_APB2ENR  |= SPI1CLK_ENABLE  ; break;
			case TIMER1:  RCC->RCC_APB2ENR  |=TIMER1CLK_ENABLE  ;break;
			case ADC2:    RCC->RCC_APB2ENR  |= ADC2CLK_ENABLE  ;break;
			case ADC1:    RCC->RCC_APB2ENR  |= ADC1CLK_ENABLE  ; break;
            case GPIOA:   RCC->RCC_APB2ENR  |= GPIOACLK_ENABLE ;break;
            case GPIOB:   RCC->RCC_APB2ENR  |= GPIOBCLK_ENABLE ;break;
            case GPIOC:   RCC->RCC_APB2ENR  |= GPIOCCLK_ENABLE ;break;
            case GPIOD:   RCC->RCC_APB2ENR  |= GPIODCLK_ENABLE ; break;
            case I2C2 :   RCC->RCC_APB1ENR  |= i2C2CLK_ENABLE  ;  break;
            case I2C1 :   RCC->RCC_APB1ENR  |= i2C1CLK_ENABLE  ; break;
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