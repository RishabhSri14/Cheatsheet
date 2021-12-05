
typedef struct node Node;
typedef Node* PtrToNode;
typedef struct Ht Ht;
typedef Ht* PtrToHt;
typedef struct StrNode StrNode;
typedef StrNode* PtrToStrNode;
typedef struct StrHt StrHt;
typedef StrHt* PtrToStrHt;

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node
{
    long int n;
    PtrToNode next;
};

struct Ht
{
    long long int table_size;
    PtrToNode* arr;
};



struct StrNode
{
    char* data;
    PtrToStrNode next;
};

struct StrHt
{
    long long int table_size;
    PtrToStrNode* arr;
};
//Integer hashing
long long int gethash(long int x,long long int table_size);
PtrToNode InitNode(long int n);
PtrToHt InitHashing(long long int table_size);
void insertSepChain(long int x,PtrToHt ht);  
void insertQuadProb(long int x,PtrToHt ht);
void insertLinProb(long int x,PtrToHt ht);
int findSepChain(long int x,PtrToHt ht);  
int findQuadProb(long int x,PtrToHt ht);
int findLinProb(long int x,PtrToHt ht);


//String Hash
PtrToStrNode InitStrNode(char*ch);
PtrToStrHt InitStrHashing(long long int table_size);
long int GetStrHash(char*ch,long long int table_size);
bool existSep(char*ch,PtrToStrHt dict);
void insertStr(char*ch,PtrToStrHt dict);
long long int GetStringHash(char ch[],long long int table_size);
long long int getExtendedHash(char a[],int l,int index,long long int pind,long long int power);



//String Hash
long long int GetStringHash(char ch[],long long int table_size)
{
    long long int key=0;
    int p=33;
    int q=1;
    int n=strlen(ch);
    for(int i=0;i<n;i++)
    {
        key=(key+(ch[i])*q)%table_size;
            q=(q*p)%table_size;
        
    }
    return key%table_size;    
}

long long int getExtendedHash(char a[],int l,int index,long long int pind,long long int power)
{
    long long int table_size=1e5+7;
    long long int s=0;
    int p=1;
    for(int i=0;i<l/(index+1);i++)
    {
        s=(s+(pind)*p)%table_size;
        p=(p*power)%table_size;
    }
    return s;
}







PtrToStrNode InitStrNode(char*ch)
{
    PtrToStrNode x=(PtrToStrNode)malloc(sizeof(StrNode));
    x->data=(char*)malloc(35*sizeof(char));
    strcpy(x->data,ch);
    x->next=NULL;
    return x;
}

PtrToStrHt InitStrHashing(long long int table_size)
{
    PtrToStrHt ht=(PtrToStrHt)malloc(sizeof(StrHt));
    ht->table_size=table_size;
    ht->arr=(PtrToStrNode*)malloc(sizeof(PtrToStrNode)*table_size);
    for(int i=0;i<table_size;i++)
    {
        ht->arr[i]=InitStrNode("\0");
    }
    return ht;
}

long int GetStrHash(char*ch,long long int table_size)
{
    long int key=0;
    int p=33;
    int q=1;
    int n=strlen(ch);
    for(int i=0;i<n;i++)
    {
        if(ch[i]>=65 && ch[i]<=90)
        {
            key=(key+(ch[i]-64)*q)%table_size;
            q=(q*p)%table_size;
        }
        if(ch[i]>=97 && ch[i]<=122)
        {
            key=(key+(ch[i]-70)*q)%table_size;
            q=(q*p)%table_size;
        }
    }
    return key%table_size;

}

bool existSep(char*ch,PtrToStrHt dict)
{
    long long int key=GetStrHash(ch,dict->table_size);
    PtrToStrNode temp=dict->arr[key];
    while(temp->next!=NULL )
    {
        temp=temp->next;
        if(strcmp(temp->data,ch)==0)
        {
            return true;
        }
    }
    return false;
}

void insertStr(char*ch,PtrToStrHt dict)
{
    long long int key=GetStrHash(ch,dict->table_size);
    PtrToStrNode new_node=InitStrNode(ch);
    PtrToStrNode temp=dict->arr[key];
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;
}









//Integer hashing
long long int gethash(long int x,long long int table_size)
{
    return (x%table_size);
}

PtrToNode InitNode(long int data)
{
    PtrToNode x=(PtrToNode)malloc(sizeof(Node));
    x->n=data;
    x->next=NULL;
    return x;
}

PtrToHt InitHashing(long long int table_size)
{
    PtrToHt ht=(PtrToHt)malloc(sizeof(Ht));
    ht->table_size=table_size;
    ht->arr=(PtrToNode*)malloc(sizeof(PtrToNode)*table_size);
    for(int i=0;i<table_size;i++)
    {
        ht->arr[i]=InitNode(-1);
    }
    return ht;
}

void insertSepChain(long int x,PtrToHt ht)
{
    long long int key=gethash(x,ht->table_size);
    PtrToNode new_node=InitNode(x);
    PtrToNode temp=ht->arr[key];
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;

}


void insertQuadProb(long int x,PtrToHt ht)
{
    long long int i=1;
    long long int key=gethash(x,ht->table_size);
    long long int temp=key;
    while(((ht->arr[temp])->n)!=-1)
    {
        temp=(key+i*i)%(ht->table_size);
        i++;
    }
    ht->arr[temp]->n=x;
}
void insertLinProb(long int x,PtrToHt ht)
{
    long long int key=gethash(x,ht->table_size);
    while(((ht->arr[key])->n)!=-1)
    {
        key=(key+1)%(ht->table_size);
    }
    ht->arr[key]->n=x;
}

int findSepChain(long int x,PtrToHt ht)
{
    int i=0,j=-1;
    long long int key=gethash(x,ht->table_size);
    PtrToNode temp=ht->arr[key];
    while(temp->next!=NULL )
    {
        j++;
        temp=temp->next;
        if(temp->n==x)
        {
            i=1;
            return j;
        }
    }
    if(i==0)
    return -1;
}  


int findQuadProb(long int x,PtrToHt ht)
{
    long long int i=1;
    long long int key =gethash(x,ht->table_size);
    long long int temp=key;
    while(((ht->arr[temp])->n)!=-1)
    {
        if((ht->arr[temp])->n==x)
        {
            return temp;
        }
        temp=(key+i*i)%(ht->table_size);
        i++;
    }
    return -1;
}
int findLinProb(long int x,PtrToHt ht)
{
    long long int key=gethash(x,ht->table_size);
    while(((ht->arr[key])->n)!=-1)
    {
        if((ht->arr[key])->n==x)
        {
            return key;
        }
        key=(key+1)%(ht->table_size);
    }
    return -1;
}




