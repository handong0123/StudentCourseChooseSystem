/*
**@作者 李樟取
**@功能 ManagerMenu类声明
**@日期 2013/12/20
*/
#pragma once
#include "Utils.h"
#include "Student.h"
#include <iostream>
#include "Manager.h"
#include <map>
using namespace std;
class ManagerMenu:public Utils{
public:
	void showManagerMenu();
	void handleNum(int,Manager&);
private:
};
