/*
**@作者 李樟取
**@功能 Menu类声明
**@日期 2013/12/20
*/
#pragma once
#include <iostream>
#include "ManagerMenu.h"
#include "StudentMenu.h"
#include "Utils.h"
using namespace std;
class Menu:public Utils{
public:
	void showMainMenu();
	void showLogin();
	ManagerMenu getManagerMenu();
	StudentMenu getStudentMenu();
private:
	ManagerMenu m;
	StudentMenu s;
	
};