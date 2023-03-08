// Ex1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <string.h>
using namespace std;
class STU
{
private:
	char *sno;
	int age;
public:
	STU(char *Sno,int Age)
	{
		int Len = strlen(Sno);
		sno = new char[Len+1]; 
		strcpy(sno,Sno);
		age = Age;
	}
	char * GetClassNum()
	{
		STU temp = *this;
		int Len = strlen(sno);
		temp.sno[Len-2]='\0';
		return temp.sno;
	}
	~STU(){delete []sno;}
	void print()
	{cout<<sno<<" "<<age<<endl;}

};

class Vec
{
private:
	int x,y;
public:
	Vec(int X=0,int Y=0) //默认值
		:x(X),y(Y){} //这个函数将带参的构造函数与不带参的构造函数合体了
	//Vec(){}//这里不能在写不带参的构造函数，会报错
	~Vec(){} //析构函数，不接受任何参数，用于释放内存
	Vec add(const Vec &ob);
	void print()
	{
		cout<<"("<<x<<","<<y<<")"<<endl;
	}
};
Vec Vec::add(const Vec &ob)
{
	//Vec tmp;
	//tmp.x = x+ob.x;
	//tmp.y = y+ob.y;
	//return tmp;
	return Vec(x+ob.x,y+ob.y); //无名对象 //同时也调用了复制构造函数
}

int main()
{
	//STU s("190801123",20);
	//s.print();
	//char *p = s.GetClassNum();
	//cout<<p<<endl;
	//s.print();
	////s.GetClassNum()
	
	Vec v1(2,4),v2(-1,-4);
	Vec v3 = v1.add(v2);
	Vec v4;
	//v1.print();
	//v2.print();
	//v3.print();

	Vec *v = new Vec(3,5);
	v->print();

	Vec vv[3] = {Vec(1,1),Vec(2,4),Vec(-2,3)}; //无名对象新的用法
	vv[0].print();
	vv[1].print();
	vv[2].print();
	return 0;
}

