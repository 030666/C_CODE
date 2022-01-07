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
		if (EG == -1)//表明无实验
			M_ZongGrades = UG * 0.3 + JG * 0.7;
		else 
			M_ZongGrades = UG * 0.15 +EG*0.15+ JG * 0.7;
		
		//计算实得学分
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
	string M_LessonID;//课程编号
	string M_LessonName;//课程名称
	float M_Credit;//学分
	float M_UsuGrades;//平时成绩
	float M_ExpGrades;//实验成绩
	float M_JuanGrades;//卷面成绩
	float M_ZongGrades;//综合成绩
	float M_ActCredit;//实得学分
};