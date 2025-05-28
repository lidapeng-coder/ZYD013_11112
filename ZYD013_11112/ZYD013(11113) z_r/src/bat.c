#include "public.h"                  // Device header


_bat bat={1,420};


u16 get_bat(void)
{
    u32 ttt=0;
    #if cpu_t2
    ADCON1=0x60;\

    #else
    ADCON1=0x60;
    #endif
    ADCON0=0x39;\
    ADIF=0;\
    ADIE=0;\
    GO=1;\
    while(GO);
    ADIF=0;
    ttt=((ADRESH&0x0f)<<8)|ADRESL;
    ttt=491520ul/ttt;
    return ttt;
}




// #define bat_task_id 		14
// #define bat_task_ms		    1000
// #define bat_task_max		0

//2s  0
void bat_task(task* task_)
{
    u16 b=0;
    if(SMO_PWM&&(USB_DET==0)&&(SI_MIC==0)&&(task_list[ui_id].active==0))
    {
	    b=get_bat();
        //uart_txnum(b,4);
        if((bat.bat>b)||((bat.bat+50)<=b))
        {
            bat.bat=b;
        }
        if( bat.bat<=317)
        {
            bat.dian=0;
            //uart_txln("lowbat");
        }
        else if ( bat.bat<=345)
        {
            bat.dian=1;
        }
        else if ( bat.bat<=370)
        {
            bat.dian=2;
        }
        else if ( bat.bat<=390)
        {
            bat.dian=3;
        }
        else 
        {
            bat.dian=4;
        }

    }
}


