#include "student.h"

//ѧ�����캯��
Student::Student(string id, string name, double temp, int cough,string time, string date)
{
	this->m_Id = id;
	this->m_Name = name;
	//ͨ��ѧ�Ż�ȡѧԺ����
	this->m_Institute = this->getInstituteCode();
	this->m_Temperature = temp;
	this->m_isCough = cough;
	//ͨ�����Ժ������жϽ���״̬
	this->isHealth();
	this->m_Time = time;
	this->m_Date = date;
	//����ȡ����ѧԺ����ת��ΪѧԺ����
	this->m_InstituteName = this->getInstituteName();
}

//��ʾѧ����Ϣ
void Student::showInfo()
{
	cout << this->m_Id << "\t" << this->m_Name << "\t" << this->m_InstituteName
		<< "\t" << this->m_Temperature << "\t" << this->m_isCough << "\t\t" << this->m_health
		<< "\t\t" << this->m_Time << "\t" << this->m_Date << endl;
}

//�жϽ���״̬����
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

//��ѧ���л�ȡѧԺ����
int Student::getInstituteCode()
{
	//��ѧ�ŵĵ�5,6λ�ֳ�
	string code = this->m_Id.substr(4, 2);
	//ת��Ϊint�ͷ���
	return stoi(code);
}

//ѧԺ����ת��ΪѧԺ����
string Student::getInstituteName()
{
	switch (this->m_Institute)
	{
	case 1:
		return "ͨ��ѧԺ";
	case 2:
		return "�����ѧԺ";
	case 3:
		return "���ѧԺ";
		break;
	case 4:
		return "�Զ���ѧԺ";
		break;
	case 5:
		return "����ѧԺ";
		break;
	case 6:
		return "�о���Ժ";
		break;
	case 7:
		return "����ѧԺ";
		break;
	case 8:
		return "����ѧԺ";
		break;
	case 9:
		return "����ѧԺ";
		break;
	case 10:
		return "��ýѧԺ";
		break;
	case 11:
		return "�Ƚ�����ѧԺ";
		break;
	case 12:
		return "���˼����ѧԺ";
		break;
	default:
		break;
	}
}