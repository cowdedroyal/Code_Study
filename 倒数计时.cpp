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
//	do_work():status(0)//ctor
//	{
// 
//	};
 
	void operator()() //重载（） 操作符
	{
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
	 
	
//	int    status;
};

//class do_work_2
//{
//public:
//	void operater()()
//	{
//		for(int i=0;i<100;i++){
// 			i++;
//		}
//	};
//};

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
// 		cout<<i<<" ";
			cin>>i;
		}
		flag=1;
	}
};

int main(){
	printf("HELLO\n");
    thread t2(operate);
    t2.detach();
    
    thread t1(operator1);
    t1.join();
//    do_work dw; 
//	std::thread subThread(dw); // 通过拷贝传值，不影响主线程里面的值
//	subThread.join();
// 	do_work_2 dw2;
// 	std::thread subThread2(dw2);
// 	subThread2.join();
//	dw.status = 0;
//	cout << "before sub thread complete " << dw.status << endl;//输出0
//	std::thread subThread(dw); // 通过拷贝传值，不影响主线程里面的值
//	subThread.join();
//	cout << "after sub thread complete " << dw.status << endl;//输出0
// 
//	dw.status = 0;
//	cout << "before sub thread complete " << dw.status << endl;//输出0
//	std::thread subThread2(std::ref(dw)); // 传引用   不能使用std::thread subThread2(&dw)， 会导致 compile fail
//	subThread2.join();
//	cout << "after sub thread complete " << dw.status << endl;//输出100
	return 0;
}








