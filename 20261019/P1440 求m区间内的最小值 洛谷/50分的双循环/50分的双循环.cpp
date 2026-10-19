#include <iostream>
using namespace std;
#define MAXSIZE 2000005
long long Data[MAXSIZE];
long long ans[MAXSIZE];
long long MIN(long long a,long long b){
    return a<b?a:b;
}
long long MAX(long long a,long long b){
    return a>b?a:b;
}
int main(void){
    long long n,m,i=0,j,min=0;
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>Data[i];
    }
    for(i=1;i<n;i++){
        min=Data[MAX(0,i-m)];
        for(j=MAX(0,i-m);j<i;j++){
            min=MIN(min,Data[j]);
        }
        ans[i]=min;
    }
    cout<<"0"<<"\n";
    for(i=1;i<n;i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}