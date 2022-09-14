#banksystem makefile

#target:dependancies
#(tap)action

BankSystemAPP: main.o BankAccount.o BankSystem.o BankAdmin.o BankClient.o BankDB.o
	gcc main.o BankAccount.o BankSystem.o BankAdmin.o BankClient.o BankDB.o -o BankSystemAPP
	
main.o: main.c 
	gcc -c main.c
	
BankAccount.o: BankAccount.c BankAccount.h
	gcc -c BankAccount.c

BankSystem.o: BankSystem.c BankSystem.h
	gcc -c BankSystem.c
	
BankAdmin.o: BankAdmin.c BankAdmin.h
	gcc -c BankAdmin.c

BankClient.o: BankClient.c BankClient.h
	gcc -c BankClient.c
	
BankDB.o: BankDB.c BankDB.h
	gcc -c BankDB.c

clean: 
	rm -f main.o BankAccount.o BankSystem.o BankAdmin.o BankClient.o BankDB.o BankSystemAPP