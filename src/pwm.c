#include"public.h"
#include"pwm.h"



pwm_ pwm={0,0,0,0,0,1293,300};

#if !usedef
void pwm_init(void)
{
	//pwm.duty_t=pwm.duty *2-1;
	init_duty_t(pwm.duty_t,pwm.duty);
}

void pwm_task(void)//8ms 0
{
	if(pwm.duty)\
	{\
		if(pwm.duty<100)\
		{\
			tim_init_pwm(pwm.duty_t);\
			SMO_PWM=0;\
			cmpon_pwm();\
			timon_pwm();\
		}\
		else\
		{\
			SMO_PWM=0;\
			cmpon_pwm();\
		}\
		ADCON1=0x60;\
		ADCON0=0x39;\
		ADIF=0;\
		ADIE=1;\
		PEIE=1;\
		GIE=1;\
		GO=1;\
		pwm.load_flag=0;\
	}\
	else\
	{\
		SMO_PWM=1;\
		cmpoff_pwm();\
	}
}

#endif
