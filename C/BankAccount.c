#include <stdio.h>
#include<stdlib.h>  // for random generation 
#include <time.h> // for time 
#include <math.h>
#include <unistd.h>
#include "BankAccount.h"
#include "BankDB.h"

extern FILE * fptr; // the file pointer defined in database file 

// create a new account  and return the account
sBankAccount BankAccount_create(){
	sBankAccount BA_temp;
	printf("enter the NAME of the bank account owner :");
	fflush(stdin);
	gets(BA_temp.m_Name);
	printf("enter the ADDRESS of the bank account owner :");
	fflush(stdin);
	gets(BA_temp.m_address);
	printf("enter the national ID of the bank account owner(14 digits) :");
	fflush(stdin);
	gets(BA_temp.m_NID);
	printf("enter the age of the bank account owner :");
	fflush(stdin);
	scanf("%d",&BA_temp.m_age);
	if(BA_temp.m_age<21){
		printf("enter the Gardian's name to the bank account :");
		
		gets(BA_temp.m_GardName);
		printf("enter the Gardian's ID to the bank account :");
		
		gets(BA_temp.m_GardID);
	}
	printf("--------------------------------------------------");
	BA_temp.m_acc_status= active;
	BA_temp.m_balance= 0;


	
	generate_random(sizeof(BA_temp.m_BankID),BA_temp.m_BankID);
	generate_random(sizeof(BA_temp.m_password),BA_temp.m_password);
	printf("\nthe bank account ID:");
	printf("%s",BA_temp.m_BankID);
	printf("\nthe bank account PASSWORD :");
	printf("%s",BA_temp.m_password);
	
	
	fflush(stdin);
	
	Acc_wait_enter();   // wait the user to press enter to continue
	return BA_temp;
}

//---print the account ---------------------------------------
void BankAccount_print(sBankAccount BA){
	printf("\nthe NAME of the bank account owner :");
	printf("%s",BA.m_Name);
	printf("\nthe ADDRESS of the bank account owner :");
	printf("%s",BA.m_address);
	printf("\nthe national ID of the bank account owner :");
	printf("%s",BA.m_NID);
	printf("\nthe age of the bank account owner :");
	printf("%d",BA.m_age);
	if(BA.m_age<21){
		printf("\nthe Gardian's name to the bank account :");
		printf("%s",BA.m_GardName);
		printf("\nthe Gardian's ID to the bank account :");
		printf("%s",BA.m_GardID);
	}
	printf("\n--------------------------------------------------");
	printf("\nthe bank account balance :");
	printf("%d",BA.m_balance);
	printf("\n--------------------------------------------------");
	printf("\n==================================================");
	printf("\nthe bank account ID:");
	printf("%s",BA.m_BankID);
	printf("\nthe bank account PASSWORD :");
	printf("%s",BA.m_password);
	printf("\n==================================================\n");
	
	
	Acc_wait_enter();

}

//--------true random generator------------------------------------------
void  generate_random(int digits , char arr[])
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
	
	itoa(num,arr,10);
	random_seed ++;
}

//----- compare if two accpunt Bank IDs are identical or not  --- return 0 if equal
int Account_BankID_compare(char a[],char b[])  
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
int Account_password_compare(char a[],char b[])  
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
void Acc_transaction (int ACC_INDEX)
{	
	int INDEX;
	int MONEY;
	sBankAccount BA_local;   // reciever account
	sBankAccount BA;         // sender account
	
	INDEX=file_Account_get_byID("\n enter the account ID that is desired to transfer money to (10 digits):");

	printf("\n enter the  money to transfer:");
	scanf("%d",&MONEY);
	
	BA_local=file_struct_read(INDEX); //read the reciever account from database
	BA=file_struct_read(ACC_INDEX);   // read the seding account from database

	printf("\n -----------------------------------------\n");
	if( (MONEY < BA.m_balance) && ((BA.m_acc_status)== active))
	{
		
		printf("transfereing.");
		sleep(1);
		printf("..");
		sleep(1);
		printf("..");
		sleep(1);

		BA.m_balance-=MONEY;           // update account balance
		BA_local.m_balance+=MONEY;     // update account balance

		//BankAccount_print(BA);
		//BankAccount_print(BA_local);
		file_struct_rewrite(&BA,ACC_INDEX);              // writing back the account to the database
		file_struct_rewrite(&BA_local,INDEX);            // writing back the account to the database
		printf("************ after transaction your account is :\n");
		BankAccount_print(file_struct_read(ACC_INDEX));
		//BankAccount_print(file_struct_read(INDEX));   
	
	}
	else 
	{   
		if(MONEY > BA.m_balance)
		{printf("not enough money in the account\n");}		
		else if (BA.m_acc_status != active)
		{printf("your account is not active\n");}
		else
		{printf("invalid account entered \n");}	
			
	}
}

//used to change the state of the account 
void Acc_change_state (int ACC_INDEX)
{	
	char state;
	sBankAccount BA_local;
	BA_local=file_struct_read(ACC_INDEX);              // reading account from DB
	
	printf("your current account statu is :");
	if(BA_local.m_acc_status == active){ printf("active\n");}
	else if(BA_local.m_acc_status == restricted){ printf("restricted\n");}
	else if(BA_local.m_acc_status == closed){ printf("closed\n");}
	
	printf("change it to : 1-active , 2-restricted , 3-closed\n");
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
	printf("\n state changed successfully \n");
	sleep(1);
}

//used to get cash from the account 
void Acc_get_cash (int ACC_INDEX)
{
	char money;
	sBankAccount BA_local;
	BA_local=file_struct_read(ACC_INDEX);
	printf("your balance in the account:%d\n",BA_local.m_balance);
	
	
	printf("enter the amount you want to withdraw:\n");
	scanf("%d",&money);
	
	if(money<BA_local.m_balance)
	{
		BA_local.m_balance-=money;
		file_struct_rewrite(&BA_local,ACC_INDEX);
		BankAccount_print(file_struct_read(ACC_INDEX));
	}
	else 
	{	
	printf("failed to get cash ... your balance is low");
	}
	
	
	
	
	
}

//used to deposit cash into account
void Acc_deposit (int ACC_INDEX)
{
	int money;
	sBankAccount BA_local;
	BA_local=file_struct_read(ACC_INDEX);
	printf("your balance in the account:%d\n",BA_local.m_balance);
	
	
	printf("enter the amount you want to deposit:\n");
	scanf("%d",&money);
	
		BA_local.m_balance+=money;
	
	file_struct_rewrite(&BA_local,ACC_INDEX);
	BankAccount_print(file_struct_read(ACC_INDEX));
	

}

//used to show accounts 
void Acc_show (int ACC_INDEX)
{
		
	sBankAccount BA_local;
	BA_local=file_struct_read(ACC_INDEX);
	printf("showing account number %d ....\n",ACC_INDEX);   //display the order of the acc in the DB
	
	BankAccount_print(file_struct_read(ACC_INDEX));

}

// used to wait until the user press enter
void Acc_wait_enter()
{
	fflush(stdin);                              //clear the buffer
	printf("\npress enter to continue\n");     
	getchar();                                    //read the enter and ignore it
	system("cls");                              // clear console screen 
}

//used to change the account password  
void Acc_change_pass (int ACC_INDEX)
{
	char password[4];		
			
	sBankAccount BA_local;
	BA_local=file_struct_read(ACC_INDEX);         // read the account from DB
	
	printf("to change your account password \n type your current PASSWORD (4 digits) : ");
	scanf("%s",password);
	if(Account_password_compare(password,BA_local.m_password)==0)
	{
	printf("enter your new password (4 digits) : ");
	scanf("%s",BA_local.m_password);
	}
	
	printf("showing account number %d  with new password....\n",ACC_INDEX);
	file_struct_rewrite(&BA_local,ACC_INDEX);
	//BankAccount_print(file_struct_read(ACC_INDEX));   to check if the password is changed 

}