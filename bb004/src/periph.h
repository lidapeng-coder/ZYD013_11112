/*******************************************************************************
* Device      : AD18F128
* Author      : XAD Application Team
* Version     : V0.0.1
* Date        : 20221107
********************************************************************************/
#ifndef __PERIPH_H__
#define __PERIPH_H__
//------------------------------------头文件--------------------------------------
#include "AD18F128.h"
#include "public.h"
//------------------------------------宏定义--------------------------------------

#define timer0_isr() cnt0++;\
        if(cnt0>=timer0cnt)\
        {\
            tim0flag=1;\
            cnt0=0;\
            T0CS0=1;\
            T0CLKEN=0;\
        }

#define cmp0_off()  CMP0IE=0
#define cmp0_on()   CMP0IF=0; CMP0IE=1

#define cmp1_off()  CMP1IE=0
#define cmp1_on()   CMP1IF=0; CMP1IE=1

//------------------------------------变量声明------------------------------------

extern u16 cnt0,timer0cnt;
extern u8 tim0flag;
//-----------------------------------外部函数-------------------------------------
void GPIO_Init(void);
void timer1_init(void);//8ms   一直开
char timer0_cnt(uint16_t ms,uint8_t lab);//  16ms  自动关
void fvr_init(void);//1v
u16 adc_bat(void);
void dac_init(void);
void cmp_init(void);

#endif
