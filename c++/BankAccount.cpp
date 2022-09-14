#include <iostream>
#include<stdlib.h>  // for random generation 
#include <time.h> // for time 
#include <math.h>
#include <string>
#include <unistd.h>
#include "BankAccount.h"
#include "BankDB.h"

using namespace std;

extern FILE * fptr; // the file pointer defined in database file 

void cBankAccount::setter(class_attr s)
{
	
	switch (s)
	{
		case name:
		cin>>m_BankID;
		break;
		case address:
		cin>>m_address;
		break;
		case balance:
		cin>>m_balance;
		break;
		case NID:
		cin>>m_NID;
		break;
		case age:
		cin>>m_age;
		break;
		case BankID:
		cin>>m_BankID;
		break;
		case GardName:
		cin>>m_GardName;
		break;
		case password:
		cin>>m_password;
		break;
	}
}

int cBankAccount::int_getter(class_attr s)
{
		switch (s)
	{
		
		case balance:
		return m_balance;
		break;
		
		case age:
		return m_age;
		break;
		
	}
}
string cBankAccount::str_getter(class_attr s)
{
	
	
		switch (s)
	{
		case name:
		return m_BankID;
		break;
		case address:
		return m_address;
		break;
		case NID:
		return m_NID;
		break;
		case BankID:
		return m_BankID;
		break;
		case GardName:
		return m_GardName;
		break;
		case password:
		return m_password;
		break;
	}
}
AccountStatus cBankAccount::state_getter()
{

		return m_acc_status;
		
}





// create a new account  and return the account
cBankAccount cBankAccount::BankAccount_create(){
	cBankAccount BA_temp;
	cout<<"enter the NAME of the bank account owner :";
	fflush(stdin);
	cin>>BA_temp.m_Name;
	cout<<"enter the ADDRESS of the bank account owner :";
	fflush(stdin);
	getline(cin,BA_temp.m_address);
	cout<<"enter the national ID of the bank account owner(14 digits) :";
	fflush(stdin);
	getline(cin,BA_temp.m_NID);
	cout<<"enter the age of the bank account owner :";
	fflush(stdin);
	cin>>BA_temp.m_age;
	if(BA_temp.m_age<21){
		cout<<"enter the Gardian's name to the bank account :";
		getline(cin,BA_temp.m_GardName);
		cout<<"enter the Gardian's ID to the bank account :";
		getline(cin,BA_temp.m_GardID);
	}
	cout<<"--------------------------------------------------";

	generate_random(sizeof(BA_temp.m_BankID),BA_temp.m_BankID);
	generate_random(sizeof(BA_temp.m_password),BA_temp.m_password);
	cout<<"\nthe bank account ID:";
	cout<<BA_temp.m_BankID;
	cout<<"\nthe bank account PASSWORD :";
	cout<<BA_temp.m_password;
	
	fflush(stdin);
	
	Acc_wait_enter();   // wait the user to press enter to continue
	return BA_temp;
}

//---print the account ---------------------------------------
// void cBankAccount::BankAccount_print(cBankAccount BA){
	// cout<<"\nthe NAME of the bank account owner :";
	// cout<<BA.m_Name;
	// cout<<"\nthe ADDRESS of the bank account owner :";
	// cout<<BA.m_address;
	// cout<<"\nthe national ID of the bank account owner :";
	// cout<<BA.m_NID;
	// cout<<"\nthe age of the bank account owner :";
	// cout<<BA.m_age;
	// if(BA.m_age<21){
		// cout<<"\nthe Gardian's name to the bank account :";
		// cout<<BA.m_GardName);
		// cout<<"\nthe Gardian's ID to the bank account :";
		// cout<<"BA.m_GardID);
	// }
	// cout<<"\n--------------------------------------------------";
	// cout<<"\nthe bank account balance :";
	// cout<<BA.m_balance;
	// cout<<"\n--------------------------------------------------";
	// cout<<"\n==================================================";
	// cout<<"\nthe bank account ID:";
	// cout<<BA.m_BankID;
	// cout<<"\nthe bank account PASSWORD :";
	// cout<<BA.m_password;
	// cout<<"\n==================================================\n";
	
	// Acc_wait_enter();

// }

void cBankAccount::BankAccount_print( ){
	cout<<"\nthe NAME of the bank account owner :";
	cout<<m_Name;
	cout<<"\nthe ADDRESS of the bank account owner :";
	cout<<m_address;
	cout<<"\nthe national ID of the bank account owner :";
	cout<<m_NID;
	cout<<"\nthe age of the bank account owner :";
	cout<<m_age;
	if(m_age<21){
		cout<<"\nthe Gardian's name to the bank account :";
		cout<<m_GardName;
		cout<<"\nthe Gardian's ID to the bank account :";
		cout<<m_GardID;
	}
	cout<<"\n--------------------------------------------------";
	cout<<"\nthe bank account balance :";
	cout<<m_balance;
	cout<<"\n--------------------------------------------------";
	cout<<"\n==================================================";
	cout<<"\nthe bank account ID:";
	cout<<m_BankID;
	cout<<"\nthe bank account PASSWORD :";
	cout<<m_password;
	cout<<"\n==================================================\n";
	
	Acc_wait_enter();

}
//--------true random generator------------------------------------------
void  generate_random(int digits , string arr)
{
	long long r=1;
	long long num ;
	char buffer[digits];
	static int random_seed = 1;
	
	for(int i=0;i<digits;i++){
		r*=10;
	}
	
	srand(time(NULL)+random_seed);
	num = ((rand()%r)+(r/10));
	
	itoa(num,&arr[0],10);
	random_seed ++;
}

//----- compare if two accpunt Bank IDs are identical or not  --- return 0 if equal
int Account_BankID_compare(string a,string b) 
{  
    int flag=0,i=0;  
    while(i<10 )  
    {  
       if(a[i]!=b[i])  
       {  
           flag=1;  
           break;  
		   
       }  
       i++;	   
    }  
    if(flag==0)  
    return 0;  
    else  
    return 1;  
}  

//----- compare if two accpunt Bank password are identical or not  --- return 0 if equal
int Account_password_compare(string a,string b)  
{  
    int flag=0,i=0;  
    while(i<4 )  
    {  
       if(a[i]!=b[i])  
       {  
           flag=1;  
           break;  
		   
       }  
       i++;	   
    }  
    if(flag==0)  
    return 0;  
    else  
    return 1;  
}  

// used to transfer money from one account to another and write back them to database
void cBankAccount::transaction (int ACC_INDEX)
{	
	int INDEX;
	int MONEY;
	cBankAccount BA_local;   // reciever account
	cBankAccount BA;         // sender account
	
	INDEX=file_Account_get_byID("\n enter the account ID that is desired to transfer money to (10 digits):");

	cout<<"\n enter the  money to transfer:";
	cin>>MONEY;
	
	BA_local=file_struct_read(INDEX); //read the reciever account from database
	BA=file_struct_read(ACC_INDEX);   // read the seding account from database

	cout<<"\n -----------------------------------------\n";
	if( (MONEY < BA.m_balance) && ((BA.m_acc_status)== active))
	{
		
		cout<<"transfereing.";
		sleep(1);
		cout<<"..";
		sleep(1);
		cout<<"..";
		sleep(1);

		BA.m_balance-=MONEY;           // update account balance
		BA_local.m_balance+=MONEY;     // update account balance

		//BankAccount_print(BA);
		//BankAccount_print(BA_local);
		file_struct_rewrite(&BA,ACC_INDEX);              // writing back the account to the database
		file_struct_rewrite(&BA_local,INDEX);            // writing back the account to the database
		cout<<"************ after transaction your account is :\n";
		BA.BankAccount_print();
		//BankAccount_print(file_struct_read(INDEX));   
	
	}
	else 
	{   
		if(MONEY > BA.m_balance)
		{cout<<"not enough money in the account\n";}		
		else if (BA.m_acc_status != active)
		{cout<<"your account is not active\n";}
		else
		{cout<<"invalid account entered \n";}	
			
	}
}

//used to change the state of the account 
void cBankAccount::change_state (int ACC_INDEX)
{	
	char state;
	cBankAccount BA_local;
	BA_local=file_struct_read(ACC_INDEX);              // reading account from DB
	
	cout<<"your current account statu is :";
	if(BA_local.m_acc_status == active){ cout<<"active\n";}
	else if(BA_local.m_acc_status == restricted){ cout<<"restricted\n";}
	else if(BA_local.m_acc_status == closed){ cout<<"closed\n";}
	
	cout<<"change it to : 1-active , 2-restricted , 3-closed\n";
	scanf("%d",&state);
	switch (state)
	{
		case 1:
		BA_local.m_acc_status=active;
		break;
		case 2:
		BA_local.m_acc_status=restricted;
		break;
		case 3:
		BA_local.m_acc_status=closed;
		break;
	}
	file_struct_rewrite(&BA_local,ACC_INDEX);
	cout<<"\n state changed successfully \n";
	sleep(1);
}

//used to get cash from the account 
void cBankAccount::get_cash (int ACC_INDEX)
{
	char money;
	cBankAccount BA_local;
	BA_local=file_struct_read(ACC_INDEX);
	cout<<"your balance in the account:%d\n",BA_local.m_balance;
	
	
	cout<<"enter the amount you want to withdraw:\n";
	cin>>money;
	
	if(money<BA_local.m_balance)
	{
		BA_local.m_balance-=money;
		file_struct_rewrite(&BA_local,ACC_INDEX);
		BA_local.BankAccount_print( );
	}
	else 
	{	
	cout<<"failed to get cash ... your balance is low";
	}
	
	
	
	
	
}

//used to deposit cash into account
void cBankAccount::deposit (int ACC_INDEX)
{
	int money;
	cBankAccount BA_local;
	BA_local=file_struct_read(ACC_INDEX);
	cout<<"your balance in the account:%d\n",BA_local.m_balance;
	
	
	cout<<"enter the amount you want to deposit:\n";
	cin>>money;
	
		BA_local.m_balance+=money;
	
	file_struct_rewrite(&BA_local,ACC_INDEX);
	BA_local.BankAccount_print();
	

}

//used to show accounts 
void cBankAccount::show (int ACC_INDEX)
{
		
	cBankAccount BA_local;
	BA_local=file_struct_read(ACC_INDEX);
	cout<<"showing account number %d ....\n",ACC_INDEX;   //display the order of the acc in the DB
	
	BA_local.BankAccount_print();

}

// used to wait until the user press enter
void Acc_wait_enter()
{
	fflush(stdin);                              //clear the buffer
	cout<<"\npress enter to continue\n";     
	getchar();                                    //read the enter and ignore it
	system("cls");                              // clear console screen 
}

//used to change the account password  
void cBankAccount::change_pass (int ACC_INDEX)
{
	char password[4];		
			
	cBankAccount BA_local;
	BA_local=file_struct_read(ACC_INDEX);         // read the account from DB
	
	cout<<"to change your account password \n type your current PASSWORD (4 digits) : ";
	cin>>password;
	if(Account_password_compare(password,BA_local.m_password)==0)
	{
	cout<<"enter your new password (4 digits) : ";
	cin>>BA_local.m_password;
	}
	
	cout<<"showing account number %d  with new password....\n",ACC_INDEX;
	file_struct_rewrite(&BA_local,ACC_INDEX);
	//BankAccount_print(file_struct_read(ACC_INDEX));   to check if the password is changed 

}