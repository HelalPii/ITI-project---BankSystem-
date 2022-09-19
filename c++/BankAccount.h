
#ifndef BankAccount_H_
#define BankAccount_H_

#include <sstream>
using namespace std;

#define	active 1
#define	restricted 2
#define	closed 3

#define passwordLENGTH__ 4
#define BankIDLENGTH__ 10


/*prototypes*/
void  generate_random(int digits , string & arr);
int Account_BankID_compare(string a,string b) ;
int Account_password_compare(string a,string b);
void Acc_wait_enter();

enum ClassMember
{
	name,
	acc_status,
	age,
	balance,
	address,
	NID,
	bankID,
	password,
	GardName,
	GardID
	
};


class cBankAccount {
	
	public :
	
		string m_Name;
		string m_address ;
		string m_NID ;
		string m_BankID ;
		string m_password ;
		string m_GardName ;
		string m_GardID ;
		int    m_balance;
		int    m_age ;
		int    m_acc_status;
	
	public:
		cBankAccount(void):m_balance(20) , m_acc_status(active) {}   // constructor
		cBankAccount(int bal,string name,string add,string BID,int ag, string ND):
							m_balance(bal) ,
							m_acc_status(active) ,
							m_Name(name),
							m_address(add),
							m_BankID(BID),
							m_age(ag),
							m_NID(ND),
							m_password("4444")
							{  cout<<"password intially is : 4444\n"; }   // constructor
		
	
		template <typename T>
		void set_value(string member,T value);
		
		void set_value(string member);
		void set_state();
		
		int  get_int_value(string member);
		string  get_str(string member);
		int get_state();
		
		void create();
		void print();
		void transaction (int ACC_INDEX);
		void get_cash (int ACC_INDEX);
		void deposit (int ACC_INDEX);
		void change_pass (int ACC_INDEX);
	
	
};
//-------------------------------------------------

		

		template <typename T>
		void cBankAccount::set_value(string member,T value)
		{
			/*
			using the string stream object to convert the input
			string to int for the case of the int members
			*/
			
			stringstream ss; 
			int num_value;
		    ss << value;
		    ss >> num_value;
			
			
			if(member =="age"){m_age =num_value;}
			else if(member =="balance"){m_balance=num_value;}
			
			else if(member == "name") {m_Name = value;}
			else if(member =="address"){m_address=value;}
			else if(member =="NID"){m_NID = value;}
			else if(member =="bankID"){m_BankID =value;}
			else if(member =="password"){m_password =value;}
			else if(member =="GardName"){m_GardName =value;}
			else if(member =="GardID"){m_GardID=value;}
			
		}

	
	
	#endif