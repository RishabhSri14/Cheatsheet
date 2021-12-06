#include <stdio.h>
#include <stdlib.h>
struct Edge
{
    int s;
    int d;
    long int l;
};
struct Vertex
{
    int id;
    int len;
    struct Vertex* next;
};

struct Vertex* InitVertex(int id,int l)
{
    struct Vertex* v=(struct Vertex *)malloc(sizeof(struct Vertex));
    v->id=id;
    v->len=l;
    v->next=(struct Vertex *)malloc(sizeof(struct Vertex));
    v->next=NULL;
    return v;
}
void TopologicalSort(struct Vertex* V[],struct Vertex* v,int res[],int visited[],int n,int* s)
{
    
    struct Vertex *temp=V[v->id];
    while(temp->next!=NULL){
        temp=temp->next;
        TopologicalSort(V,temp,res,visited,n,s);
    }
    if(visited[v->id]!=1)
    {
        res[*s]=v->id;
        (*s)=*s + 1;
    }
    visited[v->id]=1;
}

void wrapper(struct Vertex *V[],int res[],int visited[],int n, int* s)
{
    for(int i=0;i<n;i++)
    {
        struct Vertex *temp=V[i];
        if(visited[i]!=1)
        {
            TopologicalSort(V,temp,res,visited,n,s);
        }
    }
    
}

int main()
{
    int v,e;
    printf("Enter the number of vertices and edges:\n");
    scanf("%d %d",&v,&e);
    struct Edge E[e];
    struct Vertex* V[v];
    for(int i=0;i<e;i++)
    {
        V[i]=InitVertex(i,0);
        scanf("%d %d %ld",&E[i].s,&E[i].d,&E[i].l);
    }
    for(int i=0;i<e;i++)
    {
        struct Vertex* temp=V[E[i].s];

        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=InitVertex(E[i].d,E[i].l);
    }
//===============================Input Complete=======================================

    int stack[v];
    int visited[v];
    for(int i=0;i<v;i++)//O(V)
        visited[i]=0;
    int s=0;
    wrapper(V,stack,visited,v,&s);//O(E)
    for(int i=0;i<s;i++)
    {
        printf("%d ",stack[s-1-i]);
    }
}