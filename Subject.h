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
	string classNum;//�γ̱��
	string className;//�γ�����
	double credit;//ѧ��
	int times;//ѧʱ
};
