#define  _CRT_SECURE_NO_WARNINGS  
#include"system.h"
#include<iostream>
#include<fstream>
#include<map>
#include<vector>
#include<algorithm>
#include <sstream>//将int转换为string
using namespace std;
//重载左移运算符使之能够输出学生信息
ostream& operator<<(ostream& out, Student& st1) { 
	out << "学号:" << st1.M_id << "  姓名：" << st1.M_name << "  性别：" << st1.M_sex
		<< "  学生宿舍号：" << st1.M_homeId << "  学生电话号码：" << st1.M_callId << endl;
	return out;
}

//重载左移运算符使之能够输出学生成绩
ostream& operator<<(ostream& out, Score & sc) {
	out << "课程编号：" << sc.M_LessonID << " 课程名称：" << sc.M_LessonName << " 综合成绩：" << sc.M_ZongGrades << " 实得学分：" << sc.M_ActCredit << endl;
	return out;
}

//构造函数
System::System()
{
	//从文件中加载学生信息
	System::LoadMes();
	//从文件中加载成绩信息
	System::LoadScore();
	
}
//展示菜单函数
void System::show_Menu()
{
	cout << "************************************" << endl;
	cout << "********欢迎使用学籍管理系统********" << endl;
	cout << "************0、退出系统*************" << endl;
	cout << "************1、数据录入*************" << endl;
	cout << "************2、查询功能*************" << endl;
	cout << "************3、删除功能*************" << endl;
	cout << "************4、排序功能*************"<< endl;
	cout << "************************************" << endl;
}

//退出系统函数
void System::ExitSystem()
{
	cout << "欢迎下次使用！" << endl;

	//保存学生信息到文件
	System::SaveMes();

	//保存成绩信息
	System::SaveScore();

	system("pause");
	exit(0);//退出程序
}

//成绩数据录入函数
void System::SetScore()
{
	cout << "请输入学号、课程编号、课程名称、学分、平时成绩、实验成绩和卷面成绩:" << endl;
	string id;//学号

	string ld;
	string ln;
	float sc, us, es, ss;
	cin >> id >> ld >> ln >> sc >> us >> es >> ss;

	Score msc(ld, ln, sc,us, es, ss);
	
	//找到学号对应的成绩数组，然后存进去
	map<string, vector<Score>>::iterator pos = mp.find(id);//找到对应学号的迭代器
	//如果没有找到,则新建一个
	if (pos == mp.end()) {
		vector<Score>ms;
		ms.push_back(msc);
		mp.insert(pair<string, vector<Score>>(id, ms));
	}
	else {//找到了
		pos->second.push_back(msc);//然后通过迭代器找到学号对应的成绩数组
	}
	cout << "成绩录入成功！" << endl;
	system("pause");
	system("cls");
	return;
}

//查询函数
void System::Find()
{

	while (true) {
		cout << "你是要查询基本信息还是查询成绩：" << endl;
		string cho;
		cin >> cho;
		if (cho == "基本信息") {
			cout << "请问是按学号、姓名还是宿舍查询？" << endl;
			string choice;
			cin >> choice;
			if (choice == "学号") {
				cout << "请输入您要查询的学号：";
				/*int iid;
				cin >> iid;*/
				string id;
				cin >> id;
				//stringstream ss;
				//ss << iid;
				//ss >> id;//或者 res = ss.str();
				//输入数据合法
				for (vector<Student>::iterator it = st.begin(); it != st.end(); it++) {
					if (id == (*it).M_id) {
						cout << *it;
						system("pause");
						system("cls");
						return;
					}
				}
				cout << "没查询到相关学生信息，请重新选择!" << endl;
				system("pause");
				system("cls");
				break;
			}
			else if (choice == "姓名") {
				cout << "请输入您要查询的姓名：";
				string name;
				cin >> name;
				//遍历
				for (int i = 0; i < st.size(); i++) {
					if (name == st[i].M_name) {
						cout << st[i];
						system("pause");
						system("cls");
						return;
					}
				}
				cout << "没查询到相关学生信息，请重新选择!" << endl;
				system("pause");
				system("cls");
				break;

			}
			else if (choice == "宿舍") {
				cout << "请输入您要查询的宿舍号：";
				bool flag = 0;
				string homeid;
				cin >> homeid;
				//遍历
				for (int i = 0; i < st.size(); i++) {
					if (homeid == st[i].M_homeId) {
						cout << st[i];
						flag = 1;//用来标记是否找到
					}
				}
				if (flag ) {
					system("pause");
					system("cls");
					break;
				}
				if (!flag ) {
					cout << "没查询到相关学生信息，请重新选择!" << endl;
					system("pause");
					system("cls");
					break;
				}
			}
			else {
				cout << "输入错误请重新输入" << endl;
				system("cls");
				return;
			}
		}
		else {//成绩查询
			string id;
			cout<<"请输入学号：";
			cin >> id;
			int iid = stoi(id,0,10);//将string转换为数字
			//找到学号对应的成绩数组
			map<string, vector<Score>>::iterator pos = mp.find(id);//找到对应学号的迭代器
			//如果没有找到,则新建一个
			if (pos == mp.end()) {
				cout << "没找到此学生成绩信息" << endl;
			}
			else {//找到了
				int cnt = 0;
				float s = 0;
				cout << "学号：" << id << "       " << "姓名:" << st[iid - 1].M_name << endl;
				for (auto x : pos->second) {
					cnt++;//修的门数加一
					s += x.M_ActCredit;
					cout << x;
				}
				printf("共修：%d科，实得总学分为：%.3f\n", cnt, s);
			}
			system("pause");
			system("cls");
			return;
		}
	}
}

//删除函数
void System::Delete()
{
	cout << "请输入要删除学生信息的学号：";
	string id;
	cin >> id;
	//先判断一下A文件中是否有这个学生信息
	for (vector<Student>::iterator it = st.begin(); it != st.end(); it++) {
		if (id == (*it).M_id) {
			st.erase(it);
			//再判断B文件
			map<string, vector<Score>>::iterator pos = mp.find(id);//找到对应学号的迭代器
			if (pos != mp.end())  mp.erase(pos);
			cout << "删除成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
			cout << "没找到此学生成绩信息！" << endl;
			system("pause");
			system("cls");
			return;

}

//排序函数
void System::SortScore()
{
	cout << "请选择按照综合成绩排序还是实得学分排序:";//sort不能对关联性容器例如map排序
	string choice1;
	cin >> choice1;
	if (choice1 == "综合成绩") {
		cout << "请输入要排序的学生学号：";
		string id;
		cin >> id;
		map<string, vector<Score>>::iterator pos = mp.find(id);//找到对应学号的迭代器
		if (pos != mp.end()) {//找到了
			cout << "请选择升序排列还是降序：";
			string choice2;
			cin >> choice2;

			if (choice2 == "升序") {
				multimap<float, string>tt;//对应成绩和课程名称 成绩会自动排序
				for (vector<Score>::iterator it = pos->second.begin(); it != pos->second.end(); it++)
					tt.insert(make_pair(it->M_ZongGrades, it->M_LessonName));

				//插入完即排序完，此时只需要进行输出就可以
				cout << "学号为" << id << "的学生成绩升序排行为：" << endl;
				for (multimap<float, string>::iterator mt = tt.begin(); mt != tt.end(); mt++) 
					cout << "课程名称：" << mt->second << "  综合成绩" << mt->first << endl;
				system("pause");
				system("cls");
				return;
			}
			else {//降序
				multimap<float, string,greater<float>>tt;//对应成绩和课程名称 成绩会自动排序
				for (vector<Score>::iterator it = pos->second.begin(); it != pos->second.end(); it++)
					tt.insert(make_pair(it->M_ZongGrades, it->M_LessonName));
				//改变插入方式，变为从大到小即可
				cout << "学号为" << id << "的学生成绩降序排行为：" << endl;
				for (multimap<float, string, greater<float>>::iterator mt = tt.begin(); mt != tt.end(); mt++) 
					cout << "课程名称：" << mt->second << "  综合成绩" << mt->first << endl;
					system("pause");
					system("cls");
					return;
			}
		}
		else {
			cout << "没找到该学生成绩" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
		else if (choice1 == "实得学分") {
		cout << "请输入要排序的学生学号：";
		string id;
		cin >> id;
		map<string, vector<Score>>::iterator pos = mp.find(id);//找到对应学号的迭代器
		if (pos != mp.end()) {//找到了
			cout << "请选择升序排列还是降序：";
			string choice2;
			cin >> choice2;

			if (choice2 == "升序") {
				multimap<float, string>tt;//对应成绩和课程名称 成绩会自动排序
				for (vector<Score>::iterator it = pos->second.begin(); it != pos->second.end(); it++)
					tt.insert(make_pair(it->M_ActCredit, it->M_LessonName));

				//插入完即排序完，此时只需要进行输出就可以
				cout << "学号为" << id << "的学生学分升序排行为：" << endl;
				for (multimap<float, string>::iterator mt = tt.begin(); mt != tt.end(); mt++)
					cout << "课程名称：" << mt->second << "  实得学分" << mt->first << endl;
				system("pause");
				system("cls");
				return;
			}
			else {//降序
				multimap<float, string, greater<float>>tt;//对应成绩和课程名称 成绩会自动排序
				for (vector<Score>::iterator it = pos->second.begin(); it != pos->second.end(); it++)
					tt.insert(make_pair(it->M_ActCredit, it->M_LessonName));
				//改变插入方式，变为从大到小即可
				cout << "学号为" << id << "的学生学分降序排行为：" << endl;
				for (multimap<float, string, greater<float>>::iterator mt = tt.begin(); mt != tt.end(); mt++)
					cout << "课程名称：" << mt->second << "  实得学分" << mt->first << endl;
				system("pause");
				system("cls");
				return;
			}
		}
		else {
			cout << "没找到该学生学分信息" << endl;
			system("pause");
			system("cls");
			return;
		}
		}
		else
		{
			cout << "输入错误，请重新选择！" << endl;
			system("pause");
			system("cls");
			return;
		}
}

//加载学生信息的函数
void System::LoadMes() {
	//1、创建流对象
	ifstream ifs;
	//2、打开文件
	ifs.open("A.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败！" << endl;
		return;
	}
	//3、读取数据
	string buf;
	while (getline(ifs, buf))
	{
		//cout << buf << endl;
		//将文件中的信息导入到程序中

		//定义两个迭代器用来分割字符串
		//获取id
		string::iterator it1 = buf.begin();
		string::iterator it2 = find(buf.begin(), buf.end(), ' ');
		string id = string(it1, it2);

		//获取名字
		while (*it2 == ' ') { it2++; }//让迭代器跳过id和名字之间的空格
		it1 = it2;
		it2 = find(it1, buf.end(), ' ');//继续找到名字的最后一位
		string name = string(it1, it2);

		//获取性别
		while (*it2 == ' ') { it2++; }//让迭代器跳过名字和性别之间的空格
		it1 = it2;
		it2 = find(it1, buf.end(), ' ');//继续找到性别的最后一位
		string sex = string(it1, it2);

		//获取学生宿舍号码
		while (*it2 == ' ') { it2++; }//让迭代器跳过性别和宿舍号之间的空格
		it1 = it2;
		it2 = find(it1, buf.end(), ' ');//继续找到宿舍号码的最后一位
		string homeid = string(it1, it2);

		//获取学生电话号码
		while (*it2 == ' ') { it2++; }//让迭代器跳过性别和宿舍号之间的空格
		it1 = it2;
		it2 = find(it1, buf.end(), ' ');//继续找到宿舍号码的最后一位
		string callid = string(it1, it2);

		Student st1(id, name, sex, homeid, callid);
		st.push_back(st1);
	}
	//4、关闭文件
	ifs.close();
}

//保存学生信息的函数
void System::SaveMes() {
	ofstream ofs;
	ofs.open("A.txt", ios::out);

	for (vector<Student>::iterator it = st.begin(); it != st.end(); it++) {
		ofs << (*it).M_id << " " << (*it).M_name << " " << (*it).M_sex << " "
			<< (*it).M_homeId << " " << (*it).M_callId << endl;
	}
	ofs.close();
}

//加载学生成绩 
void System::LoadScore() {
	ifstream ifs;
	ifs.open("B.txt", ios::in);
	string buf;
	while (getline(ifs, buf))
	{
		//获取学号
		string::iterator it1 = buf.begin();
		string::iterator it2 = find(buf.begin(), buf.end(), ' ');
		string id = string(it1, it2);

		//获取课号
		while (*it2 == ' ') { it2++; }//让迭代器跳过学号和课号之间的空格
		it1 = it2;
		it2 = find(it1, buf.end(), ' ');//继续找到课号的最后一位
		string lessonid = string(it1, it2);

		//获取课程名称
		while (*it2 == ' ') { it2++; }//让迭代器跳过课号和课程名字之间的空格
		it1 = it2;
		it2 = find(it1, buf.end(), ' ');//继续找到课程名字的最后一位
		string lessoname = string(it1, it2);

		//获取学分
		while (*it2 == ' ') { it2++; }
		it1 = it2;
		it2 = find(it1, buf.end(), ' ');
		string ct = string(it1, it2);
		float credit = stod(ct);

		//获取平时成绩
		while (*it2 == ' ') { it2++; }
		it1 = it2;
		it2 = find(it1, buf.end(), ' ');
		string nt = string(it1, it2);
		float us = stod(nt);

		//获取实验成绩
		while (*it2 == ' ') { it2++; }
		it1 = it2;
		it2 = find(it1, buf.end(), ' ');
		string et = string(it1, it2);
		float es = stod(et);

		//获取卷面成绩
		while (*it2 == ' ') { it2++; }
		it1 = it2;
		it2 = find(it1, buf.end(), ' ');
		string ot = string(it1, it2);
		float os = stod(ot);

		Score sc(lessonid, lessoname, credit, us, es, os);
		//cout << id << lessonid<< lessoname << credit << us << es << os << endl;
		map<string, vector<Score>>::iterator pos = mp.find(id);//找到对应学号的迭代器

		//如果没有找到,则新建一个
		if (pos == mp.end()) {
			vector<Score>ms;
			ms.push_back(sc);
			mp.insert(pair<string, vector<Score>>(id, ms));
		}
		else
			pos->second.push_back(sc);
	}
	ifs.close();
}

//保存学生成绩到文件中
void System::SaveScore()
{
	ofstream ofs;
	ofs.open("B.txt", ios::out);
	for (map<string,vector<Score>>::iterator it = mp.begin(); it != mp.end(); it++)
	{
		for (vector<Score>::iterator mt = it->second.begin(); mt != it->second.end(); mt++) {
			ofs << it->first << " " << mt->M_LessonID << " " << mt->M_LessonName
				<< " " << mt->M_Credit << " " << mt->M_UsuGrades
				<< " " << mt->M_ExpGrades << " " << mt->M_JuanGrades
				<< " " << mt->M_ZongGrades << " " << mt->M_ActCredit << endl;
		}
	}
	ofs.close();
}

//析构函数
System::~System()
{
	
}