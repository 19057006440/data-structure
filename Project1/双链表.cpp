#include <stdio.h>
#include <stdlib.h>

typedef struct DNode
{
	int data;
	struct DNode* prior, * next;
}DNode, *DLinkList;

//初始化双链表（带头结点）
bool InitDLinkList(DLinkList& L)
{
	L = (DNode*)malloc(sizeof(DNode));//分配一个头结点
	if (L = NULL)
	{
		return false;
	}
	L->prior = NULL;	//头结点的prior永远指向NULL
	L->next = NULL;
	return false;
}

//在p结点之后插入s结点
bool InsertNextNode(DNode* p, DNode* s)
{
	if (p == NULL || s == NULL)
	{
		return false;
	}
	s->next = p->next;		//画图好理解
	if (p->next != NULL)
	{
		p->next->prior = s;
	}
	s->prior = p;
	p->next = s;
	return true;
}

//删除p结点的后继结点
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
	if (q->next != NULL)	//q不是最后一个结点
	{
		q->next->prior = p;
	}
	free(q);
	return true;
}

//双链表的遍历
bool traverse(DLinkList& p)
{
	//后向遍历
	while (p != NULL)
	{
		p = p->next;
	}
	//前向遍历
	while (p != NULL)
	{
		p = p->prior;
	}
	//前向遍历（跳过头结点）
	while (p->prior  != NULL)
	{
		p = p->prior;
	}
}

void testDLinkList()
{
	DLinkList L;
	InitDLinkList(L);
}

int main()
{
	return 0;
}