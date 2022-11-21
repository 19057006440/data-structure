//#include <iostream>
//using namespace std;
////哈夫曼树：相同度下，带权路径长度最小的树
////把权重最大的放在最上面
//typedef char** HuffmanCode;
////哈夫曼树的存储(一维结构体数组)
//typedef struct
//{
//	int weight;		//权值
//	int parent, lch, rch;
//}HTNode, *HuffmanTree;
//
//int CreatHuffmanTree(HuffmanTree HT, int n)//构造哈夫曼树
//{
//	//初始化
//	if (n <= 1)
//	{
//		return ;
//	}
//	int m = 2 * n - 1;//数组共2n-1个元素
//	HT = new HTNode[m + 1];//0号未用，HT[m]表示根结点
//	for (size_t i = 1; i < m; i++)//将2n-1个元素的parent, lch, rch置为0
//	{
//		HT[i].lch = 0;
//		HT[i].rch = 0;
//		HT[i].parent = 0;
//
//	}
//	//输入权值
//	for (size_t i = 1; i <= n; i++)//输入前n个元素的weight值
//	{
//		cin >> HT[i].weight;
//	}
//	//合并产生n - 1个结点 -- 构造哈夫曼树
//	for (size_t i = n + 1; i < m; i++)
//	{
//		Select(HT, i - 1, s1, s2);//在HT[k](1 <= k <= i - 1)中选择两个其双亲域==0
//		HT[s1].parent = i;//从表中删除s1，s2
//		HT[s2].parent = i;
//		HT[i].lch = s1;//s1、s2分别作为i的左右孩子
//		HT[i].rch = s2;
//		HT[i].weight = HT[s1].weight + HT[s2].weight;//i的权值作为左右孩子权值之和
//	}
//}
//
//
////哈夫曼编码
//void CreatHuffmanCode(HuffmanTree HT, HuffmanCode& HC, int n)
//{//从叶子到根逆向求每个字符的哈夫曼编码，存储在编码表HC中
//	HC = new char* [n + 1];	//分配n个字符编码的头指针矢量
//	char* cd = new char[n];		//分配临时存放编码的动态数组空间
//	cd[n - 1] = '\0';		//编码结束符
//	int start, c, f;
//	for (size_t i = 1; i <= n; i++)	//出个字符求哈夫曼编码
//	{
//		start = n - 1;
//		c = i;
//		f = HT[i].parent;
//		while (f != 0)//从叶子节点开始向上回溯，直道根结点
//		{
//			--start;			//回溯一次start向前指一个位置
//			if (HT[f].lch == c)//左孩子就是0，右孩子就是1
//			{
//				cd[start] = '0';
//			}
//			else
//			{
//				cd[start] = '1';
//			}
//			c = f;
//			f = HT[f].parent;//继续向前回溯
//		}//求出第i个字符的编码
//		HC[i] = new char[n - start];//为第i个字符串编码分配空间
//		strcpy(HC[i], &cd[start]);		//将求得的编码从临时空间cd复制到HC当前行中
//	}
//	delete cd;					
//}
#include<stdio.h>
#include<iostream>
using namespace std;
//哈夫曼树定义
typedef struct {
	int weight;
	int parent, lchild, rchild;
}HTNode, * HuffmanTree;

//选择两个双亲域为0且权值最小的结点，并返回在HT中的序号s1，s2
void Select(HuffmanTree& HT, int n, int& s1, int& s2)
{
	//寻找第一个双亲域为0且权值最小的结点
	int min;
	for (int i = 1; i <= n; i++)	//找到第一个双亲域为0的，下标暂存到min
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

	//寻找第二个双亲域为0且权值最小的结点
	for (int i = 1; i <= n; i++)	//找到第一个双亲域为0的，下标暂存到min
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

//创建哈夫曼树
void CreateHuffmanTree(HuffmanTree& HT, int n, int* ht)
{
	//初始化
	int i, m = 2 * n - 1, s1, s2;		//m为所有结点的个数
	if (n <= 1) return;
	HT = new HTNode[m + 1];				//0号不用从1开始，多申请一行，前1~n存放叶子结点
	for (i = 1; i <= m; ++i)			//遍历每一个结点并赋值为0
	{
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}

	//创建树
	for (i = 1; i <= n; ++i)			//把叶子结点权值放入表中
	{
		HT[i].weight = ht[i - 1];
	}
	for (int i = n + 1; i <= m; ++i)     //从非叶子结点开始创建
	{
		Select(HT, i - 1, s1, s2);		//选择两个最小的结点

		HT[s1].parent = i;
		HT[s2].parent = i;				//把叶子结点双亲域赋上
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}

//哈夫曼编码
typedef char** HuffmanCode;		//哈夫曼编码表，指针数组
char* cd;						//用来临时存放当前正在求解的第i个字符的编码
int start;						//cd数组的下标指针

void CreatHuffmanCode(HuffmanTree HT, HuffmanCode& HC, int n, int* ht)
{
	int i, c, f;
	HC = new char* [n + 1];
	cd = new char[n];
	cd[n - 1] = '\0';
	for (i = 1; i <= n; ++i)
	{
		start = n - 1;
		c = i;						//当前结点
		f = HT[i].parent;			//双亲结点

		while (f != 0)				//因为cd数组的start指针从后往前，所以哈夫曼树从下往上即从叶子到根结点进行比较，
		{
			if (HT[f].lchild == c) cd[--start] = '0';
			else				   cd[--start] = '1';
			c = f;
			f = HT[f].parent;
		}
		HC[i] = new char[n - start];
		strcpy(HC[i], &cd[start]);

		//输出
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
	HuffmanTree HT;						//构造哈夫曼
	HuffmanCode HC;						//哈夫曼编码
	int n = 8;							//n为叶子节点的个数
	int ht[8] = { 5,29,7,8,14,23,3,11 };

	CreateHuffmanTree(HT, n, ht);
	CreatHuffmanCode(HT, HC, n, ht);
	return 0;
}