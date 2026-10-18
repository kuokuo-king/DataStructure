#include <iostream>
#include <string>
using namespace std;
#define MAXSIZE 1000005
typedef struct Stack{
  unsigned long long data[MAXSIZE];
  unsigned long long length;
}Stack;
int push(Stack &S,unsigned long long e){
  S.data[S.length++]=e;
  return 0;
}
int pop(Stack &S){
  if(S.length==0){
    cout<<"Empty"<<"\n";
  }
  else{
    S.length--;
  }
  return 0;
}
int query(const Stack &S){
  if(S.length==0){
    cout<<"Anguei!"<<"\n";
  }
  else{
    cout<<S.data[S.length-1]<<"\n";
  }
  return 0;
}
int getSize(const Stack &S){
  cout<<S.length<<"\n";
  return 0;
}

Stack S;

int main(void){
  S.length=0;
  unsigned long long N,i,j;
  unsigned long long e;
  cin>>N;
  for(i=0;i<N;i++){
    S.length=0;
    unsigned long long n;
    cin>>n;
    for(j=0;j<n;j++){
      string act;
      cin>>act;
      if(act=="push"){
        cin>>e;
        push(S,e);
        continue;
      }
      else if(act=="pop")pop(S);
      else if(act=="query")query(S);
      else if(act=="size")getSize(S);
    }
  }
  return 0;
}