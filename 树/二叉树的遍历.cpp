#include <iostream>

//递归算法


//先序遍历: DLR 
//中序遍历: LDR
//后序遍历: LRD 

typedef int Status, Elemtype;
typedef struct BiTNode
{
	Elemtype data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

void Visit(BiTree T)
{
	printf("%d ", T->data);
	return;
}

Status PreOrderTraverse(BiTree T)//先序遍历，根左右
{
	if (T == NULL)
	{
		return true;
	}
	else
	{
		Visit(T);					//访问根节点
		PreOrderTraverse(T->lchild);//递归遍历左子树
		PreOrderTraverse(T->rchild);//递归遍历右子树
	}
}

Status InOrderTraverse(BiTree T)//中序遍历，左根右
{
	if (T == NULL)
	{
		return true;
	}
	else
	{
		InOrderTraverse(T->lchild);//递归遍历左子树
		InOrderTraverse(T->rchild);//递归遍历右子树
		Visit(T);					//访问根节点
	}
}

Status PostOrderTraverse(BiTree T)//后序遍历，左右根
{
	if (T == NULL)
	{
		return true;
	}
	else
	{
		InOrderTraverse(T->lchild);//递归遍历左子树
		Visit(T);					//访问根节点
		InOrderTraverse(T->rchild);//递归遍历右子树
	}
}



//非递归算法
//中序遍历非递归算法（用栈做）


/*
Status InOrderTraverse(BiTree T)
{
	BiTree p;
	InitStack(S);		//初始化一个栈
	p = T;
	while (p||StackEmpyt(S))
	{
		if (p)
		{
			Push(S, p); //把当前元素p压入栈中
			p = p->lchild;
		}
		else
		{
			Pop(S, q);//把当前元素弹出栈，存储在q中
			printf("%c", q->data);
			p = q->rchild;
		}
	}
	return true;
}
*/