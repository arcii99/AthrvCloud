//FormAI DATASET v1.0 Category: Banking Record System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 10
#define MAX_TRANSACTIONS 100

typedef struct account {
    int accountNumber;
    float balance;
} Account;

typedef struct transaction {
    int accountNumber;
    char description[50];
    float amount;
} Transaction;

Account bankAccounts[MAX_ACCOUNTS];
Transaction transactionHistory[MAX_TRANSACTIONS];
int numAccounts = 0;
int numTransactions = 0;

void addAccount(int accountNumber, float balance) {
    if (numAccounts < MAX_ACCOUNTS) {
        bankAccounts[numAccounts].accountNumber = accountNumber;
        bankAccounts[numAccounts].balance = balance;
        numAccounts++;
        printf("Account added successfully.\n");
    } else {
        printf("Maximum number of accounts reached.\n");
    }
}

void deposit(int accountNumber, float amount, char* description) {
    int i;
    for (i = 0; i < numAccounts; i++) {
        if (bankAccounts[i].accountNumber == accountNumber) {
            bankAccounts[i].balance += amount;
            transactionHistory[numTransactions].accountNumber = accountNumber;
            strcpy(transactionHistory[numTransactions].description, description);
            transactionHistory[numTransactions].amount = amount;
            numTransactions++;
            printf("Deposit successful.\n");
            return;
        }
    }
    printf("Account not found.\n");
}

void withdraw(int accountNumber, float amount, char* description) {
    int i;
    for (i = 0; i < numAccounts; i++) {
        if (bankAccounts[i].accountNumber == accountNumber) {
            if (bankAccounts[i].balance >= amount) {
                bankAccounts[i].balance -= amount;
                transactionHistory[numTransactions].accountNumber = accountNumber;
                strcpy(transactionHistory[numTransactions].description, description);
                transactionHistory[numTransactions].amount = -amount;
                numTransactions++;
                printf("Withdrawal successful.\n");
            } else {
                printf("Insufficient balance.\n");
            }
            return;
        }
    }
    printf("Account not found.\n");
}

void displayAccount(int accountNumber) {
    int i;
    for (i = 0; i < numAccounts; i++) {
        if (bankAccounts[i].accountNumber == accountNumber) {
            printf("Account Number: %d\n", bankAccounts[i].accountNumber);
            printf("Balance: $%.2f\n", bankAccounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void displayTransactionHistory(int accountNumber) {
    int i;
    int count = 0;
    for (i = 0; i < numTransactions; i++) {
        if (transactionHistory[i].accountNumber == accountNumber) {
            printf("Transaction %d:\n", count+1);
            printf("Description: %s\n", transactionHistory[i].description);
            printf("Amount: $%.2f\n", transactionHistory[i].amount);
            count++;
        }
    }
    if (count == 0) {
        printf("No transactions found for account number %d.\n", accountNumber);
    }
}

int main() {
    int option;
    do {
        printf("\nSelect an option:\n");
        printf("1. Add account\n");
        printf("2. Make a deposit\n");
        printf("3. Make a withdrawal\n");
        printf("4. Display account details\n");
        printf("5. Display transaction history\n");
        printf("6. Exit\n");
        scanf("%d", &option);

        switch(option) {
            case 1:
                if (numAccounts >= MAX_ACCOUNTS) {
                    printf("Maximum number of accounts reached.\n");
                    break;
                }
                int accountNumber;
                float balance;
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter initial balance: ");
                scanf("%f", &balance);
                addAccount(accountNumber, balance);
                break;
            case 2:
                int depositAccountNumber;
                float depositAmount;
                char depositDescription[50];
                printf("Enter account number: ");
                scanf("%d", &depositAccountNumber);
                printf("Enter deposit amount: ");
                scanf("%f", &depositAmount);
                printf("Enter description: ");
                scanf("%s", depositDescription);
                deposit(depositAccountNumber, depositAmount, depositDescription);
                break;
            case 3:
                int withdrawAccountNumber;
                float withdrawAmount;
                char withdrawDescription[50];
                printf("Enter account number: ");
                scanf("%d", &withdrawAccountNumber);
                printf("Enter withdrawal amount: ");
                scanf("%f", &withdrawAmount);
                printf("Enter description: ");
                scanf("%s", withdrawDescription);
                withdraw(withdrawAccountNumber, withdrawAmount, withdrawDescription);
                break;
            case 4:
                int displayAccountNumber;
                printf("Enter account number: ");
                scanf("%d", &displayAccountNumber);
                displayAccount(displayAccountNumber);
                break;
            case 5:
                int displayTransactionAccountNumber;
                printf("Enter account number: ");
                scanf("%d", &displayTransactionAccountNumber);
                displayTransactionHistory(displayTransactionAccountNumber);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    } while (option != 6);

    return 0;
}