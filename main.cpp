#include <iostream>
using namespace std;
#include <string>

#include "studentManager.h"

int main()
{
	//测试代码
	//StudentManager sm;
	//sm.addStudent();

	////创建学生管理实例化对象
	StudentManager sm;

	while (true)
	{
		sm.showMenu();

		cout << "请选择序号：" << endl;
		int select = 0;
		cin >> select;
		switch (select)
		{
		case 0:
			//退出系统
			sm.exit_System();
			break;
		case 1:
			//添加学生信息
			sm.addStudent();
			break;
		case 2:
			//修改学生信息
			sm.modify_Student();
			break;
		case 3:
			//显示所有学生信息
			sm.show_Student();
			break;
		case 4:
			//查询学生健康状况
			sm.search_Student();
			break;
		case 5:
			//查询异常状况学生信息及健康状况预警
			sm.dangerous_Student();
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
	

	system("pause");
	return 0;
}