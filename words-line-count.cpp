#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fread("words.txt");
    int wc = 1, lc = 1;

    char c;
    while (fread)
    {
        fread.get(c);
        if (c == ' ' || c == '\n')
            wc++;
        if (c == '\n')
            lc++;
    }
    fread.close();
    cout << "Number of words: " << wc << endl;
    cout << "Number of lines: " << lc << endl;

    return 0;
}