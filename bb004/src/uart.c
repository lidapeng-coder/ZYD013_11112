#include "public.h"                  // Device header

void uart_init(void)//115200
{
    TRISD2 = 0;PD2OD = 0;PD2PU = 0;PD2PD = 1;PD2AEN = 0; //pd2  tx
    TRISD3 = 0;PD3OD = 0;PD3PU = 0;PD3PD = 1;PD3AEN = 0; //pd3  rx

    UARTCLKEN=1;
	TX0_MAP = MAP_PD2;
	RX0_MAP = MAP_PD3;

    SPEN=1;
    BGRM=1;
    BRGH=1;
    SPBRG=69;
    TXEN=1;
}


void uart_txc(char c)
{
	while(!TXIF)	/* set when register is empty */
		continue;
	TXREG = c;
	while(!TXIF);
	while(!TMRT);
}
#if 0
uint16_t power(uint8_t a,uint8_t b)
{
	uint16_t t=1;
	for(uint8_t i=0;i<b;i++)
	{
		t*=a;
	}
	return t;
}
#else
u16 power[5]={1,10,100,1000,10000};
#define power(a,b)	power[b] 

#endif
void uart_txnum(uint16_t p,uint8_t len)
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
void uart_txfloat(float p,uint8_t len1,uint8_t len2)
{
	float t;
	t=p*(float)power(10,len2);
	for(uint8_t i=0;i<len1+len2;i++)
	{
		uart_txc(((uint16_t)t/power(10,len1+len2-1-i))%10+'0');
		if(i==len1-1)
		{
			uart_txc('.');
		}
	}
	uart_txc('\t');
	uart_txc('\n');
	
}