//FormAI DATASET v1.0 Category: Password management ; Style: Romeo and Juliet
// 'Tis but thy password that is my enemy
// Thou art thyself, though not without a key.
// What's a key? It is nor hand, nor foot,
// Nor arm, nor face, nor any other part
// Belonging to a man. O, be some other word!
// What's in a word? That which we call a password
// By any other name would smell as sweet;
// So Romeo would, were he not Romeo call'd,
// Retain that dear perfection which he owes
// Without that title. Password, doff thy name,
// And for that name which is no part of thee
// Take all myself.
// - Romeo and Juliet Act II, Scene II

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 30
#define MAX_ACCOUNTS 10

// Define a structure to store our accounts
typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Account;

// Declare global variables for our accounts and number of accounts
Account accounts[MAX_ACCOUNTS];
int num_accounts = 0;

// Function to add an account
void add_account(char username[], char password[]) {
    // Check if we have reached the maximum number of accounts allowed
    if (num_accounts >= MAX_ACCOUNTS) {
        printf("Sorry, we cannot add any more accounts.\n");
        return;
    }
    
    // Create a new account with the given username and password
    Account new_account;
    strcpy(new_account.username, username);
    strcpy(new_account.password, password);
    
    // Add the new account to the accounts array and increase the number of accounts
    accounts[num_accounts] = new_account;
    num_accounts++;
    
    printf("Account added successfully.\n");
}

// Function to remove an account
void remove_account(char username[]) {
    int i;
    for (i = 0; i < num_accounts; i++) {
        // Check if the current account matches the given username
        if (strcmp(accounts[i].username, username) == 0) {
            // Shift all accounts after the removed account backward
            int j;
            for (j = i; j < num_accounts - 1; j++) {
                accounts[j] = accounts[j+1];
            }
            // Decrease the number of accounts
            num_accounts--;
            printf("Account removed successfully.\n");
            return;
        }
    }
    
    printf("Could not find account with that username.\n");
}

// Function to change a password
void change_password(char username[], char old_password[], char new_password[]) {
    int i;
    for (i = 0; i < num_accounts; i++) {
        // Check if the current account matches the given username and old password
        if (strcmp(accounts[i].username, username) == 0 && strcmp(accounts[i].password, old_password) == 0) {
            // Change the password for the current account
            strcpy(accounts[i].password, new_password);
            printf("Password changed successfully.\n");
            return;
        }
    }
    
    // If we reach this point, the account with the given username and old password was not found
    printf("Could not find account with that username and password.\n");
}

// Main function
int main() {
    char input[MAX_PASSWORD_LENGTH];
    int choice;
    while (1) {
        // Print the menu
        printf("\n1. Add an account\n2. Remove an account\n3. Change a password\n4. Exit\n\nEnter a choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                // Get input for new account and add it
                printf("\nEnter the username for the new account: ");
                scanf("%s", input);
                char new_user[MAX_PASSWORD_LENGTH];
                strcpy(new_user, input);
                printf("Enter the password for the new account: ");
                scanf("%s", input);
                char new_pass[MAX_PASSWORD_LENGTH];
                strcpy(new_pass, input);
                add_account(new_user, new_pass);
                break;
            case 2:
                // Get input for account to remove and remove it
                printf("\nEnter the username for the account to remove: ");
                scanf("%s", input);
                char rem_user[MAX_PASSWORD_LENGTH];
                strcpy(rem_user, input);
                remove_account(rem_user);
                break;
            case 3:
                // Get input for account and new password and change the password
                printf("\nEnter the username for the account: ");
                scanf("%s", input);
                char chg_user[MAX_PASSWORD_LENGTH];
                strcpy(chg_user, input);
                printf("Enter the old password for the account: ");
                scanf("%s", input);
                char chg_old[MAX_PASSWORD_LENGTH];
                strcpy(chg_old, input);
                printf("Enter the new password for the account: ");
                scanf("%s", input);
                char chg_new[MAX_PASSWORD_LENGTH];
                strcpy(chg_new, input);
                change_password(chg_user, chg_old, chg_new);
                break;
            case 4:
                // Exit the program
                printf("\nGoodbye!\n");
                exit(0);
                break;
            default:
                // Invalid choice
                printf("\nInvalid choice.\n");
                break;
        }
    }
    
    return 0;
}