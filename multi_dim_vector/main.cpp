#include "multi_dim_vector.h"
#include <iostream>
using namespace std;

int main()
{
	int dim1,dim2;
	cout << "请输入你要创建的向量的维度：";
	cin >> dim1;
	multi_dim_vector mv1(dim1);
	multi_dim_vector mv2(dim1);
	mv1.Add(mv2).display();
	mv1.Sub(mv2).display();
	cout<<"mv1*mv2: "<<mv1.Multi(mv2)<<endl;

	cout<<"你想获得mv1向量的某个维度的值：";
	cin>>dim2;
	cout<<"mv1的第"<<dim2<<"维度的值为: "<<get_elem(mv1,dim2-1);
	return 0;
}