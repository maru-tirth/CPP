#include <iostream>
using namespace std;

// Template function
template <class T>
class addition {
    public :
    T add(T a, T b)
    {
        return a + b;
    }
};

int main()
{
    addition<int> a;
    cout << a.add(10, 20) << endl;

    addition<float> b;
    cout << b.add(10.5, 20.5) << endl;

    return 0;
}