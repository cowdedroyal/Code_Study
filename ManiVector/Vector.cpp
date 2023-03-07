#include "Vector.h"
#include <iostream>
using namespace std;

Vector::Vector() //无参数值的构造函数
{
	x = 0;
	y = 0;
}

Vector::Vector(int x1, int y1) //有参数值的构造函数
{
	x = x1;
	y = y1;
}

void Vector::display() 
{
	cout << "Vector(x,y): (" << x << "," << y << ")" << endl;
}

Vector Vector::Add(const Vector& ob2) 
{
	x = x + ob2.x;
	y = y + ob2.y;
	//return Vector();
	return *this;//为什么用*this //采用这个方式可以连续调用
}

Vector Vector::Sub(const Vector& ob2)
{
	x = x - ob2.x;
	y = y - ob2.y;
	return Vector();//无名对象，有什么作用? #1
}

int Vector::Mult(const Vector& ob2)
{
	int result;
	result = x * ob2.x + y * ob2.y;
	return result;
}

int getx(Vector &ob)
{
	return ob.x;
}

int gety(Vector& ob)
{
	return ob.y;
}

Vector GetVector(Matrix &ob,int i, int j)
{
	return ob.get(i,j);
}

Matrix::Matrix()
{
	//Matrix无参的初始化，通过Vector的无参初始化完成
}

Matrix::Matrix(Vector MaAr[2][2])
{
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			MatrixArray[i][j] = MaAr[i][j];//完成对Matrix有参的初始化
		}
	}
}

void Matrix::display()
{
	cout << "Matrix:" << endl;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cout<<"(" << getx(MatrixArray[i][j]) << ","<<gety(MatrixArray[i][j])<<") ";
		}
		cout << endl;
	}
}

Vector Matrix::get(int i, int j)
{
	return MatrixArray[i][j];
}

Matrix Matrix::Add(const Matrix& ob2)
{
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			MatrixArray[i][j].Add(ob2.MatrixArray[i][j]);
		}
	}
	return *this;
}

Matrix Matrix::Sub(const Matrix& ob2)
{
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			MatrixArray[i][j].Sub(ob2.MatrixArray[i][j]);
		}
	}
	return Matrix();
}

int* Matrix::Mult(const Matrix& ob2)
{
	int k = 0,temp=0;
	int *array = new int[4];
	for (int i = 0; i < 2; i++) {
		temp=0;
		for (int j = 0; j < 2; j++) {
			 temp += MatrixArray[i][j].Mult(ob2.MatrixArray[j][0]);
		}
		array[k++] = temp;
		temp = 0;
		for (int j = 0; j < 2; j++) {
			temp += MatrixArray[i][j].Mult(ob2.MatrixArray[j][1]);
		}
		array[k++] = temp;
	}
	return array;
}




