#include "pch.h"
#include "CppUnitTest.h"
#include "../lab11.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double t = averagePlus("D:\\Patiuk\AP\\lab_2\\labs11\\lab11.1\\1.dat");
			Assert::AreEqual(t, 2.6);
		}
	};
}
