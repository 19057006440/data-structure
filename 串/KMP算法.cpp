#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define MAXLEN 255

typedef struct//��̬����ʵ��
{
	char ch[MAXLEN];
	int length;
}SString;

//KMP�㷨

void get_next(SString T, int next[])
{
	int i = 1, j = 0;
	next[i] = 0;
	while (i < T.length)
	{
		if (j == 0 || T.ch[i] == T.ch[j])
		{
			++i;
			++j;//��pi == pj����next[j + 1] = next[j] + 1
			next[i] = j;
		}
		else
		{
			//������j = next[j]��ѭ������
			j = next[j];
		}
	}
}

int Index_KMP(SString S, SString T)
{
	int i = 1, j = 1;
	int next[T.length + 1];
	get_next(T, next);//��ģʽ����next����
	while (i <= S.length && j <= T.length)
	{
		if (j == 0||S.ch[i] == T.ch[j])
		{							//�����ȽϺ����ַ�
			++i; 
			++j;
		}
		else
		{
			j = next[j];	//ģʽ�������ƶ�
		}
	}
	if (j > T.length)
	{
		return i - T.length;//ƥ��ɹ�
	}
	else
	{
		return 0;
	}
}