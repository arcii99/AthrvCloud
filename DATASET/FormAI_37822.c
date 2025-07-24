//FormAI DATASET v1.0 Category: Banking Record System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 1000
#define MAX_AMOUNT 10000

struct Transaction {
    int account_number;
    int amount;
    char description[100];
};

struct Account {
    int account_number;
    int balance;
    char owner[50];
    struct Transaction transaction_history[MAX_TRANSACTIONS];
    int num_transactions;
};

struct Bank {
    struct Account accounts[MAX_ACCOUNTS];
    int num_accounts;
};

void print_account(struct Account account) {
    printf("Account Number: %d\n", account.account_number);
    printf("Owner: %s\n", account.owner);
    printf("Balance: %d\n", account.balance);
    printf("Transaction History:\n");
    for (int i = 0; i < account.num_transactions; i++) {
        printf("Transaction #%d: %s - %d\n", i+1, account.transaction_history[i].description, account.transaction_history[i].amount);
    }
    printf("\n");
}

void deposit(struct Account *account, int amount, char *description) {
    if (amount > 0 && amount <= MAX_AMOUNT) {
        account->balance += amount;
        strcpy(account->transaction_history[account->num_transactions].description, description);
        account->transaction_history[account->num_transactions].amount = amount;
        account->num_transactions++;
        printf("%d deposited successfully! New balance is %d\n", amount, account->balance);
    } else {
        printf("Invalid amount!\n");
    }
}

void withdraw(struct Account *account, int amount, char *description) {
    if (amount > 0 && amount <= MAX_AMOUNT && amount <= account->balance) {
        account->balance -= amount;
        strcpy(account->transaction_history[account->num_transactions].description, description);
        account->transaction_history[account->num_transactions].amount = -amount;
        account->num_transactions++;
        printf("%d withdrawn successfully! New balance is %d\n", amount, account->balance);
    } else {
        printf("Invalid amount or insufficient balance!\n");
    }
}

struct Account *get_account(struct Bank *bank, int account_number) {
    for (int i = 0; i < bank->num_accounts; i++) {
        if (bank->accounts[i].account_number == account_number) {
            return &bank->accounts[i];
        }
    }
    return NULL;
}

void add_account(struct Bank *bank, char *owner) {
    if (bank->num_accounts < MAX_ACCOUNTS) {
        struct Account new_account;
        new_account.account_number = 1000 + bank->num_accounts;
        new_account.balance = 0;
        strcpy(new_account.owner, owner);
        new_account.num_transactions = 0;
        bank->accounts[bank->num_accounts] = new_account;
        bank->num_accounts++;
        printf("%s's account created successfully! Account number is %d\n", owner, new_account.account_number);
    } else {
        printf("Maximum number of accounts reached!\n");
    }
}

int main() {
    struct Bank bank;
    bank.num_accounts = 0;
    int option;
    do {
        printf("Welcome to MyBank!\n");
        printf("1. Add Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. View Account\n");
        printf("5. Exit\n");
        printf("Enter option (1-5): ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                printf("Enter owner name: ");
                char owner[50];
                scanf("%s", owner);
                add_account(&bank, owner);
                break;
            case 2:
                printf("Enter account number: ");
                int account_number;
                scanf("%d", &account_number);
                struct Account *account;
                account = get_account(&bank, account_number);
                if (account == NULL) {
                    printf("Invalid account number!\n");
                } else {
                    printf("Enter amount to deposit: ");
                    int amount;
                    scanf("%d", &amount);
                    printf("Enter description: ");
                    char description[100];
                    scanf("%s", description);
                    deposit(account, amount, description);
                }
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                account = get_account(&bank, account_number);
                if (account == NULL) {
                    printf("Invalid account number!\n");
                } else {
                    printf("Enter amount to withdraw: ");
                    int amount;
                    scanf("%d", &amount);
                    printf("Enter description: ");
                    char description[100];
                    scanf("%s", description);
                    withdraw(account, amount, description);
                }
                break;
            case 4:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                account = get_account(&bank, account_number);
                if (account == NULL) {
                    printf("Invalid account number!\n");
                } else {
                    print_account(*account);
                }
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option!\n");
                break;
        }
    } while (option != 5);
    return 0;
}