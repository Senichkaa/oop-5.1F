#pragma once
#include "Exception.h"
#include "InheritedException.h"
class Triad
{
private:
	double a, b, c;
public:
	Triad();
	Triad(double a, double b, double c) throw(out_of_range);
	Triad(const Triad& s);

	double get_a() const { return a; }
	double get_b() const { return b; }
	double get_c() const { return c; }

	void set_a(double value) { a = value; }
	void set_b(double value) { b = value; }
	void set_c(double value) { c = value; }

	Triad& operator = (const Triad& s);
	operator string() const;
	
	friend ostream& operator << (ostream& out, const Triad& s);
	friend istream& operator >> (istream& in, Triad& s) throw(Exception);
};

