//FormAI DATASET v1.0 Category: Banking Record System ; Style: scientific
#include <stdio.h>
#include <string.h>

struct Transaction {
    int date;
    char type[10];
    float amount;
};

struct Account {
    char accountNumber[20];
    char accountHolder[50];
    float balance;
    struct Transaction transactions[1000];
    int transactionCount;
} accounts[1000];

int accountCount = 0;

// Function to create a new account
void createAccount(char accountNumber[], char accountHolder[]) {
    struct Account newAccount;
    strcpy(newAccount.accountNumber, accountNumber);
    strcpy(newAccount.accountHolder, accountHolder);
    newAccount.balance = 0;
    newAccount.transactionCount = 0;
    accounts[accountCount] = newAccount;
    accountCount++;
}

// Function to add a transaction to an account
void addTransaction(char accountNumber[], int date, char type[], float amount) {
    int i;
    for (i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            struct Transaction newTransaction;
            newTransaction.date = date;
            strcpy(newTransaction.type, type);
            newTransaction.amount = amount;
            accounts[i].transactions[accounts[i].transactionCount] = newTransaction;
            accounts[i].transactionCount++;
            if (strcmp(type, "credit") == 0) {
                accounts[i].balance += amount;
            } else {
                accounts[i].balance -= amount;
            }
        }
    }
}

// Main function
int main() {
    createAccount("123456", "John Doe");
    createAccount("789012", "Jane Smith");
    addTransaction("123456", 20220101, "credit", 1000.0);
    addTransaction("123456", 20220102, "debit", 500.0);
    addTransaction("789012", 20220103, "credit", 2000.0);
    int i;
    for (i = 0; i < accountCount; i++) {
        printf("Account Number: %s\n", accounts[i].accountNumber);
        printf("Account Holder: %s\n", accounts[i].accountHolder);
        printf("Balance: %.2f\n", accounts[i].balance);
        printf("Transactions:\n");
        int j;
        for (j = 0; j < accounts[i].transactionCount; j++) {
            printf("%d %8s %.2f\n",
                accounts[i].transactions[j].date,
                accounts[i].transactions[j].type,
                accounts[i].transactions[j].amount
            );
        }
        printf("\n");
    }
    return 0;
}