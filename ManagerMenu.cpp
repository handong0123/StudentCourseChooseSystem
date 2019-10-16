/*
**@作者 李樟取
**@功能 ManagerMenu类的实现
**@日期 2013/12/20
*/
#include "Login.h"
#include "ManagerMenu.h"
#include "Course.h"
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;
//显示菜单
void ManagerMenu::showManagerMenu(){
	cout<<"        ▇▇▇▇▇▇▇▇▇▇学生选课管理系统(管理员)▇▇▇▇▇▇▇▇▇▇"<<endl;
	cout<<"        ▇                                                            ▇"<<endl;
	cout<<"        ▇                 1.[增加学生] 2.[删除学生]                  ▇"<<endl;
	cout<<"        ▇                 3.[查看学生] 4.[增加课程]                  ▇"<<endl;
	cout<<"        ▇                 5.[删除课程] 6.[查看课程]                  ▇"<<endl;
	cout<<"        ▇                 7.[退    出]                               ▇"<<endl;
	cout<<"        ▇                                                            ▇"<<endl;
	cout<<"        ▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇"<<endl;
	cout<<"                           请输入要操作的编号:"<<endl;
}
//处理各个编号的功能
void ManagerMenu::handleNum(int h,Manager &m){
	clearScreen();
	switch (h)
	{
	case 1:
		m.addStudent();
		break;
	case 2:
		m.deleteStudent();
		break;
	case 3:
		m.viewStudent();
		break;
	case 4:
		m.addCourse();
		break;
	case 5:
		m.deleteCourse();
		break;
	case 6:
		m.viewCourse();
		break;
	case 7:
		m.writeStudent();
		m.writeCourse();
		m.writeUser();
		m.exitSystem();
		break;
	default:
		cout<<"输入错误，正在准备退出"<<endl;
		exitSystem();
		break;
	}
}
