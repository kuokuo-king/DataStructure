#include <iostream>
using namespace std;
char Data[200];
char lc[200],rc[200];
void preOrder(char i){
	if(i == '*')return;
	cout<<i;
	preOrder(lc[i]);
	preOrder(rc[i]);
}
 int main(void){
	int n,i;
	char root;
	cin>>n;
	for(i=0;i<n;i++){
		char a,b,c;
		cin>>a>>b>>c;
		if(i==0)root=a;
		lc[a]=b;
		rc[a]=c;
	}
	preOrder(root);
	return 0;
 }