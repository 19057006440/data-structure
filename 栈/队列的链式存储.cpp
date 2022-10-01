#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode//��ʽ���н��
{
	int data;
	struct LinkNode* next;
}LinkNode;

typedef struct //��ʽ����
{
	LinkNode* front, * rear;//���еĶ�ͷ�Ͷ�βָ��
}LinkQueue;

//���г�ʼ������ͷ��㣩
void Init(LinkQueue& Q)
{	//��ʼʱ��front��rear��ָ��ͷ���
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
}

//���г�ʼ��������ͷ��㣩
void Init(LinkQueue& Q)
{	//��ʼʱ��front��rear��ָ��NULL
	Q.front = Q.rear = NULL;
}

//�ж϶����Ƿ�Ϊ�գ���ͷ��㣩
bool IsEmpyt(LinkQueue& Q)
{
	if (Q.front == Q.rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//�ж϶����Ƿ�Ϊ�գ�����ͷ��㣩
bool IsEmpyt(LinkQueue& Q)
{
	if (Q.front == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//��Ӳ�������ͷ��㣩
void EnQueue(LinkQueue& Q, int x)
{
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	Q.rear->next = s;		//�½ڵ���뵽rear֮��
	Q.rear = s;				//�޸ı�βָ��
}

//��Ӳ���������ͷ��㣩
void EnQueue(LinkQueue& Q, int x)
{
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	if (Q.front == NULL)//�ڿն����в����һ��Ԫ��
	{
		Q.front = s;		//�޸Ķ�ͷ�� ��βָ��
		Q.rear = s;
	}
	else
	{
		Q.rear->next = s;		//�½ڵ���뵽rear֮��
		Q.rear = s;				//�޸ı�βָ��
	}
}

//���ӣ���ͷ��㣩
bool DeQueue(LinkQueue& Q, int& x)
{
	if (Q.front == Q.rear)//�ն�
	{
		return false;
	}
	LinkNode* p = Q.front->next;
	x = p->data;
	Q.front->next = p->next;	//�޸�ͷ����nextָ��
	if (Q.rear == p)			//���һ��������
	{								
		Q.rear = Q.front;		
	}
	free(p);
	return true;
}


//���ӣ�����ͷ��㣩
bool DeQueue(LinkQueue& Q, int& x)
{
	if (Q.front == Q.rear)//�ն�
	{
		return false;
	}
	LinkNode* p = Q.front;
	x = p->data;
	Q.front = p->next;			//�޸�ͷ����nextָ��
	if (Q.rear == p)			//���һ��������
	{
		Q.rear = Q.front = NULL;
	}
	free(p);
	return true;
}