#include <stdio.h>
#include <stdlib.h>

//ʵ���Ͼ��ǹ涨��ֻ��ͷ�����β��ĵ�����
typedef struct Linknode
{
	int data;					//������
	struct Linknode* next;		//ָ����
}*LiStack;						//ջ���Ͷ���

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