#include <iostream> 
export module Complejo;
using namespace std;

export void MyFunc();

export class Complejo {
	double re = 0;
	double im = 0; // representation: two doubles with default value 0.0

public:
	Complejo(double r, double i) :re{ r }, im{ i } {} // construct complex 	from two scalars : {r, i}
	Complejo(double r) :re{ r } {} // construct complex	from one scalar : {r, 0}
	Complejo() {} // default complex:	{ 0, 0 }
};

