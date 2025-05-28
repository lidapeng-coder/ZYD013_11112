/*******************************************************************************
* Device      : PS1101
* Author      : XAD Application Team
* Version     : V0.0.1
* Date        : 20220830
* Description : PA/PB/PC设置为输入状态关下拉开上拉,分别给每个IO接地,通过万用表查看对应IO的电流，根据公式R=U/I算出上拉电阻阻值
* Note		  :
********************************************************************************/

/*********************************************************************************************
*常用配置字功能说明:
*
*_FINTOSC_DIV1_1L  :  内部 RC 振荡器频率选择
*_FCPU_4T_1L       :  选择指令周期为4T模式
*_SMT_SMV_1L       :  电平选择位
*_LVREN_OFF_1L     :  LVR 使能选择           
*_LVR24V_1L        :  LVR 电压选择2.4V    
*
*_DBGEN_I2C_OFF_2L :  I2C 调试模式使能选择               
*_DBGEN_UART_00_2L :  UART 调试模式使能选择              
*_RESETE_OFF_2L    :  外部复位使能选择           
*_WDTE_OFF_2L      :  WDT 使能选择         
*_TWDT_111_2L      :  看门狗溢出时间及上电复位时间选择         
*
*注意：1.配置字若无特别需求请勿修改；
*      2.其他配置字及相应功能见Datasheet及头文件；
*
************************************************************************************************/

#include "public.h"
#if cpu_t2
__CONFIG(1,_FINTOSC_DIV1_1L     & _FCPU_2T_1L         & _SMT_SMV_1L     & _LVREN_ON_1L    & _LVR24V_1L  );
#else
__CONFIG(1,_FINTOSC_DIV1_1L     & _FCPU_4T_1L         & _SMT_SMV_1L     & _LVREN_ON_1L    & _LVR20V_1L  );
#endif
__CONFIG(2,_DBGEN_I2C_OFF_2L     & _DBGEN_UART_01_2L    & _RESETE_OFF_2L  & _WDTE_OFF_2L     & _TWDT_111_2L   );


//u8 dlll=1;
u8 pwm_flag=0;
u8 adc_flag=0;
u8 adc_cnt=0;
u8 adc_begin=0;
u8 cfg_flag=1;

#include <stdint.h>

// typedef struct {
//     uint32_t quotient;  // 商
//     uint32_t remainder; // 余数
// } DivResult;

// DivResult div32u(uint32_t dividend, uint32_t divisor) {
//     DivResult result = {0, 0};
//     if (divisor == 0) return result; // 处理除数为0的情况

//     for (int8_t i = 31; i >= 0; i--) { // 32次循环处理每位
//         result.remainder <<= 1;        // 余数左移1位
//         result.remainder |= (dividend >> i) & 1; // 取被除数当前最高位
        
//         if (result.remainder >= divisor) {       // 余数 >= 除数
//             result.remainder -= divisor;         // 余数减去除数
//             result.quotient |= (1UL << i);       // 设置商对应位为1
//         }
//     }
//     return result;
// }

u8 pwm_cnt=0;
u16 pwm_bat=300;
void main(void)
{  
  	gpio_init();
  	timer0_init();
	//__delay_us(30);
  	timer1_init();
  	cmp0_init();
	timer2_init();
  	task_init();
	//uart_init();
	#if	bug
	uart_init();
	#endif
	
	cb_init();
	// pwm.duty=50;
	// pwm_init();
/*
	ui.w1	    =0;
	ui.w2	    =0;
		
	ui.ou_d	    =0;
	ui.wa	    =0;
	ui.ts	    =1;
	ui.yd	    =1;	
	ui.dian_s   =0;

	ui_ld.n		=10		;
	ui_ld.ts 	=10		;
	ui_ld.w0	=10		;
	ui_ld.w1	=10		;
	ui_ld.w2	=10		;
	ui_ld.w3	=10		;
	ui_ld.w4	=10		;
	ui_ld.w5	=10		;
	ui_ld.w6	=10		;
	ui_ld.w7	=10		;
	ui_ld.w8	=10		;
	ui_ld.w9	=10		;
	ui_ld.w10	=10		;
	ui_ld.w11	=10		;

	ui.num1	    =10;
	ui.num2	    =10;
	ui.dian		=5;


	new_nixie();
	*/
	//if(ui.yd){nixie_z[1][1]|=mask0on;}else{nixie_z[1][1]&=mask0off;}
	// if(ui.yd)
	// {
	// 	ui.dian_s   =1;
	// 	new_nixie();
	// }
	// else
	// {
	// 	ui.num1=8;
	// 	new_nixie();
	// }
	//nixie_z[1][1]|=0x01;
	//SMO_PWM=0;

/* 	nixie_z[0][0]=0xFF;
	nixie_z[1][0]=0xff;
	nixie_z[2][0]=0xff;
	nixie_z[3][0]=0xff;
	nixie_z[4][0]=0xff;
	nixie_z[5][0]=0xff;
	nixie_z[6][0]=0xff;
	nixie_z[7][0]=0xff;
	nixie_z[8][0]=0xff;

	nixie_z[0][1]=0xff;
	nixie_z[1][1]=0xff;
	nixie_z[2][1]=0xff;
	nixie_z[3][1]=0xff;
	nixie_z[4][1]=0xff;
	nixie_z[5][1]=0xff;
	nixie_z[6][1]=0xff;
	nixie_z[7][1]=0xff;
	nixie_z[8][1]=0xff;

	// ui_ld.n=1;
	// ui_ld.w=1;
	// ui_ld.ts=1;

	ldz(5); */
	ui_id=6;
	add_task_id(si_mic_id,si_mic_ms,si_mic_max,0);
	//bat_task(&task_list[(u8)add_task_id(bat_task_id,bat_task_ms,bat_task_max,1)]);
	add_task_id(bat_task_id,bat_task_ms,bat_task_max,1);
	u16 b_=get_bat();
	//uart_txnum(b,4);
	if((bat.bat>b_)||((bat.bat+50)<=b_))
	{
		bat.bat=b_;
	}
	if( bat.bat<=317)
	{
		bat.dian=0;
		#if chrg_g
		chrg_num=0;
		#endif
		//uart_txln("lowbat");
	}
	else if ( bat.bat<=345)
	{
		bat.dian=1;
		#if chrg_g
		chrg_num=15;
		#endif
	}
	else if ( bat.bat<=370)
	{
		bat.dian=2;
		#if chrg_g
		chrg_num=40;
		#endif
	}
	else if ( bat.bat<=390)
	{
		bat.dian=3;
		#if chrg_g
		chrg_num=65;
		#endif
	}
	else 
	{
		bat.dian=4;
		#if chrg_g
		chrg_num=85;
		#endif
	}
	// u16 bat__[5]={0};
	// bat__[0]=get_bat();
	// bat__[1]=get_bat();
	// bat__[2]=get_bat();
	// bat__[3]=get_bat();
	// bat__[4]=get_bat();
	//uart_txnum(b,4);
	//if((((bat__[1]+bat__[2]+bat__[3]+bat__[4])>>2)<=320)&&(SI_MIC))
	if((get_bat()<=330)&&SI_MIC)
	{
		bat.bat=315;
		bat.dian=0;
		pwm.duty=0;
		lowbat_init=0;
	}
	#if	bug
	uart_txln("init");
	#endif
	add_task_id(key_task_id,key_task_ms,key_task_max,2);
	add_task_id(chrg_task_id,chrg_task_ms,chrg_task_max,3);
	add_task_id(cb_task_id,cb_task_ms,cb_task_max,4);
	add_task_id(sleep_task_id,sleep_task_ms,sleep_task_max,5);
	// // pwm.duty=40;
	// // pwm_init();
	add_task_id(ui_begin_id,ui_begin_ms,ui_begin_max,ui_id);
	//add_task_id(ui_smoing_id,ui_smoing_ms,ui_smoing_max,ui_id);
	//bat.bat=get_bat();
	pwm.load_t=300;
	yd=SMO_DET;

/* 	LED0=1;
	LED1=1;
	LED2=1;
	LED3=1;
	LED4=1;
	LED5=1;
	LED6=1;
	LED7=1;
	LED8=1;
	LED9=0;

	tris0=0;	
	tris1=0;
	tris2=0;
	tris3=0;
	tris4=0;
	tris5=0;
	tris6=0;
	tris7=0;
	tris8=0;
	tris9=0; 

	ui_buff[10].j1=1;
	ui_buff[10].j5=1;
	ui_buff[5].g=1;
*/
//ui_buff[10].j3=1;
//ui_buff[3].h=1;
//ui_buff[3].g=1;
	// ui_buff[0].buf=0xff;
	// ui_buff[10].j0=1;
	while(1)
  	{
     	task_loop();
		if(pwm_flag)
		{
			pwm_flag=0;
			pwm_task();
		}
		if(tim_ui.ok)
		{
			ledz_off();	
			if(adc_begin)
			{


				adc_begin=0;

				#if cpu_t2
				ADCON1=0x60;
				#else
				ADCON1=0x60;
				#endif
				ADCON0=0x39;\
				ADIF=0;\
				ADIE=0;\
				GO=1;\
				while(GO==1);
				ADIF=0;
				pwm.bat_t=((ADRESH&0x0f)<<8)|ADRESL;

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
				pwm.load_t=((ADRESH&0x0f)<<8)|ADRESL;
				pwm.adc_ok=1;
				if( pwm.load_t>=4094)
				{ 
					si_mic_flag.kl=1;
					pwm.duty=0;
					cmpoff_pwm();
					//uart_txln("kl_bat");
				}
				//uart_txln("1");
			}
			#if bug_a1
			PA1=~PA1;
			#endif
			
			ui_loop();
			
			tim_ui.ok=0;
		}
		if(pwm.adc_ok)
		{
				pwm_cnt++;
				if(pwm_cnt==2)
				{
					if(pwm.load_t>2500)
					{
						pwm_bat=120*(u32)pwm.load_t/pwm.bat_t;
						//pwm.load_t=div32u(120*(u32)pwm.load_t,pwm.bat_t).quotient;
						pwm_bat-=13;
					}
					else{
						pwm_bat=310;
					}
					if(pwm_bat<=200&&pwm_bat>=180)
					{
						bat.bat=310;
						bat.dian=0;
						pwm.duty=0;
						lowbat_init=0;
						//cmpoff_pwm();
						#if bug
						//uart_txln("low__");
						#endif
						//uart_txnum(pwm_bat,4);
					}
				}
				if(pwm_cnt>=5)
				{

					pw_t=300000ul*pw/((u32)pwm_bat*pwm_bat);
					cfg_flag=1;
					pwm_cnt=0;
					pwm.adc_ok=0;

				}
				//uart_txnum(pwm.load_t,5);
				//uart_txnum(pw_t,5);
				//tim_ui.ok=0;
				pwm.adc_ok=0;
				#if bug
				//uart_txnum(pwm.load_t ,5);
				#endif
				//uart_txln("")
			
			//uart_txnum(pwm.bat_t,4);
		}
		// uart_txnum(5,2);
		// uart_txln("666");
		// uart_txc('6');
		
		// SMO_PWM=0;
  	}

}
//高优先级中断服务函数

void interrupt ISR_h (void)
{
//进入中断后系统自动关闭中断
	if(cmpif_pwm)
	{
		
		#if 1
		if(cmpout_pwm&&cmpie_pwm)
		{
			#if od
			PA0OD=0;
			#endif
			SMO_PWM=1;
			si_mic_flag.dl=1;
			pwm.duty=0;
			//si_mic_flag.dl=1;
			#if od
			PA0OD=1;
			#endif
			#if 0
			uart_txln("dl 0");
			#endif
			// __delay_us(pwm_dl_chek);
			// if(SMO_DET)
			// {
			// 	si_mic_flag.kl=1;
			// }
			// else
			// {
			// }
		}
		#else
		//if(dlll)
		//{		
		if(cmpie_pwm)
		{
			#if od
			PA0OD=0;
			#endif
			SMO_PWM=1;
			pwm.duty=0;
			si_mic_flag.dl=1;
			#if od
			PA0OD=1;
			#endif
			// adc_begin=0;
			// adc_cnt=0;
			// adc_flag=0;
			// pwm.adc_ok=0;
			// pwm_bat=310;
			// __delay_us(pwm_dl_chek);
			// if(SMO_DET)
			// {
			// 	si_mic_flag.kl=1;
			// }
			// else
			// {
			// 	si_mic_flag.dl=1;
			// }
		}
		//}
		//dlll=1;
		#if bug
		//uart_txln("dl 0");
		#endif
		
		#endif
		
		cmpif_pwm=0;
	}

	if(TMR1IE && TMR1IF)//8ms 一直开
	{
		TMR1IF=0;
		task_isr();
		pwm_flag=1;
		//return;
	}
	if(TMR0IE && TMR0IF)
	{
		TMR0IF=0;
		ui_tim_isr();
		if(adc_flag==1)
		{
			adc_cnt++;
			if(adc_cnt>=5)
			{
				adc_begin=1;
				adc_cnt=0;
				adc_flag=0;
			}
		}
		// ui_loop();
		
	}
	if(timif_pwm  && timie_pwm)  //pwm专用 自动关
	{
		//tim_isr_pwm();
		//IOCUR=0x00;
		timif_pwm=0;
		cmpoff_pwm();
		SMO_PWM=1;
		timoff_pwm();
	}

	if(timie_cnt && timif_cnt)// 16ms  自动关
	{
		tim_cnt_isr();
		timif_cnt=0;
		tim_cnt.cnt++;
		if(tim_cnt.timercnt==tim_cnt.cnt)
		{
			tim_flag.timflag=1;
			timoff_cnt(); 
		}
	}
	
	// 	pwm.adc_ok=1;
	// 	if(pwm.load_flag==0)
	// 	{
	// 		pwm.bat_t=((ADRESH&0x0f)<<8)|ADRESL;
	// 		if(SI_MIC&&(si_mic_flag.dl==0))
	// 		{
	// 			ADCON1=0x60;\
	// 			ADCON0=0x15;
	// 			ADIF=0;\
	// 			ADIE=1;\
	// 			GO=1;\
	// 			pwm.load_flag=1;
	// 		}
	// 	}
	//}
	if(PAIF ||PCIF || PBIF)
	{
		PAIF=0;
		PCIF=0;
		PBIF=0;

		PA4MSK=0;
		PA5MSK=0;
		PB1MSK=0;
		PC6MSK=0;
		PAIE=0;
		PBIE=0;
		PCIE=0;
	}
}

//低优先级中断服务函数

void interrupt low_priority ISR_l (void)
{

	if(TMR2IF||ADIF)
	{
		TMR2IF=0;
		ADIF=0;
	}
}

