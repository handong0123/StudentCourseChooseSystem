/*
**@���� ����ȡ
**@���� Student���ʵ��
**@���� 2013/12/20
*/
#include "Student.h"
#include <iomanip>
//���������>>
ifstream & operator>> (ifstream &in, Student &s){
	string num,name,cl;
	in>>num>>name>>cl;
	s.setNum(num);
	s.setName(name);
	s.setHisClass(cl);
	return in;
}
//���������<<
ofstream & operator<< (ofstream &out, Student &s){
	out<<s.getNum()<<" "<<s.getName()<<" "<<s.getHisClass();
	return out;
}
//���캯��
Student::Student(){
	string tu;
	string tp;
	Course tempCourse;
	if(getFileSize("course.data")>0){
		ifstream is("course.data",ios_base::in);
		while (!is.eof())
		{
			is>>tempCourse;
			all.insert(map<string,Course>::value_type(tempCourse.getNum(),tempCourse));
		}
		is.close();
	}
	
	if(getFileSize("current.data")>0){
		ifstream ru("current.data",ios_base::in);
		ru>>tu>>tp;
		ru.close();
	}
	num=tu;
	string file=".\\data\\"+tu;
	if(getFileSize(file.c_str())>0){
		ifstream is2(file.c_str(),ios_base::in);
		Course tempCourse1;
		while (!is2.eof())
		{	
			is2>>tempCourse1;
			course.insert(map<string,Course>::value_type(tempCourse1.getNum(),tempCourse1));
		}
		is2.close();
	}
	
}
//ѡ��
void Student::selectCourse(){
	string num;
	cout<<"������Ҫѡ��Ŀγ̱��"<<endl;
	cin>>num;
	map<string,Course>::iterator it=all.find(num);
	if(it==all.end()){
		cout<<"�ÿγ̲����ڣ�����ѡ��"<<endl;
	}else{
		course.insert(map<string,Course>::value_type((it->second).getNum(),(it->second)));
		cout<<"���ѳɹ�ѡ��ÿγ̣�"<<endl;
	}
	pauseScreen();
}
//�˿�
void Student::cancelCourse(){
	string num;
	cout<<"������Ҫȡ��ѡ��Ŀγ̱��"<<endl;
	cin>>num;
	map<string,Course>::iterator it=course.find(num);
	if(it==course.end()){
		cout<<"��û��ѡ��ÿγ̣�"<<endl;
	}else{
		course.erase(it);
		cout<<"���ѳɹ�ȡ��ѡ��ÿγ̣�"<<endl;
	}
	pauseScreen();
}
//�鿴��ѡ�γ�
void Student::viewCourse(){
	if(course.size()==0){
		cout<<"û��ѡ���κογ�"<<endl;
	}else{
		cout<<"����ѡ��Ŀγ�����:"<<endl;
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
//�鿴���пγ�
void Student::allCourse(){
	if(all.size()==0){
		cout<<"û�пγ̿�ѡ��"<<endl;
	}else
	{
		cout<<"���п�ѡ�Ŀγ�����:"<<endl;
		cout<<"���������������Щ������������Щ������������Щ������������Щ�������������"<<endl;
		cout<<"��  �γ̱��  ��  �γ�����  ��  �ڿ���ʦ  ��  �γ�ѧ��  ��  �γ�ѧʱ  ��"<<endl;
		for(map<string,Course>::iterator it=all.begin();it!=all.end();++it){
			cout<<"���������������੤�����������੤�����������੤�����������੤������������"<<endl;
			cout<<"��"<<setiosflags(ios_base::left)<<setw(12)<<(it->second).getNum()<<"��"<<setiosflags(ios_base::left)<<setw(12)<<(it->second).getName()<<"��"<<setiosflags(ios_base::left)<<setw(12)<<(it->second).getTeacher()<<"��"<<setiosflags(ios_base::left)<<setw(12)<<(it->second).getCredit()<<"��"<<setiosflags(ios_base::left)<<setw(12)<<(it->second).getTimes()<<"��"<<endl;
		}
		cout<<"���������������ة������������ة������������ة������������ة�������������"<<endl;
	}
	pauseScreen();
}
//��ӡ��Ϣ
void Student::printInformation(){
	cout<<"������Ϣ����:"<<endl;
	ifstream isStudent("student.data",ios_base::in);
	string n1,n2,n3;
	while (!isStudent.eof())
	{
		isStudent>>n1>>n2>>n3;
		if(n1==num){
			cout<<"�������������Щ����������Щ�����������"<<endl;
			cout<<"��   ѧ��   ��   ����   ��   �༶   ��"<<endl;
			cout<<"�������������੤���������੤����������"<<endl;
			cout<<"��"<<setiosflags(ios_base::left)<<setw(10)<<n1<<"��"<<setiosflags(ios_base::left)<<setw(10)<<n2<<"��"<<setiosflags(ios_base::left)<<setw(10)<<n3<<"��"<<endl;
			cout<<"�������������ة����������ة�����������"<<endl;
			break;
		}
	}
	isStudent.close();
	viewCourse();
}
//д���ļ�
void Student::writeCourse(){
	remove("current.data");
	string file=".\\data\\"+getUsername();
	remove(file.c_str());
	ofstream os(file.c_str(),ios_base::app);
	for(map<string,Course>::iterator it=course.begin();it!=course.end();++it){
		if(it==course.begin()){
			os<<(it->second);
		}else{
			os<<endl;
			os<<(it->second);
		}
	}
}
//��ȡ����
string Student::getName(){
	return name;
}
//��ȡѧ��
string Student::getNum(){
	return num;
}
//��ȡ�༶
string Student::getHisClass(){
	return hisClass;
}
//��������
void Student::setName(string n){
	this->name=n;
}
//����ѧ��
void Student::setNum(string n){
	this->num=n;
}
//���ð༶
void Student::setHisClass(string c){
	this->hisClass=c;
}