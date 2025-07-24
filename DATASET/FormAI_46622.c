//FormAI DATASET v1.0 Category: Banking Record System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Banking_Record {
    char name[50];
    int account_number;
    float balance;
};

void print_record(struct Banking_Record record) {
    printf("Name: %s\n", record.name);
    printf("Account Number: %d\n", record.account_number);
    printf("Balance: %.2f\n", record.balance);
    printf("\n");
}

void save_record(struct Banking_Record record) {
    FILE *file = fopen("bank_records.txt", "a");

    fprintf(file, "%s;%d;%.2f\n", record.name, record.account_number, record.balance);
    fclose(file);
    printf("Record Saved Successfully!\n\n");
}

void search_record(int account_number) {
    FILE *file = fopen("bank_records.txt", "r");
    char buffer[1024];

    while (fgets(buffer, 1024, file)) {
        struct Banking_Record record;
        char *name = strtok(buffer, ";");
        char *account_number_str = strtok(NULL, ";");
        char *balance_str = strtok(NULL, "\n");

        record.account_number = atoi(account_number_str);
        record.balance = atof(balance_str);

        if (record.account_number == account_number) {
            strcpy(record.name, name);
            print_record(record);
            fclose(file);
            return;
        }
    }

    printf("Record Not Found!\n\n");
    fclose(file);
}

int main() {
    printf("Welcome to the Banking Record System!\n\n");

    while (1) {
        printf("Please choose an option:\n");
        printf("1. Add New Record\n");
        printf("2. Search for Record\n");
        printf("3. Exit\n");
        printf("\n");

        int choice;
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            struct Banking_Record record;
            printf("Please enter the following details:\n");

            printf("Name: ");
            scanf("%s", record.name);

            printf("Account Number: ");
            scanf("%d", &record.account_number);

            printf("Balance: ");
            scanf("%f", &record.balance);

            save_record(record);
        }
        else if (choice == 2) {
            int account_number;
            printf("Please enter the Account Number: ");
            scanf("%d", &account_number);
            search_record(account_number);
        }
        else if (choice == 3) {
            printf("Thank you for using the Banking Record System!\n\n");
            return 0;
        }
        else {
            printf("Invalid Choice!\n\n");
        }
    }
}