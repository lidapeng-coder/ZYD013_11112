#ifndef _task_h
#define _task_h

#define sip 0


#define MAX_TASKS 	8          	// 最大任务数量
#define TIMER_BASE 	3        	// 定时器基准时间（8ms）

#define __disable_isr()			TMR1IE=0
#define __enable_isr()			TMR1IE=1

typedef struct task {
    uint16_t interval;       // 执行间隔（ms）。最大8191ms
    uint16_t counter;        // 当前剩余时间
    uint8_t id1;            // 任务函数id
    uint8_t id2;
    uint8_t active;          // 任务激活标志
    uint8_t ready;           // 任务就绪标志
	uint8_t maxSuc;			 //	任务最大执行次数 0是无限次数	
	uint8_t sucCnt;			//当前成功次数
} task;

void task_init(void) ;

// 添加任务（返回任务ID，-1表示失败）
char add_task(uint8_t id1,uint8_t id2, uint32_t interval_ms,uint8_t suc_max);
// 添加任务指定id（成功返回1，-1表示失败）
char add_task_id(uint8_t id1,uint8_t id2, uint32_t interval_ms,uint8_t suc_max,char task_id);
// 删除任务
void remove_task(int task_id);


void find_task(uint8_t id1,uint8_t id2,task* task_);

#if 0

#define task_isr();
#define task_loop();

#endif



 extern   task task_list[MAX_TASKS];


#if sip

#define task_isr() 	for(int i=0; i<MAX_TASKS; i++) {\
        if(task_list[i].active) {\
			task_list[i].counter--;\
            if(task_list[i].counter == 0) {\
                task_list[i].ready = 1;\
                task_list[i].counter = task_list[i].interval;\
            }\
        }\
    }
#else

#define task_isr()  if(task_list[0].active) {\
			task_list[0].counter--;\
            if(task_list[0].counter == 0) {\
                task_list[0].ready = 1;\
                task_list[0].counter = task_list[0].interval;\
            }\
    }\
	if(task_list[1].active) {\
			task_list[1].counter--;\
            if(task_list[1].counter == 0) {\
                task_list[1].ready = 1;\
                task_list[1].counter = task_list[1].interval;\
            }\
    }\
	if(task_list[2].active) {\
			task_list[2].counter--;\
            if(task_list[2].counter == 0) {\
                task_list[2].ready = 1;\
                task_list[2].counter = task_list[2].interval;\
            }\
    }\
	if(task_list[3].active) {\
			task_list[3].counter--;\
            if(task_list[3].counter == 0) {\
                task_list[3].ready = 1;\
                task_list[3].counter = task_list[3].interval;\
            }\
    }\
	if(task_list[4].active) {\
			task_list[4].counter--;\
            if(task_list[4].counter == 0) {\
                task_list[4].ready = 1;\
                task_list[4].counter = task_list[4].interval;\
            }\
    }\
	if(task_list[5].active) {\
			task_list[5].counter--;\
            if(task_list[5].counter == 0) {\
                task_list[5].ready = 1;\
                task_list[5].counter = task_list[5].interval;\
            }\
    }\
	if(task_list[6].active) {\
			task_list[6].counter--;\
            if(task_list[6].counter == 0) {\
                task_list[6].ready = 1;\
                task_list[6].counter = task_list[6].interval;\
            }\
    }\
	if(task_list[7].active) {\
			task_list[7].counter--;\
            if(task_list[7].counter == 0) {\
                task_list[7].ready = 1;\
                task_list[7].counter = task_list[7].interval;\
            }\
    }
#endif

#if sip

#define 	task_loop()	for(u8 i=0; i<MAX_TASKS; i++) {\
				if(task_list[i].active && task_list[i].ready) {\
					__disable_isr();\
					task_list[i].ready = 0;\
					__enable_isr();\
					find_task(task_list[i].id1,task_list[i].id2,&task_list[i]);\
					if(task_list[i].maxSuc!=0)\
					{\
						task_list[i].sucCnt++;\
						if(task_list[i].sucCnt==task_list[i].maxSuc)\
						{\
							task_list[i].active=0;\
						}\
					}\
				}\
			}
#else

#define 	task_loop()     if(task_list[0].active && task_list[0].ready) {\
					            __disable_isr();\
					            task_list[0].ready = 0;\
					            __enable_isr();\
					            find_task(task_list[0].id1,task_list[0].id2,&task_list[0]);\
					            if(task_list[0].maxSuc!=0)\
                                {\
                                    task_list[0].sucCnt++;\
                                    if(task_list[0].sucCnt==task_list[0].maxSuc)\
                                    {\
                                        task_list[0].active=0;\
                                    }\
                                }\
				            }\
                            if(task_list[1].active && task_list[1].ready) {\
					            __disable_isr();\
					            task_list[1].ready = 0;\
					            __enable_isr();\
					            find_task(task_list[1].id1,task_list[1].id2,&task_list[1]);\
					            if(task_list[1].maxSuc!=0)\
                                {\
                                    task_list[1].sucCnt++;\
                                    if(task_list[1].sucCnt==task_list[1].maxSuc)\
                                    {\
                                        task_list[1].active=0;\
                                    }\
                                }\
				            }\
                            if(task_list[2].active && task_list[2].ready) {\
					            __disable_isr();\
					            task_list[2].ready = 0;\
					            __enable_isr();\
					            find_task(task_list[2].id1,task_list[2].id2,&task_list[2]);\
					            if(task_list[2].maxSuc!=0)\
                                {\
                                    task_list[2].sucCnt++;\
                                    if(task_list[2].sucCnt==task_list[2].maxSuc)\
                                    {\
                                        task_list[2].active=0;\
                                    }\
                                }\
				            }\
                            if(task_list[3].active && task_list[3].ready) {\
					            __disable_isr();\
					            task_list[3].ready = 0;\
					            __enable_isr();\
					            find_task(task_list[3].id1,task_list[3].id2,&task_list[3]);\
					            if(task_list[3].maxSuc!=0)\
                                {\
                                    task_list[3].sucCnt++;\
                                    if(task_list[3].sucCnt==task_list[3].maxSuc)\
                                    {\
                                        task_list[3].active=0;\
                                    }\
                                }\
				            }\
                            if(task_list[4].active && task_list[4].ready) {\
					            __disable_isr();\
					            task_list[4].ready = 0;\
					            __enable_isr();\
					            find_task(task_list[4].id1,task_list[4].id2,&task_list[4]);\
					            if(task_list[4].maxSuc!=0)\
                                {\
                                    task_list[4].sucCnt++;\
                                    if(task_list[4].sucCnt==task_list[4].maxSuc)\
                                    {\
                                        task_list[4].active=0;\
                                    }\
                                }\
				            }\
                            if(task_list[5].active && task_list[5].ready) {\
					            __disable_isr();\
					            task_list[5].ready = 0;\
					            __enable_isr();\
					            find_task(task_list[5].id1,task_list[5].id2,&task_list[5]);\
					            if(task_list[5].maxSuc!=0)\
                                {\
                                    task_list[5].sucCnt++;\
                                    if(task_list[5].sucCnt==task_list[5].maxSuc)\
                                    {\
                                        task_list[5].active=0;\
                                    }\
                                }\
				            }\
                            if(task_list[6].active && task_list[6].ready) {\
					            __disable_isr();\
					            task_list[6].ready = 0;\
					            __enable_isr();\
					            find_task(task_list[6].id1,task_list[6].id2,&task_list[6]);\
					            if(task_list[6].maxSuc!=0)\
                                {\
                                    task_list[6].sucCnt++;\
                                    if(task_list[6].sucCnt==task_list[6].maxSuc)\
                                    {\
                                        task_list[6].active=0;\
                                    }\
                                }\
				            }\
                            if(task_list[7].active && task_list[7].ready) {\
					            __disable_isr();\
					            task_list[7].ready = 0;\
					            __enable_isr();\
					            find_task(task_list[7].id1,task_list[7].id2,&task_list[7]);\
					            if(task_list[7].maxSuc!=0)\
                                {\
                                    task_list[7].sucCnt++;\
                                    if(task_list[7].sucCnt==task_list[7].maxSuc)\
                                    {\
                                        task_list[7].active=0;\
                                    }\
                                }\
				            }



#endif


#define aip33626_sys_begin_id1      1
#define aip33626_sys_begin_id2      1
#define aip33626_sys_begin_tim      5000
#define aip33626_sys_begin_maxcnt   3

#define aip33626_flash_id1          1
#define aip33626_flash_id2          2
#define aip33626_flash_tim          250
#define aip33626_flash_maxcnt_5     10
#define aip33626_flash_maxcnt_10    20

#define aip33626_breath_id1      1
#define aip33626_breath_id2      3
#define aip33626_breath_tim      50
#define aip33626_breath_maxcnt   40

#define aip33626_breath_stop_id1      1
#define aip33626_breath_stop_id2      4
#define aip33626_breath_stop_tim      250
#define aip33626_breath_stop_maxcnt   21

#define aip33626_breath_stop_id1      1
#define aip33626_breath_stop_id2      4
#define aip33626_breath_stop_tim      250
#define aip33626_breath_stop_maxcnt   21

#define aip33626_smo_reset_id1      1
#define aip33626_smo_reset_id2      6
#define aip33626_smo_reset_tim      250
#define aip33626_smo_reset_maxcnt   24

#define aip33626_batFull_id1      1
#define aip33626_batFull_id2      7
#define aip33626_batFull_tim      8
#define aip33626_batFull_maxcnt   1

#define aip33626_freeChrg_id1      1
#define aip33626_freeChrg_id2      8
#define aip33626_freeChrg_tim      250
#define aip33626_freeChrg_maxcnt   7


#define si_mic_task_id1      2
#define si_mic_task_id2      1
#define si_mic_task_tim      40
#define si_mic_task_maxcnt   0

#define smo_det_task_id1      3
#define smo_det_task_id2      1
#define smo_det_task_tim      16
#define smo_det_task_maxcnt   0

#define key_task_id1      4
#define key_task_id2      1
#define key_task_tim      16
#define key_task_maxcnt   0

#define key_timer_task_id1      4
#define key_timer_task_id2      2
#define key_timer_task_tim      40
#define key_timer_task_maxcnt   0

#define bat_task_id1      5
#define bat_task_id2      1
#define bat_task_tim      3000
#define bat_task_maxcnt   0

#define chrg_task_id1      6
#define chrg_task_id2      1
#define chrg_task_tim      250
#define chrg_task_maxcnt   0

#define sleep_task_id1      7
#define sleep_task_id2      1
#define sleep_task_tim      250
#define sleep_task_maxcnt   0



#endif