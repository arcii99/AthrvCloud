//FormAI DATASET v1.0 Category: Banking Record System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 50
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int accountNumber;
    float balance;
} BankAccount;

BankAccount accounts[MAX_ACCOUNTS];
int numAccounts = 0;

void addAccount(char name[], int accountNumber, float balance) {
    BankAccount newAccount;
    strcpy(newAccount.name, name);
    newAccount.accountNumber = accountNumber;
    newAccount.balance = balance;
    accounts[numAccounts++] = newAccount;
}

void printAccounts() {
    printf("********* BANKING RECORD SYSTEM *********\n");
    for(int i=0; i<numAccounts; i++) {
        printf("Account Holder Name: %s\n", accounts[i].name);
        printf("Account Number: %d\n", accounts[i].accountNumber);
        printf("Account Balance: %.2f\n", accounts[i].balance);
        printf("----------------------------------------\n");
    }
}

void findAccount(int accountNumber) {
    printf("********* FIND ACCOUNT *********\n");
    for(int i=0; i<numAccounts; i++) {
        if(accounts[i].accountNumber == accountNumber) {
            printf("Account Holder Name: %s\n", accounts[i].name);
            printf("Account Number: %d\n", accounts[i].accountNumber);
            printf("Account Balance: %.2f\n", accounts[i].balance);
            printf("----------------------------------------\n");
            return;
        }
    }
    printf("Account number %d not found.\n", accountNumber);
}

void deposit(int accountNumber, float amount) {
    for(int i=0; i<numAccounts; i++) {
        if(accounts[i].accountNumber == accountNumber) {
            accounts[i].balance += amount;
            printf("Deposited %.2f successfully to account number %d.\n", amount, accountNumber);
            return;
        }
    }
    printf("Account number %d not found.\n", accountNumber);
}

void withdraw(int accountNumber, float amount) {
    for(int i=0; i<numAccounts; i++) {
        if(accounts[i].accountNumber == accountNumber) {
            if(accounts[i].balance < amount) {
                printf("Not enough balance to withdraw %.2f from account number %d.\n", amount, accountNumber);
                return;
            }
            accounts[i].balance -= amount;
            printf("Withdrawn %.2f successfully from account number %d.\n", amount, accountNumber);
            return;
        }
    }
    printf("Account number %d not found.\n", accountNumber);
}

int main() {
    addAccount("John", 1001, 12000.50);
    addAccount("Jane", 1002, 9800.25);
    addAccount("Chris", 1003, 15000.00);

    printAccounts();

    findAccount(1002);

    deposit(1001, 500.75);
    deposit(1003, 1000.00);

    withdraw(1002, 5000.00);
    withdraw(1001, 15000.00);

    printAccounts();

    return 0;
}