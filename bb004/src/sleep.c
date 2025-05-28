#include "public.h"                  // Device header

// u8 sleep_flag=0;
// u8 sleep_cnt=0;
void sleep_mode(void)
{

	PORTA = 0X00;//输入输出数据初始化为0
	PORTB = 0X08;
	PORTC = 0X01;
	PORTD = 0X01;
	SMTA = 0xEF; 

    // TRISA = 0X10;//IO初始化为输出模式  0:输出  1：输入
    // TRISB = 0X03;
    // TRISC = 0X08;
    // TRISD = 0X04;

    PAPU = 0XfF;//关闭上拉电阻   0：使能  1：关闭
    PBPU = 0XFf;
    PCPU = 0XFf;
    PDPU = 0XFb;

    PAPD = 0XdF;//关闭下拉电阻   0：使能  1：关闭
    PBPD = 0XFF;
    PCPD = 0XF7;
    PDPD = 0XFF;

    PAOD = 0X00;//关闭开漏模式   0：关闭  1：使能
    PBOD = 0X00;
    PCOD = 0X00;
    PDOD = 0X00;

    ANASEL0 = 0X00;//关闭模拟通道   0：关闭  1：打开 
    ANASEL1 = 0X00;
    ANASEL2 = 0X00;
    ANASEL3 = 0X00;

	TMR1ON=0;
	T1CLKEN=0;

    SPEN=0;
	UARTCLKEN=0;

	FVREN=0;
	DAC0EN=0;
	DAC1EN=0;
	CMP0EN=0;
	CMP1EN=0;

	ADON=0;
	ADCCLKEN=0;
	
	// if(sleep_cnt<48)
	// {
		

		TRISA = 0X10;//IO初始化为输出模式  0:输出  1：输入
    	TRISB = 0X03;
    	TRISC = 0X08;
    	TRISD = 0X04;

		PA4MSK=1;
		PB0MSK=1;
		PB1MSK=1;
		PC3MSK=1;
		PD2MSK=1;

		PAIF=0;
		PBIF=0;
		PCIF=0;
		PDIF=0;

		PINA4;
		PINB0;
		PINB1;
		PINC3;
		PIND2;

		PAIE=1;
		PBIE=1;
		PCIE=1;
		PDIE=1;

		// T1CLKEN=1;
		// TMR1H=0x15;
		// TMR2L=0xa0;
		// T1CON0=0xb2;

		// TMR1IF=0;
		// TMR1IE=1;
		// TMR1ON=1;
	// }
	// else
	// {
	// 	sleep_cnt=0;

	// 	TRISA = 0X00;//IO初始化为输出模式  0:输出  1：输入
    // 	TRISB = 0X00;
    // 	TRISC = 0X00;
    // 	TRISD = 0X04;

	// 	PD2MSK=1;
	// 	PDIF=0;
	// 	PIND2;
	// 	PDIE=1;
	// }

	GIE=1;

	SLEEP_PWOFF();

	//int_close();

}

char sleep_task_id;
//250ms 0
void sleep_task(task* task_)
{
	// #if dug
	// uart_txnum(sleep_cnt,2);
	// #endif


	// if(sleep_flag==0)
	// {
		if(task_list[aip33626_task_id].active==0&&task_1_7_flag==0)
		{
			task_->sucCnt++;
			if(task_->sucCnt>=20)
			{
				task_->sucCnt=0;
				#if dug
				uart_txln("sleep");
				#endif
				

				sleep_mode();
				
				GPIO_Init();//IO口初始化
				fvr_init();
				dac_init();
				cmp_init();
				timer1_init();
				aip33626_init();
				#if dug
				uart_init();
				#endif
				
			}
		}
		else
		{
			task_->sucCnt=0;
		}
	// }
}
