#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream fwrite("alphabets.txt");
    fwrite << "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    fwrite.close();

    ifstream fread("alphabets.txt");
    ofstream fwrite1("vowels.txt");
    ofstream fwrite2("consonants.txt");

    char c;

    while (fread)
    {
        fread.get(c);
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            fwrite1 << c;
        else
            fwrite2 << c;
    }

    fread.close();
    fwrite1.close();
    fwrite2.close();

    return 0;
}