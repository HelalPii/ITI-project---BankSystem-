#include <stdio.h>
#include <unistd.h>
#include "BankAdmin.h"
#include "BankAccount.h"
#include "BankDB.h"



  // check credintals for the clients to log in 
int Client_login()
{
	char BankID[10];
	char password[4];
	sBankAccount BA_local;
	int index=-1;
	
	index=file_Account_get_byID("enter your BANK ID(10 digits) :");
	
	
	if(index > -1)
	{
		printf("enter your PASSWORD(4 digits):");
		scanf("%s",password);
		BA_local=file_struct_read(index);
		if((Account_password_compare(password,BA_local.m_password)==0))
		{
		printf("the account was found \n");
		return index;
		}
		else 
		{
			return -1;
		}
		
	}
	else 
	{
		printf("the account was NOT found \n");
		return -1;
	}
	
}

//client main menu 
void Client_main(int CUR_ACC_INDEX)
{
	
	
	int selector;
	printf("**************************************************\n");
	printf("------------------helloo client-------------------\n");
	printf("--------------------------------------------------\n");
	printf("------1=make trans  2=ch password  3=get cash-----\n");
	printf("-----------4-=deposit in acc  5=show acc----------\n");
	printf("*********************6=return*********************\n");
	scanf("%d",&selector);
		sleep(1);
		system("cls");
	switch(selector)
	{	
		case 1:
		Acc_transaction( CUR_ACC_INDEX);
		break;
		case 2:
		Acc_change_pass (CUR_ACC_INDEX); // not done yet
		break;
		case 3:
		Acc_get_cash(CUR_ACC_INDEX);
		break;
		case 4:
		Acc_deposit(CUR_ACC_INDEX);
		break;
		case 5:
		Acc_show(CUR_ACC_INDEX);
		break;
		case 6:
		/// by default return to main menu
		break;
		
	}
		
}
