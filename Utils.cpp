/*
**@���� ����ȡ
**@���� ������Utils
**@���� 2013/12/20
*/
#include "Utils.h"
//���ƹ��ľ���λ��
void Utils::position(int x, int y){
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = {x, y};
	SetConsoleCursorPosition(h, pos);
}
//����
void Utils::clearScreen(){
	system("cls");
}
//��ͣ
void Utils::pauseScreen(){
	cout<<"�����⽨����."<<endl;
	system("pause");
}
//�˳�
void Utils::exitSystem(){
	cout<<"�����˳�..."<<endl;
	exit(0);
}
//��ȡ�ļ���С
long Utils::getFileSize(string name){
	ifstream in(name.c_str());   
	in.seekg(0,ios::end);   
	long size = in.tellg();   
	in.close();
	return size;
}