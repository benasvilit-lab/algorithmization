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
            std::stack<int> s;
            s.push(1);
            s.push(2);
            s.push(3);
            Assert::IsTrue(find_in_stack(s, 2));
        }

        TEST_METHOD(TestMethod2) {
            std::stack<int> s;
            s.push(1);
            s.push(2);
            s.push(3);
            Assert::IsFalse(find_in_stack(s, 5));
        }

        TEST_METHOD(TestMethod3) {
            std::stack<int> s;
            s.push(100); 
            s.push(200);
            Assert::IsTrue(find_in_stack(s, 100));
        }
    };
}