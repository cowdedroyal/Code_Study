#include <thread>
#include <chrono> //秒表
#include <iostream>
#include<ctime>
using namespace std;

int flag=0;

class Clock{
	int h;
	int m;
	int s;
public:
	void set(int hour,int min,int sec);//set(int ,int ,int )
	void tick();
	void show();
	void run();
};
void Clock::set(int hour,int min,int sec)
{
	h=hour;
	m=min;
	s=sec;
}
void Clock::tick()
{
	time_t t=time(NULL);//取得当前时间
	while(time(NULL)==t);
	if(--s<0){
		s=59;
		if(--m<0){
			m=59;
			--h<0;
		}
	}
}
void Clock::show()
{
	cout<<'\r';
	if(h<10)cout<<0;
	cout<<h<<':';
	if(m<10)cout<<0;
	cout<<m<<':';
	if(s<10)cout<<0;
	cout<<s<<flush;
}
void Clock::run()
{
	while(h!=0||m!=0||s!=0){
		if(flag==0)
			tick();
		else
			break;
//		show();
	}
	if(flag==0){
		cout<<endl<<"Time out!"<<endl;
		cout<<'\a';
	}
	else{
		cout<<endl<<"Congradulation!"<<endl;
		cout<<'\a';
	}	
}


class do_work    
{    
	
public:
 	Clock c;
	void operator()() //重载（） 操作符
	{
		cout<<"请输入倒计时的时间：";
		int h1=0,m1=0,s1=10;
//		cin>>h1>>m1>>s1;
		c.set(h1,m1,s1);
		c.run();
	};   
	 
};

void operator1() //重载（） 操作符
{
	Clock c;
		cout<<"请输入倒计时的时间：";
		int h1=0,m1=0,s1=10;
//		cin>>h1>>m1>>s1;
		c.set(h1,m1,s1);
		c.run();
//		for (int i = 0; i < 100; i ++){
//			this_thread::sleep_for(chrono::milliseconds(10)); 
//			status ++;
//		}
//		cout << "sub thread finish" << endl;
};

void operate()
{
	
	if(flag==0){
		for(int i=0;i<10;i++){
 			this_thread::sleep_for(chrono::milliseconds(100));
			cin>>i;
		}
		flag=1;
	}
};

int main(){
	printf("HELLO\n");
    thread t2(operate);
    t2.detach(); //detach对flag的修改可以影响到join，反之则不可以
    
    thread t1(operator1);
    t1.join(); //占据主程序，知道结束才释放
	return 0;
}








