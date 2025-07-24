//FormAI DATASET v1.0 Category: Data recovery tool ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float balance;
} BankAccount;

void recoverAccounts() {
    FILE *fp = fopen("bankdata.dat", "rb");
    if (fp == NULL) {
        printf("Error opening file");
        return;
    }
    BankAccount *account = (BankAccount*)malloc(sizeof(BankAccount));
    if (account == NULL) {
        printf("Memory allocation error");
        return;
    }
    printf("ID\tName\tBalance\n");
    while (fread(account, sizeof(BankAccount), 1, fp) == 1) {
        printf("%d\t%s\t%.2f\n", account->id, account->name, account->balance);
    }
    free(account);
    fclose(fp);
}

int main() {
    int choice;
    printf("Data Recovery Tool - Bank Accounts\n");
    printf("1. Recover accounts\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            recoverAccounts();
            break;
        case 2:
            printf("Exiting program");
            return 0;
        default:
            printf("Invalid choice");
            return 1;
    }
    return 0;
}