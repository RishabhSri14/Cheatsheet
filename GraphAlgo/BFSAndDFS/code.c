#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct vertex vertex;

typedef  struct vertex* PtrTovertex;
typedef vertex* ElementType;
typedef struct Queue* Que;

struct Queue {
    long int  NumItems;
    long int  Capacity;
    long int Front;
    long int  Rear;
    ElementType* QArr;
};


struct vertex
{
    int id;
    PtrTovertex next;
};

typedef struct Adj_list
{
    PtrTovertex* list;
}Adj_list;
// We can create weighted adjacency matrix by adding int** weight but here we'll use adj matrix for that 


PtrTovertex InitNode(int data);
int** InitAdj_Mat(int v) ;
void UpdateAdj_Mat(int** a,int i,int j,int weight);
Adj_list InitAdj_List(int v);
void InsertEdge(int u,int v,Adj_list a);// directed u->v
void BFS_List(Adj_list  a,int n);
void BFS_Mat(int ** a,int n);
void DFS_List(Adj_list a,int n,int start_node,PtrTovertex ft[]);
void DFS_visit(Adj_list a,PtrTovertex start,int* c,int check[],PtrTovertex ft[]);
void Djishtra(PtrTovertex* a,int ** b,int n);
void Prims(PtrTovertex* a,int **b,int n);
void BellmondFord(PtrTovertex* a,int **b,int n);
Que InitQue(long int que_capacity);
void Enque(Que Q,const ElementType E);
ElementType Deque(Que Q);

PtrTovertex InitNode(int data)
{
    PtrTovertex v = (PtrTovertex)malloc(sizeof(vertex));
    v->id = data;
    v->next = NULL;
    return v;
}

// Good when just need to check whether there is an edge between i and j
// space: O(n^2) #very bad
// Finding neighbour of any vertex: O(n) and for all vertex O(n^2)

int **InitAdj_Mat(int v)
{
    int **a = (int **)malloc(sizeof(int *) * v);
    for (int i = 0; i < v; i++)
        a[i] = (int *)malloc(sizeof(int) * v);
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
            a[i][j] = 1e5;
    }
    return a;
}
void UpdateAdj_Mat(int **a, int i, int j, int weight)
{
    a[i][j] = weight;
    a[j][i] = weight;
}

//Good in finding neighbours
// Finding neighbour of any vertex: O(k) and for all vertex O(nk) = O(E)
// To check whether there is a edge or not worst case is O(n) #Complete graph
Adj_list InitAdj_List(int v)
{
    Adj_list a;
    a.list = (PtrTovertex *)malloc(sizeof(PtrTovertex) * v);
    for (int i = 0; i < v; i++)
    {
        a.list[i] = InitNode(i); //first header node acts as self loop
    }

    return a;
}

void InsertEdge(int u, int v, Adj_list a) // directed u->v
{
    int i = 1;
    PtrTovertex temp = InitNode(v);
    PtrTovertex temp1 = a.list[u];
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
        if (temp1->id == v)
        {
            i = 0;
            return;
        }
    }
    if (i == 1)
        temp1->next = temp;
}

void BFS_List(Adj_list a, int n)
{
    int check[n];               //-1 for unseen 1 for seen
    for (int i = 0; i < n; i++) // O(V)
        check[i] = -1;
    Que q = InitQue(1e5);
    PtrTovertex *x = a.list;
    Enque(q, (x[0]));
    check[0] = 1;

    while (q->NumItems != 0) //O(E)
    {
        PtrTovertex temp1 = Deque(q);
        printf("%d\n", temp1->id);
        PtrTovertex temp = x[temp1->id];
        while (temp->next != NULL)
        {
            temp = temp->next;
            if (check[temp->id] == -1)
            {
                Enque(q, temp);
                check[temp->id] = 1;
            }
        }
    }
}
/*If ElementType in Queue.h is int
void BFS_Mat(int** a,int n)
{
    int check[n];//-1 for unseen 1 for seen
    for(int i=0;i<n;i++) // O(V)
    check[i]=-1;
    Que q=InitQue(1e5);
    Enque(q,0);
    check[0]=1;
    while(q->NumItems!=0)//O(V^2)   #as every element will be in a queue and inner for loop is use for every element in the list
    {
        int x=Deque(q);

        for(int i=1;i<n;i++)
        {
            if(a[x][i]!=1e5 && check[i]==-1)
            {
                Enque(q,i);
                check[i]=1;
            }
        }
}
*/

void DFS_List(Adj_list a, int n, int start_node, PtrTovertex ft[])
{
    int c = 0;
    int check[n];               //-1 for unseen 1 for seen
    for (int i = 0; i < n; i++) // O(V)
        check[i] = -1;
    printf("%d\n", start_node);
    check[0] = 1;
    PtrTovertex temp = a.list[start_node];
    while (temp->next != NULL) //O(E)
    {
        temp = temp->next;
        if (check[temp->id] == -1)
        {
            printf("%d\n", temp->id);
            check[temp->id] = 1;
            DFS_visit(a, temp, &c, check, ft);
            ft[c] = temp;
            c++;
        }
    }
}

void DFS_visit(Adj_list a, PtrTovertex start, int *c, int check[], PtrTovertex ft[])
{
    PtrTovertex temp = a.list[start->id];
    while (temp->next != NULL)
    {
        temp = temp->next;
        if (check[temp->id] == -1)
        {
            printf("%d\n", temp->id);
            check[temp->id] = 1;
            DFS_visit(a, temp, c, check, ft);
            ft[*c] = temp;
            (*c)++;
        }
    }
}


//This is of O(V^2+E)
//using priority queue it can be changed to O(VlogV +ElogV)
void Djishtra(PtrTovertex *a, int **b, int n)
{
    struct temp
    {
        int *known;
        int *dv;
        int *pv;
    };

    struct temp table;
    table.known = malloc(sizeof(int) * n);
    table.dv = malloc(sizeof(int) * n);
    table.pv = malloc(sizeof(int) * n);
    //initialisation    O(V)
    for (int i = 1; i < n; i++)
    {
        table.known[i] = 0;
        table.dv[i] = b[0][i];
        if (table.dv[i] != 1e5)
        {
            table.pv[i] = 0;
        }
        else
            table.pv[i] = -1;
    }
    table.known[0] = 1;
    table.pv[0]=0;
    table.dv[0]=0;
    int check = 1;
    //Step 2:
    while (check < n)
    {
        check = 1;
        int min = 1e7;
        int min_index;
        for (int i = 1; i < n; i++)
        {
            if (table.known[i] == 1)
                check++;
            if (table.dv[i] < min && table.known[i] == 0)
            {
                min = table.dv[i];
                min_index = i;
            }
        }
        table.known[min_index] = 1;
        //Step3:Relax
        PtrTovertex temp = a[min_index];
        while (temp->next != NULL)
        {
            temp = temp->next;
            int i = temp->id;
            if (table.known[i] == 0)
            {
                if (table.dv[i] > table.dv[min_index] + b[min_index][i])
                {
                    table.dv[i] = table.dv[min_index] + b[min_index][i];
                    table.pv[i]=min_index;
                }
            }
        }
    }
    printf("Shortest path between 0 to ith vertex is:\n");
    for(int i=1;i<n;i++)
    {
        printf("0->%d = %d\n",i,table.dv[i]);
        int prev=i;
        printf("The path is:\n");
        printf("%d<-",i);
        while(table.pv[prev]!=0)
        {
            prev=table.pv[prev];
            printf("%d<-",prev);
        }
        printf("0\n");
    }
}

//O(V + VE)
void BellmondFord(PtrTovertex* a,int **b,int n)
{
    struct temp
    {
        int *dv;
        int *pv;
    };
    struct temp table;
    //Initialisation
    table.dv=malloc(sizeof(int)*n);
    table.pv=malloc(sizeof(int)*n);
    for(int i=1;i<n;i++)
    {
        table.dv[i]=1e5;
        table.pv[i]=-1;
    }
    table.dv[0]=0;
    table.pv[0]=0;
    for(int h=1;h<n;h++)
    {
        for(int i=0;i<n;i++)
        {
            PtrTovertex temp=a[i];
            while (temp->next!=NULL)
            {
                temp=temp->next;
                int j=temp->id;
                if(table.dv[i]+b[i][j]<table.dv[j])
                {
                    table.dv[j]=table.dv[i]+b[i][j];
                    table.pv[j]=i;
                }
            }
            
        }
    }
    printf("Shortest path between 0 to ith vertex is:\n");
    for(int i=1;i<n;i++)
    {
        printf("0->%d = %d\n",i,table.dv[i]);
        int prev=i;
        printf("The path is:\n");
        printf("%d<-",i);
        while(table.pv[prev]!=0)
        {
            prev=table.pv[prev];
            printf("%d<-",prev);
        }
        printf("0\n");
    }

}






//O(V^2+E)
//Using Priority Queue O(Vlogv +ElogV)
void Prims(PtrTovertex* a,int **b,int n)
{
    struct temp
    {
        int *known;
        int *dv;
        int *pv;
    };

    struct temp table;
    table.known = malloc(sizeof(int) * n);
    table.dv = malloc(sizeof(int) * n);
    table.pv = malloc(sizeof(int) * n);
    //initialisation    O(V)
    for (int i = 1; i < n; i++)
    {
        table.known[i] = 0;
        table.dv[i] = b[0][i];
        if (table.dv[i] != 1e5)
        {
            table.pv[i] = 0;
        }
        else
            table.pv[i] = -1;
    }
    table.known[0] = 1;
    table.pv[0]=0;
    table.dv[0]=0;
    int check = 1;
    //Step 2:
    while (check < n)
    {
        check = 1;
        int min = 1e7;
        int min_index;
        for (int i = 1; i < n; i++)
        {
            if (table.known[i] == 1)
                check++;
            if (table.dv[i] < min && table.known[i] == 0)
            {
                min = table.dv[i];
                min_index = i;
            }
        }
        table.known[min_index] = 1;
        //Step3:Relax
        PtrTovertex temp = a[min_index];
        while (temp->next != NULL)
        {
            temp = temp->next;
            int i = temp->id;
            if (table.known[i] == 0)
            {
                if (table.dv[i] > b[min_index][i])
                {
                    table.dv[i] = b[min_index][i];
                }
            }
        }
    }
    printf("The path length in MST is: ");
    int sum=0;
    for(int i=1;i<n;i++)
    {
        sum+=table.dv[i];
    }
    printf("%d\n",sum);
    for(int i=1;i<n;i++)
    {
        int prev=i;
        printf("%d->",i);
        while(table.pv[prev]!=0)
        {
            prev=table.pv[prev];
            printf("%d->",prev);
        }
        printf("0\n");
    }
}
