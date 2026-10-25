#include <iostream>
using namespace std;
int Data[105];
int nxt[105];
int main(void){
    int n,m,i,cnt=0,out=0;
    cin>>n>>m;
    for(i=0;i<n;i++){
        Data[i]=i+1;
        if(i==n-1)nxt[i]=0;
        else nxt[i]=i+1;
    }
    i=0;
    while(out<n){
        cnt++;
        if(cnt==m-1){
            cout<<Data[nxt[i]]<<" ";
            nxt[i]=nxt[nxt[i]];
            out++;
            cnt=0;
        }
        i=nxt[i];
    }
    return 0;
}