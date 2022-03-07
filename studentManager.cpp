#include "studentManager.h"

//构造函数
StudentManager::StudentManager()
{
	ifstream ifs;
	ifs.open("data1.txt", ios::in);
	//1、文件不存在
	if (!ifs.is_open())
	{
		this->stuArray = NULL;
		this->stuNum = 0;
		this->isFileEmpty = true;
		//cout << "文件不存在或记录为空" << endl;
	}
	//2、文件存在但无记录
	char ch;
	ifs >> ch;
	if (ifs.eof())//从文件流中读取到文件末尾
	{
		this->stuArray = NULL;
		this->stuNum = 0;
		this->isFileEmpty = true;
		//cout << "文件不存在或记录为空" << endl;

	}
	//3、文件存在且有记录
	//记录文件中的信息条数
	this->stuNum = this->getStrNum();
	//cout << "职工人数为：" << this->stuNum << endl;
	
	//开辟与项目条数相同的空间
	this->stuArray = new Student * [this->stuNum];
	//将文件中的数据保存到stuArray数组中
	this->init_Student();

	


}

//显示菜单
void StudentManager::showMenu()
{
	cout << "************************************************************" << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "             欢迎使用2020学生返校健康管理系统！             " << endl;
	cout << "                       0.退出管理程序                       " << endl;
	cout << "                       1.添加学生信息                       " << endl;
	cout << "                       2.修改学生信息                       " << endl;
	cout << "                     3.显示所有学生信息                     " << endl;
	cout << "                     4.查询学生健康状况                     " << endl;
	cout << "            5.查询异常状况学生信息及健康状况预警            " << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "************************************************************" << endl;

	cout << endl;
}

//退出程序
void StudentManager::exit_System()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}

//1.0学生学号有效性检查
bool StudentManager::isRightId(string id)
{
	if (id.size() == 9)
	{
		int year = stoi(id.substr(0, 4));
		int code = stoi(id.substr(4, 2));
		int number = stoi(id.substr(6, 3));
		if (year >= 2016 && year <= 2019 && code >= 0 && code <= 12)
		{
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

//添加学生信息
void StudentManager::addStudent()
{
	
	//计算添加新空间大小
	int newSize = this->stuNum + 1;
	//开辟新的内存空间
	Student** newSpace = new  Student * [newSize];
	
	//判断原来文件中是否有数据
	//将原来的内容拷贝到新的空间中
	if (this->stuArray != NULL)
	{
		for (int i = 0; i < stuNum; i++)
		{
			newSpace[i] = this->stuArray[i];
		}
	}

	//添加数据
	string name;//姓名
	string id;//学号
	double temp;//体温
	int cough;//是否咳嗽
	string time;//记录时间
	string date;//日期

	cout << "请输入学生各项信息：";
	cin.get();
	cin.get();
	do
	{
		cout << "学生学号：";
		cin >> id; //TODO:须验证正确性
		if (isRightId(id))
		{
			break;
		}
		cout << "该学号信息无效，请重新输入！" << endl;
	} while (1);
	cout << "学生姓名：";
	cin >> name;
	cout << "学生体温：";
	cin >> temp;
	cout << "是否咳嗽：";
	cin >> cough;
	cout << "时间：";
	cin >> time;
	cout << "日期：";
	cin >> date;

	Student* student = NULL;
	student = new Student(id, name, temp, cough, time, date);
	//打印该同学信息
	cout << "学号\t\t姓名\t学院\t\t体温\t是否咳嗽\t健康状态\t时间\t日期" << endl;
	student->showInfo();
	//将创建的职工指针，保存到数组中
	newSpace[newSize - 1] = student;
	//释放原来的空间
	delete[] this->stuArray;
	//更新新空间的指向
	this->stuArray = newSpace;
	//更新人数
	this->stuNum = newSize;

	//更新文件标志
	this->isFileEmpty= false;

	//提示添加成功
	cout << "成功添加到系统中" << endl;
	//保存到文件中
	this->saveStudentInfo();
	

}

//保存学生信息到文件中
void StudentManager::saveStudentInfo()
{
	ofstream ofs;
	ofs.open("data1.txt", ios::out); //用输出的方式打开文件 -- 写文件

	//将每个人的数据写入到文件中
	for (int i = 0; i < this->stuNum; i++)
	{
		ofs << this->stuArray[i]->m_Id << " "
			<< this->stuArray[i]->m_Name << " "
			<< this->stuArray[i]->m_InstituteName << " "
			<< this->stuArray[i]->m_Temperature << " "
			<< this->stuArray[i]->m_isCough << " "
			<< this->stuArray[i]->m_health << " "
			<< this->stuArray[i]->m_Time << " "
			<< this->stuArray[i]->m_Date << endl;
	}
	ofs.close();

}

//统计文件中信息条数
int StudentManager::getStrNum()
{
	ifstream ifs;
	ifs.open("data1.txt", ios::in);

	string name;//姓名
	string id;//学号
	double temp;//体温
	string institute; //学院
	int cough;//是否咳嗽
	int health; //健康状况
	string time;//记录时间
	string date;//日期

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >>institute
		&& ifs >> temp && ifs >> cough && ifs >> health
		&& ifs >> time && ifs >> date)
	{
		num++;
	}
	return num;

}

//初始化学生信息数组
void StudentManager::init_Student()
{
	ifstream ifs;
	ifs.open("data1.txt", ios::in);

	string name;//姓名
	string id;//学号
	double temp;//体温
	string institute; //学院
	int cough;//是否咳嗽
	int health; //健康状况
	string time;//记录时间
	string date;//日期

	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> institute
		&& ifs >> temp && ifs >> cough && ifs >> health
		&& ifs >> time && ifs >> date)
	{
		Student* stu = NULL;
		stu = new Student(id, name, temp, cough, time, date);
		//将数据存放到数组中
		this->stuArray[index] = stu;

		index++;
	}
}

//通过id判断学生是否存在 如果存在返回所在数组下标，不存在返回-1
int StudentManager::isExist(string id)
{
	int index = -1;
	for (int i = 0; i < this->stuNum; i++)
	{
		if (this->stuArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

//修改学生信息
void StudentManager::modify_Student()
{
	if (this->isFileEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		string name;//姓名
		string id;//学号
		double temp;//体温
		int cough;//是否咳嗽
		string time;//记录时间
		string date;//日期

		cout << "请输入要修改信息的学生学号：";
		cin >> id;
		int res = this->isExist(id);
		if (res != -1)
		{
			//找到该名学生
			cout << "找到学号 " << this->stuArray[res]->m_Id << " 的学生 " << this->stuArray[res]->m_Name << endl;
			name = this->stuArray[res]->m_Name;
			cout << "请输入体温：";
			cin >> temp;
			cout << "是否咳嗽：";
			cin >> cough;
			cout << "记录时间：";
			cin >> time;
			cout << "更新日期：";
			cin >> date;
			//删除该条信息原数据
			delete this->stuArray[res];

			Student* stu = NULL;
			stu = new Student(id, name, temp, cough, time, date);
			//更新数据 到数组中
			this->stuArray[res] = stu;

			cout << "修改成功！" << endl;
			//保存数据到文件中
			this->saveStudentInfo();
		}
		else
		{
			cout << "未找到该名学生，请确认有无记录或学号是否正确。" << endl;
		}
	}
}

//显示所有学生信息
void StudentManager::show_Student()
{
	
	if (this->isFileEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "所有记录如下：" << endl;
		cout << "学号\t\t姓名\t学院\t\t体温\t是否咳嗽\t健康状态\t时间\t日期" << endl;
		for (int i = 0 ; i < this->stuNum; i++)
		{
			//打印每条记录信息
			this->stuArray[i]->showInfo();
		}
	}
	
}

//4.查询学生健康状况
void StudentManager::search_Student()
{
	if (isFileEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请选择查询方式：" << endl;
		cout << "1、按学号查找" << endl;
		cout << "2、按姓名查找" << endl;
		int select;
		cin >> select;
		if (select == 1)
		{
			//按学号查找
			string id;
			string nowTime;
			do
			{
				cout << "学生学号：";
				cin >> id;
				if (isRightId(id))
				{
					break;
				}
				cout << "该学号信息无效，请重新输入！" << endl;
			} while (1);
			//判断id是否存在
			int res = this->isExist(id);
			if (res != -1)
			{
				//打开文件输出流
				ofstream ofs("data2.txt", ios::trunc);

				cout << "请输入当前日期：";
				cin >> nowTime;
				cout << "截至 " << nowTime.substr(0, 4) << " 年 " << stoi(nowTime.substr(4, 2)) << " 月 "
					<< stoi(nowTime.substr(6, 2)) << " 日该生的健康管理信息为：" << endl;
				ofs << "截至 " << nowTime.substr(0, 4) << " 年 " << stoi(nowTime.substr(4, 2)) << " 月 "
					<< stoi(nowTime.substr(6, 2)) << " 日该生的健康管理信息为：" << endl;
				cout << "学号：" << this->stuArray[res]->m_Id << endl;
				ofs << "学号：" << this->stuArray[res]->m_Id << endl;
				cout << "姓名：" << this->stuArray[res]->m_Name << endl;
				ofs << "姓名：" << this->stuArray[res]->m_Name << endl;
				cout << "学院：" << this->stuArray[res]->m_InstituteName << endl;
				ofs << "学院：" << this->stuArray[res]->m_InstituteName << endl;
				cout << "体温\t是否咳嗽\t健康状态\t时间\t日期" << endl;
				ofs << "体温\t是否咳嗽\t健康状态\t时间\t日期" << endl;
				bool flag = false; //标记是否存在符合条件的数据
				for (int i = 0; i < this->stuNum; i++)
				{
					if (this->stuArray[i]->m_Id == id)
					{
						if (compareDate(nowTime, this->stuArray[i]->m_Date))
						{
							//此时记录在当前日期之前并且学号正确
							cout << this->stuArray[i]->m_Temperature << "\t" << this->stuArray[i]->m_isCough
								<< "\t\t" << this->stuArray[i]->m_health << "\t\t" << this->stuArray[i]->m_Time
								<< "\t" << this->stuArray[i]->m_Date << endl;
							ofs << this->stuArray[i]->m_Temperature << "\t" << this->stuArray[i]->m_isCough
								<< "\t" << this->stuArray[i]->m_health << "\t" << this->stuArray[i]->m_Time
								<< "\t" << this->stuArray[i]->m_Date << endl;
							flag = true;
						}
					}
				}
				if (flag == false)
				{
					cout << "没有符合条件的结果" << endl;
					ofs << "没有符合条件的结果" << endl;
				}
				ofs.close();
			}
			else
			{
				cout << "未找到该学号学生，请重试" << endl;
			}
		}
		else
		{
			string name;
			//按姓名查找
			cout << "请输入学生姓名：";
			cin >> name;
			bool flag1 = false;
			int* index = new int[this->stuNum];
			int num = 0;
			for (int i = 0; i < this->stuNum; i++)
			{
				if (this->stuArray[i]->m_Name == name)
				{
					//找到有此人数据
					flag1 = true;
					//将下标保存在index数组中
					index[num++] = i;
				}
			}
			if (flag1 == true)
			{
				//有学生记录
				//打开文件输出流
				ofstream ofs("data2.txt", ios::trunc);
				string nowTime;
				cout << "请输入当前日期：";
				cin >> nowTime;
				cout << "截至 " << nowTime.substr(0, 4) << " 年 " << stoi(nowTime.substr(4, 2)) << " 月 "
					<< stoi(nowTime.substr(6, 2)) << " 日该生的健康管理信息为：" << endl;
				ofs << "截至 " << nowTime.substr(0, 4) << " 年 " << stoi(nowTime.substr(4, 2)) << " 月 "
					<< stoi(nowTime.substr(6, 2)) << " 日该生的健康管理信息为：" << endl;
				cout << "学号：" << this->stuArray[index[0]]->m_Id << endl;
				ofs << "学号：" << this->stuArray[index[0]]->m_Id << endl;
				cout << "姓名：" << this->stuArray[index[0]]->m_Name << endl;
				ofs << "姓名：" << this->stuArray[index[0]]->m_Name << endl;
				cout << "学院：" << this->stuArray[index[0]]->m_InstituteName << endl;
				ofs << "学院：" << this->stuArray[index[0]]->m_InstituteName << endl;
				cout << "体温\t是否咳嗽\t健康状态\t时间\t日期" << endl;
				ofs << "体温\t是否咳嗽\t健康状态\t时间\t日期" << endl;
				bool flag2 = false;
				for (int i = 0; i < num; i++)
				{
					if (compareDate(nowTime, this->stuArray[index[i]]->m_Date))
					{
						//此时记录在当前日期之前并且学号正确
						cout << this->stuArray[index[i]]->m_Temperature << "\t" << this->stuArray[index[i]]->m_isCough
							<< "\t\t" << this->stuArray[index[i]]->m_health << "\t\t" << this->stuArray[index[i]]->m_Time
							<< "\t" << this->stuArray[index[i]]->m_Date << endl;
						ofs << this->stuArray[index[i]]->m_Temperature << "\t" << this->stuArray[index[i]]->m_isCough
							<< "\t" << this->stuArray[index[i]]->m_health << "\t" << this->stuArray[index[i]]->m_Time
							<< "\t" << this->stuArray[index[i]]->m_Date << endl;
						flag2 = true;
					}
				}
				if (flag2 == false)
				{
					cout << "没有符合条件的结果" << endl;
					ofs << "没有符合条件的结果" << endl;
				}
				ofs.close();
			}
			else
			{
				cout << "未找到该名学生，请重试" << endl;
			}
		}
	}
}

//比较保存日期与当前日期的前后，如果在包含当前日期之前，返回True，否则返回False
bool StudentManager::compareDate(string nowDate, string date)
{
	int intNowDate = stoi(nowDate); //将当前日期转化为int型
	int intDate = stoi(date); //将保存日期转化为int型

	return intDate <= intNowDate;


}

//5.1异常查询异常状况学生信息
void StudentManager::dangerous_Student()
{
	if (isFileEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		bool flag = false;
		//遍历信息数组查找异常状况学生
		for (int i = 0; i < this->stuNum; i++)
		{
			if (this->stuArray[i]->m_health == 0)
			{
				flag = true;
				break;
			}
		}
		if (flag == true)
		{
			//存在状况异常的学生
			ofstream ofs("data3.txt", ios::trunc);
			cout << "健康状况异常的学生如下：" << endl;
			ofs << "健康状况异常的学生如下：" << endl;
			cout << "学号\t\t姓名\t学院\t\t体温\t是否咳嗽\t健康状态\t时间\t日期" << endl;
			ofs << "学号\t\t姓名\t学院\t体温\t是否咳嗽\t健康状态\t时间\t日期" << endl;
			for (int i = 0; i < this->stuNum; i++)
			{
				if (this->stuArray[i]->m_health == 0)
				{
					this->stuArray[i]->showInfo();
					ofs << this->stuArray[i]->m_Id << "\t" << this->stuArray[i]->m_Name << "\t" << this->stuArray[i]->m_InstituteName
						<< "\t" << this->stuArray[i]->m_Temperature << "\t" << this->stuArray[i]->m_isCough << "\t" << this->stuArray[i]->m_health
						<< "\t" << this->stuArray[i]->m_Time << "\t" << this->stuArray[i]->m_Date << endl;
				}
			}
			ofs.close();
		}
		else
		{
			cout << "没有查找到健康状况异常的学生" << endl;
		}



	}


}

//5.2健康状况预警  未完成
void StudentManager::health_Alert()
{
	//Todo:
}