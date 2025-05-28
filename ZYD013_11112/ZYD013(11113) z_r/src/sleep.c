#include"public.h"


//200  0
void sleep_task(task* task_)
{
    if(task_list[ui_id].active==0)
    {
        task_->sucCnt++;
        if(task_->sucCnt>=25)
        {
            task_->sucCnt=0;
            sleep_mode();

            NOP();
            gpio_init();
            timer0_init();
            __delay_us(30);
            timer1_init();
            timer2_init();
            cmp0_init();
            #if bug
            uart_init();
            #endif
            //uart_init();
            __delay_ms(50);
            
        }
    }
    else
    {
        task_->sucCnt=0;
    }
}
void sleep_mode(void)
{
    PME=0;
	PORTA = 0X01;//输入输出数据初始化为0
	PORTB = 0X01;
	PORTC = 0X00;

    // TRISA = 0X10;//IO初始化为输出模式  0:输出  1：输入
    // TRISB = 0X03;
    // TRISC = 0X08;
    // TRISD = 0X04;

    PAPU = 0XfF;//关闭上拉电阻   0：使能  1：关闭
    PBPU = 0XFf;
    PCPU = 0Xbf;

    PAPD = 0XeF;//关闭下拉电阻   0：使能  1：关闭

    PAOD = 0X00;//关闭开漏模式   0：关闭  1：使能

	TMR1ON=0;
    TMR2ON=0;

	FVREN=0;
	DACEN=0;
	CMP0EN=0;
	CMP1EN=0;

	ADON=0;
	
	// if(sleep_cnt<48)
	// {
		

		TRISA = 0X30;//IO初始化为输出模式  0:输出  1：输入
    	TRISB = 0X02;
    	TRISC = 0X40;

		PA4MSK=1;
		PA5MSK=1;
        PB1MSK=1;
		PC6MSK=1;

		PAIF=0;
        PBIF=0;
		PCIF=0;

		PINA4;
		PINA5;
        PINB1;
		PINC6;

		PAIE=1;
        PBIE=1;
		PCIE=1;
        PEIE=1;
	    GIE=1;

	SLEEP_PWOFF();

	//int_close();

}
