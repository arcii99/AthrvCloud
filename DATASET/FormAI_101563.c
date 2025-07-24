//FormAI DATASET v1.0 Category: Banking Record System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 1000
#define MAX_HISTORY 10

// Struct to store account information
typedef struct {
    int account_number;
    char name[50];
    double balance;
    char history[MAX_HISTORY][100];
    int history_count;
} Account;

// Global account array
Account accounts[MAX_ACCOUNTS];
int account_count = 0;

// Function to add a new account
void add_account(int account_number, char* name, double balance) {
    Account new_account;
    new_account.account_number = account_number;
    strcpy(new_account.name, name);
    new_account.balance = balance;
    new_account.history_count = 0;
    accounts[account_count++] = new_account;
}

// Function to get an account by account number
Account* get_account(int account_number) {
    for (int i = 0; i < account_count; i++) {
        if (accounts[i].account_number == account_number) {
            return &accounts[i];
        }
    }
    return NULL;
}

// Function to add a transaction to an account's history
void add_history(Account* account, char* transaction) {
    if (account->history_count >= MAX_HISTORY) {
        // Remove oldest transaction to make room for new one
        for (int i = 1; i < MAX_HISTORY; i++) {
            strcpy(account->history[i-1], account->history[i]);
        }
        account->history_count--;
    }
    strcpy(account->history[account->history_count++], transaction);
}

// Function to deposit money into an account
void deposit(int account_number, double amount) {
    Account* account = get_account(account_number);
    if (account == NULL) {
        printf("Account not found\n");
        return;
    }
    account->balance += amount;
    char transaction[100];
    sprintf(transaction, "Deposit of $%.2f", amount);
    add_history(account, transaction);
    printf("Deposit successful\n");
}

// Function to withdraw money from an account
void withdraw(int account_number, double amount) {
    Account* account = get_account(account_number);
    if (account == NULL) {
        printf("Account not found\n");
        return;
    }
    if (account->balance < amount) {
        printf("Insufficient balance\n");
        return;
    }
    account->balance -= amount;
    char transaction[100];
    sprintf(transaction, "Withdrawal of $%.2f", amount);
    add_history(account, transaction);
    printf("Withdrawal successful\n");
}

// Function to print an account's information
void print_account(Account* account) {
    printf("Account Number: %d\n", account->account_number);
    printf("Name: %s\n", account->name);
    printf("Balance: $%.2f\n", account->balance);
    printf("Transaction History:\n");
    for (int i = account->history_count-1; i >= 0; i--) {
        printf("- %s\n", account->history[i]);
    }
}

int main() {
    // Initialize accounts
    add_account(111111, "John Smith", 5000.0);
    add_account(222222, "Jane Doe", 10000.0);
    
    // Perform some transactions
    deposit(111111, 2000.0);
    withdraw(222222, 5000.0);
    deposit(111111, 1000.0);
    withdraw(222222, 3000.0);
    
    // Print account information
    print_account(get_account(111111));
    print_account(get_account(222222));
    
    return 0;
}