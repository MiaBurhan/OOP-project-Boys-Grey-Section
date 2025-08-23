#include <iostream>
using namespace std;

class Account {
public:
    int accNo;
    string name;
    double balance;

    void show() {
        cout << accNo << " | " << name << " | " << balance << endl;
    }
};

class Admin {
    string user="admin", pass="123";
    Account a[3];
public:
    Admin() {
        a[0]={1001,"Ali",50000};
        a[1]={1002,"Burhan",25000};
        a[2]={1003,"Qasim",150000};
    }
    bool login(string u,string p){ return u==user && p==pass; }
    void view() {
        cout<<"AccNo | Name | Balance\n";
        for(int i=0;i<3;i++) a[i].show();
    }
    void report() {
        double total=0;
        for(int i=0;i<3;i++) total+=a[i].balance;
        cout<<"Total Accounts: 3\nTotal Balance : "<<total<<endl;
    }
};

int main() {
    Admin ad; string u,p;
    cout<<"Login\nUser: "; cin>>u;
    cout<<"Pass: "; cin>>p;
    if(ad.login(u,p)) {
        int ch;
        do {
            cout<<"\n1.View\n2.Report\n3.Exit\nChoice: ";
            cin>>ch;
            if(ch==1) ad.view();
            else if(ch==2) ad.report();
        }while(ch!=3);
    } else cout<<"Wrong Login!\n";
}
