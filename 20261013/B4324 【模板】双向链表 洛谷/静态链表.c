#include <stdio.h>
typedef struct Node{
    int pre;
    int next;
}Node;
int used[500005];
Node a[500005];
int main(void){
    int n1,n2,i,act,x,y,p,q;
    scanf("%d %d",&n1,&n2);
    for(i=1;i<=n1;i++){
        used[i] = 1;
        if(i==1)a[i].pre=0;
        else a[i].pre=i-1;
        if(i==n1)a[i].next=0;
        else a[i].next=i+1;
    }
    for(i=0;i<n2;i++){
        scanf("%d",&act);
        switch(act){
            case 1:
                scanf("%d %d",&x,&y);
                if(x==y)break;
                p=x;q=y;
                if (x < 1 || x > n1 || y < 1 || y > n1 || used[x] == 0 || used[y] == 0) break;
                if(a[p].pre != 0) a[a[p].pre].next=a[p].next;
                if(a[p].next != 0) a[a[p].next].pre=a[p].pre;
                a[p].next=q;
                a[p].pre=a[q].pre;
                if(a[q].pre != 0) a[a[q].pre].next=p;
                a[q].pre=p;
                break;
            case 2:
                scanf("%d %d",&x,&y);
                if(x==y)break;
                p=x;q=y;
                if (x < 1 || x > n1 || y < 1 || y > n1 || used[x] == 0 || used[y] == 0) break;
                if(a[p].pre != 0) a[a[p].pre].next=a[p].next;
                if(a[p].next != 0) a[a[p].next].pre=a[p].pre;
                a[p].pre=q;
                a[p].next=a[q].next;
                if(a[q].next != 0) a[a[q].next].pre=p;
                a[q].next=p;
                break;
            case 3:
                scanf("%d",&x);
                if (x < 1 || x > n1 || used[x] == 0) break;
                p=x;
                if(a[p].pre != 0)a[a[p].pre].next=a[p].next;
                if(a[p].next != 0)a[a[p].next].pre=a[p].pre;
                a[p].pre=0;
                a[p].next=0;
                used[p] = 0;
                break;
            default:
                break;
        }
    }
    int start = 0;
    for(i = 1; i <= n1; i++){
        if(used[i] && a[i].pre == 0){
            start = i;
            break;
        }
    }
    if(start == 0){
        printf("Empty!\n");
    } else {
        for(i = start; i != 0; i = a[i].next){
        printf("%d ", i);
    }
        printf("\n");
    }
    return 0;
}