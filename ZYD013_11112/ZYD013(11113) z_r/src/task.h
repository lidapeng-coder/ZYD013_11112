#ifndef _task_h
#define _task_h

#define MAX_TASKS 	8          	// 最大任务数量
#define TIMER_BASE 	3        	// 定时器基准时间（8ms）

#define __disable_isr()			GIE=0;PEIE=0
#define __enable_isr()			GIE=1;PEIE=1

typedef struct task{
    u8 id; // 任务函数指针
    uint16_t interval;       // 执行间隔（*8ms）。最大8191ms
    uint16_t counter;        // 当前剩余时间
    uint8_t active;          // 任务激活标志
    uint8_t ready;           // 任务就绪标志
	uint8_t maxSuc;			 //	任务最大执行次数 0是无限次数	
	uint8_t sucCnt;			//当前成功次数
} task;

void task_init(void) ;
// 添加任务（返回任务ID，-1表示失败）
s8 add_task(u8 id, uint32_t interval_ms,uint8_t suc_max);
// 删除任务
// void remove_task(int task_id);

void find_task(task* task_);

s8 add_task_id(u8 id, uint32_t interval_ms,uint8_t suc_max,s8 task_id);
#if 0

#define task_isr();
#define task_loop();

#endif



extern task task_list[MAX_TASKS];

#if 0

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
#if 0
#define 	task_loop()	for(int i=0; i<MAX_TASKS; i++) {\
				if(task_list[i].active && task_list[i].ready) {\
					__disable_isr();\
					task_list[i].ready = 0;\
					__enable_isr();\
					find_task(&task_list[i]);\
					if(task_list[i].maxSuc)\
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
#define 	task_loop()	if(task_list[0].active && task_list[0].ready) {\
                            __disable_isr();\
                            task_list[0].ready = 0;\
                            __enable_isr();\
                            si_mic_task(&task_list[0]);\
                            if(task_list[0].maxSuc)\
                            {\
                                task_list[0].sucCnt++;\
                                if(task_list[0].sucCnt==task_list[0].maxSuc)\
                                {\
                                    task_list[0].active=0;\
                                }\
                            }\
                        }\
                        else if(task_list[1].active && task_list[1].ready) {\
                            __disable_isr();\
                            task_list[1].ready = 0;\
                            __enable_isr();\
                            bat_task(&task_list[1]);\
                            if(task_list[1].maxSuc)\
                            {\
                                task_list[1].sucCnt++;\
                                if(task_list[1].sucCnt==task_list[1].maxSuc)\
                                {\
                                    task_list[1].active=0;\
                                }\
                            }\
                        }\
                        else if(task_list[2].active && task_list[2].ready) {\
                            __disable_isr();\
                            task_list[2].ready = 0;\
                            __enable_isr();\
                            key_task(&task_list[2]);\
                            if(task_list[2].maxSuc)\
                            {\
                                task_list[2].sucCnt++;\
                                if(task_list[2].sucCnt==task_list[2].maxSuc)\
                                {\
                                    task_list[2].active=0;\
                                }\
                            }\
                        }\
                        else if(task_list[3].active && task_list[3].ready) {\
                            __disable_isr();\
                            task_list[3].ready = 0;\
                            __enable_isr();\
                            chrg_task(&task_list[3]);\
                            if(task_list[3].maxSuc)\
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
                            cb_task(&task_list[4]);\
                            if(task_list[4].maxSuc)\
                            {\
                                task_list[4].sucCnt++;\
                                if(task_list[4].sucCnt==task_list[4].maxSuc)\
                                {\
                                    task_list[4].active=0;\
                                }\
                            }\
                        }\
                        else if(task_list[5].active && task_list[5].ready) {\
                            __disable_isr();\
                            task_list[5].ready = 0;\
                            __enable_isr();\
                            sleep_task(&task_list[5]);\
                            if(task_list[5].maxSuc)\
                            {\
                                task_list[5].sucCnt++;\
                                if(task_list[5].sucCnt==task_list[5].maxSuc)\
                                {\
                                    task_list[5].active=0;\
                                }\
                            }\
                        }\
                        else if(task_list[6].active && task_list[6].ready) {\
                            __disable_isr();\
                            task_list[6].ready = 0;\
                            __enable_isr();\
                            find_task(&task_list[6]);\
                            if(task_list[6].maxSuc)\
                            {\
                                task_list[6].sucCnt++;\
                                if(task_list[6].sucCnt==task_list[6].maxSuc)\
                                {\
                                    task_list[6].active=0;\
                                }\
                            }\
                        }
                        // else if(task_list[7].active && task_list[7].ready) {\
                        //     __disable_isr();\
                        //     task_list[7].ready = 0;\
                        //     __enable_isr();\
                        //     find_task(&task_list[7]);\
                        //     if(task_list[7].maxSuc)\
                        //     {\
                        //         task_list[7].sucCnt++;\
                        //         if(task_list[7].sucCnt==task_list[7].maxSuc)\
                        //         {\
                        //             task_list[7].active=0;\
                        //         }\
                        //     }\
                        // }
			

#endif

#endif