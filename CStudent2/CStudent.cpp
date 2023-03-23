#include "CStudent.h"

CStudent::CStudent()
{
	cout<< "������ѧ���������ͳɼ���";
	cin >> Name >> score;
}

void Display(CStudent& cs)
{
	string rank;
	if (cs.score >= 90)
		rank = "����";
	else if (cs.score >= 80 && cs.score <= 89)
		rank = "����";
	else if (cs.score >= 70 && cs.score <= 79)
		rank = "�е�";
	else if (cs.score >= 60 && cs.score <= 69)
		rank = "����";
	else rank = "������";
	cout << setw(8) << cs.Name << "\t" << cs.score << "\t" << rank << endl;
}

void CProcess::Transform(CStudent& cs)
{
	if (cs.score >= 90)
		cs.level = "����";
	else if (cs.score >= 80 && cs.score <= 89)
		cs.level = "����";
	else if (cs.score >= 70 && cs.score <= 79)
		cs.level = "�е�";
	else if (cs.score >= 60 && cs.score <= 69)
		cs.level = "����";
	else cs.level = "������";
}

void CProcess::Display(CStudent& cs)
{
	cout << setw(8) << cs.Name << "\t" << cs.score << "\t" << cs.level << endl;
}
