#include "stm32f10x.h"                  // Device header
#include "Key.h"
#include "OLED.h"
#include "GUI_control.h"
#define canshu_num 3
 uint32_t *p1;
 uint32_t *i1;
 uint32_t *d1;
 uint32_t P1;
 uint32_t I1;
 uint32_t D1;
 uint8_t mod=1;
 

 

//#define KEY_add 1 //+
//#define KEY_sub 2 //- 
//#define KEY_mod 3 //mod
//#define KEY_ok  4 //ok
//#define KEY_x10 5// 切换倍数

void GUI_control_PID()
{

	if(KEY_Scan(1)==3)
	{
		mod++;
		if(mod>canshu_num)
		{
			
			mod=mod%canshu_num;
		}
		
		
	}

   

//*****************************
  if(mod==1)//调节第一个参数p
{
	OLED_ShowChar(48,0,'<',16,1);//1608字体
	OLED_clearare(48,16,56,32);
	OLED_clearare(48,32,56,48);
	if(KEY_Scan(1)==1)
	{
		P1++;
	 FLASH_Unlock();// 解锁flash
	 FLASH_ErasePage(0x08000000+2*1024*20);//   已用地址0x800 0000+已用flash  C8T6 1KB每页  RCT6 2KB每页
	 FLASH_ProgramWord(0x08000000+2*1024*20,P1);//写入一个32位数据
	 FLASH_Lock();//flash上锁 
	}
	
	 else if(KEY_Scan(1)==2)
	{
		P1--;
	 FLASH_Unlock();// 解锁flash
	 FLASH_ErasePage(0x08000000+2*1024*20);//   已用地址0x800 0000+已用flash  C8T6 1KB每页 RCT6 2KB每页
	 FLASH_ProgramWord(0x08000000+2*1024*20,P1);//写入一个32位数据
	 FLASH_Lock();//flash上锁 
	}

}
////****************************
  else if(mod==2)//调节第二个参数i
{
	 OLED_clearare(48,0,56,16);
	 OLED_ShowChar(48,16,'<',16,1);//1608字体
	 OLED_clearare(48,32,56,48);
	if(KEY_Scan(1)==1)
	{
		I1++;
	 FLASH_Unlock();// 解锁flash
	 FLASH_ErasePage(0x08000000+2*1024*21);//   已用地址0x800 0000+已用flash  C8T6 1KB每页  RCT6 2KB每页
	 FLASH_ProgramWord(0x08000000+2*1024*21,I1);//写入一个32位数据
	 FLASH_Lock();//flash上锁 
	}
	
	else if(KEY_Scan(1)==2)
	{
		I1--;
		FLASH_Unlock();// 解锁flash
	 FLASH_ErasePage(0x08000000+2*1024*21);//   已用地址0x800 0000+已用flash  C8T6 1KB每页  RCT6 2KB每页
	 FLASH_ProgramWord(0x08000000+2*1024*21,I1);//写入一个32位数据
	 FLASH_Lock();//flash上锁 
	}
	 

} 

//****************************
  else if(mod==3)//调节第二个参数d
{
	 OLED_clearare(48,0,56,16);
	 OLED_clearare(48,16,56,32);
   OLED_ShowChar(48,32,'<',16,1);//1608字体
	
	if(KEY_Scan(1)==1)
	{
		 D1++;
	 FLASH_Unlock();// 解锁flash
	 FLASH_ErasePage(0x08000000+2*1024*22);//   已用地址0x800 0000+已用flash  C8T6 1KB每页 RCT6 2KB每页
	 FLASH_ProgramWord(0x08000000+2*1024*22,D1);//写入一个32位数据
	 FLASH_Lock();//flash上锁 
	}
	
	else if(KEY_Scan(1)==2)
	{
		D1--;
	 FLASH_Unlock();// 解锁flash
	 FLASH_ErasePage(0x08000000+2*1024*22);//   已用地址0x800 0000+已用flash  C8T6 1KB每页  RCT6 2KB每页
	 FLASH_ProgramWord(0x08000000+2*1024*22,D1);//写入一个32位数据
	 FLASH_Lock();//flash上锁 
	}
	
	
}
//*****************************
  OLED_ShowChar(1,0,'P',16,1);//1608字体
	OLED_ShowChar(1,16,'I',16,1);//1608字体
  OLED_ShowChar(1,32,'D',16,1);//1608字体
  OLED_ShowNum(9,0,*p1,4,16,1);
  OLED_ShowNum(9,16,*i1,4,16,1);
  OLED_ShowNum(9,32,*d1,4,16,1);
	OLED_Refresh();
//****************************
	
}