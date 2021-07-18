#include <cstdio>
#include "stack.h"

void Initqueue(Queue& Q)
{
    Q.rear = Q.front = 0;

}

bool Isempty(Queue Q)
{
    if (Q.rear == Q.front)
        return true;
    else
        return false;
}


bool Enqueue(Queue& Q, TNode* x)
{
    if ((Q.rear + 1) % maxsize == Q.front)
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % maxsize;
    return true;
}

bool Dequeue(Queue& Q, TNode*& x)
{
    if (Q.rear == Q.front)
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % maxsize;
    return true;

}
void Initstack(Stack& s)
{
    s.top=-1;
}

bool Stack_isempty(Stack s)
{
    if(s.top==-1)
        return true;
    else
        return false;

}
bool push(Stack& s,TNode* x)
{
    if(s.top==maxsize-1)
        return false;

    s.data[++s.top]=x;
    return true;
}

bool pop(Stack& s,TNode* &x)
{
    if(s.top==-1)
        return false;

    x=s.data[s.top--];
    return true;
}

//
// Created by x on 2021/7/18.
//

