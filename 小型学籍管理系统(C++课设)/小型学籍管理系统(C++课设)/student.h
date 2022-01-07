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
	string M_id;//学生学号
	string M_name;//学生姓名
	string M_sex;//学生性别
	string M_homeId;//学生宿舍号码
	string M_callId;//学生电话号码
};