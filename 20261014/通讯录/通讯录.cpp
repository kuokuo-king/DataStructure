#include <iostream>
using namespace std;
#define MAX 1000
void ShowMenu(void){
    cout<<"************************"<<endl;
    cout<<"***** 1.添加联系人 *****"<<endl;
    cout<<"***** 2.显示联系人 *****"<<endl;
    cout<<"***** 3.删除联系人 *****"<<endl;
    cout<<"***** 4.查找联系人 *****"<<endl;
    cout<<"***** 5.修改联系人 *****"<<endl;
    cout<<"***** 6.清空联系人 *****"<<endl;
    cout<<"***** 0.退出通讯录 *****"<<endl;
    cout<<"************************"<<endl;
};

//联系人结构体
struct person{
  string name;
  string sex;
  int age;
  int phonenumber;
  string address;
};

//通讯录结构体
struct Book{
  person personArray[MAX];
  int size;
};

//1.添加联系人
void addPerson(Book &book){
  if(book.size == MAX){
    cout<<"通讯录已满"<<endl;
    return;
  }
  else{
    cout<<"姓名"<<endl;
    cin>>book.personArray[book.size].name;

    cout<<"性别"<<endl;
    cin>>book.personArray[book.size].sex;

    cout<<"年龄"<<endl;
    cin>>book.personArray[book.size].age;

    cout<<"电话"<<endl;
    cin>>book.personArray[book.size].phonenumber;

    cout<<"地址"<<endl;
    cin>>book.personArray[book.size].address;

    book.size++;
    cout<<"添加成功"<<endl;
    
  }
}
//2.显示联系人
void showPerson(Book &book){
  if(book.size ==0){
    cout<<"通讯录为空"<<endl;
    return;
  }
  else{
    int i;
    for(i=0;i<book.size;i++){
      cout<<"姓名:"<<book.personArray[i].name<<endl;
      cout<<"性别:"<<book.personArray[i].sex<<endl;
      cout<<"年龄:"<<book.personArray[i].age<<endl;
      cout<<"电话:"<<book.personArray[i].phonenumber<<endl;
      cout<<"地址:"<<book.personArray[i].address<<endl;
    }
  }
}
//查找--返回下标或-1
int isExist(Book book,string name){
  for(int i=0;i<book.size;i++){
    if(name==book.personArray[i].name){
      cout<<"找到此人"<<endl;
      return i;
    }
  }
  cout<<"未找到此人"<<endl;
  return -1;
}
//3.删除联系人
void personDelete(Book &book,int locate){
  for(locate++;locate<book.size;locate++){
    book.personArray[locate]=book.personArray[locate+1];
  }
  book.size--;
  cout<<"删除成功"<<endl;
  return;
}
//4.查找联系人
void personSearch(Book &book){
  string name;
  cout<<"请输入要查找的人的姓名："<<endl;
  cin>>name;
  int locate=isExist(book,name);
  if(locate!=-1){
    cout<<"姓名:"<<book.personArray[locate].name<<endl;
    cout<<"性别:"<<book.personArray[locate].sex<<endl;
    cout<<"年龄:"<<book.personArray[locate].age<<endl;
    cout<<"电话:"<<book.personArray[locate].phonenumber<<endl;
    cout<<"地址:"<<book.personArray[locate].address<<endl;
    return;
  }
  else return;
}
//5.修改联系人
void personModify(Book &book){
  string name;
  cout<<"请输入要修改的人的姓名："<<endl;
  cin>>name;
  int locate=isExist(book,name);
  if(locate!=-1){
    cout<<"请输入姓名:"<<endl;
    cin>>book.personArray[locate].name;

    cout<<"请输入性别:"<<endl;
    cin>>book.personArray[locate].sex;

    cout<<"请输入年龄:"<<endl;
    cin>>book.personArray[locate].age;

    cout<<"请输入电话:"<<endl;
    cin>>book.personArray[locate].phonenumber;

    cout<<"请输入地址:"<<endl;
    cin>>book.personArray[locate].address;

    cout<<"修改成功"<<endl;
    return;
  }
  else return;
}
//6.清空联系人
void personEmpty(Book &book){
  book.size=0;
  cout<<"已清空"<<endl;
  return;
}
int main(void){
    Book book;
    book.size=0;

    int select=0;
    ShowMenu();
    while(1){
        cout<<"选择操作"<<endl;
        cin>>select;
        switch(select){
          case 1://1.添加联系人
            addPerson(book);
            break;
          case 2://2.显示联系人
            showPerson(book);
            break;
          case 3://3.删除联系人
            {string name;
            cout<<"请输入要删除的联系人姓名:"<<endl;
            cin>>name;
            int locate=isExist(book,name);
            if(locate!=-1){
              personDelete(book,locate);
              break;
            }
            else break;
            }
          case 4://4.查找联系人
            personSearch(book);
            break;
          case 5://5.修改联系人 
            personModify(book);
            break;
          case 6://6.清空联系人
            personEmpty(book);
            break;
          case 0://0.退出通讯录
            system("pause");
            return 0;
          default:
            cout<<"输入异常"<<endl;
            break;
        }
    }
    system("pause");
    return 0;
}