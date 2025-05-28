#ifndef _ui_h
#define _ui_h

#include "public.h"


#define mask0on		1
#define mask0off	0xfe
#define mask1on		2
#define mask1off	0xfd


#define ledzon		0
// #define onz  0
// #define on   1
// #define off  0

#define tris_w  0
#define tris_r  1
#define ledon   1
#define ledoff  0


typedef struct ui_
{
	u8 w1		;//
	u8 w2		;//
	u8 num1		;//
	u8 num2		;//
	u8 ou_d		;//
	u8 wa		;//
	u8 ts		;//
	u8 yd		;//
	u8 dian		;
	u8 dian_s	;//
} ui_;


typedef struct ui__
{
	u8 w	;
	u8 n	;
	u8 ts	;
} ui__;

typedef struct tim_ui_
{
	u8 cnt9		;
	u8 cnt10	;
	u8 ok		;
} tim_ui_;

// typedef struct ui_flag_
// {
// 	bit pinr	;
// 	bit led_on	;
// } ui_flag_;


#define ui_cb_id			0
#define ui_cb_ms			50
#define ui_cb_max			53

#define ui_chrg_id			1
#define ui_chrg_ms			500
#define ui_chrg_max			0

#define ui_chrgfree_id		2
#define ui_chrgfree_ms		300
#define ui_chrgfree_max		6

#define ui_chrgfull_id		3
#define ui_chrgfull_ms		5000
#define ui_chrgfull_max		3

#define ui_smoing_id		4
#define ui_smoing_ms		50
#define ui_smoing_max		0

#define ui_smoend_id		5
#define ui_smoend_ms		50
#define ui_smoend_max		73

#define ui_dl_id			5
#define ui_dl_ms			50
#define ui_dl_max			73

#define ui_getup_id			5
#define ui_getup_ms			50
#define ui_getup_max		73

#define ui_kl_id			6
#define ui_kl_ms			250
#define ui_kl_max			10

#define ui_ts_on_id			7
#define ui_ts_on_ms			50
#define ui_ts_on_max		100

#define ui_ts_off_id		8
#define ui_ts_off_ms		50
#define ui_ts_off_max		43

#define ui_timout_id		10
#define ui_timout_ms		250
#define ui_timout_max		10

#define ui_lowbat_id    ui_timout_id
#define ui_lowbat_ms    ui_timout_ms
#define ui_lowbat_max   20

#define ui_begin_id    16
#define ui_begin_ms    300
#define ui_begin_max   3

//50ms 53
void ui_cb(task* task_);
//500ms 0
void ui_chrg(task* task_);
//250ms 6
void ui_chrgfree(task* task_);
//5000ms 3
void ui_chrgfull(task* task_);
//50ms 0
void ui_smoing(task* task_);
//50ms 73
void ui_smoend_dl_getup(task* task_);
//250ms 10
void ui_kl(task* task_);
//50ms 40
void ui_ts_on(task* task_);
//50ms 42
void ui_ts_off(task* task_);
//250ms 10
void ui_timout(task* task_);
//300ms  3
void ui_begin(task* task_);

void new_nixie(void) ;

void ldz(u8 a);

#define pols0	0xff
#define pols1	0xc0
#define pols2	0xff
#define pols3	0xc0
#define pols4	0xff
#define pols5	0xc0
#define pols6	0x00
#define pols7	0x3f
#define pols8	0x00

#if 0
#define pme0	0x01
#define pme1	0x02
#define pme2	0x04
#define pme3	0x08
#define pme4	0x10
#define pme5	0x20
#define pme6	0x08
#define pme7	0x10
#define pme8	0x20
#else
#define pme0	HBPWMOE00
#define pme1	HBPWMOE01
#define pme2	HBPWMOE10
#define pme3	HBPWMOE11
#define pme4	HBPWMOE20
#define pme5	HBPWMOE21
#define pme6	HBPWMOE11
#define pme7	HBPWMOE20
#define pme8	HBPWMOE21



#endif
#define duty0	DUTY20
#define duty1	DUTY20
#define duty2	DUTY22
#define duty3	DUTY22
#define duty4	DUTY24
#define duty5	DUTY24
#define duty6	DUTY22
#define duty7	DUTY24
#define duty8	DUTY24

#define ui_delay	0
#define uidelay		
extern ui__ ui_ld;
extern volatile tim_ui_ tim_ui;
extern volatile u8 nixie_z[9][2];
extern volatile ui_ ui;
extern s8 ui_id;

/* tris0=tris_r;\
						tris1=tris_r;\
						tris2=tris_r;\
						tris3=tris_r;\
						tris4=tris_r;\
						tris5=tris_r;\
						tris6=tris_r;\
						tris7=tris_r;\
						tris8=tris_r;\
						tris9=tris_r;\
						\
						LED0=ledzon;\
						LED1=ledzon;\
						LED2=ledzon;\
						LED3=ledzon;\
						LED4=ledzon;\
						LED5=ledzon;\
						LED6=ledzon;\
						LED7=ledzon;\
						LED8=ledzon;\
						LED9=ledzon;\ */

#define ui_tim_isr()	tim_ui.ok=1

#define ledz_off()		tris0=tris_r;\
						tris1=tris_r;\
						tris2=tris_r;\
						tris3=tris_r;\
						tris4=tris_r;\
						tris5=tris_r;\
						tris6=tris_r;\
						tris7=tris_r;\
						tris8=tris_r;\
						tris9=tris_r;\
						\
						PME=0;\
						T2CON0=4;\
    					T2CON1=2
// #else
// #define ledz_off()		tris0=tris_r;\
// 						tris1=tris_r;\
// 						tris2=tris_r;\
// 						tris3=tris_r;\
// 						tris4=tris_r;\
// 						tris5=tris_r;\
// 						tris6=tris_r;\
// 						tris7=tris_r;\
// 						tris8=tris_r;\
// 						tris9=tris_r;\
// 						\
// 						PME=0


// #endif
#define ui_loop() 		switch (tim_ui.cnt9)\
						{\
						case 0:\
							if(ui_ld.n>0){\
								if(ui_ld.n<10){pme0=1;POLS=pols0;duty0=ui_ld.n<<3;uidelay}\
								LED0=ledzon;\
								tris0=tris_w;\
								if(nixie_z[0][0]&pin1_on){LED1=ledon;tris1=tris_w;}\
								if(nixie_z[0][0]&pin2_on){LED2=ledon;tris2=tris_w;}\
								if(nixie_z[0][0]&pin3_on){LED3=ledon;tris3=tris_w;}\
								if(nixie_z[0][0]&pin4_on){LED4=ledon;tris4=tris_w;}\
								if(nixie_z[0][0]&pin5_on){LED5=ledon;tris5=tris_w;}\
								if(nixie_z[0][0]&pin6_on){LED6=ledon;tris6=tris_w;}\
								if(nixie_z[0][0]&pin7_on){LED7=ledon;tris7=tris_w;}\
								if(nixie_z[0][1]&pin0_on){LED8=ledon;tris8=tris_w;}\
								if(nixie_z[0][1]&pin1_on){LED9=ledon;tris9=tris_w;}\
							}\
							break;\
						case 1:\
							if(ui_ld.n>0){\
								if(ui_ld.n<10){pme1=1;POLS=pols1;duty1=ui_ld.n<<3;uidelay}\
								LED1=ledzon;\
								tris1=tris_w;\
								if(nixie_z[1][0]&pin0_on){LED0=ledon;tris0=tris_w;}\
								if(nixie_z[1][0]&pin2_on){LED2=ledon;tris2=tris_w;}\
								if(nixie_z[1][0]&pin3_on){LED3=ledon;tris3=tris_w;}\
								if(nixie_z[1][0]&pin4_on){LED4=ledon;tris4=tris_w;}\
								if(nixie_z[1][0]&pin5_on){LED5=ledon;tris5=tris_w;}\
								if(nixie_z[1][0]&pin6_on){LED6=ledon;tris6=tris_w;}\
								if(nixie_z[1][0]&pin7_on){LED7=ledon;tris7=tris_w;}\
								if(nixie_z[1][1]&pin0_on){LED8=ledon;tris8=tris_w;}\
							}\
							break;\
						case 2:\
							if(ui_ld.ts>0){\
								if(ui_ld.ts<10){pme1=1;POLS=pols1;duty1=ui_ld.ts<<3;uidelay}\
								LED1=ledzon;\
								tris1=tris_w;\
								if(nixie_z[1][1]&pin1_on){LED9=ledon;tris9=tris_w;}\
							}\
							break;\
						case 3:\
							if(ui_ld.w>0){\
							if(ui_ld.w<10){pme2=1;POLS=pols2;duty2=ui_ld.w<<3;uidelay}\
							LED2=ledzon;\
							tris2=tris_w;\
							if((nixie_z[2][0]&pin0_on)){LED0=ledon;tris0=tris_w;}\
							if((nixie_z[2][0]&pin1_on)){LED1=ledon;tris1=tris_w;}\
							if((nixie_z[2][0]&pin3_on)){LED3=ledon;tris3=tris_w;}\
							if((nixie_z[2][0]&pin4_on)){LED4=ledon;tris4=tris_w;}\
							if((nixie_z[2][0]&pin5_on)){LED5=ledon;tris5=tris_w;}\
							if((nixie_z[2][0]&pin6_on)){LED6=ledon;tris6=tris_w;}\
							if((nixie_z[2][0]&pin7_on)){LED7=ledon;tris7=tris_w;}}\
							break;\
						case 4:\
							if(ui_ld.n>0){\
							if(ui_ld.n<10){pme2=1;POLS=pols2;duty2=ui_ld.n<<3;uidelay}\
							LED2=ledzon;\
							tris2=tris_w;\
							if((nixie_z[2][1]&pin0_on)){LED8=ledon;tris8=tris_w;}}\
							break;\
						case 5:\
							if(ui_ld.w>0){\
							if(ui_ld.w<10){pme3=1;POLS=pols3;duty3=ui_ld.w<<3;uidelay}\
							LED3=ledzon;\
							tris3=tris_w;\
							if((nixie_z[3][0]&pin0_on)){LED0=ledon;tris0=tris_w;}\
							if((nixie_z[3][0]&pin1_on)){LED1=ledon;tris1=tris_w;}\
							if((nixie_z[3][0]&pin2_on)){LED2=ledon;tris2=tris_w;}\
							if((nixie_z[3][0]&pin4_on)){LED4=ledon;tris4=tris_w;}\
							if((nixie_z[3][0]&pin5_on)){LED5=ledon;tris5=tris_w;}\
							if((nixie_z[3][0]&pin6_on)){LED6=ledon;tris6=tris_w;}\
							if((nixie_z[3][0]&pin7_on)){LED7=ledon;tris7=tris_w;}}\
							break;\
						case 6:\
							if(ui_ld.w>0){\
							if(ui_ld.w<10){pme4=1;POLS=pols4;duty4=ui_ld.w<<3;uidelay}\
							LED4=ledzon;\
							tris4=tris_w;\
							if((nixie_z[4][0]&pin0_on)){LED0=ledon;tris0=tris_w;}\
							if((nixie_z[4][0]&pin1_on)){LED1=ledon;tris1=tris_w;}\
							if((nixie_z[4][0]&pin2_on)){LED2=ledon;tris2=tris_w;}\
							if((nixie_z[4][0]&pin3_on)){LED3=ledon;tris3=tris_w;}\
							if((nixie_z[4][0]&pin5_on)){LED5=ledon;tris5=tris_w;}\
							if((nixie_z[4][0]&pin6_on)){LED6=ledon;tris6=tris_w;}\
							if((nixie_z[4][0]&pin7_on)){LED7=ledon;tris7=tris_w;}\
							if((nixie_z[4][1]&pin0_on)){LED8=ledon;tris8=tris_w;}\
							if((nixie_z[4][1]&pin1_on)){LED9=ledon;tris9=tris_w;}}\
							break;\
						case 7:\
							if(ui_ld.w>0){\
							if(ui_ld.w<10){pme5=1;POLS=pols5;duty5=ui_ld.w<<3;uidelay}\
							LED5=ledzon;\
							tris5=tris_w;\
							if((nixie_z[5][0]&pin0_on)){LED0=ledon;tris0=tris_w;}\
							if((nixie_z[5][0]&pin1_on)){LED1=ledon;tris1=tris_w;}\
							if((nixie_z[5][0]&pin2_on)){LED2=ledon;tris2=tris_w;}\
							if((nixie_z[5][0]&pin3_on)){LED3=ledon;tris3=tris_w;}\
							if((nixie_z[5][0]&pin4_on)){LED4=ledon;tris4=tris_w;}\
							if((nixie_z[5][0]&pin6_on)){LED6=ledon;tris6=tris_w;}\
							if((nixie_z[5][0]&pin7_on)){LED7=ledon;tris7=tris_w;}\
							if((nixie_z[5][1]&pin0_on)){LED8=ledon;tris8=tris_w;}\
							if((nixie_z[5][1]&pin1_on)){LED9=ledon;tris9=tris_w;}}\
							break;\
						case 8:\
							if(ui_ld.w>0){\
							if(ui_ld.w<10){pme6=1;POLS=pols6;duty6=ui_ld.w<<3;uidelay}\
							LED6=ledzon;\
							tris6=tris_w;\
							if((nixie_z[6][0]&pin0_on)){LED0=ledon;tris0=tris_w;}\
							if((nixie_z[6][0]&pin1_on)){LED1=ledon;tris1=tris_w;}\
							if((nixie_z[6][0]&pin2_on)){LED2=ledon;tris2=tris_w;}\
							if((nixie_z[6][0]&pin3_on)){LED3=ledon;tris3=tris_w;}\
							if((nixie_z[6][0]&pin4_on)){LED4=ledon;tris4=tris_w;}\
							if((nixie_z[6][0]&pin5_on)){LED5=ledon;tris5=tris_w;}\
							if((nixie_z[6][0]&pin7_on)){LED7=ledon;tris7=tris_w;}\
							if((nixie_z[6][1]&pin0_on)){LED8=ledon;tris8=tris_w;}\
							if((nixie_z[6][1]&pin1_on)){LED9=ledon;tris9=tris_w;}}\
							break;\
						case 9:\
							if(ui_ld.w>0){\
							if(ui_ld.w<10){pme7=1;POLS=pols7;duty7=ui_ld.w<<3;uidelay}\
							LED7=ledzon;\
							tris7=tris_w;\
							if((nixie_z[7][0]&pin0_on)){LED0=ledon;tris0=tris_w;}\
							if((nixie_z[7][0]&pin1_on)){LED1=ledon;tris1=tris_w;}\
							if((nixie_z[7][0]&pin2_on)){LED2=ledon;tris2=tris_w;}\
							if((nixie_z[7][0]&pin3_on)){LED3=ledon;tris3=tris_w;}\
							if((nixie_z[7][0]&pin4_on)){LED4=ledon;tris4=tris_w;}\
							if((nixie_z[7][0]&pin5_on)){LED5=ledon;tris5=tris_w;}\
							if((nixie_z[7][0]&pin6_on)){LED6=ledon;tris6=tris_w;}\
							if((nixie_z[7][1]&pin0_on)){LED8=ledon;tris8=tris_w;}\
							if((nixie_z[7][1]&pin1_on)){LED9=ledon;tris9=tris_w;}}\
							break;\
						case 10:\
							if(ui_ld.n>0){\
							if(ui_ld.n<10){pme8=1;POLS=pols8;duty8=ui_ld.n<<3;uidelay}\
							LED8=ledzon;\
							tris8=tris_w;\
							if((nixie_z[8][0]&pin0_on)){LED0=ledon;tris0=tris_w;}\
							if((nixie_z[8][0]&pin1_on)){LED1=ledon;tris1=tris_w;}\
							if((nixie_z[8][0]&pin2_on)){LED2=ledon;tris2=tris_w;}\
							if((nixie_z[8][0]&pin3_on)){LED3=ledon;tris3=tris_w;}\
							if((nixie_z[8][0]&pin4_on)){LED4=ledon;tris4=tris_w;}}\
							break;\
						case 11:\
							if(ui_ld.w>0){\
							if(ui_ld.w<10){pme8=1;POLS=pols8;duty8=ui_ld.w<<3;uidelay}\
							LED8=ledzon;\
							tris8=tris_w;\
							if((nixie_z[8][0]&pin5_on)){LED5=ledon;tris5=tris_w;}\
							if((nixie_z[8][0]&pin6_on)){LED6=ledon;tris6=tris_w;}\
							if((nixie_z[8][0]&pin7_on)){LED7=ledon;tris7=tris_w;}}\
							break;\
						\
						default:\
							break;\
						}\
						tim_ui.cnt9++;\
						if(tim_ui.cnt9>=12)\
						{\
							tim_ui.cnt9=0;\
						}


#endif


/* 
						if(tim_ui.cnt9<=4)\
						{\
							if(tim_ui.cnt9<=2)\
							{\
								if(tim_ui.cnt9==0)\
								{\
									\
									tris0=tris_w;\
									if((nixie_z[0][0]&pin1_on) && tim_ui.cnt10<ui_ld.n){tris1=tris_w;LED1=ledon;}\
									if((nixie_z[0][0]&pin2_on) && tim_ui.cnt10<ui_ld.n){tris2=tris_w;LED2=ledon;}\
									if((nixie_z[0][0]&pin3_on) && tim_ui.cnt10<ui_ld.n){tris3=tris_w;LED3=ledon;}\
									if((nixie_z[0][0]&pin4_on) && tim_ui.cnt10<ui_ld.n){tris4=tris_w;LED4=ledon;}\
									if((nixie_z[0][0]&pin5_on) && tim_ui.cnt10<ui_ld.n){tris5=tris_w;LED5=ledon;}\
									if((nixie_z[0][0]&pin6_on) && tim_ui.cnt10<ui_ld.n){tris6=tris_w;LED6=ledon;}\
									if((nixie_z[0][0]&pin7_on) && tim_ui.cnt10<ui_ld.n){tris7=tris_w;LED7=ledon;}\
									if((nixie_z[0][1]&pin0_on) && tim_ui.cnt10<ui_ld.n){tris8=tris_w;LED8=ledon;}\
									if((nixie_z[0][1]&pin1_on) && tim_ui.cnt10<ui_ld.n){tris9=tris_w;LED9=ledon;}\
								}\
								else if(tim_ui.cnt9==1)\
								{\
									tris1=tris_w;\
									if((nixie_z[1][0]&pin0_on) && tim_ui.cnt10<ui_ld.n) {tris0=tris_w;LED0=ledon;}\
									if((nixie_z[1][0]&pin2_on) && tim_ui.cnt10<ui_ld.n) {tris2=tris_w;LED2=ledon;}\
									if((nixie_z[1][0]&pin3_on) && tim_ui.cnt10<ui_ld.n) {tris3=tris_w;LED3=ledon;}\
									if((nixie_z[1][0]&pin4_on) && tim_ui.cnt10<ui_ld.n) {tris4=tris_w;LED4=ledon;}\
									if((nixie_z[1][0]&pin5_on) && tim_ui.cnt10<ui_ld.n) {tris5=tris_w;LED5=ledon;}\
									if((nixie_z[1][0]&pin6_on) && tim_ui.cnt10<ui_ld.n) {tris6=tris_w;LED6=ledon;}\
									if((nixie_z[1][0]&pin7_on) && tim_ui.cnt10<ui_ld.n) {tris7=tris_w;LED7=ledon;}\
									if((nixie_z[1][1]&pin0_on) && tim_ui.cnt10<ui_ld.n) {tris8=tris_w;LED8=ledon;}\
									if((nixie_z[1][1]&pin1_on) && tim_ui.cnt10<ui_ld.ts){tris9=tris_w;LED9=ledon;}\
								}\
								else\
								{\
									tris2=tris_w;\
									if((nixie_z[2][0]&pin0_on) && tim_ui.cnt10<ui_ld.w11){tris0=tris_w;LED0=ledon;}\
									if((nixie_z[2][0]&pin1_on) && tim_ui.cnt10<ui_ld.w10){tris1=tris_w;LED1=ledon;}\
									if((nixie_z[2][0]&pin3_on) && tim_ui.cnt10<ui_ld.w11){tris3=tris_w;LED3=ledon;}\
									if((nixie_z[2][0]&pin4_on) && tim_ui.cnt10<ui_ld.w10){tris4=tris_w;LED4=ledon;}\
									if((nixie_z[2][0]&pin5_on) && tim_ui.cnt10<ui_ld.w9 ){tris5=tris_w;LED5=ledon;}\
									if((nixie_z[2][0]&pin6_on) && tim_ui.cnt10<ui_ld.w11){tris6=tris_w;LED6=ledon;}\
									if((nixie_z[2][0]&pin7_on) && tim_ui.cnt10<ui_ld.w10){tris7=tris_w;LED7=ledon;}\
									if((nixie_z[2][1]&pin0_on) && tim_ui.cnt10<ui_ld.n  ){tris8=tris_w;LED8=ledon;}\
								}\
							}\
							else\
							{\
								if(tim_ui.cnt9==3)\
								{\
									tris3=tris_w;\
									if((nixie_z[3][0]&pin0_on) && tim_ui.cnt10<ui_ld.w10){tris0=tris_w;LED0=ledon;}\
									if((nixie_z[3][0]&pin1_on) && tim_ui.cnt10<ui_ld.w11){tris1=tris_w;LED1=ledon;}\
									if((nixie_z[3][0]&pin2_on) && tim_ui.cnt10<ui_ld.w11){tris2=tris_w;LED2=ledon;}\
									if((nixie_z[3][0]&pin4_on) && tim_ui.cnt10<ui_ld.w10){tris4=tris_w;LED4=ledon;}\
									if((nixie_z[3][0]&pin5_on) && tim_ui.cnt10<ui_ld.w9 ){tris5=tris_w;LED5=ledon;}\
									if((nixie_z[3][0]&pin6_on) && tim_ui.cnt10<ui_ld.w10){tris6=tris_w;LED6=ledon;}\
									if((nixie_z[3][0]&pin7_on) && tim_ui.cnt10<ui_ld.w11){tris7=tris_w;LED7=ledon;}\
								}\
								else\
								{\
									tris4=tris_w;\
									if((nixie_z[4][0]&pin0_on) && tim_ui.cnt10<ui_ld.w8){tris0=tris_w;LED0=ledon;}\
									if((nixie_z[4][0]&pin1_on) && tim_ui.cnt10<ui_ld.w7){tris1=tris_w;LED1=ledon;}\
									if((nixie_z[4][0]&pin2_on) && tim_ui.cnt10<ui_ld.w6){tris2=tris_w;LED2=ledon;}\
									if((nixie_z[4][0]&pin3_on) && tim_ui.cnt10<ui_ld.w5){tris3=tris_w;LED3=ledon;}\
									if((nixie_z[4][0]&pin5_on) && tim_ui.cnt10<ui_ld.w4){tris5=tris_w;LED5=ledon;}\
									if((nixie_z[4][0]&pin6_on) && tim_ui.cnt10<ui_ld.w3){tris6=tris_w;LED6=ledon;}\
									if((nixie_z[4][0]&pin7_on) && tim_ui.cnt10<ui_ld.w2){tris7=tris_w;LED7=ledon;}\
									if((nixie_z[4][1]&pin0_on) && tim_ui.cnt10<ui_ld.w1){tris8=tris_w;LED8=ledon;}\
									if((nixie_z[4][1]&pin1_on) && tim_ui.cnt10<ui_ld.w0){tris9=tris_w;LED9=ledon;}\
								}\
							}\
						}\
						else\
						{\
							if(tim_ui.cnt9<=6)\
							{\
								if(tim_ui.cnt9==5)\
								{\
									tris5=tris_w;\
									if((nixie_z[5][0]&pin0_on) && tim_ui.cnt10<ui_ld.w0){tris0=tris_w;LED0=ledon;}\
									if((nixie_z[5][0]&pin1_on) && tim_ui.cnt10<ui_ld.w1){tris1=tris_w;LED1=ledon;}\
									if((nixie_z[5][0]&pin2_on) && tim_ui.cnt10<ui_ld.w2){tris2=tris_w;LED2=ledon;}\
									if((nixie_z[5][0]&pin3_on) && tim_ui.cnt10<ui_ld.w3){tris3=tris_w;LED3=ledon;}\
									if((nixie_z[5][0]&pin4_on) && tim_ui.cnt10<ui_ld.w4){tris4=tris_w;LED4=ledon;}\
									if((nixie_z[5][0]&pin6_on) && tim_ui.cnt10<ui_ld.w5){tris6=tris_w;LED6=ledon;}\
									if((nixie_z[5][0]&pin7_on) && tim_ui.cnt10<ui_ld.w6){tris7=tris_w;LED7=ledon;}\
									if((nixie_z[5][1]&pin0_on) && tim_ui.cnt10<ui_ld.w7){tris8=tris_w;LED8=ledon;}\
									if((nixie_z[5][1]&pin1_on) && tim_ui.cnt10<ui_ld.w8){tris9=tris_w;LED9=ledon;}\
								}\
								else\
								{\
									tris6=tris_w;\
									if((nixie_z[6][0]&pin0_on) && tim_ui.cnt10<ui_ld.w8){tris0=tris_w;LED0=ledon;}\
									if((nixie_z[6][0]&pin1_on) && tim_ui.cnt10<ui_ld.w7){tris1=tris_w;LED1=ledon;}\
									if((nixie_z[6][0]&pin2_on) && tim_ui.cnt10<ui_ld.w6){tris2=tris_w;LED2=ledon;}\
									if((nixie_z[6][0]&pin3_on) && tim_ui.cnt10<ui_ld.w5){tris3=tris_w;LED3=ledon;}\
									if((nixie_z[6][0]&pin4_on) && tim_ui.cnt10<ui_ld.w4){tris4=tris_w;LED4=ledon;}\
									if((nixie_z[6][0]&pin5_on) && tim_ui.cnt10<ui_ld.w3){tris5=tris_w;LED5=ledon;}\
									if((nixie_z[6][0]&pin7_on) && tim_ui.cnt10<ui_ld.w2){tris7=tris_w;LED7=ledon;}\
									if((nixie_z[6][1]&pin0_on) && tim_ui.cnt10<ui_ld.w1){tris8=tris_w;LED8=ledon;}\
									if((nixie_z[6][1]&pin1_on) && tim_ui.cnt10<ui_ld.w0){tris9=tris_w;LED9=ledon;}\
								}\
							}\
							else\
							{\
								if(tim_ui.cnt9==7)\
								{\
									tris7=tris_w;\
									if((nixie_z[7][0]&pin0_on) && tim_ui.cnt10<ui_ld.w0){tris0=tris_w;LED0=ledon;}\
									if((nixie_z[7][0]&pin1_on) && tim_ui.cnt10<ui_ld.w1){tris1=tris_w;LED1=ledon;}\
									if((nixie_z[7][0]&pin2_on) && tim_ui.cnt10<ui_ld.w2){tris2=tris_w;LED2=ledon;}\
									if((nixie_z[7][0]&pin3_on) && tim_ui.cnt10<ui_ld.w3){tris3=tris_w;LED3=ledon;}\
									if((nixie_z[7][0]&pin4_on) && tim_ui.cnt10<ui_ld.w4){tris4=tris_w;LED4=ledon;}\
									if((nixie_z[7][0]&pin5_on) && tim_ui.cnt10<ui_ld.w5){tris5=tris_w;LED5=ledon;}\
									if((nixie_z[7][0]&pin6_on) && tim_ui.cnt10<ui_ld.w6){tris6=tris_w;LED6=ledon;}\
									if((nixie_z[7][1]&pin0_on) && tim_ui.cnt10<ui_ld.w7){tris8=tris_w;LED8=ledon;}\
									if((nixie_z[7][1]&pin1_on) && tim_ui.cnt10<ui_ld.w8){tris9=tris_w;LED9=ledon;}\
								}\
								else\
								{\
									tris8=tris_w;\
									if((nixie_z[8][0]&pin0_on) && tim_ui.cnt10<ui_ld.n ){tris0=tris_w;LED0=ledon;}\
									if((nixie_z[8][0]&pin1_on) && tim_ui.cnt10<ui_ld.n ){tris1=tris_w;LED1=ledon;}\
									if((nixie_z[8][0]&pin2_on) && tim_ui.cnt10<ui_ld.n ){tris2=tris_w;LED2=ledon;}\
									if((nixie_z[8][0]&pin3_on) && tim_ui.cnt10<ui_ld.n ){tris3=tris_w;LED3=ledon;}\
									if((nixie_z[8][0]&pin4_on) && tim_ui.cnt10<ui_ld.n ){tris4=tris_w;LED4=ledon;}\
									if((nixie_z[8][0]&pin5_on) && tim_ui.cnt10<ui_ld.w3){tris5=tris_w;LED5=ledon;}\
									if((nixie_z[8][0]&pin6_on) && tim_ui.cnt10<ui_ld.w4){tris6=tris_w;LED6=ledon;}\
									if((nixie_z[8][1]&pin7_on) && tim_ui.cnt10<ui_ld.w5){tris7=tris_w;LED7=ledon;}\
								}\
							}\
						}\
 */
