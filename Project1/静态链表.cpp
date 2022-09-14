#include <stdio.h>
#include <stdlib.h>

//用数组的方式实现链表

#define MaxSize 10

typedef struct Node
{
	int data;		//存储元素
	int next;		//下一个元素的数组下标
}SLinkList[MaxSize];



void testSLinkList()
{
	SLinkList a;	//定义的是一个数组
}

