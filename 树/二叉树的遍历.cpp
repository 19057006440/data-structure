#include <iostream>

//�ݹ��㷨


//�������: DLR 
//�������: LDR
//�������: LRD 

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

Status PreOrderTraverse(BiTree T)//���������������
{
	if (T == NULL)
	{
		return true;
	}
	else
	{
		Visit(T);					//���ʸ��ڵ�
		PreOrderTraverse(T->lchild);//�ݹ����������
		PreOrderTraverse(T->rchild);//�ݹ����������
	}
}

Status InOrderTraverse(BiTree T)//��������������
{
	if (T == NULL)
	{
		return true;
	}
	else
	{
		InOrderTraverse(T->lchild);//�ݹ����������
		InOrderTraverse(T->rchild);//�ݹ����������
		Visit(T);					//���ʸ��ڵ�
	}
}

Status PostOrderTraverse(BiTree T)//������������Ҹ�
{
	if (T == NULL)
	{
		return true;
	}
	else
	{
		InOrderTraverse(T->lchild);//�ݹ����������
		Visit(T);					//���ʸ��ڵ�
		InOrderTraverse(T->rchild);//�ݹ����������
	}
}



//�ǵݹ��㷨
//��������ǵݹ��㷨����ջ����


/*
Status InOrderTraverse(BiTree T)
{
	BiTree p;
	InitStack(S);		//��ʼ��һ��ջ
	p = T;
	while (p||StackEmpyt(S))
	{
		if (p)
		{
			Push(S, p); //�ѵ�ǰԪ��pѹ��ջ��
			p = p->lchild;
		}
		else
		{
			Pop(S, q);//�ѵ�ǰԪ�ص���ջ���洢��q��
			printf("%c", q->data);
			p = q->rchild;
		}
	}
	return true;
}
*/