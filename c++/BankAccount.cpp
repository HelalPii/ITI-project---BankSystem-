#include <iostream>
#include <stdlib.h>  // for random generation 
#include <time.h> // for time 
#include <math.h>
#include <string>
#include <unistd.h>
#include "BankAccount.h"
#include "BankDB.h"

using namespace std;






void	cBankAccount::set_value(string member)
{
	
	cout<<"enter the "<<(member)<<":";
	
	if(member == "name") 
	{
		string value;
		getline(cin,value);
		m_Name = value;
	}
	else if(member =="age")
	{
		int value;
		cin>>value;
		m_age =value;
	}
	else if(member =="balance")
	{
		int value;
		cin>>value;		
		m_balance=value;
	}
	else if(member =="address")
	{
		string value;
		getline(cin,value);
		m_address=value;
	}
	else if(member =="NID")
	{
		string value;
		getline(cin,value);
		m_NID = value;
	}
	else if(member =="BankID")
	{
		string value;
		getline(cin,value);	
		m_BankID =value;
	}
	else if(member =="password")
	{
		string value;
		getline(cin,value);
		m_password =value;
	}
	else if(member =="GardName")
	{
		string value;
		getline(cin,value);	
		m_GardName =value;
	}
	else if(member =="GardID")
	{
		string value;
		getline(cin,value);	
		m_GardID=value;
	}
	
}

int  cBankAccount::get_int_value(string member)
{
	cout<<"the "<<member <<" is :";
	if(member =="age"){return m_age;}
	else if(member =="balance"){return m_balance;}
}

string  cBankAccount::get_str(string member)
{
	//cout<<"the "<<member <<" is :";
	if(member == "name") {return m_Name ;}
	else if(member =="address"){return m_address;}
	else if(member =="NID"){return m_NID ;}
	else if(member =="BankID"){return m_BankID;}
	else if(member =="password"){return m_password;}
	else if(member =="GardName"){return m_GardName;}
	else if(member =="GardID"){return m_GardID;}
}

void cBankAccount::set_state()
{
	int s;
	cout<<"the account state is (( ";
		if(get_state()==active){cout<<"active  ))\n";}
		else if(get_state()==restricted){cout<<"restricted ))\n";}
		else if(get_state()==closed){cout<<"closed ))\n";}
	
	cout<<"Change the state to : 1- active  , 2- restricted , 3- closed \n ";
	cin>>s;
	
		if(s==active){m_acc_status = active;}
		else if(s==restricted){m_acc_status = restricted;}
		else if(s==closed){m_acc_status = closed;}
		
		cout<<"\n state changed successfully \n";
		sleep(1);
}

int cBankAccount::get_state()
{
	return m_acc_status;
}

//**********************************************************

// create a new account  and return the account
void cBankAccount::create(){
	
	cout<<"enter the NAME of the bank account owner :";
	fflush(stdin);
	getline(cin,m_Name);
	cout<<"enter the ADDRESS of the bank account owner :";
	fflush(stdin);
	getline(cin,m_address);
	cout<<"enter the national ID of the bank account owner(14 digits) :";
	fflush(stdin);
	getline(cin,m_NID);
	cout<<"enter the age of the bank account owner :";
	fflush(stdin);
	cin>>m_age;
	if(m_age<21){
		cout<<"enter the Gardian's name to the bank account :";
		getline(cin,m_GardName);
		cout<<"enter the Gardian's ID to the bank account :";
		getline(cin,m_GardID);
	}
	cout<<"--------------------------------------------------";

	generate_random(BankIDLENGTH__,m_BankID);
	generate_random(passwordLENGTH__,m_password);
	cout<<"\nthe bank account ID:";
	cout<<m_BankID;
	cout<<"\nthe bank account PASSWORD :";
	cout<<m_password;
	
	fflush(stdin);
	
	Acc_wait_enter();   // wait the user to press enter to continue
	
}


void cBankAccount::print( ){
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



// used to transfer money from one account to another and write back them to database
void cBankAccount::transaction (int ACC_INDEX)
{	
	int INDEX;
	int MONEY;
	cBankAccount BA_local;   // reciever account
	//cBankAccount BA;         // sender account
	
	INDEX=DB_Account_get_byID("\n enter the account ID that is desired to transfer money to (10 digits):");

	cout<<"\n enter the  money to transfer:";
	cin>>MONEY;
	
	
	BA_local=DB_read(INDEX); //read the reciever account from database
	//BA=file_struct_read(ACC_INDEX);   // read the seding account from database
	//BA_local.create();
	cout<<"\n -----------------------------------------\n";
	if( (MONEY < m_balance) && ((m_acc_status)== active))
	{
		
		cout<<"transfereing.";
		sleep(1);
		cout<<"..";
		sleep(1);
		cout<<"..";
		sleep(1);

		m_balance-=MONEY;           // update account balance
		BA_local.m_balance+=MONEY;     // update account balance

		//BankAccount_print(BA);
		//BankAccount_print(BA_local);
		DB_rewrite(this,ACC_INDEX);              // writing back the account to the database
		DB_rewrite(&BA_local,INDEX);            // writing back the account to the database
		cout<<"************ after transaction your account is :\n";
		print();
		BA_local.print();
		//BankAccount_print(file_struct_read(INDEX));   
	
	}
	else 
	{   
		if(MONEY >m_balance)
		{cout<<"not enough money in the account\n";}		
		else if (m_acc_status != active)
		{cout<<"your account is not active\n";}
		else
		{cout<<"invalid account entered \n";}	
			
	}
}


//used to get cash from the account 
void cBankAccount::get_cash (int ACC_INDEX)
{
	int money;
	cout<<"your balance in the account: "<<m_balance<<endl;
	
	
	cout<<"enter the amount you want to withdraw:\n";
	cin>>money;
	
	if(money<m_balance)
	{
		m_balance-=money;
		DB_rewrite(this,ACC_INDEX);
		print( );
	}
	else 
	{	
	cout<<"failed to get cash ... your balance is low";
	}
	
}

void cBankAccount::deposit (int ACC_INDEX)
{
	int money;
	cout<<"your balance in the account: "<<m_balance<<endl;
	
	
	cout<<"enter the amount you want to deposit:\n";
	cin>>money;
	
		m_balance+=money;
	
	DB_rewrite(this,ACC_INDEX);
	print();
	

}

//used to change the account password  
void cBankAccount::change_pass (int ACC_INDEX)
{
	string password;		
	
	cout<<"to change your account password \n type your current PASSWORD (4 digits) : ";
	cin>>password;
	if((password == m_password))
	{
	cout<<"enter your new password (4 digits) : ";
	cin>>m_password;
	}
	
	cout<<"password changed successfully !!\n";
	DB_rewrite(this,ACC_INDEX);
	
	//BankAccount_print(file_struct_read(ACC_INDEX));   to check if the password is changed 

}

//--------true random generator------------------------------------------
void  generate_random(int digits , string& arr)
{
	stringstream ss;  

	long long r=1;
	long long num ;
	char buffer[digits];
	static int random_seed = 1;
	
	for(int i=0;i<digits;i++){
		r*=10;
	}
	
	srand(time(NULL)+random_seed);
	num = ((rand()%r)+(r/10));
	
    ss<<num;  
    ss>>arr; 
 
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


void Acc_wait_enter()
{
	fflush(stdin);                              //clear the buffer
	cout<<"\npress enter to continue\n";     
	getchar();                                    //read the enter and ignore it
	system("cls");                              // clear console screen 
}