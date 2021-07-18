#include "stack.h"
#include <cassert>
#include <cstdlib>
#include <cstdio>
#include "iostream"
bool CreateBiTree(BinTree& T)
{
    char ch;
    T = (BinTree)malloc(sizeof(TNode));
    if (T==0)
        exit(false);
    std::cin>> ch;
    if (ch == '0')
        T = NULL;
    else
    {
        T->Data = ch;
        CreateBiTree(T->Left);
        CreateBiTree(T->Right);
    }
    return true;
}


//三大遍历
bool Preorder(BinTree T)
{
    if (T == NULL)
        return false;

    if (T)
    {
        printf("%c ", T->Data);
        Preorder(T->Left);
        Preorder(T->Right);

    }
    return true;
}

bool Inorder(BinTree T)
{
    if (T == NULL)
        return false;

    if (T)
    {

        Inorder(T->Left);
        printf("%c ", T->Data);
        Inorder(T->Right);

    }
    return true;
}

bool Beorder(BinTree T)
{
    if (T == NULL)
        return false;

    if (T)
    {

        Beorder(T->Left);
        Beorder(T->Right);
        printf("%c ", T->Data);


    }
    return true;
}
//层序遍历
void Levelorder(BinTree T)
{
    Queue Q;
    Initqueue(Q);
    BinTree P;
    Enqueue(Q, T);
    while (!Isempty(Q))
    {
        Dequeue(Q, P);
        printf("%c ", P->Data);
        if (P->Left != NULL)
            Enqueue(Q, P->Left);
        if (P->Right != NULL)
            Enqueue(Q, P->Right);
    }

}
//利用前序和中序建立二叉树
TNode* buildtree(char preorder[], char inorder[], int size)
{
    if (size == 0)
        return NULL;
    char rootvalue = preorder[0];
    int r = -1;
    for(int i=0;i<size;i++)
        if (inorder[i] == rootvalue)
        {
            r = i;
            break;
        }
    assert(r != -1);
    TNode* root = (TNode*)malloc(sizeof(TNode));
    root->Data = rootvalue;
    root->Left = buildtree(preorder + 1, inorder, r);
    root->Right = buildtree(preorder + 1 + r, inorder + r + 1, size - 1 - r);
    return root;

}


int GetHeight(BinTree T)
{
    if (!T)
        return 0;
    int ldep = GetHeight(T->Left);
    int rdep = GetHeight(T->Right);
    if (ldep > rdep)
        return ldep + 1;
    else
        return rdep + 1;

}

void Del(BinTree T)
{
    if(T)
    {
        Del(T->Left);
        Del(T->Right);
        free(T);
    }
}

void Tree_del(BinTree T,char x)
{
    BinTree Q[100];
    if(T)
    {
        if(T->Data==x)
        {
            Del(T);
            exit(0);
        }
        Queue Q;
        Initqueue(Q);
        Enqueue(Q,T);
        BinTree p;
        while(!Isempty(Q))
        {
            Dequeue(Q,p);
            if(p->Left!=NULL)
            {
                Del(p->Left);
                p->Left=NULL;
            } else Enqueue(Q,p->Left);
            if(p->Right!=NULL)
            {
                Del(p->Right);
                p->Right=NULL;
            } else Enqueue(Q,p->Right);
        }
    }
}

void Tree_swap(BinTree T)
{
    if(T)
    {
        Tree_swap(T->Right);
        Tree_swap(T->Left);
        BinTree temp=T->Left;
        T->Left=T->Right;
        T->Right=temp;

    }
}

int Tree_count(BinTree T)
{
    int nodes=0;
    if(T==NULL)
    {
        return 0;
    }
    else
    {
        nodes=1+ Tree_count(T->Left)+ Tree_count(T->Right);
    }
    return nodes;
}

void Leaves_count(BinTree T,int &nodes)
{
    if(T)
    {
        Leaves_count(T->Left,nodes);
        Leaves_count(T->Right,nodes);
        if(T->Left==NULL&&T->Right==NULL)
            nodes+=1;
    }
}
int Leaves_count2(BinTree T)
{
    if(!T)return 0;
    else if(!T->Right&&!T->Left)
        return Leaves_count2(T->Right)+ Leaves_count2(T->Left)+1;
    else
        return Leaves_count2(T->Right)+ Leaves_count2(T->Left);
}

void Find_kth(BinTree T,int& k,char& v)
{
    if(v!=0)
    {
        exit(0);
    }
    else if(T!=NULL)
    {
        --k;
        if(k==0)v=T->Data;
        Find_kth(T->Left,k,v);
        Find_kth(T->Right,k,v);

    }

}
void Reverse_levelorder(BinTree T)
{   Queue Q;Stack S;
    Initqueue(Q);
    Initstack(S);
    BinTree p=NULL;
    Enqueue(Q,T);
    while (!Isempty(Q))
    {
        Dequeue(Q,p);
        push(S,p);
        if(p->Left)
            Enqueue(Q,p->Left);
        if(p->Right)
            Enqueue(Q,p->Right);


    }
    TNode* e;
    while (!Stack_isempty(S))
    {
        pop(S,e);
        printf("%c ",e->Data);
    }

}

int Tree_count_binarybranch(BinTree T)
{
    if(!T)
        return 0;
    else if (T->Right&&T->Left)
        return 1+Tree_count_binarybranch(T->Left)+Tree_count_binarybranch(T->Right);
    else
        return Tree_count_binarybranch(T->Left)+Tree_count_binarybranch(T->Right);
}

bool Judge_similar(BinTree T1,BinTree T2)
{   bool lefts,rights;
    if(T1==NULL&&T2==NULL)
    {
        return true;
    }
    else if(T1==NULL||T2==NULL)
        return false;
    else
    {
        lefts=Judge_similar(T1->Left,T2->Right);
        rights= Judge_similar(T1->Right,T2->Right);
        return lefts&&rights;

    }
}

int Count_Nodes(BinTree T)
{
    if(!T)
        return 0;
    else if(T)
        return Count_Nodes(T->Left)+Count_Nodes(T->Right)+1;
    else return Count_Nodes(T->Left)+Count_Nodes(T->Right);
}

