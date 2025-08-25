#include <iostream>
#include <vector>
#include <string>
#include <iomanip>



using namespace std;

class user{
	protected: 
	    string userName;
	    string password;
	    bool isAdmin;
	
	public:
		user() { userName = ""; password = ""; isAdmin = false; }
		user(string u, string p, bool admin=false) { userName = u; password = p; isAdmin = admin; }
		
		void setData(string uName, string pass, bool admin=false){
			userName = uName;
			password = pass;
			isAdmin = admin;
		}
		string getUserName () { return userName; }
		string getPass(){ return password; }
		bool getIsAdmin() { return isAdmin; }	
};

struct product {
	int id;
    string name;
    double price;
    int stock;     
};

class store {
	protected:
		static const int maxProducts = 15;
		product products[maxProducts];
		int productCount;
    public:
    	store(): productCount(0) { defaultProducts(); } 
    	
    	void defaultProducts() {		
	        products[productCount++] = {1, "RTX 4060 8GB", 91000.0, 5};
	        products[productCount++] = {2, "Ryzen 5 5600", 41000.0, 10};
	        products[productCount++] = {3, "Corsair 16GB DDR4", 14000.0, 20};
	        products[productCount++] = {4, "Samsung 980 1TB", 18000.0, 15};
        }
       
    	void browseProducts() {
	        cout << "\n--- Available Products ---\n";
	        cout << left << setw(4) << "ID" << setw(25) << "Name" 
	             << setw(10) << "Price" << setw(6) << "Stock" << "\n";
	        for (int i = 0; i < productCount; ++i) {
	            cout << left << setw(4) << products[i].id
	                 << setw(25) << products[i].name
	                 << setw(10) << products[i].price
	                 << setw(6) << products[i].stock << "\n";
	        }
	    }

	    void addProduct() {
	        if (productCount >= maxProducts) {
	            cout << "Cannot add more products. Store full!\n";
	            return;
	        }
	        string name;
	        double price;
	        int stock;
	        cout << "Enter product name: ";
	        cin.ignore(); 
	        getline(cin, name);
	        cout << "Enter price: ";
	        cin >> price;
	        cout << "Enter stock quantity: ";
	        cin >> stock;
	        products[productCount].id = productCount + 1; 
	        products[productCount].name = name;
	        products[productCount].price = price;
	        products[productCount].stock = stock;
	        productCount++;
	        cout << "Product added successfully!\n";
	    }
	    
	    void removeProduct() {
		    int id;
		    cout << "Enter Product ID to remove: ";
		    cin >> id;
		    int idx = -1;
		    for (int i = 0; i < productCount; i++) {
		        if (products[i].id == id) { idx = i; break; }
		    }
		    if (idx == -1) { cout << "Product not found!\n"; return; }
		    for (int i = idx; i < productCount - 1; i++) { products[i] = products[i + 1]; }
		    productCount--; 
		    cout << "Product removed successfully!\n";
	    }
	    
	    void updateProduct() {
		    int id;
		    cout << "Enter Product ID to update: ";
		    cin >> id;
		    int idx = -1;
		    for (int i = 0; i < productCount; i++) {
		        if (products[i].id == id) { idx = i; break; }
		    }
		    if (idx == -1) { cout << "Product not found!\n"; return; }
		    cout << "1) Update price\n2) Update stock\nChoice: ";
		    int choice;
		    cin >> choice;
		    if (choice == 1) {
		        double newPrice;
		        cout << "Enter new price: "; cin >> newPrice;
		        products[idx].price = newPrice;
		        cout << "Price updated.\n";
		    } else if (choice == 2) {
		        int newStock;
		        cout << "Enter new stock: "; cin >> newStock;
		        products[idx].stock = newStock;
		        cout << "Stock updated.\n";
		    } else { cout << "Invalid choice.\n"; }
	    }

	    void purchaseProduct() {
		    int id, qty;
		    cout << "Enter Product ID to purchase: "; cin >> id;
		    cout << "Enter Quantity: "; cin >> qty;
		    int idx = -1;
		    for (int i = 0; i < productCount; i++) { if (products[i].id == id) { idx = i; break; } }
		    if (idx == -1) { cout << "Product not found!\n"; return; }
		    if (qty <= 0 || qty > products[idx].stock) {
		        cout << "Invalid quantity. Available stock: " << products[idx].stock << "\n"; return;
		    }
		    double total = qty * products[idx].price;
		    products[idx].stock -= qty;
		    cout << "Purchase successful!\nProduct: " << products[idx].name << "\nQuantity: " << qty << "\nTotal Price: Rs. " << total << "\n";
	    }

	    void searchProductByName() {
		    string query;
		    cout << "Enter product name or keyword to search: ";
		    cin.ignore();
		    getline(cin, query);
		    bool found = false;
		    cout << "\n--- Search Results ---\n";
		    for (int i = 0; i < productCount; i++) {
		        if (products[i].name.find(query) != string::npos) {
		            cout << "ID: " << products[i].id << " | Name: " << products[i].name 
		                 << " | Price: Rs. " << products[i].price << " | Stock: " << products[i].stock << "\n";
		            found = true;
		        }
		    }
		    if (!found) { cout << "No products found matching \"" << query << "\".\n"; }
	    }
};

// ---------------- Admin ----------------
class Admin : public user {
public:
	store s;
	Admin(string u, string p) : user(u, p, true) {}
	void menu() {
	    int choice;
	    while(true) {
	        cout << "\n[Admin Menu - " << userName << "]\n";
	        cout << "1) View products\n2) Add product\n3) Remove product\n4) Update product stock/price\n0) Logout\nEnter choice: ";
	        cin >> choice;
	        switch(choice) {
	            case 1: s.browseProducts(); break;
	            case 2: s.addProduct(); break;
	            case 3: s.removeProduct(); break;
	            case 4: s.updateProduct(); break;
	            case 0: return;
	            default: cout << "Invalid! Try again.\n"; break;
	        }
	    }
	}
};

// ---------------- Customer ----------------
class Customer : public user {
public:
	store s;
	Customer(string u, string p) : user(u, p, false) {}
	void menu() {
	    int choice;
	    while(true) {
	        cout << "\n[Customer Menu - " << userName << "]\n";
	        cout << "1) View products\n2) Purchase product\n3) Search product by name\n4) Update password\n0) Logout\nEnter choice: ";
	        cin >> choice;
	        switch(choice) {
	            case 1: s.browseProducts(); break;
	            case 2: s.purchaseProduct(); break;
	            case 3: s.searchProductByName(); break;
	            case 4: {
	                string newPass;
	                cin.ignore();
	                cout << "Enter new password: ";
	                getline(cin,newPass);
	                password = newPass;
	                cout << "Password updated.\n";
	                break;
	            }
	            case 0: return;
	            default: cout << "Invalid! Try again.\n"; break;
	        }
	    }
	}
};

// ---------------- Login System ----------------
class loginSystem {
	private:
		static const int maxUsers = 100;
		user users[maxUsers];
		int userCount;
	public:
		loginSystem() {  
	        userCount = 0;
	        users[userCount].setData("admin", "1234", true);
	        userCount++;
		}
		
		void registers() {
			if (userCount < maxUsers) {
				string uName, pass;
				cout << "\nEnter New UserName: "; cin >> uName;
				cout << "Enter New Password: "; cin >> pass;
				users[userCount].setData(uName, pass, false);
				userCount++;
			}
		}
	
	   void login() {
	   	   string uname, pass;
           cout << "Enter username: "; cin >> uname;
           cout << "Enter password: "; cin >> pass;
           bool found = false;
           for (int i = 0; i < userCount; i++) {
                if (users[i].getUserName() == uname && users[i].getPass() == pass) {
                    found = true;
                    cout << "Login successful! Welcome " << uname << endl;
                    if (users[i].getIsAdmin()) {
                        Admin a(uname, pass); a.menu();
                    } else {
                        Customer c(uname, pass); c.menu();
                    }
                    break;
                }
           }
           if (!found) { cout << "Invalid username or password!\n"; }
	   }
};

int main(){
      loginSystem l;
      int choice;
      while (true){
      	cout << "\n=== Computer Components Store (In-memory) ===\n";
        cout << "1) Login\n2) Register (customer)\n0) Exit\nEnter choice: ";
        cin >> choice;
        if (choice == 1)  { l.login(); }
		else if (choice == 2) { l.registers(); }
		else if (choice == 0 ){ cout << "Exiting program...\n"; break; }
		else { cout<<"Invalid Try Again !....\n"; }
	  }
}
