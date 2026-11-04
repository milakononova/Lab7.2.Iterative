
#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern int SumMaxOdd(int** a, const int rowCount,
    const int colCount);

namespace Lab72IterativeTests
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestSumMaxOdd)
        {
            const int rowCount = 3;
            const int colCount = 5;

            int row0[] = { 5, 2, 8, 4, 1 };
            int row1[] = { 9, 3, 4, 7, 5 };
            int row2[] = { 1, 8, 12, 3, 6 };

            int* a[] = { row0, row1, row2 };

            int result = SumMaxOdd(a, rowCount, colCount);

            Assert::AreEqual(27, result);
        }
    };
}
