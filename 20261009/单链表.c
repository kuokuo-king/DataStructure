#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

#define MAXSIZE 100 
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int ElemType; 
typedef struct Lnode{
    ElemType data;
    struct Lnode *next;
}Lnode,*LinkList;

int InitList(LinkList *L){
    *L=(LinkList)malloc(sizeof(Lnode));
    if(*L == NULL)return ERROR;
    (*L)->next=NULL;
    return OK;
}
int IsEmpty(LinkList L){
    if((L)->next==NULL)return 0;
    return 1;
}
int DestroyList(LinkList *L){
    Lnode *p;
    while(*L !=NULL){
        p=*L;
        *L=(*L)->next;
        free(p);
    }
    return OK;
}
int ClearList(LinkList *L){
    Lnode *p,*q;
    p=(*L)->next;
    q=p;
    (*L)->next=NULL;
    while(p){
        q=p;
        p=p->next;
        free(q);
    }
    return OK;
}
int LengthList(LinkList L){
    Lnode *p;
    p=L->next;
    int cnt=0;
    while(p){
        cnt++;
        p=p->next;
    }
    return cnt;
}
int GetElem(LinkList L,int i,ElemType *e){
    if(i<1)return ERROR;
    int cnt=1;
    Lnode *p;
    p=L->next;
    while(p && cnt<i){
        p=p->next;
        cnt++;
    }
    if(!p || i>cnt)return ERROR;
    *e=p->data;
    return OK;
}
Lnode* LocateList(LinkList L,ElemType e){
    Lnode *p;
    p=L->next;
    while(p && (p->data) != e)p=p->next;
    return p;
}
int InsertList(LinkList *L,ElemType e,int i){
    int cnt=0;
    Lnode *p,*s;
    p=(*L);
    if(i<1 || i>LengthList(L)+1)return ERROR;
    while(cnt<i-1){
        p=p->next;
        cnt++;
    }
    s=(Lnode*)malloc(sizeof(Lnode));
    s->next = p->next;
    p->next =s;
    return OK;
}
int DeleteList(LinkList *L,int i,ElemType *e){
    if(i<1 ||i>LengthList(L))return ERROR;
    Lnode *p,*q;
    p=*L;
    int cnt=0;
    while(cnt<i-1){
        p=p->next;
        cnt++;
    }
    q=p->next;
    *e=q->data;
    p->next=q->next;
    free(q);
    return OK;
}
void CreateList1(LinkList *L,int n){
    *L=(Lnode*)malloc(sizeof(Lnode));
    (*L)->next =NULL;
    int i;
    Lnode *p;
    for(i=n;i>0;i--){
        p=(Lnode*)malloc(sizeof(Lnode));
        scanf("%d",&(p->data));
        p->next=(*L)->next;
        (*L)->next=p;
    }
}
void CreateList2(LinkList *L,int n){
    *L=(Lnode*)malloc(sizeof(Lnode));
    (*L)->next=NULL;
    int i;
    Lnode *p,*r;
    r=*L;
    for(i=n;i>0;i--){
        p=(Lnode*)malloc(sizeof(Lnode));
        scanf("%d",&(p->data));
        p->next =NULL;
        r->next =p;
        r=p;
    }
}