#include <iostream>
using namespace std;
#include <string>

#include "studentManager.h"

int main()
{
	//���Դ���
	//StudentManager sm;
	//sm.addStudent();

	////����ѧ������ʵ��������
	StudentManager sm;

	while (true)
	{
		sm.showMenu();

		cout << "��ѡ����ţ�" << endl;
		int select = 0;
		cin >> select;
		switch (select)
		{
		case 0:
			//�˳�ϵͳ
			sm.exit_System();
			break;
		case 1:
			//���ѧ����Ϣ
			sm.addStudent();
			break;
		case 2:
			//�޸�ѧ����Ϣ
			sm.modify_Student();
			break;
		case 3:
			//��ʾ����ѧ����Ϣ
			sm.show_Student();
			break;
		case 4:
			//��ѯѧ������״��
			sm.search_Student();
			break;
		case 5:
			//��ѯ�쳣״��ѧ����Ϣ������״��Ԥ��
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