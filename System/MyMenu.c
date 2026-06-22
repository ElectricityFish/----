#include "MyMenu.h"

Menu_Item head;		//创建根节点
Menu_Item *key;



Menu_Item m1;
Menu_Item m2;

uint8_t test1=10;
uint8_t test2=50;


//通过初始化函数在任意节点下添加任意东西
void menu_init(void)
{

	//根节点初始化
	head.data=NULL;
	head.father=NULL;
	head.first_son=NULL;
	head.kind=MENU_Folder;
	head.last_brother=NULL;
	head.name="MENU";
	head.next_brother=NULL;
	head.sons=0;
	head.no=0;

	Menu_Item *folder1 = create_menu_folder_dynamic(&head,"Folder1");
	Menu_Item *folder2 = create_menu_folder_dynamic(&head,"Folder2");
	Menu_Item *folder3 = create_menu_folder_dynamic(&head,"Folder3");
	Menu_Item *folder4 = create_menu_folder_dynamic(folder1,"Folder4");

	create_menu_number_dynamic(folder1,"test1",&test1,uint8_Box);
	create_menu_number_dynamic(folder4,"test2",&test2,uint8_Box);

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

static void key_down(void)
{
	if(key->next_brother!=NULL)
	{
		key=key->next_brother;
	}
	
}

static void key_up(void)
{
	if(key->last_brother!=NULL)
	key=key->last_brother;
}

void key_enter(void)
{
	if(key->sons > 0)
	{
		key = key->first_son;
		OLED_Clear();
	}
		
}

void key_quit(void)
{
	if(key->father->father != NULL)
	{
		key = key->father;	
		OLED_Clear();
	}
}

void key_select(void)
{
	if(key->kind != MENU_Folder)
	{
		key->select = !key->select;
	}
}

void key_plus(void)
{
	switch (key->kind)
		{
			case uint8_Box :
			{
				*(uint8_t *)key->data+=1;
				break;
			}
			case uint16_Box :
			{
				*(uint16_t *)key->data+=1;
				break;
			}
			case int8_Box :
			{
				*(int8_t *)key->data+=1;
				break;
			}
			case int16_Box :
			{
				*(int16_t *)key->data+=1;
				break;
			}
			default:
			break;			
		}
}


void key_sub(void)
{
	switch (key->kind)
		{
			case uint8_Box :
			{
				*(uint8_t *)key->data-=1;
				break;
			}
			case uint16_Box :
			{
				*(uint16_t *)key->data-=1;
				break;
			}
			case int8_Box :
			{
				*(int8_t *)key->data-=1;
				break;
			}
			case int16_Box :
			{
				*(int16_t *)key->data-=1;
				break;
			}
			default:
			break;			
		}
}


void key_1(void)
{
	if(key->select==false)
	{
		key_down();
	}else 
	{
		key_plus();
		//调参函数
	}
}

void key_2(void)
{
	if(key->select==false)
	{
		key_up();
	}else 
	{
		key_sub();
		//调参函数
	}
}


void show_number(void)
{
	Menu_Item *h=key->father;
	Menu_Item *s=key->father->first_son;


	for(uint8_t i=0;i<h->sons;i++)
	{

		if(s->select)
		{
			OLED_ShowChar(i+1,11,'@');
		}else	OLED_ShowChar(i+1,11,' ');
		

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
	
	Menu_Item *h=key->father;
	Menu_Item *s=key->father->first_son;
	
	for(uint8_t i=0;i<h->sons;i++)
	{
		OLED_ShowString(i+1,2,s->name);
		s=s->next_brother;
	}
	show_key();
	show_number();
	
};
