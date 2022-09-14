#include <stdio.h>
#include <stdlib.h>

typedef struct DNode
{
	int data;
	struct DNode* prior, * next;
}DNode, *DLinkList;

//��ʼ��˫������ͷ��㣩
bool InitDLinkList(DLinkList& L)
{
	L = (DNode*)malloc(sizeof(DNode));//����һ��ͷ���
	if (L = NULL)
	{
		return false;
	}
	L->prior = NULL;	//ͷ����prior��Զָ��NULL
	L->next = NULL;
	return false;
}

//��p���֮�����s���
bool InsertNextNode(DNode* p, DNode* s)
{
	if (p == NULL || s == NULL)
	{
		return false;
	}
	s->next = p->next;		//��ͼ�����
	if (p->next != NULL)
	{
		p->next->prior = s;
	}
	s->prior = p;
	p->next = s;
	return true;
}

//ɾ��p���ĺ�̽��
bool DeleteNextDNode(DNode* p)
{
	if (p == NULL)
	{
		return false;
	}
	DNode* q = p->next;	//�ҵ�p�ĺ�̽��
	if (q == NULL)		//�ж�p�Ƿ�Ϊ���һ�����
	{
		return false;
	}
	p->next = q->next;	
	if (q->next != NULL)	//q�������һ�����
	{
		q->next->prior = p;
	}
	free(q);
	return true;
}

//˫����ı���
bool traverse(DLinkList& p)
{
	//�������
	while (p != NULL)
	{
		p = p->next;
	}
	//ǰ�����
	while (p != NULL)
	{
		p = p->prior;
	}
	//ǰ�����������ͷ��㣩
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