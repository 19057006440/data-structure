#include <iostream>
//˳��洢��֪ʶ�ʹ洢��ȫ���������ռ䣩��
using namespace std;
typedef int Elemtype;
//���������������
//��������������
//�������������Ҹ�

typedef struct BiTNode
{
	Elemtype data;
	struct BitNode* lchild, * rchild;
}BiTNode, * BiTree;

//�������
void PreOrder(BiTree T)
{
	if (T != NULL)
	{
		visit(T);			//���ʸ��ڵ�
		PreOrder(T->lchild); //�ݹ����������
		PreOrder(T->rchild);	//�ݹ����������
	}
}


//�������
void InOrder(BiTree T)
{
	if (T != NULL)
	{
		InOrder(T->lchild); //�ݹ����������
		visit(T);			//���ʸ��ڵ�
		InOrder(T->rchild);	//�ݹ����������
	}
}

void PostOrder(BiTree T)
{
	if (T != NULL)
	{
		PostOrder(T->lchild); //�ݹ����������
		PostOrder(T->rchild);	//�ݹ����������
		visit(T);			//���ʸ��ڵ�
	}
}



int main()
{
	return 0;
}