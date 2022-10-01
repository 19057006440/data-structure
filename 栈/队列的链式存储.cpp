#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode//链式队列结点
{
	int data;
	struct LinkNode* next;
}LinkNode;

typedef struct //链式队列
{
	LinkNode* front, * rear;//队列的对头和队尾指针
}LinkQueue;

//队列初始化（带头结点）
void Init(LinkQueue& Q)
{	//初始时，front，rear都指向头结点
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
}

//队列初始化（不带头结点）
void Init(LinkQueue& Q)
{	//初始时，front，rear都指向NULL
	Q.front = Q.rear = NULL;
}

//判断队列是否为空（带头结点）
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

//判断队列是否为空（不带头结点）
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

//入队操作（带头结点）
void EnQueue(LinkQueue& Q, int x)
{
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	Q.rear->next = s;		//新节点插入到rear之后
	Q.rear = s;				//修改表尾指针
}

//入队操作（不带头结点）
void EnQueue(LinkQueue& Q, int x)
{
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	if (Q.front == NULL)//在空队列中插入第一个元素
	{
		Q.front = s;		//修改队头， 队尾指针
		Q.rear = s;
	}
	else
	{
		Q.rear->next = s;		//新节点插入到rear之后
		Q.rear = s;				//修改表尾指针
	}
}

//出队（带头结点）
bool DeQueue(LinkQueue& Q, int& x)
{
	if (Q.front == Q.rear)//空队
	{
		return false;
	}
	LinkNode* p = Q.front->next;
	x = p->data;
	Q.front->next = p->next;	//修改头结点的next指针
	if (Q.rear == p)			//最后一个结点出队
	{								
		Q.rear = Q.front;		
	}
	free(p);
	return true;
}


//出队（不带头结点）
bool DeQueue(LinkQueue& Q, int& x)
{
	if (Q.front == Q.rear)//空队
	{
		return false;
	}
	LinkNode* p = Q.front;
	x = p->data;
	Q.front = p->next;			//修改头结点的next指针
	if (Q.rear == p)			//最后一个结点出队
	{
		Q.rear = Q.front = NULL;
	}
	free(p);
	return true;
}