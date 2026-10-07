#include <stdio.h>
#include <string.h> // 用于后面的 memset

#define MAXSIZE 100 // 最大容量，这里用 MAXSIZE 或 LIST_INIT_SIZE 都行
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
typedef int ElemType;
// 静态分配结构体
typedef struct {
    ElemType elem[MAXSIZE]; // 数组，空间在编译时就已经确定
    int length;             // 当前实际长度
} SqList;

Status Initlist(SqList* L){
	L->length =0;
	return OK;
}

Status Clearlist(SqList* L){
	L->length =0;
	return OK;
}

Status ListInsert(SqList* L,Status i,ElemType e){
	if(i>L->length+1  || i<1)return ERROR;
	if(L->length == MAXSIZE)return ERROR;
	int j;
	for(j=L->length-1;j>=i-1;j--){
		L->elem[j+1]=L->elem[j];
	}
	L->elem[i-1]=e;
	L->length++;
	return OK;
}
Status ListDelete(SqList *L,Status i,ElemType *e){
	if(i>L->length || i<1)return ERROR;
	*e =L->elem[i-1];
	for(;i<L->length;i++){
		L->elem[i-1]=L->elem[i];
	}
	L->length--;
	return OK;
}
Status IsEmpty(SqList L){
	return (L.length ==0);
}

Status Listlength(SqList L){
	return (L.length);
}

Status LocateElem(SqList L,ElemType e){
	int i=0;
	for(;i<L.length;i++){
		if(L.elem[i]==e){
			return i+1;
		}
	}
	return ERROR;
}

Status GetElem(SqList L,Status i,ElemType *e){
	if(i<1||i>L.length)return ERROR;
	*e=L.elem[i-1];
	return OK;
}

int main() {
    SqList L;
    Initlist(&L);
    
    // 1. 插入测试
    printf("--- 插入测试 ---\n");
    for (int i = 1; i <= 5; i++) {
        ListInsert(&L, i, i * 10); // 依次插入 10, 20, 30, 40, 50
    }
    printf("当前长度: %d\n", Listlength(L)); // 预期输出: 5
    
    // 2. 取值测试
    ElemType val;
    GetElem(L, 3, &val);
    printf("第3个元素是: %d\n", val); // 预期输出: 30
    
    // 3. 查找测试
    int pos = LocateElem(L, 40);
    printf("元素 40 的位置是: %d\n", pos); // 预期输出: 4
    pos = LocateElem(L, 99);
    printf("元素 99 的位置是: %d\n", pos); // 预期输出: 0 (找不到)
    
    // 4. 删除测试
    ElemType delVal;
    ListDelete(&L, 3, &delVal); // 删除第3个元素 (30)
    printf("--- 删除测试 ---\n");
    printf("被删除的元素是: %d\n", delVal); // 预期输出: 30
    printf("删除后长度: %d\n", Listlength(L)); // 预期输出: 4
    
    GetElem(L, 3, &val);
    printf("删除后第3个元素变成了: %d\n", val); // 预期输出: 40 (原来的40往前移了)
    
    // 5. 判空测试
    Clearlist(&L);
    printf("--- 清空测试 ---\n");
    printf("清空后长度: %d, 是否为空: %d\n", Listlength(L), IsEmpty(L)); // 预期输出: 0, 1

    return 0;
}
