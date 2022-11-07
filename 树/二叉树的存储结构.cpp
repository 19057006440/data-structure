 #include <iostream>
//˳��洢��֪ʶ�ʹ洢��ȫ���������ռ䣩��
using namespace std;

#define MaxSize 100
typedef int Elemtype;
struct TreeNode
{
	Elemtype value;	//�洢����Ԫ��
	bool isEmpty;	//����Ƿ�Ϊ��
};

//��ʽ�洢
typedef struct BiTNode
{
	Elemtype data;
	struct BiTNode* lchild, * rchild;
	//struct BiTNode *parent;
}BiTNode, *BiTree;

//����һ��������
bool CreateBitTree(BiTree& T);

//���������������
//��������������
//�������������Ҹ�

//�������
bool PreOrderTraverse(BiTree T, bool (*Visit)(Elemtype e));

//�������
bool PostOrderTraverse(BiTree T, bool (*Visit)(Elemtype e));

//��������
bool LevelOrderTraverse(BiTree T, bool (*Visit)(Elemtype e));

bool CreateBitTree(BiTree& T)
{
	Elemtype c;
	cin >> c;
	if ('#' == c)             //������#ʱ�������ĸ��ڵ�ΪNULL���Ӷ������÷�֧�ĵݹ�
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