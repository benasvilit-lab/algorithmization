#include "pch.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication2/ConsoleApplication2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests1
{
    TEST_CLASS(UnitTest1) 
    {
    public:

    TEST_METHOD(TestMethod1) {
        std::vector<int> s = { 1, 2, 3 };
        Assert::IsTrue(find_in_stack(s, 2));
    }

    TEST_METHOD(TestMethod2) {
        std::vector<int> s = { 1, 2, 3 };
        Assert::IsFalse(find_in_stack(s, 5));
    }
    };
}
