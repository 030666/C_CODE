#define  _CRT_SECURE_NO_WARNINGS  1
#define MAX 1000
#include<iostream>
#include<string>

using namespace std;
//�����ϵ�˽ṹ��
struct Person
{
	//����
	string m_Name;
	//�Ա� 1 �� 2 Ů
	int m_Sex;
	//����
	int m_Age;
	//�绰
	string m_Phone;
	//סַ
	string m_Addr;
};
//���ͨѶ¼�ṹ��
struct Addressbooks
{
	//ͨѶ¼�б������ϵ������
	struct Person personArray[MAX];
	//ͨѶ¼�е�ǰ��¼��ϵ�˵ĸ���
	int m_size;
};

//1�������ϵ��
void addPerson(Addressbooks* abs)
{
	//�ж�ͨѶ¼�Ƿ�������������˾Ͳ������
	if (abs->m_size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		//��Ӿ������ϵ��
		//����
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_Name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;
		while (true)
		{
			//����������1����2�������˳�ѭ������Ϊ���������ȷֵ
			//�������������������
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_Sex = sex;
				break;
			}
			cout << "�����������������룡" << endl;
		}
		//����
		cout << "����������" << endl;
		int age = 0;
		while (true)
		{
			//����������0��200�������˳�ѭ��
			cin >> age;
			if (age >= 0 && age <= 200)
			{
				abs->personArray[abs->m_size].m_Age = age;
				break;
			}
			cout << "�����������������룡" << endl;
		}
		

		//�绰
		cout << "������绰" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_size].m_Phone = phone;
	
		
		//��ַ
		cout << "�������ͥ��ַ" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_size].m_Addr = address;
		//����ͨѶ¼����
		abs->m_size++;
		cout << "��ӳɹ�" << endl;
		system("pause");//�밴���������
		system("cls");//��������

	}
}
//2����ʾ��ϵ��
void showPreson(Addressbooks* abs)
{
	//�ж�ͨѶ¼�������Ƿ�Ϊ�㣬���Ϊ0����ʾ��¼Ϊ��
	//�����Ϊ0����ʾ��¼����ϵ����Ϣ
	if (abs->m_size == 0)
		cout << "��ǰ��¼Ϊ��" << endl;
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "������" << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�: " <<( abs->personArray[i].m_Sex==1?"��":"Ů")<< "\t";
			cout << "�绰: " << abs->personArray[i].m_Phone<< "\t";
			cout << "סַ: " << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");//�����������
	system("cls");//����
}

//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ�����������еľ���λ�ã������ڷ���-1
//����1  ͨѶ¼  ����2  �Ա�����
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		//�ҵ��û������������
		if (abs->personArray[i].m_Name== name)
		{
			return i;
		}
	}return -1;//�������������û���ҵ�������-1
}

//3��ɾ��ָ����ϵ��
void deletePerson(Addressbooks*abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	//ret==-1  δ�鵽
	//ret!=-1  �鵽��
	int ret = isExist(abs, name);
		if (ret != -1)
		{
			//�鵽���ˣ�����ɾ������
			for (int i = ret; i < abs->m_size; i++)
			{
				//����ǰ��
				abs->personArray[i] = abs->personArray[i + 1];
			}
			abs->m_size--;//����ͨѶ¼�е���Ա��
			cout << "ɾ���ɹ�" << endl;

		}
		else
		{
			cout << "���޴���" << endl;
		}
		system("pause");
		system("cls");
}

//4������ָ����ϵ����Ϣ
void findPerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	//�ж�ָ������ϵ���Ƿ����ͨѶ¼��
	int ret=isExist(abs, name);
	if (ret != -1)//�ҵ���ϵ��
	{
		cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�: " << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "�绰: " << abs->personArray[ret].m_Phone << "\t";
		cout << "סַ: " << abs->personArray[ret].m_Addr << endl;
	}
	else   //δ�ҵ���ϵ��
	{
		cout << "���޴���" << endl;
	}
	//�����������
	system("pause");
	system("cls");
	
}

//5���޸�ָ����ϵ����Ϣ
void modifyPerson(Addressbooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret=isExist(abs, name);
	if (ret!= -1)//�ҵ�ָ����ϵ��
	{
		//����
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;
		while(true)
		{
			cin >> sex;

			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "�����������������룡" << endl;
		}
		//����
		cout << "����������" << endl;
		int age = 0;
		while (true)
		{
			//����������0��200�������˳�ѭ��
			cin >> age;
			if (age >= 0 && age <= 200)
			{
				abs->personArray[ret].m_Age = age;
				break;
			}
			cout << "�����������������룡" << endl;
		}
		//�绰
		cout << "������绰" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//��ַ
		cout << "�������ͥ��ַ" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "�޸ĳɹ���" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//6�����������ϵ��
void cleanPerson(Addressbooks* abs)
{
	cout << "���Ƿ����Ҫ���������ϵ�ˣ�'y'or'no'" << endl;
	char panduan;
	cin >> panduan;
	if (panduan == 'y')
	{
		abs->m_size = 0;//����ǰ��¼��ϵ��������Ϊ0�����߼���ղ���
		cout << "ͨѶ¼�����" << endl;
	}
	
	//�����������
	system("pause");
	system("cls");
}
//�˵�����
void showMenu()
{
	cout << "*****************************" << endl;
	cout << "*****	1�������ϵ��	*****" << endl;
	cout << "*****	2����ʾ��ϵ��	*****" << endl;
	cout << "*****	3��ɾ����ϵ��	*****" << endl;
	cout << "*****	4��������ϵ��	*****" << endl;
	cout << "*****	5���޸���ϵ��	*****" << endl;
	cout << "*****	6�������ϵ��	*****" << endl;
	cout << "*****	0���˳�ͨѶ¼	*****" << endl;
	cout << "*****************************" << endl;
}
int main()
{
	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_size = 0;
	int select = 0;//�����û�ѡ������ı���
	while (true)
	{
		//���ò˵�
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://1�������ϵ��
			addPerson(&abs);//���õ�ַ�����޸�ʵ��
			break;
		case 2://	2����ʾ��ϵ��
			showPreson(&abs);
			break;
		case 3://3��ɾ����ϵ��
		/*{cout << "������ɾ����ϵ�˵�������" << endl;
		string name;
		cin >> name;
		if (isExist(&abs, name))
		{
			cout << "���޴���" << endl;
		}
		else
		{
			cout << "�ҵ�����" << endl;
		}*/
			deletePerson(&abs);
		break;
		case 4://4��������ϵ��
			findPerson(&abs);
			break;
		case 5://5���޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6://6�������ϵ��
			cleanPerson(&abs);
			break;
		case 0://0���˳�ͨѶ¼	
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		}
	}
	system("pause");
	return 0;
}
