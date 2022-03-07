#include "student.h"

//学生构造函数
Student::Student(string id, string name, double temp, int cough,string time, string date)
{
	this->m_Id = id;
	this->m_Name = name;
	//通过学号获取学院代码
	this->m_Institute = this->getInstituteCode();
	this->m_Temperature = temp;
	this->m_isCough = cough;
	//通过咳嗽和体温判断健康状态
	this->isHealth();
	this->m_Time = time;
	this->m_Date = date;
	//将获取到的学院代码转化为学院名称
	this->m_InstituteName = this->getInstituteName();
}

//显示学生信息
void Student::showInfo()
{
	cout << this->m_Id << "\t" << this->m_Name << "\t" << this->m_InstituteName
		<< "\t" << this->m_Temperature << "\t" << this->m_isCough << "\t\t" << this->m_health
		<< "\t\t" << this->m_Time << "\t" << this->m_Date << endl;
}

//判断健康状态函数
void Student::isHealth()
{
	if (this->m_isCough == 1 || this->m_Temperature >= 37.3)
	{
		this->m_health = 0;
	}
	else
	{
		this->m_health = 1;
	}
}

//从学号中获取学院代码
int Student::getInstituteCode()
{
	//将学号的第5,6位分出
	string code = this->m_Id.substr(4, 2);
	//转化为int型返回
	return stoi(code);
}

//学院代码转化为学院名称
string Student::getInstituteName()
{
	switch (this->m_Institute)
	{
	case 1:
		return "通信学院";
	case 2:
		return "计算机学院";
	case 3:
		return "光电学院";
		break;
	case 4:
		return "自动化学院";
		break;
	case 5:
		return "经管学院";
		break;
	case 6:
		return "研究生院";
		break;
	case 7:
		return "外语学院";
		break;
	case 8:
		return "安法学院";
		break;
	case 9:
		return "体育学院";
		break;
	case 10:
		return "传媒学院";
		break;
	case 11:
		return "先进制造学院";
		break;
	case 12:
		return "马克思主义学院";
		break;
	default:
		break;
	}
}