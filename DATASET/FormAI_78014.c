//FormAI DATASET v1.0 Category: Banking Record System ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Transaction {
    char type[10];
    int amount;
    char currency[10];
    char description[50];
};

struct TransactionHistory {
    struct Transaction transaction;
    struct TransactionHistory* next;
};

struct Account {
    int accountNumber;
    char ownerName[20];
    int balance;
    struct TransactionHistory* history;
};

int generateAccountNumber() {
    static int currentAccountNumber = 10001;
    return currentAccountNumber++;
}

void deposit(struct Account *account, int amount, char currency[], char description[]) {
    account->balance += amount;
    
    struct Transaction transaction;
    strcpy(transaction.type, "DEPOSIT");
    transaction.amount = amount;
    strcpy(transaction.currency, currency);
    strcpy(transaction.description, description);
    
    struct TransactionHistory *node = (struct TransactionHistory*) malloc(sizeof(struct TransactionHistory));
    node->transaction = transaction;
    node->next = account->history;
    account->history = node;
    
    printf("Deposited %d %s in your account.\n", amount, currency);
}

void withdraw(struct Account *account, int amount, char currency[], char description[]) {
    if(account->balance < amount) {
        printf("Sorry, you do not have sufficient balance to withdraw.\n");
    }
    else {
        account->balance -= amount;
        
        struct Transaction transaction;
        strcpy(transaction.type, "WITHDRAW");
        transaction.amount = amount;
        strcpy(transaction.currency, currency);
        strcpy(transaction.description, description);
        
        struct TransactionHistory *node = (struct TransactionHistory*) malloc(sizeof(struct TransactionHistory));
        node->transaction = transaction;
        node->next = account->history;
        account->history = node;
        
        printf("Withdrawn %d %s from your account.\n", amount, currency);
    }
}

void viewBalance(struct Account *account) {
    printf("Your account balance is %d.\n", account->balance);
}

void viewTransactionHistory(struct Account *account) {
    struct TransactionHistory *temp = account->history;
    printf("---------------------------------------------\n");
    printf("\tTRANSACTION HISTORY\n");
    printf("---------------------------------------------\n");
    printf("%-10s %-10s %-20s %-50s\n", "TYPE", "AMOUNT", "CURRENCY", "DESCRIPTION");
    printf("---------------------------------------------\n");
    while(temp != NULL) {
        printf("%-10s %-10d %-20s %-50s\n", temp->transaction.type, temp->transaction.amount, temp->transaction.currency, temp->transaction.description);
        temp = temp->next;
    }
    printf("---------------------------------------------\n");
}

int main() {
    struct Account account;
    account.accountNumber = generateAccountNumber();
    strcpy(account.ownerName, "Sir Lancelot");
    account.balance = 1000;
    account.history = NULL;
    
    printf("Welcome, Sir Lancelot. Your account number is %d.\n", account.accountNumber);
    
    char choice;
    while(1) {
        printf("\nMENU:\n1. Deposit\n2. Withdraw\n3. View Balance\n4. View Transaction History\n5. Exit\nEnter your choice: ");
        scanf(" %c", &choice);
        
        switch(choice) {
            case '1': {
                int amount;
                char currency[10];
                char description[50];
                printf("Enter amount to be deposited: ");
                scanf("%d", &amount);
                printf("Enter currency: ");
                scanf("%s", currency);
                printf("Enter description: ");
                scanf(" %[^\n]", description);
                
                deposit(&account, amount, currency, description);
                break;
            }
            case '2': {
                int amount;
                char currency[10];
                char description[50];
                printf("Enter amount to be withdrawn: ");
                scanf("%d", &amount);
                printf("Enter currency: ");
                scanf("%s", currency);
                printf("Enter description: ");
                scanf(" %[^\n]", description);
                
                withdraw(&account, amount, currency, description);
                break;
            }
            case '3': {
                viewBalance(&account);
                break;
            }
            case '4': {
                viewTransactionHistory(&account);
                break;
            }
            case '5': {
                printf("Thank you for using our services.\n");
                exit(0);
            }
            default: {
                printf("Invalid choice, please try again.\n");
                break;
            }
        }
    }
    
    return 0;
}