/*
**@���� ����ȡ
**@���� Login�࣬ʵ�ֵ�½����
**@���� 2013/12/20
*/
#include "Login.h"
#include <iostream>
#include <cstring>
//���캯��
Login::Login(char* username,char* password){
	this->password=new char[strlen(username)+1];
	this->username=new char[strlen(password)+1];
	errorNum=1;
	strcpy(this->username,username);
    strcpy(this->password,password);
}
//��������
Login::~Login(){
	delete[] username;
	delete[] password;
}
//�Ƿ��½�ɹ�
bool Login::isLogin(char *str1, char *str2){
	if(strcmp(str1,username)==0&&strcmp(str2,password)==0){
		return true;
	}
	if(errorNum==3)
	{
		std::cout<<std::endl;
		std::cout<<"���Ѿ�����3��,�����Զ��˳�."<<std::endl;
		exit(0);
	}
	errorNum++;
	return false;
}
