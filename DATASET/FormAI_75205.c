//FormAI DATASET v1.0 Category: Banking Record System ; Style: Sherlock Holmes
#include<stdio.h>
#include<string.h>

// Define structure for bank account details
struct bankAccount {
    char name[50];
    char type[50];
    int accountNumber;
    float balance;
};

// Function to display all account details
void displayAll(struct bankAccount accounts[], int count) {
    for(int i=0; i<count; i++) {
        printf("Account #%d\n", i+1);
        printf("Name: %s\n", accounts[i].name);
        printf("Type: %s\n", accounts[i].type);
        printf("Account Number: %d\n", accounts[i].accountNumber);
        printf("Balance: %0.2f\n\n", accounts[i].balance);
    }
}

// Function to display account details of a specific account number
void displayAccountDetails(struct bankAccount accounts[], int count, int accountNumber) {
    for(int i=0; i<count; i++) {
        if(accounts[i].accountNumber == accountNumber) {
            printf("Account Details:\n");
            printf("Name: %s\n", accounts[i].name);
            printf("Type: %s\n", accounts[i].type);
            printf("Account Number: %d\n", accounts[i].accountNumber);
            printf("Balance: %0.2f\n\n", accounts[i].balance);
            return;
        }
    }
    printf("Account with account number %d does not exist.\n", accountNumber);
}

// Function to add a new bank account
void addNewAccount(struct bankAccount accounts[], int *count) {
    struct bankAccount newAccount;
    printf("Enter account holder name: ");
    scanf("%s", newAccount.name);
    printf("Enter account type (Saving/Current): ");
    scanf("%s", newAccount.type);
    printf("Enter account number: ");
    scanf("%d", &newAccount.accountNumber);
    printf("Enter opening balance: ");
    scanf("%f", &newAccount.balance);
    accounts[*count] = newAccount;
    (*count)++;
    printf("New account added successfully!\n\n");
}

// Function to delete an existing bank account
void deleteAccount(struct bankAccount accounts[], int *count, int accountNumber) {
    for(int i=0; i<*count; i++) {
        if(accounts[i].accountNumber == accountNumber) {
            for(int j=i; j<*count-1; j++) {
                accounts[j] = accounts[j+1];
            }
            (*count)--;
            printf("Account with account number %d has been deleted.\n\n", accountNumber);
            return;
        }
    }
    printf("Account with account number %d does not exist.\n", accountNumber);
}

// Function to update an existing bank account
void updateAccountDetails(struct bankAccount accounts[], int count, int accountNumber) {
    for(int i=0; i<count; i++) {
        if(accounts[i].accountNumber == accountNumber) {
            printf("Enter new account holder name: ");
            scanf("%s", accounts[i].name);
            printf("Enter new account type (Saving/Current): ");
            scanf("%s", accounts[i].type);
            printf("Enter new opening balance: ");
            scanf("%f", &accounts[i].balance);
            printf("Account with account number %d has been updated.\n\n", accountNumber);
            return;
        }
    }
    printf("Account with account number %d does not exist.\n", accountNumber);
}

int main() {
    // Declare and initialize an array of bank account structures
    struct bankAccount accounts[10] = {
        {"Sherlock Holmes", "Saving", 101, 50000},
        {"John Watson", "Current", 202, 10000},
        {"Irene Adler", "Saving", 303, 20000},
        {"Mycroft Holmes", "Current", 404, 30000},
        {"Mary Morstan", "Saving", 505, 40000}
    };
    int count = 5;
    int option, accountNumber;

    printf("Welcome to the Banking Record System!\n\n");
    do {
        printf("Select an option:\n");
        printf("1. Display all account details\n");
        printf("2. Display account details of a specific account number\n");
        printf("3. Add a new account\n");
        printf("4. Delete an existing account\n");
        printf("5. Update an existing account\n");
        printf("6. Exit\n\n");
        printf("Enter option number: ");

        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\nShowing all account details:\n\n");
                displayAll(accounts, count);
                break;
            case 2:
                printf("\nEnter account number to display account details: ");
                scanf("%d", &accountNumber);
                printf("\n");
                displayAccountDetails(accounts, count, accountNumber);
                break;
            case 3:
                printf("\nAdding a new account:\n\n");
                addNewAccount(accounts, &count);
                break;
            case 4:
                printf("\nEnter account number to delete account: ");
                scanf("%d", &accountNumber);
                printf("\n");
                deleteAccount(accounts, &count, accountNumber);
                break;
            case 5:
                printf("\nEnter account number to update account details: ");
                scanf("%d", &accountNumber);
                printf("\n");
                updateAccountDetails(accounts, count, accountNumber);
                break;
            case 6:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid option selected. Please try again.\n\n");
                break;
        }
    } while(option != 6);

    return 0;
}