#pragma once
#include <iostream>
using namespace std;

#include "student.h"
#include <fstream>

class StudentManager
{

public:
	//构造函数
	StudentManager();
	//显示菜单
	void showMenu();
	//0.退出程序
	void exit_System();
	//1.0学生学号有效性检查
	bool isRightId(string id);
	//1.添加学生信息
	void addStudent();
	//1.1保存学生信息到文件中
	void saveStudentInfo();
	//1.2返回统计文件中信息条数
	int getStrNum();
	//1.3初始化学生信息数组
	void init_Student();
	//2.修改学生信息
	void modify_Student();
	//2.1通过id判断学生是否存在 如果存在返回所在数组下标，不存在返回-1
	int isExist(string id);
	//3.显示所有学生信息
	void show_Student();
	//4.查询学生健康状况
	void search_Student();
	//比较保存日期与当前日期的前后，如果在包含当前日期之前，返回True，否则返回False
	bool compareDate(string nowDate, string date);
	//5.1异常查询异常状况学生信息
	void dangerous_Student();
	//5.2健康状况预警
	void health_Alert();


	//析构函数
	//~StudentManager();

	//记录学生信息条数
	int stuNum;
	//学生数组指针
	Student** stuArray;
	//判断文件是否为空 标志
	bool isFileEmpty;
};