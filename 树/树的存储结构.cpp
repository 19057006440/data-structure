

typedef int ElemType;
//1��˫�ױ�ʾ��
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


//2����������
//���ӽڵ�ṹ
typedef struct CTNode
{
	int child;
	struct CTNode* next;
}*ChildPtr;

//˫�׽��ṹ
typedef struct
{
	int data;
	ChildPtr firstchild;//��������ͷָ��
}CTBox;

//���ṹ
typedef struct
{
	CTBox nodes[MAX_TREE_SIZE];
	int n, r;//�ڵ����͸�����λ��
}CTree;

//3�������ֵܱ�ʾ��(��������ʾ�������������ʾ��)

typedef struct CSNode
{
	int data;
	struct CSNode* firstchild, * nextsibling;
	//��ָ��ָ�����ӣ���ָ��ָ���ұߵĵ�һ���ֵܽڵ�
}CSNode, *CSTree;

//�����������ת��
// ����ɶ�����
//ͨ�����������ֵܽ��ʵ���Ͼ��Ƕ�Ӧ���������Һ���
//�ֵ����������ӣ�Ȼ����ת45

//��������Ϊ��
//��������˫�ף�ȥ��ԭ���Һ���





//ɭ��ת���ɶ�����
//������������



//������ת��Ϊɭ��
//ȥ��ȫ���Һ��ߣ����������ٻ�ԭ

