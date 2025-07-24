//FormAI DATASET v1.0 Category: Banking Record System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
    int acc_number;
    char name[50];
    float balance;
};

typedef struct account Account;

void deposit(Account* acc, float amount) {
    acc->balance += amount;
    printf("Deposit of $%.2f was successful, new balance: $%.2f\n", amount, acc->balance);
}

void withdraw(Account* acc, float amount) {
    if (amount > acc->balance) {
        printf("Withdrawal failed! Not enough funds available.\n");
    } else {
        acc->balance -= amount;
        printf("Withdrawal of $%.2f was successful, new balance: $%.2f\n", amount, acc->balance);
    }
}

void display(Account* acc) {
    printf("Account Details:\n");
    printf("Name: %s\n", acc->name);
    printf("Account Number: %d\n", acc->acc_number);
    printf("Account Balance: $%.2f\n", acc->balance);
}

int main() {
    Account acc1;
    acc1.acc_number = 123456;
    strcpy(acc1.name, "John Doe");
    acc1.balance = 1000.00;

    // Deposit some money into account
    deposit(&acc1, 500.00);

    // Withdraw some money from account
    withdraw(&acc1, 200.00);

    // Display account details
    display(&acc1);

    return 0;
}