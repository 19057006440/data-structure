#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_OP 20

typedef struct vector
{
	int* data;//存储的数据
	int size;//顺序表总长度
	int length;//顺序表已经存储的长度
}vector;

vector* init(int n);//初始化
int insert(vector* vec, int ind, int val);//插入
int expand(vector* vec);//拓展
int erase(vector* vec, int ind);//删除
void clear(vector* vec);//清空
void output(vector* vec);//输出

int main0()
{

	srand(time(0));
	int op, ind, val;
	vector* vec = init(1);
	for (int i = 0; i < MAX_OP; i++)
	{
		op = rand() % 4;
		ind = rand() & (vec->length + 1);
		val = rand() % 100;
		switch (op)
		{
			case 2:
			case 3:
			case 0:
			{
				printf("insert %d at %d to vector\n", val, ind);
				insert(vec, ind, val);
				break;
			}
			case 1:
			{
				printf("erase item at %d from vector\n", ind);
				erase(vec, ind);
				break;
			}
		}
		output(vec);
		printf("\n");
	}
	return 0;
}

vector* init(int n)//顺序表初始化
{
	vector* vec = (vector*)malloc(sizeof(vector));
	vec->data = (int*)malloc(sizeof(int) * n);
	vec->size = n;
	vec->length = 0;
	return vec;
}

int expand(vector* vec)
{
	int new_size = vec->size * 2;
	int* p = (int*)realloc(vec->data, sizeof(int) * new_size);
	if (p == NULL)
	{
		return 0;
	}
	vec->size == new_size;
	vec->data = p;
	return 1;
}

int insert(vector* vec, int ind, int val)//插入
{
	if (vec == NULL)//合法性检测
	{
		return 0;
	}
	if (vec->length == vec->size)//满了，扩容
	{
		if (!expand(vec))
		{
			return 0;
		}
		printf("expand vector size to %d success\n", vec->size);
	}
	if (ind < 0 || ind > vec->length)//插入的位置不对
	{
		return 0;
	}
	for (int i = vec->length; i >= ind; i--)//从后往前移动
	{
		vec->data[i] = vec->data[i - 1];
	}
	vec->data[ind] = val;
	vec->length++;
	return 1;
}

int erase(vector* vec, int ind)
{
	if (vec == NULL)//合法性检测
	{
		return 0;
	}
	if (vec->length == 0)//没有数据
	{
		return 0;
	}
	if (ind < 0 || ind >= vec->length)//插入的位置不对
	{
		return 0;
	}
	for (int i = ind + 1; i < vec->length; i++)
	{
		vec->data[i - 1] = vec->data[i];
	}
	vec->length--;
	return 1;
}

void clear(vector* vec)//顺序表的销毁
{
	if (vec == NULL)
	{
		return;
	}
	free(vec->data);
	free(vec);
	return;
}

void output(vector* vec)
{
	printf("array(%d) = [", vec->length);
	for (int i = 0; i < vec->length; i++)
	{
		if (i != 0)
		{
			printf(", ");
		}
		printf("%d", vec->data[i]);
	}
	printf("]\n");
	return;
}