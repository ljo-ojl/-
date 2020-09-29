#include <iostream>
typedef  int ElemType;
using namespace std;

//线索二叉树
typedef struct ThreadNode{
	ElemType data;
	bool ltag, rtag;
	struct ThreadNode* lChild, * rChild;
}ThreadNode, *ThreadTree;


//初始化
void initTree(ThreadTree &T) {
	T->data = -1;
	T->ltag = T->rtag = 0;
	T->lChild = T->rChild = NULL;
}


void insertNode(ThreadTree T, ElemType x)
{
	ThreadNode* tmp = new ThreadNode;
	tmp->data = x;
	tmp->ltag = tmp->rtag = 0;
	tmp->lChild = tmp->rChild = NULL;

	if (T->lChild == NULL)
	{
		T->lChild = tmp;
	}
}

//中序遍历对二叉树线索化
void InThread(ThreadTree &p, ThreadTree &pre)
{
	if (p != NULL)
	{
		InThread(p->lChild, pre);
		if (p->lChild == NULL)
		{
			p->lChild = pre;
			p->ltag = 1;
		}
		if (pre != NULL && pre->rChild == NULL)
		{
			pre->rChild = p;
			pre->rtag = 1;
		}
		pre = p;
		InThread(p->rChild, pre);
	}
}

void CreateInThread(ThreadTree T)
{
	ThreadTree pre = NULL;
	if (T != NULL)
	{
		InThread(T, pre);
		pre->rChild = NULL;
		pre->rtag;
	}
}

int main1()
{
	ThreadTree T = new ThreadNode;
	initTree(T);
	for (int i = 0; i < 10; i++)
	{
		insertNode(T, i);
	}


	return 0;
}