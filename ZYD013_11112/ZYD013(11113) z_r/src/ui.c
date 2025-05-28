#include"public.h"

volatile u8 nixie_z[9][2]={
0,0,
0,0,
0,0,
0,0,
0,0,
0,0,
0,0,
0,0,
0,0
};
s8 ui_id=0;
const u8 nixienum[10]=
{
    0x7d,
    0x0c,
    0xb5,
    0x9d,
    0xcc,
    0xd9,
    0xf9,
    0x0d,
    0xfd,
    0xdd
};

volatile ui_ ui={
    0,0,0,0,0,
    0,0,0,0,0
    };

ui__ ui_ld={
    10,10,10
    };
volatile tim_ui_ tim_ui={0,0,0};
void new_nixie(void)
{
    u8 temp=0;
    if(ui.num1<10)
    {
        nixie_z[0][0]=nixienum[ui.num1];
        temp=nixie_z[0][0]&mask0on;
        if(nixie_z[0][0]&mask1on)
        {
            nixie_z[0][0]|=mask0on;
        }
        else
        {
            nixie_z[0][0]&=mask0off;
        }
        if(temp)
        {
            nixie_z[0][0]|=mask1on;
        }
        else
        {
            nixie_z[0][0]&=mask1off;
        }
        if((ui.num1==1)&&(ui.num2==6))
        {
            nixie_z[0][0]=0x60;
        }
    }
    else
    {
        nixie_z[0][0]=0;
    }
    if(ui.ou_d){nixie_z[0][1]|=mask0on;}else{nixie_z[0][1]&=mask0off;}
    if(ui.wa){nixie_z[0][1]|=mask1on;}else{nixie_z[0][1]&=mask1off;}

    if(ui.num2<10)
    {
        nixie_z[1][0]=nixienum[ui.num2];
    }
    else
    {
        nixie_z[1][0]=0;
    }
    if(ui.ts){nixie_z[1][1]|=mask1on;}else{nixie_z[1][1]&=mask1off;}

    nixie_z[2][0]=ui.w1?0xff:0;
    if(ui.ou_d){nixie_z[2][1]|=mask0on;}else{nixie_z[2][1]&=mask0off;}
    nixie_z[2][1]&=mask1off;

    if(ui.w1)
    {
        nixie_z[3][0]=0xff;
        nixie_z[3][1]=0x00;
        nixie_z[4][0]=0xff;
        nixie_z[4][1]=0x03;
        nixie_z[5][0]=0xff;
        nixie_z[5][1]=0x03;
        nixie_z[6][0]=0xff;
        nixie_z[6][1]=0x03;
        nixie_z[7][0]=0xff;
        nixie_z[7][1]=0x03;
    }
    else
    {
        nixie_z[3][0]=0;
        nixie_z[3][1]=0;
        nixie_z[4][0]=0;
        nixie_z[4][1]=0;
        nixie_z[5][0]=0;
        nixie_z[5][1]=0;
        nixie_z[6][0]=0;
        nixie_z[6][1]=0;
        nixie_z[7][0]=0;
        nixie_z[7][1]=0;
    }
    temp=0;
    if(ui.w2)
    {
        temp=0xe0;
    }
    if(ui.dian>4)
    {
        nixie_z[8][0]=0;
    }
    else
    {
        nixie_z[8][0]=((0x0f<<(4-ui.dian))&0x0f);
    }
    if(ui.dian_s)
    {
        nixie_z[8][0]|=0x10;
    }
    else
    {
        nixie_z[8][0]&=0xef;
        
    }
    nixie_z[8][0]|=temp;
    nixie_z[8][1]=0;
    
    if(ui.yd){nixie_z[1][1]|=mask0on;}else{nixie_z[1][1]&=mask0off;}
}


void ldz(u8 a)
{
    ui_ld.n		=a;
    ui_ld.ts 	=a;
    ui_ld.w 	=a;
}
//50ms 53
void ui_cb(task* task_)
{
    if(task_->sucCnt<=21)
    {
        if(task_->sucCnt==0)
        {
            ui.w1	    =1;
            ui.w2	    =0;
            
            ui.ou_d	    =1;
            ui.ts	    =ts;
            ui.yd	    =yd;
            ui.wa	    =0;
            ui.dian_s   =0;


            ldz(10);
        }
        if((task_->sucCnt&1)==0)
        {
            if(zz)
            {
                ui.num1	    =zz/100;
                ui.num2	    =(zz/10)%10;
                
            }
            else
            {
                ui.num1     =0;
                ui.num2     =0;
            }
            ui.dian	    =5;
        }
    }
    else if(task_->sucCnt<=42)
    {
        if(task_->sucCnt==22)
        {
            ui.w1	    =1;
            ui.w2	    =ts;
            
            ui.ou_d	    =0;
            ui.ts	    =ts;
            ui.yd	    =yd;
            ui.wa	    =1;
            ui.dian_s  =0;

        }
        if((task_->sucCnt&1)==0)
        {
            ui.num1	    =pw/10;
            ui.num2	    =pw-ui.num1*10;
            ui.dian	    =5;
            
        }
        
    }
    else
    {
        if(task_->sucCnt&1)
        {
            ui.num1	    =pw/10;
            ui.num2	    =pw-ui.num1*10;
            ui.dian	    =5;
        }
        ldz(52-task_->sucCnt);
    }
    new_nixie();
    if(task_->sucCnt==52)
    {
        if(USB_DET&&(CHRG_FULL==0))
        {
            add_task_id(ui_chrg_id,ui_chrg_ms,ui_chrg_max,ui_id);
        }
    }
}

//500ms 0
void ui_chrg(task* task_)
{
    if(task_->sucCnt==0)
    {
        ui.w1	    =0;
        ui.w2	    =0;
            
        ui.ou_d	    =0;
        ui.ts	    =ts;
        ui.yd	    =yd;
        ui.wa	    =0;
        ui.dian_s   =1;
        ldz(10);

        ui.num1	    =99;
        ui.num2	    =99;
    }
    if(task_->sucCnt&1)
    {
        ui.dian	    =bat.dian>3?4:bat.dian+1;
    }
    else
    {
        ui.dian	    =bat.dian>3?3:bat.dian;
    }
    task_->sucCnt++;
    new_nixie();
}

//300ms 6
void ui_chrgfree(task* task_)
{
    if(task_->sucCnt&1)
    {
        /* ui.w1	    =0;
        ui.w2	    =0;
            
        ui.ou_d	    =0;
        ui.ts	    =0;
        ui.yd	    =yd;
        ui.wa	    =0;
        ui.dian_s   =0;

        ui_ld.w0	=0;
        ui_ld.n	    =0;
        ui_ld.ts    =0;

        ui.num1	    =99;
        ui.num2	    =99; */
        ldz(0);
    }
    else
    {
        ui.dian	    =4;
        ui.w1	    =1;
        ui.w2	    =1;
            
        ui.ou_d	    =1;
        ui.wa	    =1;
        ui.ts	    =1;
        ui.yd	    =1;
        ui.dian_s   =1;
        ldz(10);

        ui.num1	    =8;
        ui.num2	    =8;
    }
    new_nixie();
}

//5000ms 3
void ui_chrgfull(task* task_)
{
    if(task_->sucCnt==0)
    {
        ui.w1	    =0;
        ui.w2	    =0;
            
        ui.ou_d	    =0;
        ui.ts	    =ts;
        ui.yd	    =yd;
        ui.wa	    =0;
        ui.dian_s   =1;
        ldz(10);

        ui.num1	    =99;
        ui.num2	    =99;
        ui.dian	    =bat.dian;
    }
    else if(task_->sucCnt==2)
    {
        ldz(0);
    }
    new_nixie();
}

//50ms 0
void ui_smoing(task* task_)
{
    if(task_->sucCnt==0)
    {
        ui.w1		=1;
        ui.w2		=1;
        ui.num1		=99;
        ui.num2		=99;
        ui.ou_d		=0;
        ui.wa		=0;
        ui.ts		=0;
        ui.yd		=yd;
        ui.dian_s	=0;
        ui.dian     =5;
    }
    if(task_->sucCnt<=9)
    {
        ui_ld.w=task_->sucCnt+1;
    }
    else
    {
        ui_ld.w=19-task_->sucCnt;

    }
    new_nixie();
    task_->sucCnt++;
    if(task_->sucCnt>=20)
    {
        task_->sucCnt=0;
    }
    // if(ui_ld.w==0)
    // {
    //     timer2_init();
    // }
}

//50ms 73
void ui_smoend_dl_getup(task* task_)
{
    if(task_->sucCnt<=62)
    {
        if(task_->sucCnt==0)
        {
            ui.w1		=1;
            ui.w2		=1;
            
            ui.ou_d		=0;
            ui.wa		=1;
            ui.ts		=ts;
            ui.yd		=yd;
            
            ui.dian_s	=1;
            ldz(10);
        }
        
    }
    else
    {
        ldz(72-task_->sucCnt);
    }
    if((task_->sucCnt&1)==0)
    {
        ui.num1	    =pw/10;
        ui.num2	    =pw-ui.num1*10;
        ui.dian	    =bat.dian;
    }
    new_nixie();
    if(task_->sucCnt==72)
    {
        if(USB_DET&&(CHRG_FULL==0))
        {
            add_task_id(ui_chrg_id,ui_chrg_ms,ui_chrg_max,ui_id);
        }
    }
}

//250ms 10
void ui_kl(task* task_)
{
    if(task_->sucCnt&1)
    {
        ui.w1	    =1;
        ui.w2	    =0;
            
        ui.ou_d	    =0;
        ui.wa	    =0;
        ui.ts	    =0;
        ui.yd	    =0;
        ui.dian_s   =0;
        ui.dian     =5;
        ldz(10);

        ui.num1	    =99;
        ui.num2	    =99;
    }
    else
    {
        ui.w1	    =1;
        ui.w2	    =0;
            
        ui.ou_d	    =0;
        ui.wa	    =0;
        ui.ts	    =0;
        ui.yd	    =1;
        ui.dian_s  =0;
        ui.dian     =5;
        ldz(10);

        ui.num1	    =99;
        ui.num2	    =99;
    }
    if(task_->sucCnt==9)
    {
        ldz(0);
    }
    new_nixie();
}

//50ms 100
void ui_ts_on(task* task_)
{
    if(task_->sucCnt<=9)
    {
        if(task_->sucCnt==0)
        {
            ui.w1		=1;
            ui.w2		=0;
            
            ui.ou_d		=0;
            ui.wa		=1;
            ui.ts		=1;
            ui.yd		=yd;
            
            ui.dian_s	=1;
        }
        
    }
    else if(task_->sucCnt<=19)
    {
        ldz(19-task_->sucCnt);
        ui_ld.ts=10;
    }
    else if(task_->sucCnt<=89)
    {
        ui_ld.ts=10;
    }
    else
    {
        ui_ld.ts=99-task_->sucCnt;
    }
    if(((task_->sucCnt&1)==0)&&task_->sucCnt<19)
    {
        ui.num1	    =pw/10;
        ui.num2	    =pw-ui.num1*10;
        ui.dian	    =bat.dian;
    }
    new_nixie();
    if(task_->sucCnt==99)
    {
        if(USB_DET&&(CHRG_FULL==0))
        {
            add_task_id(ui_chrg_id,ui_chrg_ms,ui_chrg_max,ui_id);
        }
    }
}

//50ms 43
void ui_ts_off(task* task_)
{
    if(((task_->sucCnt&1)==0)&&task_->sucCnt>=21)
    {
        ui.w1		=1;
        ui.w2		=1;
        ui.num1	    =pw/10;
        ui.num2	    =pw-ui.num1*10;
        ui.dian	    =bat.dian;
        new_nixie();
    }
    if(task_->sucCnt<=11)
    {
        if(task_->sucCnt==0)
        {
            ui.w1		=0;
            ui.w2		=0;
            
            ui.ou_d		=0;
            ui.wa		=1;
            ui.ts		=0;
            ui.yd		=yd;
            
            ui.dian_s	=1;
            
            ui_ld.n=0;
            new_nixie();
        }
        switch (task_->sucCnt)
        {
        case 0:
            nixie_z[4][1]|=pin1_on;
            nixie_z[6][1]|=pin1_on;
            nixie_z[5][0]|=pin0_on;
            nixie_z[7][0]|=pin0_on;

            break;
        case 1:
            nixie_z[4][1]|=pin0_on;
            nixie_z[6][1]|=pin0_on;
            nixie_z[5][0]|=pin1_on;
            nixie_z[7][0]|=pin1_on;
            break;
        case 2:
            nixie_z[4][0]|=pin7_on;
            nixie_z[6][0]|=pin7_on;
            nixie_z[5][0]|=pin2_on;
            nixie_z[7][0]|=pin2_on;
            break;
        case 3:
            nixie_z[4][0]|=pin6_on;
            nixie_z[6][0]|=pin5_on;
            nixie_z[5][0]|=pin3_on;
            nixie_z[7][0]|=pin3_on;

            nixie_z[8][0]|=pin5_on;
            break;
        case 4:
            nixie_z[4][0]|=pin5_on;
            nixie_z[6][0]|=pin4_on;
            nixie_z[5][0]|=pin4_on;
            nixie_z[7][0]|=pin4_on;

            nixie_z[8][0]|=pin6_on;
            break;
        case 5:
            nixie_z[4][0]|=pin3_on;
            nixie_z[6][0]|=pin3_on;
            nixie_z[5][0]|=pin6_on;
            nixie_z[7][0]|=pin5_on;

            nixie_z[8][0]|=pin7_on;
            break;
        case 6:
            nixie_z[4][0]|=pin2_on;
            nixie_z[6][0]|=pin2_on;
            nixie_z[5][0]|=pin7_on;
            nixie_z[7][0]|=pin6_on;
            break;
        case 7:
            nixie_z[4][0]|=pin1_on;
            nixie_z[6][0]|=pin1_on;
            nixie_z[5][1]|=pin0_on;
            nixie_z[7][1]|=pin0_on;
            break;
        case 8:
            nixie_z[4][0]|=pin0_on;
            nixie_z[6][0]|=pin0_on;
            nixie_z[5][1]|=pin1_on;
            nixie_z[7][1]|=pin1_on;
            break;
        case 9:
            nixie_z[2][0]|=pin5_on;
            nixie_z[3][0]|=pin5_on;
            break;
        case 10:
            nixie_z[2][0]|=pin4_on;
            nixie_z[2][0]|=pin7_on;
			nixie_z[2][0]|=pin1_on;
            nixie_z[3][0]|=pin0_on;
            nixie_z[3][0]|=pin6_on;
            nixie_z[3][0]|=pin4_on;
            break;
        case 11:
            nixie_z[2][0]|=pin3_on;
            nixie_z[2][0]|=pin6_on;
			nixie_z[2][0]|=pin0_on;
            nixie_z[3][0]|=pin1_on;
            nixie_z[3][0]|=pin7_on;
            nixie_z[3][0]|=pin2_on;
            break;

        
        default:
            break;
        }
    }
    else if(task_->sucCnt<=21)
    {
        ui_ld.n++;
    }
    else
    {
        if(task_->sucCnt==42)
        {
            ldz(0);
        }
    }
    if(task_->sucCnt==42)
    {
        if(USB_DET&&(CHRG_FULL==0))
        {
            add_task_id(ui_chrg_id,ui_chrg_ms,ui_chrg_max,ui_id);
        }
    }
}

//250ms 10
void ui_timout(task* task_)
{
    if(task_->sucCnt&1)
    {
        ldz(0);
    }
    else
    {
        ui.w1		=1;
        ui.w2		=1;
        
        ui.ou_d		=0;
        ui.wa		=1;
        ui.ts		=0;
        ui.yd		=yd;
        
        ui.dian_s	=1;
        ldz(10);

        ui.num1	    =pw/10;
        ui.num2	    =pw-ui.num1*10;
        ui.dian	    =bat.dian;

    }
    new_nixie();
}

//300ms  3
void ui_begin(task* task_)
{
    if(task_->sucCnt==0)
    {
        ui.w1		=1;
        ui.w2		=1;
        
        ui.ou_d		=1;
        ui.wa		=1;
        ui.ts		=1;
        ui.yd		=1;
        
        ui.dian_s	=1;
        ldz(10);

        ui.num1	    =8;
        ui.num2	    =8;
        ui.dian	    =4;

    }
    else  if(task_->sucCnt==1)
    {
        ldz(0);

    }
    else
    {
        #if bug
        uart_txln("sleep");
        #endif
        cb_init();
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
        __delay_ms(50);
    }
    new_nixie();
}



