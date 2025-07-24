//FormAI DATASET v1.0 Category: Banking Record System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 10000
#define MAX_TRANSACTIONS 100000

typedef struct {
    int account_number;
    char name[100];
    double balance;
} Account;

typedef struct {
    int from_account;
    int to_account;
    double amount;
} Transaction;

int num_accounts = 0;
Account accounts[MAX_ACCOUNTS];

int num_transactions = 0;
Transaction transactions[MAX_TRANSACTIONS];

void print_account_info(Account account) {
    printf("Account Number: %d\n", account.account_number);
    printf("Name: %s\n", account.name);
    printf("Balance: $%.2f\n", account.balance);
    printf("\n");
}

void add_account(int account_number, char* name, double balance) {
    Account account;
    account.account_number = account_number;
    strcpy(account.name, name);
    account.balance = balance;
    accounts[num_accounts] = account;
    num_accounts++;
}

void transfer_funds(int from_account_number, int to_account_number, double amount) {
    Account* from_account = NULL;
    Account* to_account = NULL;
    int i;
    for(i = 0; i < num_accounts; i++) {
        if(accounts[i].account_number == from_account_number) {
            from_account = &accounts[i];
        }
        else if(accounts[i].account_number == to_account_number) {
            to_account = &accounts[i];
        }
        if(from_account != NULL && to_account != NULL) break;
    }
    if(from_account == NULL) {
        printf("Error: Account with account number %d not found\n", from_account_number);
        return;
    }
    if(to_account == NULL) {
        printf("Error: Account with account number %d not found\n", to_account_number);
        return;
    }
    if(from_account->balance < amount) {
        printf("Error: Insufficient funds\n");
        return;
    }
    from_account->balance -= amount;
    to_account->balance += amount;
    Transaction transaction;
    transaction.from_account = from_account_number;
    transaction.to_account = to_account_number;
    transaction.amount = amount;
    transactions[num_transactions] = transaction;
    num_transactions++;
}

void print_transaction_info(Transaction transaction) {
    printf("From Account Number: %d\n", transaction.from_account);
    printf("To Account Number: %d\n", transaction.to_account);
    printf("Amount: $%.2f\n", transaction.amount);
    printf("\n");
}

void print_transactions_for_account(int account_number) {
    int i;
    for(i = 0; i < num_transactions; i++) {
        if(transactions[i].from_account == account_number
            || transactions[i].to_account == account_number) {
            print_transaction_info(transactions[i]);
        }
    }
}

int main() {
    add_account(12345, "John Smith", 5000.00);
    add_account(67890, "Jane Doe", 10000.00);
    add_account(24680, "Bob Johnson", 7500.00);

    transfer_funds(12345, 67890, 2500.00);
    transfer_funds(24680, 12345, 1000.00);

    printf("Account Information:\n");
    int i;
    for(i = 0; i < num_accounts; i++) {
        print_account_info(accounts[i]);
        printf("Transaction History:\n");
        print_transactions_for_account(accounts[i].account_number);
    }

    return 0;
}