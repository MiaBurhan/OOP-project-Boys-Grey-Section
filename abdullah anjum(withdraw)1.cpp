#include <iostream>
using namespace std;
class BankAccount {
private:
    int accountNumber;
    string accountHolder;
    double balance;

public:
    BankAccount(int accNo, string name, double bal) {
        accountNumber = accNo;
        accountHolder = name;
        balance = bal;
    }

    void displayDetails() {
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nAccount Holder: " << accountHolder;
        cout << "\nCurrent Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid amount! Enter a positive value.\n";
        }
        else if (amount > balance) {
            cout << "Insufficient Balance! Withdrawal Failed.\n";
        }
        else {
            balance -= amount;
            cout << "Withdrawal Successful! Rs. " << amount << " withdrawn.\n";
            cout << "Remaining Balance: " << balance << endl;
        }
    }
};

int main() {
    int accNo;
    string name;
    double initialBalance, withdrawAmount;
    cout << "Enter Account Number: ";
    cin >> accNo;
    cin.ignore(); 
    cout << "Enter Account Holder Name: ";
    getline(cin, name);
    cout << "Enter Initial Balance: ";
    cin >> initialBalance;
    BankAccount account(accNo, name, initialBalance);
    account.displayDetails();
    cout << "\nEnter Amount to Withdraw: ";
    cin >> withdrawAmount;
    account.withdraw(withdrawAmount);

    return 0;
}

