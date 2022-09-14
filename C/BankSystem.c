#include <stdio.h>
#include <stdlib.h>
#include "BankSystem.h"
#include "BankAdmin.h"
#include "BankClient.h"
#include <unistd.h>

void Bank_welcome(void )
{   system("cls");
	printf("**************************************************\n");
	printf("--------------------------------------------------\n");
	printf("***********welcom to the bank system**************\n");
	printf("--------------------------------------------------\n");
	printf("******************islam helal*********************\n");
	sleep(3);
	system("cls");
}

int Bank_select_window(void){
	int selector;
	printf("**************************************************\n");
	printf("---------------choose your login------------------\n");
	printf("-------------1=ADMIN -----2=CLIENT----------------\n");
	printf("--------------------------------------------------\n");
	printf("**************************************************\n");
	scanf("%d",&selector);
	system("cls");
	return selector;
}

void Bank_Admin(){
	
	if(Admin_login())
	{
		Admin_main();
	}
	else 
	{
		printf("failed to login \n");	
	}
}


void Bank_client()
{
	
	int Client_index=Client_login();
	
	if(Client_index>-1){
	Client_main(Client_index);
	}
	else
	{
	printf("failed to login \n");	
	exit(1);
	}
}


