#include "public.h"                  // Device header


u8 smo_timerout =0,sim_mic_o=0,state_pwm=0,duty0=0,duty1=0;
u8 state_pwm_cnt=0;
u8 breath_init=1,breath_state=3;
u8 mode_sub=0;

const u32 p[2]={6960000,12960000};

u16 p0=0,p1=0;

u8 you=6,mode_you=0;
u8 dl0_flag=0,dl1_flag=0;
u32 you_cnt=0;

char si_mic_task_id;

u8 dl_init=0;

// u8 smo_init=1;

extern u32 temp1;



//40ms  0
void si_mic_task(task* task_)
{
	if(	sim_mic_o==1 && SI_MIC==0&&mode==0)
	{
		state_pwm_cnt++;
		if(state_pwm_cnt>=3)
		{
			state_pwm++;
			state_pwm&=1;
			state_pwm_cnt=0;
		}
	}
	if(sim_mic_o==0 && SI_MIC==1)
	{
		PB0AEN=0;
		PB1AEN=0;
		PB0PU=0;
		PB1PU=0;

		if(SMO_DET1||SMO_DET2)
		{
	
			dl0_flag=1;
			duty0=0;
			duty1=0;
			dl_init=1;
			//uart_txln("kl");
	
		}
		PB0AEN=1;
		PB1AEN=1;
	}

	sim_mic_o=SI_MIC;

	if(dl0_flag==1 || dl1_flag==1)
	{
		if(dl_init)
		{
			breath_state=3;
			state_key=2;
			state_smo_det=3;
			state_chrg=3;

			task_list[aip33626_task_id].active=0;
			add_task_id(aip33626_flash_id1,aip33626_flash_id2,aip33626_flash_tim,
				aip33626_flash_maxcnt_5,aip33626_task_id);	
			dl_init=0;
		}
		if(timer0_cnt(1008,1)==1)
		{
			dl0_flag=0;
			dl1_flag=0;
			breath_init=1;
		}
		duty0=0;
		duty1=0;
		return;
	}


	if(smo_timerout)
	{
		if(timer0_cnt(1008,0)==1)
		{
			smo_timerout=0;
			breath_init=1;
			
		}
		duty0=0;
		duty1=0;
		return;
	}
	if(SI_MIC&&!USB_DET)
	{
		if(low_bat_flag==0)
		{
			u32 tt=409500/temp1;
			tt+=30;							///!!!!!!
			if(tt<=280)
			{
				duty0=0;
				duty1=0;
				mode_dian=1;
				dian=1;
				low_bat_flag=1;
				return;
			}

			tt*=tt;
			if(mode==0)
			{
				p0=p[0]/(tt);
				p1=p[1]/(tt);
				if(state_pwm==1)
				{
					u16 temp=p0;
					p0=p1;
					p1=temp;
				}
			}
			else
			{
				p0=p[1]/(tt);
				p1=p0;
			}
			duty0=p0;
			duty1=p1;
			
			#if !pwm_bug

			pwm_init();

			#endif

			#if dug
			#endif
		}
		else
		{
			duty0=0;
			duty1=0;
		}
		if(breath_init)
		{
			breath_state=0;
			state_key=2;
			state_smo_det=3;
			state_chrg=3;

			
		}
		switch (breath_state)
		{
			case 0 :
				if(breath_init)
				{
					mode_sub=0;
					task_list[aip33626_task_id].active=0;
					add_task_id(aip33626_breath_id1,aip33626_breath_id2,
            			aip33626_breath_tim,aip33626_breath_maxcnt,aip33626_task_id);
					breath_init=0;
				}
				if(task_list[aip33626_task_id].active==0)
				{
					mode_sub=2;
					breath_state=1;
					add_task_id(aip33626_breath_stop_id1,aip33626_breath_stop_id2,
						aip33626_breath_stop_tim,aip33626_breath_stop_maxcnt,aip33626_task_id);


				}
				break;
			case 1:
				if(task_list[aip33626_task_id].active==0)
				{
					mode_sub=1;
					breath_state=2;
					add_task_id(aip33626_breath_id1,aip33626_breath_id2,
            			aip33626_breath_tim,aip33626_breath_maxcnt,aip33626_task_id);

				}
				break;
			case 2:
				if(task_list[aip33626_task_id].active==0)
				{
					mode_sub=0;
					breath_state=0;
					add_task_id(aip33626_breath_id1,aip33626_breath_id2,
            			aip33626_breath_tim,aip33626_breath_maxcnt,aip33626_task_id);

				}
				break;
			default:
				break;
		}
		task_->sucCnt++;
		if(task_->sucCnt>=200)
		{
			duty0=0;
			duty1=0;
			if(mode==0)
			{
				you_cnt+=200;
			}
			else
			{
				you_cnt+=260;
			}
			task_->sucCnt=0;
			smo_timerout=1;
			task_list[aip33626_task_id].active=0;
			add_task_id(aip33626_flash_id1,aip33626_flash_id2,aip33626_flash_tim,
				aip33626_flash_maxcnt_10,aip33626_task_id);	

		}
	}
	else
	{
		duty0=0;
		duty1=0;
		if(mode==0)
		{
			you_cnt+=task_->sucCnt;
		}
		else
		{
			you_cnt+=task_->sucCnt*1.3f;
		}
		task_->sucCnt=0;
		breath_init=1;
		switch (breath_state)
		{
			case 0 :
				if(task_list[aip33626_task_id].active==0)
				{
					mode_sub=2;
					breath_state=1;
					add_task_id(aip33626_breath_stop_id1,aip33626_breath_stop_id2,
						aip33626_breath_stop_tim,aip33626_breath_stop_maxcnt,aip33626_task_id);

				}
				break;
			case 1:
				if(task_list[aip33626_task_id].active==0)
				{
					mode_sub=1;
					breath_state=3;
					add_task_id(aip33626_breath_id1,aip33626_breath_id2,
            			aip33626_breath_tim,aip33626_breath_maxcnt,aip33626_task_id);

				}
				break;
			default:
				break;
		}
	}
	if(you_cnt>=12500)
	{
		you_cnt=0;
		if(you==0)
		{
			mode_you=1;
		}
		else
		{
			you--;
		}
	}
}

