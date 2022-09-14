#include <stdio.h>
#include <stdlib.h>

typedef struct LNode	//���嵥����������
{
	int data;			//������
	struct LNode* next;//ָ����ָ����һ�����
}LNode, * LinkList;

//����ͷ�ڵ�ĵ�����
bool Init(LinkList& L)//��ʼ��
{
	L = NULL;
	return true;
}

//��ͷ�ڵ�ĵ�����(���洢����)
bool Init(LinkList& L)//��ʼ��
{ 
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL)
	{
		return false;
	}
	L->next = NULL;
	return true;
}

LNode* GetElem(LinkList L, int i)//����һ���ڵ㣬LinkListǿ��������һ��������
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

//��ͷ���İ�λ�����
bool ListInsert(LinkList& L, int i, int e)
{
	if (i < 1)//λ��Ϸ��Լ��
	{
		return false;
	}
	LNode* p;		//ָ��ǰɨ�赽�Ľ��
	int j = 0;		//��ǰpָ����ǵڼ������
	p = L;			//Lָ��ͷ��㣬 ͷ����ǵ�0����㣨�������ݣ�
	while (p != NULL && j < i - 1)//ѭ���ҵ���i - 1�����
	{
		p = p->next;
		j++;
	}
	if (p == NULL)//�ж�iֵ�Ƿ�Ϸ�
	{
		return false;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));//����һ���½��
	s->data = e;					//�洢��ֵ
	s->next = p->next;				//�����s����p֮��
	p->next = s;					//����������ɵߵ�
	return true;					//����ɹ�
}

//����ͷ���İ�λ�����
bool ListInsert(LinkList& L, int i, int e)
{
	if (i < 1)//λ��Ϸ��Լ��
	{
		return false;
	}
	if (i == 1)//�����һ�����
	{
		LNode* s = (LNode*)malloc(sizeof(LNode));
		s->data = e;
		s->next = L;
		L = s;				//ͷָ��ָ���½ڵ�
		return true;
	}
	LNode* p;		//ָ��ǰɨ�赽�Ľ��
	int j = 1;		//��ǰpָ����ǵڼ������
	p = L;			//Lָ��ͷ��㣬 ͷ����ǵ�0����㣨�������ݣ�
	while (p != NULL && j < i - 1)//ѭ���ҵ���i - 1�����
	{
		p = p->next;
		j++;
	}
	if (p == NULL)//�ж�iֵ�Ƿ�Ϸ�
	{
		return false;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));//����һ���½��
	s->data = e;					//�洢��ֵ
	s->next = p->next;				//�����s����p֮��
	p->next = s;					//����������ɵߵ�
	return true;					//����ɹ�
}

//�ڵ�i��λ�ú����Ԫ��e����ͷ��㣩
bool ListInsert(LinkList& L, int i, int e)
{
	if (i < 1)
	{
		return false;
	}
	LNode* p;	//ָ��pָ��ǰɨ�赽�Ľ��
	int j = 0;	//��ǰpָ����ǵڼ������
	p = L;		//Lָ��ͷ��㣬ͷ����ǵ�0����㣨�������ݣ�
	while (p != NULL && j < i - 1)				//ѭ���ҵ���i - 1�����
	{
		p = p->next;
		j++;
	}
	if (p == NULL)	//iֵ�Ϸ����ж�
	{
		return false;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;		//�ý��s��������Ԫ��e
	s->next = p->next;	//�����s����p֮��
	p->next = s;
	return true;
}

//��p���ǰ����Ԫ��e����ͷ��㣩
//��˵��ǰ�壬����û��ǰһ�����ĵ�ַ�������¿���һ����㣬��Ҫǰ��Ľ������ݱ��浽�½�㣬Ȼ���ٽ���Ҫ�������ݷ���Ҫǰ��Ľ�㣬ʵ��ǰ�������
bool InsertPriorNode(LNode* p, int e)
{
	if (p == NULL)
	{
		return false;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)//�ڴ����ʧ��
	{
		return false;
	}
	s->next = p->next;		//���
	p->next = s;			//ǰ��
	s->data = p->data;		//���ݽ���
	p->data = e;			//��ֵ
	return true;
}

//��λ��ɾ������ͷ��㣩
bool ListDelete(LinkList& L, int i, int& e)
{
	if (i < 1)
	{
		return false;
	}
	LNode* p;		//ָ��pָ��ǰɨ�赽�Ľ��
	int j = 0;		//��ǰpָ����ǵڼ������
	p = L;			// Lָ��ͷ��㣬ͷ����ǵ�0����㣨�������ݣ�
	while (p != NULL && j < i - 1)   //ѭ���ҵ���i - 1 �����
	{
		p = p->next;
		j++;
	}
	if (p == NULL)						//i ֵ���Ϸ�
	{
		return false;
	}
	if (p->next == NULL)				//��i - 1�����֮�����������ڵ�
	{
		return false;
	}
	LNode* q = p->next;					//q ָ��ɾ�����
	e = q->data;						//���汻ɾ����ֵ
	p->next = q->next;					//��q�������жϿ�
	free(q);							//�ͷſռ�
	return true;
}

//ָ���ڵ��ɾ��(������ǰ�����)
bool DeleteNode(LNode* p)
{
	if (p == NULL)
	{
		return false;
	}
	LNode* q = p->next;		//qָ��p�ĺ�̽��
	p->data = p->next->data;//�ͺ�̽�㽻��������p->next������NULL, �п�ָ��Ĵ���
	p->next = q->next;		//��*q���������жϿ�
	free(p);				//�ͷź�̽��Ĵ洢�ռ�
	return true;
}

//������İ�λ����
//�ⲿ�ִ����ǰ��Ĳ����ɾ���е�һ������ȫ��ͬ�����Կ��Ե����������
LNode* GetElem(LinkList L, int i)
{
	if (i < 0)
	{
		return NULL;
	}
	LNode* p;//ͬ��
	int j = 0;
	p = L;
	while (p != NULL && j < i)	//ѭ���ҵ���i�����
	{
		p = p->next;
		j++;
	}
	return p;
}

//������İ�ֵ����
LNode* LocateElem(LinkList L, int e)
{
	LNode* p = L->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
	}
	return p;
}

//���
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
