#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_OP 30

typedef struct ListNode//节点
{
	int data;
	struct ListNode* next;
}ListNode;

typedef struct LinkList//链表
{
	ListNode* head;
	int length;
}LinkList;

ListNode* init_listnode(int val);//节点初始化
LinkList* init_linklist();//链表初始化
int insert(LinkList* l, int ind, int val);//插入
int erase(LinkList* l, int ind);//删除
void clear_listnode(ListNode* node);//清理节点
void clear_linklist(LinkList* l);//清理链表
void output(LinkList* l);//输出

int main()
{
	srand(time(0));

	LinkList* l = init_linklist();
	for (int i = 0; i < MAX_OP; i++)
	{
		int op = rand() % 3;
		int ind = rand() % (l->length + 1);
		int val = rand() % 100;
		switch (op)
		{
			case 0:
			case 1:
			{
				printf("insert %d at %d to LinkList = %d\n", val, ind, insert(l, ind, val));
				break;
			}
			case 2:
			{
				printf("erase item at %d frome LinkList = %d", ind, erase(l, ind));
				break;
			}
		}
		output(l);
		printf("\n");
	}
	return 0;
}

ListNode* init_listnode(int val)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = val;
	p->next = NULL;
	return p;
}

LinkList* init_linklist()
{
	LinkList* l = (LinkList*)malloc(sizeof(LinkList));
	l->head->next = NULL;
	l->length = 0;
	return 0;
}

int insert(LinkList* l, int ind, int val)
{
	if (l == NULL)
	{
		return 0;
	}
	if (ind<0 || ind>l->length)
	{
		return 0;
	}
	ListNode* p = l->head, * node = init_listnode(val);
	while (ind--)
	{
		p = p->next;
	}
	node->next = p->next;
	p->next = node;
	l->length++;
	return 1;
}

int erase(LinkList* l, int ind)
{
	if (l == NULL)
	{
		return 0;
	}
	if (ind < 0 || ind >= l->length)
	{
		return 0;
	}
	ListNode* p = l->head, * q;
	while (ind--)
	{
		p = p->next;
	}
	q = p->next->next;
	clear_listnode(p->next);
	p->next = q;
	l->length--;
	return 1;
}

void clear_listnode(ListNode* node)
{
	if (node == NULL)
	{
		return;
	}
	free(node);
	return;
}

void clear_linklist(LinkList* l)
{
	if (l == NULL)
	{
		return;
	}
	ListNode* p = l->head->next, * q;
	while (p)
	{
		q = p->next;
		clear_listnode(p);
		p = q;
	}
	free(l);
	return;
}

void output(LinkList* l)
{
	printf("LinkList(%d) : ", l->length);
	for (ListNode* p = l->head->next; p; p = p->next)
	{
		printf("%d -> ", p->data);
	}
	printf("NULL\n");
	return;
}
