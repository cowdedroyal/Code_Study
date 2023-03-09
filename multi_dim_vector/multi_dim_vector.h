#pragma once
class multi_dim_vector
{
	friend int get_elem(const multi_dim_vector& ob, int en);
public:
	multi_dim_vector();
	~multi_dim_vector();
	multi_dim_vector(const multi_dim_vector& ob2);
	multi_dim_vector(int d);
	void display();
	multi_dim_vector Add(const multi_dim_vector& ob2);
	multi_dim_vector Sub(const multi_dim_vector& ob2);
	int Multi(const multi_dim_vector& ob2);
private:
	int dim;
	int* data;
};

int get_elem(const multi_dim_vector& ob, int en);



