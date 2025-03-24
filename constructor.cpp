#include <iostream>
using namespace std;
// COMMON USE OF CONSTRUCTORS

// class Demo
// {
//     string name;
//     int age;
// public:
//     // Default constructor
//     Demo()
//     {
//         name = "John";
//         age = 25;
//     }
//     // Parameterized constructor
//     Demo(string n, int a)
//     {
//         name = n;
//         age = a;
//     }
//     // Copy constructor
//     Demo(Demo &a)
//     {
//         name = a.name;
//         age = a.age;
//     }
//     void display()
//     {
//         cout << "Name: " << name << endl;
//         cout << "Age: " << age << endl;
//     }
//     ~Demo()
//     {
//         cout << "\nDestructor called" << endl;
//     }
// };

// int main()
// {
//     Demo d1;
//     Demo d2("Robert", 30);
//     Demo d3 = d2;
//     cout << "Object 1: " << endl;
//     d1.display();
//     cout << "\nObject 2: " << endl;
//     d2.display();
//     cout << "\nObject 3: " << endl;
//     d3.display();
//     return 0;
// }

// ADDITION OF TWO INTEGERS

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
//     // Default constructor
//     Complex() {}
//     // Parameterized constructor
//     Complex(int a, int b)
//     {
//         real = a;
//         img = b;
//     }
//     void showData()
//     {
//         cout << real << " + " << img << "i" << endl;
//     }
//     // Function to add two complex numbers
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
//     Complex C1(3, 4);
//     C1.showData();
//     Complex C2(5, 6);
//     C2.showData();
//     Complex C3;
//     C3 = C1.sum(C2);
//     C3.showData();
//     return 0;
// }