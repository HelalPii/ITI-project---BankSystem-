#include <iostream>
#include <unistd.h>
#include "BankAdmin.h"
#include "BankAccount.h"
#include "BankDB.h"



  // check credintals for the clients to log in 
int Client_login()
{
	string BankID;
	string password;
	cBankAccount BA_local;
	int index=-1;
	
	index=DB_Account_get_byID("enter your BANK ID(10 digits) :");
	
	
	if(index > -1)
	{
		cout<<"enter your PASSWORD(4 digits):";
		getline(cin,password);
		BA_local=DB_read(index);
		
		BA_local.print();
		
		cout<<"entermned pass word "<<password<<"\naccount pass"<<BA_local.m_password;
		
		if(password == BA_local.m_password)
		{
		cout<<"the account was found \n";
		return index;
		}
		else 
		{
			return -1;
		}
		
	}
	else 
	{
		cout<<"the account was NOT found \n";
		return -1;
	}
	
}

//client main menu 
void Client_main(int CUR_ACC_INDEX)
{
	
	
	int selector;
	cout<<"**************************************************\n";
	cout<<"------------------helloo client-------------------\n";
	cout<<"--------------------------------------------------\n";
	cout<<"------1=make trans  2=ch password  3=get cash-----\n";
	cout<<"-----------4-=deposit in acc  5=show acc----------\n";
	cout<<"*********************6=return*********************\n";
	cin>>selector;
		sleep(1);
		system("cls");
		
		cBankAccount BA_local = DB_read(CUR_ACC_INDEX);
	switch(selector)
	{	
	
		case 1:
		BA_local.transaction( CUR_ACC_INDEX);
		break;
		case 2:
		BA_local.change_pass (CUR_ACC_INDEX); // not done yet
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
		
}
