#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    static int nextAccountNumber;
    static int totalAccounts;
    static double totalBankBalance;

public:
    int accountNumber;
    string name;
    string phone;
    string dob;
    string type;
    double balance;
    int mpin;
    bool isBlocked;

    Account() {
        accountNumber = 0;
        isBlocked = false;
        balance = 0;
        mpin = 0;
    }

    void createAccount() {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Phone Number: ";
        getline(cin, phone);
        cout << "Enter Year of Birth (YYYY): ";
        getline(cin, dob);

        cout << "Set M-PIN: ";
        int pin, confirmPin;
        cin >> pin;
        cout << "Confirm M-PIN: ";
        cin >> confirmPin;

        if (pin != confirmPin) {
            cout << "M-PIN mismatch. Account creation failed.\n";
            return;
        }

        cout << "Enter Initial Deposit (Minimum 3000): ";
        cin >> balance;

        if (balance < 3000) {
            cout << "Initial deposit must be at least 3000.\n";
            return;
        }

        mpin = pin;
        accountNumber = nextAccountNumber++;
        totalAccounts++;
        totalBankBalance += balance;

        type = (2025 - stoi(dob) < 18) ? "Minor" : "Adult";
        cout << "Account Created Successfully! Account Number: " << accountNumber << endl;
    }

    static int getTotalAccounts() { return totalAccounts; }
    static double getTotalBankBalance() { return totalBankBalance; }

    bool validateMpin(int inputPin) {
        return inputPin == mpin;
    }

    void deposit(double amount) {
        balance += amount;
        totalBankBalance += amount;
        cout << "Amount deposited. Current Balance: " << balance << endl;
    }

    bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            totalBankBalance -= amount;
            cout << "Withdrawal successful. Current Balance: " << balance << endl;
            return true;
        }
        cout << "Insufficient balance.\n";
        return false;
    }

    bool resetMpin(int oldPin, int newPin, int confirmPin) {
        if (mpin != oldPin) {
            cout << "Old M-PIN is incorrect.\n";
            return false;
        }
        if (newPin != confirmPin) {
            cout << "M-PIN confirmation mismatch.\n";
            return false;
        }
        mpin = newPin;
        cout << "M-PIN reset successfully.\n";
        return true;
    }

    bool deleteAccount(int inputMpin, string inputName) {
        if (mpin != inputMpin || name != inputName) {
            cout << "M-PIN or Name mismatch. Deletion failed.\n";
            return false;
        }
        cout << "Account Deleted Successfully.\n";
        totalAccounts--;
        totalBankBalance -= balance;
        return true;
    }

    void blockAccount() {
        isBlocked = true;
        cout << "Account blocked due to multiple failed attempts.\n";
    }

    string getName() { return name; }
    int getAccountNumber() { return accountNumber; }
    bool getBlockedStatus() { return isBlocked; }
};

int Account::nextAccountNumber = 1001;
int Account::totalAccounts = 0;
double Account::totalBankBalance = 0.0;

const int MAX_ACCOUNTS = 100;
Account accounts[MAX_ACCOUNTS];

Account* searchAccount(int accNo) {
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        if (accounts[i].getAccountNumber() == accNo) {
            return &accounts[i];
        }
    }
    return nullptr;
}

void userMenu() {
    int choice;
    do {
        cout << "\nUser Menu:\n"
             << "1. Create Account\n2. Deposit Money\n3. Withdraw Money\n"
             << "4. Reset M-PIN\n5. Delete Account\n6. Exit\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            for (int i = 0; i < MAX_ACCOUNTS; i++) {
                if (accounts[i].getAccountNumber() == 0) {
                    accounts[i].createAccount();
                    break;
                }
            }
        } else if (choice == 2) {
            int accNo, pin, tries = 3;
            double amount;
            cout << "Enter Account Number: ";
            cin >> accNo;
            Account* acc = searchAccount(accNo);
            if (!acc) { cout << "Account not found.\n"; continue; }
            if (acc->getBlockedStatus()) { cout << "Account is blocked.\n"; continue; }

            cout << "Hello, " << acc->getName() << endl;
            while (tries--) {
                cout << "Enter M-PIN: ";
                cin >> pin;
                if (acc->validateMpin(pin)) {
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    acc->deposit(amount);
                    break;
                } else {
                    cout << "Incorrect M-PIN.\n";
                    if (tries == 0) acc->blockAccount();
                }
            }
        } else if (choice == 3) {
            int accNo, pin, tries = 3;
            double amount;
            cout << "Enter Account Number: ";
            cin >> accNo;
            Account* acc = searchAccount(accNo);
            if (!acc) { cout << "Account not found.\n"; continue; }
            if (acc->getBlockedStatus()) { cout << "Account is blocked.\n"; continue; }

            cout << "Hello, " << acc->getName() << endl;
            while (tries--) {
                cout << "Enter M-PIN: ";
                cin >> pin;
                if (acc->validateMpin(pin)) {
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    acc->withdraw(amount);
                    break;
                } else {
                    cout << "Incorrect M-PIN.\n";
                    if (tries == 0) acc->blockAccount();
                }
            }
        } else if (choice == 4) {
            int accNo, oldPin, newPin, confirmPin;
            cout << "Enter Account Number: ";
            cin >> accNo;
            Account* acc = searchAccount(accNo);
            if (!acc) { cout << "Account not found.\n"; continue; }

            cout << "Enter Old M-PIN: ";
            cin >> oldPin;
            cout << "Enter New M-PIN: ";
            cin >> newPin;
            cout << "Confirm New M-PIN: ";
            cin >> confirmPin;
            acc->resetMpin(oldPin, newPin, confirmPin);
        } else if (choice == 5) {
            int accNo, pin;
            string name;
            cout << "Enter Account Number: ";
            cin >> accNo;
            Account* acc = searchAccount(accNo);
            if (!acc) { cout << "Account not found.\n"; continue; }

            cout << "Enter Account Holder Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter M-PIN: ";
            cin >> pin;

            if (acc->deleteAccount(pin, name)) {
                acc->accountNumber = 0;  // Mark the slot as free
            }
        }
    } while (choice != 6);
}

void staffMenu() {
    string staffCode;
    cout << "Enter Staff Code: ";
    cin >> staffCode;
    if (staffCode != "MPB2025") {
        cout << "Invalid Staff Code!\n";
        return;
    }
    int choice;
    cout << "1. View Total Accounts\n2. View Total Bank Balance\nEnter your choice: ";
    cin >> choice;
    if (choice == 1) {
        cout << "Total Accounts: " << Account::getTotalAccounts() << endl;
    } else if (choice == 2) {
        cout << "Total Bank Balance: " << Account::getTotalBankBalance() << endl;
    } else {
        cout << "Invalid choice.\n";
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\n=== Welcome to Account Management System ===\n";
        cout << "1. User\n2. Bank Staff\n3. Exit\nEnter your choice: ";
        cin >> choice;
        if (choice == 1) userMenu();
        else if (choice == 2) staffMenu();
        else if (choice == 3) break;
        else cout << "Invalid choice!\n";
    }
    return 0;
}
