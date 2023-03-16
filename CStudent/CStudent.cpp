#include "CStudent.h"

CStudent::CStudent() 
{
	No[0] = NULL;
	Name[0] = NULL;
	DegChinese = 0;
	DegMaths = 0;
	DegEnglish = 0;
	Sum = 0;
	Num = 1;
}

CStudent::CStudent(const char* No1, const char* Name1)
{
	strcpy_s(No, strlen(No1) + 1, No1);
	strcpy_s(Name, Name1);
	DegChinese = 0;
	DegMaths = 0;
	DegEnglish = 0;
	Sum = 0;
	Num = 1;
}

CStudent::~CStudent()
{
}

/*
* @brief 得到数组私有成员的值
* @param 0是语文成绩，1是数学成绩，2是英语成绩，3是排名
*/
int CStudent::getdata(int number)
{
	switch (number) {
	case 0: return DegChinese; break;
	case 1: return DegMaths; break;
	case 2: return DegEnglish; break;
	case 3: return Num; break;
	}
	return 0;
}

void CStudent::SetData()
{
	if (No[0] == NULL && Name[0] == NULL) {
		cout << "请输入学生的学号姓名(空格分开)：";
		cin >> No;
		cin >> Name;
	}
	cout << "请输入学号为" << No << Name << "同学的成绩" << endl;
	cout << "语文成绩：";
	cin >> DegChinese;
	cout << "数学成绩：";
	cin >> DegMaths;
	cout << "英语成绩：";
	cin >> DegEnglish;
	Sum = DegChinese + DegMaths + DegEnglish;
}

void CStudent::SetNum(int Nu)
{
	Num = Nu;
}

void CStudent::SetData(char *No1,char *Name1,int Ch,int Ma,int En)
{
	strcpy_s(No,strlen(No1)+1, No1);
	strcpy_s(Name, Name1);
	DegChinese = Ch;
	DegMaths = Ma;
	DegEnglish = En;
	Sum = DegChinese + DegMaths + DegEnglish;
}

void CStudent::Display()
{
	cout << setw(15)<< No << "\t" <<setw(10)<< Name << "\t" 
		<< DegChinese << "\t" << DegMaths<< "\t" 
		<< DegEnglish<<"\t"<< fixed << setprecision(2)<<Average();
}

float CStudent::Average()
{
	return (float)Sum/(float)3;
}

void CStatistic::Average()
{
	/*
	* @brief 记录每一科的总分
	* @param 0是语文，1是数学，2是英语 3是平均分
	*/
	float Sum[NUMBER];
	memset(Sum, 0, sizeof(Sum));
	for (int i = 0; i < Nums; i++) {
		Sum[0] += (float)StuArray[i].getdata(0);
		Sum[1] += (float)StuArray[i].getdata(1);
		Sum[2] += (float)StuArray[i].getdata(2);
		Sum[3] += StuArray[i].Average();
	}
	AveChinese = Sum[0] / (float)Nums;
	AveMaths = Sum[1] / (float)Nums;
	AveEnglish = Sum[2] / (float)Nums;
	AveAve = Sum[3] / (float)Nums;
}

void CStatistic::Sort()
{
	CStudent temp;
	for (int i = 0; i < Nums; i++) {
		for (int j = 0; j < Nums-1- i; j++) {
			if (StuArray[j].Average() < StuArray[j+1].Average()) {
				temp = StuArray[j];
				StuArray[j] = StuArray[j+1];
				StuArray[j+1] = temp;
			}
		}
		StuArray[Nums-1-i].SetNum(Nums - i);
	}
}

void CStatistic::Display()
{
	cout << setw(15) << "学号" << "\t" << setw(10) <<"姓名" << "\t"
		<< "语文\t数学\t英语\t平均分\t名次" << endl;
	for (int i=0; i < Nums; i++) {
		StuArray[i].Display();
		cout << "\t" << StuArray[i].getdata(3) << endl;
	}
	cout << setw(15)<<"总评";
	cout<< "\t" <<setw(10)<<"\t"<< AveChinese << "\t"
		<< AveMaths << "\t" << AveEnglish << "\t" << AveAve << endl;
}
