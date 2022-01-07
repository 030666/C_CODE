#define  _CRT_SECURE_NO_WARNINGS  
#include"system.h"
#include<iostream>
#include<fstream>
#include<map>
#include<vector>
#include<algorithm>
#include <sstream>//��intת��Ϊstring
using namespace std;
//�������������ʹ֮�ܹ����ѧ����Ϣ
ostream& operator<<(ostream& out, Student& st1) { 
	out << "ѧ��:" << st1.M_id << "  ������" << st1.M_name << "  �Ա�" << st1.M_sex
		<< "  ѧ������ţ�" << st1.M_homeId << "  ѧ���绰���룺" << st1.M_callId << endl;
	return out;
}

//�������������ʹ֮�ܹ����ѧ���ɼ�
ostream& operator<<(ostream& out, Score & sc) {
	out << "�γ̱�ţ�" << sc.M_LessonID << " �γ����ƣ�" << sc.M_LessonName << " �ۺϳɼ���" << sc.M_ZongGrades << " ʵ��ѧ�֣�" << sc.M_ActCredit << endl;
	return out;
}

//���캯��
System::System()
{
	//���ļ��м���ѧ����Ϣ
	System::LoadMes();
	//���ļ��м��سɼ���Ϣ
	System::LoadScore();
	
}
//չʾ�˵�����
void System::show_Menu()
{
	cout << "************************************" << endl;
	cout << "********��ӭʹ��ѧ������ϵͳ********" << endl;
	cout << "************0���˳�ϵͳ*************" << endl;
	cout << "************1������¼��*************" << endl;
	cout << "************2����ѯ����*************" << endl;
	cout << "************3��ɾ������*************" << endl;
	cout << "************4��������*************"<< endl;
	cout << "************************************" << endl;
}

//�˳�ϵͳ����
void System::ExitSystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;

	//����ѧ����Ϣ���ļ�
	System::SaveMes();

	//����ɼ���Ϣ
	System::SaveScore();

	system("pause");
	exit(0);//�˳�����
}

//�ɼ�����¼�뺯��
void System::SetScore()
{
	cout << "������ѧ�š��γ̱�š��γ����ơ�ѧ�֡�ƽʱ�ɼ���ʵ��ɼ��;���ɼ�:" << endl;
	string id;//ѧ��

	string ld;
	string ln;
	float sc, us, es, ss;
	cin >> id >> ld >> ln >> sc >> us >> es >> ss;

	Score msc(ld, ln, sc,us, es, ss);
	
	//�ҵ�ѧ�Ŷ�Ӧ�ĳɼ����飬Ȼ����ȥ
	map<string, vector<Score>>::iterator pos = mp.find(id);//�ҵ���Ӧѧ�ŵĵ�����
	//���û���ҵ�,���½�һ��
	if (pos == mp.end()) {
		vector<Score>ms;
		ms.push_back(msc);
		mp.insert(pair<string, vector<Score>>(id, ms));
	}
	else {//�ҵ���
		pos->second.push_back(msc);//Ȼ��ͨ���������ҵ�ѧ�Ŷ�Ӧ�ĳɼ�����
	}
	cout << "�ɼ�¼��ɹ���" << endl;
	system("pause");
	system("cls");
	return;
}

//��ѯ����
void System::Find()
{

	while (true) {
		cout << "����Ҫ��ѯ������Ϣ���ǲ�ѯ�ɼ���" << endl;
		string cho;
		cin >> cho;
		if (cho == "������Ϣ") {
			cout << "�����ǰ�ѧ�š��������������ѯ��" << endl;
			string choice;
			cin >> choice;
			if (choice == "ѧ��") {
				cout << "��������Ҫ��ѯ��ѧ�ţ�";
				/*int iid;
				cin >> iid;*/
				string id;
				cin >> id;
				//stringstream ss;
				//ss << iid;
				//ss >> id;//���� res = ss.str();
				//�������ݺϷ�
				for (vector<Student>::iterator it = st.begin(); it != st.end(); it++) {
					if (id == (*it).M_id) {
						cout << *it;
						system("pause");
						system("cls");
						return;
					}
				}
				cout << "û��ѯ�����ѧ����Ϣ��������ѡ��!" << endl;
				system("pause");
				system("cls");
				break;
			}
			else if (choice == "����") {
				cout << "��������Ҫ��ѯ��������";
				string name;
				cin >> name;
				//����
				for (int i = 0; i < st.size(); i++) {
					if (name == st[i].M_name) {
						cout << st[i];
						system("pause");
						system("cls");
						return;
					}
				}
				cout << "û��ѯ�����ѧ����Ϣ��������ѡ��!" << endl;
				system("pause");
				system("cls");
				break;

			}
			else if (choice == "����") {
				cout << "��������Ҫ��ѯ������ţ�";
				bool flag = 0;
				string homeid;
				cin >> homeid;
				//����
				for (int i = 0; i < st.size(); i++) {
					if (homeid == st[i].M_homeId) {
						cout << st[i];
						flag = 1;//��������Ƿ��ҵ�
					}
				}
				if (flag ) {
					system("pause");
					system("cls");
					break;
				}
				if (!flag ) {
					cout << "û��ѯ�����ѧ����Ϣ��������ѡ��!" << endl;
					system("pause");
					system("cls");
					break;
				}
			}
			else {
				cout << "�����������������" << endl;
				system("cls");
				return;
			}
		}
		else {//�ɼ���ѯ
			string id;
			cout<<"������ѧ�ţ�";
			cin >> id;
			int iid = stoi(id,0,10);//��stringת��Ϊ����
			//�ҵ�ѧ�Ŷ�Ӧ�ĳɼ�����
			map<string, vector<Score>>::iterator pos = mp.find(id);//�ҵ���Ӧѧ�ŵĵ�����
			//���û���ҵ�,���½�һ��
			if (pos == mp.end()) {
				cout << "û�ҵ���ѧ���ɼ���Ϣ" << endl;
			}
			else {//�ҵ���
				int cnt = 0;
				float s = 0;
				cout << "ѧ�ţ�" << id << "       " << "����:" << st[iid - 1].M_name << endl;
				for (auto x : pos->second) {
					cnt++;//�޵�������һ
					s += x.M_ActCredit;
					cout << x;
				}
				printf("���ޣ�%d�ƣ�ʵ����ѧ��Ϊ��%.3f\n", cnt, s);
			}
			system("pause");
			system("cls");
			return;
		}
	}
}

//ɾ������
void System::Delete()
{
	cout << "������Ҫɾ��ѧ����Ϣ��ѧ�ţ�";
	string id;
	cin >> id;
	//���ж�һ��A�ļ����Ƿ������ѧ����Ϣ
	for (vector<Student>::iterator it = st.begin(); it != st.end(); it++) {
		if (id == (*it).M_id) {
			st.erase(it);
			//���ж�B�ļ�
			map<string, vector<Score>>::iterator pos = mp.find(id);//�ҵ���Ӧѧ�ŵĵ�����
			if (pos != mp.end())  mp.erase(pos);
			cout << "ɾ���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
			cout << "û�ҵ���ѧ���ɼ���Ϣ��" << endl;
			system("pause");
			system("cls");
			return;

}

//������
void System::SortScore()
{
	cout << "��ѡ�����ۺϳɼ�������ʵ��ѧ������:";//sort���ܶԹ�������������map����
	string choice1;
	cin >> choice1;
	if (choice1 == "�ۺϳɼ�") {
		cout << "������Ҫ�����ѧ��ѧ�ţ�";
		string id;
		cin >> id;
		map<string, vector<Score>>::iterator pos = mp.find(id);//�ҵ���Ӧѧ�ŵĵ�����
		if (pos != mp.end()) {//�ҵ���
			cout << "��ѡ���������л��ǽ���";
			string choice2;
			cin >> choice2;

			if (choice2 == "����") {
				multimap<float, string>tt;//��Ӧ�ɼ��Ϳγ����� �ɼ����Զ�����
				for (vector<Score>::iterator it = pos->second.begin(); it != pos->second.end(); it++)
					tt.insert(make_pair(it->M_ZongGrades, it->M_LessonName));

				//�����꼴�����꣬��ʱֻ��Ҫ��������Ϳ���
				cout << "ѧ��Ϊ" << id << "��ѧ���ɼ���������Ϊ��" << endl;
				for (multimap<float, string>::iterator mt = tt.begin(); mt != tt.end(); mt++) 
					cout << "�γ����ƣ�" << mt->second << "  �ۺϳɼ�" << mt->first << endl;
				system("pause");
				system("cls");
				return;
			}
			else {//����
				multimap<float, string,greater<float>>tt;//��Ӧ�ɼ��Ϳγ����� �ɼ����Զ�����
				for (vector<Score>::iterator it = pos->second.begin(); it != pos->second.end(); it++)
					tt.insert(make_pair(it->M_ZongGrades, it->M_LessonName));
				//�ı���뷽ʽ����Ϊ�Ӵ�С����
				cout << "ѧ��Ϊ" << id << "��ѧ���ɼ���������Ϊ��" << endl;
				for (multimap<float, string, greater<float>>::iterator mt = tt.begin(); mt != tt.end(); mt++) 
					cout << "�γ����ƣ�" << mt->second << "  �ۺϳɼ�" << mt->first << endl;
					system("pause");
					system("cls");
					return;
			}
		}
		else {
			cout << "û�ҵ���ѧ���ɼ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
		else if (choice1 == "ʵ��ѧ��") {
		cout << "������Ҫ�����ѧ��ѧ�ţ�";
		string id;
		cin >> id;
		map<string, vector<Score>>::iterator pos = mp.find(id);//�ҵ���Ӧѧ�ŵĵ�����
		if (pos != mp.end()) {//�ҵ���
			cout << "��ѡ���������л��ǽ���";
			string choice2;
			cin >> choice2;

			if (choice2 == "����") {
				multimap<float, string>tt;//��Ӧ�ɼ��Ϳγ����� �ɼ����Զ�����
				for (vector<Score>::iterator it = pos->second.begin(); it != pos->second.end(); it++)
					tt.insert(make_pair(it->M_ActCredit, it->M_LessonName));

				//�����꼴�����꣬��ʱֻ��Ҫ��������Ϳ���
				cout << "ѧ��Ϊ" << id << "��ѧ��ѧ����������Ϊ��" << endl;
				for (multimap<float, string>::iterator mt = tt.begin(); mt != tt.end(); mt++)
					cout << "�γ����ƣ�" << mt->second << "  ʵ��ѧ��" << mt->first << endl;
				system("pause");
				system("cls");
				return;
			}
			else {//����
				multimap<float, string, greater<float>>tt;//��Ӧ�ɼ��Ϳγ����� �ɼ����Զ�����
				for (vector<Score>::iterator it = pos->second.begin(); it != pos->second.end(); it++)
					tt.insert(make_pair(it->M_ActCredit, it->M_LessonName));
				//�ı���뷽ʽ����Ϊ�Ӵ�С����
				cout << "ѧ��Ϊ" << id << "��ѧ��ѧ�ֽ�������Ϊ��" << endl;
				for (multimap<float, string, greater<float>>::iterator mt = tt.begin(); mt != tt.end(); mt++)
					cout << "�γ����ƣ�" << mt->second << "  ʵ��ѧ��" << mt->first << endl;
				system("pause");
				system("cls");
				return;
			}
		}
		else {
			cout << "û�ҵ���ѧ��ѧ����Ϣ" << endl;
			system("pause");
			system("cls");
			return;
		}
		}
		else
		{
			cout << "�������������ѡ��" << endl;
			system("pause");
			system("cls");
			return;
		}
}

//����ѧ����Ϣ�ĺ���
void System::LoadMes() {
	//1������������
	ifstream ifs;
	//2�����ļ�
	ifs.open("A.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ�ܣ�" << endl;
		return;
	}
	//3����ȡ����
	string buf;
	while (getline(ifs, buf))
	{
		//cout << buf << endl;
		//���ļ��е���Ϣ���뵽������

		//�������������������ָ��ַ���
		//��ȡid
		string::iterator it1 = buf.begin();
		string::iterator it2 = find(buf.begin(), buf.end(), ' ');
		string id = string(it1, it2);

		//��ȡ����
		while (*it2 == ' ') { it2++; }//�õ���������id������֮��Ŀո�
		it1 = it2;
		it2 = find(it1, buf.end(), ' ');//�����ҵ����ֵ����һλ
		string name = string(it1, it2);

		//��ȡ�Ա�
		while (*it2 == ' ') { it2++; }//�õ������������ֺ��Ա�֮��Ŀո�
		it1 = it2;
		it2 = find(it1, buf.end(), ' ');//�����ҵ��Ա�����һλ
		string sex = string(it1, it2);

		//��ȡѧ���������
		while (*it2 == ' ') { it2++; }//�õ����������Ա�������֮��Ŀո�
		it1 = it2;
		it2 = find(it1, buf.end(), ' ');//�����ҵ������������һλ
		string homeid = string(it1, it2);

		//��ȡѧ���绰����
		while (*it2 == ' ') { it2++; }//�õ����������Ա�������֮��Ŀո�
		it1 = it2;
		it2 = find(it1, buf.end(), ' ');//�����ҵ������������һλ
		string callid = string(it1, it2);

		Student st1(id, name, sex, homeid, callid);
		st.push_back(st1);
	}
	//4���ر��ļ�
	ifs.close();
}

//����ѧ����Ϣ�ĺ���
void System::SaveMes() {
	ofstream ofs;
	ofs.open("A.txt", ios::out);

	for (vector<Student>::iterator it = st.begin(); it != st.end(); it++) {
		ofs << (*it).M_id << " " << (*it).M_name << " " << (*it).M_sex << " "
			<< (*it).M_homeId << " " << (*it).M_callId << endl;
	}
	ofs.close();
}

//����ѧ���ɼ� 
void System::LoadScore() {
	ifstream ifs;
	ifs.open("B.txt", ios::in);
	string buf;
	while (getline(ifs, buf))
	{
		//��ȡѧ��
		string::iterator it1 = buf.begin();
		string::iterator it2 = find(buf.begin(), buf.end(), ' ');
		string id = string(it1, it2);

		//��ȡ�κ�
		while (*it2 == ' ') { it2++; }//�õ���������ѧ�źͿκ�֮��Ŀո�
		it1 = it2;
		it2 = find(it1, buf.end(), ' ');//�����ҵ��κŵ����һλ
		string lessonid = string(it1, it2);

		//��ȡ�γ�����
		while (*it2 == ' ') { it2++; }//�õ����������κźͿγ�����֮��Ŀո�
		it1 = it2;
		it2 = find(it1, buf.end(), ' ');//�����ҵ��γ����ֵ����һλ
		string lessoname = string(it1, it2);

		//��ȡѧ��
		while (*it2 == ' ') { it2++; }
		it1 = it2;
		it2 = find(it1, buf.end(), ' ');
		string ct = string(it1, it2);
		float credit = stod(ct);

		//��ȡƽʱ�ɼ�
		while (*it2 == ' ') { it2++; }
		it1 = it2;
		it2 = find(it1, buf.end(), ' ');
		string nt = string(it1, it2);
		float us = stod(nt);

		//��ȡʵ��ɼ�
		while (*it2 == ' ') { it2++; }
		it1 = it2;
		it2 = find(it1, buf.end(), ' ');
		string et = string(it1, it2);
		float es = stod(et);

		//��ȡ����ɼ�
		while (*it2 == ' ') { it2++; }
		it1 = it2;
		it2 = find(it1, buf.end(), ' ');
		string ot = string(it1, it2);
		float os = stod(ot);

		Score sc(lessonid, lessoname, credit, us, es, os);
		//cout << id << lessonid<< lessoname << credit << us << es << os << endl;
		map<string, vector<Score>>::iterator pos = mp.find(id);//�ҵ���Ӧѧ�ŵĵ�����

		//���û���ҵ�,���½�һ��
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

//����ѧ���ɼ����ļ���
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

//��������
System::~System()
{
	
}