//FormAI DATASET v1.0 Category: Banking Record System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    int accountNo;
    char name[50];
    float balance;
};

void displayAccount(struct Account acc) {
    printf("Account Number: %d\n", acc.accountNo);
    printf("Name: %s\n", acc.name);
    printf("Balance: $%.2f\n\n", acc.balance);
}

void deposit(struct Account *acc, float amount) {
    acc->balance += amount;
}

void withdraw(struct Account *acc, float amount) {
    if (acc->balance - amount < 0) {
        printf("Insufficient Funds\n\n");
    }
    else {
        acc->balance -= amount;
    }
}

int main() {
    struct Account accounts[10];
    int numAccounts = 0;
    int menuChoice = 0;
    int accountChoice = 0;

    printf("Welcome to the C Banking Record System!\n\n");

    while (menuChoice != 4) {
        printf("Choose an option:\n");
        printf("1) Create Account\n");
        printf("2) Display Account\n");
        printf("3) Make Transaction\n");
        printf("4) Exit\n\n");

        scanf("%d", &menuChoice);

        switch (menuChoice) {
            case 1: 
                if (numAccounts < 10) {
                    printf("Enter Account Number: ");
                    scanf("%d", &accounts[numAccounts].accountNo);
                    fflush(stdin);

                    printf("Enter Name: ");
                    fgets(accounts[numAccounts].name, sizeof(accounts[numAccounts].name), stdin);
                    accounts[numAccounts].name[strlen(accounts[numAccounts].name) - 1] = '\0';

                    printf("Enter Initial Balance: ");
                    scanf("%f", &accounts[numAccounts].balance);

                    numAccounts++;

                    printf("\nAccount Created Successfuly!\n\n");
                }
                else {
                    printf("Maximum Number of Accounts Reached\n\n");
                }
                break;

            case 2: 
                if (numAccounts > 0) {
                    printf("Choose Account:\n");
                    for (int i = 0; i < numAccounts; i++) {
                        printf("%d) %s\n", i + 1, accounts[i].name);
                    }

                    scanf("%d", &accountChoice);

                    printf("\n");
                    displayAccount(accounts[accountChoice - 1]);
                }
                else {
                    printf("No Accounts Exist\n\n");
                }
                break;

            case 3: 
                if (numAccounts > 0) {
                    printf("Choose Account:\n");
                    for (int i = 0; i < numAccounts; i++) {
                        printf("%d) %s\n", i + 1, accounts[i].name);
                    }

                    scanf("%d", &accountChoice);

                    printf("Choose Transaction:\n");
                    printf("1) Deposit\n");
                    printf("2) Withdrawal\n\n");

                    int transactionChoice = 0;
                    scanf("%d", &transactionChoice);

                    float amount = 0;

                    switch (transactionChoice) {
                        case 1:
                            printf("Enter Amount to Deposit: ");
                            scanf("%f", &amount);

                            deposit(&accounts[accountChoice - 1], amount);

                            printf("\n");
                            displayAccount(accounts[accountChoice - 1]);
                            break;

                        case 2:
                            printf("Enter Amount to Withdraw: ");
                            scanf("%f", &amount);

                            withdraw(&accounts[accountChoice - 1], amount);

                            printf("\n");
                            displayAccount(accounts[accountChoice - 1]);
                            break;

                        default:
                            printf("Invalid Transaction Choice\n\n");
                            break;
                    }
                }
                else {
                    printf("No Accounts Exist\n\n");
                }
                break;

            case 4:
                printf("Exiting...\n\n");
                break;

            default:
                printf("Invalid Menu Choice\n\n");
                break;
        }
    }

    return 0;
}