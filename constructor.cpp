#include <iostream>
using namespace std;
// COMMON USE OF CONSTRUCTORS
class Demp
{
    string name;
    int age;

public:
    // Default constructor
    Demp()
    {
        name = "John";
        age = 25;
    }
    // Parameterized constructor
    Demp(string n, int a)
    {
        name = n;
        age = a;
    }
    // Copy constructor
    Demp(Demp &d)
    {
        name = d.name;
        age = d.age;
    }
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

    ~Demp()
    {
        cout << "Destructor called" << endl;
    }
};

int main()
{
    Demp d1;
    Demp d2("Robert", 30);
    Demp d3 = d2;
    cout << "Object 1" << endl;
    d1.display();
    cout << "Object 2" << endl;
    d2.display();
    cout << "Object 3" << endl;
    d3.display();
    return 0;
}

// ADDITION OF TWO NUMBERS

// class Addition
// {
//     int num1, num2, sum;
// public:
//     Addition(int a, int b)
//     {
//         num1 = a;
//         num2 = b;
//         sum = num1 + num2;
//     }
//     void display()
//     {
//         cout << "Sum of " << num1 << " and " << num2 << " is " << sum << endl;
//     };
// };

// int main()
// {
//     int n1, n2;
//     cout << "Enter first number: ";
//     cin >> n1;
//     cout << "Enter second number: ";
//     cin >> n2;
//     Addition a(n1, n2);
//     a.display();
//     return 0;
// }

// ADDITION OF TEO COMPLEX NUMBERS

// class Complex
// {
//     int real, img;
// public:
//     Complex() {}
//     Complex(int a, int b)
//     {
//         real = a;
//         img = b;
//     }
//     void showData()
//     {
//         cout << real << " + " << img << "i" << endl;
//     }
//     Complex sum(Complex C1)
//     {
//         Complex C3;
//         C3.real = real + C1.real;
//         C3.img = img + C1.img;
//         return C3;
//     }
// };

// int main()
// {
//     Complex obj1(3, 4);
//     obj1.showData();
//     Complex obj2(5, 6);
//     obj2.showData();
//     Complex obj3;
//     obj3 = obj1.sum(obj2);
//     obj3.showData();
//     return 0;
// }