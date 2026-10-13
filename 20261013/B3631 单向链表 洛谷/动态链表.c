#include <stdio.h>
#include <stdlib.h>

typedef struct Lnode{
    int data;
    struct Lnode *next;
}Lnode,*LinkList;

Lnode* GetElement(LinkList L,int e){
    Lnode *p;
    p=L->next;
    while(p!=NULL && p->data !=e)p=p->next;
    return p;
}
void Insert(Lnode *p,int e){
    Lnode *q=(LinkList)malloc(sizeof(Lnode));
    q->next=p->next;
    p->next=q;
    q->data=e;
}
void SearchNext(Lnode *p){
    if(p->next!=NULL)printf("%d",(p->next)->data);
    else printf("%d",0);
}
void Delete(Lnode *p){
    Lnode *q=p->next;
    p->next =(p->next)->next;
    free(q);
}
int main(void){
    int n,i,act,a,b;
    scanf("%d",&n);
    LinkList L;
    Lnode *p;
    L=(LinkList)malloc(sizeof(Lnode));
    p=(LinkList)malloc(sizeof(Lnode));
    L->next =p;
    p->data=1;
    p->next=NULL;
    for(i=0;i<n;i++){
        scanf("%d",&act);
        switch (act){
            case 1:
                scanf("%d %d",&a,&b);
                Insert(GetElement(L,a),b);
                break;
            case 2:
                scanf("%d",&a);
                SearchNext(GetElement(L,a));
                break;
            case 3:
                scanf("%d",&a);
                Delete(GetElement(L,a));
                break;
        }
    }
    return 0;
}
/*
# B3631 单向链表

## 题目描述

实现一个数据结构，维护一张表（最初只有一个元素 $1$）。需要支持下面的操作，其中 $x$ 和 $y$ 都是 $1$ 到 $10^6$ 范围内的正整数，且保证任何时间表中所有数字均不相同，操作数量不多于 $10^5$：

- `1 x y` ：将元素 $y$ 插入到 $x$ 后面；
- `2 x` ：询问 $x$ 后面的元素是什么。如果 $x$ 是最后一个元素，则输出 $0$；
- `3 x`：从表中删除元素 $x$ **后面的那个元素**，不改变其他元素的先后顺序。

## 输入格式

第一行一个整数 $q$ 表示操作次数。

接下来 $q$ 行，每行表示一次操作，操作具体见题目描述。

## 输出格式

对于每个操作 2，输出一个数字，用换行隔开。

## 输入输出样例 #1

### 输入 #1

```
6
1 1 99
1 99 50
1 99 75
2 99
3 75
2 1
```

### 输出 #1

```
75
99
```



这是用动态链表实现的，但是似乎超时了，正在尝试用数组模拟*/