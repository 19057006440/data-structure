//#include <iostream>
//using namespace std;
////������������ͬ���£���Ȩ·��������С����
////��Ȩ�����ķ���������
//typedef char** HuffmanCode;
////���������Ĵ洢(һά�ṹ������)
//typedef struct
//{
//	int weight;		//Ȩֵ
//	int parent, lch, rch;
//}HTNode, *HuffmanTree;
//
//int CreatHuffmanTree(HuffmanTree HT, int n)//�����������
//{
//	//��ʼ��
//	if (n <= 1)
//	{
//		return ;
//	}
//	int m = 2 * n - 1;//���鹲2n-1��Ԫ��
//	HT = new HTNode[m + 1];//0��δ�ã�HT[m]��ʾ�����
//	for (size_t i = 1; i < m; i++)//��2n-1��Ԫ�ص�parent, lch, rch��Ϊ0
//	{
//		HT[i].lch = 0;
//		HT[i].rch = 0;
//		HT[i].parent = 0;
//
//	}
//	//����Ȩֵ
//	for (size_t i = 1; i <= n; i++)//����ǰn��Ԫ�ص�weightֵ
//	{
//		cin >> HT[i].weight;
//	}
//	//�ϲ�����n - 1����� -- �����������
//	for (size_t i = n + 1; i < m; i++)
//	{
//		Select(HT, i - 1, s1, s2);//��HT[k](1 <= k <= i - 1)��ѡ��������˫����==0
//		HT[s1].parent = i;//�ӱ���ɾ��s1��s2
//		HT[s2].parent = i;
//		HT[i].lch = s1;//s1��s2�ֱ���Ϊi�����Һ���
//		HT[i].rch = s2;
//		HT[i].weight = HT[s1].weight + HT[s2].weight;//i��Ȩֵ��Ϊ���Һ���Ȩֵ֮��
//	}
//}
//
//
////����������
//void CreatHuffmanCode(HuffmanTree HT, HuffmanCode& HC, int n)
//{//��Ҷ�ӵ���������ÿ���ַ��Ĺ��������룬�洢�ڱ����HC��
//	HC = new char* [n + 1];	//����n���ַ������ͷָ��ʸ��
//	char* cd = new char[n];		//������ʱ��ű���Ķ�̬����ռ�
//	cd[n - 1] = '\0';		//���������
//	int start, c, f;
//	for (size_t i = 1; i <= n; i++)	//�����ַ������������
//	{
//		start = n - 1;
//		c = i;
//		f = HT[i].parent;
//		while (f != 0)//��Ҷ�ӽڵ㿪ʼ���ϻ��ݣ�ֱ�������
//		{
//			--start;			//����һ��start��ǰָһ��λ��
//			if (HT[f].lch == c)//���Ӿ���0���Һ��Ӿ���1
//			{
//				cd[start] = '0';
//			}
//			else
//			{
//				cd[start] = '1';
//			}
//			c = f;
//			f = HT[f].parent;//������ǰ����
//		}//�����i���ַ��ı���
//		HC[i] = new char[n - start];//Ϊ��i���ַ����������ռ�
//		strcpy(HC[i], &cd[start]);		//����õı������ʱ�ռ�cd���Ƶ�HC��ǰ����
//	}
//	delete cd;					
//}
#include<stdio.h>
#include<iostream>
using namespace std;
//������������
typedef struct {
	int weight;
	int parent, lchild, rchild;
}HTNode, * HuffmanTree;

//ѡ������˫����Ϊ0��Ȩֵ��С�Ľ�㣬��������HT�е����s1��s2
void Select(HuffmanTree& HT, int n, int& s1, int& s2)
{
	//Ѱ�ҵ�һ��˫����Ϊ0��Ȩֵ��С�Ľ��
	int min;
	for (int i = 1; i <= n; i++)	//�ҵ���һ��˫����Ϊ0�ģ��±��ݴ浽min
	{
		if (HT[i].parent == 0)
		{
			min = i;
			break;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (HT[i].parent == 0)
		{
			if (HT[i].weight < HT[min].weight)
			{
				min = i;
			}
		}
	}
	s1 = min;

	//Ѱ�ҵڶ���˫����Ϊ0��Ȩֵ��С�Ľ��
	for (int i = 1; i <= n; i++)	//�ҵ���һ��˫����Ϊ0�ģ��±��ݴ浽min
	{
		if (HT[i].parent == 0 && i != s1)
		{
			min = i;
			break;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (HT[i].parent == 0 && i != s1)
		{
			if (HT[i].weight < HT[min].weight)
			{
				min = i;
			}
		}
	}
	s2 = min;
}

//������������
void CreateHuffmanTree(HuffmanTree& HT, int n, int* ht)
{
	//��ʼ��
	int i, m = 2 * n - 1, s1, s2;		//mΪ���н��ĸ���
	if (n <= 1) return;
	HT = new HTNode[m + 1];				//0�Ų��ô�1��ʼ��������һ�У�ǰ1~n���Ҷ�ӽ��
	for (i = 1; i <= m; ++i)			//����ÿһ����㲢��ֵΪ0
	{
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}

	//������
	for (i = 1; i <= n; ++i)			//��Ҷ�ӽ��Ȩֵ�������
	{
		HT[i].weight = ht[i - 1];
	}
	for (int i = n + 1; i <= m; ++i)     //�ӷ�Ҷ�ӽ�㿪ʼ����
	{
		Select(HT, i - 1, s1, s2);		//ѡ��������С�Ľ��

		HT[s1].parent = i;
		HT[s2].parent = i;				//��Ҷ�ӽ��˫������
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}

//����������
typedef char** HuffmanCode;		//�����������ָ������
char* cd;						//������ʱ��ŵ�ǰ�������ĵ�i���ַ��ı���
int start;						//cd������±�ָ��

void CreatHuffmanCode(HuffmanTree HT, HuffmanCode& HC, int n, int* ht)
{
	int i, c, f;
	HC = new char* [n + 1];
	cd = new char[n];
	cd[n - 1] = '\0';
	for (i = 1; i <= n; ++i)
	{
		start = n - 1;
		c = i;						//��ǰ���
		f = HT[i].parent;			//˫�׽��

		while (f != 0)				//��Ϊcd�����startָ��Ӻ���ǰ�����Թ��������������ϼ���Ҷ�ӵ��������бȽϣ�
		{
			if (HT[f].lchild == c) cd[--start] = '0';
			else				   cd[--start] = '1';
			c = f;
			f = HT[f].parent;
		}
		HC[i] = new char[n - start];
		strcpy(HC[i], &cd[start]);

		//���
		printf("%d->", ht[i - 1]);
		for (int j = start; j <= n - 1; ++j)
		{
			printf("%c ", cd[j]);
		}
		printf("\n");

	}
	delete[] cd;
}

int main() {
	HuffmanTree HT;						//���������
	HuffmanCode HC;						//����������
	int n = 8;							//nΪҶ�ӽڵ�ĸ���
	int ht[8] = { 5,29,7,8,14,23,3,11 };

	CreateHuffmanTree(HT, n, ht);
	CreatHuffmanCode(HT, HC, n, ht);
	return 0;
}