#include "CStudent.h"

int main()
{
	int StNum = 0;
	cout << "请输入学生的数量：";
	cin >> StNum;
	CStudent *css = new CStudent[StNum];
	CProcess cpr;
	cout << "友元函数输出方式：" << endl;
	cout << setw(8) << "姓名" << "\t" << "成绩" << "\t" << "等级" << endl;
	for (int i = 0; i < StNum; i++)
	{
		Display(css[i]);
	}
	cout << endl;
	cout << "友元类的输出方式：" << endl;
	cout << setw(8) << "姓名" << "\t" << "成绩" << "\t" << "等级" << endl;
	for (int i = 0; i < StNum; i++)
	{
		cpr.Transform(css[i]);
		cpr.Display(css[i]);
	}
	return 0;
}