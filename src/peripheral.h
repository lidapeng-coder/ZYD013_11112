#ifndef __peripheral_h
#define __peripheral_h

#define ioi             1

#define od		        1
#define doubled		    0
#define bug             0
#define bug_a1          0
#define usedef          1

#define kuai_8ms        0

#define en_di           1
#define PS1101          1
#define AD18F128        0

#define zhong_wei       0


#define cpu_t2          0


#include "public.h"

#define cmpout_pwm              CMP0OUT
#define cmpie_pwm               CMP0IE
#define cmpif_pwm               CMP0IF
#define cmpon_pwm()             cmpif_pwm=0;cmpie_pwm=1
#define cmpoff_pwm()            cmpie_pwm=0;cmpif_pwm=0

#define tim_isr_pwm()           
#define timif_pwm               TMR3IF
#define timie_pwm               TMR3IE
#define timon_pwm()             TMR3ON=1
#define timoff_pwm()            TMR3ON=0
#define init_duty_t(x,y)        x=y-1
#define tim_init_pwm(x)         PR3=x; TMR3=0; T3CON0=0x9b;timif_pwm=0;timie_pwm=1;PEIE=1;GIE=1;timon_pwm()


#define tim_cnt_isr()           
#define timon_cnt()             TMR2ON=1
#define timoff_cnt()            TMR2ON=0
#define timif_cnt               TMR2IF
#define timie_cnt               TMR3IE
#define tim_cnt_init()          TMR3=0;PR3=0x7c;T3CON0=0xfb;timif_cnt=0;timie_cnt=1;PEIE=1;GIE=1;timon_cnt()


#define pols0	0xff
#define pols1	0xc0
#define pols2	0xff
#define pols3	0xc0
#define pols4	0xff
#define pols5	0xc0
#define pols6	0x00
#define pols7	0x3f
#define pols8	0x00
#define pols9	0x7f

#if 0
#define pme0	0x01
#define pme1	0x02
#define pme2	0x04
#define pme3	0x08
#define pme4	0x10
#define pme5	0x20
#define pme6	0x08
#define pme7	0x10
#define pme8	0x20
#else
#define pme0	HBPWMOE00
#define pme1	HBPWMOE01
#define pme2	HBPWMOE10
#define pme3	HBPWMOE11
#define pme4	HBPWMOE20
#define pme5	HBPWMOE21
#define pme6	HBPWMOE11
#define pme7	HBPWMOE20
#define pme8	HBPWMOE21
#define pme9	HBPWMOE20
#endif


#define ledpwm_(x,y)	if(x<ui_ldmax){pme##y=1;POLS=pols##y;duty##y=x<<3;uidelay}

#define duty0	DUTY20
#define duty1	DUTY20
#define duty2	DUTY22
#define duty3	DUTY22
#define duty4	DUTY24
#define duty5	DUTY24
#define duty6	DUTY22
#define duty7	DUTY24
#define duty8	DUTY24
#define duty9	DUTY24

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

void cmp0_init(void);
void gpio_init(void);
void timer1_init(void);
void timer0_init(void);//500us
u16 adc_demo(u8 chl);//0 bat  1 load

void uart_init(void);//115200
void uart_txc(u8 c);
void uart_txnum(uint32_t p,uint8_t len);

void uart_txln(const char * p);
void timer2_init(void);







#define pin0_on	1
#define	pin1_on 2
#define pin2_on 4
#define pin3_on 8
#define pin4_on 16
#define pin5_on 32
#define pin6_on 64
#define	pin7_on 128

#define pin0_off	0	
#define	pin1_off	0
#define pin2_off	0
#define pin3_off	0
#define pin4_off	0
#define pin5_off	0
#define pin6_off	0
#define	pin7_off	0


#endif