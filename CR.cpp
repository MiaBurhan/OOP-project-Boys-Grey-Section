#include <iostream>
using namespace std;

int main() {
    long double Amount = 0;
    long double Gold = 0;
    long double Silver = 0;

    const long double goldPrice = 300000.0L;   
    const long double silverPrice = 10000.0L;

    int age;
    int religion;
    int yearsHeld;

    cout << "\t\t\t\t=====================================\t\t\t\n";
    cout << "ENTER YOUR RELIGION (1 FOR MUSLIM, 2 FOR NON-MUSLIM): ";
    cin >> religion;

    if (religion != 1 && religion != 2) {
        cout << "INVALID RELIGION INPUT" << endl;
        return 0;
    }

    if (religion == 2) {
        cout << "ZAKAT IS NOT APPLICABLE TO YOUR ASSETS" << endl;
        return 0;
    }

    cout << "ENTER YOUR AGE: ";
    cin >> age;

    if (age < 18) {
        cout << "ZAKAT IS NOT APPLICABLE TO YOUR ASSETS" << endl;
        return 0;
    }

    cout << "ENTER HOW MANY YEARS YOU HAVE HELD THESE ASSETS: ";
    cin >> yearsHeld;

    if (yearsHeld < 1) {
        cout << "ZAKAT IS NOT APPLICABLE BECAUSE ASSETS HAVE NOT BEEN HELD FOR AT LEAST 1 YEAR" << endl;
        return 0;
    }

    cout << "SELECT YOUR ASSET TYPE:" << endl;
    cout << "1. CASH" << endl;
    cout << "2. GOLD" << endl;
    cout << "3. SILVER" << endl;
    cout << "Enter your choice (1-3): ";

    int assetType;
    cin >> assetType;

    if (assetType < 1 || assetType > 3) {
        cout << "INVALID ASSET TYPE! PLEASE ENTER 1, 2, OR 3." << endl;
        return 0;
    }

    if (assetType == 1) {
        cout << "ENTER YOUR CASH AMOUNT: ";
        cin >> Amount;
    } 
    else if (assetType == 2) {
        cout << "ENTER AMOUNT OF GOLD (IN TOLA): ";
        cin >> Gold;
        Amount = Gold * goldPrice;
    } 
    else if (assetType == 3) {
        cout << "ENTER AMOUNT OF SILVER (IN TOLA): ";
        cin >> Silver;
        Amount = Silver * silverPrice;
    }

    long double goldNisab = 52 * goldPrice;
    long double silverNisab = 52 * silverPrice;

    if (Amount >= goldNisab || Amount >= silverNisab) {
        long double zakat = Amount * 0.025L;
        cout << "\nZAKAT APPLICABLE ON YOUR ASSETS" << endl;
        cout << "TOTAL ASSET VALUE: " << Amount << endl;
        cout << "ZAKAT TO PAY (2.5%): " << zakat << endl;
    } 
    else {
        cout << "\nZAKAT IS NOT APPLICABLE TO YOUR ASSETS AS THEY DO NOT MEET NISAB THRESHOLD" << endl;
        cout << "Gold Nisab: " << goldNisab << endl;
        cout << "Silver Nisab: " << silverNisab << endl;
    }

    return 0;
}
