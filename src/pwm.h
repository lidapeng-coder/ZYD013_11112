#ifndef _pwm_h
#define _pwm_h


#include "public.h"
typedef struct pwm_
{
	uint8_t duty;
	uint8_t duty_t;
	u8  adc_ok;
	u8  load_flag;
	u8 	dl_t;
	u16 bat_t;
	u16 load_t;
	#if doubled 
	uint8_t duty1;
	uint8_t duty_t1;
	#endif

	#if zhong_wei
	uint8_t	dl_t;
	#endif
} pwm_;
extern pwm_ pwm;

#define pwm_dl_chek		2

#if usedef
#define pwm_init() 	init_duty_t(pwm.duty_t,pwm.duty)

#if 0
#define pwm_task() 		if(pwm.duty)\
						{\
							SMO_PWM=0;\
							__delay_us(pwm_dl_chek);\
							pwm.dl_t=SMO_DET;\
							if(pwm.duty<100)\
							{\
								SMO_PWM=1;\
							}\
							if(pwm.dl_t)\
							{\
								if(pwm.duty<100)\
								{\
									tim_init_pwm(pwm.duty_t);\
									SMO_PWM=0;\
									cmpon_pwm();\
								}\
								else\
								{\
									SMO_PWM=0;\
									cmpon_pwm();\
								}\
							}\
							else\
							{\
								SMO_PWM=1;\
								pwm.duty=0;\
								si_mic_flag.dl=1;\
							}\
							adc_flag=1;\
						}\
						else\
						{\
							SMO_PWM=1;\
							cmpoff_pwm();\
						}

#else

#define pwm_task() 		if(pwm.duty)\
						{\
							if(pwm.duty<100)\
							{\
								tim_init_pwm(pwm.duty_t);\
								SMO_PWM=0;\
								cmpon_pwm();\
							}\
							else\
							{\
								SMO_PWM=0;\
								cmpon_pwm();\
							}\
							adc_flag=1;\
						}\
						else\
						{\
							SMO_PWM=1;\
							cmpoff_pwm();\
						}
#endif


#else
void pwm_init( void );
void pwm_task(void);//8ms 0
#endif


#endif