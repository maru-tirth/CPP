#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    for (int i = 0; i < 10; i++)
    {
        // Write data in file
        ofstream fout;
        fout.open("file.txt", ios::app);
        fout << i << endl;
        fout.close();
    }
    // Read data from file
    string str1;
    ifstream fin("file.txt");
    while (getline(fin, str1))
    {
        cout << str1 << endl;
    }
    fin.close();
    return 0;
}