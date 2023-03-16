#pragma once
#include <string.h>
#include <iostream>
#include<iomanip>
using namespace std;
#define MaxSize 20
#define MaxNum 100
#define NUMBER 4
#define Name_Size 20

class CStudent
{
private:
	char *No = new char[MaxSize]; 
	char Name[Name_Size];
	int DegChinese;
	int DegMaths;
	int DegEnglish;
	int Sum;
	int Num;
public:
	CStudent();
	CStudent(const char* No1,const char* Name1);
	~CStudent();
	int getdata(int number);
	void SetData();
	void SetNum(int Nu); //…Ë÷√≈≈√˚
	void SetData(char* No1, char* Name1, int Ch, int Ma, int En);
	void Display();
	float Average();
};

class CStatistic 
{
private:
	int Nums;
	float AveChinese;
	float AveMaths;
	float AveEnglish;
	float AveAve;
	CStudent StuArray[MaxNum];
public:
	CStatistic(int Num,CStudent SA) {
		Nums = Num;
		AveChinese = 0;
		AveMaths = 0;
		AveEnglish = 0;
		AveAve = 0;
		for (int i = 0; i < Nums; i++) {
			StuArray[i] = SA;
		}
	}
	CStatistic(int Num, CStudent *SA) {
		Nums = Num;
		AveChinese = 0;
		AveMaths = 0;
		AveEnglish = 0;
		AveAve = 0;
		for (int i = 0; i < Nums; i++) {
			StuArray[i] = SA[i];
		}
	}
	void Average();
	void Sort();
	void Display();
};