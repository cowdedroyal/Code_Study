#include "create_calculate.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <iomanip>
using namespace std;
int flag = 0;
float correct_rate;
int num;
int tm[3];

void create_calculate::calculate()
{
	int count=0;
	cout << "请输入要出的题数(不超过200)(注意除法保留两位小数即可):"<<endl;
	cout << "请输入规定的时间(按照0 0 0的格式):" << endl;
	cin >> num;
	cin>>tm[0]>>tm[1]>>tm[2];
	//srand(time(NULL)); /*让每次随机数不同*/
	for (int i = 0; i < num; ) {
		float a = (float)((rand() + 1) % 100);
		float b = (float)((rand() + 1) % 100);
		int c = rand() % 4;
		if (a != 0 && b != 0)
		{
			count++;
			if (count % 5 != 0) 
			{
				cout << a << operater[c] << b << "=" << '\t';
			}
			else 
			{
				cout << a << operater[c] << b << "=" << '\t'<<endl;
			}
			switch (operater[c])
			{
			case '+': number[i] = (a + b);  break;
			case '-': number[i] = (a - b);  break;
			case '*': number[i] = (a * b);  break;
			case '/': number[i] = (a / b);  break;
			}
			i++;
		}
	}
	cout <<endl<<"请输入你的答案(输入完答案记得按回车):"<<endl;
}

void create_calculate::correct()
{
	for (int i = 0; i < num; i++)
	{
		cin >> number_ans[i];
	}
	flag = 1;
	int count=0;
	for (int i = 0; i < num; i++)
	{
		if (round(number[i] * 100) / 100 == number_ans[i]) count++;
		else
		{
			cout << endl<< "你本次填错的是: " << number_ans[i] << " 正确答案: " << number[i] << endl;
		}
	}
	correct_rate = ((float)count) / num;
}

void create_calculate::Clock::set(int hour, int min, int sec)
{
	h = hour;
	m = min;
	s = sec;
}
void create_calculate::Clock::tick()
{
	time_t t = time(NULL);//取得当前时间
	while (time(NULL) == t);
	if (--s < 0) {
		s = 59;
		if (--m < 0) {
			m = 59;
			--h < 0;
		}
	}
}

void create_calculate::Clock::show()
{
	cout << '\r';
	if (h < 10)cout << 0;
	cout << h << ':';
	if (m < 10)cout << 0;
	cout << m << ':';
	if (s < 10)cout << 0;
	cout << s << flush;
}

void create_calculate::Clock::run()
{
	while (h != 0 || m != 0 || s != 0) {
		if (flag == 0)
			tick();
		else
			break;
		//show();
	}
	if (flag == 0) {
		cout << endl << "Time out!" << endl;
		cout << '\a';
	}
	else {
		cout << setiosflags(ios::fixed) << setprecision(2);
		cout << endl << "你本次的正确率为：" <<correct_rate*100<<"%"<< endl;
		cout << '\a';
	}
}

void create_calculate::Clock::timing()
{
	set(tm[0], tm[1], tm[2]);
	run();
}


