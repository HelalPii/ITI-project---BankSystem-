#ifndef BADB_H_
#define BADB_H_
#include "BankAccount.h"

#define filename "BA_DB.txt"


	

void file_init(FILE ** fptr,char);
void  file_close(FILE ** fptr);
void  file_struct_write(sBankAccount *BA);
void  file_struct_rewrite(sBankAccount* BA,int index);
sBankAccount file_struct_read(int index);
int file_Account_get_byID(char msg[]);

/*
//////////simple demo code////////////
sBankAccount BA={"islam","asasd",
				"279702211440",22,
				"123000221",
				"654561659615",
				"54351665161",
				active,12,"1234"
				};
sBankAccount BA2={"hani","asasd",
				"279702211440",22,
				"123000221",
				"654561659615",
				"54351665161",
				active,12,"1234"
				};
sBankAccount BA1;
sBankAccount BA3;

file_init();
file_struct_write(&BA);
file_struct_write(&BA2);

getchar();
BA1=file_struct_read(0);
BankAccount_print(BA1);

BA3=file_struct_read(1);
BankAccount_print(BA3);

*/




#endif