/*
**@作者 李樟取
**@功能 当前登录角色Role类的实现
**@日期 2013/12/20
*/
#include "Role.h"
//设置用户名
void Role::setUsername(string n){
	this->username=n;
}
//设置密码
void Role::setPassword(string p){
	this->password=p;
}
//获取用户名
string Role::getUsername(){
	return username;
}