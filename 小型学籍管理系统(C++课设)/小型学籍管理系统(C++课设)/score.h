#define  _CRT_SECURE_NO_WARNINGS  
#pragma once

#include<string>
using namespace std;
class Score {
public:

	Score(string LI,string LN, float C,float UG,float EG,float JG) {
		M_LessonID = LI;
		M_LessonName = LN;
		M_Credit = C;
		M_UsuGrades = UG;
		M_ExpGrades = EG;
		M_JuanGrades = JG;
		if (EG == -1)//������ʵ��
			M_ZongGrades = UG * 0.3 + JG * 0.7;
		else 
			M_ZongGrades = UG * 0.15 +EG*0.15+ JG * 0.7;
		
		//����ʵ��ѧ��
		if (M_ZongGrades >= 90 && M_ZongGrades <= 100)
			M_ActCredit = M_Credit;
		else if (M_ZongGrades >= 80 && M_ZongGrades < 90)
			M_ActCredit = M_Credit * 0.8;
		else if (M_ZongGrades >= 70 && M_ZongGrades < 80)
			M_ActCredit = M_Credit * 0.75;
		else if (M_ZongGrades >= 60 && M_ZongGrades < 70)
			M_ActCredit = M_Credit * 0.7;
		else 
			M_ActCredit = 0;
	}
	string M_LessonID;//�γ̱��
	string M_LessonName;//�γ�����
	float M_Credit;//ѧ��
	float M_UsuGrades;//ƽʱ�ɼ�
	float M_ExpGrades;//ʵ��ɼ�
	float M_JuanGrades;//����ɼ�
	float M_ZongGrades;//�ۺϳɼ�
	float M_ActCredit;//ʵ��ѧ��
};