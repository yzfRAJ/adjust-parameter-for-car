#ifndef __KEY__H
#define __KEY__H
#include "stdint.h"
#include "sys.h"

#define KEY_X10 GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_11)//��ȡ���� 0�����л�
#define KEY_ADD GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_12)//��ȡ���� 1��
#define KEY_SUB GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13)//��ȡ���� 2��
#define KEY_MOD GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_14)//��ȡ���� 3ģʽ�л�
#define KEY_OK  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_15)//��ȡ���� 4ȷ��


#define KEY_add 1 //+
#define KEY_sub 2 //- 
#define KEY_mod 3 //mod
#define KEY_ok  4 //ok
#define KEY_x10 5// �л�����

void Key_Init(void);//������ʼ��

u8 KEY_Scan(u8 mode);//����ɨ�� 1���� 0��֧������
	



#endif
