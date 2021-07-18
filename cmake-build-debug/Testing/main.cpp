// Tree_teacher.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <cstdio>
#include <iostream>
#include "stack.h"
using namespace std;
int GetHeight(BinTree T);



int main()
{
    char a[] = { '4','3','1','2','5','6','7' };
    char b[] = { '1','3','2','4','6','5','7' };
    BinTree T3 = buildtree(a, b, 7);
    char c[]=  { '1','2','4','5','3','6','7' };
    char d[]=  { '4','2','5','1','6','3','7' };
    BinTree T2 = buildtree(c, d, 7);
    cout << "   T 3\n";
    cout <<"     4      \n";
    cout <<"   5   3    \n";
    cout <<"  1 2 6 7   \n";
    cout << "   T 2\n";
    cout <<"     1      \n";
    cout <<"   2   3    \n";
    cout <<"  4 5 6 7   \n";
    printf("%d", GetHeight(T3));
    printf("\n");
    Tree_swap(T3);
    Preorder(T3);
    printf("\n");
    printf("%d",Tree_count(T3));
    printf("\n");
    printf("%d",Tree_count(T3));
    printf("\n");
    Reverse_levelorder(T3);
    printf("\n");
    cout<<Tree_count_binarybranch(T3);
    printf("\n");
    cout<<Leaves_count2(T3);
    printf("\n");
    if(Judge_similar(T3,T2))
        cout<<"similar!\n";
    else
        cout<<"Not similar!\n";
    cout<<Count_Nodes(T3);


}


