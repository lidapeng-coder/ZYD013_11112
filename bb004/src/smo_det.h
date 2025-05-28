#ifndef     __smo_det_h_
#define     __smo_det_h_

#include "public.h"

//16ms  0
void smo_det_task(task* task_);

extern u8 state_smo_det;
extern u8 smo_det_task_id;
extern u8 smo_det1_o,smo_det2_o;
extern u8 cr_flag;
#define smo_det_init()     PB0AEN=0;\
		PB1AEN=0;\
		PB0PU=0;\
		PB1PU=0;\
        smo_det1_o=SMO_DET1;\
        smo_det2_o=SMO_DET2;\
        PB0AEN=1;\
		PB1AEN=1

#endif

