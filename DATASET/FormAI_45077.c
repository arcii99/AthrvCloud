//FormAI DATASET v1.0 Category: Banking Record System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the structure for a medieval-style bank account */
struct medieval_bank_account {
    char name[25];
    int account_number;
    int balance;
};

/* Define function for creating a new bank account */
struct medieval_bank_account create_account(char name[], int account_num) {
    struct medieval_bank_account new_account;
    strcpy(new_account.name, name);
    new_account.account_number = account_num;
    new_account.balance = 0;
    return new_account;
}

/* Define function for depositing money into an account */
void deposit(struct medieval_bank_account* account, int amount) {
    account->balance += amount;
}

/* Define function for withdrawing money from an account */
void withdraw(struct medieval_bank_account* account, int amount) {
    if (account->balance >= amount) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds!\n");
    }
}

/* Define function for displaying the account details */
void display_account(struct medieval_bank_account account) {
    printf("Account Name: %s\n", account.name);
    printf("Account Number: %d\n", account.account_number);
    printf("Balance: %d\n", account.balance);
}

/* Define the main function */
int main() {
    struct medieval_bank_account account1 = create_account("Sir Lancelot", 1);
    struct medieval_bank_account account2 = create_account("Sir Galahad", 2);
    
    /* Deposit and withdraw some amount from the accounts */
    deposit(&account1, 100);
    withdraw(&account1, 50);
    deposit(&account2, 200);
    withdraw(&account2, 300);
    
    /* Display the account details */
    printf("Account Details:\n");
    display_account(account1);
    display_account(account2);
    
    return 0;
}