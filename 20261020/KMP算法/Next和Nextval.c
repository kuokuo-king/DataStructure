#include <stdio.h>
#define MAXSIZE 100005

typedef struct{
    char ch[MAXSIZE+1]; 
    int length;
}SString;

void GetNext(SString T, int *next) {
    next[1]=0;
    int j=0;
    int i=1;
    while (i<T.length) {
        if (j==0 ||T.ch[i]==T.ch[j]) {
            i++,j++;
            next[i]=j;
        } else {
            j=next[j];
        }              
    }
}

void GetNextval(SString T, int *next) {
    next[1]=0;
    int j=0;
    int i=1;
    while (i<T.length) {
        if (j==0 ||T.ch[i]==T.ch[j]) {
            i++,j++;
            if(T.ch[i]==T.ch[j]){
                next[i]=next[j];
            }else{
                next[i]=j;
            }
        }else{
            j=next[j];
        }
    }
}