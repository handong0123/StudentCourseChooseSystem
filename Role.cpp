/*
**@���� ����ȡ
**@���� ��ǰ��¼��ɫRole���ʵ��
**@���� 2013/12/20
*/
#include "Role.h"
//�����û���
void Role::setUsername(string n){
	this->username=n;
}
//��������
void Role::setPassword(string p){
	this->password=p;
}
//��ȡ�û���
string Role::getUsername(){
	return username;
}