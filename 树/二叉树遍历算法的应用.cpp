#include <iostream>

typedef int Status, Elemtype;

typedef struct BiTNode
{
	Elemtype data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

//1、二叉树的建立

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
		CreateBiTree(T->lchild);//构造左子树
		CreateBiTree(T->rchild);//构造右子树
	}
	return true;
}

//2、复制二叉树
//先复制根结点，然后递归复制左右子树
int Copy(BiTree T, BiTree& NewT) 
{
	if (T == NULL)//如果是空树就返回0
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

//3、计算二叉树的深度

int Depth(BiTree T)
{
	int m = 0, n = 0;
	if (T == NULL)
	{
		return 0;
	}
	else
	{
		m = Depth(T->lchild);//左子树的深度
		n = Depth(T->rchild);//右子树的深度
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

//4、求二叉树中的结点个数
//空树：节点个数为0
//结点个数为左子树的结点个数+右子树的结点个数+1
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

//5、计算叶子节点个数
//叶子节点个数为左子树的结点个数+右子树的结点个数+1
int LeafCount(BiTree T)
{
	if (T == NULL)//空树
	{
		return 0;
	}
	if (T->lchild == NULL && T->rchild == NULL)//叶子节点（返回1）
	{
		return 1;
	}
	else
	{
		return LeafCount(T->lchild) + LeafCount(T->rchild);
	}
}

