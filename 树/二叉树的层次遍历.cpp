#include <iostream>

using namespace std;

typedef int Status, Elemtype;

const int MaxSize = 100;

typedef struct BTNode
{
	Elemtype data;
	struct BTNode* lchild, * rchild;
}BTNode, * BiTree;

//主要是用队列

typedef struct
{
	BTNode data[MaxSize];//存放队中元素
	int front, rear;	//对头和队尾指针
}SqQueue;				//顺序循环队列类型

void LevelOrder(BTNode* b)
{
	BTNode* p;
	SqQueue* qu;
	InitQueue(qu);//初始化队列
	enQueue(qu, b);//根节点指针进入队列
	while (!QueueEmpty(qu))//队不为空，就进入循环
	{
		deQueue(qu, p); //出队结点p
		printf("%d", p->data);//访问结点p
		if (p->lchild != NULL)//有左孩子时进队
		{
			enQueue(qu, p->lchild);
		}
		if (p->rchild != NULL)//有右孩子时进队
		{
			enQueue(qu, p->rchild);
		}
	}
}