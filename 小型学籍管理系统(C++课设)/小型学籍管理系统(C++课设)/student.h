#define  _CRT_SECURE_NO_WARNINGS  
#include<string>
#include<vector>
#pragma once 
using namespace std;
class Student
{
public:
	Student(string id, string name, string sex, string homeid, string callid)
	{
		M_id = id;
		M_name = name;
		M_sex = sex;
		M_homeId = homeid;
		M_callId = callid;
	}
	string M_id;//ѧ��ѧ��
	string M_name;//ѧ������
	string M_sex;//ѧ���Ա�
	string M_homeId;//ѧ���������
	string M_callId;//ѧ���绰����
};