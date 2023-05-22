/*
����ר��ģ�壬��ͨ��ģ��Ļ�����ɾ����MPU��ش���
����MPU6050_Exit��ش��루�ⲿ�����ж��ã�
�˳���ʹ��F103RCT6���ڴ�������Ʒ������ʹ��C8���л������ļ�
*/
#include <stm32f10x.h>
#include <math.h>
#include <stdint.h>
#include "sys.h"
#include "Delay.h"
#include "Timer.h"
#include "control.h"
#include "Motor.h"
#include "servo.h"
#include "key.h"
#include "bsp_usart.h" 
#include "GUI_control.h"
#include "OLED.h"
#include "PWM.h"
#include "mpu6050.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h" 
//#include "encode.h"
extern uint32_t *p1;
extern uint32_t *i1;
extern uint32_t *d1;
extern uint32_t P1;
extern uint32_t I1;
extern	uint32_t D1;
u8 Start_flag=0;
//************************MPU6050��ز���*************
// float Pitch,Roll,Yaw;						//�Ƕ�
// short gyrox,gyroy,gyroz;				//������--���ٶ�
// short aacx,aacy,aacz;	
//***************************************************
//////-----------------------------------------------------------
//////-----------------------------------------------------------

int main(void)
{ 
USART_Config();//��ʼ������ ��ǰ9600
OLED_Init();// IIC PB3 SCL  PB4 SDA
Motor_Init();//R PB 12 13   PA0 // L PB 14 15    PA1            
Servo_Init();//PA11
Key_Init();
//MPU_Init();					//��ʼ��MPU6050 PB10 PB11
//mpu_dmp_init(); 
//	 Timer_Init();
//****************FLASH������س�ʼ����***********************	
//*************************************************************
//p1=(uint32_t *)(0x08000000+2*1024*20);//��������Ʒÿҳ2KB
//i1=(uint32_t *)(0x08000000+2*1024*21);
//d1=(uint32_t *)(0x08000000+2*1024*22);
//	*p1=0;//����ֵ��
//	*i1=0;
//	*d1=0;
//P1=*p1;
//I1=*i1;
//D1=*d1;
//**************************************************************	

  while(1)
 {
//	 printf("1");
//	 
//   GUI_control_PID();

//   if(KEY_Scan(0)==4)//OK������
//    Start_flag=1;
// 
//	
//   while(Start_flag)
//  {
//if(KEY_Scan(0)==4)//OK������
//    Start_flag=0;
//   printf("OK");
//  }
 }
}

