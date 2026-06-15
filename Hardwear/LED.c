#include "stm32f10x.h"                  // Device header

void LED_Init(void)//初始化LED
{

	RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOA ,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode  =GPIO_Mode_Out_PP ;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1|GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed =GPIO_Speed_50MHz ;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	//初始化后是低电平
	
	GPIO_SetBits(GPIOA,GPIO_Pin_1|GPIO_Pin_2);

}

void LED1_ON(void)//点亮LED1
{

	GPIO_ResetBits (GPIOA,GPIO_Pin_1);
}

void LED1_OFF(void)//熄灭LED1
{

	GPIO_SetBits (GPIOA,GPIO_Pin_1);
}

void LED2_ON(void)//点亮LED2
{

	GPIO_ResetBits (GPIOA,GPIO_Pin_2);
}

void LED2_OFF(void)//熄灭LED2
{

	GPIO_SetBits (GPIOA,GPIO_Pin_2);
}

void LED1_Turn(void)//转换灯的状态
{
	if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_1)==0)//读取输出状态
	{
		GPIO_SetBits (GPIOA,GPIO_Pin_1);
	}else{
		GPIO_ResetBits (GPIOA,GPIO_Pin_1);
	}
}
void LED2_Turn(void)
{
	if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_2)==0)
	{
		GPIO_SetBits (GPIOA,GPIO_Pin_2);
	}else{
		GPIO_ResetBits (GPIOA,GPIO_Pin_2);
	}
}
