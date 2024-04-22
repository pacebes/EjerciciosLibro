#pragma once
#include <iostream> 
#include <stdexcept>
#include <string> 
using namespace std;

enum class Error_action { ignore, throwing, terminating, logging }; // error-handling alternatives

constexpr Error_action default_Error_action = Error_action::throwing; // a default

enum class Error_code { range_error, length_error }; // individual errors

extern string error_code_name[];

// names of individual errors
template<Error_action action = default_Error_action, class C>
constexpr void expect(C cond, Error_code x) // take "action" if the expected condition "cond" doesn't hold
{
	if constexpr (action == Error_action::logging)
        if (!cond()) std::cerr << "expect() failure: " << int(x) << ' ' << error_code_name[int(x)] << '\n';
	if constexpr (action == Error_action::throwing)
		if (!cond()) throw x;
	if constexpr (action == Error_action::terminating)
		if (!cond()) terminate();
	// or no action
}



class Vector {

public:
	Vector(int s);
	double& operator[](int i);
	Vector() { elem = nullptr;  sz = 0; }; // default initalize to "empty"; that is, to no elements
	int size();
	~Vector() { delete[] elem; };
	Vector(std::initializer_list<double>); // initialize with a list of	doubles

	Vector(const Vector& a); // copy constructor
	Vector& operator=(const Vector& a); // copy assignment
	Vector(Vector&& a); // move constructor
	Vector& operator=(Vector&& a); // move assignment


	void push_back(double); // add element at end,	increasing the size by one

	double* begin();

	double* end();

private:
	double* elem; // elem points to an array of sz doubles
	int sz;
};

