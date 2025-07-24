//FormAI DATASET v1.0 Category: Password management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Account;

Account accounts[MAX_PASSWORDS];

void initialize() {
    // Initialize accounts
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        strcpy(accounts[i].username, "");
        strcpy(accounts[i].password, "");
    }
}

void add_account() {
    // Add a new account
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        if (strcmp(accounts[i].username, "") == 0) {
            printf("Enter username: ");
            scanf("%s", accounts[i].username);
            printf("Enter password: ");
            scanf("%s", accounts[i].password);
            printf("Account added successfully.\n");
            return; // Return so we don't add more than one account
        }
    }
    printf("Sorry, you have reached the maximum number of accounts.\n");
}

void delete_account() {
    // Delete an account
    char username[MAX_PASSWORD_LENGTH];
    printf("Enter the username of the account you want to delete: ");
    scanf("%s", username);
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            strcpy(accounts[i].username, "");
            strcpy(accounts[i].password, "");
            printf("Account deleted successfully.\n");
            return; // Return so we don't delete more than one account
        }
    }
    printf("Account not found.\n");
}

void print_accounts() {
    // Print all accounts
    printf("Username\tPassword\n");
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        if (strcmp(accounts[i].username, "") != 0) {
            printf("%s\t%s\n", accounts[i].username, accounts[i].password);
        }
    }
}

int main() {
    initialize();

    int choice = 0;
    do {
        // Show menu and get choice
        printf("1: Add Account\n");
        printf("2: Delete Account\n");
        printf("3: Print Accounts\n");
        printf("4: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handle choice
        switch (choice) {
            case 1:
                add_account();
                break;
            case 2:
                delete_account();
                break;
            case 3:
                print_accounts();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}