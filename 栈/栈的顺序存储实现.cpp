#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10
typedef struct stack
{
	int data[MaxSize];	//静态数组中存放栈中元素
	int top;			//栈顶指针
}SqStack;

//初始化栈
void Init(SqStack& S)
{
	S.top = -1;			//初始化栈顶指针
}

//新元素入栈
bool Push(SqStack& S, int x)
{
	if (S.top == MaxSize - 1)	//栈满
	{
		return false;
	}
	S.top = S.top + 1;			//指针加1
	S.data[S.top] = x;			//新元素入栈
	//上面两个合起来等价于S.data[++S.top] = x
	return true;
}

//出栈操作
bool Pop(SqStack& S, int& x)
{
	if (S.top == -1)		//栈空
	{
		return false;
	}
	x = S.data[S.top];		//栈顶元素先出栈
	S.top-- ;				//指针再减一
	//上面两个合起来等价于x = S.data[S.top--]
	return true;
}

//读取栈顶元素
bool GetTop(SqStack& S, int& x)
{
	if (S.top == -1)		//栈空
	{
		return false;
	}
	x = S.data[S.top];		//x记录栈顶元素
	return true;
}


void testStack()
{
	SqStack S;			//声明一个顺序栈
	Init(S);			
}

int main()
{

	return 0;
}