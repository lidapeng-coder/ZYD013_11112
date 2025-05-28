#include"public.h"
u8 zz=30;
u8 zz_begin=0;
u8 zz_[6]={0};
u8 zz_p=0;
u8 get_load(void)
{
	u32 temp=0;
	SMO_DET_EN=0;
	__delay_us(10);
	#if cpu_t2
    ADCON1=0x60;
    #else
    ADCON1=0x60;
    #endif
	ADCON0=0x15;
	ADIF=0;
	ADIE=0;
	GO=1;
	while(GO==1);
	ADIF=0;
	temp=((ADRESH&0x0f)<<8)|ADRESL;
	SMO_DET_EN=1;
	temp=510ul*temp/(4095ul-temp);
	//uart_txnum(temp,5);
	return temp;
}

u8 cb_o=0;

#define cb_task_id 		11
#define cb_task_ms		70
#define cb_task_max		0
extern u8 cb_o;
#define cb_init()	cb_o=SMO_DET
u8 yd=0;
//70ms 0
void cb_task(task* task_)
{
	if(SMO_PWM&&(SI_MIC==0))
	{
		if(cb_o!=SMO_DET)
		{
			zz_begin=1;
			zz_p=0;
			#if bug
			uart_txln("cb");
			#endif
		}
		cb_o=SMO_DET;
	}
	if(zz_begin)
	{
		zz_[zz_p]=get_load();
		yd=(zz_[zz_p]==0)?1:0;
		zz_p++;
		if(zz_p>=6)
		{
			u16 zz_t=zz_[2]+zz_[3]+zz_[4]+zz_[5];
			zz=zz_t>>2;
			zz_begin=0;
			add_task_id(ui_cb_id,ui_cb_ms,ui_cb_max,ui_id);
		}
	}
		
}
