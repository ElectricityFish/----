//这两个文件绑定数据以及显示
#ifndef __MYMENU_H
#define __MYMENU_H
#include "stm32f10x.h"
#include "OLED.h"
#include "Menu.h"

void menu_init(void);
void menu_show(void);

void key_1(void);
void key_2(void);
void key_enter(void);
void key_quit(void);
void key_select(void);
#endif
