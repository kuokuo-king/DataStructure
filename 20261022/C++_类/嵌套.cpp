#include <iostream>
#include <string>
using namespace std;

class Phone{
public:
	Phone(string name){
		m_PhoneName=name;
	}
	string m_PhoneName;
};
class Person
{
public:
	Person(string name,string phonename):m_Name(name),m_Phone(phonename){}
	string m_Name;
	Phone m_Phone;
};
int main(void){
	Person yanhuo("yanhuo","Sally");
	cout<<yanhuo.m_Phone.m_PhoneName;
}