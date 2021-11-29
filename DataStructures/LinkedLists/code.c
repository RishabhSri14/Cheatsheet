#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int ElementType;
typedef struct Node ListNode;
typedef struct Node* PtrToNode;

typedef PtrToNode List;
typedef PtrToNode Position;

struct Node {
    ElementType Element;
    Position Next;
};



int AreEqualElems(int a,int b)
{
    if (a==b)
    return 1;
    else
    return 0;
}


PtrToNode MakeNode(ElementType X)
{
    PtrToNode a=(PtrToNode)malloc(sizeof(ListNode));
    assert (a!=NULL);
    a->Element=X;
    a->Next=NULL;
    return a;
}

List CreateEmptyList()  //Easiest
{
    List p;
    p=MakeNode(0);
    return p;
}
//                   (IMPORTANT)
//when we wish to change the address to which a pointer points by function call

// without function call it's just a matter of assignment 
void CreateEmptyList1(List* PP)  //Second use of double pointer after arrays(RECOMMENDED)
{
    *PP=MakeNode(0);

}

void InsertAtFront(List* h,ElementType X)
{
    PtrToNode p=MakeNode(X);
    p->Next=*h;
    *h=p;
}

void InsertAtFront_v2(List L,ElementType X)
{
    PtrToNode p=MakeNode(X);
    p->Next=L;
    ListNode temp=*p;
    *p=*L;
    *L=temp;
}

void InsertAtRear(List* LP,ElementType X)
{
    PtrToNode p=MakeNode(X);
    PtrToNode temp=*LP;
    while ((temp->Next)!=NULL)
    {
        temp=temp->Next;
    }
    temp->Next=p;
}

void DeleteNode(PtrToNode P)
{
    if (P!=NULL)
    free(P);
}
void DeleteList(List* LP)//Leaving head node
{
    (*LP)->Next=NULL;
}

void EmptyList(List* LP)
{
    free(*LP);
}

void PrintList(List P)
{
    while((P->Next)!=NULL)
    {
        printf("%d\n",P->Element);
        P=P->Next;
    }
}

