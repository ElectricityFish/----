#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Timer.h"
#include "Key.h"

uint8_t KeyNum;

int main(void)

{
	
	OLED_Init ();
	Key_Init();
	Timer_Init();
	
	while(1)
	{
		KeyNum=Key_GetNum();
		
		if(KeyNum==1)
		{
			OLED_Clear ();
			OLED_ShowNum (1,1,1,1);
		}
		if(KeyNum==2)
		{
			OLED_Clear ();
			OLED_ShowNum (1,1,2,1);
		}
		if(KeyNum==3)
		{
			OLED_Clear ();
			OLED_ShowNum (1,1,3,1);
		}
		if(KeyNum==4)
		{
			OLED_Clear ();
			OLED_ShowNum (1,1,4,1);
		}
	
	}

	
}


void TIM1_UP_IRQHandler (void)
{
	
	if(TIM_GetITStatus (TIM1,TIM_IT_Update)==SET)
	{
		
		Key_Tick();
		TIM_ClearITPendingBit (TIM1,TIM_IT_Update);
	}
}

