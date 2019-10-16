/*
**@作者 李樟取
**@功能 Student类的实现
**@日期 2013/12/20
*/
#include "Student.h"
#include <iomanip>
//重载运算符>>
ifstream & operator>> (ifstream &in, Student &s){
	string num,name,cl;
	in>>num>>name>>cl;
	s.setNum(num);
	s.setName(name);
	s.setHisClass(cl);
	return in;
}
//重载运算符<<
ofstream & operator<< (ofstream &out, Student &s){
	out<<s.getNum()<<" "<<s.getName()<<" "<<s.getHisClass();
	return out;
}
//构造函数
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
//选课
void Student::selectCourse(){
	string num;
	cout<<"请输入要选择的课程编号"<<endl;
	cin>>num;
	map<string,Course>::iterator it=all.find(num);
	if(it==all.end()){
		cout<<"该课程不存在，不能选择"<<endl;
	}else{
		course.insert(map<string,Course>::value_type((it->second).getNum(),(it->second)));
		cout<<"你已成功选择该课程！"<<endl;
	}
	pauseScreen();
}
//退课
void Student::cancelCourse(){
	string num;
	cout<<"请输入要取消选择的课程编号"<<endl;
	cin>>num;
	map<string,Course>::iterator it=course.find(num);
	if(it==course.end()){
		cout<<"你没有选择该课程！"<<endl;
	}else{
		course.erase(it);
		cout<<"你已成功取消选择该课程！"<<endl;
	}
	pauseScreen();
}
//查看已选课程
void Student::viewCourse(){
	if(course.size()==0){
		cout<<"没有选择任何课程"<<endl;
	}else{
		cout<<"您已选择的课程如下:"<<endl;
		cout<<"┌──────┬──────┬──────┬──────┬──────┐"<<endl;
		cout<<"│  课程编号  │  课程名称  │  授课老师  │  课程学分  │  课程学时  │"<<endl;
		for(map<string,Course>::iterator it=course.begin();it!=course.end();++it){
			cout<<"├──────┼──────┼──────┼──────┼──────┤"<<endl;
			cout<<"│"<<setiosflags(ios_base::left)<<setw(12)<<(it->second).getNum()<<"│"<<setiosflags(ios_base::left)<<setw(12)<<(it->second).getName()<<"│"<<setiosflags(ios_base::left)<<setw(12)<<(it->second).getTeacher()<<"│"<<setiosflags(ios_base::left)<<setw(12)<<(it->second).getCredit()<<"│"<<setiosflags(ios_base::left)<<setw(12)<<(it->second).getTimes()<<"│"<<endl;
		}
		cout<<"└──────┴──────┴──────┴──────┴──────┘"<<endl;
	}
	pauseScreen();
}
//查看所有课程
void Student::allCourse(){
	if(all.size()==0){
		cout<<"没有课程可选！"<<endl;
	}else
	{
		cout<<"所有可选的课程如下:"<<endl;
		cout<<"┌──────┬──────┬──────┬──────┬──────┐"<<endl;
		cout<<"│  课程编号  │  课程名称  │  授课老师  │  课程学分  │  课程学时  │"<<endl;
		for(map<string,Course>::iterator it=all.begin();it!=all.end();++it){
			cout<<"├──────┼──────┼──────┼──────┼──────┤"<<endl;
			cout<<"│"<<setiosflags(ios_base::left)<<setw(12)<<(it->second).getNum()<<"│"<<setiosflags(ios_base::left)<<setw(12)<<(it->second).getName()<<"│"<<setiosflags(ios_base::left)<<setw(12)<<(it->second).getTeacher()<<"│"<<setiosflags(ios_base::left)<<setw(12)<<(it->second).getCredit()<<"│"<<setiosflags(ios_base::left)<<setw(12)<<(it->second).getTimes()<<"│"<<endl;
		}
		cout<<"└──────┴──────┴──────┴──────┴──────┘"<<endl;
	}
	pauseScreen();
}
//打印信息
void Student::printInformation(){
	cout<<"您的信息如下:"<<endl;
	ifstream isStudent("student.data",ios_base::in);
	string n1,n2,n3;
	while (!isStudent.eof())
	{
		isStudent>>n1>>n2>>n3;
		if(n1==num){
			cout<<"┌─────┬─────┬─────┐"<<endl;
			cout<<"│   学号   │   姓名   │   班级   │"<<endl;
			cout<<"├─────┼─────┼─────┤"<<endl;
			cout<<"│"<<setiosflags(ios_base::left)<<setw(10)<<n1<<"│"<<setiosflags(ios_base::left)<<setw(10)<<n2<<"│"<<setiosflags(ios_base::left)<<setw(10)<<n3<<"│"<<endl;
			cout<<"└─────┴─────┴─────┘"<<endl;
			break;
		}
	}
	isStudent.close();
	viewCourse();
}
//写入文件
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
//获取姓名
string Student::getName(){
	return name;
}
//获取学号
string Student::getNum(){
	return num;
}
//获取班级
string Student::getHisClass(){
	return hisClass;
}
//设置姓名
void Student::setName(string n){
	this->name=n;
}
//设置学号
void Student::setNum(string n){
	this->num=n;
}
//设置班级
void Student::setHisClass(string c){
	this->hisClass=c;
}