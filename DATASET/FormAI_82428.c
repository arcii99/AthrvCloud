//FormAI DATASET v1.0 Category: Banking Record System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100 // maximum number of accounts that can be stored
#define MAX_TRANSACTIONS 1000 // maximum number of transactions that can be stored per account

struct Transaction {
    char date[11]; // format dd/mm/yyyy
    char description[100];
    double amount;
};

struct Account {
    char accountNumber[11]; // format XX-XXXX-XXXX
    char holderName[100];
    double balance;
    struct Transaction transactions[MAX_TRANSACTIONS];
    int numTransactions;
};

struct Bank {
    struct Account accounts[MAX_ACCOUNTS];
    int numAccounts;
};

void addAccount(struct Bank *bank, struct Account account) {
    if (bank->numAccounts >= MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached.");
        return;
    }
    bank->accounts[bank->numAccounts] = account;
    bank->numAccounts++;
    printf("Account added successfully.\n");
}

void addTransaction(struct Account *account, struct Transaction transaction) {
    if (account->numTransactions >= MAX_TRANSACTIONS) {
        printf("Maximum number of transactions reached for this account.");
        return;
    }
    account->transactions[account->numTransactions] = transaction;
    account->numTransactions++;
    account->balance += transaction.amount;
    printf("Transaction added successfully.\n");
}

void viewTransactions(struct Account account) {
    if (account.numTransactions == 0) {
        printf("No transactions found for this account.\n");
        return;
    }
    printf("\nAccount Number: %s\nHolder Name: %s\nBalance: %.2lf\n", account.accountNumber, account.holderName, account.balance);
    printf("\nTransactions:\n");
    for (int i = 0; i < account.numTransactions; i++) {
        printf("Date: %s\nDescription: %s\nAmount: %.2lf\n\n", account.transactions[i].date, account.transactions[i].description, account.transactions[i].amount);
    }
}

int main() {
    struct Bank bank;
    bank.numAccounts = 0;
    int option;
    
    do {
        printf("\nWelcome to the Banking Record System.\n");
        printf("Please select an option:\n");
        printf("1. Add account\n");
        printf("2. Add transaction\n");
        printf("3. View transactions for an account\n");
        printf("4. Exit\n");
        printf("Option: ");
        scanf("%d", &option);
        
        switch(option) {
            case 1: {
                struct Account account;
                printf("Enter account number (format XX-XXXX-XXXX): ");
                scanf("%s", account.accountNumber);
                printf("Enter holder name: ");
                scanf(" %[^\n]s", account.holderName);
                account.balance = 0.0;
                account.numTransactions = 0;
                addAccount(&bank, account);
                break;
            }
            case 2: {
                char accountNumber[11];
                printf("Enter account number (format XX-XXXX-XXXX): ");
                scanf("%s", accountNumber);
                int accountIndex = -1;
                for (int i = 0; i < bank.numAccounts; i++) {
                    if (strcmp(bank.accounts[i].accountNumber, accountNumber) == 0) {
                        accountIndex = i;
                        break;
                    }
                }
                if (accountIndex == -1) {
                    printf("Account not found.\n");
                    break;
                }
                struct Transaction transaction;
                printf("Enter date (format dd/mm/yyyy): ");
                scanf("%s", transaction.date);
                printf("Enter description: ");
                scanf(" %[^\n]s", transaction.description);
                printf("Enter amount: ");
                scanf("%lf", &transaction.amount);
                addTransaction(&bank.accounts[accountIndex], transaction);
                break;
            }
            case 3: {
                char accountNumber[11];
                printf("Enter account number (format XX-XXXX-XXXX): ");
                scanf("%s", accountNumber);
                int accountIndex = -1;
                for (int i = 0; i < bank.numAccounts; i++) {
                    if (strcmp(bank.accounts[i].accountNumber, accountNumber) == 0) {
                        accountIndex = i;
                        break;
                    }
                }
                if (accountIndex == -1) {
                    printf("Account not found.\n");
                    break;
                }
                viewTransactions(bank.accounts[accountIndex]);
                break;
            }
            case 4: {
                printf("Exiting program.\n");
                break;
            }
            default: {
                printf("Invalid option selected.\n");
                break;
            }
        }
    } while (option != 4);
    
    return 0;
}