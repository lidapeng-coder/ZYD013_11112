#ifndef     __bat_h_
#define     __bat_h_

#include "public.h"


typedef struct _bat
{
	u8 dian;
	u16 bat;
} _bat;
extern _bat bat;


#define bat_task_id 		14
#define bat_task_ms		    1000
#define bat_task_max		0

//2s  0
void bat_task(task* task_);

u16 get_bat(void);
#endif

