#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct Person{
    string name;
    int birthday;
    int id;
};
bool cmp(const Person& a,const Person& b){
    if(a.birthday!=b.birthday)return a.birthday<b.birthday;
    return a.id>b.id;
}
Person P[100];
int main(void){
    int n,i,y,m,d;
    string name;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>name>>y>>m>>d;
        P[i].name=name;
        P[i].birthday=y*10000+m*100+d;
        P[i].id=i;
    }
    sort(P,P+n,cmp);
    for(i=0;i<n;i++){
        cout<<P[i].name<<"\n";
    }
    return 0;
}
