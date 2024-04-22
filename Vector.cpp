#include <iostream> 
#include <stdexcept>
#include <string> 
#include "Vector.h"

const bool depuracion = true;

string error_code_name[]{ "range error", "length error" };

Vector::Vector(const Vector& a) // copy constructor
	:elem{ new double[a.sz] }, // allocate space for elements
	sz{ a.sz }
{
	if (depuracion) { cout << "Vector::Vector constructor de copia  " << endl; }
	for (int i = 0; i != sz; ++i) // copy elements
		elem[i] = a.elem[i];
}

Vector& Vector::operator=(const Vector& a) // copy assignment
{
	if (depuracion) { cout << "Vector::operator= copia" << endl; }
	double* p = new double[a.sz];
	for (int i = 0; i != a.sz; ++i)
		p[i] = a.elem[i];
	delete[] elem; // delete old elements
	elem = p;
	sz = a.sz;
	return *this;
}

Vector::Vector(Vector&& a) // move constructor
 // The && means �rvalue reference� and is a reference to which we can bind an rvalue.The word �rvalue� is intended to complement
 // �lvalue, � which roughly means �something that can appear on the left - hand side of an assignment�[Stroustrup, 2010].So an rvalue is
 // - to a first approximation � a value that you can�t assign to, such as an integer returned by a function call.Thus, an rvalue reference is a
 // reference to something that nobody else can assign to, so we can safely �steal� its value.The res local variable in operator+() for Vectors is an example.
	:elem{ a.elem }, // "grab the elements" from a
	sz{ a.sz }
{
	if (depuracion) { cout << "Vector::Vector constructor 'move' " << endl; }

	a.elem = nullptr; // now a has no elements
	a.sz = 0;

}

Vector& Vector::operator=(Vector&& a) // move assignment
{
	if (depuracion) { cout << "Vector::operator= move " << endl; }

	delete[] elem; // delete old elements
	elem = a.elem; 
	a.elem = nullptr; // now a has no elements
	sz = a.sz;
	a.sz = 0;
	return *this;

}

Vector::Vector(int s)
{
	if (depuracion) { cout << "Vector::Vector (int s)" << endl; }
	if (s < 0)
		throw std::length_error{ "Vector constructor: negative size" };

	elem = new double[s];
	sz = s;
}


Vector::Vector(std::initializer_list<double> lst) // initialize with a list
	:elem{ new double[lst.size()] }, sz{ static_cast<int>(lst.size()) }
{
	if (depuracion) { cout << "Vector::Vector(std::initializer_list<double> lst) " << endl; }
	copy(lst.begin(), lst.end(), elem); // copy from lst into elem
}


void Vector::push_back(double newElement) // initialize with a list
{
	if (depuracion) { cout << "Vector::push_back) " << endl; }
	Vector newVector(sz + 1);
	for (int i=0; i!= sz; ++i)
	{
		newVector[i] = elem[i];
	}
	newVector[sz] = newElement;

	sz = newVector.size();
	delete[] elem;
	elem = newVector.elem;
	newVector.elem=nullptr;
	
}

/*
double& Vector::operator[](int i)
{
	if (!(0 <= i && i < size()))
		throw std::out_of_range{ "Vector::operator[]" };

	return elem[i];
}
*/

double& Vector::operator[](int i)
{
	if (depuracion) { cout << "Vector::operator[]) " << endl; }
	expect([i, this] { return 0 <= i && i < size(); },
		Error_code::range_error);
	return elem[i];
}


int Vector::size()
{
	if (depuracion) { cout << "Vector::size() " << endl; }
	return sz;
}

bool operator==(Vector& v1, Vector& v2)
{
	if (depuracion) { cout << "Vector::operator == " << endl; }
	
	if (v1.size() != v2.size())
		return false;
	for (int i = 0; i < v1.size(); ++i)
		if (v1[i] != v2[i])
			return false;
	return true;
}

double* Vector::begin() {
	return &elem[0];
}

double* Vector::end() {
	return &elem[0] + sz;
}
