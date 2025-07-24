//FormAI DATASET v1.0 Category: Database Indexing System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000

typedef struct {
    int id;
    char name[50];
    char address[100];
    float salary;
} Record;

typedef struct {
    int id;
    int index;
} Index;

Index indexes[MAX_RECORDS];
int indexCount = 0;

int compare(const void *p1, const void *p2) {
    Index i1 = *(Index *)p1;
    Index i2 = *(Index *)p2;

    if (i1.id > i2.id) {
        return 1;
    } else if (i1.id < i2.id) {
        return -1;
    } else {
        return 0;
    }
}

void createIndex(Record records[], int count) {
    for (int i = 0; i < count; i++) {
        indexes[i].id = records[i].id;
        indexes[i].index = i;
    }

    qsort(indexes, count, sizeof(Index), compare);
    indexCount = count;
}

void addRecord(Record records[], int *count, Record newRecord) {
    if (*count >= MAX_RECORDS) {
        printf("Error: Maximum number of records reached!\n");
        return;
    }

    records[*count] = newRecord;
    indexes[indexCount].id = newRecord.id;
    indexes[indexCount].index = *count;
    (*count)++;
    indexCount++;

    qsort(indexes, indexCount, sizeof(Index), compare);
}

void printRecord(Record record) {
    printf("ID: %d\n", record.id);
    printf("Name: %s\n", record.name);
    printf("Address: %s\n", record.address);
    printf("Salary: %.2f\n", record.salary);
    printf("---------------------------------\n");
}

void searchByID(Record records[], int count, int id) {
    int index = -1;

    for (int i = 0; i < indexCount; i++) {
        if (indexes[i].id == id) {
            index = indexes[i].index;
            break;
        }
    }

    if (index != -1) {
        printRecord(records[index]);
    } else {
        printf("Record not found.\n");
    }
}

int main() {
    Record records[MAX_RECORDS];
    int count = 0;

    Record r1 = { 101, "John Smith", "123 Main Street", 5000.00 };
    Record r2 = { 102, "Jane Doe", "456 Elm Street", 6000.00 };
    Record r3 = { 103, "Bob Johnson", "789 Maple Street", 7000.00 };

    addRecord(records, &count, r1);
    addRecord(records, &count, r2);
    addRecord(records, &count, r3);

    searchByID(records, count, 102);

    return 0;
}