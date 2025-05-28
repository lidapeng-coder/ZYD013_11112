#ifndef _si_mic_h
#define _si_mic_h

typedef struct si_mic_state_
{
	u8 o;
	
	
} si_mic_state_;

typedef struct si_mic_flag_
{
	uint8_t dl;
	uint8_t kl;
	u8 dl_zt;
	u8 kl_zt;
	u8 smo_init;
} si_mic_flag_;

typedef struct si_mic_cnt_
{
	
	
	
} si_mic_cnt_;
extern u8 pw;
extern si_mic_flag_ si_mic_flag;
extern s8 si_mic_task_id;
extern u32 pw_t;
extern u8 lowbat_init;
//40ms 0
void si_mic_task(task* task_);
extern u8 cb_ui_flag;
#define si_mic_id	9
#if kuai_8ms
#define si_mic_ms	8
#else
#define si_mic_ms	40
#endif
#define si_mic_max	0

#endif