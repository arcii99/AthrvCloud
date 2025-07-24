//FormAI DATASET v1.0 Category: Banking Record System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_ACCOUNT_NO 100000
#define MAX_NAME_LENGTH 50

typedef struct {
    int account_no;
    char name[MAX_NAME_LENGTH];
    float balance;
} Record;

void createRecord(Record records[], int *index) {
    int account_no;
    char name[MAX_NAME_LENGTH];
    float balance;

    printf("Enter account number: ");
    scanf("%d", &account_no);

    if (account_no < 0 || account_no >= MAX_ACCOUNT_NO) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Enter name: ");
    getchar();
    fgets(name, MAX_NAME_LENGTH, stdin);

    printf("Enter balance: ");
    scanf("%f", &balance);

    Record record = { account_no, name, balance };
    records[*index] = record;
    *index += 1;

    printf("Record created successfully.\n");
}

void displayRecords(Record records[], int index) {
    if (index == 0) {
        printf("No records found.\n");
        return;
    }

    printf("Account No.  Name           Balance\n");
    printf("----------------------------------\n");

    for (int i = 0; i < index; i++) {
        printf("%-12d %-14s %-.2f\n", records[i].account_no, records[i].name, records[i].balance);
    }
}

void deleteRecord(Record records[], int *index) {
    int account_no;

    printf("Enter account number: ");
    scanf("%d", &account_no);

    int i;
    for (i = 0; i < *index; i++) {
        if (records[i].account_no == account_no) {
            break;
        }
    }

    if (i == *index) {
        printf("Record not found.\n");
        return;
    }

    for (int j = i; j < *index - 1; j++) {
        records[j] = records[j + 1];
    }

    *index -= 1;
    printf("Record deleted successfully.\n");
}

int main() {
    int choice;
    int index = 0;
    Record records[MAX_RECORDS];

    printf("Welcome to the C Banking Record System!\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Record\n");
        printf("2. Display Records\n");
        printf("3. Delete Record\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createRecord(records, &index);
                break;
            case 2:
                displayRecords(records, index);
                break;
            case 3:
                deleteRecord(records, &index);
                break;
            case 4:
                printf("Exiting program. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}