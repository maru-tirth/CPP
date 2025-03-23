#include <iostream>
using namespace std;
class Coustmer
{
    string name;
    int account_number, balance;
    static int total_coustmer;

public:
    Coustmer(string name, int account_number, int balance)
    {
        this->name = name;
        this->account_number = balance;
        this->balance = balance;
        total_coustmer++;
    }
    void display()
    {
        cout << "\nAccount Holder's Name: " << name << endl;
        cout << "Account Holder's Account Number: " << account_number << endl;
        cout << "Account Holder's Balance: " << balance << endl;
        cout << "Account ID: " << total_coustmer << endl;
    }

    void display_total()
    {
        cout << "\nTotal Coustmer: " << total_coustmer << endl;
    }
};
int Coustmer::total_coustmer = 0;
int main()
{
    Coustmer A1("Rohit", 01, 11000);
    // A1.display();
    Coustmer A2("Mohit", 02, 11000);
    // A2.display();
    Coustmer A3("Ajit", 03, 11000);
    // A3.display();
    A1.display_total();
}