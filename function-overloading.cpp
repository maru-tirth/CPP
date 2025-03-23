#include <iostream>
using namespace std;

// Function overloading example
class Calculator
{
public:
    // Add two integers
    int add(int a, int b)
    {
        return a + b;
    }

    // Add three integers
    int add(int a, int b, int c)
    {
        return a + b + c;
    }

    // Add two floating-point numbers
    double add(double a, double b)
    {
        return a + b;
    }
};

int main()
{
    Calculator calc;
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;
    cout << "Addition of two integers: " << calc.add(a, b) << endl;
    cout << "Addition of three integers: " << calc.add(5, 10, 15) << endl;
    cout << "Addition of two doubles: " << calc.add(5.5, 10.5) << endl;

    return 0;
}