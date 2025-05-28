#include "public.h"                  // Device header


u8 t=20;
u8 key_o=0;
u8 key_timer_flag=0;
char key_timer_id;
char key_task_id;
u8 mode=0;

//extern u8 you,mode_you;

u8 state_key=2;

//16  0
void key_task(task* task_)
{
	if(key==0 && key_o==1)
	{
		if(key_timer_flag==1)
		{
			t=task_list[key_timer_id].sucCnt;
			if(t<=13)
			{
				mode++;
				mode&=1;
				// if(task_list[aip33626_task_id].active==0||task_list[aip33626_task_id].id2==5)
				// {
				// 	add_task_id(1,5,1000,2,aip33626_task_id);

				// }
				key_timer_flag=0;
				t=15;
			}
		}
		else
		{
			key_timer_flag=1;
		}
	}
	else if(key==1&&key_o==0)
	{
		if(task_list[aip33626_task_id].active==0 && task_1_7_flag==0)
		{
			mode_sub=0;
			state_key=0;
			add_task_id(aip33626_breath_id1,aip33626_breath_id2,
            	aip33626_breath_tim,aip33626_breath_maxcnt,aip33626_task_id);
			state_chrg=3;


		}
	}
	key_o=key;
	if(key==0)
	{
		task_->sucCnt++;
		if(task_->sucCnt>=187)
		{
			task_->sucCnt=0;
			if(cr_flag)
			{	
				cr_flag=0;
				you=6;
				mode_you=0;
				task_list[aip33626_task_id].active=0;
				add_task_id(aip33626_smo_reset_id1,aip33626_smo_reset_id2,
					aip33626_smo_reset_tim,aip33626_smo_reset_maxcnt,aip33626_task_id);
				breath_state=3;
				state_key=2;
				state_smo_det=3;
				state_chrg=3;
			}

		
		}
		
	}
	else
	{
		task_->sucCnt=0;
	}
	switch (state_key)
	{
	case 0:
		if(task_list[aip33626_task_id].active==0)
		{
			mode_sub=2;
			state_key=1;
			add_task_id(aip33626_breath_stop_id1,aip33626_breath_stop_id2,
                aip33626_breath_stop_tim,aip33626_breath_stop_maxcnt,aip33626_task_id);
		}
		break;
	case 1:
		if(task_list[aip33626_task_id].active==0)
		{
			mode_sub=1;
			state_key=2;
			add_task_id(aip33626_breath_id1,aip33626_breath_id2,
            	aip33626_breath_tim,aip33626_breath_maxcnt,aip33626_task_id);
		}
		break;

	default:
		break;
	}
}

// 40  0
void key_timer_task(task* task_)
{
	if(key_timer_flag)
	{
		task_->sucCnt++;
		if(task_->sucCnt>=14)
		{
			key_timer_flag=0;
		}
	}
	else
	{
		task_->sucCnt=0;
	}
}


