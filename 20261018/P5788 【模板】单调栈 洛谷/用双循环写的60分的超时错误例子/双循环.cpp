#include <iostream>
#include <string>
using namespace std;

long long Data[3000005],res[3000005];

int main(void){
  long long n,i,j;
  cin>>n;
  for(i=0;i<n;i++){
    cin>>Data[i];
  }
  long long len=i;
  res[len-1]=0;
  for(i=len-1;i>=0;i--){
    for(j=i+1;j<len;j++){
      if(Data[i]<Data[j]){
        res[i]=j+1;
        break;
      }
    }
  }
  for(i=0;i<len;i++){
    cout<<res[i]<<" ";
  }
  return 0;
}