#include <iostream>
#include <stdlib.h>
#include <string>

#include "BankDB.h"
#include "BankAccount.h"

using namespace std;

	 FILE * fptr;    //file pointer
	 
	 // initiate and prepare the file 
void file_init(FILE** fptr,char mode)
{
	
	//choose mode of opening the file 
	if(mode=='r')                       // read and write mode    
	*fptr = fopen(filename,"r+"); 

	else  if (mode == 'a')              // read and append mode
	*fptr = fopen(filename,"a+"); 
	
	
	if (fptr== NULL)               
    {	
        //fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
}
    // close the file using the file pointer
void  file_close(FILE ** fptr)
{	
	//close the file using the pointer
	fclose(*fptr); 
}
   // read an account from DB based on its Address
cBankAccount file_struct_read(int index)
{	
	file_init(&fptr,'r');                            //open the file in read and write mode
    cBankAccount BA;                                 //local bank account to hold the read account
	int siz=index * sizeof(cBankAccount);            // compute the index (address )of the account in the DB
	fseek(fptr, siz, SEEK_SET);                      // move the file pointer to the desired address in DB
	fread(&BA, sizeof(cBankAccount), 1, fptr);       // read the account in the address into the local bank account
	
	if (fptr== NULL)
    {	
        //fprintf(stderr, "\nError reading from file\n");
        exit (1);
    }
	else
	{
		//BankAccount_print(BA);                    // to display the read account
		return BA;
	}
}
  // write an account into the DB
void  file_struct_write(cBankAccount* BA) 
{	
	file_init(&fptr,'a');                               // open the file in read and append mode 
	fwrite (BA, sizeof( cBankAccount), 1, fptr);        // append the account to the DB

	if(fwrite != 0){
        cout<<"*** your account was added successfully ! ***\n";
    }
	else{
        cout<<"error adding the account !\n";
	}
	file_close(&fptr);                                 // close the file until the next operation 
}

// over write the account into the DB based on the address
void  file_struct_rewrite(cBankAccount* BA,int index)
{	
	file_init(&fptr,'r');                              // open the file in read and append mode 
	int siz=index * sizeof(cBankAccount);              // compute the index (address )of the account in the DB
	fseek(fptr, siz, SEEK_SET);                        // move the file pointer to the desired address in DB
	fwrite (BA, sizeof( cBankAccount), 1, fptr);       // over-write the account to the DB to that address

	if(fwrite != 0)
        cout<<"your account was added successfully !\n";
    else
        cout<<"error adding the account !\n";
	file_close(&fptr);
}

// fetch the account from DB by its bank ID
int  file_Account_get_byID(string msg)
{	string Bank_ID;
	cout<<msg;
	cin>>Bank_ID;
	cBankAccount BA_local;                   //local bank account to hold the read account
	
	int i =0;
	fseek(fptr,0, SEEK_SET);                 // move the file pointer to the desired address in DB
	
	while(feof(fptr)==0){                    // while the pointer hasnt reached the end of file
		cout<<"I:%d\n",i;              // display the index in DB (address)
		
		BA_local=file_struct_read(i);       // roll through all saved accounts in database
		
			if(Account_BankID_compare(Bank_ID,BA_local.str_getter(BankID))==0)   // validate of the bank id is fount in the DB
			{
				cout<<"account found with ID number :%s    in index:%d\n",BankID,i;
				return i;
			}
		i++;
		}
		cout<<"account not found \n";
		return -1;
}
	  
	
