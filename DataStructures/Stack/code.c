#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef char ElementType;

typedef struct StackInfo* Stack;

struct StackInfo {    
    long int MaxNumItems;
    long int TopId;
    ElementType *StackItem;
};

Stack InitStack(unsigned long int max_items)
{

    Stack s=(Stack)malloc(sizeof(struct StackInfo));
    s->MaxNumItems=max_items;
    s->TopId=-1;
    s->StackItem=(ElementType*)malloc(sizeof(ElementType)*max_items);
    return s;

}

void Push(Stack S,ElementType E)
{
    S->TopId++;
    S->StackItem[S->TopId]=E;
}

void Pop(Stack S)
{
    S->TopId--;
}

ElementType Top(const Stack S)
{
    return ((S->StackItem)[S->TopId]);
}

int IsEmpty(const Stack S)
{
    if(S->TopId<0)
    return 1;
    else 
    return 0;
}

void ClearStack(Stack S)
{
    free(S->StackItem);
} 

void DeleteStack(Stack* S)
{
    free((*S)->StackItem);
    free(*S);
}
