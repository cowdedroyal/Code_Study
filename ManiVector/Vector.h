#pragma once
#ifndef VECTOR_H_
#define VECTOP_H_ //避免重定义

class Vector
{
	friend int getx(Vector &ob); //给予权限访问私有数据成员
	friend int gety(Vector& ob); //注意引用类型也可以修改实参
public:
	Vector();
	Vector(int x1, int y1);
	//输出数据成员函数
	void display();
	//功能成员函数
	Vector Add(const Vector& ob2); 
	Vector Sub(const Vector& ob2);
	int Mult(const Vector& ob2); //点乘
private:
	int x;
	int y;
};

int getx(Vector& ob);
int gety(Vector& ob);

class Matrix{
public:
	Matrix();
	Matrix(Vector MaAr[2][2]);
	void display();
	Vector get(int i, int j);
	Matrix Add(const Matrix& ob2);
	Matrix Sub(const Matrix& ob2);
	int *Mult(const Matrix& ob2);
private:
	Vector MatrixArray[2][2]; 
};

Vector GetVector(Matrix& ob,int i, int j);//不用友元的访问私有数据成员的方法

#endif // !VECTOR_H_