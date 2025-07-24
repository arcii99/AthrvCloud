//FormAI DATASET v1.0 Category: Banking Record System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold the banking record data
typedef struct {
    int account_num;
    char name[50];
    float balance;
} Record;

int main() {
    int option;
    int num_records = 0; // keeps track of number of records
    Record *records = NULL; // points to memory for holding the records
    
    while (1) {
        printf("\nWelcome to the Banking Record System!\n");
        printf("Please choose an option:\n");
        printf("1. Add a new record\n");
        printf("2. Update an existing record\n");
        printf("3. Print all records\n");
        printf("4. Exit\n");
        printf("Option: ");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                // Allocate memory for a new record
                records = realloc(records, (num_records+1) * sizeof(Record));
                
                // Prompt user for account number, name, and balance
                printf("\nAdd a new record:\n");
                printf("Account number: ");
                scanf("%d", &records[num_records].account_num);
                printf("Name: ");
                scanf("%s", records[num_records].name);
                printf("Balance: $");
                scanf("%f", &records[num_records].balance);
                
                num_records++;
                printf("\nRecord added!\n");
                break;
                
            case 2:
                // Prompt user for account number to update
                int update_num;
                int found = 0;
                printf("\nEnter the account number to update: ");
                scanf("%d", &update_num);
                
                // Search for the record with the given account number
                for (int i = 0; i < num_records; i++) {
                    if (records[i].account_num == update_num) {
                        found = 1;
                        // Prompt user for new balance
                        printf("Enter the new balance: $");
                        scanf("%f", &records[i].balance);
                        printf("\nRecord updated!\n");
                        break;
                    }
                }
                if (!found) {
                    printf("Record not found.\n");
                }
                break;
                
            case 3:
                printf("\nPrinting all records:\n");
                printf("Account Number\tName\tBalance\n");
                for (int i = 0; i < num_records; i++) {
                    printf("%d\t%s\t$%.2f\n", records[i].account_num, records[i].name, records[i].balance);
                }
                break;
                
            case 4:
                printf("\nGoodbye!\n");
                // Free the memory allocated for the records
                free(records);
                return 0;
                
            default:
                printf("\nInvalid option.\n");
                break;
        }
    }
}