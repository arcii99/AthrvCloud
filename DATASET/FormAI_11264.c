//FormAI DATASET v1.0 Category: Banking Record System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[100];
    char account_number[20];
    int balance;
    int transaction_history[100];
    int num_transactions;
} account;

void print_transactions(account acc) {
    printf("Transaction History for Account %s:\n", acc.account_number);
    for(int i = 0; i < acc.num_transactions; i++) {
        printf("[%d] %d\n", i+1, acc.transaction_history[i]);
    }
}

void deposit(account *acc, int amount) {
    printf("Deposit Success! %d credited to Account %s\n", amount, acc->account_number);
    acc->balance += amount;
    acc->transaction_history[acc->num_transactions++] = amount;
}

void withdraw(account *acc, int amount) {
    if(acc->balance < amount) {
        printf("Withdraw Failed! Insufficient Balance for Account %s\n", acc->account_number);
    } else {
        printf("Withdraw Success! %d debited from Account %s\n", amount, acc->account_number);
        acc->balance -= amount;
        acc->transaction_history[acc->num_transactions++] = -amount;
    }
}

void check_balance(account acc) {
    printf("Account Number: %s\n", acc.account_number);
    printf("Name: %s\n", acc.name);
    printf("Balance: %d\n", acc.balance);
}

void transfer(account *acc1, account *acc2, int amount) {
    if(acc1->balance < amount) {
        printf("Transfer Failed! Insufficient Balance for Account %s\n", acc1->account_number);
    } else {
        printf("Transfer Success! %d transferred from Account %s to Account %s\n", amount, acc1->account_number, acc2->account_number);
        acc1->balance -= amount;
        acc2->balance += amount;
        acc1->transaction_history[acc1->num_transactions++] = -amount;
        acc2->transaction_history[acc2->num_transactions++] = amount;
    }
}

int main() {
    srand(time(NULL));
    account accounts[10];
    for(int i = 0; i < 10; i++) {
        sprintf(accounts[i].account_number, "ACC-%07d", rand() % 10000000);
        strcpy(accounts[i].name, "John Doe");
        accounts[i].balance = rand() % 10000;
        accounts[i].num_transactions = 0;
    }
    int choice, amount, account_choice1, account_choice2;
    do {
        printf("\nBank Record System\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check Balance\n");
        printf("4. Transfer\n");
        printf("5. Print Transaction History\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the Account Number: ");
                scanf("%d", &account_choice1);
                printf("Enter the Deposit Amount: ");
                scanf("%d", &amount);
                deposit(&accounts[account_choice1-1], amount);
                break;
            case 2:
                printf("Enter the Account Number: ");
                scanf("%d", &account_choice1);
                printf("Enter the Withdrawal Amount: ");
                scanf("%d", &amount);
                withdraw(&accounts[account_choice1-1], amount);
                break;
            case 3:
                printf("Enter the Account Number: ");
                scanf("%d", &account_choice1);
                check_balance(accounts[account_choice1-1]);
                break;
            case 4:
                printf("Enter the Source Account Number: ");
                scanf("%d", &account_choice1);
                printf("Enter the Destination Account Number: ");
                scanf("%d", &account_choice2);
                printf("Enter the Transfer Amount: ");
                scanf("%d", &amount);
                transfer(&accounts[account_choice1-1], &accounts[account_choice2-1], amount);
                break;
            case 5:
                printf("Enter the Account Number: ");
                scanf("%d", &account_choice1);
                print_transactions(accounts[account_choice1-1]);
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 6);
    return 0;
}