// ConsoleApplication10.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stack>
#include <queue>
using namespace std;
#define ElemType int

typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lChild, *rChild;
}BiTnode, *BiTree;

void insert(BiTree& T, ElemType x) //层序插入
{
    queue<BiTNode*> Q;

    BiTNode *n = new BiTNode;
    n->data = x;
    n->lChild = nullptr;
    n->rChild = nullptr;

	BiTNode* p = T;
	Q.push(T);
	while (!Q.empty())
	{
		p = Q.front();
		Q.pop();
		if (p->lChild != NULL)
		{
			Q.push(p->lChild);
		}
        if (p->lChild == NULL)
		{
			p->lChild = n;
			return;
		}
		if (p->rChild != NULL)
		{
			Q.push(p->rChild);
		}
		if (p->rChild == NULL)
		{
			p->rChild = n;
			return;
		}
	}
}

void insert2(BiTree& T, ElemType x) //单链树(无右节点）
{
    BiTNode* n = new BiTNode;
    n->data = x;
    n->lChild = nullptr;
    n->rChild = nullptr;

    BiTNode* p = T;
    while (true)
    {
        if (p->lChild == NULL)
        {
            p->lChild = n;
            return;
        } 
        else
        {
            p = p->lChild;
        }
    }
}

void preOrder(BiTree T) //前序遍历
{
    if (T != NULL)
    {
        cout << T->data << endl;
        preOrder(T->lChild);
        preOrder(T->rChild);
    }
}


void preOrder2(BiTree T) {
    stack<BiTNode *> S;
    BiTree p = T;
    while (p || !S.empty())
    {
        if (p)
        {
            cout << p->data;
            S.push(p);
            p = p->lChild;
        }
        else
        {
            p = S.top();
            S.pop();
            p = p->rChild;
        }
    }
}


void inOrder(BiTree T) //中序遍历(递归）
{
    if (T != NULL)
    {
        inOrder(T->lChild);
        cout << T->data << endl;
        inOrder(T->rChild);
    }
}


void inOrder2(BiTree T) //中序遍历（遍历）
{
    stack<BiTree> S;
    BiTree p = T;
    while (p || !S.empty())
    {
        if (p)
        {
            S.push(p);
            p = p->lChild;
        }
        else
        {
            p = S.top();
            cout << S.top()->data << endl;
            S.pop();
            p = p->rChild;
        }
    }
}


void postOrder(BiTree T) //后序遍历（递归）
{
    if (T != NULL) 
    {
        postOrder(T->lChild);
        postOrder(T->rChild);
        cout << T->data << endl;
    }
}

void postOrder2(BiTree T) //迭代后序
{
    stack<BiTNode *> S;
    BiTNode* p = T;
    BiTNode* r = NULL;

    while (p || !S.empty())
    {
        if (p)
        {
            S.push(p);
            p = p->lChild;
        }
        else
        {
            p = S.top();
            if ((p->rChild != NULL) && (r != p->rChild))
            {
                p = p->rChild;
                S.push(p);
                p = p->lChild;
            }
            else //是叶节点 或 右子节点已被访问过
            {
                cout << S.top()->data << endl;
                S.pop();
                r = p;
                p = NULL;
            }
        }
    }
}

void levelOrder(BiTree T) //层序遍历
{
    queue<BiTNode *> Q;
    BiTree p = T; 
    Q.push(p);
    while (!Q.empty())
    {
        p = Q.front();
        cout << p->data << endl;
        Q.pop();
        if (p->lChild != NULL)
        {
            Q.push(p->lChild);
        }
        if (p->rChild != NULL)
        {
            Q.push(p->rChild);
        }
    }
}

int searchTreeDeepth(BiTree T) //返回二叉树深度（节点最大层数） 根节点深度为一
{
    BiTNode* p = T;
    BiTNode* r = T;
    stack<BiTNode*> S;
    S.push(T);
    int maxLayer = 0;
    int layerCount = 1;
   
    while (!S.empty())
    {
        if (((r == p->lChild) && (p->rChild == NULL)) || (r == p->rChild)) {
            r = p;
            p = S.top();
            S.pop();
        }
        else if ((p->lChild != nullptr) && (r != p->lChild))
        {
            S.push(p->lChild);
            layerCount++;
            p = p->lChild;
        } 
        else if ((p->rChild != nullptr) && (r != p->rChild))
        {
            S.push(p->rChild);
            layerCount++;
            p = p->rChild;
        }
        else if ((p->lChild == NULL) && (p->rChild == NULL))
        {
            if (layerCount > maxLayer)
            {
                maxLayer = layerCount;
            }
            r = p;
            p = S.top();
            S.pop();
            layerCount--;
        }
    }
    return maxLayer;
}



void levelOrder2(BiTree T) // 自下而上 自右到左的层序遍历
{
    queue<BiTNode*> q;
    stack<BiTNode*> S;
    BiTNode *p = T;
    q.push(p);
    while (!q.empty())
    {
        S.push(q.front());
        p = q.front();
        q.pop();
        if (p->lChild != NULL)
        {
            q.push(p->lChild);
        }
        if (p->rChild != NULL)
        {
            q.push(p->rChild);
        }
    }

    while (!S.empty())
    {
        cout << S.top()->data <<endl;
        S.pop();
    }
}

int main()
{
    BiTree T = new BiTNode;
    T->data = -1;
    T->lChild = nullptr;
    T->rChild = nullptr;
    for (int i = 0; i < 10; i++)
    {
        insert(T, i);
    }
 
    inOrder(T);
    cout << searchTreeDeepth(T);
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
