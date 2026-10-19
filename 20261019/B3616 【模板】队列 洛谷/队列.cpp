#include <iostream>
#include <string>
using namespace std;
#define MAXSIZE 10005

typedef struct MyQueue{
  long data[MAXSIZE];
  long head;
  long tail;
}MyQueue;
MyQueue Q;
void push(MyQueue &Q,long e){
  Q.data[Q.tail]=e;
  Q.tail=(Q.tail+1)%MAXSIZE;
  return;
}
void pop(MyQueue &Q){
  if(Q.head==Q.tail)cout<<"ERR_CANNOT_POP"<<"\n";
  else Q.head=(Q.head+1)%MAXSIZE;
  return;
}
void query(const MyQueue &Q){
  if(Q.head==Q.tail)cout<<"ERR_CANNOT_QUERY"<<"\n";
  else cout<<Q.data[Q.head]<<"\n";
}
void size(const MyQueue &Q){
  cout<<(Q.tail-Q.head+MAXSIZE)%MAXSIZE<<"\n";
}
int main(void){
  Q.head=0;
  Q.tail=0;
  long N,i;
  long act;
  long e;
  cin>>N;
  for(i=0;i<N;i++){
    cin>>act;
    switch (act){
      case 1:
        cin>>e;
        push(Q,e);
        break;
      case 2:
        pop(Q);
        break;
      case 3:
        query(Q);
        break;
      case 4:
        size(Q);
        break;
    }
  }
  return 0;
}
