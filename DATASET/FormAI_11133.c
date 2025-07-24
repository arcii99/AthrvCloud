//FormAI DATASET v1.0 Category: Banking Record System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for bank records
struct BankRecord {
    char accNo[20];
    char name[50];
    float balance;
};

int main() {
    // Array to store bank records
    struct BankRecord records[100];

    // Variables for user input and loop control    
    char input[50];
    int choice = 0, recordCount = 0, i;

    printf("Welcome to the bank record system!\n");

    while (choice != 4) {
        // Display menu
        printf("\nPlease choose an option:\n");
        printf("1. Add a new record\n");
        printf("2. View all records\n");
        printf("3. Search for a record\n");
        printf("4. Exit\n");
        fgets(input, 50, stdin);
        choice = atoi(input);

        switch(choice) {
            case 1:
                // Add a new record
                printf("\nEnter account number: ");
                fgets(records[recordCount].accNo, 20, stdin);

                printf("Enter customer name: ");
                fgets(records[recordCount].name, 50, stdin);

                printf("Enter account balance: ");
                fgets(input, 50, stdin);
                records[recordCount].balance = atof(input);

                recordCount++;
                printf("\nRecord added successfully.\n");
                break;

            case 2:
                // View all records
                if (recordCount == 0) {
                    printf("\nNo records found.\n");
                } else {
                    printf("\n%-20s%-50s%-10s\n", "Account No.", "Name", "Balance");
                    for (i = 0; i < recordCount; i++) {
                        printf("%-20s%-50s%-10.2f\n", records[i].accNo, records[i].name, records[i].balance);
                    }
                }
                break;

            case 3:
                // Search for a record
                printf("\nEnter account number to search for: ");
                fgets(input, 20, stdin);

                for (i = 0; i < recordCount; i++) {
                    if (strcmp(input, records[i].accNo) == 0) {
                        printf("\n%-20s%-50s%-10s\n", "Account No.", "Name", "Balance");
                        printf("%-20s%-50s%-10.2f\n", records[i].accNo, records[i].name, records[i].balance);
                        break;
                    } else if (i == (recordCount - 1)) {
                        printf("\nNo record found for account number %s.\n", input);
                    }
                }
                break;

            case 4:
                // Exit program
                printf("\nGoodbye!\n");
                break;

            default:
                // Invalid input
                printf("\nInvalid input. Please try again.\n");
                break;
        }
    }

    return 0;
}