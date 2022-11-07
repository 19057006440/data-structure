

typedef int ElemType;
//双亲表示法
typedef struct PTNode
{
	ElemType data;
	int parent;//双亲位置域
}PTNode;

#define MAX_TREE_SIZE 100

typedef struct
{
	PTNode nodes[MAX_TREE_SIZE];
	int r, n;//根结点的位置和结点个数
}PTree;