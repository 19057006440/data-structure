#include <iostream>

typedef int ElemType;

typedef struct BiNode
{
	ElemType data;
	struct BiNode* lchild, * rchild;//���Һ���ָ��
}BiNode, *BiTree;

//��������

typedef struct TriNode
{
	ElemType data;
	struct TriNode* lchild, * parent, * rchild;
}TriNode, *TriTree;
