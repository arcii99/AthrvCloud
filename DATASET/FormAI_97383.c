//FormAI DATASET v1.0 Category: Banking Record System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct that stores a customer's banking record
typedef struct {
    char name[50];
    int account_number;
    float balance;
} BankingRecord;

int main() {
    int num_records;
    printf("Welcome to the Banking Record System\n");

    // Prompt the user for the number of records to store
    printf("How many records would you like to store? ");
    scanf("%d", &num_records);

    // Allocate memory for an array of BankingRecord structs
    BankingRecord *records = malloc(num_records * sizeof(BankingRecord));

    // Prompt the user to enter data for each record
    for (int i = 0; i < num_records; i++) {
        printf("\nEnter data for Record #%d\n", i+1);
        printf("Name: ");
        scanf("%s", records[i].name);
        printf("Account Number: ");
        scanf("%d", &records[i].account_number);
        printf("Balance: ");
        scanf("%f", &records[i].balance);
    }

    // Print out all the records
    printf("\nAll Banking Records:\n");
    for (int i = 0; i < num_records; i++) {
        printf("\nRecord #%d\n", i+1);
        printf("Name: %s\n", records[i].name);
        printf("Account Number: %d\n", records[i].account_number);
        printf("Balance: $%.2f\n", records[i].balance);
    }

    // Free the memory allocated for the records array
    free(records);

    printf("\nThank you for using the Banking Record System!\n");
    return 0;
}