/*
**@作者 李樟取
**@功能 Manager类声明
**@日期 2013/12/20
*/
#pragma once
#include "Role.h"
#include "Student.h"
#include "Course.h"
#include "Utils.h"
#include <string>
#include <map>
#include <fstream>
using namespace std;

class Manager:public Role,public Utils{
public:
	Manager();
	void addStudent();
	void deleteStudent();
	void addCourse();
	void deleteCourse();
	void viewStudent();
	void viewCourse();
	void writeStudent();
	void writeCourse();
	void writeUser();
private:
	map<string,Course> course;
	map<string,Student> student;
};