#include <stdio.h>
#include <stdlib.h>

typedef struct LNode	//定义单链表结点类型
{
	int data;			//数据域
	struct LNode* next;//指针域，指向下一个结点
}LNode, * LinkList;

//不带头节点的单链表
bool Init(LinkList& L)//初始化
{
	L = NULL;
	return true;
}

//带头节点的单链表(不存储数据)
bool Init(LinkList& L)//初始化
{ 
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL)
	{
		return false;
	}
	L->next = NULL;
	return true;
}

LNode* GetElem(LinkList L, int i)//返回一个节点，LinkList强调这里是一个单链表
{
	int j = 1;
	LNode* p = L->next;
	if (i == 0)
	{
		return L;
	}
	if (i < 1)
	{
		return NULL;
	}
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	return p;
}

//带头结点的按位序插入
bool ListInsert(LinkList& L, int i, int e)
{
	if (i < 1)//位序合法性检测
	{
		return false;
	}
	LNode* p;		//指向当前扫描到的结点
	int j = 0;		//当前p指向的是第几个结点
	p = L;			//L指向头结点， 头结点是第0个结点（不存数据）
	while (p != NULL && j < i - 1)//循环找到第i - 1个结点
	{
		p = p->next;
		j++;
	}
	if (p == NULL)//判断i值是否合法
	{
		return false;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));//创建一个新结点
	s->data = e;					//存储数值
	s->next = p->next;				//将结点s连到p之后
	p->next = s;					//两句操作不可颠倒
	return true;					//插入成功
}

//不带头结点的按位序插入
bool ListInsert(LinkList& L, int i, int e)
{
	if (i < 1)//位序合法性检测
	{
		return false;
	}
	if (i == 1)//插入第一个结点
	{
		LNode* s = (LNode*)malloc(sizeof(LNode));
		s->data = e;
		s->next = L;
		L = s;				//头指针指向新节点
		return true;
	}
	LNode* p;		//指向当前扫描到的结点
	int j = 1;		//当前p指向的是第几个结点
	p = L;			//L指向头结点， 头结点是第0个结点（不存数据）
	while (p != NULL && j < i - 1)//循环找到第i - 1个结点
	{
		p = p->next;
		j++;
	}
	if (p == NULL)//判断i值是否合法
	{
		return false;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));//创建一个新结点
	s->data = e;					//存储数值
	s->next = p->next;				//将结点s连到p之后
	p->next = s;					//两句操作不可颠倒
	return true;					//插入成功
}

//在第i个位置后插入元素e（带头结点）
bool ListInsert(LinkList& L, int i, int e)
{
	if (i < 1)
	{
		return false;
	}
	LNode* p;	//指针p指向当前扫描到的结点
	int j = 0;	//当前p指向的是第几个结点
	p = L;		//L指向头结点，头结点是第0个结点（不存数据）
	while (p != NULL && j < i - 1)				//循环找到第i - 1个结点
	{
		p = p->next;
		j++;
	}
	if (p == NULL)	//i值合法性判断
	{
		return false;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;		//用结点s保存数据元素e
	s->next = p->next;	//将结点s连到p之后
	p->next = s;
	return true;
}

//在p结点前插入元素e（带头结点）
//（说是前插，但是没有前一个结点的地址，所以新开辟一个结点，当要前插的结点的数据保存到新结点，然后再将需要保存数据放入要前插的结点，实现前插操作）
bool InsertPriorNode(LNode* p, int e)
{
	if (p == NULL)
	{
		return false;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)//内存分配失败
	{
		return false;
	}
	s->next = p->next;		//后继
	p->next = s;			//前驱
	s->data = p->data;		//数据交换
	p->data = e;			//赋值
	return true;
}

//按位序删除（带头结点）
bool ListDelete(LinkList& L, int i, int& e)
{
	if (i < 1)
	{
		return false;
	}
	LNode* p;		//指针p指向当前扫描到的结点
	int j = 0;		//当前p指向的是第几个结点
	p = L;			// L指向头结点，头结点是第0个结点（不存数据）
	while (p != NULL && j < i - 1)   //循环找到第i - 1 个结点
	{
		p = p->next;
		j++;
	}
	if (p == NULL)						//i 值不合法
	{
		return false;
	}
	if (p->next == NULL)				//第i - 1个结点之后已无其他节点
	{
		return false;
	}
	LNode* q = p->next;					//q 指向被删除结点
	e = q->data;						//保存被删除的值
	p->next = q->next;					//将q结点从链中断开
	free(q);							//释放空间
	return true;
}

//指定节点的删除(类似于前插操作)
bool DeleteNode(LNode* p)
{
	if (p == NULL)
	{
		return false;
	}
	LNode* q = p->next;		//q指向p的后继结点
	p->data = p->next->data;//和后继结点交换数据域（p->next可能是NULL, 有空指针的错误）
	p->next = q->next;		//将*q结点从链表中断开
	free(p);				//释放后继结点的存储空间
	return true;
}

//单链表的按位查找
//这部分代码和前面的插入和删除中的一部分完全相同，所以可以调用这个函数
LNode* GetElem(LinkList L, int i)
{
	if (i < 0)
	{
		return NULL;
	}
	LNode* p;//同上
	int j = 0;
	p = L;
	while (p != NULL && j < i)	//循环找到第i个结点
	{
		p = p->next;
		j++;
	}
	return p;
}

//单链表的按值查找
LNode* LocateElem(LinkList L, int e)
{
	LNode* p = L->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
	}
	return p;
}

//求表长
int Length(LinkList L)
{
	int len = 0;
	LNode* p = L;
	while (p->next != NULL)
	{
		p = p->next;
		len++;
	}
	return len;
}

bool test()
{
	LinkList L;
	Init(L);
}

int main()
{

	return 0;
}
