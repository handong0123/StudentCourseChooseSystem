/*
**@���� ����ȡ
**@���� StudentMenu���ʵ��
**@���� 2013/12/20
*/
#include "StudentMenu.h"
#include <iostream>
using namespace std;
//��ʾ�˵�
void StudentMenu::showStudentMenu(){
	cout<<"        �~�~�~�~�~�~�~�~�~�~ѧ��ѡ�ι���ϵͳ(ѧ����)�~�~�~�~�~�~�~�~�~�~"<<endl;
	cout<<"        �~                                                            �~"<<endl;
	cout<<"        �~                 1.[ѡ��γ�] 2.[��ѡ�γ�]                  �~"<<endl;
	cout<<"        �~                 3.[��ѡ�γ�] 4.[��ѡ�γ�]                  �~"<<endl;
	cout<<"        �~                 5.[��Ϣ���] 6.[��    ��]                  �~"<<endl;
	cout<<"        �~                                                            �~"<<endl;
	cout<<"        �~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~"<<endl;
	cout<<"                           ������Ҫ�����ı��:"<<endl;
}
//������
void StudentMenu::handleNum(int h,Student &s){
	clearScreen();
	switch (h)
	{
	case 1:
		s.selectCourse();
		break;
	case 2:
		s.cancelCourse();
		break;
	case 3:
		s.viewCourse();
		break;
	case 4:
		s.allCourse();
		break;
	case 5:
		s.printInformation();
		break;
	case 6:
		s.writeCourse();
		s.exitSystem();
		break;
	default:
		cout<<"�����������׼���˳�"<<endl;
		s.exitSystem();
		break;
	}
}
