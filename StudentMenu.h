/*
**@作者 李樟取
**@功能 StudentMenu声明
**@日期 2013/12/20
*/
#pragma once
#include "Utils.h"
#include "Student.h"
class StudentMenu:public Utils{
public:
	void showStudentMenu();
	void handleNum(int,Student&);
private:
};
