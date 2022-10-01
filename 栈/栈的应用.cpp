#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//¿®∫≈∆•≈‰

#define MaxSize 10

typedef struct 
{
	char data[MaxSize];
	int top;
}SqStack;

void InitStack(SqStack& S)//≥ı ºªØ
{
	S.top = -1;
}

bool StackEmpyt(SqStack& S)//’ªø’
{
	if (-1 == S.top)
	{
		return true;
	}
	return false;
}

bool Push(SqStack& S, char x)//»Î’ª
{
	if (S.top == MaxSize -1)
	{
		return false;
	}
	S.top++;
	S.data[S.top] = x;
	return true;
}

bool Pop(SqStack& S, char& x)//≥ˆ’ª
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
		if (str[i] == '{' || str[i] == '[' || str[i] == '(')//…®√ËµΩ◊Û¿®∫≈æÕ»Î’ª
		{
			Push(S, str[i]);
		}
		else
		{
			if (StackEmpyt(S)) //…®√ËµΩ”“¿®∫≈∂¯«“µ±«∞’ªø’
			{
				return false;	//∆•≈‰ ß∞‹
			}
			char topElem;
			Pop(S, topElem);//’ª∂•‘™Àÿ≥ˆ’ª
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
	return StackEmpyt(S);//	ºÏÀ˜ÕÍ»´≤ø¿®∫≈∫Û£¨’ªø’Àµ√˜∆•≈‰≥…π¶
}
