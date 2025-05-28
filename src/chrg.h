#ifndef _chrg_h
#define _chrg_h

#define chrg_g  1

#define chrg_task_id 		12
#define chrg_task_ms		100
#define chrg_task_max		0
//100ms 0
void chrg_task(task* task_);

#if chrg_g
extern u8 chrg_num;
#endif

#endif