#include "stm32f10x.h"                  // Device header
#include "motor.h"
#include "sys.h"
#include "math.h"
#include "control.h"
#include "Trail.h"
#include "oled.h"
int MOTO1,MOTO2;// OUTPUT �ǿ��ƶ����PWM���ֵ; OUTPUT1 ��OUTPUT2 �ǿ���С���������ٶȵ�PWM���ֵ


int PID_sd=0;//С������PID��������PWM���ֵ

int PID_jc=0;//С�������ٶ�PID��������PWM���ֵ
int tim5 =0;

extern int error;//����lk.c�����error�������ڱ��ļ���ʹ��error�ñ���  //��Ϊ���PID�������Ͳ���PID�������Ĵ�������ֵ

extern int a;//����lk.c�����a�������ڱ��ļ���ʹ��a�ñ���  //��Ϊ�����ٶ�PID�������Ĵ�������ֵ
/********************************************************************************



*********************************************************************************/

//��ʱ��5�жϷ�����	 
//���Ŀ��ƺ���
//------------------------------------------------------------------------------------
void TIM5_IRQHandler(void)
{ 
 	if( TIM_GetITStatus(TIM5, TIM_IT_Update) != RESET )		// �ж��Ƿ�ΪTIM5�ĸ����ж�
	{
		TIM_ClearITPendingBit(TIM5, TIM_IT_Update );  		// ���TIM5�����жϱ�־
		tim5++;
		OLED_ShowNum(1,1,tim5,3,12,1);
		OLED_Refresh ();
//     read_line();	

// 
//	  	PID_sd=Position_PID (error,0);//������PID�����������PWMֵ��ֵ��PID_sd       //��error��0����
//		  PID_jc=Position_P (a,0);//�������ٶ�PID�����������PWMֵ��ֵ��PID_jc         //��a��0����
//		  MOTO1=a+PID_sd;//�����ٶ�+�ٶ�ƫ���� //�����ٶ�Ҳ���Ժ㶨Ϊĳ��ֵ�����������ٺͶ���ͱȽϺõ�
//	    MOTO2=a-PID_sd;//�����ٶ�-�ٶ�ƫ����
//		  Xianfu_Pwm(100);//�޷�����
//			Set_Pwm( MOTO1, MOTO2);
		}
}

	

 int Position_P (int Encoder,int Target)   //�����ٶ�PID������//����Encoder=a��Target=0;
{  
	 float Position_KP=0,Position_KD=0; //������������Ҫ�����ʺ��Լ�С������ֵ��С  //��Ϊû���õ�KI(����)����������ȥ���˺�KI��ص�ʽ��
	 static float Bias,Pwm,Last_Bias;
	 Bias=Encoder-Target; //ƫ��=ʵ��ֵ -Ŀ��ֵ
	 Pwm=100-Position_KP*Bias+Position_KD*(Bias-Last_Bias);//λ��ʽPID������//����7200��С�����PWM�����ֵ��Ҳ����������TIM2�Ĵ��δ����������errorΪ��ʱ����ʾС�����ں��ߵ����룬û��ƫ�ƣ�������ʱa=0��ʹ����󷵻ص�PWMֵΪ7200��ʹ����ﵽ����ٶ�
	 Last_Bias=Bias;                                       //������һ��ƫ�� 
	 return Pwm;                                           //����PWMֵ
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------
/**********************************************************************************************/
//------------------------------------------------------------------------------------------------------------------------------------------------------------
int Position_PID (int Encoder,int Target)   //����PID������//����Encoder=error��Target=0;
{ 	
	 float Position_KP=4.5,Position_KI=0,Position_KD=40;
	 static float Bias,Pwm,Integral_bias,Last_Bias;
	 Bias=Encoder-Target;                                  //����ƫ��
	 Integral_bias+=Bias;	                                 //���ƫ��Ļ���
	 Pwm=Position_KP*Bias+Position_KI*Integral_bias+Position_KD*(Bias-Last_Bias);       //λ��ʽPID������
	 Last_Bias=Bias;                                       //������һ��ƫ�� 
	 return Pwm;                                           //����PWMֵ
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------
/*********************************************************************************************************/
//------------------------------------------------------------------------------------------------------------------------------------------------------------

/**************************************************************************
�������ܣ�����PWM��ֵ 
��ڲ�������ֵ
����  ֵ����
**************************************************************************/
void Xianfu_Pwm(int amplitude)
{	
    if(MOTO1<0) MOTO1=0;	
		if(MOTO1>amplitude)  MOTO1=amplitude;	
	  if(MOTO2<0) MOTO2=0;	
		if(MOTO2>amplitude)  MOTO2=amplitude;		
}


void Set_Pwm(int Motor_X,int Motor_Y)//������ó���PWMֵ����
{

		     Motor_L(Motor_X);
	       Motor_R(Motor_Y);


}








