//FormAI DATASET v1.0 Category: Banking Record System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[50];
    int accNum;
    float balance;
} Account;

// Function to check if a string is numeric
int isNumeric(char str[]) {
    char *endptr;
    strtol(str, &endptr, 10);
    return *endptr == '\0';
}

int main() {
    int choice, numAccounts = 0;
    char input[50];
    Account accounts[100];

    printf("Welcome to the Banking Record System!\n");
    printf("-------------------------------------\n");

    // Loop through until the user chooses to exit
    while (1) {
        printf("1. Add a new account\n");
        printf("2. View all accounts\n");
        printf("3. Search for an account\n");
        printf("4. Exit\n");

        printf("Please enter your choice: ");
        fgets(input, 50, stdin);
        
        // Check if the input is a number between 1-4
        if (isNumeric(input) && atoi(input) >= 1 && atoi(input) <= 4) {
            choice = atoi(input);
            printf("\n");

            // Add a new account
            if (choice == 1) {
                printf("Adding a new account\n");
                printf("--------------------\n");

                printf("Please enter the name of the account holder: ");
                fgets(accounts[numAccounts].name, 50, stdin);

                printf("Please enter the account number: ");
                fgets(input, 50, stdin);

                // Check if the account number is numeric
                if (isNumeric(input)) {
                    accounts[numAccounts].accNum = atoi(input);
                } else {
                    printf("Error: Please enter a valid account number\n\n");
                    continue;
                }

                printf("Please enter the balance: ");
                fgets(input, 50, stdin);

                // Check if the balance is numeric
                if (isNumeric(input)) {
                    accounts[numAccounts].balance = atof(input);
                } else {
                    printf("Error: Please enter a valid balance\n\n");
                    continue;
                }

                numAccounts++;
                printf("Account added successfully!\n\n");

            // View all accounts
            } else if (choice == 2) {
                printf("Viewing all accounts\n");
                printf("--------------------\n");

                // Check if there are any accounts
                if (numAccounts == 0) {
                    printf("No accounts found!\n\n");
                    continue;
                }

                // Print the header
                printf("%-20s %-20s %-20s\n", "Name", "Account Number", "Balance");
                printf("----------------------------------------------------------------\n");

                // Loop through all the accounts and print them
                for (int i = 0; i < numAccounts; i++) {
                    printf("%-20s %-20d %-20.2f\n", accounts[i].name, accounts[i].accNum, accounts[i].balance);
                }

                printf("\n");

            // Search for an account
            } else if (choice == 3) {
                printf("Searching for an account\n");
                printf("-----------------------\n");

                // Check if there are any accounts
                if (numAccounts == 0) {
                    printf("No accounts found!\n\n");
                    continue;
                }

                printf("Please enter the account number: ");
                fgets(input, 50, stdin);

                // Check if the account number is numeric
                if (isNumeric(input)) {
                    int accNum = atoi(input);
                    int found = 0;

                    // Loop through all the accounts and search for the account number
                    for (int i = 0; i < numAccounts; i++) {
                        if (accounts[i].accNum == accNum) {
                            printf("Account found:\n");
                            printf("%-20s %-20d %-20.2f\n\n", accounts[i].name, accounts[i].accNum, accounts[i].balance);
                            found = 1;
                            break;
                        }
                    }

                    // If the account number was not found, print an error message
                    if (!found) {
                        printf("Error: Account not found\n\n");
                    }

                } else {
                    printf("Error: Please enter a valid account number\n\n");
                    continue;
                }
            // Exit
            } else if (choice == 4) {
                printf("Thank you for using the Banking Record System!\n");
                exit(0);
            }
        } else {
            printf("Error: Please enter a valid choice\n\n");
        }
    }
    return 0;
}