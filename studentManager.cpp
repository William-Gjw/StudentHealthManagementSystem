#include "studentManager.h"

//���캯��
StudentManager::StudentManager()
{
	ifstream ifs;
	ifs.open("data1.txt", ios::in);
	//1���ļ�������
	if (!ifs.is_open())
	{
		this->stuArray = NULL;
		this->stuNum = 0;
		this->isFileEmpty = true;
		//cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	//2���ļ����ڵ��޼�¼
	char ch;
	ifs >> ch;
	if (ifs.eof())//���ļ����ж�ȡ���ļ�ĩβ
	{
		this->stuArray = NULL;
		this->stuNum = 0;
		this->isFileEmpty = true;
		//cout << "�ļ������ڻ��¼Ϊ��" << endl;

	}
	//3���ļ��������м�¼
	//��¼�ļ��е���Ϣ����
	this->stuNum = this->getStrNum();
	//cout << "ְ������Ϊ��" << this->stuNum << endl;
	
	//��������Ŀ������ͬ�Ŀռ�
	this->stuArray = new Student * [this->stuNum];
	//���ļ��е����ݱ��浽stuArray������
	this->init_Student();

	


}

//��ʾ�˵�
void StudentManager::showMenu()
{
	cout << "************************************************************" << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "             ��ӭʹ��2020ѧ����У��������ϵͳ��             " << endl;
	cout << "                       0.�˳��������                       " << endl;
	cout << "                       1.���ѧ����Ϣ                       " << endl;
	cout << "                       2.�޸�ѧ����Ϣ                       " << endl;
	cout << "                     3.��ʾ����ѧ����Ϣ                     " << endl;
	cout << "                     4.��ѯѧ������״��                     " << endl;
	cout << "            5.��ѯ�쳣״��ѧ����Ϣ������״��Ԥ��            " << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "************************************************************" << endl;

	cout << endl;
}

//�˳�����
void StudentManager::exit_System()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

//1.0ѧ��ѧ����Ч�Լ��
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

//���ѧ����Ϣ
void StudentManager::addStudent()
{
	
	//��������¿ռ��С
	int newSize = this->stuNum + 1;
	//�����µ��ڴ�ռ�
	Student** newSpace = new  Student * [newSize];
	
	//�ж�ԭ���ļ����Ƿ�������
	//��ԭ�������ݿ������µĿռ���
	if (this->stuArray != NULL)
	{
		for (int i = 0; i < stuNum; i++)
		{
			newSpace[i] = this->stuArray[i];
		}
	}

	//�������
	string name;//����
	string id;//ѧ��
	double temp;//����
	int cough;//�Ƿ����
	string time;//��¼ʱ��
	string date;//����

	cout << "������ѧ��������Ϣ��";
	cin.get();
	cin.get();
	do
	{
		cout << "ѧ��ѧ�ţ�";
		cin >> id; //TODO:����֤��ȷ��
		if (isRightId(id))
		{
			break;
		}
		cout << "��ѧ����Ϣ��Ч�����������룡" << endl;
	} while (1);
	cout << "ѧ��������";
	cin >> name;
	cout << "ѧ�����£�";
	cin >> temp;
	cout << "�Ƿ���ԣ�";
	cin >> cough;
	cout << "ʱ�䣺";
	cin >> time;
	cout << "���ڣ�";
	cin >> date;

	Student* student = NULL;
	student = new Student(id, name, temp, cough, time, date);
	//��ӡ��ͬѧ��Ϣ
	cout << "ѧ��\t\t����\tѧԺ\t\t����\t�Ƿ����\t����״̬\tʱ��\t����" << endl;
	student->showInfo();
	//��������ְ��ָ�룬���浽������
	newSpace[newSize - 1] = student;
	//�ͷ�ԭ���Ŀռ�
	delete[] this->stuArray;
	//�����¿ռ��ָ��
	this->stuArray = newSpace;
	//��������
	this->stuNum = newSize;

	//�����ļ���־
	this->isFileEmpty= false;

	//��ʾ��ӳɹ�
	cout << "�ɹ���ӵ�ϵͳ��" << endl;
	//���浽�ļ���
	this->saveStudentInfo();
	

}

//����ѧ����Ϣ���ļ���
void StudentManager::saveStudentInfo()
{
	ofstream ofs;
	ofs.open("data1.txt", ios::out); //������ķ�ʽ���ļ� -- д�ļ�

	//��ÿ���˵�����д�뵽�ļ���
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

//ͳ���ļ�����Ϣ����
int StudentManager::getStrNum()
{
	ifstream ifs;
	ifs.open("data1.txt", ios::in);

	string name;//����
	string id;//ѧ��
	double temp;//����
	string institute; //ѧԺ
	int cough;//�Ƿ����
	int health; //����״��
	string time;//��¼ʱ��
	string date;//����

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >>institute
		&& ifs >> temp && ifs >> cough && ifs >> health
		&& ifs >> time && ifs >> date)
	{
		num++;
	}
	return num;

}

//��ʼ��ѧ����Ϣ����
void StudentManager::init_Student()
{
	ifstream ifs;
	ifs.open("data1.txt", ios::in);

	string name;//����
	string id;//ѧ��
	double temp;//����
	string institute; //ѧԺ
	int cough;//�Ƿ����
	int health; //����״��
	string time;//��¼ʱ��
	string date;//����

	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> institute
		&& ifs >> temp && ifs >> cough && ifs >> health
		&& ifs >> time && ifs >> date)
	{
		Student* stu = NULL;
		stu = new Student(id, name, temp, cough, time, date);
		//�����ݴ�ŵ�������
		this->stuArray[index] = stu;

		index++;
	}
}

//ͨ��id�ж�ѧ���Ƿ���� ������ڷ������������±꣬�����ڷ���-1
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

//�޸�ѧ����Ϣ
void StudentManager::modify_Student()
{
	if (this->isFileEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		string name;//����
		string id;//ѧ��
		double temp;//����
		int cough;//�Ƿ����
		string time;//��¼ʱ��
		string date;//����

		cout << "������Ҫ�޸���Ϣ��ѧ��ѧ�ţ�";
		cin >> id;
		int res = this->isExist(id);
		if (res != -1)
		{
			//�ҵ�����ѧ��
			cout << "�ҵ�ѧ�� " << this->stuArray[res]->m_Id << " ��ѧ�� " << this->stuArray[res]->m_Name << endl;
			name = this->stuArray[res]->m_Name;
			cout << "���������£�";
			cin >> temp;
			cout << "�Ƿ���ԣ�";
			cin >> cough;
			cout << "��¼ʱ�䣺";
			cin >> time;
			cout << "�������ڣ�";
			cin >> date;
			//ɾ��������Ϣԭ����
			delete this->stuArray[res];

			Student* stu = NULL;
			stu = new Student(id, name, temp, cough, time, date);
			//�������� ��������
			this->stuArray[res] = stu;

			cout << "�޸ĳɹ���" << endl;
			//�������ݵ��ļ���
			this->saveStudentInfo();
		}
		else
		{
			cout << "δ�ҵ�����ѧ������ȷ�����޼�¼��ѧ���Ƿ���ȷ��" << endl;
		}
	}
}

//��ʾ����ѧ����Ϣ
void StudentManager::show_Student()
{
	
	if (this->isFileEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "���м�¼���£�" << endl;
		cout << "ѧ��\t\t����\tѧԺ\t\t����\t�Ƿ����\t����״̬\tʱ��\t����" << endl;
		for (int i = 0 ; i < this->stuNum; i++)
		{
			//��ӡÿ����¼��Ϣ
			this->stuArray[i]->showInfo();
		}
	}
	
}

//4.��ѯѧ������״��
void StudentManager::search_Student()
{
	if (isFileEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��ѡ���ѯ��ʽ��" << endl;
		cout << "1����ѧ�Ų���" << endl;
		cout << "2������������" << endl;
		int select;
		cin >> select;
		if (select == 1)
		{
			//��ѧ�Ų���
			string id;
			string nowTime;
			do
			{
				cout << "ѧ��ѧ�ţ�";
				cin >> id;
				if (isRightId(id))
				{
					break;
				}
				cout << "��ѧ����Ϣ��Ч�����������룡" << endl;
			} while (1);
			//�ж�id�Ƿ����
			int res = this->isExist(id);
			if (res != -1)
			{
				//���ļ������
				ofstream ofs("data2.txt", ios::trunc);

				cout << "�����뵱ǰ���ڣ�";
				cin >> nowTime;
				cout << "���� " << nowTime.substr(0, 4) << " �� " << stoi(nowTime.substr(4, 2)) << " �� "
					<< stoi(nowTime.substr(6, 2)) << " �ո����Ľ���������ϢΪ��" << endl;
				ofs << "���� " << nowTime.substr(0, 4) << " �� " << stoi(nowTime.substr(4, 2)) << " �� "
					<< stoi(nowTime.substr(6, 2)) << " �ո����Ľ���������ϢΪ��" << endl;
				cout << "ѧ�ţ�" << this->stuArray[res]->m_Id << endl;
				ofs << "ѧ�ţ�" << this->stuArray[res]->m_Id << endl;
				cout << "������" << this->stuArray[res]->m_Name << endl;
				ofs << "������" << this->stuArray[res]->m_Name << endl;
				cout << "ѧԺ��" << this->stuArray[res]->m_InstituteName << endl;
				ofs << "ѧԺ��" << this->stuArray[res]->m_InstituteName << endl;
				cout << "����\t�Ƿ����\t����״̬\tʱ��\t����" << endl;
				ofs << "����\t�Ƿ����\t����״̬\tʱ��\t����" << endl;
				bool flag = false; //����Ƿ���ڷ�������������
				for (int i = 0; i < this->stuNum; i++)
				{
					if (this->stuArray[i]->m_Id == id)
					{
						if (compareDate(nowTime, this->stuArray[i]->m_Date))
						{
							//��ʱ��¼�ڵ�ǰ����֮ǰ����ѧ����ȷ
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
					cout << "û�з��������Ľ��" << endl;
					ofs << "û�з��������Ľ��" << endl;
				}
				ofs.close();
			}
			else
			{
				cout << "δ�ҵ���ѧ��ѧ����������" << endl;
			}
		}
		else
		{
			string name;
			//����������
			cout << "������ѧ��������";
			cin >> name;
			bool flag1 = false;
			int* index = new int[this->stuNum];
			int num = 0;
			for (int i = 0; i < this->stuNum; i++)
			{
				if (this->stuArray[i]->m_Name == name)
				{
					//�ҵ��д�������
					flag1 = true;
					//���±걣����index������
					index[num++] = i;
				}
			}
			if (flag1 == true)
			{
				//��ѧ����¼
				//���ļ������
				ofstream ofs("data2.txt", ios::trunc);
				string nowTime;
				cout << "�����뵱ǰ���ڣ�";
				cin >> nowTime;
				cout << "���� " << nowTime.substr(0, 4) << " �� " << stoi(nowTime.substr(4, 2)) << " �� "
					<< stoi(nowTime.substr(6, 2)) << " �ո����Ľ���������ϢΪ��" << endl;
				ofs << "���� " << nowTime.substr(0, 4) << " �� " << stoi(nowTime.substr(4, 2)) << " �� "
					<< stoi(nowTime.substr(6, 2)) << " �ո����Ľ���������ϢΪ��" << endl;
				cout << "ѧ�ţ�" << this->stuArray[index[0]]->m_Id << endl;
				ofs << "ѧ�ţ�" << this->stuArray[index[0]]->m_Id << endl;
				cout << "������" << this->stuArray[index[0]]->m_Name << endl;
				ofs << "������" << this->stuArray[index[0]]->m_Name << endl;
				cout << "ѧԺ��" << this->stuArray[index[0]]->m_InstituteName << endl;
				ofs << "ѧԺ��" << this->stuArray[index[0]]->m_InstituteName << endl;
				cout << "����\t�Ƿ����\t����״̬\tʱ��\t����" << endl;
				ofs << "����\t�Ƿ����\t����״̬\tʱ��\t����" << endl;
				bool flag2 = false;
				for (int i = 0; i < num; i++)
				{
					if (compareDate(nowTime, this->stuArray[index[i]]->m_Date))
					{
						//��ʱ��¼�ڵ�ǰ����֮ǰ����ѧ����ȷ
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
					cout << "û�з��������Ľ��" << endl;
					ofs << "û�з��������Ľ��" << endl;
				}
				ofs.close();
			}
			else
			{
				cout << "δ�ҵ�����ѧ����������" << endl;
			}
		}
	}
}

//�Ƚϱ��������뵱ǰ���ڵ�ǰ������ڰ�����ǰ����֮ǰ������True�����򷵻�False
bool StudentManager::compareDate(string nowDate, string date)
{
	int intNowDate = stoi(nowDate); //����ǰ����ת��Ϊint��
	int intDate = stoi(date); //����������ת��Ϊint��

	return intDate <= intNowDate;


}

//5.1�쳣��ѯ�쳣״��ѧ����Ϣ
void StudentManager::dangerous_Student()
{
	if (isFileEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		bool flag = false;
		//������Ϣ��������쳣״��ѧ��
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
			//����״���쳣��ѧ��
			ofstream ofs("data3.txt", ios::trunc);
			cout << "����״���쳣��ѧ�����£�" << endl;
			ofs << "����״���쳣��ѧ�����£�" << endl;
			cout << "ѧ��\t\t����\tѧԺ\t\t����\t�Ƿ����\t����״̬\tʱ��\t����" << endl;
			ofs << "ѧ��\t\t����\tѧԺ\t����\t�Ƿ����\t����״̬\tʱ��\t����" << endl;
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
			cout << "û�в��ҵ�����״���쳣��ѧ��" << endl;
		}



	}


}

//5.2����״��Ԥ��  δ���
void StudentManager::health_Alert()
{
	//Todo:
}