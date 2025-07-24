//FormAI DATASET v1.0 Category: Database simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    int id;
    char name[20];
    char email[50];
} Record;

Record database[MAX_RECORDS];
int num_records = 0;

void addRecord(int id, char *name, char *email) {
    if (num_records >= MAX_RECORDS) {
        printf("Error: database is full\n");
        return;
    }

    Record record = {id};
    strncpy(record.name, name, 20);
    strncpy(record.email, email, 50);

    database[num_records++] = record;
}

void printRecords() {
    for (int i = 0; i < num_records; i++) {
        printf("%d: %s (%s)\n", database[i].id, database[i].name, database[i].email);
    }
}

int findRecordById(int id) {
    for (int i = 0; i < num_records; i++) {
        if (database[i].id == id) {
            return i;
        }
    }
    return -1;
}

void updateRecord(int id, char *name, char *email) {
    int index = findRecordById(id);
    if (index == -1) {
        printf("Error: record with id %d not found\n", id);
        return;
    }

    strncpy(database[index].name, name, 20);
    strncpy(database[index].email, email, 50);
}

void deleteRecord(int id) {
    int index = findRecordById(id);
    if (index == -1) {
        printf("Error: record with id %d not found\n", id);
        return;
    }

    for (int i = index; i < num_records - 1; i++) {
        database[i] = database[i + 1];
    }

    num_records--;
}

int main() {
    addRecord(1, "John Smith", "john.smith@example.com");
    addRecord(2, "Jane Doe", "jane.doe@example.com");

    printRecords();

    updateRecord(2, "Jane Smith", "jane.smith@example.com");
    deleteRecord(1);

    printRecords();

    return 0;
}