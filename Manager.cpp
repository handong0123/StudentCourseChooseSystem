/*
**@���� ����ȡ
**@���� Manager���ʵ��
**@���� 2013/12/20
*/
#include "Manager.h"
#include <iomanip>
//���캯��
Manager::Manager(){
	if(getFileSize("course.data")>0){
		ifstream is("course.data",ios_base::in);
		Course tempCourse;
		while (!is.eof())
		{
			is>>tempCourse;
			course.insert(map<string,Course>::value_type(tempCourse.getNum(),tempCourse));
		}
		is.close();
	}
	if(getFileSize("student.data")>0){
		ifstream isStudent("student.data",ios_base::in);
		Student tempStudent;
		while (!isStudent.eof())
		{
			isStudent>>tempStudent;
			student.insert(map<string,Student>::value_type(tempStudent.getNum(),tempStudent));
		}
		isStudent.close();
	}
}
//����ѧ��
void Manager::addStudent(){
	cout<<"������������Ϣ��"<<endl;
	cout<<"ѧ��  ����  �༶"<<endl;
	string num,name,hisClass;
	cin>>num>>name>>hisClass;
	Student s;
	s.setNum(num);
	s.setName(name);
	s.setHisClass(hisClass);
	map<string,Student>::iterator it=student.find(num);
	if(it==student.end()){
		student.insert(map<string,Student>::value_type(s.getNum(),s));
		cout<<"��ӳɹ�"<<endl;
	}else{
		cout<<"��ѧ���Ѵ���"<<endl;
	}
	pauseScreen();
	
}
//ɾ��ѧ��
void Manager::deleteStudent(){
	string num;
	cout<<"������ɾ��ѧ����ѧ��"<<endl;
	cin>>num;
	map<string,Student>::iterator it=student.find(num);
	if(it==student.end()){
		cout<<"��ѧ��������"<<endl;
	}else{
		student.erase(it);
		cout<<"ɾ���ɹ���"<<endl;
	}
	pauseScreen();
}
//���ӿγ�
void Manager::addCourse(){
	cout<<"������������Ϣ��"<<endl;
	cout<<"�γ̱��"<<" "<<"�γ�����"<<" "<<"�ڿ���ʦ"<<" "<<"�γ�ѧ��"<<" "<<"�γ�ѧʱ"<<endl;
	string num,name,teacher;
	double credit;
	int times;
	cin>>num>>name>>teacher>>credit>>times;
	Course c;
	c.setNum(num);
	c.setName(name);
	c.setTeacher(teacher);
	c.setCredit(credit);
	c.setTimes(times);
	map<string,Course>::iterator it=course.find(num);
	if(it==course.end()){
		course.insert(map<string,Course>::value_type(c.getNum(),c));
		cout<<"��ӳɹ�"<<endl;
	}else{
		cout<<"�ÿγ��Ѵ���"<<endl;
	}
	pauseScreen();
	
}
//ɾ���γ�
void Manager::deleteCourse(){
	string num;
	cout<<"������ɾ���γ̵ı��"<<endl;
	cin>>num;
	map<string,Course>::iterator it=course.find(num);
	if(it==course.end()){
		cout<<"�ÿγ̲�����"<<endl;
	}else{
		course.erase(it);
		cout<<"ɾ���ɹ���"<<endl;
	}
	pauseScreen();
}
//�鿴ѧ��
void Manager::viewStudent(){
	
	if(student.size()==0){
		cout<<"Ŀǰû��ѧ����"<<endl;
	}else{
		cout<<"�������������Щ����������Щ�����������"<<endl;
		cout<<"��   ѧ��   ��   ����   ��   �༶   ��"<<endl;
	
		for(map<string,Student>::iterator it=student.begin();it!=student.end();++it){
			cout<<"�������������੤���������੤����������"<<endl;
			cout<<"��"<<setiosflags(ios_base::left)<<setw(10)<<(it->second).getNum()<<"��"<<setiosflags(ios_base::left)<<setw(10)<<(it->second).getName()<<"��"<<setiosflags(ios_base::left)<<setw(10)<<(it->second).getHisClass()<<"��"<<endl;
		}
		cout<<"�������������ة����������ة�����������"<<endl;
	}
	pauseScreen();
}
//�鿴�γ�
void Manager::viewCourse(){
	if(course.size()==0){
		cout<<"Ŀǰû�пγ̣�"<<endl;
	}else{
		cout<<"���������������Щ������������Щ������������Щ������������Щ�������������"<<endl;
		cout<<"��  �γ̱��  ��  �γ�����  ��  �ڿ���ʦ  ��  �γ�ѧ��  ��  �γ�ѧʱ  ��"<<endl;
		for(map<string,Course>::iterator it=course.begin();it!=course.end();++it){
		cout<<"���������������੤�����������੤�����������੤�����������੤������������"<<endl;
		cout<<"��"<<setiosflags(ios_base::left)<<setw(12)<<(it->second).getNum()<<"��"<<setiosflags(ios_base::left)<<setw(12)<<(it->second).getName()<<"��"<<setiosflags(ios_base::left)<<setw(12)<<(it->second).getTeacher()<<"��"<<setiosflags(ios_base::left)<<setw(12)<<(it->second).getCredit()<<"��"<<setiosflags(ios_base::left)<<setw(12)<<(it->second).getTimes()<<"��"<<endl;
	}
		cout<<"���������������ة������������ة������������ة������������ة�������������"<<endl;
	}
	pauseScreen();
}
//д���ļ�
void Manager::writeStudent(){
	remove("student.data");
	ofstream os("student.data",ios_base::app);
	for(map<string,Student>::iterator it=student.begin();it!=student.end();++it){
		if(it==student.begin()){
			os<<(it->second).getNum()<<" "<<(it->second).getName()<<" "<<(it->second).getHisClass();
		}else{
			os<<endl;
			os<<(it->second).getNum()<<" "<<(it->second).getName()<<" "<<(it->second).getHisClass();
		}
		
	}
}
//д���ļ�
void Manager::writeCourse(){
	remove("course.data");
	ofstream os("course.data",ios_base::app);
	for(map<string,Course>::iterator it=course.begin();it!=course.end();++it){
		if(it==course.begin()){
			os<<(it->second);
		}else{
			os<<endl;
			os<<(it->second);
		}
	}
}
//д���ļ�
void Manager::writeUser(){
	remove("user.data");
	ofstream os("user.data",ios_base::app);
	for(map<string,Student>::iterator it=student.begin();it!=student.end();++it){
		if(it==student.begin()){
			os<<(it->second).getNum()<<" "<<(it->second).getNum();
		}else{
			os<<endl;
			os<<(it->second).getNum()<<" "<<(it->second).getNum();
		}
		
	}
	
}