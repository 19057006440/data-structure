#include <iostream>

using namespace std;

typedef int Status, Elemtype;

const int MaxSize = 100;

typedef struct BTNode
{
	Elemtype data;
	struct BTNode* lchild, * rchild;
}BTNode, * BiTree;

//��Ҫ���ö���

typedef struct
{
	BTNode data[MaxSize];//��Ŷ���Ԫ��
	int front, rear;	//��ͷ�Ͷ�βָ��
}SqQueue;				//˳��ѭ����������

void LevelOrder(BTNode* b)
{
	BTNode* p;
	SqQueue* qu;
	InitQueue(qu);//��ʼ������
	enQueue(qu, b);//���ڵ�ָ��������
	while (!QueueEmpty(qu))//�Ӳ�Ϊ�գ��ͽ���ѭ��
	{
		deQueue(qu, p); //���ӽ��p
		printf("%d", p->data);//���ʽ��p
		if (p->lchild != NULL)//������ʱ����
		{
			enQueue(qu, p->lchild);
		}
		if (p->rchild != NULL)//���Һ���ʱ����
		{
			enQueue(qu, p->rchild);
		}
	}
}