#include <iostream>
//顺序存储（知识和存储完全二叉树（空间））
using namespace std;
typedef int Elemtype;
//先序遍历：根左右
//中序遍历：左根右
//后续遍历：左右根

typedef struct BiTNode
{
	Elemtype data;
	struct BitNode* lchild, * rchild;
}BiTNode, * BiTree;

//先序遍历
void PreOrder(BiTree T)
{
	if (T != NULL)
	{
		visit(T);			//访问根节点
		PreOrder(T->lchild); //递归遍历左子树
		PreOrder(T->rchild);	//递归遍历右子树
	}
}


//中序遍历
void InOrder(BiTree T)
{
	if (T != NULL)
	{
		InOrder(T->lchild); //递归遍历左子树
		visit(T);			//访问根节点
		InOrder(T->rchild);	//递归遍历右子树
	}
}

void PostOrder(BiTree T)
{
	if (T != NULL)
	{
		PostOrder(T->lchild); //递归遍历左子树
		PostOrder(T->rchild);	//递归遍历右子树
		visit(T);			//访问根节点
	}
}



int main()
{
	return 0;
}