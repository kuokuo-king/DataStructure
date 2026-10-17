#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
//队列的结构体
typedef struct SqQueue{
    char *base;
    int head,tail;
}SqQueue;

//1.队列的初始化
int InitQueue(SqQueue *Q){
    (*Q).base=(SqQueue*)malloc(sizeof(SqQueue));
    (*Q).head=0;
    (*Q).tail=0;
    return 0;
}
//2.求队列的长度（+MAXSIZE针对循环队列）
int LengthQueue(SqQueue Q){
    return ((Q.head-Q.tail)%MAXSIZE);
}
//3.入队
int EnterQ(SqQueue *Q,char e){
    if(((*Q).tail+1)%MAXSIZE==(*Q).head)return -1;
    (*Q).base[(*Q).tail]=e;
    (*Q).tail=((*Q).tail+1)%MAXSIZE;
    return 1;
}
//4.出队
int OutQ(SqQueue *Q,char *e){
    if((*Q).head==(*Q).tail)return -1;
    *e=(*Q).tail;
    (*Q).head=((*Q).head+1)%MAXSIZE;
    return 1;
}
//5.判断是否为空
int IsEmpty(SqQueue Q){
    if(Q.head==Q.tail)return 1;
    return 0;
}
//6.判断是否为满
int IsFull(SqQueue Q){
    if((Q.tail+1)%MAXSIZE==Q.head)return 1;
    return 0;
}
//7.获取第一个元素
int GetHead(SqQueue Q,char *e){
    if(IsEmpty(Q))return -1;
    *e=Q.base[Q.head];
    return 0;
}