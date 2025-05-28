#include "public.h"                  // Device header
#include "myi2c.h"
//#include "aip33626.h"

void aip33626_sendcmd(uint8_t cmd)
{
	myi2c_start();
	myi2c_sendbyte(aip_id);
	myi2c_reciveack();
	myi2c_sendbyte(cmd);
	myi2c_reciveack();
	myi2c_stop();
}

void aip33626_sursor(uint8_t site)
{
	aip33626_sendcmd(aip_addrh|(site>>4));
	aip33626_sendcmd(aip_addrl|(site&0x0f));
}
void aip33626_ram(uint8_t addr,uint8_t dat)
{
	aip33626_sursor(addr);
	myi2c_start();
	myi2c_sendbyte(aip_id);
	myi2c_reciveack();
	myi2c_sendbyte(0);
	myi2c_reciveack();
	myi2c_sendbyte(dat);
	myi2c_reciveack();
	myi2c_stop();
}
void aip33626_init(void)
{

	myi2c_init();
	lcd_on();
	aip33626_sendcmd(aip_self_inc);
	aip33626_sendcmd(aip_on);
}


void aip33626_allDisplay_(u8 num)//(uint8_t* arr,uint8_t num)
{
	uint8_t i=0;
	aip33626_sursor(0x00);
	myi2c_start();
	myi2c_sendbyte(aip_id);
	myi2c_reciveack();
	myi2c_sendbyte(0x00);
	myi2c_reciveack();
	for(i=0;i<128;i++)
	{
		myi2c_sendbyte(num);
		myi2c_reciveack();
	}
	
	myi2c_stop();
}
void aip33626_allDisplay(u8* num)//(uint8_t* arr,uint8_t num)
{
	uint8_t i=0;
	aip33626_sursor(0x00);
	myi2c_start();
	myi2c_sendbyte(aip_id);
	myi2c_reciveack();
	myi2c_sendbyte(0x00);
	myi2c_reciveack();
	for(i=0;i<128;i++)
	{
		myi2c_sendbyte(num[i]);
		myi2c_reciveack();
	}
	
	myi2c_stop();
}


u8 col_cnt=0;
u8 arr_col[128]={0};
u8 col_init=1;

u8 aip33626_task_id=0;

void arr_col_init(u8 num)
{
	u8 i;
	for(i=0;i<128;i++)
	{
		arr_col[i]=num;
	}
}


#if 0
const u8 arr_cnt[128]={
40,40,4,2,0,7,8 ,12,16,17,22,26,28,6,40,40,//0
40,40,3,2,1,7,10,12,40,19,23,26,29,6,40,40,//1
40,40,2,2,0,7,11,14,40,20,23,25,27,6,40,40,//2
40,40,2,3,1,7,10,15,40,21,23,25,27,6,40,40,//3
40,40,2,4,0,7,10,40,17,20,24,27,28,6,40,40,//4
40,40,2,5,0,8,10,40,18,19,24,27,29,6,40,40,//5
40,40,2,6,1,9,12,14,40,20,24,28,30,6,40,40,//6
40,40,2,6,0,9,13,15,40,22,25,30,30,5,40,40 //7
};
void new_col(u8 you,u8 dian,u8 mode_you,u8 mode_dian,u8 mode,u8 mode_sub)
{
	u8 i=0,t=0,t1=0,t2;
	static u8 mode_sub_2=0;
	
	if(mode_sub!=2)
	{	
		mode_sub_2=0;
		for(i=0;i<128;i++)
		{
			
			if(t>=2 && t<=13)
			{
				if(arr_cnt[i]<=col_cnt && arr_cnt[i]+9>=col_cnt)
				{
					arr_col[i]=(col_cnt+1-arr_cnt[i])*25;
				}
				else if(arr_cnt[i]+9<col_cnt)
				{
					arr_col[i]=250;
				}
				else
				{
					arr_col[i]=0;
				}
				
			}

			t++;
			if(t>=16)
			{
				t=0;
			}
			
		}
		arr_col[24]=250;
		arr_col[40]=250;
		arr_col[56]=250;
		arr_col[71]=250;
		arr_col[87]=250;
		arr_col[104]=250;
		arr_col[120]=250;
	}
	else{
		mode_sub_2++;
	}
	if(mode_you==0)
	{
		if(col_init==1)
		{
			arr_col[0]=0;
			switch (you)
			{
			case 6:
				arr_col[96]=250;
			case 5:
				arr_col[80]=250;
			case 4:
				arr_col[64]=250;
			case 3:
				arr_col[48]=250;
			case 2:
				arr_col[32]=250;
			case 1:
				arr_col[16]=250;
				/* code */
				break;
			
			default:
				break;
			}
		}
		
	}
	else
	{
		if(mode_sub!=2)
		{
			if(col_cnt==0 || col_cnt==10 || col_cnt==20||col_cnt==30)
			{
				arr_col[0]=250;
				switch (you)
				{
				case 6:
					arr_col[96]=250;
				case 5:
					arr_col[80]=250;
				case 4:
					arr_col[64]=250;
				case 3:
					arr_col[48]=250;
				case 2:
					arr_col[32]=250;
				case 1:
					arr_col[16]=250;
					/* code */
					break;
				
				default:
					break;
				}
			}
			else if(col_cnt==5 || col_cnt==15 || col_cnt==25||col_cnt==35)
			{
				arr_col[0 ]=0;
				arr_col[16]=0;
				arr_col[32]=0;
				arr_col[48]=0;
				arr_col[64]=0;
				arr_col[80]=0;
				arr_col[96]=0;
			}
			
		}
		else
		{
			if(mode_sub_2&0x01)
			{
				arr_col[0]=250;
				switch (you)
				{
				case 6:
					arr_col[96]=250;
				case 5:
					arr_col[80]=250;
				case 4:
					arr_col[64]=250;
				case 3:
					arr_col[48]=250;
				case 2:
					arr_col[32]=250;
				case 1:
					arr_col[16]=250;
					/* code */
					break;
				
				default:
					break;
				}
			}
			else 
			{
				arr_col[0 ]=0;
				arr_col[16]=0;
				arr_col[32]=0;
				arr_col[48]=0;
				arr_col[64]=0;
				arr_col[80]=0;
				arr_col[96]=0;
			}
		}
	}
	if(mode_dian==0)
	{
		if(col_init==1)
		{
			arr_col[1]=0;
			switch (dian)
			{
			case 6:
				arr_col[97]=250;
			case 5:
				arr_col[81]=250;
			case 4:
				arr_col[65]=250;
			case 3:
				arr_col[49]=250;
			case 2:
				arr_col[33]=250;
			case 1:
				arr_col[17]=250;
				/* code */
				break;
			
			default:
				break;
			}
		}
	}
	else if(mode_dian==1)
	{
		if(mode_sub!=2)
		{
			if(col_cnt==0 || col_cnt==10 || col_cnt==20||col_cnt==30)
			{
				arr_col[1]=250;
				switch (dian)
				{
				case 6:
					arr_col[97]=250;
				case 5:
					arr_col[81]=250;
				case 4:
					arr_col[65]=250;
				case 3:
					arr_col[49]=250;
				case 2:
					arr_col[33]=250;
				case 1:
					arr_col[17]=250;
					/* code */
					break;
				
				default:
					break;
				}
			}
			else if(col_cnt==5 || col_cnt==15 || col_cnt==25||col_cnt==35)
			{
				arr_col[1 ]=0;
				arr_col[17]=0;
				arr_col[33]=0;
				arr_col[49]=0;
				arr_col[65]=0;
				arr_col[81]=0;
				arr_col[97]=0;
			}
		}
		else
		{
			if(mode_sub_2&0x01)
			{
				arr_col[1]=250;
				switch (dian)
				{
				case 6:
					arr_col[97]=250;
				case 5:
					arr_col[81]=250;
				case 4:
					arr_col[65]=250;
				case 3:
					arr_col[49]=250;
				case 2:
					arr_col[33]=250;
				case 1:
					arr_col[17]=250;
					/* code */
					break;
				
				default:
					break;
				}
			}
			else 
			{
				arr_col[1 ]=0;
				arr_col[17]=0;
				arr_col[33]=0;
				arr_col[49]=0;
				arr_col[65]=0;
				arr_col[81]=0;
				arr_col[97]=0;
			}
		}
	}
	else
	{
		if(col_cnt==0 || col_cnt==10 || col_cnt==20||col_cnt==30)
		{
			arr_col[1 ]=250;
			
		}
		else if(col_cnt==5 || col_cnt==15 || col_cnt==25||col_cnt==35)
		{
			arr_col[1 ]=0;
			
		}
		if(mode_sub==1)
		{
			t2=39-col_cnt;
		}
		else
		{
			t2=col_cnt;
		}
		if(!(t2&0x01))
		{
			t1=(t2/2)%6;
			if(t1==0)
			//if(col_cnt==0 || col_cnt==12||col_cnt==24||col_cnt==36)
			{
				arr_col[17]=250;
				arr_col[33]=0;
				arr_col[49]=0;
				arr_col[65]=0;
				arr_col[81]=0;
				arr_col[97]=0;
			}
			else if(t1==1)
			//else if(col_cnt==2 || col_cnt==14||col_cnt==26||col_cnt==38)
			{
				arr_col[17]=0;
				arr_col[33]=250;
			}
			else if(t1==2)
			//else if(col_cnt==4 || col_cnt==16||col_cnt==28)
			{
				arr_col[33]=0;
				arr_col[49]=250;
			}
			else if(t1==3)
			//else if((col_cnt==6 || col_cnt==18||col_cnt==30))
			{
				arr_col[49]=0;
				arr_col[65]=250;
			}
			else if(t1==4)
			//else if((col_cnt==8 || col_cnt==20||col_cnt==32))
			{
				arr_col[65]=0;
				arr_col[81]=250;
			}
			else if(t1==5)
			//else if((col_cnt==10 || col_cnt==22||col_cnt==34))
			{
				arr_col[81]=0;
				arr_col[97]=250;
			}
		}
	}
	if(col_init==1||col_cnt==0||col_cnt==15||col_cnt==30)
	{
		
		if(mode==0)
		{
			arr_col[14]=250;
			arr_col[30]=250;
			arr_col[46]=250;
			arr_col[62]=250;
			arr_col[78]=250;
			arr_col[94]=250;

			arr_col[110]=0;
			arr_col[126]=0;
			arr_col[112]=0;
			arr_col[113]=0;
		}
		else
		{
			arr_col[14]=0;
			arr_col[30]=0;
			arr_col[46]=0;
			arr_col[62]=0;
			arr_col[78]=0;
			arr_col[94]=0;

			arr_col[110]=250;
			arr_col[126]=250;
			arr_col[112]=250;
			arr_col[113]=250;
		}
	}
	if(col_init==1)
	{
		col_init=0;
	}
	if(col_cnt==39)
	{
		col_init=1;
	}
}
#else
u8 t1=0;
u8 state_q=0;
const u8 arr_q[]={
a3 ,b3 ,c3 ,d3 ,e3 ,f3 ,g3 ,h3,
a4 ,b4 ,c4 ,d4 ,e4 ,f4 ,g4 ,h4,
a14,b14,c14,d14,e14,f14,h14,g14
};

const u8 arr_cnt[128]={
40,40,40,40,0,7,8 ,12,16,17,22,26,28,40,40,40,//0
40,40,40,40,1,7,10,12,40,19,23,26,29,40,40,40,//1
40,40,40,40,0,7,11,14,40,20,23,25,27,40,40,40,//2
40,40,40,40,1,7,10,15,40,21,23,25,27,40,40,40,//3
40,40,40,40,0,7,10,40,17,20,24,27,28,40,40,40,//4
40,40,40,40,0,8,10,40,18,19,24,27,29,40,40,40,//5
40,40,40,40,1,9,12,14,40,20,24,28,30,40,40,40,//6
40,40,40,40,0,9,13,15,40,22,25,30,30,40,40,40 //7
};
void new_col(u8 you,u8 dian,u8 mode_you,u8 mode_dian,u8 mode,u8 mode_sub)
{
	u8 i=0,t=0,t2;
	static u8 mode_sub_2=0;
	
	if(mode_sub!=2)
	{	
		mode_sub_2=0;
		for(i=0;i<128;i++)
		{
			
			if(t>=4 && t<=12)
			{
				if(arr_cnt[i]<=col_cnt && arr_cnt[i]+9>=col_cnt)
				{
					arr_col[i]=(col_cnt+1-arr_cnt[i])*25;
				}
				else if(arr_cnt[i]+9<col_cnt)
				{
					arr_col[i]=250;
				}
				else
				{
					arr_col[i]=0;
				}
				
			}

			t++;
			if(t>=16)
			{
				t=0;
			}
			
		}
		arr_col[24]=250;
		arr_col[40]=250;
		arr_col[56]=250;
		arr_col[71]=250;
		arr_col[87]=250;
		arr_col[104]=250;
		arr_col[120]=250;
	}
	else{
		mode_sub_2++;
	}
	if(mode_you==0)
	{
		if(col_init==1)
		{
			arr_col[0]=0;
			switch (you)
			{
			case 6:
				arr_col[96]=250;
			case 5:
				arr_col[80]=250;
			case 4:
				arr_col[64]=250;
			case 3:
				arr_col[48]=250;
			case 2:
				arr_col[32]=250;
			case 1:
				arr_col[16]=250;
				/* code */
				break;
			
			default:
				break;
			}
		}
		
	}
	else
	{
		if(mode_sub!=2)
		{
			if(col_cnt==0 || col_cnt==10 || col_cnt==20||col_cnt==30)
			{
				arr_col[0]=250;
				switch (you)
				{
				case 6:
					arr_col[96]=250;
				case 5:
					arr_col[80]=250;
				case 4:
					arr_col[64]=250;
				case 3:
					arr_col[48]=250;
				case 2:
					arr_col[32]=250;
				case 1:
					arr_col[16]=250;
					/* code */
					break;
				
				default:
					break;
				}
			}
			else if(col_cnt==5 || col_cnt==15 || col_cnt==25||col_cnt==35)
			{
				arr_col[0 ]=0;
				arr_col[16]=0;
				arr_col[32]=0;
				arr_col[48]=0;
				arr_col[64]=0;
				arr_col[80]=0;
				arr_col[96]=0;
			}
			
		}
		else
		{
			if(mode_sub_2&0x01)
			{
				arr_col[0]=250;
				switch (you)
				{
				case 6:
					arr_col[96]=250;
				case 5:
					arr_col[80]=250;
				case 4:
					arr_col[64]=250;
				case 3:
					arr_col[48]=250;
				case 2:
					arr_col[32]=250;
				case 1:
					arr_col[16]=250;
					/* code */
					break;
				
				default:
					break;
				}
			}
			else 
			{
				arr_col[0 ]=0;
				arr_col[16]=0;
				arr_col[32]=0;
				arr_col[48]=0;
				arr_col[64]=0;
				arr_col[80]=0;
				arr_col[96]=0;
			}
		}
	}
	if(mode_dian==0)
	{
		if(col_init==1)
		{
			arr_col[1]=0;

			arr_col[97]=0;
			arr_col[81]=0;
			arr_col[65]=0;
			arr_col[49]=0;
			arr_col[33]=0;
			arr_col[17]=0;
			switch (dian)
			{
			case 6:
				arr_col[97]=250;
			case 5:
				arr_col[81]=250;
			case 4:
				arr_col[65]=250;
			case 3:
				arr_col[49]=250;
			case 2:
				arr_col[33]=250;
			case 1:
				arr_col[17]=250;
				/* code */
				break;
			
			default:
				break;
			}
		}
	}
	else if(mode_dian==1)
	{
		if(mode_sub!=2)
		{
			if(col_cnt==0 || col_cnt==10 || col_cnt==20||col_cnt==30)
			{
				arr_col[1]=250;
				switch (dian)
				{
				case 6:
					arr_col[97]=250;
				case 5:
					arr_col[81]=250;
				case 4:
					arr_col[65]=250;
				case 3:
					arr_col[49]=250;
				case 2:
					arr_col[33]=250;
				case 1:
					arr_col[17]=250;
					/* code */
					break;
				
				default:
					break;
				}
			}
			else if(col_cnt==5 || col_cnt==15 || col_cnt==25||col_cnt==35)
			{
				arr_col[1 ]=0;
				arr_col[17]=0;
				arr_col[33]=0;
				arr_col[49]=0;
				arr_col[65]=0;
				arr_col[81]=0;
				arr_col[97]=0;
			}
		}
		else
		{
			if(mode_sub_2&0x01)
			{
				arr_col[1]=250;

				
				switch (dian)
				{
				case 6:
					arr_col[97]=250;
				case 5:
					arr_col[81]=250;
				case 4:
					arr_col[65]=250;
				case 3:
					arr_col[49]=250;
				case 2:
					arr_col[33]=250;
				case 1:
					arr_col[17]=250;
					/* code */
					break;
				
				default:
					break;
				}
			}
			else 
			{
				arr_col[1 ]=0;
				arr_col[17]=0;
				arr_col[33]=0;
				arr_col[49]=0;
				arr_col[65]=0;
				arr_col[81]=0;
				arr_col[97]=0;
			}
		}
	}
	else
	{
		if(col_cnt==0 || col_cnt==10 || col_cnt==20||col_cnt==30)
		{
			arr_col[1 ]=250;
			
		}
		else if(col_cnt==5 || col_cnt==15 || col_cnt==25||col_cnt==35)
		{
			arr_col[1 ]=0;
		}

		if(mode_sub==1)
		{
			t2=39-col_cnt;
		}
		else
		{
			t2=col_cnt;
		}
		if((t2&0x01)==0)
		{
			
			//t1=(t2>>1)%6;
			if(t1==0)
			//if(col_cnt==0 || col_cnt==12||col_cnt==24||col_cnt==36)
			{
				arr_col[17]=250;
				arr_col[33]=0;
				arr_col[49]=0;
				arr_col[65]=0;
				arr_col[81]=0;
				arr_col[97]=0;
			}
			else if(t1==1)
			//else if(col_cnt==2 || col_cnt==14||col_cnt==26||col_cnt==38)
			{
				arr_col[17]=0;
				arr_col[33]=250;
				arr_col[49]=0;
				arr_col[65]=0;
				arr_col[81]=0;
				arr_col[97]=0;
			}
			else if(t1==2)
			//else if(col_cnt==4 || col_cnt==16||col_cnt==28)
			{
				arr_col[17]=0;
				arr_col[33]=0;
				arr_col[49]=250;
				arr_col[65]=0;
				arr_col[81]=0;
				arr_col[97]=0;
			}
			else if(t1==3)
			//else if((col_cnt==6 || col_cnt==18||col_cnt==30))
			{
				arr_col[17]=0;
				arr_col[33]=0;
				arr_col[49]=0;
				arr_col[65]=250;
				arr_col[81]=0;
				arr_col[97]=0;
			}
			else if(t1==4)
			//else if((col_cnt==8 || col_cnt==20||col_cnt==32))
			{
				arr_col[17]=0;
				arr_col[33]=0;
				arr_col[49]=0;
				arr_col[65]=0;
				arr_col[81]=250;
				arr_col[97]=0;
			}
			else
			//else if((col_cnt==10 || col_cnt==22||col_cnt==34))
			{
				arr_col[17]=0;
				arr_col[33]=0;
				arr_col[49]=0;
				arr_col[65]=0;
				arr_col[81]=0;
				arr_col[97]=250;
			}
			t1++;
			if(t1>=6)
			{
				t1=0;
			}
		}

		
	}
	if(mode_sub<=2)//((col_cnt&1)==0||mode_sub==2)
	{
		arr_col[arr_q[state_q]]=250;

		// if(state_q==0)
		// {
		// 	arr_col[arr_q[23]]=0;
		// }
		// else
		// {
		// 	arr_col[arr_q[state_q-1]]=0;
		// }
		arr_col[arr_q[state_q==0?23:(state_q-1)]]=0;
		
		state_q++;
		if(state_q>=24)
		{
			state_q=0;
		}
	}
	

	if(col_init==1||col_cnt==15||col_cnt==30||col_cnt==5)
	{
		
		if(mode==0)
		{
			arr_col[14]=250;
			arr_col[30]=250;
			arr_col[46]=250;
			arr_col[62]=250;
			arr_col[78]=250;
			arr_col[94]=250;

			arr_col[110]=0;
			arr_col[126]=0;
			arr_col[112]=0;
			arr_col[113]=0;
		}
		else
		{
			arr_col[14]=0;
			arr_col[30]=0;
			arr_col[46]=0;
			arr_col[62]=0;
			arr_col[78]=0;
			arr_col[94]=0;

			arr_col[110]=250;
			arr_col[126]=250;
			arr_col[112]=250;
			arr_col[113]=250;
		}
	}
	if(col_init==1)
	{
		col_init=0;
	}
	if(col_cnt==39)
	{
		col_init=1;
	}
}

#endif
// void breath_display(u8 you,u8 dian,u8 mode_you,u8 mode_dian,u8 mode)
// {
// 	new_col(you,dian,mode_you,mode_dian,mode);
// 	aip33626_allDisplay(arr_col);
// }

//5s  3
void aip33626_sys_begin(task* task_)
{
	if(task_->sucCnt==2)
	{
		aip33626_allDisplay_(0);
		return;
	}
	aip33626_allDisplay_(255);
	
}


//250ms  10 or 20
void aip33626_flash(task* task_)
{
	if(task_->sucCnt&0x01)
	{
		aip33626_allDisplay_(0);
	}
	else
	{
		aip33626_allDisplay_(250);
	}
}

extern u8 you,dian,mode_you,mode_dian,mode,mode_sub;
//50ms  40
void aip33626_breath(task* task_)
{
	if(mode_sub==0)
	{
		if(task_->sucCnt==0)
		{
			col_init=1;
			arr_col_init(0);
		}
		col_cnt=task_->sucCnt;
	}
	else
	{
		col_cnt=39-task_->sucCnt;
		if((col_cnt==0 && SI_MIC==0 && USB_DET==0) ||task_1_7_flag)
		{
			aip33626_allDisplay_(0);
			return;
		}

	}
	new_col(you,dian,mode_you,mode_dian,mode,mode_sub);
	aip33626_allDisplay(arr_col);
}

//250ms  21
void aip33626_breath_stop(task* task_)
{
	if(task_->sucCnt==1)
	{
		return;
	}
	col_init=1;
	col_cnt=39;
	new_col(you,dian,mode_you,mode_dian,mode,mode_sub);
	aip33626_allDisplay(arr_col);
}

//1000ms  2
void aip33626_nol_doub(task* task_)
{
	#if 0
	aip33626_allDisplay_(0);
	
	if(task_->sucCnt==1)
	{
		return;
	}
	if(mode==0)
	{
		aip33626_ram(14,250);
		aip33626_ram(30,250);
		aip33626_ram(46,250);
		aip33626_ram(62,250);
		aip33626_ram(78,250);
		aip33626_ram(94,250);

		aip33626_ram(110,0);
		aip33626_ram(112,0);
		aip33626_ram(113,0);
		aip33626_ram(126,0);
	}
	else
	{
		aip33626_ram(14,0);
		aip33626_ram(30,0);
		aip33626_ram(46,0);
		aip33626_ram(62,0);
		aip33626_ram(78,0);
		aip33626_ram(94,0);

		aip33626_ram(110,250);
		aip33626_ram(112,250);
		aip33626_ram(113,250);
		aip33626_ram(126,250);
	}
	#else
	if(task_->sucCnt==1)
	{
		aip33626_allDisplay_(0);
		return;
	}
	arr_col_init(0);
	if(mode==0)
	{
		arr_col[14]=250;
		arr_col[30]=250;
		arr_col[46]=250;
		arr_col[62]=250;
		arr_col[78]=250;
		arr_col[94]=250;


		arr_col[110]=0;
		arr_col[112]=0;
		arr_col[113]=0;
		arr_col[126]=0;
	}
	else
	{
		arr_col[14]=0;
		arr_col[30]=0;
		arr_col[46]=0;
		arr_col[62]=0;
		arr_col[78]=0;
		arr_col[94]=0;


		arr_col[110]=250;
		arr_col[112]=250;
		arr_col[113]=250;
		arr_col[126]=250;
	}
	aip33626_allDisplay(arr_col);
	#endif
}

//250ms  24
void aip33626_smo_reset(task* task_)
{
	if(task_->sucCnt==0)
	{
		// you=6;
		// mode_you=0;
		// aip33626_allDisplay_(0);
		arr_col_init(0);
	}

	if(task_->sucCnt<=19&& !((task_->sucCnt)& 0x01 ))
	{

		arr_col[0 ]=250;
		arr_col[16]=250;
		arr_col[32]=250;
		arr_col[48]=250;
		arr_col[64]=250;
		arr_col[80]=250;
		arr_col[96]=250;
	}
	else if((task_->sucCnt<=20&&((task_->sucCnt)&0x01))||task_->sucCnt==23)
	{
		arr_col[0 ]=0;
		arr_col[16]=0;
		arr_col[32]=0;
		arr_col[48]=0;
		arr_col[64]=0;
		arr_col[80]=0;
		arr_col[96]=0;
	}
	else if(task_->sucCnt==20)
	{
		arr_col[0 ]=0;
		arr_col[16]=250;
		arr_col[32]=250;
		arr_col[48]=250;
		arr_col[64]=250;
		arr_col[80]=250;
		arr_col[96]=250;
	}
	aip33626_allDisplay(arr_col);
}

//8ms 1
void aip33626_batFull(  task* task_)
{
	//aip33626_allDisplay_(250);
	arr_col_init(250);
	arr_col[0]=0;
	switch (you)
	{
	case 1:
		arr_col[32]=0;
	case 2:
		arr_col[48]=0;
	case 3:
		arr_col[64]=0;
	case 4:
		arr_col[80]=0;
	case 5:
		arr_col[96]=0;
		break;
	case 6:
		/* code */
		break;
	
	default:
		break;
	}

	arr_col[1]=0;

	if(mode==0)
	{
		arr_col[110]=0;
		arr_col[112]=0;
		arr_col[113]=0;
		arr_col[126]=0;
	}
	else
	{
		arr_col[14]=0;
		arr_col[30]=0;
		arr_col[46]=0;
		arr_col[62]=0;
		arr_col[78]=0;
		arr_col[94]=0;
	}
	if(task_->id2==7)
	{
		aip33626_allDisplay(arr_col);
	}
}

//250ms  7
void aip33626_freeChrg(task* task_)
{
	if(task_->sucCnt&0x01)
	{
		aip33626_batFull(task_);
		switch (dian)
		{
		case 1:
			arr_col[33]=0;
		case 2:
			arr_col[49]=0;
		case 3:
			arr_col[65]=0;
		case 4:
			arr_col[81]=0;
		case 5:
			arr_col[97]=0;
		case 6:
			break;
		
		default:
			break;
		}
		aip33626_allDisplay(arr_col);
	}
	else
	{
		aip33626_allDisplay_(0);
	}
}














