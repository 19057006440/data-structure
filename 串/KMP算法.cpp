#include <stdio.h>
#include <stdlib.h>
#include <iostream>

const int Len = 25;

typedef struct
{
	char ch[Len];
	int length;
}String;

void GetNextArr(String SubString, int* next)//获得next数组
{
	int j = 0, k = -1;
	next[0] = -1;
	while (j < SubString.length - 1)
	{
		if (k == -1 || SubString.ch[j] == SubString.ch[k])
		{
			++j;
			++k;//若pj == pk，则next[k + 1] = next[k] + 1
			next[j] = k;
		}
		else
		{
			//否则令j = next[j]，循环继续
			k = next[k];
		}
	}
}

int KMP(String S, String SubString)
{
	int next[Len], i = 0, j = 0;
	GetNextArr(SubString, next);
	while (i < S.length && j < SubString.length)
	{
		if (j == -1 || S.ch[i] == SubString.ch[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];	//j回退
		}
	}
	if (j >= SubString.length)
	{
		return (i - SubString.length);
	}
	else
	{
		return -1;
	}
}

