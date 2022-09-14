
#ifndef BankAccount_H_
#define BankAccount_H_



typedef enum {
	active =0,
	restricted =1,
	closed=2
	
} AccountStatus;

typedef struct {
	
	char m_Name[80];
	int m_balance;
	char m_address[100];
	char m_NID[14];
	int  m_age ;
	char m_BankID[10];
	char m_GardName[80];
	char m_GardID[14];
	AccountStatus m_acc_status;
	char m_password[4];
	
	
}sBankAccount;
//-------------------------------------------------
sBankAccount BankAccount_create();
void  generate_random(int digits , char a[]);
void BankAccount_print(sBankAccount);
void modify_Account(sBankAccount);  //  not completed 
int Account_BankID_compare(char a[],char b[]);  
int Account_password_compare(char a[],char b[]) ;

void Acc_wait_enter();
void Acc_change_pass(int);
void Acc_transaction (int);
void Acc_change_state (int);
void Acc_get_cash (int);
void Acc_deposit (int);
void Acc_show (int);



#endif