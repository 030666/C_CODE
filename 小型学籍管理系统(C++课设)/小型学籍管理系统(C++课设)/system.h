#define  _CRT_SECURE_NO_WARNINGS  
#pragma once 
using namespace std;
#include<map>
#include"student.h"
#include"score.h"
class System
{
public:
	//���캯��
	System();

	//չʾ�˵�����
	void show_Menu();

	//�˳�ϵͳ����
	void ExitSystem();

	//�ɼ�����¼�뺯��
	void SetScore();

	//��ѯ����
	void Find();

	//ɾ������
	void Delete();

	//������
	void SortScore();


	//����ѧ���ɼ��ĺ���
	void SaveScore();
	//����ѧ���ɼ� 
	void LoadScore();

	//����ѧ����Ϣ�ĺ���
	void SaveMes();

	//����ѧ����Ϣ�ĺ���
	void LoadMes();

	//��������
	~System();

	vector<Student>st;//����ά��ÿ��ѧ����Ϣ������
	map<string, vector<Score>>mp;//key��Ӧ��ѧ�ţ�ÿ��ѧ�Ŷ�Ӧһ��vector,vector���ÿһ��Ԫ�ش�ÿ�ųɼ�
};