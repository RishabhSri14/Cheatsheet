typedef char ElementType ;
typedef struct node Node;
typedef Node* PtrToNode;
typedef struct Queue* Queue;


struct node{
    ElementType data;
    PtrToNode child;
    PtrToNode sibling;
};

struct Queue
{
    PtrToNode* a;
    int lid;
    int rid;
};


void Enque(PtrToNode n,Queue q);
void SibEnque(PtrToNode root,Queue q);
PtrToNode Deque(Queue q);

PtrToNode InitNode(ElementType a);
void PrintPre(PtrToNode root);
void PrintPre2(PtrToNode root);
void PrintPost(PtrToNode root);
void PrintLevel(PtrToNode root);

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

PtrToNode InitNode(ElementType a)
{
    PtrToNode temp=(PtrToNode)malloc(sizeof(Node));
    assert (temp!=NULL);
    temp->data=a;
    temp->child=NULL;
    temp->sibling=NULL;
    return temp;
}

Queue InitQueue()
{
    Queue q=(Queue)malloc(sizeof(struct Queue));
    assert(q!=NULL);
    q->a=(PtrToNode*)malloc(sizeof(PtrToNode)*1000);
    assert(q->a!=NULL);
    q->lid=0;
    q->rid=-1;
}

void Enque(PtrToNode n,Queue q)
{
    q->rid+=1;
    q->a[q->rid]=n;

}

void SibEnque(PtrToNode root,Queue q)
{
    if(root==NULL)
    return;
    else
    {
        Enque(root,q);
        SibEnque(root->sibling,q);
    }
    
}

PtrToNode Deque(Queue q)
{
    if(q->rid>=0)
    {
        q->lid+=1;
        return (q->a[(q->lid)-1]);
    }
}

//Traversals

//PreOrder
void PrintPre(PtrToNode root)
{
    if(root!=NULL)
    printf("%c\n",root->data);
    else 
    return;
    PrintPre(root->child);
    PrintPre(root->sibling);
}

//PreOrder type 2
void PrintPre2(PtrToNode root)
{
    if(root!=NULL)
    printf("%c\n",root->data);
    else 
    return;
    PrintPre2(root->sibling);
    PrintPre2(root->child);
}

//PostOrder
void PrintPost(PtrToNode root)
{
    if(root==NULL)
    return;
    else{
        PrintPost(root->child);
        printf("%c\n",root->data);
        PrintPost(root->sibling);
    }
}

//LevelOrder
void printlevel(PtrToNode root,Queue q)
{
    while(q->rid>=q->lid)
    {
        PtrToNode E=Deque(q);
        printf("%c\n",E->data);
        if(E->child!=NULL)
        SibEnque(E->child,q);


    }


}


void PrintLevel(PtrToNode root)
{
    Queue q=InitQueue();
    Enque(root,q);
    printlevel(root,q);
}