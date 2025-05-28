#include "public.h"
#include "myi2c.h"


/*************************************************************************
* 常用配置字功能说明：
//Config 1
* _FINTOSC_DIV1_1L  :  内部时钟分频选择
* _LVREN_ON_1L      :  使能LVR
* _LVT24V_1L        ： 选择LVR电压为2.4V
//Config 2
* _FLASH_CP7_OFF_2L :  7K*16~8K*16 FLASH保护位，保护后不可擦写(仅CBP为1时有效)
* _FLASH_CP6_OFF_2L :  6K*16~7K*16 FLASH保护位，保护后不可擦写(仅CBP为1时有效)
* _FLASH_CP5_OFF_2L :  5K*16~6K*16 FLASH保护位，保护后不可擦写(仅CBP为1时有效)
* _FLASH_CP4_OFF_2L :  4K*16~5K*16 FLASH保护位，保护后不可擦写(仅CBP为1时有效)
* _FLASH_CP3_OFF_2L :  3K*16~4K*16 FLASH保护位，保护后不可擦写(仅CBP为1时有效)
* _FLASH_CP2_OFF_2L ： 2K*16~3K*16 FLASH保护位，保护后不可擦写(仅CBP为1时有效)
* _FLASH_CP1_OFF_2L ： 1K*16~2K*16 FLASH保护位，保护后不可擦写(仅CBP为1时有效)
* _FLASH_CP0_OFF_2L ： 0k   ~1K*16 FLASH保护位，保护后不可擦写(仅CBP为1时有效)
* _CRYLEN_OFF_2L    ： 禁用外部低速时钟
* _CRYHEN_OFF_2L    ： 禁用外部高速时钟
* _IDIS_OFF_2L      ： 模拟IO打开，读取IO数据始终为0(模拟IO关闭，IDIS位对读取IO输入无影响)
* _CKSUM_OFF_2L     ： 使能程序校验
* _CBP_OFF_2L       :  禁用代码加密
* _RESETE_OFF_2L    ： 禁用外部复位
* _RSEL_LOW_2L      ： 端口上拉电阻为190KΩ，下拉电阻为300KΩ
* _STV_ON_2L        ： 使能堆栈溢出复位
//Config 3
* _PSUT_1_3L        ： 选择上电复位时间为 2.5ms
* _FCPU_2T_3L       ： 选择指令周期为2T模式
* _WDTEN_OFF_3L     ： 使能看门狗
* _TWDT_000_3L      :  选择看门狗溢出时间为128.4ms
//Config 4
* _OSCM_HIRC_16M_4L ： 选择内部高速时钟16MHz
* _DBG_OFF_4L       :  禁用DEBUG模式（使能后将固定PA2和PA3为DEBUG_IO）
* _ENVDDL_OFF_4L    :  低电压状态FLASH禁止读
* _BBP_OFF_4L       :  禁止保护 BOOT LOADER 的前 512bytes FLASH (默认)
* _FCMEN_OFF_4L     :  系统时钟失效监测使能位
* _IESO_OFF_4L      :  禁用双速启动模式（仅在系统时钟为外部晶振模式时有效）
* _MAPEN_ON_4L      :  IO 映射 MAP 寄存器配置使能选择
******************************************************************************/
//-----------------------------------CONCFG WROD------------------------------
__CONFIG(1,_FINTOSC_DIV1_1L     & _LVREN_ON_1L       & _LVT22V_1L                                                                                              );
__CONFIG(2,_FLASH_CP7_OFF_2L    & _FLASH_CP6_OFF_2L  & _FLASH_CP5_OFF_2L  & _FLASH_CP4_OFF_2L   & _FLASH_CP3_OFF_2L & _FLASH_CP2_OFF_2L  & _FLASH_CP1_OFF_2L  &_FLASH_CP0_OFF_2L
            &_CRYLEN_OFF_2L     & _CRYHEN_OFF_2L     & _IDIS_OFF_2L       & _CKSUM_OFF_2L      & _CBP_OFF_2L     & _RESETE_OFF_2L & _RSEL_LOW_2L & _STV_ON_2L  );
__CONFIG(3,_PSUT_1_3L           & _FCPU_2T_3L        & _WDTEN_OFF_3L      & _TWDT_000_3L                                                                       );
__CONFIG(4,_OSCM_HIRC_16M_4L    & _DBG_OFF_4L        & _ENVDDL_OFF_4L     & _BBP_OFF_4L       & _FCMEN_OFF_4L     & _IESO_OFF_4L      & _MAPEN_ON_4L           );

//==============================================================================================
// ----Function: 主函数
// --Parameters: None
// -----Returns: None
//---------Note: 该例程演示GPIO输入输出状态配置；PB0作为触发中断输入，PB1作为输出;
//				 PB0触发中断,PB1响应相应动作
//==============================================================================================

u32 temp1=1300,temp2=3900,temp3=3900;

u8 adc_ok=0;

#if  dug
        
void v(task* task_)
{
    PWM2=~PWM2;
}
#endif
void main(void)
{
    
    GPIO_Init();//IO口初始化
    fvr_init();
    dac_init();
    cmp_init();
    task_init();
    timer1_init();


	aip33626_init();
    #if dug
    uart_init();
    #endif
    smo_det_init(); 


    aip33626_task_id=add_task_id(aip33626_sys_begin_id1,aip33626_sys_begin_id2,
        aip33626_sys_begin_tim,aip33626_sys_begin_maxcnt,0);
    si_mic_task_id=add_task_id(si_mic_task_id1,si_mic_task_id2,
        si_mic_task_tim,si_mic_task_maxcnt,1);
    key_task_id=add_task(key_task_id1,key_task_id2,
        key_task_tim,key_task_maxcnt);
    key_timer_id=add_task(key_timer_task_id1,key_timer_task_id2,
        key_timer_task_tim,key_timer_task_maxcnt);
    smo_det_task_id=add_task(smo_det_task_id1,smo_det_task_id2,
        smo_det_task_tim,smo_det_task_maxcnt);
    chrg_task_id=add_task(chrg_task_id1,chrg_task_id2,
        chrg_task_tim,chrg_task_maxcnt);


    bat_task_id=add_task(bat_task_id1,bat_task_id2,
        bat_task_tim,bat_task_maxcnt);
    sleep_task_id=add_task(sleep_task_id1,sleep_task_id2,
        sleep_task_tim,sleep_task_maxcnt);

    while (1)
    {
        task_loop();
        #if pwm_bug
        if(pwm_task_id)
        {
            pwm_task_id=0;
            pwm_task();
        }
        #endif
        if(adc_ok)
        {
            adc_ok=0;
            temp1=((ADRESH&0x0f)<<8)|ADRESL;
            temp2=((ADRESH1&0x0f)<<8)|ADRESL1;
            temp3=((ADRESH2&0x0f)<<8)|ADRESL2;
            if((temp2<3950 )||(temp3<3950 ))
            {
                dl0_flag=1;
                duty0=0;
                duty1=0;
                dl_init=1;
            }
        }
        // if(sleep_flag)
        // {
        //     sleep_flag=0;
        //     sleep_mode();
                    
        //     // GPIO_Init();//IO口初始化
        //     // fvr_init();
        //     // dac_init();
        //     // cmp_init();
        //     // timer1_init();
        //     // aip33626_init();
        //     // #if dug
        //     // uart_init();
        //     // #endif
        // }
	
    }

}

//高优先级中断服务函数
void interrupt ISR_h (void)
{
//进入中断后系统自动关闭中断
    
    if(CMP1IF &&CMP1IE)
    {
        CMP1IF=0;
        if(CMP1OUT)
        {
            PWM2=1;
            dl1_flag=1;
            duty0=0;
            duty1=0;
            dl_init=1;
            #if dug
            uart_txln("dl 1");
            #endif
            
        }
    }    
    if(CMP0IF&&CMP0IE)
    {
        CMP0IF=0;
       if(CMP0OUT)
        {
            PWM1=1;
            dl0_flag=1;
            duty0=0;
            duty1=0;
            dl_init=1;
            
            #if dug
            uart_txln("dl 0");
            #endif
        }
    }
    
    if((TMR1IF==1)  && (TMR1IE==1) )//8ms 一直开
	{
		TMR1IF = 0; //清除PB中断标志位
        task_isr();

        #if pwm_bug
        pwm_task_id=1;
        #else
        pwm_task();
        
        #endif
        // if(T1CON0==0xb3)
        // {
        //     sleep_cnt++;
        //     sleep_flag=1;
        // }
	}
    if((TMR0IF==1)  && (TMR0IE==1))//8ms自动关
	{
		TMR0IF = 0; 
        timer0_isr();
        
	}
    if((TMR2IF==1) && (TMR2IE==1))//自动关
    {
        TMR2IF = 0;
        cmp0_off();
        PWM1=1;
        TMR2ON=0;

    }
    if((TMR3IF==1) && (TMR3IE==1))//自动关
    {
        TMR3IF = 0;
        cmp1_off();
        PWM2=1;
        TMR3ON=0;
    }
    if(ADIE && ADIF)
    {
        ADIF=0;
        adc_ok=1;
    }
    if((PAIE == 1) && (PAIF == 1))
    {
        int_close();

    }
    if(PBIE&&PBIF)
    {
        int_close();
    }
    if((PDIE == 1) && (PDIF == 1))
    {
        int_close();
    }
    if(PCIE&&PCIF)
    {
        int_close();
    }
}

//低优先级中断服务函数
void interrupt low_priority ISR_l (void)
{
//进入中断后系统自动关闭中断

}


