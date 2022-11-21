

typedef int ElemType;
//1·双亲表示法
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


//2·孩子链表
//孩子节点结构
typedef struct CTNode
{
	int child;
	struct CTNode* next;
}*ChildPtr;

//双亲结点结构
typedef struct
{
	int data;
	ChildPtr firstchild;//孩子链表头指针
}CTBox;

//树结构
typedef struct
{
	CTBox nodes[MAX_TREE_SIZE];
	int n, r;//节点数和根结点的位置
}CTree;

//3·孩子兄弟表示法(二叉树表示法，二叉链表表示法)

typedef struct CSNode
{
	int data;
	struct CSNode* firstchild, * nextsibling;
	//左指针指向左孩子，右指针指向右边的第一个兄弟节点
}CSNode, *CSTree;

//树与二叉树的转换
// 树变成二叉树
//通过二叉链表，兄弟结点实际上就是对应二叉树的右孩子
//兄弟相连留左子，然后旋转45

//二叉树变为树
//左孩右右连双亲，去掉原来右孩线





//森林转换成二叉树
//树变二叉根相连



//二叉树转换为森林
//去掉全部右孩线，孤立二叉再还原

