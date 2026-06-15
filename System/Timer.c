#include "stm32f10x.h"                  // Device header



void Timer_Init(void)//初始化定时器
{
	RCC_APB2PeriphClockCmd (RCC_APB2Periph_TIM1,ENABLE);//要使用APB2的开启时钟控制，因为TIM1是APB2总线的外设
	//选择时基单元的时钟
	TIM_InternalClockConfig(TIM1);//TIM1的时基单元由内部时钟来驱动，（也可以不写，因为定时器上电后默认为内部时钟）
	//配置时基单元
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_TimeBaseInitStruct.TIM_ClockDivision =TIM_CKD_DIV1 ;//指定时钟分频，与滤波器有关（当前不是特别重要）
	TIM_TimeBaseInitStruct.TIM_CounterMode =TIM_CounterMode_Up;//计数器模式，这里是向上计数
	//这两个是决定定时时间的参数
	//参考：计数器溢出频率：CK_CNT_OV = CK_CNT / (ARR + 1)
	//				       = CK_PSC / (PSC + 1) / (ARR + 1)
	TIM_TimeBaseInitStruct.TIM_Period =1000-1;
	TIM_TimeBaseInitStruct.TIM_Prescaler =72-1;//这里是一ms，PSC和ARR的取值都在0到65535之间
	//因为预分频器和计数器都有一个数的偏差，所以要减一
	TIM_TimeBaseInitStruct.TIM_RepetitionCounter =0;//重复计数器，高级计数器才有，这里不需要用，给0即可
	TIM_TimeBaseInit(TIM1,&TIM_TimeBaseInitStruct);
	
	//刚初始化完会进中断，为了避免可以先清除中断标志位
	TIM_ClearFlag (TIM1,TIM_FLAG_Update );
	//使能更新中断
	TIM_ITConfig(TIM1,TIM_IT_Update,ENABLE);//使能中断,开启更新中断到NVIC的通路
	
	//配置NVIC
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel =TIM1_UP_IRQn;//选中定时器在NVIC中的通道
	NVIC_InitStruct.NVIC_IRQChannelCmd =ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=2; 
	NVIC_InitStruct.NVIC_IRQChannelSubPriority =1;
	NVIC_Init(&NVIC_InitStruct);
	
	//最后启动定时器
	TIM_Cmd(TIM1,ENABLE);
	
	
}	

//中断函数
/*
void TIM1_UP_IRQHandler (void)
{
	
	if(TIM_GetITStatus (TIM1,TIM_IT_Update)==SET)
	{
		
		
		TIM_ClearITPendingBit (TIM1,TIM_IT_Update);
	}
}

	*/
//中断函数可以放在使用它的地方，这里注释掉相当于一个模板


