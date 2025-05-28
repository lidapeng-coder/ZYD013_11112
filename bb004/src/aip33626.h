#ifndef _aip33626_h_
#define  _aip33626_h_

#include "public.h"

#define lcd_on() LCD_EN=0
#define lcd_off() LCD_EN=1

void aip33626_init(void);
//void aip33626_clear(void);//(uint8_t* arr,uint8_t num);
void aip33626_allDisplay_(u8 num);
void aip33626_allDisplay(u8* num);//(uint8_t* arr,uint8_t num)
void arr_col_init(u8 num);
void new_col(u8 you,u8 dian,u8 mode_you,u8 mode_dian,u8 mode,u8 mode_sub);
void aip33626_ram(uint8_t addr,uint8_t dat);

//5s  3
void aip33626_sys_begin(task* task_);//id 1 1
//250ms  10 or 20
void aip33626_flash(task* task_);//id 1 2
//50ms  40
void aip33626_breath(task* task_);//id 1 3
//250ms  21
void aip33626_breath_stop(task* task_);//id 1 4
//1000ms  2
void aip33626_nol_doub(task* task_);//id 1 5
//250ms  24
void aip33626_smo_reset(task* task_);//id 1 6
//8ms 1
void aip33626_batFull(   task* task_);//id 1 7
//250ms  7
void aip33626_freeChrg(task* task_);//id 1 8


extern u8 col_cnt;
extern u8 arr_col[128];
extern u8 col_init;
extern u8 aip33626_task_id;
#define aip_id          0x78
#define aip_self_inc    0x64
#define aip_no_inc      0x60
#define aip_on          0x86
#define aip_off         0x81
#define aip_addrh       0xc0
#define aip_addrl       0xe0

#define a3  2
#define b3  18
#define c3  34
#define d3  50
#define e3  66
#define f3  82
#define g3  98
#define h3  114

#define a4  3
#define b4  19
#define c4  35
#define d4  51
#define e4  67
#define f4  83
#define g4  99
#define h4  115

#define a14 13
#define b14 29
#define c14 45
#define d14 61
#define e14 77
#define f14 93
#define g14 109
#define h14 125


#endif

