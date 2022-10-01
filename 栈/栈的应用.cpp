#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//����ƥ��

#define MaxSize 10

typedef struct 
{
	char data[MaxSize];
	int top;
}SqStack;

void InitStack(SqStack& S)//��ʼ��
{
	S.top = -1;
}

bool StackEmpyt(SqStack& S)//ջ��
{
	if (-1 == S.top)
	{
		return true;
	}
	return false;
}

bool Push(SqStack& S, char x)//��ջ
{
	if (S.top == MaxSize -1)
	{
		return false;
	}
	S.top++;
	S.data[S.top] = x;
	return true;
}

bool Pop(SqStack& S, char& x)//��ջ
{
	if (S.top == -1)
	{
		return false;
	}
	x = S.data[S.top];
	S.top--;
	return true;
}

bool bracketCheck(char str[], int length)
{
	SqStack S;
	InitStack(S);
	for (int i = 0; i < length; i++)
	{
		if (str[i] == '{' || str[i] == '[' || str[i] == '(')//ɨ�赽�����ž���ջ
		{
			Push(S, str[i]);
		}
		else
		{
			if (StackEmpyt(S)) //ɨ�赽�����Ŷ��ҵ�ǰջ��
			{
				return false;	//ƥ��ʧ��
			}
			char topElem;
			Pop(S, topElem);//ջ��Ԫ�س�ջ
			if (str[i] ==')' && topElem != '(')
			{
				return false;
			}
			if (str[i] == ']' && topElem != '[')
			{
				return false;
			}
			if (str[i] == '}' && topElem != '{')
			{
				return false;
			}
		}
	}
	return StackEmpyt(S);//	������ȫ�����ź�ջ��˵��ƥ��ɹ�
}
