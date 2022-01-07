#define  _CRT_SECURE_NO_WARNINGS  
#pragma once 
using namespace std;
#include<map>
#include"student.h"
#include"score.h"
class System
{
public:
	//构造函数
	System();

	//展示菜单函数
	void show_Menu();

	//退出系统函数
	void ExitSystem();

	//成绩数据录入函数
	void SetScore();

	//查询函数
	void Find();

	//删除函数
	void Delete();

	//排序函数
	void SortScore();


	//保存学生成绩的函数
	void SaveScore();
	//加载学生成绩 
	void LoadScore();

	//保存学生信息的函数
	void SaveMes();

	//加载学生信息的函数
	void LoadMes();

	//析构函数
	~System();

	vector<Student>st;//用来维护每个学生信息的数组
	map<string, vector<Score>>mp;//key对应的学号，每个学号对应一个vector,vector里的每一个元素存每门成绩
};