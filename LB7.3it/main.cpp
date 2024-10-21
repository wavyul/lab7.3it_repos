#include <iostream>
#include <iomanip>
#include <time.h>
#include <Windows.h>

using namespace std;

void Create(int** a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int size)
{
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

bool isLocalMin(int** a, int i, int j, int size)
{
    int current = a[i][j];
    for (int x = i - 1; x <= i + 1; x++)
    {
        for (int y = j - 1; y <= j + 1; y++)
        {
            if (x >= 0 && x < size && y >= 0 && y < size)
            {
                if (x == i && y == j)
                    continue; // Пропускаємо сам елемент
                if (a[x][y] <= current)
                    return false;
            }
        }
    }
    return true;
}

void countLocalMinima(int** a, const int size)
{
    int count = 0;
    for (int i = 1; i < size - 1; i++)
    {
        for (int j = 1; j < size - 1; j++)
        {
            if (isLocalMin(a, i, j, size))
            {
                count++;
            }
        }
    }
    cout << "Кількість локальних мінімумів: " << count << endl;
}

int sumAboveMainDiagonal(int** a, const int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            sum += abs(a[i][j]);
        }
    }
    return sum;
}

int main()
{
    srand((unsigned)time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int Low = -10;
    int High = 10;
    int size;
    cout << "n = ";
    cin >> size;

    int** a = new int* [size];

    for (int i = 0; i < size; i++)
        a[i] = new int[size];

    Create(a, size, Low, High);
    Print(a, size);

    countLocalMinima(a, size);

    int sum = sumAboveMainDiagonal(a, size);
    cout << "Сума модулів елементів вище головної діагоналі: " << sum << endl;

    for (int i = 0; i < size; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
