#include <stdio.h>
#include <stdlib.h>


typedef struct LNode	//���嵥����������
{
	int data;			//������
	struct LNode* next;//ָ����ָ����һ�����
}LNode, * LinkList;
//����������
//�ȳ�ʼ��һ��������
//Ȼ��ÿ��ȡһ������Ԫ�أ����뵽��β/��ͷ

//1��Init()
//2��ListInsert()

//β�巨
LinkList List_Tailnsert(LinkList& L)//������������
{
	int x;
	L = (LinkList)malloc(sizeof(LNode));//����ͷ���
	LNode* s, * r = L;					//rΪ��βָ��
	scanf("%d", &x);					//�������ֵ
	while (x != 9999)					
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;				//rָ���µı�β���
		scanf("%d", &x);
	}
	r->next = NULL;		//β�����Ϊ��
	return L;
}

//ͷ�巨
LinkList List_Headlnsert(LinkList& L)//������������
{
	LNode* s;				
	int x;
	L = (LinkList)malloc(sizeof(LNode));//����ͷ���
	L->next = NULL;						//��ʼΪ������
	scanf("%d", &x);					//�������ֵ
	while (x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));//�����½��
		s->data = x;
		s->next = L->next ;
		L->next = s;				//rָ���µı�β���
		scanf("%d", &x);
	}
	return L;
}
int main()
{
	
	return 0;
}