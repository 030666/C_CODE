#define  _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<iostream>
#include"student.h"
#include"system.h"

using namespace std;

int main()
{

	//实例化管理系统对象
	System sm;

	int choice = 0;//用来记录用户的选择
	while (true)
	{
		//调用展示菜单函数
		sm.show_Menu();

		cout << "请输入您的选择：" << endl;
		cin >> choice;//接受用户的选项
		switch (choice)
		{
		case 0://退出系统
		{
			sm.ExitSystem();
			//退出系统先保存一下数据
			sm.SaveMes();
			break;
		}
		case 1://数据录入
		{
			sm.SetScore();
			sm.SaveScore();
			break;
		}
		case 2://查询功能
			sm.Find();
			break;
		case 3://删除功能
		{	
		sm.Delete();
		sm.SaveScore();
		break;
		}
		case 4://排序功能
			sm.SortScore();
			break;
		default:
			system("cls");//清屏
		}
	
	}
	system("pause");
	return 0;
}
