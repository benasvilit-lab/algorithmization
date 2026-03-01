#include "pch.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication5/ConsoleApplication5.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

double square(double x) {
	return x * x;
}
namespace UnitTest3
{
	TEST_CLASS(UnitTest3)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			double result = simpson_rule(square, 0.0, 3.0, 1000);
			Assert::AreEqual(9.0, result, 0.00001, L"Значения не совпали для x^2");
		}
		TEST_METHOD(TestMethod2)
		{
			double r1 = simpson_rule(function2, 5.0, 6.0, 100);
			double r2 = simpson_rule(function2, 5.0, 6.0, 100);
			Assert::AreEqual(r1, r2, 0.00001, L"Результаты одного и того же расчета различаются");
		}
		TEST_METHOD(TestMethod3)
		{
			double result = simpson_rule(function1, 5.0, 5.0, 100);
			Assert::AreEqual(0.0, result, 0.00001, L"Площадь на нулевом интервале должна быть 0");
		}
	};
}
