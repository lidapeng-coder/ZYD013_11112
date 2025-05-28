#ifndef _tim_h
#define _tim_h

typedef struct tim_state_
{
	
	
	
	
} tim_state_;

typedef struct tim_flag_
{
	uint8_t timflag;
	
} tim_flag_;

typedef struct tim_cnt_
{
	uint16_t cnt;
	uint16_t timercnt;
	
	
} tim_cnt_;

extern tim_cnt_ tim_cnt;
extern tim_flag_ tim_flag;

s8 tim_cnt_fuc(uint16_t ms,uint8_t lab);//  16ms  
// void wait(void); 
#endif