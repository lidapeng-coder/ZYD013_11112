#ifndef _myi2c_h_
#define  _myi2c_h_

#include "public.h"



void myi2c_init(void);
void myi2c_start(void);
void myi2c_stop(void);
void myi2c_sendbyte(u8 by);
u8 myi2c_recivebyte(void );
void myi2c_sendack(u8 b);
u8 myi2c_reciveack(void );
#endif

