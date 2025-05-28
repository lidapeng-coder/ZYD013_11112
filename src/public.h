#ifndef __public_h
#define __public_h

#include "peripheral.h"



#if en_di
#if PS1101
#include "PS1101.h"
#include "PS1101_DEF.h"
#endif
#if AD18F128
#include "AD18F128.h"
#endif
#endif
#if zhong_wei
#include "sc.h"
#endif


#ifndef uint8_t
#define uint8_t		unsigned char 
#define uint16_t 	unsigned int  
#define uint32_t 	unsigned long 
#endif

#ifndef u8
#define u8		unsigned char 
#define u16 	unsigned int  
#define u32 	unsigned long 
#endif

#ifndef s8
#define s8		signed char 
#define s16 	signed int  
#define s32 	signed long 
#endif

#ifndef vu8
#define vu8		volatile signed char 
#define vu16 	volatile signed int  
#define vu32 	volatile signed long 
#endif

#define SMO_PWM         PA0
#define SMO_DET         PINB1
#define SMO_DET_EN      PB0
#define SI_MIC          PINA4
#define CHRG_FULL       PINA1
#define USB_DET         PINA5
#define key             PINC6
#define LED0    PC0
#define LED1    PC1
#define LED2    PC2
#define LED3    PC3
#define LED4    PC4
#define LED5    PC5
#define LED6    PB5
#define LED7    PB4
#define LED8    PB3
#define LED9    PB2

#define tris0    TRISC0
#define tris1    TRISC1
#define tris2    TRISC2
#define tris3    TRISC3
#define tris4    TRISC4
#define tris5    TRISC5
#define tris6    TRISB5
#define tris7    TRISB4
#define tris8    TRISB3
#define tris9    TRISB2



#include "peripheral.h"
#include  "task.h"
#include  "cb.h"
#include  "chrg.h"
#include  "ui.h"
#include  "pwm.h"
#include  "si_mic.h"
#include  "sleep.h"
#include  "tim.h"
#include  "bat.h"
#include  "key.h"
// #include "stdio.h"
#define  putch   uart_txc
#endif