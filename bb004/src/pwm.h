#ifndef     __pwm_h_
#define     __pwm_h_

#include "public.h"

//8ms  0
void pwm_task(void);

extern char pwm_task_id;
void pwm_init(void);
#endif

