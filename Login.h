/*
**@作者 李樟取
**@功能 Login类声明
**@日期 2013/12/20
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