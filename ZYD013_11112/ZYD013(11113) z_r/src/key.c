#include "public.h"                  // Device header

u8 ts=0;

u8 key_o=1;
u8 key_cnt=0,key_cnt_flag=0;
u8 ts_cnt=0;
u8 pw_add_flag=1;
u8 pw_mode=0;
// void ts_cnt_move(u8 new)
// {
//     ts_cnt[0]=ts_cnt[1];
//     ts_cnt[1]=ts_cnt[2];
//     ts_cnt[2]=ts_cnt[3];
//     ts_cnt[3]=new;
// }

//40  0
void key_task(task* task_)
{
    if ((task_list[ui_id].active==0)||(task_list[ui_id].id!=ui_getup_id))
    {
        pw_mode=0;
    }
    // else
    // {
    //     key_state=2;
    // }
    
	if(key_o&& (key==0))
    {
        if((task_list[ui_id].id!=ui_smoing_id)&&(ts==0)&&pw_mode)
        {
            pw++;
            if(pw>=31)
            {
                pw=5;
            }
            //add_task_id(ui_getup_id,ui_getup_ms,ui_getup_max,ui_id);
        }
        // else if(task_list[ui_id].active==0)
        // {
        //     key_state=1;
        // }
        //yd=SMO_DET;
        #if bug
        uart_txln("getup");
        #endif
        if(key_cnt_flag==0)
        {
            key_cnt_flag=1;
        }
        else
        {
            ts_cnt++;
            key_cnt=0;
        }
        if(task_list[ui_id].id!=ui_smoing_id)
        {
            add_task_id(ui_getup_id,ui_getup_ms,ui_getup_max,ui_id);
        }
        pw_add_flag=1;
    }
    // else if(key&& (key_o==0))
    // {
    //     if(key_state==1)
    //     {
    //         key_state=2;
    //     }
    // }
    key_o=key;

    // if((key==0)&&(task_list[ui_id].active==0))
    // {
    // }
    if((key==0))
    {
        if((task_list[ui_id].id!=ui_smoing_id)&&(ts==0)&&pw_mode)
        {
            task_->sucCnt++;
            if(task_->sucCnt>=6)
            {
                task_->sucCnt=0;
                if(task_list[ui_id].id!=ui_smoing_id)
                {
                    add_task_id(ui_getup_id,ui_getup_ms,ui_getup_max,ui_id);
                }
                if(pw_add_flag)
                {
                    pw++;
                    if(pw>=31)
                    {
                        pw=5;
                    }
                }
                if(pw==30)
                {
                    pw_add_flag=0;
                }

            }
        }
    }
    else
    {
        task_->sucCnt=0;
    }
    if(key_cnt_flag)
    {
        key_cnt++;
        if(key_cnt>=13)
        {
            key_cnt_flag=0;
            key_cnt=0;
        }
    }
    else
    {
        if(ts_cnt==1)
        {
            pw_mode=1;
        }
        else if(ts_cnt>=4)
        {
            if((task_list[ui_id].id!=ui_smoing_id)&&(pw_mode==0))
            {
                if(ts==0)
                {
                    ts=1;
                    add_task_id(ui_ts_on_id,ui_ts_on_ms,ui_ts_on_max,ui_id);
                    #if bug
                    uart_txln("ts_on");
                    #endif
                }
                else
                {   
                    ts=0;
                    add_task_id(ui_ts_off_id,ui_ts_off_ms,ui_ts_off_max,ui_id);
                    #if bug
                    uart_txln("ts_off");
                    #endif
                }
            }
        }
        key_cnt=0;
        ts_cnt=0;
    }

}


