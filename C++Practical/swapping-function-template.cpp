#include<iostream>
using namespace std;
template<class A>
void Swap(A &a, A &b)
{
    A temp;
    temp = a;
    a = b;
    b = temp;
}
int main()
{
    int a = 10, b = 20;
    cout << "\nBefore swapping: a = " << a << " b = " << b << endl;
    Swap(a, b);
    cout << "After swapping: a = " << a << " b = " << b << endl;

    float c = 10.5, d = 20.5;
    cout << "\nBefore swapping: c = " << c << " d = " << d << endl;
    Swap(c, d);
    cout << "After swapping: c = " << c << " d = " << d << endl;

    string e = "Hello", f = "World";
    cout << "\nBefore swapping: e = " << e << " f = " << f << endl;
    Swap(e, f);
    cout << "After swapping: e = " << e << " f = " << f << endl;
    return 0;
}