#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

#include "BankDB.h"
#include "BankAccount.h"

using namespace std;


cBankAccount DB_Glob_arr[50];
int DB_global_index=0;

// initiate and prepare the file 
void DB_init()
{	
		cBankAccount BA(30,"islam","benha","1002",23,"123456888");
		cBankAccount BA3(46,"kareem","benha","1003",23,"123456999");
		cBankAccount BA2;
		cBankAccount BA4(99,"toto","benha","1004",23,"1234568777");
		// BA(30,"islam","benha","1002",23,"123456888");
		// BA3(46,"kareem","benha","1003",23,"123456999");
		// BA4(99,"toto","benha","1004",23,"1234568777");
	
		DB_write(BA);
		DB_write(BA3);
		DB_write(BA4);
		
		cout<<"intialized the database with 3 accounts\n";
}


   // read an account from DB based on its Address
cBankAccount DB_read(int index)
{	
	return DB_Glob_arr[index];
}


  // write an account into the DB
void  DB_write(cBankAccount& BA) 
{	
	DB_Glob_arr[DB_global_index]=BA;
	
	cout<<"account added !!!!!!!"<<endl;
	DB_global_index++;
	
}



//over write the account into the DB based on the address
void  DB_rewrite(cBankAccount& BA,int index)
{	
	DB_Glob_arr[index]=BA;
}

void  DB_rewrite(cBankAccount* BA,int index)
{	

	DB_Glob_arr[index].m_Name=BA->m_Name;
	DB_Glob_arr[index].m_address=BA->m_address;
	DB_Glob_arr[index].m_NID=BA->m_NID;
	DB_Glob_arr[index].m_BankID=BA->m_BankID;
	DB_Glob_arr[index].m_password=BA->m_password;
	DB_Glob_arr[index].m_GardName=BA->m_GardName;
	DB_Glob_arr[index].m_GardID=BA->m_GardID;
	DB_Glob_arr[index].m_balance=BA->m_balance;
	DB_Glob_arr[index].m_age=BA->m_age;
	DB_Glob_arr[index].m_acc_status=BA->m_acc_status;
}

//fetch the account from DB by its bank ID
int  DB_Account_get_byID(string msg)
{	
	string Bank_ID;
	cout<<msg<<"\n";
	fflush(stdin);
	getline(cin,Bank_ID);
	cBankAccount BA_local;
	
	
	for(int i =0 ; i<DB_global_index;i++)
	{
	
		if(DB_read(i).m_BankID == Bank_ID)
		{
			cout<<"found your account with ID: "<<Bank_ID<<endl;
			return i;
			break;
		}
	}
	
}

void DB_print()
{
	
	for(int i =0 ; i<DB_global_index;i++)
	{
		DB_Glob_arr[i].print();
	}
}
	  
	
