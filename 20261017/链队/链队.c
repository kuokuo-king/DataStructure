#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
//队列结点的结构体
typedef struct QNode{
    char data;
    struct QNode *next;
}QNode;
//队列的结构体
typedef struct LinkQueue{
    QNode *head;
    QNode *tail;
}LinkQueue;
//1.初始化
int InitQueue(LinkQueue *Q){
    (*Q).head=(QNode*)malloc(sizeof(QNode));
    (*Q).tail=(*Q).head;
    Q->head->next=NULL;
    Q->tail->next=NULL;
    return 0;
}
//2.入队
int EnterQ(LinkQueue *Q,char e){
    QNode *p=(QNode*)malloc(sizeof(QNode));
    p->data=e;
    p->next=NULL;
    Q->tail->next=p;
    Q->tail=p;
    return 0;
}
//3.出队
int OutQ(LinkQueue *Q,char *e){
    if (Q->head == Q->tail)return -1;
    QNode *p=Q->head->next;
    *e=p->data;
    if (Q->tail == p)Q->tail = Q->head;
    free(p);
    return 0;
}
