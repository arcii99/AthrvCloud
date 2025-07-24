//FormAI DATASET v1.0 Category: Banking Record System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure of a single record in the banking system
typedef struct bank_record {
    int accountNumber;
    char accountHolder[50];
    double balance;
} BankRecord;

// Function to display the records of all account holders
void displayRecords(int numRecords, BankRecord bankRecords[]) {
    printf("==================== BANKING RECORDS ====================\n\n");
    printf("%-15s %-30s %-20s\n", "Account Number", "Account Holder", "Balance");

    for(int i = 0; i < numRecords; i++) {
        printf("%-15d %-30s $%-.2f\n", bankRecords[i].accountNumber, bankRecords[i].accountHolder, bankRecords[i].balance);
    }

    printf("\n\n");
}

// Function to search for a specific account record by account number
void searchRecord(int numRecords, BankRecord bankRecords[]) {
    int accountNo;
    printf("Enter the account number to search: ");
    scanf("%d", &accountNo);

    for(int i = 0; i < numRecords; i++) {
        if(bankRecords[i].accountNumber == accountNo) {
            printf("Account Holder: %s\nBalance: $%.2f\n", bankRecords[i].accountHolder, bankRecords[i].balance);
            return;
        }
    }

    printf("Account not found.\n");
}

// Function to add a new record to the banking system
int addRecord(int numRecords, BankRecord bankRecords[]) {
    printf("Enter the account number: ");
    int accountNo;
    scanf("%d", &accountNo);

    for(int i = 0; i < numRecords; i++) {
        if(bankRecords[i].accountNumber == accountNo) {
            printf("Account number already exists.\n");
            return numRecords;
        }
    }

    BankRecord newRecord;
    newRecord.accountNumber = accountNo;
    printf("Enter the account holder name: ");
    scanf("%s", newRecord.accountHolder);
    printf("Enter the account balance: ");
    scanf("%lf", &newRecord.balance);

    bankRecords[numRecords] = newRecord;
    printf("Record added successfully!\n");
    numRecords++;

    return numRecords;
}

// Function to delete an existing record from the banking system
int deleteRecord(int numRecords, BankRecord bankRecords[]) {
    int accountNo;
    printf("Enter the account number to delete: ");
    scanf("%d", &accountNo);

    for(int i = 0; i < numRecords; i++) {
        if(bankRecords[i].accountNumber == accountNo) {
            for(int j = i; j < numRecords - 1; j++) {
                bankRecords[j] = bankRecords[j+1];
            }

            numRecords--;
            printf("Record deleted successfully!\n");
            return numRecords;
        }
    }

    printf("Account not found.\n");
    return numRecords;
}

int main() {
    // Welcome message
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    printf("Welcome to the Medieval Banking Record System!\n\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

    // Initializing the banking system with sample records
    BankRecord bankRecords[5];
    bankRecords[0].accountNumber = 123456;
    strcpy(bankRecords[0].accountHolder, "Sir John");
    bankRecords[0].balance = 10000.00;

    bankRecords[1].accountNumber = 234567;
    strcpy(bankRecords[1].accountHolder, "Lady Anne");
    bankRecords[1].balance = 5000.00;

    bankRecords[2].accountNumber = 345678;
    strcpy(bankRecords[2].accountHolder, "Sir Richard");
    bankRecords[2].balance = 20000.00;

    bankRecords[3].accountNumber = 456789;
    strcpy(bankRecords[3].accountHolder, "Lady Elizabeth");
    bankRecords[3].balance = 7500.00;

    bankRecords[4].accountNumber = 567890;
    strcpy(bankRecords[4].accountHolder, "Sir William");
    bankRecords[4].balance = 12000.00;

    int numRecords = 5;

    // Menu driven options
    int choice;

    do {
        printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\nPlease choose one of the following options:\n\n");
        printf("1. Display Records\n");
        printf("2. Search Record by Account Number\n");
        printf("3. Add New Record\n");
        printf("4. Delete Record\n");
        printf("5. Exit\n");
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                displayRecords(numRecords, bankRecords);
                break;
            case 2:
                searchRecord(numRecords, bankRecords);
                break;
            case 3:
                numRecords = addRecord(numRecords, bankRecords);
                break;
            case 4:
                numRecords = deleteRecord(numRecords, bankRecords);
                break;
            case 5:
                printf("Thank you for using the Medieval Banking Record System!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(choice != 5);

    return 0;
}