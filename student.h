#pragma once
#include <iostream>
#include <string>
using namespace std;


//学生类
class Student
{
public:
	//重写类构造函数
	Student(string id, string name, double temp, int cough, string time, string date);
	//显示学生信息
	void showInfo();
	//判断健康状态函数
	void isHealth();
	//从学号中获取学院id
	int getInstituteCode();
	//代码转化为学院名称
	string getInstituteName();
	


	string m_Id; //学号
	string m_Name; //姓名
	int m_Institute; //学院类
	double m_Temperature; //体温
	int m_isCough; //是否咳嗽(0/1)
	int m_health; //健康状态
	string m_Time; //统计时间
	string m_Date; //统计日期
	string m_InstituteName; //记录学院名称
};

