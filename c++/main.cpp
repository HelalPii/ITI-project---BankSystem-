#include <iostream>
#include <unistd.h>

using namespace std;

#include "BankSystem.h"
#include "BankAccount.h"
#include "BankDb.h"


int main (void){
	DB_init(); // to intialize the DB
	Acc_wait_enter();
	
		while (1){


				switch (Bank_select_window())
				{
					case 1: 
					Bank_Admin();
					break;
					
					case 2:
					Bank_client();
					break;
				}
			
			}


		return 0;

	}
