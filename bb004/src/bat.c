#include "public.h"                  // Device header


u8 dian=1,mode_dian=0;
u16 bat=410,bat_o;
char bat_task_id;
u8 low_bat_flag=0;
//3s  0
void bat_task(task* task_)
{
	if(!SI_MIC&&PWM1&&PWM2&&!USB_DET&&(dl0_flag==0)&&(dl1_flag==0))
	{
		
		bat_o=adc_bat();
		if(bat_o<bat)
		{
			bat=bat_o;
		}

		if(bat<=334)
		{
			mode_dian=1;
			dian=1;
			low_bat_flag=1;
		}
		else if(bat<340)
		{
			mode_dian=0;
			dian=1;
			low_bat_flag=0;
		}
		else if(bat<350)
		{
			mode_dian=0;
			dian=2;
			low_bat_flag=0;
		}
		else if(bat<360)
		{
			mode_dian=0;
			dian=3;
			low_bat_flag=0;
		}
		else if(bat<370)
		{
			mode_dian=0;
			dian=4;
			low_bat_flag=0;
		}
		else if(bat<380)
		{
			mode_dian=0;
			dian=5;
			low_bat_flag=0;
		}
		else 
		{
			mode_dian=0;
			dian=6;
			low_bat_flag=0;
		}
	}
}


