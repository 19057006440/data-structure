#include <stdio.h>
#include <stdlib.h>

typedef struct LNode	//定义单链表结点类型
{
	int data;			//数据域
	struct LNode* next;//指针域，指向下一个结点
}LNode, * LinkList;

typedef struct DNode	//定义双链表结点类型
{
	int data;
	struct DNode* prior, * next;
}DNode, * DLinkList;


//循环单链表
bool Init(LinkList& L)
{
	L = (LNode*)malloc(sizeof(LNode));
	if (L = NULL)
	{
		return false;
	}
	L->next = L;
	return true;
}

//判断循环单链表是否为空
bool Empty(DLinkList L)
{
	if (L->next == L)
	{
		return true;
	}
	return false;
}

//判断结点p是否为循环单链表的尾结点
bool isTail(DLinkList L, DNode* p)
{
	if (p->next == L)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//循环双链表
bool Init(DLinkList& L)
{
	L = (DNode*)malloc(sizeof(DNode));
	if (L = NULL)
	{
		return false;
	}
	L->prior = L; 		//头结点的前指针指向自己
	L->next = L;		//头结点的尾指针指向自己
	return true;
}

//判断循环双链表是否为空
bool Empty(DLinkList L)
{
	if (L->next == L)
	{
		return true;
	}
	return false;
}

//判断结点p是否为循环双链表的尾结点
bool isTail(DLinkList L, DNode* p)
{
	if (p->next == L)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//循环双链表的插入(与双链表相比少了是否为表尾的操作)
bool InsertNextNode(DNode* p, DNode* s)
{
	if (p == NULL || s == NULL)
	{
		return false;
	}
	s->next = p->next;		//画图好理解
	p->next->prior = s;
	s->prior = p;
	p->next = s;
	return true;
}

//循环双链表的删除(与双链表相比少了是否为表尾的操作)
bool DeleteNextDNode(DNode* p)
{
	if (p == NULL)
	{
		return false;
	}
	DNode* q = p->next;	//找到p的后继结点
	if (q == NULL)		//判断p是否为最后一个结点
	{
		return false;
	}
	p->next = q->next;
	q->next->prior = p;
	free(q);
	return true;
}
