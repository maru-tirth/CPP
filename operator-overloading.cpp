#include <iostream>
using namespace std;

class Complex
{
    int real, img;

public:
    Complex() {}

    Complex(int real, int img)
    {
        this->real = real;
        this->img = img;
    }

    void display()
    {
        cout << real << " + i" << img << endl;
    }

    Complex operator+(Complex &c)
    {
        Complex ans;
        ans.real = real + c.real;
        ans.img = img + c.img;
        return ans;
    }
};

int main()
{
    Complex c1(10, 20);
    c1.display();
    Complex c2(30, 40);
    c2.display();
    Complex c3 = c1 + c2;
    c3.display();
    return 0;
}