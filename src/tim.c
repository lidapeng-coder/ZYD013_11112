#include"public.h"
#include"tim.h"

tim_cnt_ tim_cnt={0,0};
tim_flag_ tim_flag={0};
s8 tim_cnt_fuc(uint16_t ms,uint8_t lab)//  16ms  
{
	static uint8_t init_flag=1;
	static uint8_t ls_lab=0;
	if(ls_lab!=lab)
	{
		init_flag=1;
		ls_lab=lab;
	}
		
	if(init_flag)
	{
		tim_cnt.cnt=0;
		tim_cnt.timercnt=ms>>4;

		/* TMR1H=0x83;
		TMR1L=0x00;
		T1CON=0x30;
		
		TMR1IF=0;
		TMR1IE=1;
		PEIE=1;
		GIE=1;
		TMR1ON=1;
		 */

		tim_cnt_init();
		init_flag=0;
		return -1;
	}
	
	if(tim_flag.timflag)
	{
		tim_flag.timflag=0;
		init_flag=1;
		return 1;
	}
	
	return 0;
	
}

// void wait(void)  
// {	
// 	while(tim_flag.tim1flag!=1);
// 	tim_flag.tim1flag=0;
// }

