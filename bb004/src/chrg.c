#include "public.h"                  // Device header



char chrg_task_id;

u8 state_chrg=3;


u8 usb_det_o=0;

u8 cd_fz=0;

u8 task_1_7_flag=0;
u8 task_1_7_init=0;
//250ms  0
void chrg_task(task* task_)
{
    if(USB_DET)
    {
        if(state_chrg>=3&&breath_state>=3)
        {
            if(task_list[aip33626_task_id].active==0 && task_1_7_flag==0)
			{
                mode_sub=0;
                mode_dian=2;
                add_task_id(aip33626_breath_id1,aip33626_breath_id2,
                    aip33626_breath_tim,aip33626_breath_maxcnt,aip33626_task_id);

                state_chrg=0;   
                state_key=3;
                //breath_state=3;
                state_smo_det=3;
            }
        }
        if(CHRG_FULL)
        {
            if(task_1_7_flag==0)
            {
                task_1_7_init=1;
            }
            task_1_7_flag=1;
            
        }
        if(task_1_7_init)
        {
            task_1_7_init=0;
            dian=6;
            mode_dian=0;
            state_chrg=3;
            task_list[aip33626_task_id].active=0;
            add_task_id(aip33626_batFull_id1,aip33626_batFull_id2,
                aip33626_batFull_tim,aip33626_batFull_maxcnt,aip33626_task_id);
        }
        task_->sucCnt++;
        if(task_->sucCnt>=240)
        {
            task_->sucCnt=0;
            cd_fz++;
            if(cd_fz>=13)
            {
                if(dian<5)
                {
                    dian++;
                }
                cd_fz=0;
            }
        }
    }
    else
    {
        task_->sucCnt=0;
        cd_fz=0;
    }
    if(USB_DET==0 && usb_det_o)
    {
        task_list[aip33626_task_id].active=0;
        add_task_id(aip33626_freeChrg_id1,aip33626_freeChrg_id2,
            aip33626_freeChrg_tim,aip33626_freeChrg_maxcnt,aip33626_task_id);
        state_chrg=3;
        task_1_7_flag=0;

        bat=adc_bat();
    }

    usb_det_o=USB_DET;
    switch (state_chrg)
	{
	case 0:
		if(task_list[aip33626_task_id].active==0)
		{
			mode_sub=2;
			state_chrg=1;
            mode_dian=0;
			add_task_id(aip33626_breath_stop_id1,aip33626_breath_stop_id2,
                aip33626_breath_stop_tim,aip33626_breath_stop_maxcnt,aip33626_task_id);
		}
		
		break;
	case 1:
		if(task_list[aip33626_task_id].active==0)
		{
			mode_sub=1;
			state_chrg=2;
            mode_dian=2;
			add_task_id(aip33626_breath_id1,aip33626_breath_id2,
                aip33626_breath_tim,aip33626_breath_maxcnt,aip33626_task_id);
		}
		break;
    case 2:
		if(USB_DET&&task_list[aip33626_task_id].active==0)
		{
			mode_sub=0;
			state_chrg=0;
            mode_dian=2;
			add_task_id(aip33626_breath_id1,aip33626_breath_id2,
                aip33626_breath_tim,aip33626_breath_maxcnt,aip33626_task_id);
		}
		break;
	default:
		break;
	}
}