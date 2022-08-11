#include "TrianglePrivate.h"

TrianglePrivate::TrianglePrivate()
	: Triad()
{}

TrianglePrivate::TrianglePrivate(double A, double B, double C) throw (logic_error)
{
	if (!(A + B > C && B + C > A && A + C > B))
		throw logic_error("Condition is not met");

	set_a(A); set_b(B); set_c(C);
}

TrianglePrivate::TrianglePrivate(const TrianglePrivate& v)
	: Triad(v)
{}

TrianglePrivate& TrianglePrivate::operator = (const TrianglePrivate& n)
{
	double a = n.get_a();
	double b = n.get_b();
	double c = n.get_c();
	return *this;
}

TrianglePrivate::operator string () const
{
	stringstream ss;
	ss << endl;
	ss << "a = " << get_a() << endl;
	ss << "b = " << get_b() << endl;
	ss << "c = " << get_c() << endl;
	return ss.str();
}

TrianglePrivate& TrianglePrivate::operator ++() throw(out_of_range)
{
	this->set_a(this->get_a() + 1);
	if (get_a() > 10)
		throw out_of_range("Side is bigger than 10");
	//стандарт
	return *this;
}

TrianglePrivate& TrianglePrivate::operator --() throw(InheritedException)
{
	this->set_b(this->get_b() - 1);
	if (get_b() <= 0)
		throw new InheritedException();
	return *this;
}

TrianglePrivate TrianglePrivate::operator ++(int) throw (Exception)
{
	TrianglePrivate a(*this);
	this->set_a(this->get_a() + 1);
	if (get_a() > 10)
		throw Exception("Side is bigger than 10");
	//власний
	return a;
}

TrianglePrivate TrianglePrivate::operator --(int) throw(InheritedException)
{
	TrianglePrivate a(*this);
	this->set_b(this->get_b() - 1);
	if (get_b() <= 0)
		throw InheritedException();
	//нащадок
	return a;
}

ostream& operator <<(ostream& out, const TrianglePrivate& s)
{
	out << (string)s;
	return out;
}

istream& operator >>(istream& in, TrianglePrivate& s) throw (logic_error)
{
	double a, b, c;
	cout << "a = "; in >> a;
	cout << "b = "; in >> b;
	cout << "c = "; in >> c;

	if (!(a + b > c && b + c > a && a + c > b))
		throw logic_error("Condition is not met");

	s.set_a(a); s.set_b(b); s.set_c(c);
}

double TrianglePrivate::Sum()
{
	return get_a() + get_b() + get_c();
}

double TrianglePrivate::Square() const
{
	double a = get_a();
	double b = get_b();
	double c = get_c();
	double S = 0;
	double p = (a + b + c) / 2;
	S = sqrt(p * (p - a) * (p - b) * (p - c));
	return S;
}

void TrianglePrivate::Angle(double& A, double& B, double& C) const
{
	const double PI = atan(1) * 4;
	double a = get_a();
	double b = get_b();
	double c = get_c();

	double S = Square();
	double sinA = (S * 2) / (a * b);
	double x1 = asin(sinA);
	A = (x1 * 180) / PI;

	double sinB = (sinA * b) / c;
	double x2 = asin(sinB);
	B = (x2 * 180) / PI;

	C = 180 - (A + B);
}
