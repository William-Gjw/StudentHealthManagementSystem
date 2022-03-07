#pragma once
#include <iostream>
using namespace std;

#include "student.h"
#include <fstream>

class StudentManager
{

public:
	//���캯��
	StudentManager();
	//��ʾ�˵�
	void showMenu();
	//0.�˳�����
	void exit_System();
	//1.0ѧ��ѧ����Ч�Լ��
	bool isRightId(string id);
	//1.���ѧ����Ϣ
	void addStudent();
	//1.1����ѧ����Ϣ���ļ���
	void saveStudentInfo();
	//1.2����ͳ���ļ�����Ϣ����
	int getStrNum();
	//1.3��ʼ��ѧ����Ϣ����
	void init_Student();
	//2.�޸�ѧ����Ϣ
	void modify_Student();
	//2.1ͨ��id�ж�ѧ���Ƿ���� ������ڷ������������±꣬�����ڷ���-1
	int isExist(string id);
	//3.��ʾ����ѧ����Ϣ
	void show_Student();
	//4.��ѯѧ������״��
	void search_Student();
	//�Ƚϱ��������뵱ǰ���ڵ�ǰ������ڰ�����ǰ����֮ǰ������True�����򷵻�False
	bool compareDate(string nowDate, string date);
	//5.1�쳣��ѯ�쳣״��ѧ����Ϣ
	void dangerous_Student();
	//5.2����״��Ԥ��
	void health_Alert();


	//��������
	//~StudentManager();

	//��¼ѧ����Ϣ����
	int stuNum;
	//ѧ������ָ��
	Student** stuArray;
	//�ж��ļ��Ƿ�Ϊ�� ��־
	bool isFileEmpty;
};