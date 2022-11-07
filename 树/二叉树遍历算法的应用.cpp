#include <iostream>

typedef int Status, Elemtype;

typedef struct BiTNode
{
	Elemtype data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

//1���������Ľ���

Status CreateBiTree(BiTree& T)
{
	char ch;
	std::cin >> ch;
	if (ch == '#')
	{
		T = NULL;
	}
	else
	{
		if (!(T = new BiTNode))
		{
			exit(OVERFLOW);
		}
		T->data = ch;
		CreateBiTree(T->lchild);//����������
		CreateBiTree(T->rchild);//����������
	}
	return true;
}

//2�����ƶ�����
//�ȸ��Ƹ���㣬Ȼ��ݹ鸴����������
int Copy(BiTree T, BiTree& NewT) 
{
	if (T == NULL)//����ǿ����ͷ���0
	{
		NewT = NULL;
		return 0;
	}
	else
	{
		NewT = new BiTNode;
		NewT->data = T->data;
		Copy(T->lchild, NewT->lchild);
		Copy(T->rchild, NewT->rchild);
	}
}

//3����������������

int Depth(BiTree T)
{
	int m = 0, n = 0;
	if (T == NULL)
	{
		return 0;
	}
	else
	{
		m = Depth(T->lchild);//�����������
		n = Depth(T->rchild);//�����������
		if (m > n)
		{
			return (m + 1);
		}
		else
		{
			return (n + 1);
		}
	}
}

//4����������еĽ�����
//�������ڵ����Ϊ0
//������Ϊ�������Ľ�����+�������Ľ�����+1
int NodeCount(BiTree T)
{
	if (T == NULL)
	{
		return 0;
	}
	else
	{
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
	}
}

//5������Ҷ�ӽڵ����
//Ҷ�ӽڵ����Ϊ�������Ľ�����+�������Ľ�����+1
int LeafCount(BiTree T)
{
	if (T == NULL)//����
	{
		return 0;
	}
	if (T->lchild == NULL && T->rchild == NULL)//Ҷ�ӽڵ㣨����1��
	{
		return 1;
	}
	else
	{
		return LeafCount(T->lchild) + LeafCount(T->rchild);
	}
}

