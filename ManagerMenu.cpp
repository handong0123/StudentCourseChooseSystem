/*
**@���� ����ȡ
**@���� ManagerMenu���ʵ��
**@���� 2013/12/20
*/
#include "Login.h"
#include "ManagerMenu.h"
#include "Course.h"
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;
//��ʾ�˵�
void ManagerMenu::showManagerMenu(){
	cout<<"        �~�~�~�~�~�~�~�~�~�~ѧ��ѡ�ι���ϵͳ(����Ա)�~�~�~�~�~�~�~�~�~�~"<<endl;
	cout<<"        �~                                                            �~"<<endl;
	cout<<"        �~                 1.[����ѧ��] 2.[ɾ��ѧ��]                  �~"<<endl;
	cout<<"        �~                 3.[�鿴ѧ��] 4.[���ӿγ�]                  �~"<<endl;
	cout<<"        �~                 5.[ɾ���γ�] 6.[�鿴�γ�]                  �~"<<endl;
	cout<<"        �~                 7.[��    ��]                               �~"<<endl;
	cout<<"        �~                                                            �~"<<endl;
	cout<<"        �~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~"<<endl;
	cout<<"                           ������Ҫ�����ı��:"<<endl;
}
//���������ŵĹ���
void ManagerMenu::handleNum(int h,Manager &m){
	clearScreen();
	switch (h)
	{
	case 1:
		m.addStudent();
		break;
	case 2:
		m.deleteStudent();
		break;
	case 3:
		m.viewStudent();
		break;
	case 4:
		m.addCourse();
		break;
	case 5:
		m.deleteCourse();
		break;
	case 6:
		m.viewCourse();
		break;
	case 7:
		m.writeStudent();
		m.writeCourse();
		m.writeUser();
		m.exitSystem();
		break;
	default:
		cout<<"�����������׼���˳�"<<endl;
		exitSystem();
		break;
	}
}
