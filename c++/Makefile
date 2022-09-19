#banksystem makefile

#target:dependancies
#(tap)action

BankSystemAPP: main.o BankAccount.o BankSystem.o BankAdmin.o BankClient.o BankDB.o
	g++ main.o BankAccount.o BankSystem.o BankAdmin.o BankClient.o BankDB.o -o BankSystemAPP
	
main.o: main.cpp 
	g++ -c main.cpp
	
BankAccount.o: BankAccount.cpp BankAccount.h
	g++ -c BankAccount.cpp

BankSystem.o: BankSystem.cpp BankSystem.h
	g++ -c BankSystem.cpp
	
BankAdmin.o: BankAdmin.cpp BankAdmin.h
	g++ -c BankAdmin.cpp

BankClient.o: BankClient.cpp BankClient.h
	g++ -c BankClient.cpp
	
BankDB.o: BankDB.cpp BankDB.h
	g++ -c BankDB.cpp

clean: 
	rm -f main.o BankAccount.o BankSystem.o BankAdmin.o BankClient.o BankDB.o BankSystemAPP