#ifndef     __uart_h_
#define     __uart_h_

#include "public.h"

void uart_init(void);//115200
void uart_txnum(uint16_t p,uint8_t len);
void uart_txln(const char * p);
void uart_txfloat(float p,uint8_t len1,uint8_t len2);
#endif

