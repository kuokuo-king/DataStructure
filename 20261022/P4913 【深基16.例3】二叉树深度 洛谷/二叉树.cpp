#include <iostream>
using namespace std;
#define MAXSIZE 1000005
int Data[MAXSIZE];
int lc[MAXSIZE],rc[MAXSIZE];
int MAX(int a,int b){
	return a>b?a:b;
}
void Search(int i,int &cnt,int &max){
	if(i==0){
		return;
	}
	cnt++;
	max=MAX(cnt,max);
	Search(lc[i],cnt,max);
	Search(rc[i],cnt,max);
	cnt--;
	return;
}
 int main(void){
	int n,i,max=0,cnt=0;
	cin>>n;
	int a,b;
	for(i=1;i<=n;i++){
		cin>>a>>b;
		lc[i]=a;
		rc[i]=b;
	}
	Search(1,cnt,max);
	cout<<max;
	return 0;
 }
