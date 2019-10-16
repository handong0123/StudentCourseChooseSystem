/*
**@作者 李樟取
**@功能 Student类声明
**@日期 2013/12/20
*/
#pragma once
#include "Course.h"
#include "Utils.h"
#include "Role.h"
#include <string>
#include <fstream>
#include <map>
using namespace std;
class Student:public Role,public Utils{
public:
	friend ifstream & operator>> (ifstream &in,  Student &c);
	friend ofstream & operator<< (ofstream &out,  Student &c);
	Student();
	void selectCourse();
	void cancelCourse();
	void viewCourse();
	void allCourse();
	void printInformation();
	string getName();
	string getNum();
	string getHisClass();
	void setName(string);
	void setNum(string);
	void setHisClass(string);
	void writeCourse();
private:
	string name;
	string num;
	string hisClass;
	map<string,Course> course,all;
};
