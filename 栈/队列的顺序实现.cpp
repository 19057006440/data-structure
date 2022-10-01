#include <stdio.h>
#include <stdlib.h>

//ѭ������
#define MaxSize 10
typedef struct
{
	int data[MaxSize];	//��̬������
	int front, rear;	//��ͷָ��Ͷ�βָ��
}SqQueue;

//��ʼ������
void Init(SqQueue& Q)
{
	//��ʼʱ����ͷ����βָ��ָ��0;
	Q.rear = 0;
	Q.front = 0;
}

bool Insert(SqQueue& Q, int x)
{
	if ((Q.rear + 1) % MaxSize == Q.front)	//��������
	{
		return false;
	}
	Q.data[Q.rear] = x;	//������Ԫ��
	Q.rear = (Q.rear + 1) % MaxSize;//��βָ���һȡģ
	//��ģ���㽫�洢�ռ����߼��ϱ���ˡ���״��
	return true;
}

bool DeQueue(SqQueue& Q, int& x)
{
	if (Q.rear == Q.front)//�ж϶����Ƿ�Ϊ��
	{
		return false;
	}
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	return true;
}

//���ͷԪ�ص�ֵ����x����
bool GetHead(SqQueue Q, int& x)
{
	if (Q.rear == Q.front)
	{
		return false;
	}
	x = Q.data[Q.front];
	return true;
}

//����Ԫ�ظ��� == (reae+MaxSize-front)&MaxSize 

//�ж϶����Ƿ�Ϊ��
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