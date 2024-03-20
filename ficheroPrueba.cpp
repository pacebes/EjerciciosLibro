#include <iostream> 
#include <string> 
#include "ficheroPrueba.h" 

int My_code::main()
{
		
	std::cout << "Programa My_code::main \n";
	return (1);
	// ...
}

void funcionPrueba()
{
	std::cout << "Función prueba invocada \n";
}

int sum(const std::vector<int>& v)
{
	int s = 0;
	for (const int i : v)
		s += i;
	return s;
}


Entry345 read_entry345(std::istream& is)
{
    std::string s;
    int i;
    is >> s >> i;
    return { s,i };
}

void usaC(Container& c)
{
	const int sz = c.size();
	for (int i = 0; i != sz; ++i)
		std::cout << c[i] << '\n';
}


ostream& operator<<(ostream& os, const Entry11& e)
{
	return os << "{\"" << e.name << "\", " << e.number << "}";
}


istream& operator>>(istream& is, Entry11& e)
// read { "name" , number } pair. Note: formatted with { " " , and }
{
	char c, c2;
	if (is >> c && c == '{' && is >> c2 && c2 == '"') { // start with a { followed		by a "
		string name; // the default value of a string is the empty string : ""
		while (is.get(c) && c != '"') // anything before a " is part of			the name
			name += c;
		if (is >> c && c == ',') {
			int number = 0;
			if (is >> number >> c && c == '}') { // read the number and a		}
				e = { name,number }; // assign to the entry
				return is;
			}
		}
	}
	is.setstate(ios_base::failbit); // register the failure in the stream
	return is;
}

ostringstream DivideByZeroException::cnvt;

task sequencer(int start, int step )
{
	auto value = start;
	while (true) {
		cout << "value: " << value << '\n'; // communicate a result
		co_yield 0; // sleep until someone resumes this coroutine
		value += step; // update state
	}
}

task char_seq(char start)
{
	auto value = start;
	while (true) {
		cout << "value: " << value << '\n'; // communicate result
		co_yield 0;
		++value;
	}
}

task string_seq(string start)
{
	auto value = start;
	while (true) {
		cout << "value: " << value << '\n'; // communicate result
		co_yield 0;
		value+="0";
	}
}