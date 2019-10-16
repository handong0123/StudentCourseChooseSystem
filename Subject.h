#pragma once
#include <iostream>
#include <string>
using namespace std;
class Subject{
public:
	string getNum();
	string getName();
	string getTeacher();
	double getCredit();
	int getTimes();
	void setNum(string);
	void setName(string);
	void setCredit(double);
	void setTimes(int);
	void setTeacher(string);
private:
	string teacher;
	string classNum;//课程编号
	string className;//课程名称
	double credit;//学分
	int times;//学时
};
