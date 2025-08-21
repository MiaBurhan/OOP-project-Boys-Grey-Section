#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    string username;
    string pin;

public:
    Account(string u, string p) {
        username = u;
        pin = p;
    }

    string getUsername() { return username; }
    string getPin() { return pin; }
};

class BankSystem {
private:
    Account accounts[10];
    int accountCount;
    string loggedInUser;

public:
    BankSystem() {
        accountCount = 0;
        loggedInUser = "";
    }

    void addAccount(Account acc) {
        if (accountCount < 10) {
            accounts[accountCount] = acc;
            accountCount++;
        }
    }

    bool login(string username, string pin) {
        for (int i = 0; i < accountCount; i++) {
            if (accounts[i].getUsername() == username && accounts[i].getPin() == pin) {
                loggedInUser = username;
                cout << "Login Successful. Welcome " << username << endl;
                return true;
            }
        }
        cout << "Invalid Username or PIN." << endl;
        return false;
    }

    void logout() {
        if (loggedInUser != "") {
            cout << loggedInUser << " has logged out." << endl;
            loggedInUser = "";
        } else {
            cout << "No user is currently logged in." << endl;
        }
    }
};

int main() {
    BankSystem bank;

    // Add accounts
    bank.addAccount(Account("Saad ", "1234"));
    bank.addAccount(Account("Ali", "5678"));

    string user, pin;
    int choice;

    do {
        cout << "\n1. Login\n2. Logout\n3. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Username: ";
            cin >> user;
            cout << "Enter PIN: ";
            cin >> pin;
            bank.login(user, pin);
        }
        else if (choice == 2) {
            bank.logout();
        }

    } while (choice != 3);

    return 0;
}
