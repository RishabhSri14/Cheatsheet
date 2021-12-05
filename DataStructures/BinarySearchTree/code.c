typedef struct TreeNode* PtrToNode;
typedef int ElementType;

struct TreeNode
{
    ElementType data;
    PtrToNode Left;
    PtrToNode Right;
};

PtrToNode InitNode(ElementType data);
PtrToNode prevsearch(PtrToNode root,ElementType data);
PtrToNode SearchSmallest(PtrToNode root);


//Basics of binary search tree
PtrToNode insert(PtrToNode root,ElementType data);
PtrToNode search(PtrToNode root,ElementType data);
PtrToNode Delete(PtrToNode root,ElementType data);
void btsort(PtrToNode t);


void finddepth(PtrToNode T,PtrToNode P);

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

PtrToNode InitNode(ElementType data)
{
    PtrToNode temp=(PtrToNode)(malloc(sizeof(struct TreeNode)));
    assert(temp!=NULL);
    temp->data=data;
    temp->Left=NULL;
    temp->Right=NULL;
    return temp;
}

PtrToNode insert(PtrToNode root,ElementType data)
{
    if(root==NULL)
    {
        PtrToNode temp=InitNode(data);
        return temp;
    }
    if(data>root->data)
    {
        root->Right=insert(root->Right,data);
    }
    if(data< root->data)
    {
        root->Left=insert(root->Left,data);
    }
    return root;
}
//USE THIS METHOD OF RECURSION WHEN VALUE OBTAINED AT END IS THE FINAL VALUE
PtrToNode search(PtrToNode root,ElementType data)
{
    if(root== NULL)
    return NULL;
    if(data==root->data)
    {
        return root;
    }
    if(data >root->data)
    {
        return (search(root->Right,data));
    }
    if(data < root->data)
    {
        return (search(root->Left,data));
    }
}

PtrToNode prevsearch(PtrToNode root,ElementType data)
{
    if(root== NULL)
    return NULL;
    if(data==root->Right->data || root->Left->data==data )
    {
        return root;
    }
    if(data >root->data)
    {
        return (prevsearch(root->Right,data));
    }
    if(data < root->data)
    {
        return (prevsearch(root->Left,data));
    }
}

PtrToNode SearchSmallest(PtrToNode root)
{
    while(root->Left!=NULL)
    root=root->Left;

    return root;

}

PtrToNode Delete(PtrToNode root,ElementType data)
{
    PtrToNode temp=search(root,data);
    
    if(temp->Left==NULL || temp->Right==NULL)
    {
        if(temp->Left==NULL  && temp->Right==NULL)
        {
            root=NULL;
            free (root);
        }
        if(temp->Left==NULL  && temp->Right!=NULL)
        {
            temp=temp->Right;
            /*PtrToNode temp0=prevsearch(root,data);
            if(temp->data > temp0->data)
            {
                temp0->Right=temp->Right;
            }
            if(temp->data < temp0->data)
            {
                temp0->Left=temp->Right;
            }*/

        }
        if(temp->Left!=NULL  && temp->Right==NULL)
        {
            temp=temp->Left;
            /*PtrToNode temp0=prevsearch(root,data);
            if(temp->data > temp0->data)
            {
                temp0->Right=temp->Left;
            }
            if(temp->data < temp0->data)
            {
                temp0->Left=temp->Left;
            }*/
        }   
    }
    else
    {
        PtrToNode min=SearchSmallest(temp);
        temp->data=min->data;
        min->data=data;
        Delete(root,data);
        
    }

    
}

void btsort(PtrToNode t)
{
    if(t==NULL)
    return;
    btsort(t->Left);
    printf("%d ",t->data);
    btsort(t->Right);
}


void finddepth(PtrToNode T,PtrToNode P)
{
    int c=0;
    while(T->data != P->data)
    {
        if(T->data > P->data)
        {
            c++;
            T=T->Left;

        }
        if(T->data < P->data)
        {
            c++;
            T=T->Right;

        }
    }
    printf("%d",c);
}

