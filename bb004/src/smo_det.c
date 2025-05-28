#include "public.h"                  // Device header



u8 smo_det1_o=1,smo_det2_o=1,cb_flag=0;
u8 state_smo_det=2;

u8 cr_flag=0;
u8 smo_det_task_id;
//16ms  0
void smo_det_task(task* task_)
{
	if(!SI_MIC&&PWM1&&PWM2&&dl0_flag==0&&dl1_flag==0)
	{
		PB0AEN=0;
		PB1AEN=0;

		PB0PU=0;
		PB1PU=0;

		if(smo_det1_o!=SMO_DET1)
		{	
			
			cb_flag=1;
			
		}
		if(smo_det2_o!=SMO_DET2)
		{
			cb_flag=1;
		}
		if(smo_det1_o==1&&SMO_DET1==0)
		{	
			
			cr_flag=1;
			
		}
		if(smo_det2_o==1&&SMO_DET2==0)
		{	
			
			cr_flag=1;
			
		}

		smo_det1_o=SMO_DET1;
		smo_det2_o=SMO_DET2;
		PB0AEN=1;
		PB1AEN=1;
	}
	

	
	if(cb_flag)
	{
		cb_flag=0;
		mode_sub=0;
		task_list[aip33626_task_id].active=0;
		add_task_id(aip33626_breath_id1,aip33626_breath_id2,
            aip33626_breath_tim,aip33626_breath_maxcnt,aip33626_task_id);
		state_smo_det=0;
		breath_state=3;
		state_key=2;
		state_chrg=3;
		
		
	}
	switch (state_smo_det)
	{
	case 0:
		if(task_list[aip33626_task_id].active==0)
		{
			mode_sub=2;
			state_smo_det=1;
			add_task_id(aip33626_breath_stop_id1,aip33626_breath_stop_id2,
				aip33626_breath_stop_tim,aip33626_breath_stop_maxcnt,aip33626_task_id);
		}
		
		break;
	case 1:
		if(task_list[aip33626_task_id].active==0)
		{
			mode_sub=1;
			state_smo_det=3;
			add_task_id(aip33626_breath_id1,aip33626_breath_id2,
            	aip33626_breath_tim,aip33626_breath_maxcnt,aip33626_task_id);
		}
		break;
	default:
		break;
	}
}
