#include"public.h"
#include"task.h"

task task_list[MAX_TASKS]={0};

// 初始化任务调度系统
void task_init(void) {
    for(uint8_t i=0; i<MAX_TASKS; i++) {
        task_list[i].active = 0;
        task_list[i].ready = 0;
    }
}

// 添加任务（返回任务ID，-1表示失败）
s8 add_task(u8 id, uint32_t interval_ms,uint8_t suc_max) {
    uint16_t interval_ticks = interval_ms >>TIMER_BASE;
    
    // 参数有效性检查
    if(interval_ticks == 0 ) 
        return -1;

    // 查找空闲任务槽
    for(int i=0; i<MAX_TASKS; i++) {
        if(!task_list[i].active) {
            // 进入临界区（关中断）
            __disable_isr();
            
            task_list[i].id = id;
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
s8 add_task_id(u8 id, uint32_t interval_ms,uint8_t suc_max,s8 task_id) {
    uint16_t interval_ticks = interval_ms >>TIMER_BASE;
    
    // 参数有效性检查
    if(interval_ticks == 0 || task_id<0) 
        return -1;

    // 查找空闲任务槽
        // 进入临界区（关中断）
    __disable_isr();
    
    task_list[task_id].id = id;
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
void find_task(task* task_)
{
    // if(task_->id<=3)
    // {
    //     if(task_->id<=1)
    //     {
    //         if(task_->id==0)//0
    //         {

    //         }
    //         else//1
    //         {

    //         }
    //     }
    //     else
    //     {
    //         if(task_->id==2)//2
    //         {

    //         }
    //         else//3
    //         {
                
    //         }
    //     }
    // }
    // else
    // {
    //     if(task_->id<=5)
    //     {
    //         if(task_->id==4)//4
    //         {

    //         }
    //         else//5
    //         {

    //         }
    //     }
    //     else
    //     {
    //         if(task_->id==6)//6
    //         {

    //         }
    //         else//7
    //         {
                
    //         }
    //     }
    // }
    switch (task_->id)
    {
    case 0:
        ui_cb(task_);//50ms 53
        break;
    case 1:
        ui_chrg(task_);//500ms 0
        break;
    case 2:
        ui_chrgfree(task_);//300ms 6
        break;
    case 3:
        ui_chrgfull(task_);//5000ms 3
        break;
    case 4:
        ui_smoing(task_);//50ms 0
        break;
    case 5:
        ui_smoend_dl_getup(task_);//50ms 73
        break;
    case 6:
        ui_kl(task_);//250ms 10
        break;
    case 7:
        ui_ts_on(task_);//50ms 40
        break;
    case 8:
        ui_ts_off(task_);//50ms 56
        break;
    case 9:
        si_mic_task(task_);//8ms 0
        break;
    case 10:
        ui_timout(task_);//250 10
        break;
    case 11:
        cb_task(task_);//70ms 0
        break;
    case 12:
        chrg_task(task_);//100ms  0
        break;
    case 13:
        key_task(task_);//40ms  0
        break;
    case 14:
        bat_task(task_);//2000ms  0
        break;
    case 15:
        sleep_task(task_);//200ms  0
        break;
    case 16:
        ui_begin(task_);//200ms  0
        break;
    case 17:
        //ui_smoend(task_);//200ms  0
        break;
    default:
        //sleep_task(task_);//200ms  0
        break;
    }
}

// 删除任务
// void remove_task(int task_id) {
//     if(task_id >= 0 && task_id < MAX_TASKS) {
//         __disable_isr();
//         task_list[task_id].active = 0;
//         __enable_isr();
//     }
// }



