//FormAI DATASET v1.0 Category: Banking Record System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BankRecord {
    char name[50];
    int accountNumber;
    float balance;
};

int main() {
    int n, i;
    printf("Welcome to our cheerful banking record system!\n");
    printf("How many bank records do you want to create? ");
    scanf("%d", &n);
    struct BankRecord *records = malloc(n * sizeof(struct BankRecord));
    getchar();
    for (i = 0; i < n; i++) {
        printf("\nEnter the name of customer %d: ", i + 1);
        fgets(records[i].name, 50, stdin);
        records[i].name[strcspn(records[i].name, "\n")] = '\0';
        printf("Enter the account number of customer %d: ", i + 1);
        scanf("%d", &records[i].accountNumber);
        printf("Enter the balance of customer %d: ", i + 1);
        scanf("%f", &records[i].balance);
        getchar();
    }
    printf("\nBank records created successfully!\n");
    printf("Here are the details of all bank records:\n\n");
    printf("Name\t\tAccount Number\t\tBalance\n");
    for (i = 0; i < n; i++) {
        printf("%-15s%-20d$%.2f\n", records[i].name, records[i].accountNumber, records[i].balance);
    }
    free(records);
    printf("\nThank you for using our cheerful banking record system!\n");

    return 0;
}