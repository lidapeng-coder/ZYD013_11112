#ifndef     __sleep_h_
#define     __sleep_h_

#include "public.h"

extern char sleep_task_id;
// extern u8 sleep_cnt,sleep_flag;
//40ms 0
void sleep_task(task* task_);


#define  int_close()    PA4MSK=0;\
	PB0MSK=0;\
	PB1MSK=0;\
	PC3MSK=0;\
	PD2MSK=0;\
\
	PAIE=0;\
	PBIE=0;\
	PCIE=0;\
	PDIE=0;\
\
	PAIF=0;\
	PBIF=0;\
	PCIF=0;\
	PDIF=0
#endif

