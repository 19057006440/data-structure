

typedef int ElemType;
//˫�ױ�ʾ��
typedef struct PTNode
{
	ElemType data;
	int parent;//˫��λ����
}PTNode;

#define MAX_TREE_SIZE 100

typedef struct
{
	PTNode nodes[MAX_TREE_SIZE];
	int r, n;//������λ�úͽ�����
}PTree;