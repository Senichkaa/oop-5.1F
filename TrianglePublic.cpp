#include "TrianglePublic.h"

TrianglePublic::TrianglePublic()
	: Triad()
{}

TrianglePublic::TrianglePublic(double A, double B, double C) throw(logic_error)
{
	if (!(A + B > C && B + C > A && A + C > B))
		throw logic_error("Condition is not met");

	set_a(A); set_b(B); set_c(C);
}

TrianglePublic::TrianglePublic(const TrianglePublic& v)
	: Triad(v)
{}

TrianglePublic& TrianglePublic::operator ++() throw(out_of_range)
{
	this->set_a(this->get_a() + 1);
	if (get_a() > 10 || get_b() > 10 || get_c() > 10)
		throw out_of_range("Side is bigger than 10");
	return *this;
}

TrianglePublic& TrianglePublic::operator --() throw(InheritedException)
{
	this->set_b(this->get_b() - 1);
	if (get_b() == 0)
		throw new InheritedException();
	return *this;
}

TrianglePublic TrianglePublic::operator ++(int) throw (Exception)
{
	TrianglePublic a(*this);
	this->set_a(this->get_a() + 1);
	if (get_a() > 10 || get_b() > 10 || get_c() > 10)
		throw Exception("Side is bigger than 10");
	return a;
}

TrianglePublic TrianglePublic::operator --(int) throw(InheritedException)
{
	TrianglePublic a(*this);
	this->set_a(this->get_b() - 1);
	if (get_b() == 0)
		throw Exception();
	return a;
}

double TrianglePublic::Sum()
{
	return get_a() + get_b() + get_c();
}

double TrianglePublic::Square() const
{
	double a = get_a();
	double b = get_b();
	double c = get_c();
	double S = 0;
	double p = (a + b + c) / 2;
	S = sqrt(p * (p - a) * (p - b) * (p - c));
	return S;
}

void TrianglePublic::Angle(double& A, double& B, double& C) const
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
