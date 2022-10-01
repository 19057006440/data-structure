#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10
#define InitSize 10
//��̬˳�����
//typedef struct
//{
//	int data[MaxSize];
//	int length;
//}SqList;
//

//��̬˳���
typedef struct
{
	int* data;
	int maxsize;
	int length;
}SeqList;

//void InitList(SqList& L)//���ô���
//{
//	for (int i = 0; i < MaxSize; i++)
//	{
//		L.data[i] = 0;
//	}
//	L.length = 0;
//}
//
void print(SeqList& L)//���
{
	for (int i = 0; i < L.length; i++)
	{
		printf("data[%d] = %d\n", i, L.data[i]);
	}
	return;
}

void Init(SeqList& L)
{
	L.data = (int*)malloc(InitSize * sizeof(int));//malloc����
	for (int i = 0; i < InitSize; i++)
	{
		L.data[i] = 0;
	}
	L.length = 0;
	L.maxsize = InitSize;
}

void IncreaseSize(SeqList& L, int len)
{
	int* p = L.data;
	L.data = (int*)malloc((L.maxsize + len) * sizeof(int));
	for (int i = 0; i < L.length; i++)//ֵ�ĸ���
	{
		L.data[i] = p[i];
	}
	L.maxsize = L.maxsize + len;
	free(p);//�ͷ�ԭ���Ŀռ�
	return;
}

bool insert(SeqList& L, int i, int e)//��L�ĵ�iλ����Ԫ��e
{
	if (i < 1 || i > L.length + 1)
	{
		return false;
	}
	if (L.length >= MaxSize)
	{
		return false;
	}
	for (int j = L.length; j >= i; j--)//���������
	{
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;//��ֵ
	L.length++; 
	return true;
}

void bef(SeqList& L)//��ʼ��
{
	for (int i = 0; i < 9; i++)
	{
		L.data[i] = i;
		L.length++;
	}
}

bool Delete(SeqList& L, int i, int& e)//ɾ����i��λ�õ�ֵ
{
	if (i < 1|| i > L.length)//�Ϸ����ж�
	{
		return false;
	}
	e = L.data[i - 1];//����ɾ����Ԫ�ظ�ֵ��e
	for (int j = i; j < L.length; j++)
	{
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	return true;
}

bool elemget(SeqList& L, int i)//��λ����
{
	return L.data[i - 1];
}

int LocateElem(SeqList& L, int e)//��ֵ����
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] == e)//����������ĸ����������ͣ�����Ҫ�Լ��ֶ��ж������ṹ���Ӧ�ĳ�Ա�Ƿ���ͬ
		{
			return i + 1;
		}
	}
	return 0;//��ѯʧ��
}

int main()
{
	SeqList L;
	Init(L);
	bef(L);

	//int e = 0;
	//if (Delete(L, 1, e))
	//{
	//	printf("��ɾ����1��Ԫ�أ�ɾ��Ԫ��Ϊ%d\n", e);
	//}
	//else
	//{
	//	printf("λ��i���Ϸ�");
	//}
	//LocateElem(L, 12);
	print(L);
	return 0;
}