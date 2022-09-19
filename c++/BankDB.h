#ifndef BADB_H_
#define BADB_H_
#include "BankAccount.h"

#define filename "BA_DB.txt"


void  DB_init();

void  DB_write(cBankAccount &BA);
void  DB_rewrite(cBankAccount& BA,int index);
void  DB_rewrite(cBankAccount* BA,int index);
cBankAccount DB_read(int index);
int DB_Account_get_byID(std::string msg);

void DB_print();


#endif