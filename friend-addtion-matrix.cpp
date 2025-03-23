#include <iostream>
using namespace std;

class matrix2;
class matrix1
{
    int a[3][3];

public:
    void getData()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> a[i][j];
            }
        }
    }

    void showData()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << a[i][j] << " ";
                cout << endl;
            }
        }
    }
    friend void sum(matrix1, matrix2);
};

class matrix2
{
    int a[3][3];

public:
    void getData()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> a[i][j];
            }
        }
    }

    void showData()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << a[i][j] << " ";
                cout << endl;
            }
        }
    }
    friend void sum(matrix1, matrix2);
};

void sum(matrix1 m1, matrix2 m2)
{
    int a[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            a[i][j] = m1.a[i][j] + m2.a[i][j];
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    matrix1 m1;
    cout << "Enter the elements of first matrix: " << endl;
    m1.getData();
    matrix2 m2;
    cout << "Enter the elements of second matrix: " << endl;
    m2.getData();
    cout << "The sum of the two matrices is: " << endl;
    sum(m1, m2);
    return 0;
}