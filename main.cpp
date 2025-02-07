/*
**@作者 李樟取
**@功能 主函数，程序入口
**@日期 2013/12/20
*/
#include "Login.h"
#include "Menu.h"
#include "Manager.h"
#include <iostream>
#include <fstream>
using namespace std;
void operatorNum(int h,Menu &m);
int main(){
	Menu menu;
	int handle;
	menu.showMainMenu();
	cin>>handle;
	operatorNum(handle,menu);
	return 0;
}
//整个程序的控制函数
void operatorNum(int h,Menu &m){
	m.clearScreen();
	switch (h)
	{
	case 1:
		{
			ifstream is("admin.data",ios_base::in);
			char tempUsername[20];
			char tempPassword[20];
			is>>tempUsername>>tempPassword;
			is.close();
			Login login(tempUsername,tempPassword);
			char username[20],password[20];
begin1:
			cout<<"请输入你的帐号和密码:"<<endl;
			m.showLogin();
			m.position(39, 2);
			cin>>username;
			m.position(39, 4);
			cin>>password;
			Manager manager;
			if(login.isLogin(username,password))
			{
				int t;
				
				manager.setUsername(username);
				manager.setPassword(password);
				while (1)
				{
					m.clearScreen();
					m.getManagerMenu().showManagerMenu();
					cin>>t;
					m.clearScreen();
					m.getManagerMenu().handleNum(t,manager);
				}
			}
			else
			{
				cout<<endl;
				cout<<"用户名和密码输入错误,请重新输入."<<endl;	
				m.pauseScreen();
				m.clearScreen();
				goto begin1;
			}
			break;
		}
	case 2:
		{
			
			bool hasStudent;
			char tempUsername[20];
			char tempPassword[20];
			char username[20],password[20];
begin2:
			cout<<"请输入你的帐号和密码:"<<endl;
			m.showLogin();
			m.position(39, 2);
			cin>>username;
			ifstream is("user.data",ios_base::in);
			while (!is.eof()){
				is>>tempUsername>>tempPassword;
				if (strcmp(tempUsername,username)==0){
					hasStudent=true;
					break;
				}
			}
			is.close();
			Login login(tempUsername,tempPassword);
			m.position(39, 4);
			cin>>password;
			
			if(login.isLogin(username,password))
			{
				int t;
				string tnum,tname,tclass;
				ofstream cu("current.data",ios_base::out);
				cu<<username<<" "<<password;
				cu.close();	
				Student student;
				student.setUsername(username);
				student.setPassword(password);
				while (1)
				{
					m.clearScreen();
					m.getStudentMenu().showStudentMenu();
					cin>>t;
					m.clearScreen();	
					m.getStudentMenu().handleNum(t,student);
				}
			}
			else
			{
				cout<<endl;
				cout<<"用户名不存在或者密码错误."<<endl;
				m.pauseScreen();
				m.clearScreen();
				goto begin2;
			}
			break;
		}
	case 3:
		m.exitSystem();
		m.pauseScreen();
		break;
	}
}

