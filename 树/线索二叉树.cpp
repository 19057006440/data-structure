#include <iostream>
//����������

typedef struct BiThrNode
{
	int data;
	int ltag, rtag;//������־��Ϊ0��ʾ�����������ӽڵ㣬Ϊ1��ʾ�洢ǰ���ͺ��
	struct BiThrNode* lchlid, * rchild;
}BiThrNdoe, *BiThrTree;

//����һ��ͷ��㣬��һ���ڵ��lchild�����һ���ڵ��rchlidָ����