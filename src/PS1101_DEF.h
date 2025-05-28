//===========================================================================================================
// Project: PS1101 DEMO CODE
// Original Author: FAE - luojiao
// Ver: V0.0.1   2024-10-23  1.first version
// 
// 
//===========================================================================================================

#ifndef __PS1101_DEF_H
#define __PS1101_DEF_H

//======= OSCCON define============
#define ICE_TMEREN_ON           0x80
#define ICE_TMEREN_OFF          0x00
#define FINTOSC_DIV1            (0x07 << 4)
#define FINTOSC_DIV2            (0x06 << 4)
#define FINTOSC_DIV4            (0x05 << 4)
#define FINTOSC_DIV8            (0x04 << 4)
#define FINTOSC_DIV16           (0x02 << 4)
#define SIG_EN                  0x08
#define SIG_DIS                 0x00
#define CKOE_PB0_OUT_EN         0x04
#define CKOE_PB0_OUT_DIS        0x00
#define OSCF_16M                0x02
#define OSCF_32K                0x00
#define OSCM_16M                0x01
#define OSCM_32K                0x00

//======= PCON define============
#define IP_EN					0x80
#define IP_DIS				    0x00
#define PLL_32M		    		0x40 //时钟倍频选择
#define PLL_16M			        0X00	
#define PREDIV_WDT_DIS1			(0x00 << 1)	
#define PREDIV_WDT_DIS2			(0x01 << 1)		
#define PREDIV_WDT_DIS3			(0x02 << 1)		
#define PREDIV_WDT_DIS4			(0x03 << 1)	
#define PREDIV_WDT_DIS5			(0x04 << 1)		
#define PREDIV_WDT_DIS6			(0x05 << 1)	
#define PREDIV_WDT_DIS7			(0x06 << 1)	
#define PREDIV_WDT_DIS8			(0x07 << 1)		
#define WDT_EN				    0X01
#define WDT_DIS 				0X00
//======= RCON define============

//======= IOCUR define============
#define IOCUR7_10mA				0x00//PC2
#define IOCUR7_30mA				0x80//PC2
#define IOCUR6_10mA				0x00//PC0 PC1
#define IOCUR6_30mA				0x40//PC0 PC1
#define IOCUR5_10mA				0x00//PA4 PA5
#define IOCUR5_30mA				0x20//PA4 PA5
#define IOCUR4_10mA				0x00//PC6 PA3
#define IOCUR4_30mA				0x10//PC6 PA3
#define IOCUR3_10mA				0x00//PA1 PA2
#define IOCUR3_30mA				0x08//PA1 PA2
#define IOCUR2_10mA				0x00//PB1 PA0
#define IOCUR2_30mA				0x04//PB1 PA0
#define IOCUR1_10mA				0x00//PB2 PB0
#define IOCUR1_30mA				0x02//PB2 PB0
#define IOCUR0_10mA				0x00//PC3 PC4 PC5 PB3 PB4 PB5
#define IOCUR0_30mA				0x01//PC3 PC4 PC5 PB3 PB4 PB5

//======= T0CON define============
#define BUZZER_EN				0x80
#define BUZZER_DIS				0x00
#define	T0CS_CPU				(0x00 << 5)
#define	T0CS_T0CKI_PA1			(0x01 << 5)
#define	T0CS_32K				(0x02 << 5)
#define	T0CS_CMP0OUT			(0x03 << 5)
#define T0SE_FALLEDGE			0x10
#define T0SE_RISEEDGE			0x00
#define PSA_EN					0x00
#define PSA_DIS					0x08
#define T0CKPS_DIV2				0x00
#define T0CKPS_DIV4				0x01
#define T0CKPS_DIV8				0x02
#define T0CKPS_DIV16			0x03
#define T0CKPS_DIV32			0x04
#define T0CKPS_DIV64			0x05
#define T0CKPS_DIV128			0x06
#define T0CKPS_DIV256			0x07

//======= T1CON0 define============
#define T1CK_FCPU				(0x00 << 6)
#define T1CK_T1CKI_PC2			(0x01 << 6)
#define T1CK_32K				(0x02 << 6)
#define T1CK_CMP1OUT			(0x03 << 6)
#define T1ADC_EN                0x02
#define T1ADC_DIS               0x00
#define T1CKPS_DIV1				(0x00 << 2)
#define T1CKPS_DIV2				(0x01 << 2)
#define T1CKPS_DIV4				(0x02 << 2)
#define T1CKPS_DIV8				(0x03 << 2)
#define T1CKPS_DIV16			(0x04 << 2)
#define T1CKPS_DIV32			(0x05 << 2)
#define T1CKPS_DIV64			(0x06 << 2)
#define T1CKPS_DIV128			(0x07 << 2)
#define T1SYNC_DIS				0x02
#define T1SYNC_EN				0x00
#define TM1_ON					0x01
#define TM1_OFF					0x00
//======= T1CON1 define============
#define T1CAP_FALLEDGE			0x40
#define T1CAP_RISEEDGE			0x00
#define T1CH0_PA0				(0x00 << 2)
#define T1CH1_PB1				(0x01 << 2)
#define T1CH2_PB3				(0x02 << 2)
#define T1CH3_PB4				(0x03 << 2)
#define T1CH4_PC2				(0x04 << 2)
#define T1CH5_PC1				(0x05 << 2)
#define T1CH6_PC0				(0x06 << 2)
#define T1CH7_PA5				(0x07 << 2)
#define T1CH8_PA4				(0x08 << 2)
#define T1CH9_PA3				(0x09 << 2)
#define T1CH10_PC6				(0x0A << 2)
#define T1CH11_PA2				(0x0B << 2)
#define T1CH12_PA1				(0x0C << 2)
#define T1CH13_OSC32K			(0x0D << 2)
#define T1CH14_CMP0OUT			(0x0E << 2)
#define T1CH15_CMP1OUT			(0x0F << 2)
#define T1M_MODE_ORDINARY       0x00
#define T1M_MODE_CAPTURE1       0x01
#define T1M_MODE_CAPTURE2       0x02
#define T1M_MODE_CAPTURE3       0x03

//======= T2CON0 define============
#define T2OUTPS(x)              ((x-1) << 3)  //x:分频选择，x取值范围：1~32
#define TM2_ON					0x04
#define TM2_OFF					0x00
#define T2CKPS_DIV1				0x00
#define T2CKPS_DIV4				0x01
#define T2CKPS_DIV16			0x02
#define T2CKPS_DIV64			0x03
//======= T2CON1 define============
#define INT2_RISEEDGE			0x00//上升沿
#define INT2_FALLEDGE			0x80//下降沿
#define INT1_RISEEDGE			0x00
#define INT1_FALLEDGE			0x40
#define INT0_RISEEDGE			0x00
#define INT0_FALLEDGE			0x20
#define CMP1POSE_FORWARD        0x00
#define CMP1POSE_REVERSE        0x10
#define CMP0POSE_FORWARD        0x00
#define CMP0POSE_REVERSE        0x08
#define CMPCLK_CS_FCPU          0x00
#define CMPCLK_CS_OSC32K        0x04
#define T2M_MODE_ORDINARY       0x00//Timer2 工作在定时模式
#define T2M_MODE_PWMEDGE        0x02//Timer2 PWM 工作在普通边沿模式
#define T2M_MODE_PWMCENTER      0x03//Timer2 PWM 工作在中心对齐模式
//======= DTC define============
#define DTCKS_FSYS_1            (0x00 << 6)
#define DTCKS_FSYS_4            (0x01 << 6)
#define DTCKS_FSYS_16           (0x02 << 6)
#define DTCKS_FSYS_64           (0x03 << 6)
//======= POLS define============
#define PWM_MUX_00              (0x00 << 6)//PWM20,PWM21 映射至 PC3,PC4;PWM22,PWM23 映射至 PC5,PB5;PWM24,PWM25 映射至 PB4,PB3;
#define PWM_MUX_01              (0x01 << 6)//PWM20,PWM21 映射至 PC3,PC4;PWM22,PWM23 映射至 PC5,PB5;PWM24,PWM25 映射至 PB2,PB0;
#define PWM_MUX_10              (0x02 << 6)//PWM20,PWM21 映射至 PB1,PA0;PWM22,PWM23 映射至 PA1,PA2;PWM24,PWM25 映射至 PA4,PA5;
#define PWM_MUX_11              (0x03 << 6)//PWM20,PWM21 映射至 PC0,PC1;PWM22,PWM23 映射至 PC2,PC3;PWM24,PWM25 映射至 PC4,PC5;
#define HBPWM25_INVERTING       0x20//反相输出
#define HBPWM25_NON_INVERTING   0x00//同相输出
#define HBPWM24_INVERTING       0x10
#define HBPWM24_NON_INVERTING   0x00
#define HBPWM23_INVERTING       0x08
#define HBPWM23_NON_INVERTING   0x00
#define HBPWM22_INVERTING       0x04
#define HBPWM22_NON_INVERTING   0x00
#define HBPWM21_INVERTING       0x02
#define HBPWM21_NON_INVERTING   0x00
#define HBPWM20_INVERTING       0x01
#define HBPWM20_NON_INVERTING   0x00

//======= PME define============
#define UART_MUX_PC0_PC1        0x80
#define UART_MUX_PA1_PA2        0x00
#define DT_EN                   0x40
#define DT_DIS                  0x00
#define HBPWMOE25_EN            0x20
#define HBPWMOE25_DIS           0x00
#define HBPWMOE24_EN            0x10
#define HBPWMOE24_DIS           0x00
#define HBPWMOE23_EN            0x08
#define HBPWMOE23_DIS           0x00
#define HBPWMOE22_EN            0x04
#define HBPWMOE22_DIS           0x00
#define HBPWMOE21_EN            0x02
#define HBPWMOE21_DIS           0x00
#define HBPWMOE20_EN            0x01
#define HBPWMOE20_DIS           0x00
//======= HBCON define============
#define CMP1FLT_EN              0x80
#define CMP1FLT_DIS             0x00
#define CMP0FLT_EN              0x40
#define CMP0FLT_DIS             0x00
#define PWM_ASTART_EN           0x20
#define PWM_ASTART_DIS          0x00
#define PWM_ACLOSE_EN           0x10
#define PWM_ACLOSE_DIS          0x00
#define PWMAD_EN                0x08
#define PWMAD_DIS               0x00
#define PWMADPOS_MODE1X         (0x02 << 1)
#define PWMADPOS_MODE01         (0x01 << 1)
#define PWMADPOS_MODE00         (0x00 << 1)

//======= T3CON0 define============
#define T3OUTPS(x)              ((x-1) << 3)  //x:分频选择，x取值范围：1~32
#define TM3_ON					0x04
#define TM3_OFF					0x00
#define T3CKPS_DIV1				0x00
#define T3CKPS_DIV4				0x01
#define T3CKPS_DIV16			0x02
#define T3CKPS_DIV64			0x03
//======= T3CON1 define============
#define TMR3GE_EN               0x80
#define TMR3GE_DIS              0x00
#define T3GPOL_HIGH             0x40
#define T3GPOL_LOW              0x00
#define T3GTM_EN                0x20
#define T3GTM_DIS               0x00


#define T3GCK_PC0               0x00
#define T3GCK_PC1               0x01
#define T3GCK_CMP0              0x02
#define T3GCK_CMP1              0x03

//======= UARTCON define============
#define UART_PORT_EN			0x80
#define UART_PORT_DIS			0x00
#define UART_MODE9_EN			0x40
#define UART_MODE9_DIS			0x00
#define UART_HALFDUPLEX_EN		0x20
#define UART_HALFDUPLEX_DIS		0x00
#define UART_TX_EN				0x10
#define UART_TX_DIS				0x00
#define UART_BRG_DIV64			0x00
#define UART_BRG_DIV16			0x04
#define UART_BRG_DIV4			0x08
#define UART_BRG_DIV2			0x0C
#define UART_9BIT				0x02
#define UART_8BIT				0x00
#define UART_BUSY				0x01
#define UART_IDLE				0x00

//======= FVRCON define============
#define FVR_SEL_1V2             (0X00 << 4)
#define FVR_SEL_DACOUT          (0X01 << 4)
#define FVR_SEL_NTC             (0X02 << 4)
#define FVR_PG1                 (0X01 << 1)
#define FVR_PG2                 (0X02 << 1)
#define FVR_PG3                 (0X03 << 1)
#define FVR_EN                  0X01
#define FVR_DIS                 0X00

//======= ADCON0 define============
#define ADFM_LEFT               0x80
#define ADFM_RIGHT              0x00
#define ADC_PC6                 (0x00 << 2)
#define ADC_PC5                 (0x01 << 2)
#define ADC_PA1                 (0x02 << 2)
#define ADC_PA0                 (0x03 << 2)
#define ADC_PB0                 (0x04 << 2)
#define ADC_PB1                 (0x05 << 2)
#define ADC_PB5                 (0x06 << 2)
#define ADC_PC1                 (0x07 << 2)
#define ADC_PC0                 (0x08 << 2)
#define ADC_PC4                 (0x09 << 2)
#define ADC_PB2                 (0x0A << 2)
#define ADC_PC3                 (0x0B << 2)
#define ADC_PA5                 (0x0C << 2)
#define ADC_GND                 (0x0D << 2)
#define ADC_FVR                 (0x0E << 2)
#define ADC_1_4_VDD             (0x0F << 2)
#define ADC_EN                  0x01    
#define ADC_DIS                 0x00             
//======= ADCON1 define============
#define ADVREF_FVR              0x00
#define ADVREF_VDD              0x40
#define ACQT_15                 (0x07 << 3)
#define ACQT_13                 (0x06 << 3)
#define ACQT_11                 (0x05 << 3)
#define ACQT_9                  (0x04 << 3)
#define ACQT_7                  (0x03 << 3)
#define ACQT_5                  (0x02 << 3)
#define ACQT_3                  (0x01 << 3)
#define ACQT_1                  (0x00 << 3)
#define ADCS_OSC32K             0X07
#define ADCS_FSYS_64            0X06
#define ADCS_FSYS_16            0X05
#define ADCS_FSYS_4             0X04
#define ADCS_FSYS_32            0X02
#define ADCS_FSYS_8             0X01
#define ADCS_FSYS_2             0X00

//======= DACCON define============
#define DAC_SEL_VDD             0X80
#define DAC_SEL_FVR             0X00
#define DAC_EN                  0X40
#define DAC_CS00                0X00
#define DAC_CS01                0X10
#define DAC_CS10                0X20
#define DAC_CS11                0X30


//======= CMP0CON0 define============
#define CMP0_EN                 0X80
#define CMP0_OUT                0X40
#define CMP0PCH_PC1             (0<<3)
#define CMP0PCH_PB0             (1<<3)
#define CMP0PCH_PC5             (2<<3)
#define CMP0PCH_PB2             (3<<3)
#define CMP0PCH_PB4             (4<<3)
#define CMP0PCH_PB3             (5<<3)
#define CMP0PCH_FVR             (6<<3)
#define CMP0PCH_DAC             (7<<3)
#define CMP0NCH_PC0             0
#define CMP0NCH_PB1             1
#define CMP0NCH_PA1             2
#define CMP0NCH_PC4             3
#define CMP0NCH_PA4             4   
#define CMP0NCH_PA5             5  
#define CMP0NCH_FVR             6   
#define CMP0NCH_DAC             7
//======= CMP0CON1 define============
#define CMPPOSE_FORWARD         0
#define CMPPOSE_REVERSE         1
#define CMPCLK_FCPU             0
#define CMPCLK_OSC32K           1
#define CMPFILTER               (15 << 4)

#define CMP0INT_DIS             (0 << 2)//不产生中断
#define CMP0INT_RISEEDGE        (1 << 2)//上升沿触发中断
#define CMP0INT_FALLEDGE        (2 << 2)//下降沿触发中断
#define CMP0INT_DOUBLEEDGE      (3 << 2)//双沿触发中断
#define CMP0OUT_PA2_EN           0x02
#define CMP0OUT_DIS              0x00
#define CMP0HYS_EN               0x01//迟滞使能
//======= CMP1CON0 define============
#define CMP1_EN             0X80
#define CMP1_OUT            0X40
#define CMP1PCH_PC1         (0<<3)
#define CMP1PCH_PB0         (1<<3)
#define CMP1PCH_PC5         (2<<3)
#define CMP1PCH_PB2         (3<<3)
#define CMP1PCH_PB4         (4<<3)
#define CMP1PCH_PB3         (5<<3)
#define CMP1PCH_FVR         (6<<3)
#define CMP1PCH_DAC         (7<<3)
#define CMP1NCH_PC0         0
#define CMP1NCH_PB1         1
#define CMP1NCH_PA1         2
#define CMP1NCH_PC4         3
#define CMP1NCH_PA2         4   
#define CMP1NCH_PA3         5  
#define CMP1NCH_FVR         6   
#define CMP1NCH_DAC         7
//======= CMP1CON1 define============
#define CMP1INT_DIS               (0 << 2)//不产生中断
#define CMP1INT_RISEEDGE          (1 << 2)//上升沿触发中断
#define CMP1INT_FALLEDGE          (2 << 2)//下降沿触发中断
#define CMP1INT_DOUBLEEDGE        (3 << 2)//双沿触发中断
#define CMP1OUT_PA3_EN             0x02
#define CMP1OUT_DIS                0x00
#define CMP1HYS_EN                 0x01

#endif