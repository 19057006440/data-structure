#include <stdio.h>
#include <stdlib.h>


typedef struct LNode	//定义单链表结点类型
{
	int data;			//数据域
	struct LNode* next;//指针域，指向下一个结点
}LNode, * LinkList;
//建立单链表
//先初始化一个单链表
//然后每次取一个数据元素，插入到表尾/表头

//1、Init()
//2、ListInsert()

//尾插法
LinkList List_Tailnsert(LinkList& L)//正向建立单链表
{
	int x;
	L = (LinkList)malloc(sizeof(LNode));//建立头结点
	LNode* s, * r = L;					//r为表尾指针
	scanf("%d", &x);					//输入结点的值
	while (x != 9999)					
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;				//r指向新的表尾结点
		scanf("%d", &x);
	}
	r->next = NULL;		//尾结点置为空
	return L;
}

//头插法
LinkList List_Headlnsert(LinkList& L)//逆向建立单链表
{
	LNode* s;				
	int x;
	L = (LinkList)malloc(sizeof(LNode));//建立头结点
	L->next = NULL;						//初始为空链表
	scanf("%d", &x);					//输入结点的值
	while (x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));//创建新结点
		s->data = x;
		s->next = L->next ;
		L->next = s;				//r指向新的表尾结点
		scanf("%d", &x);
	}
	return L;
}
int main()
{
	
	return 0;
}