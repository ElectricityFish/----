#ifndef __LED_H//用于防止重复引用
#define __LED_H//这里有空格，在 #ifndef 和宏名之间需要空格
void LED_Init(void);
void LED1_ON(void);
void LED2_ON(void);
void LED1_OFF(void);
void LED2_OFF(void);
void LED1_Turn(void);
void LED2_Turn(void);
	
#endif
