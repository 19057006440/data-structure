#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define MAXLEN 255

typedef struct//��̬����ʵ��
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
			++j;//�����ȽϺ����ַ�
		}
		else
		{
			k++;
			i = k;
			j = 1;//�����һ���ִ�
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

