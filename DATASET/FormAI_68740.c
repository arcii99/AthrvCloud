//FormAI DATASET v1.0 Category: Password management ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_PASSWORDS 1000
#define MAX_LENGTH 32

typedef struct {
    char password[MAX_LENGTH];
    char username[MAX_LENGTH];
} Account;

// Array to hold all the accounts
Account accounts[MAX_PASSWORDS];

// Array to hold indexes of deleted accounts
int deletedAccounts[MAX_PASSWORDS];
int numDeletedAccounts = 0;

// The number of accounts currently in the system
int numAccounts = 0;

// Generates a random password
char *generatePassword() {
    static const char alphabet[] =
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789$!@#%^&*()";
    static const int alphabetLength = sizeof(alphabet) - 1;

    char *password = malloc(MAX_LENGTH);
    if (!password) {
        return NULL;
    }

    srand(time(NULL));

    int i;
    for (i = 0; i < MAX_LENGTH-1; i++) {
        password[i] = alphabet[rand() % alphabetLength];
    }
    password[MAX_LENGTH-1] = '\0';

    return password;
}

// Adds an account to the system
bool addAccount(char *username, char *password) {
    // Check if there is space for the new account
    if (numAccounts >= MAX_PASSWORDS) {
        return false;
    }

    // Find the first deleted account and use that slot if there is one
    int index = -1;
    int i;
    for (i = 0; i < numDeletedAccounts; i++) {
        index = deletedAccounts[i];
        deletedAccounts[i] = -1;

        if (index >= 0 && index < numAccounts) {
            break;
        } else {
            index = -1;
        }
    }

    // If there was no deleted account, use the next empty slot
    if (index == -1) {
        index = numAccounts;
        numAccounts++;
    }

    // Populate the account fields
    strncpy(accounts[index].username, username, MAX_LENGTH-1);
    strncpy(accounts[index].password, password, MAX_LENGTH-1);

    return true;
}

// Deletes an account from the system
bool deleteAccount(int index) {
    if (index < 0 || index >= numAccounts) {
        return false;
    }

    // Add the index to the deleted accounts array
    deletedAccounts[numDeletedAccounts] = index;
    numDeletedAccounts++;

    // Clear the account fields
    memset(accounts[index].username, 0, MAX_LENGTH);
    memset(accounts[index].password, 0, MAX_LENGTH);

    return true;
}

// Changes the password of an existing account
bool changePassword(int index, char *newPassword) {
    if (index < 0 || index >= numAccounts) {
        return false;
    }

    strncpy(accounts[index].password, newPassword, MAX_LENGTH-1);

    return true;
}

int main() {
    // Generate some random passwords and add them to the system
    addAccount("alice", generatePassword());
    addAccount("bob", generatePassword());
    addAccount("charlie", generatePassword());

    // Print out the usernames and passwords of all accounts
    int i;
    for (i = 0; i < numAccounts; i++) {
        printf("%s: %s\n", accounts[i].username, accounts[i].password);
    }

    // Change alice's password
    changePassword(0, generatePassword());

    // Delete bob's account
    deleteAccount(1);

    // Add a new account for david
    addAccount("david", generatePassword());

    // Print out the usernames and passwords of all accounts again
    printf("\n");
    for (i = 0; i < numAccounts; i++) {
        printf("%s: %s\n", accounts[i].username, accounts[i].password);
    }

    return 0;
}