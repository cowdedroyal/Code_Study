#pragma once
class create_calculate
{
public:
	void calculate();
	void correct();
	void timing();
	class Clock
	{
	public:
		void set(int hour, int min, int sec);//set(int ,int ,int )
		void tick();
		void show();
		void run();
		void timing();
	private:
		int h; //小时
		int m;
		int s;
	};
private:
	char operater[4] = { '+','-','*','/' };
	float number[200];
	float number_ans[200];
};

