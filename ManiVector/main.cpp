#include "Vector.h"
#include <iostream>
using namespace std;

int main() {
	Vector a;
	Vector b(2, 3);
	Vector c(1, 2);
	//两种函数返回值不同带来的影响 
	a.Add(b).display();  //连续调用返回的是实参 //这样才能显示a加完后的值
	b.Sub(c).display();  //不能连续调用，返回的是无名对象 //这里b被无参构造函数重载了，显示的是初始值
	b.display(); //这里显示的是减完后的值
	c.display();
	cout << "c*c: " << c.Mult(c) << endl;
	cout <<"x in a: " << getx(a) << endl;

	Vector M[2][2];
	for (int i = 0; i < 2; i++) { //初始化M
		for (int j = 0; j < 2; j++) {
			int tx, ty;
			cin >>tx >>ty;
			Vector temp(tx, ty);
			M[i][j] = temp;
		}
	}
	Matrix m(M); //有参初始化
	Matrix n; //无参初始化
	m.display();
	cout << "Matrix[1][1]: " << endl;
	GetVector(m, 1, 1).display();
	cout << "m+n: " << endl;
	m.Add(n).display();
	int* temp = m.Mult(m);
	cout <<endl<< "m*m result: ";
	for (int i = 0; i < 4; i++) {
			cout << temp[i] << " ";
	}
	return 0;
}
