/*
**@���� ����ȡ
**@���� Login������
**@���� 2013/12/20
*/
#pragma once
class Login
{
public:
	Login(char*,char*);
	~Login();
	bool isLogin(char*,char*);
private:
	char* username;
	char* password;
    int  errorNum;
};