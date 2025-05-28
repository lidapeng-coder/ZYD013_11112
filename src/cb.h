#ifndef _cb_h
#define _cb_h


extern u8 zz;

u8 get_load(void);
void cb_task(task* task_);


#define cb_task_id 		11
#define cb_task_ms		70
#define cb_task_max		0
extern u8 cb_o;
#define cb_init()	cb_o=SMO_DET
extern u8 yd;
#endif