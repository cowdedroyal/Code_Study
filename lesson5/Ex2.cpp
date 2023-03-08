// Ex2.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include<iostream>
using namespace std;
class n_vec
{
private:
	int dim;
	int *data;
public:
	n_vec(const n_vec &ob) 
	/**复制构造函数，
	由于data是程序员赋值的内存，如果不写出下面的复制构造函数，
	那么在调用复制构造函数时两个对象中的data公用一个地址
	*/
	{
		dim = ob.dim; 
		data = new int[dim];
		for(int i=0;i<dim;i++)
			data[i] = ob.data[i];
	}
	n_vec(int Dim)
	{
		dim = Dim;
		data = new int[dim];
		cout<<"Pls input data"<<endl;
		for (int i=0;i<dim;i++)
			cin>>data[i];
	}

	void print()
	{
		cout<<"(";
		for(int i=0;i<dim-1;i++)
			cout<<data[i]<<",";
		cout<<data[dim-1]<<")"<<endl;
	}
	n_vec add(const n_vec &ob)
	{
		n_vec tmp=ob;//copy constructor
		tmp.dim = dim;
		for(int i=0;i<dim;i++)
			tmp.data[i] = data[i]+ob.data[i];
		return tmp;//copy constructor
	}
};
int main()
{
	int dim;
	cout<<"please input dim: ";
	cin>>dim;
	n_vec v1(dim);
	n_vec v2(dim);
	v1.print();
	v2.print();

	cout<<"--------------"<<endl;
	n_vec v=v1.add(v2);
	v.print();
	v1.print();
	v2.print();
	return 0;
}

