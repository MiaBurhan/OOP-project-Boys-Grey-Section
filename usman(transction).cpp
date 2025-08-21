#include <iostream>
#include <string>
using namespace std;

 
class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
     
    BankAccount(string name, int number, double bal) {
        accountHolder = name;
        accountNumber = number;
        balance = bal;
    }
 
    void display() {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }

     
    double getBalance() {
        return balance;
    }

    
    bool transfer(double amount, BankAccount &receiver) {
        if(amount <= balance) {
            balance -= amount;
            receiver.balance += amount;
            cout<<"your transiction has been completed !"<<endl;
            return true;
        } else {
            cout << "Insufficient balance!" << endl;
            return false;
        }
    }
};

int main() {
    int n;

    cout << "Enter number of accounts: ";
    cin >> n;

    BankAccount* accounts[n];  

     
    for(int i = 0; i < n; i++) {
        string name;
        int number;
        double bal;

        cout << "\nEnter details for account " << i+1 << ":\n";
        cin.ignore();  
        cout << "Name: ";
        getline(cin, name);
        cout << "Account Number: ";
        cin >> number;
        cout << "Initial Balance: $";
        cin >> bal;

        accounts[i] = new BankAccount(name, number, bal);
    }

    int senderIndex, receiverIndex;
    double amount;

    cout << "\nEnter sender account index (1 to " << n << "): ";
    cin >> senderIndex;
    cout << "Enter receiver account index (1 to " << n << "): ";
    cin >> receiverIndex;
    cout << "Enter amount to transfer: $";
    cin >> amount;

    senderIndex--;  
    receiverIndex--;

     
    if(accounts[senderIndex]->transfer(amount, *accounts[receiverIndex])) {
        cout << "\nTransfer successful!\n";
    } else {
        cout << "\nTransfer failed!\n";
    }

    
    cout << "\nUpdated account details:\n";
    for(int i = 0; i < n; i++) {
        cout << "\nAccount " << i+1 << ":\n";
        accounts[i]->display();
    }

    for(int i = 0; i < n; i++) {
        delete accounts[i];
    }

    return 0;
}

