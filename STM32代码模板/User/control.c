#include "stm32f10x.h"                  // Device header
#include "motor.h"
#include "sys.h"
#include "math.h"
#include "control.h"
#include "Trail.h"
#include "oled.h"
int MOTO1,MOTO2;// OUTPUT 是控制舵机的PWM输出值; OUTPUT1 和OUTPUT2 是控制小车左右轮速度的PWM输出值


int PID_sd=0;//小车差速PID控制器的PWM输出值

int PID_jc=0;//小车基础速度PID控制器的PWM输出值
int tim5 =0;

extern int error;//引用lk.c定义的error，才能在本文件内使用error该变量  //作为舵机PID控制器和差速PID控制器的传参输入值

extern int a;//引用lk.c定义的a，才能在本文件内使用a该变量  //作为基础速度PID控制器的传参输入值
/********************************************************************************



*********************************************************************************/

//定时器5中断服务函数	 
//核心控制函数
//------------------------------------------------------------------------------------
void TIM5_IRQHandler(void)
{ 
 	if( TIM_GetITStatus(TIM5, TIM_IT_Update) != RESET )		// 判断是否为TIM5的更新中断
	{
		TIM_ClearITPendingBit(TIM5, TIM_IT_Update );  		// 清除TIM5更新中断标志
		tim5++;
		OLED_ShowNum(1,1,tim5,3,12,1);
		OLED_Refresh ();
//     read_line();	

// 
//	  	PID_sd=Position_PID (error,0);//将差速PID控制器输出的PWM值赋值给PID_sd       //将error和0传入
//		  PID_jc=Position_P (a,0);//将基础速度PID控制器输出的PWM值赋值给PID_jc         //将a和0传入
//		  MOTO1=a+PID_sd;//基础速度+速度偏差量 //基础速度也可以恒定为某个值，这样调差速和舵机就比较好调
//	    MOTO2=a-PID_sd;//基础速度-速度偏差量
//		  Xianfu_Pwm(100);//限幅函数
//			Set_Pwm( MOTO1, MOTO2);
		}
}

	

 int Position_P (int Encoder,int Target)   //基础速度PID控制器//这里Encoder=a，Target=0;
{  
	 float Position_KP=0,Position_KD=0; //参数整定，需要调到适合自己小车的数值大小  //因为没有用到KI(积分)，所以这里去除了和KI相关的式子
	 static float Bias,Pwm,Last_Bias;
	 Bias=Encoder-Target; //偏差=实际值 -目标值
	 Pwm=100-Position_KP*Bias+Position_KD*(Bias-Last_Bias);//位置式PID控制器//这里7200是小车电机PWM的最大值，也就是主函数TIM2的传参传入的数，当error为零时，表示小车处于黑线的中央，没有偏移，所以这时a=0，使得最后返回的PWM值为7200，使电机达到最大速度
	 Last_Bias=Bias;                                       //保存上一次偏差 
	 return Pwm;                                           //返回PWM值
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------
/**********************************************************************************************/
//------------------------------------------------------------------------------------------------------------------------------------------------------------
int Position_PID (int Encoder,int Target)   //差速PID控制器//这里Encoder=error，Target=0;
{ 	
	 float Position_KP=4.5,Position_KI=0,Position_KD=40;
	 static float Bias,Pwm,Integral_bias,Last_Bias;
	 Bias=Encoder-Target;                                  //计算偏差
	 Integral_bias+=Bias;	                                 //求出偏差的积分
	 Pwm=Position_KP*Bias+Position_KI*Integral_bias+Position_KD*(Bias-Last_Bias);       //位置式PID控制器
	 Last_Bias=Bias;                                       //保存上一次偏差 
	 return Pwm;                                           //返回PWM值
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------
/*********************************************************************************************************/
//------------------------------------------------------------------------------------------------------------------------------------------------------------

/**************************************************************************
函数功能：限制PWM赋值 
入口参数：幅值
返回  值：无
**************************************************************************/
void Xianfu_Pwm(int amplitude)
{	
    if(MOTO1<0) MOTO1=0;	
		if(MOTO1>amplitude)  MOTO1=amplitude;	
	  if(MOTO2<0) MOTO2=0;	
		if(MOTO2>amplitude)  MOTO2=amplitude;		
}


void Set_Pwm(int Motor_X,int Motor_Y)//将计算得出的PWM值载入
{

		     Motor_L(Motor_X);
	       Motor_R(Motor_Y);


}








