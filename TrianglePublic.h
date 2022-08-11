#pragma once
#include "Triad.h"

class TrianglePublic : public Triad
{
public:
	TrianglePublic();
	TrianglePublic(double a, double b, double c) throw(logic_error);
	TrianglePublic(const TrianglePublic& v);

	TrianglePublic& operator ++ () throw(out_of_range);
	TrianglePublic& operator -- () throw(InheritedException);
	TrianglePublic operator ++ (int) throw(Exception);
	TrianglePublic operator -- (int) throw(InheritedException);

	double Sum();
	double Square() const;
	void Angle(double& A, double& B, double& C) const;
};

