//FormAI DATASET v1.0 Category: Banking Record System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000

typedef struct {
    char name[20];
    char account_number[10];
    float balance;
} Record;

Record records[MAX_RECORDS];
int num_records = 0;

void addRecord(char *name, char *account_number, float balance)
{
    if (num_records >= MAX_RECORDS) {
        printf("Maximum number of records reached.\n");
        return;
    }

    Record new_record;
    strcpy(new_record.name, name);
    strcpy(new_record.account_number, account_number);
    new_record.balance = balance;

    records[num_records] = new_record;
    num_records++;

    printf("Record added:\nName: %s\nAccount number: %s\nBalance: %.2f\n",
           new_record.name, new_record.account_number, new_record.balance);
}

void printRecord(int index)
{
    if (index >= num_records) {
        printf("Record not found.\n");
        return;
    }

    Record record = records[index];
    printf("Record:\nName: %s\nAccount number: %s\nBalance: %.2f\n",
           record.name, record.account_number, record.balance);
}

void printRecords()
{
    int i;

    printf("Printing all records:\n");

    for (i = 0; i < num_records; i++) {
        Record record = records[i];

        printf("Record %d:\nName: %s\nAccount number: %s\nBalance: %.2f\n",
               i + 1, record.name, record.account_number, record.balance);
    }
}

int main()
{
    addRecord("John Doe", "123456", 1000.00);
    addRecord("Jane Smith", "654321", 500.00);

    printRecords();

    return 0;
}