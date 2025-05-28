#include "public.h"


void gpio_init(void)
{
    OSCCON=0x73;
    PCON=0;
    PORTA= pin0_on  | pin1_off | pin2_off | pin3_off | pin4_off | pin5_off | pin6_off | pin7_off  ;
    PORTB= pin0_on  | pin1_off | pin2_off | pin3_off | pin4_off | pin5_off | pin6_off | pin7_off  ;
    PORTC= pin0_off | pin1_off | pin2_off | pin3_off | pin4_off | pin5_off | pin6_off | pin7_off  ;

    TRISA= pin0_off | pin1_on  | pin2_on  | pin3_on  | pin4_on  | pin5_on  | pin6_on  | pin7_on   ;
    TRISB= pin0_off | pin1_on  | pin2_on  | pin3_on  | pin4_on  | pin5_on  | pin6_on  | pin7_on   ;
    TRISC= pin0_on  | pin1_on  | pin2_on  | pin3_on  | pin4_on  | pin5_on  | pin6_on  | pin7_on   ;

    #if 1
    PAPU=  pin0_on  | pin1_off | pin2_on  | pin3_on  | pin4_on  | pin5_on  | pin6_on  | pin7_on    ;
    PBPU=  pin0_on  | pin1_on  | pin2_on  | pin3_on  | pin4_on  | pin5_on  | pin6_on  | pin7_on    ;
    PCPU=  pin0_on  | pin1_on  | pin2_on  | pin3_on  | pin4_on  | pin5_on  | pin6_off | pin7_on   ;
    #else
    PAPU=  pin0_on  | pin1_off | pin2_on  | pin3_on  | pin4_on  | pin5_on  | pin6_on  | pin7_on    ;
    PBPU=  pin0_on  | pin1_off | pin2_off | pin3_off | pin4_off | pin5_off | pin6_on  | pin7_on    ;
    PCPU=  pin0_off | pin1_off | pin2_off | pin3_off | pin4_off | pin5_off | pin6_off | pin7_on   ;
    #endif
    PAPD=  pin0_on  | pin1_on  | pin2_on  | pin3_on  | pin4_off | pin5_on  | pin6_on  | pin7_on    ;

    #if !od
    PAOD=  pin0_off | pin1_off | pin2_off | pin3_off | pin4_off | pin5_off | pin6_off | pin7_off   ;
    #else
    PAOD=  pin0_on  | pin1_off | pin2_off | pin3_off | pin4_off | pin5_off | pin6_off | pin7_off   ;
    #endif    
    FVRCON=0x01;//1.2v

    #if ioi
    IOCUR=0xff;
    #else
    IOCUR=0x00;
    #endif
    ADIP=0;
    #if bug_a1
	TRISA1=0;
	#endif
}
void timer1_init(void)
{
    #if !cpu_t2
    PR1H=0x1;
    PR1L=0xf3;
    #else
    PR1H=0x3;
    PR1L=0xe7;

    #endif
    TMR1H=0x0;
    TMR1L=0x0;

    T1CON0=0x18;
    T1CON1=0;

    TMR1ON=1;

    TMR1IE=1;
    PEIE=1;
    GIE=1;
    
}

void timer2_init(void)
{
    //POLS=pols8;PME=pme8;duty8=8;
    PR2=79;
    TMR2=0;
    T2CON0=0x0;
    T2CON1=2;
    TMR2IF=0;
    TMR2IE=0;
    TMR2IP=0;
    TMR2ON=1;
}

//#define openpwm(dut)    
void cmp0_init(void)
{
    DACCON=0xfF;

    CMP0CON0=0x39;
    #if cpu_t2
    CMP0CON1=0x34;
    #else
    CMP0CON1=0x14;
    #endif
    CMP0EN=1;
    CMP0IF=0;
    CMP0IE=1;
    PEIE=1;
    GIE=1;
    //__delay_ms(40);
    CMP0IF=0;
}

void timer0_init(void)//1``4us
{
    PR0=49;
    TMR0=0;
    
    #if !cpu_t2
    T0CON=0x03;
    #else
    T0CON=0x04;
    #endif

    TMR0IF=0;
    TMR0IE=1;
    PEIE=1;
    GIE=1;

}

// volatile unsigned char        USART_BUF @0x20;        //RAM�ʼ�ĵ�ַ
// volatile bit D0                        @ ((unsigned)&USART_BUF*8)+0;
// volatile bit D1                        @ ((unsigned)&USART_BUF*8)+1;
// volatile bit D2                        @ ((unsigned)&USART_BUF*8)+2;
// volatile bit D3                        @ ((unsigned)&USART_BUF*8)+3;
// volatile bit D4                        @ ((unsigned)&USART_BUF*8)+4;
// volatile bit D5                        @ ((unsigned)&USART_BUF*8)+5;
// volatile bit D6                        @ ((unsigned)&USART_BUF*8)+6;
// volatile bit D7                        @ ((unsigned)&USART_BUF*8)+7;

static volatile ui_buff_ USART_BUF;

#define TX_DIR  TRISA1
#define TX_PIN  PA1
void uart_init(void)
{
	TX_DIR=0; 
	TX_PIN=1;
}

void delay_bps1(void)
{
        unsigned char i;

        for(i=0;i<=2;i++) 
        {
                i++;
                i--;
        }
        NOP();NOP();NOP();NOP();NOP();NOP();
        CLRWDT();
}

void putch(  u8 c)
{
    GIE  = 0;   //disable Interrupt
        while(GIE == 1)
        {
                GIE  = 0;
        }
        
        USART_BUF.buf = c;
        TX_PIN = 1;
        TX_PIN = 0; //START
        #if cpu_t2
        delay_bps1();
        #endif
        delay_bps1();
        TX_PIN = USART_BUF.a; //0
        delay_bps1();
        #if cpu_t2
        delay_bps1();
        #endif
        TX_PIN = USART_BUF.b;
        delay_bps1();
        #if cpu_t2
        delay_bps1();
        #endif
        TX_PIN = USART_BUF.c;
        delay_bps1();
        #if cpu_t2
        delay_bps1();
        #endif
        TX_PIN = USART_BUF.d;
        delay_bps1();
        #if cpu_t2
        delay_bps1();
        #endif
        TX_PIN = USART_BUF.e;
        delay_bps1();
        #if cpu_t2
        delay_bps1();
        #endif
        TX_PIN = USART_BUF.f;
        delay_bps1();
        #if cpu_t2
        delay_bps1();
        #endif
        TX_PIN = USART_BUF.g;
        delay_bps1();
        #if cpu_t2
        delay_bps1();
        #endif
        TX_PIN = USART_BUF.h;
        delay_bps1();
        #if cpu_t2
        delay_bps1();
        #endif
        TX_PIN = 1;     //stop
        delay_bps1();
        #if cpu_t2
        delay_bps1();
        #endif
        
        GIE  = 1;   //enable Interrupt
}
// void uart_init(void)//115200
// {
// /* 
//     TRISA1=0;
// 	PA1=1;
// 	UART_MUX=0;		//UART_MUX=0时PA1(TX)和PA2(RX)；UART_MUX=1时PC0(TX)和PC1(RX)
//     UARTCON = 0x00;
// 	UARTCON = 0x8c;
// 	SPBRG   = 69;	
// 	TX_EN = 1;
//     TXIF = 0;
//  */

//     TRISA1=0;
// 	PA1=1;
//     TRISA2=1;
//     PA2PU=0;
// 	UART_MUX=0;		//UART_MUX=0时PA1(TX)和PA2(RX)；UART_MUX=1时PC0(TX)和PC1(RX)
// 	UART_MUX=0;		//UART_MUX=0时PA1(TX)和PA2(RX)；UART_MUX=1时PC0(TX)和PC1(RX)
//     UARTCON = 0x00;
// 	UARTCON = 0x8c;
// 	SPBRG   =69;	
// 	TX_EN = 1;
//     TXIE=0;
    
// }

// void uart_txc(u8 c)
// {
//     while(!TXIF)continue;
// 	TXREG = c;
// 	TXIF = 0;

// }

static  u32 power[7]={1,10,100,1000,10000,100000,1000000};
#define power(a,b)	power[b] 

void uart_txnum(uint32_t p,uint8_t len)
{
	for(uint8_t i=0;i<len;i++)
	{
		uart_txc((p/power(10,len-1-i))%10+'0');
	}
	uart_txc('\t');
	uart_txc('\n');
}

void uart_txln(const char * p)
{
	for(uint8_t i=0;p[i]!=0;i++)
	{
		uart_txc(p[i]);
	}
	uart_txc('\t');
	uart_txc('\n');
}

u16 adc_demo(u8 chl)//0 bat  1 load
{
    ADCON1=0x60;
    if(chl)
    {
        ADCON0=0x15;//0x15  0x39
    }
    else
    {
        ADCON0=0x39;//0x15  0x39
    }
    

    __delay_us(10);
    ADIF=0;
    ADIE=0;
    GO=1;
    while(GO==1);
    return ((ADRESH&0x0f)<<8)|ADRESL;
}