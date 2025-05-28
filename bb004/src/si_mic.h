#ifndef     __si_mic_h_
#define     __si_mic_h_

#include "public.h"

void si_mic_task(task* task_);


extern u8 mode_sub;
extern char si_mic_task_id;
extern u8 dl0_flag,dl1_flag;
extern u8 duty0,duty1;

extern u8 breath_state;

extern u8 you,mode_you;

extern u8 dl_init;
#endif

