#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define MAXLEN 255

typedef struct//��̬����ʵ��
{
	char ch[MAXLEN];
	int length;
}SString;

typedef struct//��̬����ʵ��
{
	char* ch;
	int length;
}HString;

typedef struct StringNode//������ʽ�洢
{
	char ch[4];	//ÿ�����洢4���ַ�, ��ߴ洢�ܶ�
	struct StringNode* next;
}StringNode, *String;

//��̬����
//���ִ�
bool SubString(SString &Sub, SString S, int pos, int len)
{
	//�ִ���ΧԽ��
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
 
//�Ƚϲ���
//��S > T�� ����ֵ > 0;��S = t�� �򷵻�ֵ = 0����S < T, �򷵻�ֵ < 0
int SreCompare(SString S, SString T)
{
	for (int i = 1; i < S.length && i <= T.length; i++)
	{
		if (S.ch[i] != T.ch[i])
		{
			return S.ch[i] - T.ch[i];
		}
	}
	//ɨ������е��ַ�����ͬ���򳤶ȴ�Ĵ�����
	return S.length - T.length;
}
 
//��λ����
int Index(SString S, SString T)
{
	int i = 1, n = StrLength(S), m = StrLength(T);
	SString sub;//�ݴ��Ӵ�
	while (i <= n - m + 1)
	{
		SubString(sub, S, i, m);
		if (StrCompare(sub, T) != 0)
		{
			++i;
		}
		else
		{
			return i;//�����Ӵ��������е�λ��
		}
	}
	return 0;	//S�в�������T��ȵ��Ӵ�
}

