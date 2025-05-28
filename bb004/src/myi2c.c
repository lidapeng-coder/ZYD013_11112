#include "public.h"                  // Device header

#define n_us    2
// #define sclk_gpio_rcc 	RCC_APB2Periph_GPIOB
// #define sclk_gpio 		GPIOB
// #define sclk_pin  		GPIO_Pin_8

// #define sda_gpio_rcc 	RCC_APB2Periph_GPIOB
// #define sda_gpio  		GPIOB
// #define sda_pin   		GPIO_Pin_9




// void write_sclk(u8 bit)
// {
// 	GPIO_WriteBit(sclk_gpio,sclk_pin,(BitAction)bit);
// }
// void write_sda(u8 bit)
// {
// 	GPIO_WriteBit(sda_gpio,sda_pin,(BitAction)bit);
// }

#define write_sclk(x) 	LCD_SCL=x
#define write_sda(x) 	LCD_SDA=x


void myi2c_init(void)
{
	write_sda(1);
	__delay_us(n_us);
	write_sclk(1);
	__delay_us(n_us);
}

void myi2c_start(void)
{
	write_sda(1);
	__delay_us(n_us);
	write_sclk(1);
	__delay_us(n_us);
	write_sda(0);
	__delay_us(n_us);
	write_sclk(0);
	__delay_us(n_us);
}
void myi2c_stop(void)
{
	write_sda(0);
	__delay_us(n_us);
	write_sclk(0);
	__delay_us(n_us);
	write_sclk(1);
	__delay_us(n_us);
	write_sda(1);
}
	
void myi2c_sendbyte(u8 by)
{
	u8 i;
	for(i=0;i<8;i++)
	{
		if(by & (0x80>>i))
		{
			write_sda(1);
		}
		else
		{
			write_sda(0);
		}
		__delay_us(n_us);
		write_sclk(1);
		__delay_us(n_us);
		write_sclk(0);
		__delay_us(n_us);
	}
}

u8 myi2c_recivebyte(void )
{
	u8 i,byte=0;
	write_sda(1);
	__delay_us(n_us);
	for(i=0;i<8;i++)
	{
		write_sclk(1);
		__delay_us(n_us);
		if(LCD_SDA!=0)
		{
			byte|=(0x80>>i);
		}
		write_sclk(0);
		__delay_us(n_us);
	}
	return byte;
}

void myi2c_sendack(u8 b)
{
	if(b)
	{
		write_sda(1);
	}
	else{
		write_sda(0);
	}
	__delay_us(n_us);
	write_sclk(1);
	__delay_us(n_us);
	write_sclk(0);
	__delay_us(n_us);
}

u8 myi2c_reciveack(void )
{
	u8 byte=0,cnt=0;
	write_sda(1);
	__delay_us(n_us);
	
	write_sclk(1);
	__delay_us(n_us);
	#if 0
	while(LCD_SDA==1)
	{
		cnt++;
		if(cnt>=255)
		{
			break;
		}
	}
	#endif
	if(LCD_SDA!=0)
	{
		byte=1;
	}
	write_sclk(0);
	__delay_us(n_us);
	return byte;
}
