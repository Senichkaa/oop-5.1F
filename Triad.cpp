#include "Triad.h"

Triad::Triad()
	:a(0),b(0),c(0)
{
}

Triad::Triad(double a, double b, double c) throw(out_of_range)
{
	if (!((a > -10 && a < 10) || (b > -10 && b < 10) || (c > -10 && c < 10)))
		throw out_of_range("Numbers must belong to [-10;10]");
	//стандарт

	this->a = a;
	this->b = b;
	this->c = c;
}

Triad::Triad(const Triad& s)
{
	set_a(s.get_a());
	set_b(s.get_b());
	set_c(s.get_c());
}

Triad& Triad::operator=(const Triad& s)
{
	set_a(s.get_a());
	set_b(s.get_b());
	set_c(s.get_c());
	return *this;
}

Triad::operator string() const
{
	stringstream ss;
	ss << "a = " << a << endl;
	ss << "b = " << b << endl;
	ss << "c = " << c << endl;
	return ss.str();
}

ostream& operator<<(ostream& out, const Triad& s)
{
	out << string(s);
	return out;
}

istream& operator>>(istream& in, Triad& s) throw(Exception)
{
	double a, b, c;
	cout << "a = "; in >> a;
	cout << "b = "; in >> b;
	cout << "c = "; in >> c;

	if (!((a > -10 && a < 10) || (b > -10 && b < 10) || (c > -10 && c < 10)))
		throw out_of_range("Numbers must belong to [-10;10]");

	s.set_a(a); s.set_b(b); s.set_c(c);
	return in;
}
