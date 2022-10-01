#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define MAXLEN 255

typedef struct//静态数组实现
{
	char ch[MAXLEN];
	int length;
}SString;

typedef struct//动态数组实现
{
	char* ch;
	int length;
}HString;

typedef struct StringNode//串的链式存储
{
	char ch[4];	//每个结点存储4个字符, 提高存储密度
	struct StringNode* next;
}StringNode, *String;

//静态数组
//求字串
bool SubString(SString &Sub, SString S, int pos, int len)
{
	//字串范围越界
	if (pos + len - 1 > S.length)
	{
		return false;
	}
	for (int i = pos; i < pos + len; i++)
	{
		Sub.ch[i - pos + 1] = S.ch[i];
	}
	Sub.length = len;
	return true;
}
 
//比较操作
//若S > T， 返回值 > 0;若S = t， 则返回值 = 0；若S < T, 则返回值 < 0
int SreCompare(SString S, SString T)
{
	for (int i = 1; i < S.length && i <= T.length; i++)
	{
		if (S.ch[i] != T.ch[i])
		{
			return S.ch[i] - T.ch[i];
		}
	}
	//扫描过所有的字符都相同，则长度大的串更大
	return S.length - T.length;
}
 
//定位操作
int Index(SString S, SString T)
{
	int i = 1, n = StrLength(S), m = StrLength(T);
	SString sub;//暂存子串
	while (i <= n - m + 1)
	{
		SubString(sub, S, i, m);
		if (StrCompare(sub, T) != 0)
		{
			++i;
		}
		else
		{
			return i;//返回子串在主串中的位置
		}
	}
	return 0;	//S中不存在与T相等的子串
}

