//FormAI DATASET v1.0 Category: Banking Record System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

struct bankRecord {
    int accountNumber;
    char accountName[50];
    double balance;
};

int main() {
    int numRecords;
    printf("Enter the number of bank records: ");
    scanf("%d", &numRecords);
    struct bankRecord records[numRecords];
    
    // Input data
    for(int i=0; i<numRecords; i++) {
        printf("\nEnter the account number of record %d: ", i+1);
        scanf("%d", &records[i].accountNumber);
        printf("Enter the account name of record %d: ", i+1);
        scanf("%s", records[i].accountName);
        printf("Enter the balance of record %d: ", i+1);
        scanf("%lf", &records[i].balance);
    }
  
    // Output data
    printf("\n\nBank Records\n");
    printf("%-15s %-25s %s\n", "Account Number", "Account Name", "Balance");
    for(int i=0; i<numRecords; i++) {
        printf("%-15d %-25s $%.2f\n", records[i].accountNumber, records[i].accountName, records[i].balance);
    }

    return 0;
}