//*************************************************************************************
//#Project  :PS1101
//#Version  :v1
//#DATE     :20241009
//-------------------------change list-------------------------------------------------
//===============================================================================
//--Version.----------------Content---------------------------------------------Who---
//============================================================
//|-1 -|- initial version                                                                                       

//***********************************************************


#ifndef	__PS1101_H
#define	__PS1101_H


#define _XTAL_FREQ 16000000
#pragma intrinsic(_delay)
extern __nonreentrant void _delay(unsigned long);
/*
#pragma intrinsic(_delaywdt)
extern __nonreentrant void _delaywdt(unsigned long);
*/

#define __delay_us(x) _delay((unsigned long)((x)*(_XTAL_FREQ/4000000)))
#define __delay_ms(x) _delay((unsigned long)((x)*(_XTAL_FREQ/4000.0)))

#define SLEEP_PWDEEP()      SMCR = 0X05; SLEEP();NOP()
#define SLEEP_PWOFF()       SMCR = 0X07; SLEEP();NOP()


/*


__CONFIG(1,_FINTOSC_DIV16_1L     & _FCPU_4T_1L          & _SMT_SMV_1L     & _LVREN_OFF_1L    & _LVR24V_1L  );
__CONFIG(2,_DBGEN_I2C_ON_2L      & _DBGEN_UART_00_2L    & _RESETE_OFF_2L  & _WDTE_OFF_2L     & _TWDT_111_2L   );

*/


static volatile unsigned char	TOSU                    @0xfff;
static volatile unsigned char	TOSH                    @0xffe;
static volatile unsigned char	TOSL                    @0xffd;
static volatile unsigned char	STKPTR                  @0xffc;
static volatile unsigned char	PCLATU                  @0xffb;
static volatile unsigned char	PLCATH                  @0xffa;
static volatile unsigned char	PCL                     @0xff9;
static volatile unsigned char	TBLPTRU                 @0xff8;
static volatile unsigned char	TBLPTRH                 @0xff7;
static volatile unsigned char	TBLPTRL                 @0xff6;
static volatile unsigned char	TABLAT                  @0xff5;
static volatile unsigned char	PRODH                   @0xff4;
static volatile unsigned char	PRODL                   @0xff3;
static volatile unsigned char	INTCON                  @0xff2;
/*Definitions for INTCON register*/
static volatile bit	 GIE                          @((unsigned)&INTCON*8)+7;
static volatile bit	 GIEH                         @((unsigned)&INTCON*8)+7;
static volatile bit	 GIEL                         @((unsigned)&INTCON*8)+6;
static volatile bit	 PEIE                         @((unsigned)&INTCON*8)+6;


static volatile unsigned char	PCON                    @0xff1;
/*Definitions for PCON register*/
static volatile bit	 IPEN                         @((unsigned)&PCON*8)+7;
static volatile bit	 PLL                          @((unsigned)&PCON*8)+6;
static volatile bit	 PREDIV2                      @((unsigned)&PCON*8)+3;
static volatile bit	 PREDIV1                      @((unsigned)&PCON*8)+2;
static volatile bit	 PREDIV0                      @((unsigned)&PCON*8)+1;
static volatile bit	 WDTEN                        @((unsigned)&PCON*8)+0;


static volatile unsigned char	OSCCON                  @0xff0;
/*Definitions for OSCCON register*/
static volatile bit	 ICE_TRMEN                    @((unsigned)&OSCCON*8)+7;
static volatile bit	 FINTOSC2                     @((unsigned)&OSCCON*8)+6;
static volatile bit	 FINTOSC1                     @((unsigned)&OSCCON*8)+5;
static volatile bit	 FINTOSC0                     @((unsigned)&OSCCON*8)+4;
static volatile bit	 SIGS                         @((unsigned)&OSCCON*8)+3;
static volatile bit	 CKOE                         @((unsigned)&OSCCON*8)+2;
static volatile bit	 OSCF                         @((unsigned)&OSCCON*8)+1;
static volatile bit	 OSCM                         @((unsigned)&OSCCON*8)+0;


static volatile unsigned char	INDF                    @0xfef;
static volatile unsigned char	POSTINC0                @0xfee;
static volatile unsigned char	POSTDEC0                @0xfed;
static volatile unsigned char	PREINC0                 @0xfec;
static volatile unsigned char	PLUSW0                  @0xfeb;
static volatile unsigned char	FSR0H                   @0xfea;
static volatile unsigned char	FSR0L                   @0xfe9;
static volatile unsigned char	WREG                    @0xfe8;
static volatile unsigned char	INDF1                   @0xfe7;
static volatile unsigned char	POSTINC1                @0xfe6;
static volatile unsigned char	POSTDEC1                @0xfe5;
static volatile unsigned char	PREINC1                 @0xfe4;
static volatile unsigned char	PLUSW1                  @0xfe3;
static volatile unsigned char	FSR1H                   @0xfe2;
static volatile unsigned char	FSR1L                   @0xfe1;
static volatile unsigned char	BSR                     @0xfe0;
static volatile unsigned char	INDF2                   @0xfdf;
static volatile unsigned char	POSTINC2                @0xfde;
static volatile unsigned char	POSTDEC2                @0xfdd;
static volatile unsigned char	PREINC2                 @0xfdc;
static volatile unsigned char	PLUSW2                  @0xfdb;
static volatile unsigned char	FSR2H                   @0xfda;
static volatile unsigned char	FSR2L                   @0xfd9;
static volatile unsigned char	STATUS                  @0xfd8;
/*Definitions for STATUS register*/
static volatile bit	 N                            @((unsigned)&STATUS*8)+4;
static volatile bit	 OV                           @((unsigned)&STATUS*8)+3;
static volatile bit	 Z                            @((unsigned)&STATUS*8)+2;
static volatile bit	 DC                           @((unsigned)&STATUS*8)+1;
static volatile bit	 C                            @((unsigned)&STATUS*8)+0;


static volatile unsigned char	T0CON                  @0xfd7;
/*Definitions for T0CON0 register*/
static volatile bit	 T0OUT                        @((unsigned)&T0CON*8)+7;
static volatile bit	 T0CS1                        @((unsigned)&T0CON*8)+6;
static volatile bit	 T0CS0                        @((unsigned)&T0CON*8)+5;
static volatile bit	 T0SE                         @((unsigned)&T0CON*8)+4;
static volatile bit	 PSA                          @((unsigned)&T0CON*8)+3;
static volatile bit	 PS2                          @((unsigned)&T0CON*8)+2;
static volatile bit	 PS1                          @((unsigned)&T0CON*8)+1;
static volatile bit	 PS0                          @((unsigned)&T0CON*8)+0;

static volatile unsigned char	PR0                     @0xfd6;
static volatile unsigned char	TMR0                    @0xfd5;
static volatile unsigned char	SMCR                    @0xfd4;
/*Definitions for SMCR register*/
static volatile bit	 SM2                          @((unsigned)&SMCR*8)+3;
static volatile bit	 SM1                          @((unsigned)&SMCR*8)+2;
static volatile bit	 SM0                          @((unsigned)&SMCR*8)+1;
static volatile bit	 SE                           @((unsigned)&SMCR*8)+0;


static volatile unsigned char	FVRCON                  @0xfd3;
/*Definitions for FVRCON register*/
static volatile bit	 FVR_SEL2                     @((unsigned)&FVRCON*8)+5;
static volatile bit	 FVR_SEL1                     @((unsigned)&FVRCON*8)+4;
static volatile bit	 FVR_SEL0                     @((unsigned)&FVRCON*8)+3;
static volatile bit	 FVROUTEN                     @((unsigned)&FVRCON*8)+3;
static volatile bit	 FVRPGA1                      @((unsigned)&FVRCON*8)+2;
static volatile bit	 FVRPGA0                      @((unsigned)&FVRCON*8)+1;
static volatile bit	 FVREN                        @((unsigned)&FVRCON*8)+0;


static volatile unsigned char	RCON                    @0xfd2;
/*Definitions for RCON register*/
static volatile bit	 IRFEN                        @((unsigned)&RCON*8)+7;
static volatile bit	 STVREN                       @((unsigned)&RCON*8)+6;
static volatile bit	 RSTF1                        @((unsigned)&RCON*8)+5;
static volatile bit	 RSTF0                        @((unsigned)&RCON*8)+4;
static volatile bit	 TO                           @((unsigned)&RCON*8)+3;
static volatile bit	 PD                           @((unsigned)&RCON*8)+2;
static volatile bit	 POR                          @((unsigned)&RCON*8)+1;
static volatile bit	 BOR                          @((unsigned)&RCON*8)+0;


static volatile unsigned char	TMR1H                   @0xfd1;
static volatile unsigned char	TMR1L                   @0xfd0;
static volatile unsigned int	TMR1                    @0xfd0;

static volatile unsigned char	PR1H                    @0xfcf;
static volatile unsigned char	PR1L                    @0xfce;
static volatile unsigned int	PR1                     @0xfce;

static volatile unsigned char	T1CON0                  @0xfcd;
/*Definitions for T1CON0 register*/
static volatile bit	 T1CK1                        @((unsigned)&T1CON0*8)+7;
static volatile bit	 T1CK0                        @((unsigned)&T1CON0*8)+6;
static volatile bit	 T1ADCEN                      @((unsigned)&T1CON0*8)+5;
static volatile bit	 T1CKPS2                      @((unsigned)&T1CON0*8)+4;
static volatile bit	 T1CKPS1                      @((unsigned)&T1CON0*8)+3;
static volatile bit	 T1CKPS0                      @((unsigned)&T1CON0*8)+2;
static volatile bit	 T1SYNC                       @((unsigned)&T1CON0*8)+1;
static volatile bit	 TMR1ON                       @((unsigned)&T1CON0*8)+0;


static volatile unsigned char	T1CON1                  @0xfcc;
/*Definitions for T1CON1 register*/
static volatile bit	 T1CAP_EDGE                   @((unsigned)&T1CON1*8)+6;
static volatile bit	 T1CH3                        @((unsigned)&T1CON1*8)+5;
static volatile bit	 T1CH2                        @((unsigned)&T1CON1*8)+4;
static volatile bit	 T1CH1                        @((unsigned)&T1CON1*8)+3;
static volatile bit	 T1CH0                        @((unsigned)&T1CON1*8)+2;
static volatile bit	 T1M1                         @((unsigned)&T1CON1*8)+1;
static volatile bit	 T1M0                         @((unsigned)&T1CON1*8)+0;


static volatile unsigned char	TMR2                    @0xfca;
static volatile unsigned char	PR2                     @0xfc8;
static volatile unsigned char	DUTY20                   @0xfc6;
static volatile unsigned char	DUTY22                  @0xfc4;
static volatile unsigned char	DUTY24                  @0xfc2;

static volatile unsigned char	T2CON0                  @0xfc1;
/*Definitions for T2CON0 register*/
static volatile bit	 T2OUTPS4                     @((unsigned)&T2CON0*8)+7;
static volatile bit	 T2OUTPS3                     @((unsigned)&T2CON0*8)+6;
static volatile bit	 T2OUTPS2                     @((unsigned)&T2CON0*8)+5;
static volatile bit	 T2OUTPS1                     @((unsigned)&T2CON0*8)+4;
static volatile bit	 T2OUTPS0                     @((unsigned)&T2CON0*8)+3;
static volatile bit	 TMR2ON                       @((unsigned)&T2CON0*8)+2;
static volatile bit	 T2CKPS1                      @((unsigned)&T2CON0*8)+1;
static volatile bit	 T2CKPS0                      @((unsigned)&T2CON0*8)+0;


static volatile unsigned char	T2CON1                  @0xfc0;
/*Definitions for T2CON1 register*/
static volatile bit	 INT2EDGE                     @((unsigned)&T2CON1*8)+7;
static volatile bit	 INT1EDGE                     @((unsigned)&T2CON1*8)+6;
static volatile bit	 INT0EDGE                     @((unsigned)&T2CON1*8)+5;
static volatile bit	 CMP1POSE                     @((unsigned)&T2CON1*8)+4;
static volatile bit	 CMP0POSE                     @((unsigned)&T2CON1*8)+3;
static volatile bit	 CMPCLK_CS                    @((unsigned)&T2CON1*8)+2;
static volatile bit	 T2M1                         @((unsigned)&T2CON1*8)+1;
static volatile bit	 T2M0                         @((unsigned)&T2CON1*8)+0;


static volatile unsigned char	DTC                     @0xfbf;
/*Definitions for DTC register*/
static volatile bit	 DTCKS1                       @((unsigned)&DTC*8)+7;
static volatile bit	 DTCKS0                       @((unsigned)&DTC*8)+6;
static volatile bit	 DTD5                         @((unsigned)&DTC*8)+5;
static volatile bit	 DTD4                         @((unsigned)&DTC*8)+4;
static volatile bit	 DTD3                         @((unsigned)&DTC*8)+3;
static volatile bit	 DTD2                         @((unsigned)&DTC*8)+2;
static volatile bit	 DTD1                         @((unsigned)&DTC*8)+1;
static volatile bit	 DTD0                         @((unsigned)&DTC*8)+0;


static volatile unsigned char	POLS                    @0xfbe;
/*Definitions for POLS register*/
static volatile bit	 PWM_MUX1                     @((unsigned)&POLS*8)+7;
static volatile bit	 PWM_MUX0                     @((unsigned)&POLS*8)+6;
static volatile bit	 HBPOLS21                     @((unsigned)&POLS*8)+5;
static volatile bit	 HBPOLS20                     @((unsigned)&POLS*8)+4;
static volatile bit	 HBPOLS11                     @((unsigned)&POLS*8)+3;
static volatile bit	 HBPOLS10                     @((unsigned)&POLS*8)+2;
static volatile bit	 HBPOLS01                     @((unsigned)&POLS*8)+1;
static volatile bit	 HBPOLS00                     @((unsigned)&POLS*8)+0;


static volatile unsigned char	PME                     @0xfbd;
/*Definitions for PME register*/
static volatile bit	 UART_MUX                     @((unsigned)&PME*8)+7;
static volatile bit	 DTEN                         @((unsigned)&PME*8)+6;
static volatile bit	 HBPWMOE21                    @((unsigned)&PME*8)+5;
static volatile bit	 HBPWMOE20                    @((unsigned)&PME*8)+4;
static volatile bit	 HBPWMOE11                    @((unsigned)&PME*8)+3;
static volatile bit	 HBPWMOE10                    @((unsigned)&PME*8)+2;
static volatile bit	 HBPWMOE01                    @((unsigned)&PME*8)+1;
static volatile bit	 HBPWMOE00                    @((unsigned)&PME*8)+0;


static volatile unsigned char	HBCON                   @0xfbc;
/*Definitions for HBCON register*/
static volatile bit	 CMP1FLT                      @((unsigned)&HBCON*8)+7;
static volatile bit	 CMP0FLT                      @((unsigned)&HBCON*8)+6;
static volatile bit	 ASTART                       @((unsigned)&HBCON*8)+5;
static volatile bit	 ACLOSE                       @((unsigned)&HBCON*8)+4;
static volatile bit	 PWMADEN                      @((unsigned)&HBCON*8)+3;
static volatile bit	 PWMADPOS1                    @((unsigned)&HBCON*8)+2;
static volatile bit	 PWMADPOS0                    @((unsigned)&HBCON*8)+1;



static volatile unsigned char	PWM2ADDLY               @0xfbb;
/*Definitions for PWM2ADDLY register*/
static volatile bit	 PWM2ADDLY7                   @((unsigned)&PWM2ADDLY*8)+7;
static volatile bit	 PWM2ADDLY6                   @((unsigned)&PWM2ADDLY*8)+6;
static volatile bit	 PWM2ADDLY5                   @((unsigned)&PWM2ADDLY*8)+5;
static volatile bit	 PWM2ADDLY4                   @((unsigned)&PWM2ADDLY*8)+4;
static volatile bit	 PWM2ADDLY3                   @((unsigned)&PWM2ADDLY*8)+3;
static volatile bit	 PWM2ADDLY2                   @((unsigned)&PWM2ADDLY*8)+2;
static volatile bit	 PWM2ADDLY1                   @((unsigned)&PWM2ADDLY*8)+1;
static volatile bit	 PWM2ADDLY0                   @((unsigned)&PWM2ADDLY*8)+0;


static volatile unsigned char	TMR3                     @0xfba;
static volatile unsigned char	PR3                      @0xfb9;
static volatile unsigned char	T3CON0                   @0xfb8;
/*Definitions for T3CON0 register*/
static volatile bit	 T3OUTPS4                        @((unsigned)&T3CON0*8)+7;
static volatile bit	 T3OUTPS3                        @((unsigned)&T3CON0*8)+6;
static volatile bit	 T3OUTPS2                        @((unsigned)&T3CON0*8)+5;
static volatile bit	 T3OUTPS1                        @((unsigned)&T3CON0*8)+4;
static volatile bit	 T3OUTPS0                        @((unsigned)&T3CON0*8)+3;
static volatile bit	 TMR3ON                          @((unsigned)&T3CON0*8)+2;
static volatile bit	 T3CKPS1                         @((unsigned)&T3CON0*8)+1;
static volatile bit	 T3CKPS0                         @((unsigned)&T3CON0*8)+0;

static volatile unsigned char	T3CON1                   @0xfb7;
/*Definitions for T3CON0 register*/
static volatile bit	 TMR3GE                          @((unsigned)&T3CON1*8)+7;
static volatile bit	 T3GPOL                          @((unsigned)&T3CON1*8)+6;
static volatile bit	 T3GTM                           @((unsigned)&T3CON1*8)+5;
static volatile bit	 T3GVAL                          @((unsigned)&T3CON1*8)+2;
static volatile bit	 T3GCK1                          @((unsigned)&T3CON1*8)+1;
static volatile bit	 T3GCK0                          @((unsigned)&T3CON1*8)+0;


static volatile unsigned char	IOCUR                   @0xfB6;
static volatile unsigned char	UARTCON                 @0xfB5;
/*Definitions for UARTCON  register*/
static volatile bit	 SPEN                         @((unsigned)&UARTCON *8)+7;
static volatile bit	 MODE9                        @((unsigned)&UARTCON *8)+6;
static volatile bit	 HALF_DUPLEX                  @((unsigned)&UARTCON *8)+5;
static volatile bit	 TX_EN                        @((unsigned)&UARTCON *8)+4;
static volatile bit	 BRGM                         @((unsigned)&UARTCON *8)+3;
static volatile bit	 BRGH                         @((unsigned)&UARTCON *8)+2;
static volatile bit	 TX9_RX9                      @((unsigned)&UARTCON *8)+1;
static volatile bit	 BUSY                         @((unsigned)&UARTCON *8)+0;


static volatile unsigned char	SPBRG                   @0xfb4;
static volatile unsigned char	RCREG                   @0xfb3;
static volatile unsigned char	TXREG                   @0xfb2;



static volatile unsigned char	IPR1                    @0xfb1;
/*Definitions for IPR1 register*/
static volatile bit	 PWM24IP                       @((unsigned)&IPR1*8)+7;
static volatile bit	 PWM22IP                       @((unsigned)&IPR1*8)+6;
static volatile bit	 PWM20IP                       @((unsigned)&IPR1*8)+5;
static volatile bit	 TMR2IP                        @((unsigned)&IPR1*8)+4;
static volatile bit	 T1PRIP                        @((unsigned)&IPR1*8)+3;
static volatile bit	 T1PDIP                        @((unsigned)&IPR1*8)+2;
static volatile bit	 TMR1IP                        @((unsigned)&IPR1*8)+1;
static volatile bit	 TMR0IP                        @((unsigned)&IPR1*8)+0;


static volatile unsigned char	PIR1                    @0xfb0;
/*Definitions for PIR1 register*/
static volatile bit	 PWM24IF                       @((unsigned)&PIR1*8)+7;
static volatile bit	 PWM22IF                       @((unsigned)&PIR1*8)+6;
static volatile bit	 PWM20IF                       @((unsigned)&PIR1*8)+5;
static volatile bit	 TMR2IF                        @((unsigned)&PIR1*8)+4;
static volatile bit	 T1PRIF                        @((unsigned)&PIR1*8)+3;
static volatile bit	 T1PDIF                        @((unsigned)&PIR1*8)+2;
static volatile bit	 TMR1IF                        @((unsigned)&PIR1*8)+1;
static volatile bit	 TMR0IF                        @((unsigned)&PIR1*8)+0;


static volatile unsigned char	PIE1                    @0xfaf;
/*Definitions for PIE1 register*/
static volatile bit	 PWM24IE                      @((unsigned)&PIE1*8)+7;
static volatile bit	 PWM22IE                      @((unsigned)&PIE1*8)+6;
static volatile bit	 PWM20IE                      @((unsigned)&PIE1*8)+5;
static volatile bit	 TMR2IE                       @((unsigned)&PIE1*8)+4;
static volatile bit	 T1PRIE                       @((unsigned)&PIE1*8)+3;
static volatile bit	 T1PDIE                       @((unsigned)&PIE1*8)+2;
static volatile bit	 TMR1IE                       @((unsigned)&PIE1*8)+1;
static volatile bit	 TMR0IE                       @((unsigned)&PIE1*8)+0;


static volatile unsigned char	IPR2                    @0xfae;
/*Definitions for IPR2 register*/
static volatile bit	 PCIP                         @((unsigned)&IPR2*8)+7;
static volatile bit	 PBIP                         @((unsigned)&IPR2*8)+6;
static volatile bit	 PAIP                         @((unsigned)&IPR2*8)+5;
static volatile bit	 INT2IP                       @((unsigned)&IPR2*8)+4;
static volatile bit	 INT1IP                       @((unsigned)&IPR2*8)+3;
static volatile bit	 INT0IP                       @((unsigned)&IPR2*8)+2;
static volatile bit	 TXIP                         @((unsigned)&IPR2*8)+1;
static volatile bit	 RCIP                         @((unsigned)&IPR2*8)+0;


static volatile unsigned char	PIR2                    @0xfad;
/*Definitions for PIR2 register*/
static volatile bit	 PCIF                         @((unsigned)&PIR2*8)+7;
static volatile bit	 PBIF                         @((unsigned)&PIR2*8)+6;
static volatile bit	 PAIF                         @((unsigned)&PIR2*8)+5;
static volatile bit	 INT2IF                       @((unsigned)&PIR2*8)+4;
static volatile bit	 INT1IF                       @((unsigned)&PIR2*8)+3;
static volatile bit	 INT0IF                       @((unsigned)&PIR2*8)+2;
static volatile bit	 TXIF                         @((unsigned)&PIR2*8)+1;
static volatile bit	 RCIF                         @((unsigned)&PIR2*8)+0;


static volatile unsigned char	PIE2                    @0xfac;
/*Definitions for PIE2 register*/
static volatile bit	 PCIE                         @((unsigned)&PIE2*8)+7;
static volatile bit	 PBIE                         @((unsigned)&PIE2*8)+6;
static volatile bit	 PAIE                         @((unsigned)&PIE2*8)+5;
static volatile bit	 INT2IE                       @((unsigned)&PIE2*8)+4;
static volatile bit	 INT1IE                       @((unsigned)&PIE2*8)+3;
static volatile bit	 INT0IE                       @((unsigned)&PIE2*8)+2;
static volatile bit	 TXIE                         @((unsigned)&PIE2*8)+1;
static volatile bit	 RCIE                         @((unsigned)&PIE2*8)+0;


static volatile unsigned char	IPR3                    @0xfab;
/*Definitions for IPR2 register*/
static volatile bit	 TMR3GIP                      @((unsigned)&IPR3*8)+6;
static volatile bit	 TMR3IP                       @((unsigned)&IPR3*8)+5;
static volatile bit	 CMP1IP                       @((unsigned)&IPR3*8)+4;
static volatile bit	 CMP0IP                       @((unsigned)&IPR3*8)+3;
static volatile bit	 ADIP                         @((unsigned)&IPR3*8)+2;
static volatile bit	 PDTXIP                       @((unsigned)&IPR3*8)+1;
static volatile bit	 PDRCIP                       @((unsigned)&IPR3*8)+0;


static volatile unsigned char	PIR3                    @0xfaa;
/*Definitions for PIR2 register*/
static volatile bit	 TMR3GIF                      @((unsigned)&PIR3*8)+6;
static volatile bit	 TMR3IF                       @((unsigned)&PIR3*8)+5;
static volatile bit	 CMP1IF                       @((unsigned)&PIR3*8)+4;
static volatile bit	 CMP0IF                       @((unsigned)&PIR3*8)+3;
static volatile bit	 ADIF                         @((unsigned)&PIR3*8)+2;
static volatile bit	 PDTXIF                       @((unsigned)&PIR3*8)+1;
static volatile bit	 PDRCIF                       @((unsigned)&PIR3*8)+0;


static volatile unsigned char	PIE3                    @0xfa9;
/*Definitions for PIE2 register*/
static volatile bit	 TMR3GIE                      @((unsigned)&PIE3*8)+6;
static volatile bit	 TMR3IE                       @((unsigned)&PIE3*8)+5;
static volatile bit	 CMP1IE                       @((unsigned)&PIE3*8)+4;
static volatile bit	 CMP0IE                       @((unsigned)&PIE3*8)+3;
static volatile bit	 ADIE                         @((unsigned)&PIE3*8)+2;
static volatile bit	 PDTXIE                       @((unsigned)&PIE3*8)+1;
static volatile bit	 PDRCIE                       @((unsigned)&PIE3*8)+0;

static volatile unsigned char	CMP0CON0                @0xfa8;
/*Definitions for CMP0CON0 register*/
static volatile bit	 CMP0EN                       @((unsigned)&CMP0CON0*8)+7;
static volatile bit	 CMP0OUT                      @((unsigned)&CMP0CON0*8)+6;
static volatile bit	 CMP0PCH2                     @((unsigned)&CMP0CON0*8)+5;
static volatile bit	 CMP0PCH1                     @((unsigned)&CMP0CON0*8)+4;
static volatile bit	 CMP0PCH0                     @((unsigned)&CMP0CON0*8)+3;
static volatile bit	 CMP0NCH2                     @((unsigned)&CMP0CON0*8)+2;
static volatile bit	 CMP0NCH1                     @((unsigned)&CMP0CON0*8)+1;
static volatile bit	 CMP0NCH0                     @((unsigned)&CMP0CON0*8)+0;


static volatile unsigned char	CMP0CON1                @0xfa7;
/*Definitions for CMP0CON1 register*/
static volatile bit	 CMP0FILTER3                  @((unsigned)&CMP0CON1*8)+7;
static volatile bit	 CMP0FILTER2                  @((unsigned)&CMP0CON1*8)+6;
static volatile bit	 CMP0FILTER1                  @((unsigned)&CMP0CON1*8)+5;
static volatile bit	 CMP0FILTER0                  @((unsigned)&CMP0CON1*8)+4;
static volatile bit	 CMP0INT1                     @((unsigned)&CMP0CON1*8)+3;
static volatile bit	 CMP0INT0                     @((unsigned)&CMP0CON1*8)+2;
static volatile bit	 CMP0OUTEN                    @((unsigned)&CMP0CON1*8)+1;
static volatile bit	 CMP0HYSEN                    @((unsigned)&CMP0CON1*8)+0;


static volatile unsigned char	CMP1CON0                @0xfa6;
/*Definitions for CMP1CON0 register*/
static volatile bit	 CMP1EN                       @((unsigned)&CMP1CON0*8)+7;
static volatile bit	 CMP1OUT                      @((unsigned)&CMP1CON0*8)+6;
static volatile bit	 CMP1PCH2                     @((unsigned)&CMP1CON0*8)+5;
static volatile bit	 CMP1PCH1                     @((unsigned)&CMP1CON0*8)+4;
static volatile bit	 CMP1PCH0                     @((unsigned)&CMP1CON0*8)+3;
static volatile bit	 CMP1NCH2                     @((unsigned)&CMP1CON0*8)+2;
static volatile bit	 CMP1NCH1                     @((unsigned)&CMP1CON0*8)+1;
static volatile bit	 CMP1NCH0                     @((unsigned)&CMP1CON0*8)+0;


static volatile unsigned char	CMP1CON1                @0xfa5;
/*Definitions for CMP1CON1 register*/
static volatile bit	 CMP1FILTER3                  @((unsigned)&CMP1CON1*8)+7;
static volatile bit	 CMP1FILTER2                  @((unsigned)&CMP1CON1*8)+6;
static volatile bit	 CMP1FILTER1                  @((unsigned)&CMP1CON1*8)+5;
static volatile bit	 CMP1FILTER0                  @((unsigned)&CMP1CON1*8)+4;
static volatile bit	 CMP1INT1                     @((unsigned)&CMP1CON1*8)+3;
static volatile bit	 CMP1INT0                     @((unsigned)&CMP1CON1*8)+2;
static volatile bit	 CMP1OUTEN                    @((unsigned)&CMP1CON1*8)+1;
static volatile bit	 CMP1HYSEN                    @((unsigned)&CMP1CON1*8)+0;


static volatile unsigned char	DACCON                  @0xfa4;
/*Definitions for DACCON register*/
static volatile bit	 DAC_SEL                      @((unsigned)&DACCON*8)+7;
static volatile bit	 DACEN                        @((unsigned)&DACCON*8)+6;
static volatile bit	 DACS5                        @((unsigned)&DACCON*8)+5;
static volatile bit	 DACS4                        @((unsigned)&DACCON*8)+4;
static volatile bit	 DAC3                         @((unsigned)&DACCON*8)+3;
static volatile bit	 DAC2                         @((unsigned)&DACCON*8)+2;
static volatile bit	 DAC1                         @((unsigned)&DACCON*8)+1;
static volatile bit	 DAC0                         @((unsigned)&DACCON*8)+0;

static volatile unsigned char	ADRESH                  @0xfa3;
static volatile unsigned char	ADRESL                  @0xfa2;
static volatile unsigned char	ADCON0                  @0xfa1;
/*Definitions for ADCON0 register*/
static volatile bit	 ADFM                         @((unsigned)&ADCON0*8)+7;
static volatile bit	 CHS3                         @((unsigned)&ADCON0*8)+5;
static volatile bit	 CHS2                         @((unsigned)&ADCON0*8)+4;
static volatile bit	 CHS1                         @((unsigned)&ADCON0*8)+3;
static volatile bit	 CHS0                         @((unsigned)&ADCON0*8)+2;
static volatile bit	 GO                           @((unsigned)&ADCON0*8)+1;
static volatile bit	 DONE                         @((unsigned)&ADCON0*8)+1;
static volatile bit	 ADON                         @((unsigned)&ADCON0*8)+0;


static volatile unsigned char	ADCON1                  @0xfa0;
/*Definitions for ADCON1 register*/
static volatile bit	 ADVREF0                      @((unsigned)&ADCON1*8)+6;
static volatile bit	 ACQT2                        @((unsigned)&ADCON1*8)+5;
static volatile bit	 ACQT1                        @((unsigned)&ADCON1*8)+4;
static volatile bit	 ACQT0                        @((unsigned)&ADCON1*8)+3;
static volatile bit	 ADCS1                        @((unsigned)&ADCON1*8)+1;
static volatile bit	 ADCS0                        @((unsigned)&ADCON1*8)+0;


static volatile unsigned char	BMCST                   @0xf95;
/*Definitions for BMCST register*/
static volatile bit	 PA1RSEL                      @((unsigned)&BMCST*8)+7;
static volatile bit	 PA0RSEL                      @((unsigned)&BMCST*8)+6; 



static volatile unsigned char	PAPD                    @0xf94;
/*Definitions for PAPD register*/
static volatile bit	 PC6PD                        @((unsigned)&PAPD*8)+6;
static volatile bit	 PA5PD                        @((unsigned)&PAPD*8)+5;
static volatile bit	 PA4PD                        @((unsigned)&PAPD*8)+4;
static volatile bit	 PA3PD                        @((unsigned)&PAPD*8)+3;
static volatile bit	 PA2PD                        @((unsigned)&PAPD*8)+2;
static volatile bit	 PA1PD                        @((unsigned)&PAPD*8)+1;
static volatile bit	 PA0PD                        @((unsigned)&PAPD*8)+0;


static volatile unsigned char	PASV                    @0xf93;
/*Definitions for PASV register*/
static volatile bit	 PC1SMT                       @((unsigned)&PASV*8)+6;
static volatile bit	 PA5SMT                       @((unsigned)&PASV*8)+5;
static volatile bit	 PA4SMT                       @((unsigned)&PASV*8)+4;
static volatile bit	 PA3SMT                       @((unsigned)&PASV*8)+3;
static volatile bit	 PA2SMT                       @((unsigned)&PASV*8)+2;
static volatile bit	 PA1SMT                       @((unsigned)&PASV*8)+1;
static volatile bit	 PA0SMT                       @((unsigned)&PASV*8)+0;


static volatile unsigned char	PAOD                    @0xf92;
/*Definitions for PAOD register*/
static volatile bit	 PA5OD                        @((unsigned)&PAOD*8)+5;
static volatile bit	 PA4OD                        @((unsigned)&PAOD*8)+4;
static volatile bit	 PA2OD                        @((unsigned)&PAOD*8)+2;
static volatile bit	 PA1OD                        @((unsigned)&PAOD*8)+1;
static volatile bit	 PA0OD                        @((unsigned)&PAOD*8)+0;



static volatile unsigned char	PCINTMASK               @0xf91;
/*Definitions for PCINTMASK register*/
static volatile bit	 PC6MSK                       @((unsigned)&PCINTMASK*8)+6;
static volatile bit	 PC5MSK                       @((unsigned)&PCINTMASK*8)+5;
static volatile bit	 PC4MSK                       @((unsigned)&PCINTMASK*8)+4;
static volatile bit	 PC3MSK                       @((unsigned)&PCINTMASK*8)+3;
static volatile bit	 PC2MSK                       @((unsigned)&PCINTMASK*8)+2;
static volatile bit	 PC1MSK                       @((unsigned)&PCINTMASK*8)+1;
static volatile bit	 PC0MSK                       @((unsigned)&PCINTMASK*8)+0;


static volatile unsigned char	PBINTMASK               @0xf90;
/*Definitions for PBINTMASK register*/
static volatile bit	 PB5MSK                       @((unsigned)&PBINTMASK*8)+5;
static volatile bit	 PB4MSK                       @((unsigned)&PBINTMASK*8)+4;
static volatile bit	 PB3MSK                       @((unsigned)&PBINTMASK*8)+3;
static volatile bit	 PB2MSK                       @((unsigned)&PBINTMASK*8)+2;
static volatile bit	 PB1MSK                       @((unsigned)&PBINTMASK*8)+1;
static volatile bit	 PB0MSK                       @((unsigned)&PBINTMASK*8)+0;


static volatile unsigned char	PAINTMASK               @0xf8f;
/*Definitions for PAINTMASK register*/
static volatile bit	 PA5MSK                       @((unsigned)&PAINTMASK*8)+5;
static volatile bit	 PA4MSK                       @((unsigned)&PAINTMASK*8)+4;
static volatile bit	 PA3MSK                       @((unsigned)&PAINTMASK*8)+3;
static volatile bit	 PA2MSK                       @((unsigned)&PAINTMASK*8)+2;
static volatile bit	 PA1MSK                       @((unsigned)&PAINTMASK*8)+1;
static volatile bit	 PA0MSK                       @((unsigned)&PAINTMASK*8)+0;

static volatile unsigned char	TRISC                   @0xf8b;
/*Definitions for TRISC register*/
static volatile bit	 TRISC6                       @((unsigned)&TRISC*8)+6;
static volatile bit	 TRISC5                       @((unsigned)&TRISC*8)+5;
static volatile bit	 TRISC4                       @((unsigned)&TRISC*8)+4;
static volatile bit	 TRISC3                       @((unsigned)&TRISC*8)+3;
static volatile bit	 TRISC2                       @((unsigned)&TRISC*8)+2;
static volatile bit	 TRISC1                       @((unsigned)&TRISC*8)+1;
static volatile bit	 TRISC0                       @((unsigned)&TRISC*8)+0;


static volatile unsigned char	TRISB                   @0xf8a;
/*Definitions for TRISB register*/
static volatile bit	 TRISB5                       @((unsigned)&TRISB*8)+5;
static volatile bit	 TRISB4                       @((unsigned)&TRISB*8)+4;
static volatile bit	 TRISB3                       @((unsigned)&TRISB*8)+3;
static volatile bit	 TRISB2                       @((unsigned)&TRISB*8)+2;
static volatile bit	 TRISB1                       @((unsigned)&TRISB*8)+1;
static volatile bit	 TRISB0                       @((unsigned)&TRISB*8)+0;


static volatile unsigned char	TRISA                   @0xf89;
/*Definitions for TRISA register*/
static volatile bit	 TRISA5                       @((unsigned)&TRISA*8)+5;
static volatile bit	 TRISA4                       @((unsigned)&TRISA*8)+4;
static volatile bit	 TRISA3                       @((unsigned)&TRISA*8)+3;
static volatile bit	 TRISA2                       @((unsigned)&TRISA*8)+2;
static volatile bit	 TRISA1                       @((unsigned)&TRISA*8)+1;
static volatile bit	 TRISA0                       @((unsigned)&TRISA*8)+0;

static volatile unsigned char	PINC                    @0xf88;
/* Definitions for PINC register */
static volatile  bit	PINC6		                              @ ((unsigned)&PINC*8)+6;
static volatile  bit	PINC5		                              @ ((unsigned)&PINC*8)+5;
static volatile  bit	PINC4		                              @ ((unsigned)&PINC*8)+4;
static volatile  bit	PINC3		                              @ ((unsigned)&PINC*8)+3;
static volatile  bit	PINC2		                              @ ((unsigned)&PINC*8)+2;
static volatile  bit	PINC1		                              @ ((unsigned)&PINC*8)+1;
static volatile  bit	PINC0		                              @ ((unsigned)&PINC*8)+0;

static volatile unsigned char	PINB                    @0xf87;
/* Definitions for PINB register */
static volatile  bit	PINB5		                              @ ((unsigned)&PINB*8)+5;
static volatile  bit	PINB4		                              @ ((unsigned)&PINB*8)+4;
static volatile  bit	PINB3		                              @ ((unsigned)&PINB*8)+3;
static volatile  bit	PINB2		                              @ ((unsigned)&PINB*8)+2;
static volatile  bit	PINB1		                              @ ((unsigned)&PINB*8)+1;
static volatile  bit	PINB0		                              @ ((unsigned)&PINB*8)+0;

static volatile unsigned char	PINA                    @0xf86;
/* Definitions for PINA register */
static volatile  bit	PINA5		                              @ ((unsigned)&PINA*8)+5;
static volatile  bit	PINA4		                              @ ((unsigned)&PINA*8)+4;
static volatile  bit	PINA3		                              @ ((unsigned)&PINA*8)+3;
static volatile  bit	PINA2		                              @ ((unsigned)&PINA*8)+2;
static volatile  bit	PINA1		                              @ ((unsigned)&PINA*8)+1;
static volatile  bit	PINA0		                              @ ((unsigned)&PINA*8)+0;

static volatile unsigned char	PCPU                    @0xf85;
/*Definitions for PCPU register*/
static volatile bit	 PC6PU                        @((unsigned)&PCPU*8)+6;
static volatile bit	 PC5PU                        @((unsigned)&PCPU*8)+5;
static volatile bit	 PC4PU                        @((unsigned)&PCPU*8)+4;
static volatile bit	 PC3PU                        @((unsigned)&PCPU*8)+3;
static volatile bit	 PC2PU                        @((unsigned)&PCPU*8)+2;
static volatile bit	 PC1PU                        @((unsigned)&PCPU*8)+1;
static volatile bit	 PC0PU                        @((unsigned)&PCPU*8)+0;


static volatile unsigned char	PBPU                    @0xf84;
/*Definitions for PBPU register*/
static volatile bit	 PB5PU                        @((unsigned)&PBPU*8)+5;
static volatile bit	 PB4PU                        @((unsigned)&PBPU*8)+4;
static volatile bit	 PB3PU                        @((unsigned)&PBPU*8)+3;
static volatile bit	 PB2PU                        @((unsigned)&PBPU*8)+2;
static volatile bit	 PB1PU                        @((unsigned)&PBPU*8)+1;
static volatile bit	 PB0PU                        @((unsigned)&PBPU*8)+0;


static volatile unsigned char	PAPU                    @0xf83;
/*Definitions for PAPU register*/
static volatile bit	 PA5PU                        @((unsigned)&PAPU*8)+5;
static volatile bit	 PA4PU                        @((unsigned)&PAPU*8)+4;
static volatile bit	 PA2PU                        @((unsigned)&PAPU*8)+2;
static volatile bit	 PA1PU                        @((unsigned)&PAPU*8)+1;
static volatile bit	 PA0PU                        @((unsigned)&PAPU*8)+0;

static volatile unsigned char	PORTC                   @0xf82;
/*Definitions for PORTC register*/
static volatile bit	 PC6                          @((unsigned)&PORTC*8)+6;
static volatile bit	 PC5                          @((unsigned)&PORTC*8)+5;
static volatile bit	 PC4                          @((unsigned)&PORTC*8)+4;
static volatile bit	 PC3                          @((unsigned)&PORTC*8)+3;
static volatile bit	 PC2                          @((unsigned)&PORTC*8)+2;
static volatile bit	 PC1                          @((unsigned)&PORTC*8)+1;
static volatile bit	 PC0                          @((unsigned)&PORTC*8)+0;


static volatile unsigned char	PORTB                   @0xf81;
/*Definitions for PORTB register*/
static volatile bit	 PB5                          @((unsigned)&PORTB*8)+5;
static volatile bit	 PB4                          @((unsigned)&PORTB*8)+4;
static volatile bit	 PB3                          @((unsigned)&PORTB*8)+3;
static volatile bit	 PB2                          @((unsigned)&PORTB*8)+2;
static volatile bit	 PB1                          @((unsigned)&PORTB*8)+1;
static volatile bit	 PB0                          @((unsigned)&PORTB*8)+0;

static volatile unsigned char	PORTA                   @0xf80;
/*Definitions for PORTA register*/
static volatile bit	 PA5                          @((unsigned)&PORTA*8)+5;
static volatile bit	 PA4                          @((unsigned)&PORTA*8)+4;
static volatile bit	 PA3                          @((unsigned)&PORTA*8)+3;
static volatile bit	 PA2                          @((unsigned)&PORTA*8)+2;
static volatile bit	 PA1                          @((unsigned)&PORTA*8)+1;
static volatile bit	 PA0                          @((unsigned)&PORTA*8)+0;


/* Macros to access bytes within words and words within longs */
#define LOW_BYTE(x)     ((unsigned char)((x)&0xFF))
#define HIGH_BYTE(x)    ((unsigned char)(((x)>>8)&0xFF))
#define LOW_WORD(x)     ((unsigned short)((x)&0xFFFF))
#define HIGH_WORD(x)    ((unsigned short)(((x)>>16)&0xFFFF))

/* C access to assembler insructions */	
#define	CLRWDT()	    asm(" clrwdt")
#define	NOP()		    asm(" nop")
#define	RESET()		    asm(" reset")
#define SLEEP()		    asm(" sleep")

#define	___mkstr1(x)	#x
#define	___mkstr(x)	___mkstr1(x)

/* Store a word value to a particular configuration word register eg.
 * __CONFIG(4, DEBUGEN & LVPDIS); // write to config word 4
 * config mask attributes (such as DEBUGEN) defined in chip-specific
 * header file. */
#define	__CONFIG(n, x)	asm("\tpsect config,class=CONFIG");\
			asm("global config_word" ___mkstr(n)); \
			asm("\torg ("___mkstr(n)"-1)*2"); \
			asm("config_word" ___mkstr(n)":"); \
			asm("\tdw "___mkstr(x))
			

#define __IDLOC(w)      asm("\tpsect idloc,class=IDLOC");\
			asm("\tglobal\tidloc_word"); \
			asm("idloc_word:"); \
			asm("\tirpc\t__arg," ___mkstr(w)); \
			asm("\tdb 0f&__arg&h"); \
			asm("\tendm")



/* Address definitions for config word registers
 * (NOT TO BE USED WITH __CONFIG MACRO!) */
#define CONFIG1L	0x300000
#define CONFIG1H	0x300001
#define CONFIG2L	0x300002
#define CONFIG2H	0x300003
#define CONFIG3L	0x300004
#define CONFIG3H	0x300005
#define CONFIG4L	0x300006
#define CONFIG4H	0x300007
#define CONFIG5L	0x300008
#define CONFIG5H	0x300009
#define CONFIG6L	0x30000A
#define CONFIG6H	0x30000B
#define CONFIG7L	0x30000C
#define CONFIG7H	0x30000D

//;----- CONFIG0 Options --------------------------------------------------------
#define   _LVR20V_1L                 0xFFFC     // LVR-out Reset set to 2.0V 
#define   _LVR24V_1L                 0xFFFD     // LVR-out Reset set to 2.4V 
#define   _LVR26V_1L                 0xFFFE     // LVR-out Reset set to 2.6V 
#define   _LVR28V_1L                 0xFFFF     // LVR-out Reset set to 2.8V 

#define   _LVREN_ON_1L               0xFFFF     //  Enable LVR reset
#define   _LVREN_OFF_1L              0xFFFB     //  Disable LVR reset 	
	
#define  _SMT_TTL_1L                 0xFFF7      // Level selection  TTL
#define  _SMT_SMV_1L                 0xFFFF      // Level selection  SMTV
	
#define  _FCPU_4T_1L                 0xFFFF	//   4 Instruction cycle
#define  _FCPU_2T_1L                 0xFFEF	//   2 Instruction cycle

	
#define   _FINTOSC_DIV1_1L           0xFFFF     // Fosc DIVIDER 1:1  
#define   _FINTOSC_DIV2_1L           0xFFDF     // Fosc DIVIDER 1:2  
#define   _FINTOSC_DIV4_1L           0xFFBF     // Fosc DIVIDER 1:4  
#define   _FINTOSC_DIV8_1L           0xFF9F     // Fosc DIVIDER 1:8  
#define   _FINTOSC_DIV16_1L          0xFF7F     // Fosc DIVIDER 1:16 


//;-------CONFIG1 Options --------------------------------------------------------

#define  _TWDT_111_2L               0xFFFF 	// WDT overflow time  31.5ms   and the power on reset delay time is 31.5ms
#define  _TWDT_110_2L               0xFFFE	// WDT overflow time  4.63ms   and the power on reset delay time is 4.63ms
#define  _TWDT_101_2L               0xFFFD	// WDT overflow time  246.56ms and the power on reset delay time is 246.56ms
#define  _TWDT_100_2L               0xFFFC	// WDT overflow time  62.24ms  and the power on reset delay time is 62.24ms
#define  _TWDT_011_2L               0xFFFB	// WDT overflow time  31.5ms   and the power on reset delay time is 15 clock cycles
#define  _TWDT_010_2L               0xFFFA	// WDT overflow time  4.63ms   and the power on reset delay time is 15 clock cycles
#define  _TWDT_001_2L               0xFFF9	// WDT overflow time  246.56ms and the power on reset delay time is 15 clock cycles
#define  _TWDT_000_2L               0xFFF8	// WDT overflow time  62.24ms  and the power on reset delay time is 15 clock cycles

#define  _WDTE_OFF_2L               0xFFF7	//   WDT disabled
#define  _WDTE_ON_2L                0xFFFF	//   WDT enabled

#define  _RESETE_ON_2L              0xFFFF	//  Reset Pin enable
#define  _RESETE_OFF_2L             0xFFEF	//  Reset Pin disable

#define  _DBGEN_UART_00_2L          0XFF9F      // disable UART  debug mode  
#define  _DBGEN_UART_01_2L          0XFFBF      // enable  UART  debug mode and baud rate selection 1M 
#define  _DBGEN_UART_10_2L          0XFFDF      // enable  UART  debug mode and baud rate selection 115200 
#define  _DBGEN_UART_11_2L          0XFFFF      // enable  UART  debug mode and VPP is high and switch to PA2, rate selection 115200

#define  _DBGEN_I2C_ON_2L           0XFFFF      // Enable I2C debug mode
#define  _DBGEN_I2C_OFF_2L          0XFF7F      // disable I2C debug mode 

#endif
