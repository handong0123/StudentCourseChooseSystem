/*
**@作者 李樟取
**@功能 Role类声明
**@日期 2013/12/20
*/
#pragma once
#include <string>
using namespace std;
class Role{
public:
	void setUsername(string);
	void setPassword(string);
	string getUsername();
private:
	string username;
	string password;
};