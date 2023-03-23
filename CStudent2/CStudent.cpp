#include "CStudent.h"

CStudent::CStudent()
{
	cout<< "请输入学生的姓名和成绩：";
	cin >> Name >> score;
}

void Display(CStudent& cs)
{
	string rank;
	if (cs.score >= 90)
		rank = "优秀";
	else if (cs.score >= 80 && cs.score <= 89)
		rank = "良好";
	else if (cs.score >= 70 && cs.score <= 79)
		rank = "中等";
	else if (cs.score >= 60 && cs.score <= 69)
		rank = "及格";
	else rank = "不及格";
	cout << setw(8) << cs.Name << "\t" << cs.score << "\t" << rank << endl;
}

void CProcess::Transform(CStudent& cs)
{
	if (cs.score >= 90)
		cs.level = "优秀";
	else if (cs.score >= 80 && cs.score <= 89)
		cs.level = "良好";
	else if (cs.score >= 70 && cs.score <= 79)
		cs.level = "中等";
	else if (cs.score >= 60 && cs.score <= 69)
		cs.level = "及格";
	else cs.level = "不及格";
}

void CProcess::Display(CStudent& cs)
{
	cout << setw(8) << cs.Name << "\t" << cs.score << "\t" << cs.level << endl;
}
