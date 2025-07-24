//FormAI DATASET v1.0 Category: Banking Record System ; Style: happy
#include<stdio.h>

// Define a structure for bank account details
struct account_details {
    char name[50];
    int account_number;
    float balance;
};

// Function to deposit amount
float deposit_amount(float balance, float amount)
{
    balance += amount;
    return balance;
}

// Function to withdraw amount
float withdraw_amount(float balance, float amount)
{
    if (amount <= balance) {
        balance -= amount;
    } else {
        printf("Insufficient balance!\n");
    }
    return balance;
}

// Function to display account details
void display_account_details(struct account_details account)
{
    printf("Account details:\n");
    printf("Name: %s\n", account.name);
    printf("Account number: %d\n", account.account_number);
    printf("Balance: %.2f\n", account.balance);
}

int main()
{
    // Declare an array of account details
    struct account_details accounts[100];
    
    // Initialize the array
    for (int i = 0; i < 100; i++) {
        accounts[i].name[0] = '\0';
        accounts[i].account_number = 0;
        accounts[i].balance = 0.0;
    }
    
    // Add new account
    accounts[0].account_number = 1000;
    strcpy(accounts[0].name, "John Smith");
    accounts[0].balance = 500.0;
    
    printf("Welcome to Happy Bank!\n");
    printf("We have added a new account:\n");
    display_account_details(accounts[0]);
    
    // Deposit some amount
    float amount = 100.0;
    printf("Depositing $%.2f into account %d...\n", amount, accounts[0].account_number);
    accounts[0].balance = deposit_amount(accounts[0].balance, amount);
    display_account_details(accounts[0]);
    
    // Withdraw some amount
    amount = 200.0;
    printf("Withdrawing $%.2f from account %d...\n", amount, accounts[0].account_number);
    accounts[0].balance = withdraw_amount(accounts[0].balance, amount);
    display_account_details(accounts[0]);
    
    return 0;
}