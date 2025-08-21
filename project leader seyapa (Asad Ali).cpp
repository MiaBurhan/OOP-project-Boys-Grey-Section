#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;
class Banking{
	int completed;
	string ID,account;
	struct customer{
		string id,name,father_name,addres;
		double phone,cash,idcard;
	}customer[100];
public:
	Banking(){
		completed=0;
		
	}
	void showoptions();
	void newaccount();
	void display();
	void update();
	void search();
	void transaction();
	void logout();
};

int main(){
 string admin_name,admin_lname;
 int pin,lpin;
 cout<<"\n\n\n\t\t\t\t\t\t BANK MANAGMENT SYSTEM \n\n\n";
 cout<<"-----------------------------------------------------------------------------------------------------------------------";
 cout<<"\n\t\t\t\t\t\t SIGN UP\n";
 cout<<"Enter your name:"<<endl;
 cin>>admin_name;
 cout<<"Enter your pin: "<<endl;
 cin>>pin;
 cout<<"Your account is creating please wait";
 for(int a=0;a<5;a++){
 	cout<<".";
 	Sleep(10);
 }	
 cout<<"\nYour account is created successfully";
 system("CLS");

login:
cout<<"\n\t\t\t\t\t\t LOGIN HERE\n";
cout<<"Enter your Name: ";
cin>>admin_lname;
cout<<"Enter your four digits pin";
cin>>lpin;
if(pin==lpin&&admin_name==admin_lname){
	system("CLS");
	Banking customers;
	customers.showoptions();
	
	
	
}
else if(admin_name!=admin_lname){
	cout<<"Incorect user name or passward please try again";
	goto login;
}
return 0;
}

void Banking::showoptions(){
	char select;
	while(1){
	
cout<<"\nPress 1 for creating New account."<<endl;
cout<<"press 2 displaying the customer Information"<<endl;
cout<<"press 3 for updating custoer information"<<endl;
cout<<"press 4 for searching the specific Customer"<<endl;
cout<<"press 5 for transaction operations like deposit and withdraw"<<endl;
cout<<"press 6 for log out"<<endl;


select=getch();
switch(select){
	case '1':
		system("CLS");
		Banking::newaccount();
		
		break;
	case '2':
		system("CLS");
		Banking::display();
		
		break;
	case '3':
		system("CLS");
		Banking::update();
		
		break;
	case '4':
		system("CLS");
		Banking::search();
		
		break;
	case '5':
		system("CLS");
		Banking::transaction();
		
		break;
	case '6':
		system("CLS");
		Banking::logout();
		
		break;
	
	
		
}
}
}
void Banking::newaccount(){
	cout<<"\n\n\t\t\t\tNEW ACCOUNT CREATING..\t\t\n\n";
	cout<<"Enter the Record "<<completed+1<<"Customer\n";
	cout<<"Enter id";
	cin>>customer[completed].id;
	cout<<"Enter Name";
	cin>>customer[completed].name;
	cout<<"Enter Father Name";
	cin>>customer[completed].father_name;
	cout<<"Enter ID CARD NUMBER";
	cin>>customer[completed].idcard;
	cout<<"Enter Phone Number";
	cin>>customer[completed].phone;
	cout<<"Enter Cash";
	cin>>customer[completed].cash;
	completed++;
}
void Banking::display(){
	for(int i=0;i<completed;i++){
		int b;
		cout<<"Record of "<<b+1<<"Customer"<<endl;
		cout<<"Customer Unique ID: "<<customer[i].id<<endl;
		cout<<"Customer Name: "<<customer[i].name<<endl;
		cout<<"Customer Father Name: "<<customer[i].father_name<<endl;
		cout<<"Customer Phone No: "<<customer[i].phone<<endl;
		cout<<"Customer ID card: "<<customer[i].idcard<<endl;
		cout<<"Customer Amount: "<<customer[i].cash<<endl;
		b++;
	}
}
void Banking::update(){
	cout<<"Enter the id of the customer";
	cin>>ID;
	for(int i=0;i<completed;i++){
		if(ID==customer[i].id){
		cout<<"\n\n\n\t\t\t\tRecord of Existing Customer\t\t\t\n\n\n"<<endl;
		cout<<"Customer Unique ID: "<<customer[i].id<<endl;
		cout<<"Customer Name: "<<customer[i].name<<endl;
		cout<<"Customer Father Name: "<<customer[i].father_name<<endl;
		cout<<"Customer Phone No: "<<customer[i].phone<<endl;
		cout<<"Customer ID card: "<<customer[i].idcard<<endl;
		cout<<"Customer Amount: "<<customer[i].cash<<endl;
		
		
			cout<<"\n\n\t\t\t\tUPDATING THE CUSTOMER RECORD..\t\t\n\n";
	cout<<"\n\t\tEnter the Record Customer\n";
	cout<<"Enter id";
	cin>>customer[i].id;
	cout<<"Enter Name";
	cin>>customer[i].name;
	cout<<"Enter Father Name";
	cin>>customer[i].father_name;
	cout<<"Enter ID CARD NUMBER";
	cin>>customer[i].idcard;
	cout<<"Enter Phone Number";
	cin>>customer[i].phone;
	cout<<"Enter Cash";
	cin>>customer[i].cash;
			
		}
	}
}
void Banking::search(){
	
		cout<<"\n\n\t\tEnter the id --FOR SEARCHING-- the customer\t\t\n\n";
	cin>>ID;
	 bool found = false;
	for(int i=0;i<completed;i++){
		if(ID==customer[i].id){
		cout<<"\n\n\n\t\t\t\tRecord of Existing Customer\t\t\t\n\n\n"<<endl;
		cout<<"Customer Unique ID: "<<customer[i].id<<endl;
		cout<<"Customer Name: "<<customer[i].name<<endl;
		cout<<"Customer Father Name: "<<customer[i].father_name<<endl;
		cout<<"Customer Phone No: "<<customer[i].phone<<endl;
		cout<<"Customer ID card: "<<customer[i].idcard<<endl;
		cout<<"Customer Amount: "<<customer[i].cash<<endl;
		}
	else if(!found){
		cout<<"INVALLIED"<<endl;
		search();
	}
}}
void Banking::transaction(){
	char select;
	double mony;
		cout<<"\n\n\t\tEnter the id --FOR TRANSACTION-- the customer\t\t\n\n";
	cin>>ID;
	    cout<<"Enter Your id"<<endl;
	    cin>>account;
		for(int i=0;i<completed;i++){
			if(ID==customer[i].id){
				cout<<"Customer Unique ID: "<<customer[i].id<<endl;
	        	cout<<"Customer Name: "<<customer[i].name<<endl;
				cout<<"Customer Amount: "<<customer[i].cash<<endl;
				cout<<"\n\n\t\t 1.For Diposit "<<endl;
				cout<<"\n\n\t\t 2.For Withdraw "<<endl;
				select=getch();
		switch(select){
			case '1':
				     cout<<"ENTER AMOUNT FOR DEPOSIT"<<endl;
			        	cin>>mony;
			        cout<<"\n\n\t\t\tYour request is beaing processed";
			         for(int a=0;a<5;a++){
                        	cout<<".";
                        	Sleep(200);
                             }
                    cout<<"TRANSACTION is successful"<<endl;
			        customer[i].cash=customer[i].cash+mony;
			        cout<<"NEW BALANCE IS IN ACCOUNT NUMBER"<<customer[i].id<<"IS  = "<<customer[i].cash;
			        break;
			case '2':
				a:
				     cout<<"ENTER AMOUNT FOR WITHDRAW"<<endl;
			        	cin>>mony;
			       
			        if(mony<=customer[i].cash){
			        
			           cout<<"\n\n\t\t\tYour request is beaing processed";
			         for(int a=0;a<5;a++){
                        	cout<<".";
                        	Sleep(200);
                             }
                    cout<<"TRANSACTION is successful"<<endl;
			        customer[i].cash=customer[i].cash-mony;
			        cout<<"NEW BALANCE IS IN ACCOUNT NUMBER"<<customer[i].id<<"IS  = "<<customer[i].cash;
			    }
			    else if(mony>customer[i].cash){
			    	cout<<"Your transection Withdraw ammount is greater"<<endl;
			    	cout<<"Try again"<<endl;
			    	goto a;
				}
			        break;
			
			
			
		}
			}
		}
	
	
}
void Banking::logout(){
	exit(0);
}
















