#pragma once
#include <iostream>
using namespace std;
#include <iomanip>

class CStudent
{
private:
	string Name;
	double score;
	string level;
public:
	CStudent();
	friend void Display(CStudent& cs);
	friend class CProcess;
};

class CProcess
{
public:
	void Transform(CStudent& cs);
	void Display(CStudent& cs);
};




