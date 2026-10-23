#include <iostream>
#include <string>
using namespace std;
void Search(string med,string beh){
	if(med.empty()||beh.empty())return;
	char root=beh.back();
	cout<<root;
	int loc=med.find(root);
	Search(med.substr(0,loc),beh.substr(0,loc));
	Search(med.substr(loc+1),beh.substr(loc,beh.length()-1-loc));
}
int main(void){
	string med,beh;
	cin>>med>>beh;
	Search(med,beh);
	return 0;
}