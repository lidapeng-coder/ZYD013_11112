#ifndef __DATATYPE_H__
#define __DATATYPE_H__
//常用数据类型定义

#define uint8_t  unsigned char
#define uint16_t  unsigned int
#define uint32_t  unsigned long

typedef signed   char       s8;     //!< Signed 8 bit integer
typedef signed   short int  s16;    //!< Signed 16 bit integer
typedef signed   long       s32;    //!< Signed 32 bit integer

typedef unsigned char       u8;    //!< Unsigned 8 bit integer
typedef unsigned short int  u16;   //!< Unsigned 16 bit integer
typedef unsigned long       u32;   //!< Unsigned 32 bit integer

typedef signed char  const sc8;   /* Read Only */
typedef signed short const sc16;  /* Read Only */
typedef signed long  const sc32;  /* Read Only */

typedef unsigned char  const uc8;   /* Read Only */
typedef unsigned short const uc16;  /* Read Only */
typedef unsigned long  const uc32;  /* Read Only */


typedef volatile  signed   char       vs8;     //!< Signed 8 bit integer
typedef volatile  signed   short int  vs16;    //!< Signed 16 bit integer
typedef volatile  signed   long       vs32;    //!< Signed 32 bit integer

typedef volatile unsigned char      vu8;  //!<volatile Unsigned 8 bit integer
typedef volatile unsigned short int vu16; //!<volatile Unsigned 16 bit integer
typedef volatile unsigned long      vu32; //!<volatile Unsigned 32 bit integer


#define PWM1        PD0
#define PWM2        PB3
#define SMO_DET1    PINB0
#define SMO_DET2    PINB1 

#define SI_MIC      PINC3

#define LCD_EN      PC0
#define LCD_SCL     PC1
#define LCD_SDA     PC2

#define CHRG_FULL   PINA5

#define USB_DET     PINA4

#define key         PIND2







#endif

