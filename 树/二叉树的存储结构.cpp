 #include <iostream>
//顺序存储（知识和存储完全二叉树（空间））
using namespace std;

#define MaxSize 100
typedef int Elemtype;
struct TreeNode
{
	Elemtype value;	//存储数据元素
	bool isEmpty;	//结点是否为空
};

//链式存储
typedef struct BiTNode
{
	Elemtype data;
	struct BiTNode* lchild, * rchild;
	//struct BiTNode *parent;
}BiTNode, *BiTree;

//创建一个二叉树
bool CreateBitTree(BiTree& T);

//先序遍历：根左右
//中序遍历：左根右
//后续遍历：左右根

//先序遍历
bool PreOrderTraverse(BiTree T, bool (*Visit)(Elemtype e));

//中序遍历
bool PostOrderTraverse(BiTree T, bool (*Visit)(Elemtype e));

//后续遍历
bool LevelOrderTraverse(BiTree T, bool (*Visit)(Elemtype e));

bool CreateBitTree(BiTree& T)
{
	Elemtype c;
	cin >> c;
	if ('#' == c)             //当遇到#时，令树的根节点为NULL，从而结束该分支的递归
		T = NULL;
	else
	{
		T = new BiTree;
		T->data = c;
		CreateBitTree(T->lchild);
		CreateBitTree(T->rchild);
	}
}

bool Visit(Elemtype e)
{
	printf("%d", e);
	return true;
}

bool PreOrderTraverse(BiTree T, bool (*Visit)(Elemtype e))
{
	if (T)
	{
		if (Visit(T->data))
		{
			if (PreOrderTraverse(T->lchild, Visit))
			{
				if (PreOrderTraverse(T->rchild, Visit))
				{
					return true;
				}
			}
		}
	}
}

bool PostOrderTraverse(BiTree T, bool (*Visit)(Elemtype e))
{
	if (T)
	{
		if (PostOrderTraverse(T->lchild, Visit))
		{
			if (Visit(T->data))
			{
				if (PostOrderTraverse(T->rchild, Visit))
				{
					return true;
				}
			}
		}
	}
}

bool LevelOrderTraverse(BiTree T, bool (*Visit)(Elemtype e))
{
	if (T)
	{
		if (LevelOrderTraverse(T->lchild, Visit))
		{
			if (LevelOrderTraverse(T->rchild, Visit))
			{
				if (Visit(T->data))
				{
					return true;
				}
			}
		}
	}
}