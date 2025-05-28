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

typedef union ui_buff_{		//共用体变量类型（8bit）
   //0
    struct {
		unsigned char buf;
    };
//1
    struct {
		unsigned	a		: 1;	//bit0 显示8
		unsigned	b		: 1;
		unsigned	c		: 1;
		unsigned	d		: 1;
		unsigned	e		: 1;
		unsigned	f		: 1;
		unsigned	g		: 1;
		unsigned	h		: 1;
    };

    struct {
		unsigned	j0      	: 1;	 //bit0 显示8
		unsigned	j1			: 1;
		unsigned	j2			: 1;
		unsigned	j3			: 1;
		unsigned	j4			: 1;
		unsigned	j5			: 1;
		unsigned	j6	  		: 1;
		unsigned	j7	  		: 1;
    };	

	struct {
		unsigned	j8      	: 1;	 //bit0 显示8
		unsigned	j9			: 1;
    };	

}ui_buff_;
typedef struct ui_
{
	u8 w		;//
	u8 u		;
	u8 q		;//
	u8 num1		;//
	u8 num2		;//
	u8 ou_d		;//
	u8 wa		;//
	u8 ts		;//
	u8 yd		;//
	u8 dian		;
	u8 cnt		;//
} ui_;


typedef struct ui__
{
	u8 w1	;
	u8 w2	;
	u8 cnt	;
	u8 n	;
	u8 ts	;
} ui__;

typedef struct tim_ui_
{
	u8 cnt		;
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

#define ui_smoend_id		17
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
// //50ms 73
// void ui_smoend_dl_getup(task* task_);
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

//50ms 73
void ui_dl_getup(task* task_);
//50ms 73
void ui_smoend(task* task_);




#define led_(x,y,z)	 	if(ui_buff[x].y ){LED##z=ledon;tris##z=tris_w;}
#define ledz_(x)		LED##x=ledzon;tris##x=tris_w

#define ui_delay	10
#define ui_ldmax	10
#define uidelay	
extern ui__ ui_ld;
extern volatile tim_ui_ tim_ui;
extern volatile u8 nixie_z[9][2];
extern volatile ui_ ui;
extern s8 ui_id;
extern volatile union ui_buff_ ui_buff[12];
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

#define ui_loop() 		switch (tim_ui.cnt)\
						{\
						case 0:\
							if(ui_ld.n>0){\
								ledpwm_(ui_ld.n,0);\
								ledz_(0);\
								led_(0 ,a ,1);\
								led_(0 ,b ,2);\
								led_(0 ,c ,3);\
								led_(0 ,d ,4);\
								led_(0 ,e ,5);\
								led_(0 ,f ,6);\
								led_(0 ,g ,7);\
								led_(0 ,h ,8);\
								led_(10,j0,9);}\
							break;\
						case 1:\
							if(ui_ld.n>0){\
								ledpwm_(ui_ld.n,1);\
								ledz_(1);\
								led_(1 ,a ,0);\
								led_(1 ,b ,2);\
								led_(1 ,c ,3);\
								led_(1 ,d ,4);\
								led_(1 ,e ,5);\
								led_(1 ,f ,6);\
								led_(1 ,g ,7);\
								led_(1 ,h ,8);\}\
							break;\
						case 2:\
							if(ui_ld.ts>0){\
								ledpwm_(ui_ld.ts,1);\
								ledz_(1);\
								led_(10,j1,9);}\
							break;\
						case 3:\
							if(ui_ld.w1>0){\
								ledpwm_(ui_ld.w1,2);\
								ledz_(2);\
								led_(2 ,a ,0);\
								led_(2 ,b ,1);\
								led_(2 ,c ,3);\
								led_(2 ,d ,4);\
								led_(2 ,e ,5);\
								led_(2 ,f ,6);\
								led_(2 ,g ,7);\
								led_(2 ,h ,8);\
								led_(10,j2,9);}\
							break;\
						case 4:\
							if(ui_ld.w1>0){\
								ledpwm_(ui_ld.w1,3);\
								ledz_(3);\
								led_(3 ,a ,0);\
								led_(3 ,b ,1);\
								led_(3 ,c ,2);\
								led_(3 ,d ,4);\
								led_(3 ,e ,5);}\
							break;\
						case 5:\
							if(ui_ld.w2>0){\
								ledpwm_(ui_ld.w2,3);\
								ledz_(3);\
								led_(3 ,g ,7);\
								led_(3 ,h ,8);\
								led_(10,j3,9);}\
							break;\
						case 6:\
							if(ui_ld.n>0){\
								ledpwm_(ui_ld.n,3);\
								ledz_(3);\
								led_(3 ,f ,6);}\
							break;\
						case 7:\
							if(ui_ld.w2>0){\
								ledpwm_(ui_ld.w2,4);\
								ledz_(4);\
								led_(4 ,a ,0);\
								led_(4 ,b ,1);\
								led_(4 ,c ,2);\
								led_(4 ,d ,3);\
								led_(4 ,e ,5);\
								led_(4 ,f ,6);\
								led_(4 ,g ,7);\
								led_(4 ,h ,8);\
								led_(10,j4,9);}\
							break;\
						case 8:\
							if(ui_ld.w2>0){\
								ledpwm_(ui_ld.w2,5);\
								ledz_(5);\
								led_(5 ,a ,0);\
								led_(5 ,b ,1);\
								led_(5 ,c ,2);\
								led_(5 ,d ,3);\
								led_(5 ,e ,4);\
								led_(5 ,f ,6);\
								led_(5 ,g ,7);\
								led_(5 ,h ,8);}\
							break;\
						case 9:\
							if(ui_ld.cnt>0){\
								ledpwm_(ui_ld.cnt,5);\
								ledz_(5);\
								led_(10,j5,9);}\
							break;\
						case 10:\
							if(ui_ld.cnt>0){\
								ledpwm_(ui_ld.cnt,6);\
								ledz_(6);\
								led_(6 ,a ,0);\
								led_(6 ,b ,1);\
								led_(6 ,c ,2);\
								led_(6 ,d ,3);}\
							break;\
						case 11:\
							if(ui_ld.n>0){\
								ledpwm_(ui_ld.n,6);\
								ledz_(6);\
								led_(6 ,e ,4);\
								led_(6 ,f ,5);\
								led_(6 ,g ,7);\
								led_(6 ,h ,8);}\
							break;\
						case 12:\
							if(ui_ld.w1>0){\
								ledpwm_(ui_ld.w1,6);\
								ledz_(6);\
								led_(10,j6,9);}\
							break;\
						case 13:\
							if(ui_ld.w2>0){\
								ledpwm_(ui_ld.w2,7);\
								ledz_(7);\
								led_(7 ,a ,0);\
								led_(7 ,b ,1);\
								led_(7 ,c ,2);\
								led_(7 ,d ,3);\
								led_(7 ,e ,4);\
								led_(7 ,f ,5);\
								led_(7 ,g ,6);\
								led_(7 ,h ,8);\
								led_(10,j7,9);}\
							break;\
						case 14:\
							if(ui_ld.w2>0){\
								ledpwm_(ui_ld.w2,8);\
								ledz_(8);\
								led_(8 ,a ,0);\
								led_(8 ,b ,1);\
								led_(8 ,c ,2);\
								led_(8 ,d ,3);\
								led_(8 ,e ,4);\
								led_(8 ,f ,5);\
								led_(8 ,g ,6);\
								led_(8 ,h ,7);\
								led_(11,j8,9);}\
							break;\
						case 15:\
							if(ui_ld.w1>0){\
								ledpwm_(ui_ld.w1,9);\
								ledz_(9);\
								led_(9 ,a ,0);\
								led_(9 ,b ,1);\
								led_(9 ,c ,2);\
								led_(9 ,d ,3);\
								led_(9 ,e ,4);\
								led_(9 ,f ,5);\
								led_(9 ,g ,6);\
								led_(9 ,h ,7);\
								led_(11,j9,8);}\
							break;\
						\
						default:\
							break;\
						}\
						tim_ui.cnt++;\
						if(tim_ui.cnt>=16)\
						{\
							tim_ui.cnt=0;\
						}


#endif


/* 
						if(tim_ui.cnt<=4)\
						{\
							if(tim_ui.cnt<=2)\
							{\
								if(tim_ui.cnt==0)\
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
								else if(tim_ui.cnt==1)\
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
								if(tim_ui.cnt==3)\
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
							if(tim_ui.cnt<=6)\
							{\
								if(tim_ui.cnt==5)\
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
								if(tim_ui.cnt==7)\
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
