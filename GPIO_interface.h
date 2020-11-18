/***************************************************************************************************************************************************/
/*AUTHOR   : MOHAMED OSAMA                                                                                                                          */
/*DATE     : 21 FEB 2019                                                                                                                             */
/*VERSION  : V01                                                                                                                                    */
/***************************************************************************************************************************************************/
/* DESCRIPTION                                                                                                                                       */
/*------------                                                                                                                                       */
/* this file defines the APIs corresponding to GPIO                                                                                                    */
/*****************************************************************************************************************************************************/

/* comment :Header file guard                                                                                                                         */
#ifndef DIO_interface_h
#define DIO_interface_h
/* comment : GPIO pin index assigment  */

#define  DIO_u8_PIN_0                                                                   0
#define  DIO_u8_PIN_1                                                                   1
#define  DIO_u8_PIN_2                                                                   2
#define  DIO_u8_PIN_3                                                                   3
#define  DIO_u8_PIN_4                                                                   4
#define  DIO_u8_PIN_5                                                                   5
#define  DIO_u8_PIN_6                                                                   6
#define  DIO_u8_PIN_7                                                                   7
#define  DIO_u8_PIN_8                                                                   8
#define  DIO_u8_PIN_9                                                                   9
#define  DIO_u8_PIN_10                                                                  10
#define  DIO_u8_PIN_11                                                                  11
#define  DIO_u8_PIN_12                                                                  12
#define  DIO_u8_PIN_13                                                                  13
#define  DIO_u8_PIN_14                                                                  14
#define  DIO_u8_PIN_15                                                                  15
#define  DIO_u8_PIN_16                                                                  16 
#define  DIO_u8_PIN_17                                                                  17
#define  DIO_u8_PIN_18                                                                  18
#define  DIO_u8_PIN_19                                                                  19
#define  DIO_u8_PIN_20                                                                  20
#define  DIO_u8_PIN_21                                                                  21
#define  DIO_u8_PIN_22                                                                  22
#define  DIO_u8_PIN_23                                                                  23
#define  DIO_u8_PIN_24                                                                  24
#define  DIO_u8_PIN_25                                                                  25
#define  DIO_u8_PIN_26                                                                  26
#define  DIO_u8_PIN_27                                                                  27
#define  DIO_u8_PIN_28                                                                  28
#define  DIO_u8_PIN_29                                                                  29
#define  DIO_u8_PIN_30                                                                  30
#define  DIO_u8_PIN_31                                                                  31
#define  DIO_u8_PIN_32                                                                  45
#define  DIO_u8_PIN_33                                                                  46
#define  DIO_u8_PIN_34                                                                  47
#define  DIO_u8_PIN_35                                                                  48
#define  DIO_u8_PIN_36                                                                  49


#define DIO_u8PORT0             0
#define DIO_u8PORT1             1
#define DIO_u8PORT2             2
#define DIO_u8PORT3             3

#define DIO_u8_INPUT_ANALOG                   0b0000
#define DIO_u8_INPUT_FLOATING                 0b0100
#define DIO_u8_INPUT_PULLUP                   0b1000
#define DIO_u8_INPUT_PULLDOWN                 5

#define DIO_u8_OUTPUT_2M_PP                   0b0010           
#define DIO_u8_OUTPUT_2M_OD                   0b0110
#define DIO_u8_OUTPUT_2M_AFPP                 0b1010
#define DIO_u8_OUTPUT_2M_AFOD                 0b1110

#define DIO_u8_OUTPUT_10M_PP                  0b0001
#define DIO_u8_OUTPUT_10M_OD                  0b0101
#define DIO_u8_OUTPUT_10M_AFPP                0b1001
#define DIO_u8_OUTPUT_10M_AFOD                0b1101

#define DIO_u8_OUTPUT_50M_PP                  0b0011
#define DIO_u8_OUTPUT_50M_OD                  0b0111
#define DIO_u8_OUTPUT_50M_AFPP                0b1011
#define DIO_u8_OUTPUT_50M_AFOD                0b1111



/* comment : DIO pin value                                                                                                                */

#define INPUT_LOW                                                                        0
#define INPUT_HIGH                                                                       1
/* comment : GPIO pin direction                                                                                                             */
#define DIO_u8_input                                                                     0
#define DIO_u8_output                                                                    1
/* comment : maxmium pins number                                                                                                           */
#define  DIO_u8_PINSNUMBERS                                                             37
/* comment : maxmium ports number                                                                                                           */
#define  DIO_u8_PORTSNUMBERS                                                             4
/* comment : maximum pins in the port                                                                                                       */
#define  	DIO_u8_PINSPERPORT                                                          16

void DIO_voidInitialize (void); 
                                                                                                           
u8 DIO_u8SetPinDir (u8 Copy_u8PinId , u8 Copy_u8Mode);


u8 DIO_u8SetPinValue (u8 Copy_u8PinId , u8 Copy_u8PinValue);
u8 DIO_u8SetPortValue (u8 Copy_u8PortId , u16 Copy_u16PortValue);
u8 DIO_u8GetPinValue ( u8 Copy_u8PinId , u8 * Copy_u8Variable);

//u8 GPIO_u8GetPinValue( u8 Copy_u8PinId , u8 * Copy_u8Variable);

#endif