#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

//栈的结构体定义
typedef struct SqStack{
    char *base;
    char *top;
    int size; 
}SqStack,*Sqp;
//1.栈的初始化
int InitStack(SqStack *S){
    S->base=(char*)malloc(sizeof(SqStack)*MAXSIZE);
    if(!S->base)return -1;
    S->top = S->base;
    S->size =MAXSIZE;
    return 1;
}
//2.判断是否栈空
int IsEmpty(SqStack S){
    return S.base==S.top?1:0;
}
//3.求栈里的元素数量
int LenStack(SqStack S){
    return S.top-S.base;
}

//4.清空栈
int ClearStack(SqStack *S){
    S->top=S->base;
    return 1;
}
//5.销毁栈
int DestroyStack(SqStack *S){
    free(S->base);
    S->base=NULL;
    S->top=NULL;
    S->size=0;
    return 1;
}
//6.入栈
int Push(SqStack *S,char e){
    if(S->top-S->base==0)return -1;
    else{
        *(S->top++)=e;
        return 1;
    }
}
//7.出栈
int Pop(SqStack *S,char *e){
    if(S->base==S->top)return -1;
    *e=*(--S->top);
    return 1;
}
