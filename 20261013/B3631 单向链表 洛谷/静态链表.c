#include <stdio.h>
int next[1000005];
int main(void){
    int n,i,act,a,b;
    scanf("%d",&n);
    next[1]=0;
    for(i=0;i<n;i++){
        scanf("%d",&act);
        switch (act){
            case 1:
                scanf("%d %d",&a,&b);
                next[b]=next[a];
                next[a]=b;
                break;
            case 2:
                scanf("%d",&a);
                printf("%d\n",next[a]);
                break;
            case 3:
                scanf("%d",&a);
                next[a]=next[next[a]];
                break;
            default:
                break;
        }
    }
    return 0;
}