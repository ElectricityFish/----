#include "Menu.h"

//创建菜单项，初始化成员
static void Creat_Menu_Item(Menu_Item *father,Menu_Item *me ,char name[],void *data,MENU_KIND kind)	//参数：父节点，直接点，名字，绑定的变量，属性
{
	if(father->kind!=MENU_Folder)return;	//只有文件类型项才能有子菜单
	
	me->sons=0;
	me->name=name;
	me->father=father;
	me->first_son=NULL;//子节点先定义为空
	me->last_brother=NULL;
	me->next_brother=NULL;
	
	me->kind=kind;
	me->data=data;
	
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
	father->sons++;//这个记住不要写if-else里面
}



//创建目录
void Creat_Menu_Folder(Menu_Item *father,Menu_Item *me ,char name[])	//参数：父节点，直接点，名字
{
	Creat_Menu_Item(father,me ,name,NULL,MENU_Folder);
}

//创建文件（与参数绑定，下面不能再存放东西的）
void Creat_Menu_Number(Menu_Item *father,Menu_Item *me ,char name[],void *data,MENU_KIND kind)
{
	Creat_Menu_Item(father,me,name,data,kind);
	
}

