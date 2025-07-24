//FormAI DATASET v1.0 Category: Password management ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20 // Maximum length of password
#define MAX_USERNAME_LENGTH 20 // Maximum length of username
#define MAX_ACCOUNTS 10 // Maximum number of accounts the system can hold

// Structure for holding the user account information
struct Account {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

// Initialize array of user accounts
struct Account accounts[MAX_ACCOUNTS];

// Function to add a new account
void addAccount(char *username, char *password) {
    // Check if the account list is full
    if (sizeof(accounts) / sizeof(accounts[0]) >= MAX_ACCOUNTS) {
        printf("Error: maximum number of accounts exceeded.\n");
        return;
    }
    
    // Check if the given username is already being used
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            printf("Error: username already exists.\n");
            return;
        }
    }
    
    // Add the new account
    struct Account newAccount;
    strcpy(newAccount.username, username);
    strcpy(newAccount.password, password);
    accounts[sizeof(accounts) / sizeof(accounts[0])] = newAccount;
    printf("Account successfully created.\n");
}

// Function to find an account by username
int findAccount(char *username) {
    // Search for the account
    for (int i = 0; i < sizeof(accounts) / sizeof(accounts[0]); i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            return i;
        }
    }
    
    return -1; // Account not found
}

// Function to change an account's password
void changePassword(char *username, char *oldPassword, char *newPassword) {
    // Find the account
    int index = findAccount(username);
    if (index == -1) {
        printf("Error: account not found.\n");
        return;
    }
    
    // Check if the given password matches the account's current password
    if (strcmp(accounts[index].password, oldPassword) != 0) {
        printf("Error: incorrect password.\n");
        return;
    }
    
    // Update the password
    strcpy(accounts[index].password, newPassword);
    printf("Password successfully changed.\n");
}

// Example usage of the account management system
int main() {
    // Initialize some sample accounts
    addAccount("user1", "password1");
    addAccount("user2", "password2");
    addAccount("user3", "password3");
    
    // Try to add a new account with the same username
    addAccount("user1", "password4");
    
    // Change the password for an existing account
    changePassword("user1", "password1", "newpassword");
    changePassword("user1", "password2", "newpassword"); // Incorrect old password
    
    return 0;
}