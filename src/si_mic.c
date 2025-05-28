#include"public.h"
#include"si_mic.h"

u8 pw=8;
si_mic_flag_ si_mic_flag={0};
si_mic_state_	si_mic_state={0};
//si_mic_cnt_	si_mic_cnt={0};
s8 si_mic_task_id;
u8 timout=0;
u8 smoing=0;
u32 pw_t=30;
u8 kl_init=0;
//u8 lowbat_flag=0;
u8 lowbat_init=0;
#if kuai_8ms
u8 timout_cnt=0;
#endif
extern u8 cfg_flag;
extern u8 pwm_cnt;
void si_mic_task(task* task_)
{
	
	if(si_mic_state.o==0 && SI_MIC==1 && USB_DET==0)
	{
		yd=SMO_DET;
		if(yd)
		{
			si_mic_flag.kl=1;
			#if bug
			uart_txln("kl_yd");
			#endif
		}
		else if(get_load()<=28)
		{
			si_mic_flag.dl=1;
		}
		else if(USB_DET==0)
		{
			if(bat.dian)
			{
				if(get_bat()<=310)
				{
					bat.bat=310;
					bat.dian=0;
					#if bug
					uart_txln("low");
					#endif
				}
				//u16 b=get_bat();
				//uart_txnum(b,4);
				// if((bat.bat>b)||((bat.bat+50)<=b))
				// {
				// 	bat.bat=b;
				// }
				// if( bat.bat<=305)
				// {
				// 	bat.dian=0;
				// 	//uart_txln("lowbat");
				// }
				// else if ( bat.bat<=340)
				// {
				// 	bat.dian=1;
				// }
				// else if ( bat.bat<=360)
				// {
				// 	bat.dian=2;
				// }
				// else if ( bat.bat<=380)
				// {
				// 	bat.dian=3;
				// }
				// else 
				// {
				// 	bat.dian=4;
				// }
			}
			lowbat_init=0;
			// bat.bat=get_bat();
			#if bug
			uart_txln("smo");
			#endif
			//pwm_cnt=0;
			cfg_flag=1;
			timout=0;
			kl_init=1;
			si_mic_flag.kl_zt=0;
			si_mic_flag.smo_init=1;
			si_mic_flag.dl_zt=0;
			//timer2_init();
		}
	}
	else if(si_mic_state.o==1 && SI_MIC==0)
	{
		#if kuai_8ms
		timout_cnt=0;
		#endif
		task_->sucCnt=0;
		if(smoing)
		{
			smoing=0;
			add_task_id(ui_smoend_id,ui_smoend_ms,ui_smoend_max,ui_id);
			#if bug
			uart_txln("smoend");
			#endif
		}
	}
	si_mic_state.o=SI_MIC;
	if(si_mic_flag.dl)
	{
		si_mic_flag.kl=0;
		smoing=0;
		si_mic_flag.smo_init=0;
		si_mic_flag.dl=0;
		si_mic_flag.dl_zt=1;
		pwm.duty=0;
		task_list[ui_id].active=0;
		add_task_id(ui_dl_id,ui_dl_ms,ui_dl_max,ui_id);
		#if bug
		uart_txln("1");
		#endif
	}
	if(si_mic_flag.kl)
	{
		si_mic_flag.dl=0;
		cb_init();
		smoing=0;
		si_mic_flag.kl=0;
		si_mic_flag.smo_init=0;
		pwm.duty=0;
		si_mic_flag.kl_zt=1;
		task_list[ui_id].active=0;
		add_task_id(ui_kl_id,ui_kl_ms,ui_kl_max,ui_id);
		#if bug
		uart_txln("2");
		#endif
	}
	if(si_mic_flag.kl_zt || si_mic_flag.dl_zt )
	{
		smoing=0;
		
		return;
	}
	//uart_txln("3");
	if(SI_MIC &&(USB_DET==0)&&(ts==0)&&(timout==0))
	{
		if(kl_init)
		{
			kl_init=0;
			if(SMO_DET)
			{
				si_mic_flag.kl=1;
				return;
			}
		}
		#if cpu_t2
		if(bat.dian==0)
		#else
		if(bat.dian==0)
		#endif
		{
			//bat.bat=320;
			//bat.dian=0;
			pwm.duty=0;
			smoing=0;
			//if((lowbat_init==0)&&(si_mic_flag.dl==0))
			if(lowbat_init==0)
			{
				lowbat_init=1;
				add_task_id(ui_lowbat_id,ui_lowbat_ms,ui_lowbat_max,ui_id);
			}
		}
		else
		{
			smoing=1;
			//pwm.bat_t+=5;
			
			//pwm.load_t+=10     
			if(cfg_flag)
			{
				//PA1=~PA1;
				


				//tim_ui.ok=0;

			#if bug
				//uart_txnum(pwm.load_t,4);
			#endif
				cfg_flag=0;
				pwm.duty=(pw_t==0)?30:pw_t;
				pwm_init();
				//uart_txln("3");
				//PA1=~PA1;
			}                          ;
			//tim_ui.ok=1;
			//uart
			// uart_txnum(pwm.load_t ,5);
			// uart_txnum(pwm.bat_t,5);
			// uart_txln("");
			if(si_mic_flag.smo_init)
			{
				si_mic_flag.smo_init=0;
				add_task_id(ui_smoing_id,ui_smoing_ms,ui_smoing_max,ui_id);
			}
			task_->sucCnt++;
			if(task_->sucCnt>=250)
			{
				task_->sucCnt=0;
				#if kuai_8ms
				timout_cnt++;
				if(timout_cnt>=5)
				{
					timout_cnt=0;
				#endif
				
					pwm.duty=0;
					smoing=0;
					add_task_id(ui_timout_id,ui_timout_ms,ui_timout_max,ui_id);
					timout=1;
				#if bug
					uart_txln("out");
				#endif
				#if kuai_8ms
				}
				#endif

			}
		}

	}
	else
	{
		cfg_flag=1;
		#if kuai_8ms
		timout_cnt=0;
		#endif
		smoing=0;
		task_->sucCnt=0;
		pwm.duty=0;
	}





	/* 
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
			
			__pwm_init();
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
	}
	 */
	
}