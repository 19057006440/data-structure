#include <iostream>
//线索二叉树

typedef struct BiThrNode
{
	int data;
	int ltag, rtag;//两个标志域，为0表示正常的左右子节点，为1表示存储前驱和后继
	struct BiThrNode* lchlid, * rchild;
}BiThrNdoe, *BiThrTree;

//增加一个头结点，第一个节点的lchild和最后一个节点的rchlid指向它