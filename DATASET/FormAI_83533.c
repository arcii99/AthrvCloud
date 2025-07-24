//FormAI DATASET v1.0 Category: Password management ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// User defined constants
#define MAX_PASSWORD_LENGTH 50
#define MAX_ACCOUNTS 100

// Global variables
char passwordDatabase[MAX_ACCOUNTS][MAX_PASSWORD_LENGTH+1];
// +1 is added to allow for null terminator character

// Menu function
void printMenu() {
    printf("\n ==== Password Management ====\n\n");
    printf("1. Add Password\n");
    printf("2. View Password\n");
    printf("3. Change Password\n");
    printf("4. Delete Password\n");
    printf("5. Exit\n");
}

// Function to add a new password to the database
void addPassword() {
    char accountName[MAX_PASSWORD_LENGTH], password[MAX_PASSWORD_LENGTH];

    printf("Enter the account name: ");
    scanf("%s", accountName);

    printf("Enter the password: ");
    scanf("%s", password);

    // Check if the account already exists in the database
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        if (strcmp(accountName, passwordDatabase[i]) == 0) {
            printf("Account %s already exists\n", accountName);
            return;
        }
    }

    // Add the new password to the database
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        if (strlen(passwordDatabase[i]) == 0) {
            strcpy(passwordDatabase[i], accountName);
            strcpy(passwordDatabase[i]+strlen(accountName), password);
            printf("Password added successfully!\n");
            return;
        }
    }

    // Database is full
    printf("Password database is full\n");
}

// Function to view a password in the database
void viewPassword() {
    char accountName[MAX_PASSWORD_LENGTH];

    printf("Enter the account name: ");
    scanf("%s", accountName);

    // Search for the account in the database
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        if (strcmp(accountName, passwordDatabase[i]) == 0) {
            printf("Password: %s\n", passwordDatabase[i]+strlen(accountName));
            return;
        }
    }

    // Account not found
    printf("Account not found\n");
}

// Function to change an existing password in the database
void changePassword() {
    char accountName[MAX_PASSWORD_LENGTH], password[MAX_PASSWORD_LENGTH];

    printf("Enter the account name: ");
    scanf("%s", accountName);

    // Search for the account in the database
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        if (strcmp(accountName, passwordDatabase[i]) == 0) {
            printf("Enter the new password: ");
            scanf("%s", password);
            strcpy(passwordDatabase[i]+strlen(accountName), password);
            printf("Password changed successfully!\n");
            return;
        }
    }

    // Account not found
    printf("Account not found\n");
}

// Function to delete an account from the database
void deletePassword() {
    char accountName[MAX_PASSWORD_LENGTH];

    printf("Enter the account name: ");
    scanf("%s", accountName);

    // Search for the account in the database
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        if (strcmp(accountName, passwordDatabase[i]) == 0) {
            passwordDatabase[i][0] = '\0'; // Delete the account from the database
            printf("Password deleted successfully!\n");
            return;
        }
    }

    // Account not found
    printf("Account not found\n");
}

// Main function
int main() {
    // Initialize the password database
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        passwordDatabase[i][0] = '\0';
    }

    int choice;

    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addPassword();
                break;
            case 2:
                viewPassword();
                break;
            case 3:
                changePassword();
                break;
            case 4:
                deletePassword();
                break;
            case 5:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}