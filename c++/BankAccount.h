
#ifndef BankAccount_H_
#define BankAccount_H_






typedef enum {
	active =0,
	restricted =1,
	closed=2
	
} AccountStatus;

typedef enum {
	name=0,
	balance,
	address ,
	NID ,
	age ,
	BankID ,
	GardName ,
	GardID ,
	status,
	password 
	
} class_attr;

class cBankAccount {
	
	public :
		std::string m_Name;
		int m_balance;
		std::string m_address ;
		std::string m_NID ;
		int  m_age ;
		std::string m_BankID ;
		std::string m_GardName ;
		std::string m_GardID ;
		AccountStatus m_acc_status;
		std::string m_password ;
	
	public:
		cBankAccount(void):m_balance(0) , m_acc_status(active) {}   // constructor
		
		void setter(class_attr s);
		int int_getter(class_attr s);
		std::string str_getter(class_attr s);
		AccountStatus state_getter();
		
		cBankAccount BankAccount_create();
		//void BankAccount_print(cBankAccount);
		void BankAccount_print();
		
		void change_pass(int);
		void transaction (int);
		void change_state (int);
		void get_cash (int);
		void deposit (int);
		void show (int);
		
	
	
	
	
	
	
	
};
//-------------------------------------------------
// sBankAccount BankAccount_create();
void  generate_random(int digits ,std::string);
// void BankAccount_print(sBankAccount);
// void modify_Account(sBankAccount);  //  not completed 
int Account_BankID_compare(std::string,std::string);  
int Account_password_compare(std::string,std::string) ;

   void Acc_wait_enter();
// void Acc_change_pass(int);
// void Acc_transaction (int);
// void Acc_change_state (int);
// void Acc_get_cash (int);
// void Acc_deposit (int);
// void Acc_show (int);



#endif