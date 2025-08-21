#include <iostream>
using namespace std;

class AccountType {
public:
    void showTypes() {
        cout << "----------------------------------" << endl;
        cout << "       Available Account Types     " << endl;
        cout << "----------------------------------" << endl;
        cout << "1. Savings Account" << endl;
        cout << "2. Current Account" << endl;
        cout << "3. Business / Student Account" << endl;
        cout << "----------------------------------" << endl;
    }
};

int main() {
    cout << "Bank Management System Module" << endl;
    cout << "Developed by: Abdullah Laal" << endl;
    cout << "----------------------------------" << endl;

    AccountType obj1;
    obj1.showTypes();

    return 0;
}
