#include "CStudent.h"
#include<fstream>
#include<sstream>
int main() 
{
	ifstream infile;
	infile.open("ѧ�������ɼ�.txt", ios::in);
	if (!infile.is_open())
	{
		cout << "��ȡ�ļ�ʧ��" << endl;
		return 0;
	}
	string line;
	CStudent ss[MaxNum];
	int count = 0;
	while (getline(infile, line))
	{
		if(!strlen(line.c_str()))
		{
			continue; //���������
		}
		char No1[MaxSize];
		char Name1[20];
		string goal[3];
		//cout << line<<endl;
		istringstream is(line);
		is >> No1 >> Name1 >> goal[0] >> goal[1] >> goal[2];
		//cout << Name << " " << goal[0] << " " << goal[1] << " " << goal[2] << endl;
		int Ch1 = atoi(goal[0].c_str()); //str.c_str()��stringת����char*
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