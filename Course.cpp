/*
**@作者 李樟取
**@功能 Course类的实现
**@日期 2013/12/20
*/
#include "Course.h"
//重载运算符>>
ifstream & operator>> (ifstream &in,Course &c){
	string num,name,teacher;
	double credit;
	int times;
	in>>num>>name>>teacher>>credit>>times;
	c.setNum(num);
	c.setName(name);
	c.setTeacher(teacher);
	c.setCredit(credit);
	c.setTimes(times);
	return in;
}
//重载运算符<<
ofstream & operator<< (ofstream &out,Course &c){
	out<<c.getNum()<<" "<<c.getName()<<" "<<c.getTeacher()<<" "<<c.getCredit()<<" "<<c.getTimes();
	return out;
}
//获取课程编号
string Course::getNum(){
	return classNum;
}
//获取课程名称
string Course::getName(){
	return className;
}//获取授课老师
string Course::getTeacher(){
	return teacher;
}
//获取学分
double Course::getCredit(){
	return credit;
}
//获取学时
int Course::getTimes(){
	return times;
}
//设置课程编号
void Course::setNum(string classNum){
	this->classNum=classNum;
}
//设置课程名称
void Course::setName(string className){
	this->className=className;
}
//设置课程学分
void Course::setCredit(double credit){
	this->credit=credit;
}
//设置课程学时
void Course::setTimes(int times){
	this->times=times;
}
//设置授课老师
void Course::setTeacher(string teacher){
	this->teacher=teacher;
}