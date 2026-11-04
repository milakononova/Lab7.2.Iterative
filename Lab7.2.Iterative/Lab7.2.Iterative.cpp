
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int** a, const int rowCount,
    const int colCount, const int Low, const int High);

void Print(int** a, const int rowCount,
    const int colCount);

int SumMaxOdd(int** a, const int rowCount,
    const int colCount);

int main()
{
    srand((unsigned)time(NULL));

    const int Low = -20;
    const int High = 20;

    const int rowCount = 5;
    const int colCount = 6;

    int** a = new int* [rowCount];

    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, Low, High);

    cout << "Matrix:" << endl;
    Print(a, rowCount, colCount);

    int sum = SumMaxOdd(a, rowCount, colCount);

    cout << "Sum = " << sum << endl;

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];

    delete[] a;

    return 0;
}

void Create(int** a, const int rowCount,
    const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount,
    const int colCount)
{
    cout << endl;

    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(5) << a[i][j];

        cout << endl;
    }

    cout << endl;
}

int SumMaxOdd(int** a, const int rowCount,
    const int colCount)
{
    int sum = 0;

    for (int j = 0; j < colCount; j += 2)
    {
        int maxElement = a[0][j];

        for (int i = 1; i < rowCount; i++)
        {
            if (a[i][j] > maxElement)
                maxElement = a[i][j];
        }

        sum += maxElement;
    }

    return sum;
}
