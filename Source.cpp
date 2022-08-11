#include "TrianglePrivate.h"
#include "TrianglePublic.h"

void _unexpected_to_bad()
{
	cerr << "bad_exception" << endl;
	throw;
}

void Call_Bad() throw(bad_exception)
{
	throw bad_exception();
}

int main()
{
	try
	{
		TrianglePrivate A1;
		cin >> A1;
		cout << A1;

		cout << "Size of private class: " << sizeof(A1) << endl;

		double A = 0.0;
		double B = 0.0;
		double C = 0.0;

		cout << "Square: " << A1.Square() << endl;

		A1.Angle(A, B, C);
		cout << "Angle A = " << A << endl;
		cout << "Angle B = " << B << endl;
		cout << "Angle C = " << C << endl << endl;
		try
		{
			A1--;
		}
		catch (InheritedException a)//
		{
			cerr << a.What() << endl << endl;
		}
		catch (InheritedException* a)//
		{
			cerr << a->What() << endl << endl;
		}
	}
	catch (logic_error a)
	{
		cerr << "Exception: " << a.what() << endl;
	}

	TrianglePrivate N1;
	cin >> N1;
	cout << N1;

	try
	{
		N1++;
	}
	catch (Exception& a)//
	{
		cerr << "Exception: " << a.What() << endl;
	}
	catch (out_of_range a)
	{
		cerr << "Exception: " << a.what() << endl;
	}

	try
	{
		TrianglePublic A2(5, 2, 5);

		cout << "Size of public class: " << sizeof(A2) << endl;

		double A = 0.0;
		double B = 0.0;
		double C = 0.0;

		cout << "Square: " << A2.Square() << endl;

		A2.Angle(A, B, C);
		cout << "Angle A = " << A << endl;
		cout << "Angle B = " << B << endl;
		cout << "Angle C = " << C << endl << endl;
		try
		{
			A2--;
		}
		catch (InheritedException a)
		{
			cerr << a.What() << endl << endl;
		}
		catch (InheritedException* a)//
		{
			cerr << a->What() << endl << endl;
		}
	}
	catch (logic_error a)
	{
		cerr << "Exception: " << a.what() << endl;
	}

	TrianglePrivate N2(4, 2, 5);

	try
	{
		N2++;
	}
	catch (Exception& a)//
	{
		cerr << "Exception: " << a.What() << endl;
	}
	catch (out_of_range a)
	{
		cerr << "Exception: " << a.what() << endl;
	}

	try
	{
		Call_Bad();
	}
	catch (bad_exception)
	{
		cerr << "catch (bad_exception)" << endl;
	}
	system("pause");
}