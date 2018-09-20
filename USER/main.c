#include "Delay.h"
#include "sys.h"
#include "Usart.h"


/************************************************

************************************************/
#define led0 PBout(5)
#define led1 PEout(5)


 void Delay(u32 count)
 {
   u32 i=0;
   for(;i<count;i++);
 }
void ledgpio_int()
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|  RCC_APB2Periph_GPIOE, ENABLE);	    //ʹ��PB,PE�˿�ʱ��
  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;			    //LED0-->PB.5 �˿�����
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	 //�������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //IO���ٶ�Ϊ50MHz
  GPIO_Init(GPIOB, &GPIO_InitStructure);			     //��ʼ��GPIOB.5

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;	            //LED1-->PE.5�������
  GPIO_Init(GPIOE, &GPIO_InitStructure);	  	       //��ʼ��GPIO

    
  GPIO_SetBits(GPIOB,GPIO_Pin_5);					//PB.5 �����
   GPIO_SetBits(GPIOE,GPIO_Pin_5); 			 //PE.5 ����� 	  

}

 int main(void)
 {	

	ledgpio_int();
	
  while(1)
	{
	  led0 = 1;
	  led1 = 0;
		Delay(3000000);
		led0 = 0;
	  led1 = 1;
		Delay(3000000);
	}
 }
 
