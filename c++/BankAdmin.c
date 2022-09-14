#include <stdio.h>
#include <unistd.h>
#include "BankAdmin.h"
#include "BankAccount.h"
#include "BankDB.h"


int Admin_select_window()
{
int selector;
	printf("**************************************************\n");
	printf("------------------helloo admin--------------------\n");
	printf("--------------------------------------------------\n");
	printf("--------1=create acc  2=open acc  3=EXIT----------\n");
	printf("--------------------------------------------------\n");
	printf("**************************************************\n");
	scanf("%d",&selector);
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
			sBankAccount BankAccount_main;   // create an account object
			
			BankAccount_main=BankAccount_create();  // fill the account data 

			file_struct_write(&BankAccount_main);// add the new account to a file ;
			
			//BankAccount_print(BankAccount_main);   // print the account 
			
			
		}
		break;
		case 2:
		{
				printf("**************************************************\n");
				
				CUR_ACC_INDEX=file_Account_get_byID("enter the bank account ID");
				printf("**************************************************\n");
				printf("------------------helloo admin--------------------\n");
				printf("--------------------------------------------------\n");
				printf("-----1=make trans  2=ch acc status  3=get cash----\n");
				printf("-----------4-=deposit in acc  5=show acc----------\n");
				printf("*********************6=return*********************\n");
				scanf("%d",&AD_ACC_selector);
				sleep(1);
				system("cls");
			switch(AD_ACC_selector)
			{	
				case 1:
				Acc_transaction( CUR_ACC_INDEX);
				break;
				case 2:
				Acc_change_state (CUR_ACC_INDEX);
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
		break;
		}case 3:
		{
			exit(1);
			//exit===> nothing here just return to main menu 
		}	
	}
}

// compare the admin username and password
int string_compare(char a[],char b[])  
{  
    int flag=0,i=0;  
    while( a[i]!='\0' &&b[i]!='\0' )  
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

// check the credintals of the admin to log in 
int Admin_login()
{
	
	printf("\nhint : admin admin");

	char A_username[10]={0};
	char A_password[10]={0};
	printf("\nenter the username :");
	scanf("%s",A_username);
	printf("\nenter the password :");
	scanf("%s",A_password);
	
	// check for the admin username and password and compare them to a predefined macro
	
	if(  (string_compare(A_username,Admin_username)==0)  &&  
	     (string_compare(A_password,Admin_password)==0)     )
	{
		sleep(1);
		system("cls");
		printf("welcome admin \n ");
		
		return 1;
	}
	else 
	{
		printf("access denied , username or password may be not correct \n ");
		return 0;
	}
		
	
	
	
}