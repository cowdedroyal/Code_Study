#include "multi_dim_vector.h"
#include <iostream>
using namespace std;

multi_dim_vector::multi_dim_vector()
{
	dim = 2;
	data = new int[dim];
}

multi_dim_vector::~multi_dim_vector()
{
	delete(data);
}

multi_dim_vector::multi_dim_vector(const multi_dim_vector& ob2)
{
	dim = ob2.dim;
	data = new int[dim]; //复制构造函数这里一定要重新分配内存，获取新地址
	for (int i = 0; i < dim; i++) {
		data[i] = ob2.data[i];
	}
}

multi_dim_vector::multi_dim_vector(int d)
{
	dim = d;
	data = new int[dim]; //要分配内存
	cout << "请输入多维向量(空格分隔): " << endl;
	for (int i = 0; i < dim; i++)
	{
		cin >> data[i];
	}
}

void multi_dim_vector::display()
{
	cout << "(";
	for (int i = 0; i < dim - 1; i++)
	{
		cout << data[i] << ",";
	}
	cout << data[dim - 1] << ")" << endl;
}

multi_dim_vector multi_dim_vector::Add(const multi_dim_vector& ob2)
{
	for (int i = 0; i < dim; i++)
	{
		data[i] += ob2.data[i];
	}
	return *this;
}

multi_dim_vector multi_dim_vector::Sub(const multi_dim_vector& ob2)
{
	for (int i = 0; i < dim; i++)
	{
		data[i] -= ob2.data[i];
	}
	return *this;
}

int multi_dim_vector::Multi(const multi_dim_vector& ob2)
{
	int result = 0;
	for (int i = 0; i < dim; i++)
	{
		result += data[i] * ob2.data[i];
	}
	return result;
}

int get_elem(const multi_dim_vector& ob, int en)
{
	return ob.data[en];
}

