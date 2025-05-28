#include"public.h"
#include"task.h"

  task task_list[MAX_TASKS];

// 初始化任务调度系统
void task_init(void) {
    for(uint8_t i=0; i<MAX_TASKS; i++) {
        task_list[i].active = 0;
        task_list[i].ready = 0;
    }
}

// 添加任务（返回任务ID，-1表示失败）
char add_task(uint8_t id1,uint8_t id2, uint32_t interval_ms,uint8_t suc_max) {
    uint16_t interval_ticks = interval_ms >>TIMER_BASE;
    
    // 参数有效性检查
    if(interval_ticks == 0 || id1 == 0 ||id2==0) 
    {
        return -1;
    }

    // 查找空闲任务槽
    for(int i=0; i<MAX_TASKS; i++) {
        if(!task_list[i].active) {
            // 进入临界区（关中断）
            __disable_isr();
            
            task_list[i].id1 = id1;
            task_list[i].id2 = id2;
            task_list[i].interval = interval_ticks;
            task_list[i].counter = interval_ticks;
            task_list[i].active = 1;
            task_list[i].ready = 1;
            task_list[i].maxSuc=suc_max;
			task_list[i].sucCnt=0;
            // 退出临界区（开中断）
            __enable_isr();
            return i;
        }
    }
    return -1;
}

// 添加任务指定id（成功返回1，-1表示失败）
char add_task_id(uint8_t id1,uint8_t id2, uint32_t interval_ms,uint8_t suc_max,char task_id) {
    uint16_t interval_ticks = interval_ms >>TIMER_BASE;
    
    // 参数有效性检查
    if(interval_ticks == 0 || id1 == 0 ||id2==0 ||task_id>=MAX_TASKS) 
    {
        return -1;
    }

    // 查找空闲任务槽
    
        if(!task_list[task_id].active) {
            // 进入临界区（关中断）
            __disable_isr();
            
            task_list[task_id].id1 = id1;
            task_list[task_id].id2 = id2;
            task_list[task_id].interval = interval_ticks;
            task_list[task_id].counter = interval_ticks;
            task_list[task_id].active = 1;
            task_list[task_id].ready = 1;
            task_list[task_id].maxSuc=suc_max;
			task_list[task_id].sucCnt=0;
            // 退出临界区（开中断）
            __enable_isr();
            return task_id;
        }
    
    return -1;
}

// 删除任务
void remove_task(int task_id) {
    if(task_id >= 0 && task_id < MAX_TASKS) {
        __disable_isr();
        task_list[task_id].active = 0;
        __enable_isr();
    }
}
#if dug
void v(task* task_);

#endif


void find_task(uint8_t id1,uint8_t id2,task* task_)
{
    if(id1==aip33626_breath_id1)
    {
        switch (id2)
        {
        case aip33626_sys_begin_id2:
            aip33626_sys_begin(task_);//5s  3
            break;
        case aip33626_flash_id2:
            aip33626_flash(task_);//250ms  10 or 20
            break;
        case aip33626_breath_id2:
            aip33626_breath(task_);//50ms  40
            break;
        case aip33626_breath_stop_id2:
            aip33626_breath_stop(task_);//250ms  21
            break;
        case 5:
            break;
        case aip33626_smo_reset_id2:
            aip33626_smo_reset(task_);//250ms  24
            break;
        case aip33626_batFull_id2:
            aip33626_batFull(task_);//8ms 1
            break;
        case aip33626_freeChrg_id2:
            aip33626_freeChrg(task_);//250ms  7
            break;
        default:
        #if  dug
            v(task_);
        #endif
            break;
        }
    }
    else if(id1==si_mic_task_id1)
    {
        si_mic_task(task_);//40ms  0
    }
    else if(id1==smo_det_task_id1)
    {
        smo_det_task(task_);//16ms  0
    }
    else if(id1==key_task_id1)
    {
        if(id2==key_task_id2)
        {
            key_task(task_);//16  0
        }
        else
        {
            key_timer_task(task_);// 40  0
        }
    }
    else if(id1==bat_task_id1)
    {
        bat_task(task_);////3s  0
    }
    else if(id1==chrg_task_id1)
    {
        chrg_task(task_);//250ms  0
    }
    else
    {
        //250ms 0
        sleep_task(task_);
    }

}

