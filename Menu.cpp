/*
**@���� ����ȡ
**@���� Menu���ʵ��
**@���� 2013/12/20
*/
#include "ManagerMenu.h"
#include "StudentMenu.h"
#include "Menu.h"
#include "Login.h"
#include <fstream>
//��ȡ��Ա����ManagerMenu
ManagerMenu Menu::getManagerMenu(){
	return m;
}
//��ȡ��Ա����StudentMenu
StudentMenu Menu::getStudentMenu(){
	return s;
}
//��ʾ�˵�
void Menu::showMainMenu(){
	cout<<"                    �~�~�~�~�~�~ѧ��ѡ�ι���ϵͳ�~�~�~�~�~"<<endl;
	cout<<"                    �~                                  �~"<<endl;
	cout<<"                    �~            1.����Ա��½          �~"<<endl;
	cout<<"                    �~            2.ѧ���˵�½          �~"<<endl;
    cout<<"                    �~            3.��      ��          �~"<<endl;
	cout<<"                    �~                                  �~"<<endl;
	cout<<"                    �~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~"<<endl;
	cout<<"                              ������Ҫ�����ı��:"<<endl;
}
//��ʾ��½����
void Menu::showLogin(){
	cout<<"                         �������������Щ���������������������"<<endl;
	cout<<"                         ��  �˺�:   ��                    ��"<<endl;
	cout<<"                         �������������੤��������������������"<<endl;
	cout<<"                         ��  ����:   ��                    ��"<<endl;
	cout<<"                         �������������ة���������������������"<<endl;
}
