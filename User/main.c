#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Timer.h"
#include "Key.h"
#include "MyMenu.h"

uint8_t KeyNum;

int main(void)

{
	
	OLED_Init ();
	Key_Init();
	Timer_Init();
	menu_init();
	
	
	while(1)
	{
		menu_show();
		KeyNum=Key_GetNum();
		
		if(KeyNum==1)
		{
			key_1();
		}
		if(KeyNum==2)
		{
			key_2();
		}
		if(KeyNum==3)
		{
			key_select();
			key_enter();
		}
		if(KeyNum==4)
		{
			key_quit();
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

