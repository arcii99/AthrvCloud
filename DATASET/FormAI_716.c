//FormAI DATASET v1.0 Category: Banking Record System ; Style: inquisitive
#include <stdio.h>

// Define the maximum number of records
#define MAX_RECORDS 100

// Define the struct for a bank record
struct BankingRecord{
    char name[50];
    int account_num;
    double balance;
};

int main(){
    // Initialize the array of BankingRecord structs
    struct BankingRecord records[MAX_RECORDS];
    int num_records = 0;

    // Ask the user for input
    char answer = 'y';
    while (answer == 'y'){
        // Get the name
        printf("Enter the name: ");
        scanf("%s", &records[num_records].name);

        // Get the account number
        printf("Enter the account number: ");
        scanf("%d", &records[num_records].account_num);

        // Get the balance
        printf("Enter the balance: ");
        scanf("%lf", &records[num_records].balance);

        // Increment the number of records
        num_records++;

        // Ask if the user wants to add another record
        printf("Do you want to enter another record? (y/n): ");
        scanf(" %c", &answer);
    }

    // Print out the records
    printf("\n\nPrinting out Banking Records:\n");
    printf("Name\tAccount Number\tBalance\n");
    for (int i=0; i<num_records; i++){
        printf("%s\t%d\t$%.2lf\n", records[i].name, records[i].account_num, records[i].balance);
    }

    return 0;
}