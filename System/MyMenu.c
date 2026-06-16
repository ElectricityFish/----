#include "MyMenu.h"

Menu_Item head;		//创建根节点
Menu_Item m1;
Menu_Item m2;
Menu_Item m3;
Menu_Item m4;


void menu_init(void)
{
	Creat_Menu_Item(&head,&m1,"hello-1");
	Creat_Menu_Item(&head,&m2,"hello-2");
	Creat_Menu_Item(&head,&m3,"hello-3");
	Creat_Menu_Item(&head,&m4,"hello-4");
}

void menu_show(void)
{
	OLED_Clear();
	
	Menu_Item *h=&head;
	Menu_Item *son=head.first_son;
	
	for(uint8_t i=0;i<h->sons;i++)
	{
		OLED_ShowString(i+1,1,son->name);
		son=son->next_brother;
	}
	
}
