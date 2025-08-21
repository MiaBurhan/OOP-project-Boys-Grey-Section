#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Account {
private:
    int accountNo;
    string name;
    string cnic;
public:
    Account(int accNo=0,string n="",string c=""){
    accountNo=accNo;
    name=n;
    cnic=c;
    }
    ~Account(){ 
	}    
    int getAccountNo(){
	return accountNo;
	}
    string getName(){
	return name; 
	}
    string getCnic(){
	return cnic; 
	}
    void display(){
    cout<<"\n--- Account Details ---\n";
    cout<<"Account No:"<<accountNo<<endl;
    cout<<"Name:"<<name<<endl;
    cout<<"CNIC:"<<cnic<<endl;
    }
};
class Bank {
private:
    vector<Account>accounts;
public:
    void addAccount(int accNo,string name,string cnic){
    accounts.push_back(Account(accNo,name,cnic));
    cout<<"Account added successfully!\n";
    }
    void searchByAccountNo(int accNo) {
    for(size_t i=0;i<accounts.size();i++){
    if(accounts[i].getAccountNo()==accNo){
    accounts[i].display();
    return;
    }
    }
    cout<<"Account not found.\n";
    }
    void searchByName(string name){
    for(size_t i=0;i<accounts.size();i++){
    if(accounts[i].getName()==name){
    accounts[i].display();
    return;
    }
    }
    cout << "Account not found.\n";
    }
    void searchByCnic(string cnic){
    for(size_t i=0;i<accounts.size();i++){
    if(accounts[i].getCnic()==cnic) {
    accounts[i].display();
    return;
            }
    }
    cout<<"Account not found.\n";
    }
};
int main() {
    Bank bank;
    int choice;
    do{
    cout << "\n--- Bank Management System ---\n";
    cout<<"1. Add Account\n";
    cout<<"2. Search by Account Number\n";
    cout<<"3. Search by Name\n";
    cout<<"4. Search by CNIC\n";
    cout<<"0. Exit\n";
    cout<<"Enter choice: ";
    cin>>choice;
    switch(choice) {
    case 1:{
    int accNo;
    string name,cnic;
    cout<<"Enter Account Number: ";
    cin>>accNo;
    cout<<"Enter Name: ";
    cin>>name;
    cout<<"Enter CNIC: ";
    cin>>cnic;
    bank.addAccount(accNo,name,cnic);
    break;
    }
    case 2:{
    int accNo;
    cout<<"Enter Account Number: ";
    cin>>accNo;
    bank.searchByAccountNo(accNo);
    break;
    }
    case 3:{
    string name;
    cout<<"Enter Name:";
    cin>>name;
    bank.searchByName(name);
    break;
    }
    case 4:{
    string cnic;
    cout<<"Enter CNIC:";
    cin>>cnic;
    bank.searchByCnic(cnic);
    break;
    }
    case 0:
    cout<<"Exiting...\n";
    break;
    default:
    cout<<"Invalid choice!\n";
    }
    }
	while(choice!=0);
    return 0;
}

