#ifndef __STACK_H
#define __STACK_H

#define maxsize 50
typedef char ElementType;
typedef struct TNode* Position;
typedef Position BinTree;
struct TNode {
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

typedef struct {
    TNode* data[maxsize];
    int front, rear;

}Queue;
typedef struct {
    TNode* data[maxsize];
    int top;
}Stack;
void Initqueue(Queue& Q);
bool Isempty(Queue Q);
bool Enqueue(Queue& Q, TNode* x);
bool Dequeue(Queue& Q, TNode*& x);
void Tree_del(BinTree T,char x);
void Tree_swap(BinTree T);
int Tree_count(BinTree T);
void Leaves_count(BinTree T,int &nodes);
int Leaves_count2(BinTree T);
void Find_kth(BinTree T,int& k,char& v);
void Initstack(Stack& s);
bool pop(Stack& s,TNode* &x);
bool push(Stack& s,TNode* x);
bool Stack_isempty(Stack s);
void Reverse_levelorder(BinTree T);
int Tree_count_binarybranch(BinTree T);
bool Judge_similar(BinTree T1,BinTree T2);
TNode* buildtree(char preorder[], char inorder[], int size);
bool Preorder(BinTree T);
bool Inorder(BinTree T);
bool Beorder(BinTree T);
int Count_Nodes(BinTree T);
bool Judge_BST(BinTree T);
extern int lev;
extern int r,f,flag;
extern Queue q1;
#endif
#pragma once
