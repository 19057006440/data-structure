#include <stdio.h>
#include <stdlib.h>

//循环队列
#define MaxSize 10
typedef struct
{
	int data[MaxSize];	//静态数组存放
	int front, rear;	//队头指针和队尾指针
}SqQueue;

//初始化队列
void Init(SqQueue& Q)
{
	//初始时，队头、队尾指针指向0;
	Q.rear = 0;
	Q.front = 0;
}

bool Insert(SqQueue& Q, int x)
{
	if ((Q.rear + 1) % MaxSize == Q.front)	//队满报错
	{
		return false;
	}
	Q.data[Q.rear] = x;	//插入新元素
	Q.rear = (Q.rear + 1) % MaxSize;//队尾指针加一取模
	//用模运算将存储空间在逻辑上变成了“环状”
	return true;
}

bool DeQueue(SqQueue& Q, int& x)
{
	if (Q.rear == Q.front)//判断队列是否为空
	{
		return false;
	}
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	return true;
}

//获得头元素的值，用x返回
bool GetHead(SqQueue Q, int& x)
{
	if (Q.rear == Q.front)
	{
		return false;
	}
	x = Q.data[Q.front];
	return true;
}

//队列元素个数 == (reae+MaxSize-front)&MaxSize 

//判断队列是否为空
bool QueueEmpty(SqQueue Q)
{
	if (Q.rear==Q.front)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void testQueue()
{
	SqQueue Q;
	Init(Q);
}

int main()
{

}