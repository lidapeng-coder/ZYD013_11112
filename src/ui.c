#include"public.h"

volatile   union ui_buff_ ui_buff[12];
s8 ui_id=6;
const u8 nixienum[10]=
{
    0x3f,
    0x06,
    0x5b,
    0x4f,
    0x66,
    0x6d,
    0x7d,
    0x07,
    0x7f,
    0x6f
};

volatile ui_ ui={
    0,0,0,0,0,
    0,0,0,0,0,
    0
    };

ui__ ui_ld={
    10,10,10,10,10
    };
volatile tim_ui_ tim_ui={0};
void new_nixie(void)
{
    if(ui.num1<10)//0
    {
        ui_buff[0].buf=nixienum[ui.num1];
        if((ui.num1==1)&&(ui.num2==6))
        {
            ui_buff[0].buf=0x30;
        }
    }
    else
    {
        ui_buff[0].buf=0;
    }
    ui_buff[0].h=ui.ou_d;
    ui_buff[10].j0=ui.wa;

    if(ui.num2<10)//1
    {
        ui_buff[1].buf=nixienum[ui.num2];
    }
    else
    {
        ui_buff[1].buf=0;
    }
    ui_buff[1].h=ui.ou_d;
    ui_buff[10].j1=ui.ts;

    ui_buff[2].buf=(ui.w)?0xff:0;//2
    ui_buff[10].j2=ui.w;

    if(ui.w){ui_buff[3].buf=0x1f;}else{ui_buff[3].buf=0;}//3
    ui_buff[3].f=ui.yd;
    ui_buff[10].j3=(ui.q>=8)?1:0;
    if(ui.q>=9){
        ui_buff[3].h=1;
        if(ui.q==10)
        {
            ui_buff[3].g=1;
        }
    }

    ui_buff[4].buf=(u8)(0xff<<(10-ui.q));//4
    if(ui.q>=2){ui_buff[10].j4=1;}else{ui_buff[10].j4=0;}

    if(ui.q)//5
    {
        if(ui.q<=7){ui_buff[5].buf=(0xff>>(7-ui.q));}else{ui_buff[5].buf=0xff;}
    }
    else
    {
        ui_buff[5].buf=0;
    }
    ui_buff[10].j5=(ui.cnt>=5)?1:0;

    ui_buff[6].buf=0;//6
    switch (ui.cnt)
    {
    case 5:
    case 4:
        ui_buff[6].a=1;
    case 3:
        ui_buff[6].b=1;
    case 2:
        ui_buff[6].c=1;
    case 1:
        ui_buff[6].d=1;
        break;
    
    default:
        break;
    }
    switch (ui.dian)
    {
    case 4:
        ui_buff[6].e=1;
    case 3:
        ui_buff[6].f=1;
    case 2:
        ui_buff[6].g=1;
    case 1:
        ui_buff[6].h=1;
        break;
    
    default:
        break;
    }
    ui_buff[10].j6=(ui.w)?1:0;

    ui_buff[7].buf=(ui.u)?0xff:0;//7
    ui_buff[10].j7=ui.u;

    ui_buff[8].buf=(ui.u)?0xff:0;//8
    ui_buff[11].j8=ui.u;

    ui_buff[9].buf=(ui.w)?0xff:0;//9
    ui_buff[11].j9=ui.w;
}

void ldz(u8 a)
{
    ui_ld.w1    =a;
    ui_ld.w2 	=a;
    ui_ld.cnt 	=a;
    ui_ld.n 	=a;
    ui_ld.ts 	=a;
}

// //50ms 53
void ui_cb(task* task_)
{
    if(task_->sucCnt<=21)
    {
        if(task_->sucCnt==0)
        {
            ui.w	    =0;
            ui.u	    =0;
            ui.q        =10;

            ui.ou_d	    =1;
            ui.wa	    =0;
            ui.ts	    =ts;
            ui.yd	    =yd;
            ui.cnt      =0;
            ui.dian	    =0;
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
            new_nixie();
        }
    }
    else if(task_->sucCnt<=42)
    {
        if(task_->sucCnt==22)
        {
            ui.ou_d	    =0;
            ui.wa	    =1;
        }
        if((task_->sucCnt&1)==0)
        {
            ui.num1	    =pw/10;
            ui.num2	    =pw-ui.num1*10;
            new_nixie();
        }
    }
    else
    {
        if(task_->sucCnt&1)
        {
            ui.num1	    =pw/10;
            ui.num2	    =pw-ui.num1*10;
            ui.dian	    =0;
            new_nixie();
        }
        ldz(52-task_->sucCnt);
    }
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
        ui.w	    =0;
        ui.u	    =0;
            
        ui.ou_d	    =0;
        ui.ts	    =ts;
        ui.yd	    =yd;
        ui.wa	    =0;
        ui.dian     =0;
        ui.cnt      =0;
        ldz(10);
    }
    task_->sucCnt=1;
    ui.cnt++;
    if(ui.cnt>=6)
    {
        ui.cnt=1;
    }
    ui.num1	    =chrg_num/10;
    ui.num2	    =chrg_num-ui.num1*10;
    new_nixie();
}

//300ms 6
void ui_chrgfree(task* task_)
{
    if(task_->sucCnt&1)
    {
        ldz(0);
    }
    else
    {
        ui.w	    =1;
        ui.u	    =1;
        ui.q	    =10;
            
        ui.ou_d	    =1;
        ui.wa	    =1;
        ui.ts	    =1;
        ui.yd	    =1;
        ui.dian     =4;
        ui.cnt      =5;
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
        ui.w	    =0;
        ui.u	    =0;
        ui.q	    =0;
            
        ui.ou_d	    =0;
        ui.wa	    =0;
        ui.ts	    =ts;
        ui.yd	    =yd;
        ui.dian     =4;
        ui.cnt      =0;
        ldz(10);

        ui.num1	    =10;
        ui.num2	    =10;
        new_nixie();
    }
    else if(task_->sucCnt==2)
    {
        ldz(0);
    }
}

//50ms 0
void ui_smoing(task* task_)
{
    if(task_->sucCnt==0)
    {
        ui.w	    =1;
        ui.u	    =1;
        ui.q	    =10;
            
        ui.ou_d	    =0;
        ui.wa	    =0;
        ui.ts	    =0;
        ui.yd	    =0;
        ui.dian     =0;
        //ui.cnt      =0;
        ldz(10);

        ui.num1	    =10;
        ui.num2	    =10;
    }
    if(task_->sucCnt<=9)
    {
        ui_ld.w1=task_->sucCnt+1;
    }
    else
    {
        ui_ld.w1=19-task_->sucCnt;

    }
    if((task_->sucCnt==0)||(task_->sucCnt==10))
    {
        ui.cnt++;
        if(ui.cnt>=6)
        {
            ui.cnt=1;
        }
        new_nixie();
    }
    task_->sucCnt++;
    if(task_->sucCnt>=20)
    {
        task_->sucCnt=0;
    }
}

//50ms 73
void ui_dl_getup(task* task_)
{
    if(task_->sucCnt<=62)
    {
        if(task_->sucCnt==0)
        {
            ui.w	    =1;
            ui.u	    =1;
            ui.q	    =10;
                
            ui.ou_d	    =0;
            ui.wa	    =1;
            ui.ts	    =ts;
            ui.yd	    =yd;
            //ui.dian     =bat.dian;
            ui.cnt      =0;
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

//50ms 73
void ui_smoend(task* task_)
{
    if(task_->sucCnt<=9)
    {
        if(task_->sucCnt==0)
        {
            ui.w	    =1;
            ui.u	    =1;
            ui.q	    =10;
                
            ui.ou_d	    =0;
            ui.wa	    =1;
            ui.ts	    =ts;
            ui.yd	    =yd;
            //ui.dian     =bat.dian;
            //ui.cnt      =5;

            ui_ld.w2=10;
            ui_ld.ts=0;
        }
        ui_ld.w1=ui_ld.n=task_->sucCnt+1;
        ui_ld.cnt=9-task_->sucCnt;

    }
    else if(task_->sucCnt<=62)
    {

    }
    else
    {
        ldz(72-task_->sucCnt);
        ui_ld.cnt=0;
    }
    if((task_->sucCnt&1)==0)
    {
        ui.num1	    =pw/10;
        ui.num2	    =pw-ui.num1*10;
        ui.dian	    =bat.dian;
    }
    new_nixie();
}

//250ms 10
void ui_kl(task* task_)
{
    if(task_->sucCnt&1)
    {
        ui.w	    =1;
        ui.u	    =0;
        ui.q	    =0;
            
        ui.ou_d	    =0;
        ui.wa	    =0;
        ui.ts	    =0;
        ui.yd	    =0;
        ui.dian     =0;
        ui.cnt      =0;
        ldz(10);

        ui.num1	    =10;
        ui.num2	    =10;
    }
    else
    {
        ui.w	    =1;
        ui.u	    =0;
        ui.q	    =0;
            
        ui.ou_d	    =0;
        ui.wa	    =0;
        ui.ts	    =0;
        ui.yd	    =1;
        ui.dian     =0;
        ui.cnt      =0;
        ldz(10);

        ui.num1	    =10;
        ui.num2	    =10;
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
            ui.w	    =1;
            ui.u	    =1;
            ui.q	    =10;
                
            ui.ou_d	    =0;
            ui.wa	    =1;
            ui.ts	    =1;
            ui.yd	    =yd;
            // ui.dian     =bat.dian;
            ui.cnt      =0;
            ldz(0);

            // ui.num1	    =10;
            // ui.num2	    =10;
        }
        ldz(task_->sucCnt+1);
    }
    else if(task_->sucCnt<=30)
    {
        //ldz(19-task_->sucCnt);
        //ui_ld.ts=10;
    }
    else if(task_->sucCnt<=40)
    {
        ldz(40-task_->sucCnt);
        ui_ld.ts=10;
    }
    else
    {
        if(task_->sucCnt==99)
        {
            ui_ld.ts=0;
        }
    }
    if(((task_->sucCnt&1)==0)&&task_->sucCnt<40)
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
    if(task_->sucCnt<=9)
    {
        if(task_->sucCnt==0)
        {
            ui.w	    =1;
            ui.u	    =1;
            ui.q	    =10;
                
            ui.ou_d	    =0;
            ui.wa	    =1;
            ui.ts	    =0;
            ui.yd	    =yd;
            // ui.dian     =bat.dian;
            ui.cnt      =0;
            ldz(0);

            // ui.num1	    =10;
            // ui.num2	    =10;
        }
        ldz(task_->sucCnt+1);
    }
    else
    {
        if(task_->sucCnt==42)
        {
            ldz(0);
        }
    }
    if((task_->sucCnt&1)==0)
    {
        ui.num1	    =pw/10;
        ui.num2	    =pw-ui.num1*10;
        ui.dian	    =bat.dian;
    }
    new_nixie();
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
        ui.w	    =1;
        ui.u	    =1;
        ui.q	    =10;
            
        ui.ou_d	    =0;
        ui.wa	    =1;
        ui.ts	    =0;
        ui.yd	    =yd;
        // ui.dian     =bat.dian;
        ui.cnt      =0;
        ldz(10);

        // ui.num1	    =10;
        // ui.num2	    =10;

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
        ui.w	    =1;
        ui.u	    =1;
        ui.q	    =10;
            
        ui.ou_d	    =1;
        ui.wa	    =1;
        ui.ts	    =1;
        ui.yd	    =1;
        ui.dian     =4;
        ui.cnt      =5;
        ldz(10);

        ui.num1	    =8;
        ui.num2	    =8;

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
        __delay_ms(20);
    }
    new_nixie();
}



