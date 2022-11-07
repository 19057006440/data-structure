#include <iostream>

typedef int ElemType;

typedef struct BiNode
{
	ElemType data;
	struct BiNode* lchild, * rchild;//左右孩子指针
}BiNode, *BiTree;

//三叉链表

typedef struct TriNode
{
	ElemType data;
	struct TriNode* lchild, * parent, * rchild;
}TriNode, *TriTree;
