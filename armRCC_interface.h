#ifndef RCC_interface_h
#define RCC_interface_h

#define RCC_ENABLE_HSI 0
#define RCC_ENABLE_HSE 1
#define RCC_ENABLE_PLL 2


#define HSE_DIV        1
#define HSE_NOTDIV     0

 
#define RCC_HSEOFF     0
#define RCC_HSEON      1


#define RCC_HSIOFF      0
#define RCC_HSION       1


#define RCC_PLL_OFF     0
#define RCC_PLL_ON      1

#define PERPHERIAL_OFF  0
#define PERPHERIAL_ON   1

#define  MULT_BY2       2
#define  MULT_BY3       3 
#define  MULT_BY4       4
#define  MULT_BY5       5
#define  MULT_BY6       6
#define  MULT_BY7       7
#define  MULT_BY8       8
#define  MULT_BY9       9        

#define RCC_HSEENABLE             ((u32)0x00010000)
#define RCC_HSEUNENABLE           ((u32)0xfffeffff)
#define RCC_HSEBYPASSENABLE       ((u32)0x00040000)


#define RCC_HSI_ENABLE               ((u32)0x00000001)
#define RCC_HSI_UNENABLE             ((u32)0xfffffffe)

#define RCC_PLL_ENABLE               ((u32)0x01000000)
#define RCC_PLL_UNENABLE             ((u32)0xfeffffff)



#define RCC_ENABLE_HSI_SRC          ((u32) 0xfffeffff)
#define RCC_ENABLE_HSE_SRC          ((u32) 0x00010000)
#define RCC_NOTENABLE_HSE_DIV       ((u32) 0xfffdffff)





#define RCC_HSI_SELECTED            ((u32) 0xfffffffe)
#define RCC_HSE_SELECTED            ((u32) 0x00000001)
#define RCC_PLL_SELECTED            ((u32) 0x00000002)


#define RCC_HSERDY                 ((u32) 0x00020000)
#define RCC_HSIRDY                 ((u32) 0x00000002)
#define RCC_PLLRDY                 ((u32) 0x02000000)

#define AHB_UNDIV                  ((u32) 0xffffff7f)
#define AHB_DIV_2                  ((u32) 0x00000080)
#define AHB_DIV_4                  ((u32) 0x00000090)
#define AHB_DIV_8                  ((u32) 0x000000A0)
#define AHB_DIV_16                 ((u32) 0x000000B0)
#define AHB_DIV_64                 ((u32) 0x000000C0)
#define AHB_DIV_128                ((u32) 0x000000D0)
#define AHB_DIV_256                ((u32) 0x000000E0)
#define AHB_DIV_512                ((u32) 0x000000F0)

#define UN_PRESCALAR                0
#define PRESCAL_2                   2
#define PRESCAL_4                   4 
#define PRESCAL_8                   8
#define PRESCAL_16                  16
#define PRESCAL_64                  64
#define PRESCAL_128                 128
#define PRESCAL_256                 255
#define PRESCAL_512                 512

#define APB1_UNDIV                 ((u32)0xffffff8ff)
#define APB1_DIV2                  ((u32)0x000000400)
#define APB1_DIV4                  ((u32)0x000000500)
#define APB1_DIV8                  ((u32)0x000000600)
#define APB1_DIV16                 ((u32)0x000000700)   

#define APB2_UNDIV                 ((u32)0xfffff8fff)  
#define APB2_DIV2                  ((u32)0x000002000)
#define APB2_DIV4                  ((u32)0x000002800)
#define APB2_DIV8                  ((u32)0x000003000)
#define APB2_DIV16                 ((u32)0x000003800)


#define TIMER11CLK_ENABLE          ((u32)0x00200000) 
#define TIMER10CLK_ENABLE          ((u32)0x00100000)
#define USART1CLK_ENABLE           ((u32)0x00004000)
#define SPI1CLK_ENABLE             ((u32)0x00001000)
#define TIMER1CLK_ENABLE           ((u32)0x00000800)
#define ADC2CLK_ENABLE             ((u32)0x00000400)
#define ADC1CLK_ENABLE             ((u32)0x00000200)
#define GPIOACLK_ENABLE            ((u32)0x00000004)
#define GPIOBCLK_ENABLE            ((u32)0x00000008)
#define GPIOCCLK_ENABLE            ((u32)0x00000010)
#define GPIODCLK_ENABLE            ((u32)0x00000020)
#define i2C2CLK_ENABLE             ((u32)0x00400000)
#define i2C1CLK_ENABLE             ((u32)0x00200000)
#define UART5CLK_EANBLE            ((u32)0x00100000)
#define UART4CLK_ENABLE            ((u32)0x00080000)
#define SPI3CLK_ENABLE             ((u32)0x00008000)
#define WWDGCLK_ENABLE             ((u32)0x00000800)
#define ALTERNATIVE_CLK ENABLE     ((u32)0x00000001)

#define  TIMER11                   0
#define  TIMER10                   1
#define  USART1                    2
#define  SPI1                      3
#define  TIMER1                    4
#define   ADC2                     5
#define   ADC1                     6
#define   GPIOA                    7
#define   GPIOB                    8
#define   GPIOC                    9
#define   GPIOD                    10
#define   I2C2                     11
#define   I2C1                     12
#define   UART5                    13
#define   UART4                    14
#define   SPI3                     15
#define   WWDG                     16


#define  TIMER11                   0
#define  TIMER10                   1
#define  USART1                    2
#define  SPI1x                      3
#define  TIMER1                    4
#define   ADC2                     5
#define   ADC1                     6
#define   GPIOAx                    7
#define   GPIOBx                    8
#define   GPIOC                    9
#define   GPIOD                    10
#define   I2C2x                     11
#define   I2C1x                     12
#define   UART5                    13
#define   UART4                    14
#define   SPI3                     15
#define   WWDG                     16
#define  AFIOENX                   17


#define UN_PRESCALAR                0
#define PRESCAL_2                   2
#define PRESCAL_4                   4
#define PRESCAL_8                   8
#define PRESCAL_16                  16
#define PRESCAL_64                  64
#define PRESCAL_128                 128
#define PRESCAL_256                 255
#define PRESCAL_512                 512



#define RCC_AHB                    0
#define RCC_APB1                   1
#define RCC_APB2                   2



#define RCC_ENABLE_HSI 0
#define RCC_ENABLE_HSE 1
#define RCC_ENABLE_PLL 2

#define PERPHERIAL_OFF  0
#define PERPHERIAL_ON   1


u8 RCC_setPLLClk( u8 Copy_PLL_Status, u8 Copy_Select_Clk );
u8 RCC_setHSIClk( u8 Copy_HSI_Status);
u8 RCC_setHSEClk( u8 Copy_HSE_Status);

u8 RCC_setHseBYpassClk( u8 Copy_HSE_Status);

u8  RCC_SwitchtSystemClk (u8 Copy_RCC_Clk);


/* set the system of clock */
u8   RCC_setSystemClk (u8 Copy_RCC_clk);

/*to enable or disenabel the perpherial */
u8 RCC_u8Perpherial(u8 Copy_u8Perpherial, u8 Copy_State);

/* to change the ferq and it used only in case of using PLL clk */
void RCC_setFreq(u8 Copy_u8Freq);

/*to set the prescale of BUS */

u8 RCC_setBusPrescal (u8 Copy_SelectBus , u8 Copy_SelectPrescal );


void 	RCC_setAPB2_Prescaler (u8 Prescaler);
void    RCC_setAHB_Prescaler (u8 Prescaler);
void 	RCC_setAPB1_Prescaler (u8 Prescaler);
#endif