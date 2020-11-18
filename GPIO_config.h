/***************************************************************************************************************************************************/
/*AUTHOR   : MOHAMED OSAMA                                                                                                                          */
/*DATE     : 25 FEB 2019                                                                                                                             */
/*VERSION  : V01                                                                                                                                    */
/***************************************************************************************************************************************************/
/* DESCRIPTION                                                                                                                                       */
/*------------                                                                                                                                       */
/* this filedefines the implementation of configration                                                                          */
/*****************************************************************************************************************************************************/

#ifndef GPIO_config_h
#define GPIO_confih_h
typedef struct
{
	Register_32bit CRL;
	Register_32bit CRH;
	Register_32bit IDR;
	Register_32bit ODR;
	Register_32bit BSRR;
	Register_32bit BRR;
	Register_32bit LCKR;
	
	
	
	
}GPIO;

#define DIO_GPIOA     ((GPIO *) 0x40010800)
#define DIO_GPIOB     ((GPIO *) 0x40010C00)
#define DIO_GPIOC     ((GPIO *) 0x40011000)
#define DIO_GPIOD     ((GPIO *) 0x40011400)





#endif
