//这两个文件定义菜单的数据类型，以及数据的创建
#ifndef __MENU_H
#define __MENU_H
#include "stm32f10x.h"
#include "OLED.h"
#include <stdio.h>

typedef enum MENU_KIND{
	MENU_Folder = 0,
	int16_Box,
	uint16_Box,
	int8_Box,
	uint8_Box,
	float_Box,
}MENU_KIND;

//定义菜单项目
typedef struct  Menu_Item{
	char *name;					//菜单名字
	
	void *data;					//指向存放的变量
	MENU_KIND kind;				//记录指向数据的属性
	
	uint8_t sons;//记录父节点的子节点数量
	uint8_t no;  //记录当前是父节点的第几个子节点
	
	struct  Menu_Item *father;			//指向父节点（上一级菜单）
	struct  Menu_Item *first_son;		//指向第一个子节点（下一级菜单）
	struct  Menu_Item *next_brother;	//指向下一个兄弟节点（同一菜单里的下一项）
	struct  Menu_Item *last_brother;	//指向上一个兄弟节点（同一菜单里的上一项）
	
}Menu_Item;


void Creat_Menu_Folder(Menu_Item *father,Menu_Item *me ,char name[]);	//参数：父节点，直接点，名字
//创建文件（与参数绑定，下面不能再存放东西的）
void Creat_Menu_Number(Menu_Item *father,Menu_Item *me ,char name[],void *data,MENU_KIND kind);

#endif
