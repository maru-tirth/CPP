#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    try
    {
        if (b == 0)
            throw "Division by zero is not possible\n";
        int c = a / b;
        cout << c << endl;
    }
    catch (const char *err)
    {
        cout << "Error Occured: " << err;
    }
}

// if(b==0)
// {
//     cout<<"Division by zero is not possible\n";
//     return 0;
// }