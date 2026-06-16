#include "Menu.h"

//创建菜单项
void Creat_Menu_Item(Menu_Item *father,Menu_Item *me ,char name[])	//参数：父节点，直接点，名字
{
	me->sons=0;
	me->name=name;
	me->father=father;
	me->first_son=NULL;//子节点先定义为空
	me->last_brother=NULL;
	me->next_brother=NULL;
	
	if(father->sons==0)//如果父节点还没有子节点
	{
		father->first_son=me;	//就让父节点第一个子节点指向me 
	}
	else//如果有子节点，就让me排在父节点最后一个子节点后面
	{
		Menu_Item *p=father->first_son;
		while(p->next_brother!=NULL)
			p=p->next_brother;
		p->next_brother=me;
		me->last_brother=p;
		me->no=father->sons;
	}
	father->sons++;
}

