//这两个文件定义菜单的数据类型，以及数据的创建
#ifndef __MENU_H
#define __MENU_H
#include "stm32f10x.h"
#include "OLED.h"
#include <stdio.h>

//定义菜单项目
typedef struct  Menu_Item{
	char *name;					//菜单名字
	
	uint8_t sons;//记录父节点的子节点数量
	uint8_t no;  //记录当前是父节点的第几个子节点
	
	struct  Menu_Item *father;			//指向父节点（上一级菜单）
	struct  Menu_Item *first_son;		//指向第一个子节点（下一级菜单）
	struct  Menu_Item *next_brother;	//指向下一个兄弟节点（同一菜单里的下一项）
	struct  Menu_Item *last_brother;	//指向上一个兄弟节点（同一菜单里的上一项）
	
}Menu_Item;

void Creat_Menu_Item(Menu_Item *father,Menu_Item *me ,char name[]);	//参数：父节点，直接点，名字


#endif
