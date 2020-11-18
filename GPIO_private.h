/*******************************************************************************************************************************/
/*AUTHOR   : MOHAMED OSAMA                                                                                                    */
/*DATE     : 20 FEB 2019                                                                                                       */
/*VERSION  : V01                                                                                                              */
/******************************************************************************************************************************/
/* DESCRIPTION                                                                                                                */
/*------------                                                                                                                */


/*********************************************************************************************************************************/

#ifndef GPIO_private_h
#define GPIO_private_h


static u8 u8SetPinValue(u8 Copy_u8PinId) ;
static u8 u8RstPinValue(u8 Copy_u8PinId) ;

#define ASSIGN_NIBBLE(REG ,PIN, VAL )  (REG=(REG&(~(0xF << PIN *4)))|(VAL << PIN*4)) 


#define CRLA_REG        (*( (Register_32bit *)0x40010800))
#define GPIO_u32_CRLA      CRLA_REG.ByteAccess

#define CRHA_REG        (*( (Register_32bit *)0x40010804))
#define GPIO_u32_CRHA      CRHA_REG.ByteAccess

#define IDRA_REG        (*( (Register_32bit *)0x40010808))
#define GPIO_u32_IDRA      IDRA_REG.ByteAccess


#define ODRA_REG        (*( (Register_32bit *)0x4001080C))
#define GPIO_u32_ODRA      ODRA_REG.ByteAccess

#define BSRA_REG        (*( (Register_32bit *)0x40010810))
#define GPIO_u32_BSRA      BSRA_REG.ByteAccess

#define BRRA_REG        (*( (Register_32bit *)0x40010814))
#define GPIO_u32_BRRA      BRRA_REG.ByteAccess

#define LCKA_REG        (*( (Register_32bit *)0x40010818))
#define GPIO_u32_LCKA      LCKA_REG.ByteAccess
/****************************************************************************/



#define CRLB_REG        (*( (Register_32bit *)0x40010C00))
#define GPIO_u32_CRLB      CRLB_REG.ByteAccess

#define CRHB_REG        (*( (Register_32bit *)0x40010C04))
#define GPIO_u32_CRHB      CRHB_REG.ByteAccess

#define IDRB_REG        (*( (Register_32bit *)0x40010C08))
#define GPIO_u32_IDRB      IDRB_REG.ByteAccess


#define ODRB_REG        (*( (Register_32bit *)0x40010C0C))
#define GPIO_u32_ODRB      ODRB_REG.ByteAccess

#define BSRB_REG        (*( (Register_32bit *)0x40010C10))
#define GPIO_u32_BSRB      BSRB_REG.ByteAccess

#define BRRB_REG        (*( (Register_32bit *)0x40010C14))
#define GPIO_u32_BRRB      BRRB_REG.ByteAccess

#define LCKB_REG        (*( (Register_32bit *)0x40010C18))
#define GPIO_u32_LCKB      LCKB_REG.ByteAccess

/****************************************************************************/

#define CRLC_REG        (*( (Register_32bit *)0x40011000))
#define GPIO_u32_CRLC      CRLC_REG.ByteAccess

#define CRHC_REG        (*( (Register_32bit *)0x40011004))
#define GPIO_u32_CRHC      CRHC_REG.ByteAccess

#define IDRC_REG        (*( (Register_32bit *)0x40011008))
#define GPIO_u32_IDRC      IDRC_REG.ByteAccess


#define ODRC_REG        (*( (Register_32bit *)0x4001100C))
#define GPIO_u32_ODRC      ODRC_REG.ByteAccess

#define BSRC_REG        (*( (Register_32bit *)0x40011010))
#define GPIO_u32_BSRC      BSRC_REG.ByteAccess

#define BRRC_REG        (*( (Register_32bit *)0x40011014))
#define GPIO_u32_BRRC      BRRC_REG.ByteAccess

#define LCKC_REG        (*( (Register_32bit *)0x40011018))
#define GPIO_u32_LCKC      LCKC_REG.ByteAccess


/****************************************************************/

#define CRLD_REG        (*( (Register_32bit *)0x40011400))
#define GPIO_u32_CRLD      CRLD_REG.ByteAccess

#define CRHD_REG        (*( (Register_32bit *)0x40011404))
#define GPIO_u32_CRHD      CRHD_REG.ByteAccess

#define IDRD_REG        (*( (Register_32bit *)0x40011408))
#define GPIO_u32_IDRD      IDRD_REG.ByteAccess


#define ODRD_REG        (*( (Register_32bit *)0x4001140C))
#define GPIO_u32_ODRD      ODRD_REG.ByteAccess

#define BSRD_REG        (*( (Register_32bit *)0x40011410))
#define GPIO_u32_BSRD      BSRD_REG.ByteAccess

#define BRRD_REG        (*( (Register_32bit *)0x40011414))
#define GPIO_u32_BRRD      BRRD_REG.ByteAccess

#define LCKD_REG        (*( (Register_32bit *)0x40011418))
#define GPIO_u32_LCKD      LCKD_REG.ByteAccess




#endif