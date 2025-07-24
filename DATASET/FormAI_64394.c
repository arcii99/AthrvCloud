//FormAI DATASET v1.0 Category: Banking Record System ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Transaction {
    char transactionType[20];
    char transactionDate[20];
    int transactionAmount;
};

struct Account {
    int accountNo;
    char accountHolderName[50];
    int balance;
    struct Transaction transactions[50];
    int transactionCount;
};

int main() {
    struct Account accounts[10];
    int accountCount = 3;
    int i, j, accountNo, transactionAmount;
    char transactionType[20], transactionDate[20], accountHolderName[50], temp;

    //Initialize accounts
    strcpy(accounts[0].accountHolderName, "John Doe");
    accounts[0].accountNo = 101;
    accounts[0].balance = 5000;
    accounts[0].transactionCount = 2;
    strcpy(accounts[0].transactions[0].transactionType, "Deposit");
    strcpy(accounts[0].transactions[0].transactionDate, "01/02/2021");
    accounts[0].transactions[0].transactionAmount = 3000;
    strcpy(accounts[0].transactions[1].transactionType, "Withdrawal");
    strcpy(accounts[0].transactions[1].transactionDate, "05/03/2021");
    accounts[0].transactions[1].transactionAmount = 2000;

    strcpy(accounts[1].accountHolderName, "Jane Smith");
    accounts[1].accountNo = 102;
    accounts[1].balance = 10000;
    accounts[1].transactionCount = 1;
    strcpy(accounts[1].transactions[0].transactionType, "Deposit");
    strcpy(accounts[1].transactions[0].transactionDate, "23/06/2021");
    accounts[1].transactions[0].transactionAmount = 5000;

    strcpy(accounts[2].accountHolderName, "Bob Williams");
    accounts[2].accountNo = 103;
    accounts[2].balance = 7500;
    accounts[2].transactionCount = 3;
    strcpy(accounts[2].transactions[0].transactionType, "Deposit");
    strcpy(accounts[2].transactions[0].transactionDate, "15/01/2021");
    accounts[2].transactions[0].transactionAmount = 2000;
    strcpy(accounts[2].transactions[1].transactionType, "Withdrawal");
    strcpy(accounts[2].transactions[1].transactionDate, "25/02/2021");
    accounts[2].transactions[1].transactionAmount = 1500;
    strcpy(accounts[2].transactions[2].transactionType, "Deposit");
    strcpy(accounts[2].transactions[2].transactionDate, "18/07/2021");
    accounts[2].transactions[2].transactionAmount = 500;

    printf("Welcome to the Banking Record System!\n");
    printf("Enter 'a' to view all accounts, 'd' to view an account's details, 'n' to create a new account, or 'e' to exit: ");
    scanf("%c", &temp);

    while(temp != 'e') {
        if(temp == 'a') {
            printf("\nAll accounts:\n");

            for(i = 0; i < accountCount; i++) {
                printf("%d. Account No: %d, Account Holder Name: %s, Balance: %d\n", i+1, accounts[i].accountNo, accounts[i].accountHolderName, accounts[i].balance);
            }
        }
        else if(temp == 'd') {
            printf("\nEnter the account number: ");
            scanf("%d", &accountNo);

            for(i = 0; i < accountCount; i++) {
                if(accounts[i].accountNo == accountNo) {
                    printf("\nAccount Details:\n\n");
                    printf("Account No: %d\n", accountNo);
                    printf("Account Holder Name: %s\n", accounts[i].accountHolderName);
                    printf("Balance: %d\n", accounts[i].balance);

                    printf("\nTransaction History:\n");

                    for(j = 0; j < accounts[i].transactionCount; j++) {
                        printf("%d. Transaction Type: %s, Transaction Date: %s, Transaction Amount: %d\n", j+1, accounts[i].transactions[j].transactionType, accounts[i].transactions[j].transactionDate, accounts[i].transactions[j].transactionAmount);
                    }

                    break;
                }
            }

            if(i == accountCount) {
                printf("Account not found!\n");
            }
        }
        else if(temp == 'n') {
            printf("\nEnter the account holder name: ");
            scanf("%s", accountHolderName);
            printf("Enter the account number: ");
            scanf("%d", &accountNo);
            printf("Enter the initial balance: ");
            scanf("%d", &transactionAmount);

            accounts[accountCount].accountNo = accountNo;
            accounts[accountCount].balance = transactionAmount;
            strcpy(accounts[accountCount].accountHolderName, accountHolderName);
            accounts[accountCount].transactionCount = 1;
            strcpy(accounts[accountCount].transactions[0].transactionType, "Deposit");
            printf("Enter the transaction date (dd/mm/yyyy): ");
            scanf("%s", accounts[accountCount].transactions[0].transactionDate);
            accounts[accountCount].transactions[0].transactionAmount = transactionAmount;

            accountCount++;

            printf("New account created successfully!\n");
        }
        else {
            printf("Invalid input! Please enter 'a', 'd', 'n' or 'e'.\n");
        }

        printf("\nEnter 'a' to view all accounts, 'd' to view an account's details, 'n' to create a new account, or 'e' to exit: ");
        scanf(" %c", &temp);
    }

    return 0;
}