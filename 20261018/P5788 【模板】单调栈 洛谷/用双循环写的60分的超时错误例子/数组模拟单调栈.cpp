#include <iostream>
#include <string>
using namespace std;

long long Data[3000005],stack[3000005],res[3000005];

int main(void){
  long long top=0;
  long long n,i;
  cin>>n;
  for(i=1;i<=n;i++){
    cin>>Data[i];
  }
  for(i=1;i<=n;i++){
    while(top>0 && Data[stack[top]]<Data[i]){
      res[stack[top--]]=i;
    }
    stack[++top]=i;
  }
  for(i=1;i<=n;i++){
    cout<<res[i]<<" ";
  }
  return 0;
}