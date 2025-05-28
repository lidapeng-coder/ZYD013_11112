#include "public.h"                  // Device header


extern u8 mode,state_pwm,duty0,duty1;

char pwm_task_id;
u16 t_pwm,t_pwm_;
#if pwm_bug
//8ms  0
void pwm_task(void)
{
	if(duty0&&duty1)
    {
        if(duty0<100&&duty1<100)
        {
            u16 t=5*(u16)duty0-1;
            u16 t_=5*(u16)duty1-1;
            T2CLKEN=1;			//timer2
            TMR2H=0x00;
            TMR2L=0x00;
            
            PR2H=t>>8;
            PR2L=(u8)t;

            T2CON=0x7b;
            
            TMR2IF=0;
            TMR2IE=1;
            

            T3CLKEN=1;			//timer3
            TMR3H=0x00;
            TMR3L=0x00;
            
            PR3H=t_>>8;
            PR3L=(u8)t_;

            T3CON=0x7b;
            
            TMR3IF=0;
            TMR3IE=1;

            PWM2=0;
            TMR3ON=1;
            cmp1_on();
            PWM1=0;
            TMR2ON=1;
            cmp0_on();
            
        }
        else if(duty0>=100 && duty1<100)
        {
            

            u16 t_=5*(u16)duty1-1;

            T3CLKEN=1;			//timer3
            TMR3H=0x00;
            TMR3L=0x00;
            
            PR3H=t_>>8;
            PR3L=(u8)t_;

            T3CON=0x7b;
            
            TMR3IF=0;
            TMR3IE=1;

            PWM1=0;
            cmp0_on();
            PWM2=0;
            TMR3ON=1;
            cmp1_on();
        }
        else if(duty1>=100 && duty0<100)
        {
            u16 t=5*(u16)duty0-1;
            T2CLKEN=1;			//timer2
            TMR2H=0x00;
            TMR2L=0x00;
            
            PR2H=t>>8;
            PR2L=(u8)t;

            T2CON=0x7b;
            
            TMR2IF=0;
            TMR2IE=1;


            PWM1=0;
            TMR2ON=1;
            cmp0_on();
            PWM2=0;
            cmp1_on();
        }
        else
        {
            PWM1=0;
            cmp0_on();
            PWM2=0;
            cmp1_on();
        }
    }
    else
    {
        cmp0_off();
        cmp1_off();
        PWM1=1;
        PWM2=1;


    }
}
#else

void pwm_init(void)
{
    if(duty0&&duty1)
    {
        if(duty0<100&&duty1<100)
        {
            t_pwm=5*(u16)duty0-1;
            t_pwm_=5*(u16)duty1-1;
        }
        else if(duty0>=100 && duty1<100)
        {
            t_pwm_=5*(u16)duty1-1;
        }
        else if(duty1>=100 && duty0<100)
        {
            t_pwm=5*(u16)duty0-1;
        }
    }
}


void pwm_task(void)
{
	if(duty0&&duty1)
    {
        if(duty0<100&&duty1<100)
        {
            
            T2CLKEN=1;			//timer2
            TMR2H=0x00;
            TMR2L=0x00;
            
            PR2H=t_pwm>>8;
            PR2L=(u8)t_pwm;

            T2CON=0x7b;
            
            TMR2IF=0;
            TMR2IE=1;
            

            T3CLKEN=1;			//timer3
            TMR3H=0x00;
            TMR3L=0x00;
            
            PR3H=t_pwm_>>8;
            PR3L=(u8)t_pwm_;

            T3CON=0x7b;
            
            TMR3IF=0;
            TMR3IE=1;

            PWM2=0;
            TMR3ON=1;
            cmp1_on();
            PWM1=0;
            TMR2ON=1;
            cmp0_on();
            
        }
        else if(duty0>=100 && duty1<100)
        {
            


            T3CLKEN=1;			//timer3
            TMR3H=0x00;
            TMR3L=0x00;
            
            PR3H=t_pwm_>>8;
            PR3L=(u8)t_pwm_;

            T3CON=0x7b;
            
            TMR3IF=0;
            TMR3IE=1;

            PWM1=0;
            cmp0_on();
            PWM2=0;
            TMR3ON=1;
            cmp1_on();

            
        }
        else if(duty1>=100 && duty0<100)
        {
            T2CLKEN=1;			//timer2
            TMR2H=0x00;
            TMR2L=0x00;
            
            PR2H=t_pwm>>8;
            PR2L=(u8)t_pwm;

            T2CON=0x7b;
            
            TMR2IF=0;
            TMR2IE=1;


            PWM1=0;
            TMR2ON=1;
            cmp0_on();
            PWM2=0;
            cmp1_on();
        }
        else
        {
            PWM1=0;
            cmp0_on();
            PWM2=0;
            cmp1_on();
        }

        ADCCLKEN=1;
        ADCON0=0x3d;
        ADCON1=0xdc;
        ADCON3=0x47;
        ADCON4=0x50;
        GO=1;
        ADIF=0;
        ADIE=1;
        GIE=1;
        
    }
    else
    {
        cmp0_off();
        cmp1_off();
        PWM1=1;
        PWM2=1;

    }
}



#endif 
