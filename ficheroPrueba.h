#pragma once
import Vector; 

#ifdef __linux__ 
import vector;
import iostream;
import utility;
import string;
import ranges;
import sstream;
import exception;
import type_traits;
import locale.h;

#elif _WIN32
#include <vector>
#include <iostream>
#include <utility>
#include <string>
#include <ranges>
#include <sstream>
#include <exception>
#include <type_traits>
#include <locale.h>
#else
// Ot her OS
#endif


#ifdef __linux__ 
    //linux code goes here
#elif _WIN32
#include <winrt/Windows.Foundation.h>
#else
// Ot her OS
#endif


#include <coroutine>
#include <random>

using namespace std;

void funcionPrueba();


namespace My_code {
	// ...
	int main();
}

int sum(const std::vector<int>& v);

struct Entry345 {
    std::string name;
    int value;
};

Entry345 read_entry345(std::istream& is);

class Container {
public:
	virtual double& operator[](int) = 0; // pure virtual function
	// virtual int size() const = 0; // const member function (�5.2.1)
	virtual int size() = 0; 
	virtual ~Container() {} // destructor (�5.2.2)
};

class Vector_container : public Container { // Vector_container	implements Container
public:
	Vector_container(int s) : v(s) { } // Vector of s elements
	~Vector_container() {}
	double& operator[](int i) override { return v[i]; }
	// int size() const override { return (v.size() }
	int size() override { return (v.size()); }
private:
	Vector v;
};

void usaC(Container& c);

template<typename T>
class Less_than {
	const T val; // value to compare against
public:
	Less_than(const T& v) :val{ v } { }
	bool operator()(const T& x) const { return x < val; } // call operator
};

template<typename C, typename P>
int count(const C& c, P pred) // assume that C is a container and P is a predicate on its elements
{
	int cnt = 0;
	for (const auto& x : c)
		if (pred(x))
			++cnt;
	return cnt;
}

template<typename B>
concept Boolean =
	requires(B x, B y) {
		{ x = true };
		{ x = false };
		{ x = (x == y) };
		{ x = (x != y) };
		{ x = !x };
		{ x = (x = y) };
};

template<typename T, typename T2 = T>
concept Equality_comparable =
	requires (T a, T2 b) {
		{ a == b } -> Boolean; // compare a T to a T2 with ==
		{ a != b } -> Boolean; // compare a T to a T2 with !=
		{ b == a } -> Boolean; // compare a T2 to a T with ==
		{ b != a } -> Boolean; // compare a T2 to a T with !=
};


// struct S { int a; };
// static_assert(equality_comparable<S>);

static_assert(equality_comparable<int>);
static_assert(Equality_comparable<int, double>); 

template<typename T, typename U = T>
concept Number =
	requires(T x, U y) { // Something with arithmetic operations and a zero
	x + y; x - y; x* y; x / y; x % y;
	x += y; x -= y; x *= y; x /= y; x %= y;
	x = x; // copy
	x = 0;
};

template<typename T, typename U = T>
concept Arithmetic = Number<T, U> && Number<U, T>;

template<equality_comparable T>
bool compara(T a, T b)
{
	return a < b;
}

template<forward_iterator Iter, Arithmetic<iter_value_t<Iter>> Val>
Val accumulate(Iter first, Iter last, Val res)
{
	for (auto p = first; p != last; ++p)
		res += *p;
	return res;
}

// concept Sequence = input_range<S>; // simple to write and general

/* 
template<typename S>
concept Sequence = requires (S a) {
	typename range_value_t<S>; // S must have a value type
	typename iterator_t<S>; // S must have an iterator type
	{ a.begin() } -> same_as<iterator_t<S>>; // S must have a begin() that returns an iterator
	{ a.end() } -> same_as<iterator_t<S>>;
	requires input_iterator<iterator_t<S>>; // S's iterator	must be an input_iterator
	requires same_as<range_value_t<S>, iter_value_t<S>>;

};

*/

template<typename T>
concept Printable = requires(T t) { std::cout << t; }; // just one operation!

template<Printable T, Printable... Tail>
void imprimeTemp(T head, Tail... tail)
{
	cout << head << ' '; // first, what we do for the head
	if constexpr (sizeof...(tail) > 0)
		imprimeTemp(tail...); // then, what we do for the tail
}

template<Number... T>
int sumame(T... v)
{
	return (v + ... + 0); // add all elements of v starting with 0
}


struct Entry11 {
	string name;
	int number;
};

ostream& operator<<(ostream& os, const Entry11& e);

istream& operator>>(istream& is, Entry11& e);

template<typename C>
class Checked_iter {
public:
	using value_type = typename C::value_type;
	using difference_type = int;
	Checked_iter() { throw bad_exception; } // concept forward_iterator requires a default constructor
	Checked_iter(C& cc) : pc{ &cc } {}
	Checked_iter(C& cc, typename C::iterator pp) : pc{ &cc }, p{ pp }
	{}
	Checked_iter& operator++() { check_end(); ++p; return *this; }
	Checked_iter operator++(int) {
		check_end(); auto t{ *this }; ++p;
		return t;
	}
	value_type& operator*() const { check_end(); return *p; }
	bool operator==(const Checked_iter& a) const { return p == a.p; }
	bool operator!=(const Checked_iter& a) const { return p != a.p; }
private:
	void check_end() const { if (p == pc->end()) { throw bad_exception;  }; }
	C* pc{}; // default initialize to nullptr
	typename C::iterator p = pc->begin();
};



class DivideByZeroException : public runtime_error {
public:

	DivideByZeroException(int x, int y)
		: runtime_error("division by zero"), numerator(x), denominator(y)
	{}

	virtual const char* what() const throw()
	{
		cnvt.str("");

		cnvt << runtime_error::what() << ": " << getNumerator()
			<< " / " << getDenominator();

		return cnvt.str().c_str();
	}

	int getNumerator() const
	{
		return numerator;
	}

	int getDenominator() const
	{
		return denominator;
	}

	template<typename T>
	static T divide(const T& n1, const T& n2)
	{
		if (n2 == T(0)) {
			throw DivideByZeroException(n1, n2);
		}

		return (n1 / n2);
	}

private:
	int numerator;
	int denominator;

	static ostringstream cnvt;
};

// ostringstream DivideByZeroException::cnvt; // Se lleva al fichero de implementaci�n

/*
template<typename C, typename V>
vector<typename C::iterator> find_all(C& c, V v) // find all occurrences of v in c
{
	vector<typename C::iterator> res;
	for (auto p = c.begin(); p != c.end(); ++p)
		if (*p == v)
			res.push_back(p);
	return res;
}
*/

template<typename T>
using range_value_type_t = T::value_type;

template<typename C, typename V>
auto find_all(C& c, V v) // find all occurrences of v in c
{
	vector<range_value_type_t<C>*> res;
	for (auto& x : c)
		if (x == v)
			res.push_back(&x);
	return res;
}


template<class Iter>
class Sentinel {
public:
	Sentinel(int ee) : end(ee) { }
	Sentinel() :end(0) {} // Concept sentinel_for requires a default constructor
	friend bool operator==(const Iter& p, Sentinel s) {
		return (*p == s.end);
	}
	friend bool operator!=(const Iter& p, Sentinel s) {
		return !(p == s);
	}
private:
	iter_value_t<const char*> end; // the sentinel value
};

// static_assert(sentinel_for<Sentinel<const char*>, const char*>); // check the Sentinel for C - style strings
template <typename T>
void swap(T& a, T& b)
{
	T tmp{ std::move(a) }; // the T constructor sees an rvalue and	moves
	a = std::move(b); // the T assignment sees an rvalue and	moves
	b = std::move(tmp); // the T assignment sees an rvalue and	moves
}

class Rand_int {
public:
	Rand_int(int low, int high) :dist{ low,high } { }
	int operator()() { return dist(re); } // draw an int
	void seed(int s) { re.seed(s); } // choose new random engine seed

private:
	default_random_engine re;
	uniform_int_distribution<> dist;
};

struct task {
	void operator()() { coro.resume(); }
	struct promise_type { // mapping to the language features
		suspend_always initial_suspend() { return {}; }
		suspend_always final_suspend() noexcept { return {}; } //		co_return
		suspend_always yield_value(int) { return {}; } //		co_yield
		auto get_return_object() {
			return task {
handle_type::from_promise(*this)
			};
		}
		void return_void() {}
		void unhandled_exception() { exit(1); }
	};
	using handle_type = coroutine_handle<promise_type>;
	task(handle_type h) : coro(h) { } // called by get_return_object()
	handle_type coro; // here is the coroutine handle
};

task char_seq(char start);
task sequencer(int start, int step = 1);
task string_seq (string start);

struct Event_base {
	virtual void operator()() = 0;
	virtual ~Event_base() {}
};

template<class Act>
struct Event : Event_base {
	Event(const string n, Act a) : name{ n }, act{ move(a) } {}
	string name;
	Act act;
	void operator()() override { act(); }
};


