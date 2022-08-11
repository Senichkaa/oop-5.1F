#pragma once
#include "Triad.h"

class TrianglePrivate : private Triad
{
public:
	using Triad::get_a;
	using Triad::get_b;
	using Triad::get_c;

	using Triad::set_a;
	using Triad::set_b;
	using Triad::set_c;

	using Triad::Triad;

	TrianglePrivate();
	TrianglePrivate(double a, double b, double c) throw (logic_error);
	TrianglePrivate(const TrianglePrivate& s);

	TrianglePrivate& operator = (const TrianglePrivate& s);
	operator string () const;

	TrianglePrivate& operator ++ () throw (out_of_range);
	TrianglePrivate& operator -- () throw (InheritedException);
	TrianglePrivate operator ++ (int) throw (Exception);
	TrianglePrivate operator -- (int) throw (InheritedException);

	friend ostream& operator << (ostream& out, const TrianglePrivate& s);
	friend istream& operator >> (istream& in, TrianglePrivate& s) throw (logic_error);

	double Sum();
	double Square() const;
	void Angle(double& A, double& B, double& C) const;
};
