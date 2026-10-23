#include <iostream>
#include <string>
using namespace std;
void Search(string fro,string med){
	if(fro.empty() || med.empty())return;
	char root=fro.front();
	int loc =med.find(root);
	Search(fro.substr(1,loc),med.substr(0,loc));
	Search(fro.substr(loc+1),med.substr(loc+1));
	cout<<root;
}
int main(void){
	string fro,med;
	cin>>fro>>med;
	Search(fro,med);
	return 0;
}