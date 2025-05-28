#ifndef     __key_h_
#define     __key_h_

#include "public.h"

//16  0
void key_task(task* task_);

// 40  0
void key_timer_task(task* task_);

extern char key_timer_id;
extern char key_task_id;
extern u8 mode;
extern u8 state_key;
#endif

