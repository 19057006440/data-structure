#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10
typedef struct stack
{
	int data[MaxSize];	//��̬�����д��ջ��Ԫ��
	int top;			//ջ��ָ��
}SqStack;

//��ʼ��ջ
void Init(SqStack& S)
{
	S.top = -1;			//��ʼ��ջ��ָ��
}

//��Ԫ����ջ
bool Push(SqStack& S, int x)
{
	if (S.top == MaxSize - 1)	//ջ��
	{
		return false;
	}
	S.top = S.top + 1;			//ָ���1
	S.data[S.top] = x;			//��Ԫ����ջ
	//���������������ȼ���S.data[++S.top] = x
	return true;
}

//��ջ����
bool Pop(SqStack& S, int& x)
{
	if (S.top == -1)		//ջ��
	{
		return false;
	}
	x = S.data[S.top];		//ջ��Ԫ���ȳ�ջ
	S.top-- ;				//ָ���ټ�һ
	//���������������ȼ���x = S.data[S.top--]
	return true;
}

//��ȡջ��Ԫ��
bool GetTop(SqStack& S, int& x)
{
	if (S.top == -1)		//ջ��
	{
		return false;
	}
	x = S.data[S.top];		//x��¼ջ��Ԫ��
	return true;
}


void testStack()
{
	SqStack S;			//����һ��˳��ջ
	Init(S);			
}

int main()
{

	return 0;
}