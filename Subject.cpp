#include "Subject.h"
string Subject::getNum(){
	return classNum;
}
string Subject::getName(){
	return className;
}
string Subject::getTeacher(){
	return teacher;
}
double Subject::getCredit(){
	return credit;
}
int Subject::getTimes(){
	return times;
}
void Subject::setNum(string classNum){
	this->classNum=classNum;
}
void Subject::setName(string className){
	this->className=className;
}
void Subject::setCredit(double credit){
	this->credit=credit;
}
void Subject::setTimes(int times){
	this->times=times;
}
void Subject::setTeacher(string teacher){
	this->teacher=teacher;
}
