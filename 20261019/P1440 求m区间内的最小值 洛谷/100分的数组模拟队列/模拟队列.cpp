#include <iostream>
using namespace std;
#define MAXSIZE 2000005
long long Data[MAXSIZE];
int q[MAXSIZE];

int main(void){
    int n, m, i;
    int head = 0, tail=-1; 
    cin>>n>>m;
    for (i = 0; i < n; i++) cin>>Data[i];
    cout<<"0\n";
    for (i=1;i<n;i++) {
        while (head<=tail && Data[q[tail]]>=Data[i-1])tail--;
        q[++tail]=i-1;
        while (head<=tail && q[head]<i-m)head++;
        cout << Data[q[head]] << "\n";
    }
    return 0;
}