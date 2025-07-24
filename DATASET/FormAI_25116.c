//FormAI DATASET v1.0 Category: Banking Record System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define maximum number of transactions within an account
#define MAX_TRANSACTIONS 100

// define transaction structure
typedef struct Transaction {
    char date[15];
    double amount;
    char description[50];
} Transaction;

// define account structure
typedef struct Account {
    char name[30];
    char accountNumber[10];
    double balance;
    Transaction transactions[MAX_TRANSACTIONS];
    int transactionCount;
} Account;

// function to add a transaction to an account
void addTransaction(Account *account, Transaction transaction) {
    // check if transaction exceeds maximum number of transactions
    if (account->transactionCount >= MAX_TRANSACTIONS) {
        printf("\nTransaction limit reached for account %s", account->accountNumber);
        return;
    }
    // add transaction to account and update balance
    account->transactions[account->transactionCount] = transaction;
    account->balance += transaction.amount;
    account->transactionCount++;
}

// function to print account details and transaction history
void displayAccount(Account account) {
    printf("\nAccount Name: %s", account.name);
    printf("\nAccount Number: %s", account.accountNumber);
    printf("\nBalance: $%0.2f", account.balance);
    printf("\nTransaction History:");
    printf("\n---------------------------------------------------");
    printf("\nDate\t\tAmount\tDescription");
    printf("\n---------------------------------------------------");
    for (int i = 0; i < account.transactionCount; i++) {
        printf("\n%s\t$%0.2f\t%s", account.transactions[i].date, account.transactions[i].amount, account.transactions[i].description);
    }
    printf("\n---------------------------------------------------");
}

int main() {
    // create accounts
    Account account1 = { "John Smith", "12345678", 0 };
    Account account2 = { "Jane Doe", "87654321", 0 };
    
    // add transactions to account1
    addTransaction(&account1, (Transaction) { "01/01/2022", 1000, "Deposit" });
    addTransaction(&account1, (Transaction) { "01/02/2022", -500, "Withdrawal" });
    addTransaction(&account1, (Transaction) { "01/03/2022", 200, "Deposit" });
    
    // add transactions to account2
    addTransaction(&account2, (Transaction) { "01/01/2022", 500, "Deposit" });
    addTransaction(&account2, (Transaction) { "01/02/2022", -300, "Withdrawal" });
    
    // display account details
    displayAccount(account1);
    displayAccount(account2);
    
    return 0;
}