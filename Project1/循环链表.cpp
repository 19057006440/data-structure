#include <stdio.h>
#include <stdlib.h>

typedef struct LNode	//���嵥����������
{
	int data;			//������
	struct LNode* next;//ָ����ָ����һ�����
}LNode, * LinkList;

typedef struct DNode	//����˫����������
{
	int data;
	struct DNode* prior, * next;
}DNode, * DLinkList;


//ѭ��������
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

//�ж�ѭ���������Ƿ�Ϊ��
bool Empty(DLinkList L)
{
	if (L->next == L)
	{
		return true;
	}
	return false;
}

//�жϽ��p�Ƿ�Ϊѭ���������β���
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

//ѭ��˫����
bool Init(DLinkList& L)
{
	L = (DNode*)malloc(sizeof(DNode));
	if (L = NULL)
	{
		return false;
	}
	L->prior = L; 		//ͷ����ǰָ��ָ���Լ�
	L->next = L;		//ͷ����βָ��ָ���Լ�
	return true;
}

//�ж�ѭ��˫�����Ƿ�Ϊ��
bool Empty(DLinkList L)
{
	if (L->next == L)
	{
		return true;
	}
	return false;
}

//�жϽ��p�Ƿ�Ϊѭ��˫�����β���
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

//ѭ��˫����Ĳ���(��˫������������Ƿ�Ϊ��β�Ĳ���)
bool InsertNextNode(DNode* p, DNode* s)
{
	if (p == NULL || s == NULL)
	{
		return false;
	}
	s->next = p->next;		//��ͼ�����
	p->next->prior = s;
	s->prior = p;
	p->next = s;
	return true;
}

//ѭ��˫�����ɾ��(��˫������������Ƿ�Ϊ��β�Ĳ���)
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
	q->next->prior = p;
	free(q);
	return true;
}
