#include <stdio.h>
#include <stdlib.h>

//实际上就是规定了只能头插或者尾插的单链表
typedef struct Linknode
{
	int data;					//数据域
	struct Linknode* next;		//指针域
}*LiStack;						//栈类型定义

bool Init(LiStack& L)
{
	L = NULL;
	return true;
}

bool Insert(LiStack& L, int x)
{
	if (L == NULL)
	{
		return false;
	}
	Linknode* New = (Linknode*)malloc(sizeof(Linknode));
	if (New == NULL)
	{
		return false;
	}
	New->data = x;
	L->next = New;
	New->next == NULL;
	return true;
}

bool Delete(LiStack& L, int &x)
{

}

int main()
{

}