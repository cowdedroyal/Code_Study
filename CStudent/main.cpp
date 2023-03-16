#include "CStudent.h"
#include<fstream>
#include<sstream>
int main() 
{
	ifstream infile; //文件指针
	infile.open("学号姓名成绩.txt", ios::in);
	if (!infile.is_open())
	{
		cout << "读取文件失败" << endl;
		return 0;
	}
	string line;
	CStudent ss[MaxNum];
	int count = 0;
	while (getline(infile, line)) //读取每一行的内容
	{
		if(!strlen(line.c_str()))
		{
			continue; //不读入空行
		}
		char No1[MaxSize];
		char Name1[20];
		string goal[3];
		//cout << line<<endl;
		istringstream is(line); //将读入的行的内容按空格切割，注意不只是空格，制表符也算
		is >> No1 >> Name1 >> goal[0] >> goal[1] >> goal[2]; //只取前五个数据
		//cout << Name << " " << goal[0] << " " << goal[1] << " " << goal[2] << endl;
		int Ch1 = atoi(goal[0].c_str()); //str.c_str()将string转换成char*
		int Ma1 = atoi(goal[1].c_str());
		int En1 = atoi(goal[2].c_str());
		ss[count++].SetData(No1, Name1, Ch1, Ma1, En1);
	}
	CStatistic cs(count, ss);
	cs.Sort();
	cs.Average();
	cs.Display();
	return 0;
}
