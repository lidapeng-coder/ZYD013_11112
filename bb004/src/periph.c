/*******************************************************************************
* Device      : AD18F128
* Author      : XAD Application Team
* Version     : V0.0.1
* Date        : 20221107
********************************************************************************/

/********************************INCLUDES*************************************/
#include"AD18F128.h"
#include "Periph.h"
#include "DataType.h"
#include "stdio.h"

/***********************************************************
//---Funtion ： GPIO_Init
//---Parameters: None
//---return : None
//---Note:所有IO初始化
************************************************************/

#if 0

#define PWM1        PD0
#define PWM2        PB3
#define SMO_DET1    PINB0
#define SMO_DET2    PINB1 

#define SI_MIC      PINC3

#define LCD_EN      PC0
#define LCD_SCL     PC1
#define LCD_SDA     PC2

#define CHRG_EN     PA5

#define USB_DET     PINA4

#define key         PIND2

#endif
void GPIO_Init()
{

	OSCCON=0x70;
    CLKCFG1=0x0f;	

    PORTA = 0X00;//输入输出数据初始化为0
    PORTB = 0X08;
    PORTC = 0X07;
    PORTD = 0X01;
    SMTA = 0xEF; 

    TRISA = 0X30;//IO初始化为输出模式  0:输出  1：输入
    TRISB = 0X03;
    TRISC = 0X08;
    TRISD = 0X04;


    PAPD = 0XFF;//关闭下拉电阻   0：使能  1：关闭
    PBPD = 0XFF;
    PCPD = 0XF7;
    PDPD = 0XFF;

    PAPU = 0XdF;//关闭上拉电阻   0：使能  1：关闭
    PBPU = 0XFC;
    PCPU = 0XFF;
    PDPU = 0XFb;

    PAOD = 0X00;//关闭开漏模式   0：关闭  1：使能
    PBOD = 0X00;
    PCOD = 0X06;
    PDOD = 0X00;

    ANASEL0 = 0X00;//关闭模拟通道   0：关闭  1：打开 
    ANASEL1 = 0X03;
    ANASEL2 = 0X00;
    ANASEL3 = 0X00;


}

void timer1_init(void)//8ms
{
    T1CLKEN = 1;        //TIMER0时钟使能

    T1CLKEN = 1;   //timer1
    TMR1H=0xe0;
    TMR1L=0xc0;

	T1CON0=0x30;

    TMR1IF=0;
    TMR1IE=1;

    GIE=1;
    TMR1ON=1;



}



// void Timer2_Init(void)
// {
//     T2CLKEN = 1;

//     PR2H     = 0x03;
//     PR2L     = 0xE7;//设置定时初值，16000000/16/1000=1ms
//     TMR2H    = 0x00;
//     TMR2L    = 0x00;//
//     T2CON    = 0x07;//Timer2分频为1:16,启动Timer2
// }
/*
u16 cnt2=0,timer2cnt=0;
u8 tim2flag=0;

char timer2_cnt(uint16_t ms,uint8_t lab)//  16ms  
{
	static uint8_t init_flag=1;
	static uint8_t ls_lab=0;
	if(ls_lab!=lab)
	{
		init_flag=1;
	}
		
	if(init_flag)
	{
		cnt2=0;
		timer2cnt=ms>>4;
        T2CLKEN=1;

		TMR2H=0x00;
		TMR2L=0x00;
		
        PR2H=3;
        PR2L=0xe7;

        T2CON=0x7b;

		TMR2IF=0;
		TMR2IE=1;
		GIE=1;
		TMR2ON=1;
		init_flag=0;
		return -1;
	}
	
	if(tim2flag)
	{
		tim2flag=0;
		init_flag=1;
		return 1;
	}
	
	return 0;
	
}
*/
u16 cnt0=0,timer0cnt=0;
u8 tim0flag=0;
char timer0_cnt(uint16_t ms,uint8_t lab)//  8ms  
{
	static uint8_t init_flag=1;
	static uint8_t ls_lab=0;
	if(ls_lab!=lab)
	{
		init_flag=1;
        ls_lab=lab;
	}
		
	if(init_flag)
	{
        tim0flag=0;
		cnt0=0;
		timer0cnt=ms>>3;
        T0CLKEN=1;

		TMR0=0;
		
        PR0 = 250-1;

        T0CON=0x07;

		TMR0IF=0;
		TMR0IE=1;
		GIE=1;

		init_flag=0;
		return -1;
	}
	
	if(tim0flag)
	{
		tim0flag=0;
		init_flag=1;
		return 1;
	}
	
	return 0;
	
}



// void adc_demo

/***************************************************************************************
Funtion :   FVR_Offset
Inoput  :   unsigned char OFFSET
Output  :   None
Note    :
****************************************************************************************/
void FVR_Offset(unsigned char OFFSET)
{
	unsigned char tmp=0;
	tmp=FVRCON1&0XF0;
	FVRCON1= tmp|OFFSET;
}

/***************************************************************************************
Funtion :   FVR_CAL
Inoput  :   None
Output  :   None
Note    :   校准函数
****************************************************************************************/
//每次校准只需选择同相端
void FVR_CAL()
{
	unsigned char VOOS1 = 0,start = 0;
	unsigned char i = 0;

	FVR_OFFSET_EN=1;	            //使能校准

	FVR_Offset(0);
	__delay_us(500);
	start =FVR_A2D_OUT;

	if(start == 1)	                //减
	{
		FVRCON1 &= 0XEF;	        //校准负值
	}
	else	                        //加
	{
		FVRCON1 |= 0X10;	        //校准正值
	}

	FVR_Offset(0);
	__delay_us(500);
	start =FVR_A2D_OUT;

	for(i=0;i<=15;i++)              //从0到15找翻转点
	{
		FVR_Offset(i);
		__delay_us(500);
		if(FVR_A2D_OUT != start)
		{
			VOOS1 = i;
			break;
		}
	}
	// printf("VOOS1_1 = 0x%02x,\r\n",VOOS1);
	FVR_Offset(15);         //切换状态值并记录OP0OUT初始状态值
	__delay_us(500);
	start = FVR_A2D_OUT;
	for(i=16;i>0;i--)       //从7到0找翻转点
	{
		FVR_Offset(i-1);
		__delay_us(500);
		if(FVR_A2D_OUT != start)
		{
			VOOS1 =(VOOS1+ i-1)/2;
			break;
		}
	}
	// printf("VOOS1_2 = 0x%02x,\r\n",i-1);
	// printf("VOOS1 = 0x%02x,\r\n",VOOS1);

	FVR_Offset(VOOS1);          //填入校准值
	FVR_OFFSET_EN=0;		    //关闭校准
}
/***************************************************************************************
Funtion :   FVR_init
Inoput  :   None
Output  :   None
Note    :   FVROUT -> PC4   Vfvr -> 1V
****************************************************************************************/

void fvr_init(void)//1v
{
    // TRISC4=0;
    // PC4AEN=1;
    FVRCON = 0xa0;                      ///使能FVR  ; FVR 通过PC4输出
    FVRPGA = 0;
    FVRPGA1 = 0;                        //FVR放大倍数选择
    FVR_CAL();                          //校准FVR
	__delay_us(100);
    FVREN=1;
    __delay_us(100);

}

u16 adc_bat(void)
{
    u16 t;
    u32 t_=409500ul;
    ADCCLKEN = 1;
    ADCON0 = 0X3D;      //右对齐，通道零（FVROUT），使能ADC
    ADCON1 = 0XDC;      //参考电压VDD，高速，8TAD,FOSC/4   11011100
    ADCON3 = 0x00;      //
    ADCON4 = 0x00;      //
	ADIF=0;
	ADIE=0;
    __delay_us(10);
    GO=1;
    while(GO==1);
    ADIF=0;
    t=((ADRESH&0x0f)<<8)|ADRESL;
    // uart_txnum(t,5);
    t_=t_/t;
    //uart_txnum(t_,5);
    // uart_txnum(409500/t,5);
    // uart_txfloat(4095.0/(float)t,2,2);
    // uart_txfloat(1.0,2,2);
    // uart_txln("");
    return t_;
}

void dac_init(void)
{
    // DACCLKEN=1;
    DAC0VREF1=0;
    DAC0VREF0=0;

    DAC0CON=0x37;
    DAC0EN=1;


	DAC1VREF1=0;
    DAC1VREF0=0;

    DAC1CON=0x37;
    DAC1EN=1;
    __delay_us(100);



}
/**********************************************************
//---Funtion	:	CMP0_offset
//---Input		:	None
//---Output		:	None
//---Note		:
***********************************************************/
void CMP0_offset(unsigned char OFFSET)
{
	unsigned char tmp=0;
	tmp=CMP0CON2&0XF8;
	CMP0CON2= tmp|OFFSET;
}
/**********************************************************
//---Funtion	:	CMP0_cal
//---Input		:	None
//---Output		:	None
//---Note		:	//每次校准只需选择同相端
***********************************************************/
void CMP0_cal(void)
{
	unsigned char VOOS1 = 0,start = 0;
	unsigned char i = 0;

	CMP0CON2|=0x10;	//使能校准

	CMP0_offset(0);
	__delay_us(500);
	start =CMP0OUT;

	if(start == 1)
	{
		CMP0CON2 &= 0XF7;	//校准负值
	}
	else
	{
		CMP0CON2 |= 0X08;	    //校准正值
	}

	for(i=0;i<=7;i++)      //从0到7找翻转点
	{
		CMP0_offset(i);
		__delay_us(500);
		// printf("1_1 = 0x%02x,\r\n",i);
		if(CMP0OUT != start)
		{
			// printf("V1_1 \r\n");
			VOOS1 = i;
			break;
		}
	}
	// printf("VOOS1_1 = 0x%02x,\r\n",VOOS1);
	CMP0_offset(7);         ////切换状态值并记录OP0OUT初始状态值
	__delay_us(500);
	start = CMP0OUT;
	for(i=8;i>0;i--)       //从7到0找翻转点
	{
		CMP0_offset(i-1);
		__delay_us(500);
		// printf("1_2 = 0x%02x,\r\n",i-1);
		if(CMP0OUT != start)
		{
			// printf("V1_2 \r\n");
			VOOS1 =(VOOS1+ i-1)/2;
			break;
		}
	}
	// printf("VOOS1_2 = 0x%02x,\r\n",i-1);
	// printf("VOOS1 = 0x%02x,\r\n",VOOS1);

	CMP0_offset(VOOS1);    //填入校准值
	CMP0CON2&=0XEF;		  //关闭校准

}


/**********************************************************
//---Funtion	:	CMP0_cal
//---Input		:	None
//---Output		:	None
//---Note		:	每次校准只需选择同相端
***********************************************************/
void CMP1_offset(unsigned char OFFSET)
{
	unsigned char tmp=0;
	tmp=CMP1CON2&0XF8;
	CMP1CON2= tmp|OFFSET;
}

/**********************************************************
//---Funtion	:	CMP0_cal
//---Input		:	None
//---Output		:	None
//---Note		:	//每次校准只需选择同相端
***********************************************************/
void CMP1_cal()
{
	unsigned char VOOS1 = 0,start = 0;
	unsigned char i = 0;

	CMP1CON2|=0x10;	//使能校准

	CMP1_offset(0);
	__delay_us(500);
	start =CMP1OUT;

	if(start == 1)
	{
		CMP1CON2 &= 0XF7;	//校准负值
	}
	else
	{
		CMP1CON2 |= 0X08;	    //校准正值
	}

	for(i=0;i<=7;i++)      //从0到7找翻转点
	{
		CMP1_offset(i);
		__delay_us(500);
		// printf("1_1 = 0x%02x,\r\n",i);
		if(CMP1OUT != start)
		{
			// printf("V1_1 \r\n");
			VOOS1 = i;
			break;
		}
	}
	// printf("VOOS1_1 = 0x%02x,\r\n",VOOS1);
	CMP1_offset(7);         ////切换状态值并记录OP0OUT初始状态值
	__delay_us(500);
	start = CMP1OUT;
	for(i=8;i>0;i--)       //从7到0找翻转点
	{
		CMP1_offset(i-1);
		__delay_us(500);
		// printf("1_2 = 0x%02x,\r\n",i-1);
		if(CMP1OUT != start)
		{
			// printf("V1_2 \r\n");
			VOOS1 =(VOOS1+ i-1)/2;
			break;
		}
	}
	// printf("VOOS1_2 = 0x%02x,\r\n",i-1);
	// printf("VOOS1 = 0x%02x,\r\n",VOOS1);

	CMP1_offset(VOOS1);    //填入校准值
	CMP1CON2&=0XEF;		  //关闭校准

}




void cmp_init(void)
{
    CMPCLKEN = 	1;			//CMP时钟使能


    CMP0PCH2=0;
    CMP0PCH1=1;
    CMP0PCH0=1;
    CMP0NCH1=0;
    CMP0NCH0=1;
    CMP0POS=1;

	CMP1PCH2=1;
    CMP1PCH1=1;
    CMP1PCH0=0;
    CMP1NCH0=1;
    CMP1NCH1=1;
    CMP1POS=0;

    CMPFILTER3=0;
    CMPFILTER2=0;
    CMPFILTER1=0;
    CMPFILTER0=0;

    CMP0EN=1;
    CMP1EN=1;    

    __delay_us(100);
    CMP0IF=0;
    CMP0IE=0;
    CMP1IF=0;   
    CMP1IE=0;

    CMP0_cal();
    CMP1_cal();

    CMPCON=0x00;
    CMPCON1=0xff;
    __delay_us(100);


}



