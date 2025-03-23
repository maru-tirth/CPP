#include <iostream>
using namespace std;

class Customer
{
    string name;
    int balance, account_number;

public:
    Customer(string name, int balance, int account_number)
    {
        this->name = name;
        this->balance = balance;
        this->account_number = account_number;
    };
    // Deposit
    void deposit(int amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << amount << "₹ is credited successfully \n";
            cout << "Updated balance: " <<"₹"<<balance <<endl;
        }
        else
        {
            throw "Invalid amount\n";
        }
    }
    // Widthdraw
    void widthdraw(int amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << amount << "₹ is debited successfully \n";
            cout << "Updated balance: " <<"₹"<<balance <<endl;
        }
        else if (amount < 0)
        {
            throw "Invalid amount\n";
        }
        else
        {
            throw "Insufficient balance\n";
        }
    }
};

int main()
{
    Customer C1("John", 5000, 123456);
    try
    {
        C1.deposit(100);
        C1.widthdraw(6000);
        C1.deposit(100);
    }
    catch(const char*err)
    {
        cout << "Error: " << err<<endl;
    }
}