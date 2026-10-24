#include <stdio.h>
#define MAXSIZE 100005

typedef char BitreeElemType;
typedef struct BiNode{
    BitreeElemType data;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;

void InOrder(BiTree T) {
    if (!T)return;
    InOrder(T->lchild);
    printf("%c ", T->data);
    InOrder(T->rchild);
}
void PreOrder(BiTree T) {
    if (!T)return;
    printf("%c ", T->data);
    PreOrder(T->lchild);
    PreOrder(T->rchild);
}
void PostOrder(BiTree T) {
    if (!T)return;
    PostOrder(T->lchild);
    PostOrder(T->rchild);
    printf("%c ", T->data);
}