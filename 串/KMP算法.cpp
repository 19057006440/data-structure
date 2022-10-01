#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define MAXLEN 255

typedef struct//静态数组实现
{
	char ch[MAXLEN];
	int length;
}SString;

//KMP算法

void get_next(SString T, int next[])
{
	int i = 1, j = 0;
	next[i] = 0;
	while (i < T.length)
	{
		if (j == 0 || T.ch[i] == T.ch[j])
		{
			++i;
			++j;//若pi == pj，则next[j + 1] = next[j] + 1
			next[i] = j;
		}
		else
		{
			//否则令j = next[j]，循环继续
			j = next[j];
		}
	}
}

int Index_KMP(SString S, SString T)
{
	int i = 1, j = 1;
	int next[T.length + 1];
	get_next(T, next);//求模式串的next数组
	while (i <= S.length && j <= T.length)
	{
		if (j == 0||S.ch[i] == T.ch[j])
		{							//继续比较后续字符
			++i; 
			++j;
		}
		else
		{
			j = next[j];	//模式串向右移动
		}
	}
	if (j > T.length)
	{
		return i - T.length;//匹配成功
	}
	else
	{
		return 0;
	}
}