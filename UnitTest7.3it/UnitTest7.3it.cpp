#include "pch.h"
#include "CppUnitTest.h"
#include "../LB7.3it/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            const int size = 3;

            int** a = new int* [size];

            for (int i = 0; i < size; i++)
                a[i] = new int[size];


            a[0][0] = 1; a[0][1] = 0; a[0][2] = 3;
            a[1][0] = 4; a[1][1] = 5; a[1][2] = 6;
            a[2][0] = 7; a[2][1] = 8; a[2][2] = 9;

            int result = sumAboveMainDiagonal(a, size);

            Assert::AreEqual(9, result);
        }
    };
}
