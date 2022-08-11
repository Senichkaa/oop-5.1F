#include "pch.h"
#include "CppUnitTest.h"
#include "../oop 5.1F/Exception.cpp"
#include "../oop 5.1F/InheritedException.cpp"
#include "../oop 5.1F/Triad.cpp"
#include "../oop 5.1F/TrianglePublic.cpp"
#include "../oop 5.1F/TrianglePrivate.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UToop51F
{
	TEST_CLASS(UToop51F)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			TrianglePrivate T(3, 4, 5);
			Assert::AreEqual(T.Square(), 6.0);
		}
	};
}
