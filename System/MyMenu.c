#include "MyMenu.h"

Menu_Item head;		//创建根节点
Menu_Item *key;

Menu_Item m1;
Menu_Item m2;
Menu_Item m3;

Menu_Item m4;
Menu_Item m5;

Menu_Item m6;


uint8_t test1=10;
uint8_t test2=50;


//通过初始化函数在任意节点下添加任意东西
void menu_init(void)
{
	Creat_Menu_Folder(&head,&m1,"hello-1");
	Creat_Menu_Folder(&head,&m2,"hello-2");
	Creat_Menu_Folder(&head,&m3,"hello-3");
	
	Creat_Menu_Number(&head,&m6,"test1",&test1,uint8_Box);

	Creat_Menu_Folder(&m1,&m4,"ok-1");
	Creat_Menu_Folder(&m2,&m5,"ok-2");
	
	key=head.first_son;
	
}

void show_key(void)
{
	Menu_Item *h=key->father;
	Menu_Item *s=key->father->first_son;
	for(uint8_t i=0;i<h->sons;i++)
	{
		if(s==key)
		{
			OLED_ShowString(i+1,1,">");
		}else{
				OLED_ShowString(i+1,1," ");

		}
		s=s->next_brother;
	}
}

void key_down(void)
{
	if(key->next_brother!=NULL)
	key=key->next_brother;
	//else key=key->first_son;
}

void key_up(void)
{
	if(key->last_brother!=NULL)
	key=key->last_brother;
}


void show_number(void)
{
	Menu_Item *h=&head;
	Menu_Item *s=head.first_son;

	for(uint8_t i=0;i<h->sons;i++)
	{

		switch (s->kind)
		{
			case uint8_Box :
			{
				OLED_ShowNum(i+1,12,*(uint8_t *)s->data,4);
				break;
			}
			case uint16_Box :
			{
				OLED_ShowNum(i+1,12,*(uint16_t *)s->data,4);
				break;
			}
			case int8_Box :
			{
				OLED_ShowSignedNum(i+1,12,*(int8_t *)s->data,4);
				break;
			}
			case int16_Box :
			{
				OLED_ShowSignedNum(i+1,12,*(int16_t *)s->data,4);
				break;
			}
			default:
			break;			
		}
	
		s=s->next_brother;
	}

}

void menu_show(void)
{
	//OLED_Clear();
	
	Menu_Item *h=&head;
	Menu_Item *s=head.first_son;
	
	for(uint8_t i=0;i<h->sons;i++)
	{
		OLED_ShowString(i+1,2,s->name);
		s=s->next_brother;
	}
	show_key();
	show_number();
	
};
