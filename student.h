#pragma once
#include <iostream>
#include <string>
using namespace std;


//ѧ����
class Student
{
public:
	//��д�๹�캯��
	Student(string id, string name, double temp, int cough, string time, string date);
	//��ʾѧ����Ϣ
	void showInfo();
	//�жϽ���״̬����
	void isHealth();
	//��ѧ���л�ȡѧԺid
	int getInstituteCode();
	//����ת��ΪѧԺ����
	string getInstituteName();
	


	string m_Id; //ѧ��
	string m_Name; //����
	int m_Institute; //ѧԺ��
	double m_Temperature; //����
	int m_isCough; //�Ƿ����(0/1)
	int m_health; //����״̬
	string m_Time; //ͳ��ʱ��
	string m_Date; //ͳ������
	string m_InstituteName; //��¼ѧԺ����
};

