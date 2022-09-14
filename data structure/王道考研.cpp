#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10
#define InitSize 10
//静态顺序表定义
//typedef struct
//{
//	int data[MaxSize];
//	int length;
//}SqList;
//

//动态顺序表
typedef struct
{
	int* data;
	int maxsize;
	int length;
}SeqList;

//void InitList(SqList& L)//引用传递
//{
//	for (int i = 0; i < MaxSize; i++)
//	{
//		L.data[i] = 0;
//	}
//	L.length = 0;
//}
//
void print(SeqList& L)//输出
{
	for (int i = 0; i < L.length; i++)
	{
		printf("data[%d] = %d\n", i, L.data[i]);
	}
	return;
}

void Init(SeqList& L)
{
	L.data = (int*)malloc(InitSize * sizeof(int));//malloc分配
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
	for (int i = 0; i < L.length; i++)//值的复制
	{
		L.data[i] = p[i];
	}
	L.maxsize = L.maxsize + len;
	free(p);//释放原来的空间
	return;
}

bool insert(SeqList& L, int i, int e)//在L的第i位插入元素e
{
	if (i < 1 || i > L.length + 1)
	{
		return false;
	}
	if (L.length >= MaxSize)
	{
		return false;
	}
	for (int j = L.length; j >= i; j--)//依次向后排
	{
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;//赋值
	L.length++; 
	return true;
}

void bef(SeqList& L)//初始化
{
	for (int i = 0; i < 9; i++)
	{
		L.data[i] = i;
		L.length++;
	}
}

bool Delete(SeqList& L, int i, int& e)//删除第i个位置的值
{
	if (i < 1|| i > L.length)//合法性判断
	{
		return false;
	}
	e = L.data[i - 1];//将被删除的元素赋值给e
	for (int j = i; j < L.length; j++)
	{
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	return true;
}

bool elemget(SeqList& L, int i)//按位查找
{
	return L.data[i - 1];
}

int LocateElem(SeqList& L, int e)//按值查找
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] == e)//如果是其他的复杂数据类型，就需要自己手动判断两个结构体对应的成员是否都相同
		{
			return i + 1;
		}
	}
	return 0;//查询失败
}

int main()
{
	SeqList L;
	Init(L);
	bef(L);

	//int e = 0;
	//if (Delete(L, 1, e))
	//{
	//	printf("已删除第1个元素，删除元素为%d\n", e);
	//}
	//else
	//{
	//	printf("位序i不合法");
	//}
	//LocateElem(L, 12);
	print(L);
	return 0;
}