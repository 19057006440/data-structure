#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define MAXLEN 255

typedef struct//静态数组实现
{
	char ch[MAXLEN];
	int length;
}SString;

int Index(SString S, SString T)
{
	int k = 1;
	int i = k, j = 1;
	while (i <= S.length && j <= T.length)
	{
		if (S.ch[i] == T.ch[j])
		{
			++i;
			++j;//继续比较后续字符
		}
		else
		{
			k++;
			i = k;
			j = 1;//检查下一个字串
		}
	}
	if (j > T.length)
	{
		return k;
	}
	else
	{
		return 0;
	}
}

