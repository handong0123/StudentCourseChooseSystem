#pragma once
/*
**@作者 李樟取
**@功能 Course类声明
**@日期 2013/12/20
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Course{
public:
	friend ifstream & operator>> (ifstream &in,Course &c);
	friend ofstream & operator<< (ofstream &out,Course &c);
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
	string teacher;//授课老师
	string classNum;//课程编号
	string className;//课程名称
	double credit;//学分
	int times;//学时
};
