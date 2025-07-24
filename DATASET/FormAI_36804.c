//FormAI DATASET v1.0 Category: Password management ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define maximum length of account name and password
#define MAX_LENGTH 50

// define number of accounts stored
#define NUM_ACCOUNTS 10

// define structure for storing account information
struct AccountInfo {
    char accountName[MAX_LENGTH];
    char password[MAX_LENGTH];
};

// function to initialize account info structure
void initializeAccountInfo(struct AccountInfo *account, char *name, char *password) {
    strncpy(account->accountName, name, MAX_LENGTH);
    strncpy(account->password, password, MAX_LENGTH);
}

// function to display account names
void displayAccountNames(struct AccountInfo accounts[], int numAccounts) {
    printf("Accounts:");
    for (int i = 0; i < numAccounts; i++) {
        printf(" %s", accounts[i].accountName);
    }
    printf("\n");
}

// function to find account index by name
int findAccountIndex(struct AccountInfo accounts[], int numAccounts, char *name) {
    for (int i = 0; i < numAccounts; i++) {
        if (strncmp(accounts[i].accountName, name, MAX_LENGTH) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    // initialize accounts
    struct AccountInfo accounts[NUM_ACCOUNTS];

    // initialize account names and passwords
    initializeAccountInfo(&accounts[0], "Gmail", "password1");
    initializeAccountInfo(&accounts[1], "Facebook", "password2");
    initializeAccountInfo(&accounts[2], "LinkedIn", "password3");
    initializeAccountInfo(&accounts[3], "Twitter", "password4");
    initializeAccountInfo(&accounts[4], "Instagram", "password5");

    // display account names
    displayAccountNames(accounts, NUM_ACCOUNTS);

    // prompt user for account name and password
    char name[MAX_LENGTH];
    char password[MAX_LENGTH];
    printf("Enter account name: ");
    scanf("%s", name);
    printf("Enter password: ");
    scanf("%s", password);

    // find account index by name
    int index = findAccountIndex(accounts, NUM_ACCOUNTS, name);

    // check if account exists and password matches
    if (index != -1 && strncmp(accounts[index].password, password, MAX_LENGTH) == 0) {
        printf("Access granted.\n");
    } else {
        printf("Incorrect account name or password.\n");
    }

    return 0;
}