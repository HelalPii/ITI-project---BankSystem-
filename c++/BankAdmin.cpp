#include <iostream>
#include <unistd.h>
#include "BankAdmin.h"
#include "BankAccount.h"
#include "BankDB.h"


int Admin_select_window()
{
int selector;
	cout<<"**************************************************\n";
	cout<<"------------------helloo admin--------------------\n";
	cout<<"--------------------------------------------------\n";
	cout<<"--------1=create acc  2=open acc  3=EXIT----------\n";
	cout<<"--------------------------------------------------\n";
	cout<<"**************************************************\n";
	cin>>selector;
	system("cls");
	return selector;
}

// admin main menu
void Admin_main()
{
	int AD_ACC_selector;
	int CUR_ACC_INDEX;
	
	
	switch(Admin_select_window())
	{
		case 1:		// create account
		{  	
			cBankAccount BankAccount_main;   // create an account object
			
			BankAccount_main.create();  // fill the account data 

			DB_write(BankAccount_main);// add the new account to a file ;
			
			//BankAccount_print(BankAccount_main);   // print the account 
			
			
		}
		break;
		case 2:
		{
				cout<<"**************************************************\n";
				
				CUR_ACC_INDEX=DB_Account_get_byID("enter the bank account ID");
				cout<<"**************************************************\n";
				cout<<"------------------helloo admin--------------------\n";
				cout<<"--------------------------------------------------\n";
				cout<<"-----1=make trans  2=ch acc status  3=get cash----\n";
				cout<<"-----------4-=deposit in acc  5=show acc----------\n";
				cout<<"*********************6=return*********************\n";
				cin>>AD_ACC_selector;
				sleep(1);
				system("cls");
				
				cBankAccount BA_local = DB_read(CUR_ACC_INDEX);
				
			switch(AD_ACC_selector)
			{	
				case 1:
				BA_local.transaction( CUR_ACC_INDEX);
				break;
				case 2:
				BA_local.set_state();
				break;
				case 3:
				BA_local.get_cash(CUR_ACC_INDEX);
				break;
				case 4:
				BA_local.deposit(CUR_ACC_INDEX);
				break;
				case 5:
				BA_local.print();
				break;
				case 6:
				/// by default return to main menu
				break;
				
			}
		break;
		}case 3:
		{
			exit(1);
			//exit===> nothing here just return to main menu 
		}	
	}
}

// compare the admin username and password


// check the credintals of the admin to log in 
int Admin_login()
{
	
	cout<<"\nhint : admin admin";

	string A_username;
	string A_password;
	cout<<"\nenter the username :";
	fflush(stdin);
	getline(cin,A_username);
	cout<<"\nenter the password :";
	fflush(stdin);
	getline(cin,A_password);
	
	// check for the admin username and password and compare them to a predefined macro
	
	if(  (A_username == Admin_username)  &&  
	     (A_password == Admin_password)     )
	{
		sleep(1);
		system("cls");
		cout<<"welcome admin \n ";
		
		return 1;
	}
	else 
	{
		cout<<"access denied , username or password may be not correct \n ";
		return 0;
	}
		
	
	
	
}