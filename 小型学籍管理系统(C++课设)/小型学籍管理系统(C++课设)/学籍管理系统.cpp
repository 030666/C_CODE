#define  _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<iostream>
#include"student.h"
#include"system.h"

using namespace std;

int main()
{

	//ʵ��������ϵͳ����
	System sm;

	int choice = 0;//������¼�û���ѡ��
	while (true)
	{
		//����չʾ�˵�����
		sm.show_Menu();

		cout << "����������ѡ��" << endl;
		cin >> choice;//�����û���ѡ��
		switch (choice)
		{
		case 0://�˳�ϵͳ
		{
			sm.ExitSystem();
			//�˳�ϵͳ�ȱ���һ������
			sm.SaveMes();
			break;
		}
		case 1://����¼��
		{
			sm.SetScore();
			sm.SaveScore();
			break;
		}
		case 2://��ѯ����
			sm.Find();
			break;
		case 3://ɾ������
		{	
		sm.Delete();
		sm.SaveScore();
		break;
		}
		case 4://������
			sm.SortScore();
			break;
		default:
			system("cls");//����
		}
	
	}
	system("pause");
	return 0;
}
