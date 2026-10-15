#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

//栈的结构体定义
typedef struct StackNode{
    char data;
    struct StackNode *next;
}StackNode,*LinkStack;
//1.栈的初始化
int InitStack(LinkStack *S){
    *S=NULL;
    return 1;
}
//2.判断是否栈空
int IsEmpty(LinkStack S){
    if(S==NULL)return 1;
    return 0;
}
//3.入栈
int Push(LinkStack *S,char e){
    StackNode *p=(LinkStack)malloc(sizeof(StackNode));
    p->data =e;
    p->next=*S;
    *S=p;
    return 1;
}
//4.出栈
int Pop(LinkStack *S,char *e){
    if(*S==NULL)return 0;
    StackNode *p=*S;
    e=(*S)->data;
    *S=(*S)->next;
    free(p);
    return 1;
}
//5.获取栈顶元素
char GetTop(LinkStack S){
    if(!S){
        return S->data;
    }
}