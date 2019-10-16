#pragma once
/*
**@���� ����ȡ
**@���� Course������
**@���� 2013/12/20
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
	string teacher;//�ڿ���ʦ
	string classNum;//�γ̱��
	string className;//�γ�����
	double credit;//ѧ��
	int times;//ѧʱ
};
