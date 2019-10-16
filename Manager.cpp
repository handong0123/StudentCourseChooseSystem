/*
**@作者 李樟取
**@功能 Manager类的实现
**@日期 2013/12/20
*/
#include "Manager.h"
#include <iomanip>
//构造函数
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
//增加学生
void Manager::addStudent(){
	cout<<"请输入以下信息："<<endl;
	cout<<"学号  姓名  班级"<<endl;
	string num,name,hisClass;
	cin>>num>>name>>hisClass;
	Student s;
	s.setNum(num);
	s.setName(name);
	s.setHisClass(hisClass);
	map<string,Student>::iterator it=student.find(num);
	if(it==student.end()){
		student.insert(map<string,Student>::value_type(s.getNum(),s));
		cout<<"添加成功"<<endl;
	}else{
		cout<<"该学生已存在"<<endl;
	}
	pauseScreen();
	
}
//删除学生
void Manager::deleteStudent(){
	string num;
	cout<<"请输入删除学生的学号"<<endl;
	cin>>num;
	map<string,Student>::iterator it=student.find(num);
	if(it==student.end()){
		cout<<"该学生不存在"<<endl;
	}else{
		student.erase(it);
		cout<<"删除成功！"<<endl;
	}
	pauseScreen();
}
//增加课程
void Manager::addCourse(){
	cout<<"请输入以下信息："<<endl;
	cout<<"课程编号"<<" "<<"课程名称"<<" "<<"授课老师"<<" "<<"课程学分"<<" "<<"课程学时"<<endl;
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
		cout<<"添加成功"<<endl;
	}else{
		cout<<"该课程已存在"<<endl;
	}
	pauseScreen();
	
}
//删除课程
void Manager::deleteCourse(){
	string num;
	cout<<"请输入删除课程的编号"<<endl;
	cin>>num;
	map<string,Course>::iterator it=course.find(num);
	if(it==course.end()){
		cout<<"该课程不存在"<<endl;
	}else{
		course.erase(it);
		cout<<"删除成功！"<<endl;
	}
	pauseScreen();
}
//查看学生
void Manager::viewStudent(){
	
	if(student.size()==0){
		cout<<"目前没有学生！"<<endl;
	}else{
		cout<<"┌─────┬─────┬─────┐"<<endl;
		cout<<"│   学号   │   姓名   │   班级   │"<<endl;
	
		for(map<string,Student>::iterator it=student.begin();it!=student.end();++it){
			cout<<"├─────┼─────┼─────┤"<<endl;
			cout<<"│"<<setiosflags(ios_base::left)<<setw(10)<<(it->second).getNum()<<"│"<<setiosflags(ios_base::left)<<setw(10)<<(it->second).getName()<<"│"<<setiosflags(ios_base::left)<<setw(10)<<(it->second).getHisClass()<<"│"<<endl;
		}
		cout<<"└─────┴─────┴─────┘"<<endl;
	}
	pauseScreen();
}
//查看课程
void Manager::viewCourse(){
	if(course.size()==0){
		cout<<"目前没有课程！"<<endl;
	}else{
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
//写入文件
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
//写入文件
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
//写入文件
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