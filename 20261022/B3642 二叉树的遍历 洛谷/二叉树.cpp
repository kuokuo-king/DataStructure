#include <iostream>
using namespace std;
#define MAXSIZE 1000005
int Data[MAXSIZE];
int lc[MAXSIZE],rc[MAXSIZE];
void preOrder(int i){
	if(i == 0)return;
	cout<<i<<" ";
	preOrder(lc[i]);
	preOrder(rc[i]);
}
void medOrder(int i){
	if(i == 0)return;
	medOrder(lc[i]);
	cout<<i<<" ";
	medOrder(rc[i]);
}
void behOrder(int i){
	if(i == 0)return;
	behOrder(lc[i]);
	behOrder(rc[i]);
	cout<<i<<" ";
}
 int main(void){
	int n,i;
	cin>>n;
	int a,b;
	for(i=1;i<=n;i++){
		cin>>a>>b;
		lc[i]=a;
		rc[i]=b;
	}
	preOrder(1);
	cout<<"\n";
	medOrder(1);
	cout<<"\n";
	behOrder(1);
	return 0;
 }
