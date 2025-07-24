//FormAI DATASET v1.0 Category: Database simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 20
#define MAX_CITY_LENGTH 20

typedef struct {
    int ID;
    char name[MAX_NAME_LENGTH];
    char city[MAX_CITY_LENGTH];
} Record;

Record db[MAX_RECORDS];
int num_records = 0;

void addRecord(int ID, char* name, char* city) {
    if (num_records >= MAX_RECORDS) {
        printf("ERROR: maximum number of records reached\n");
        return;
    }
    db[num_records].ID = ID;
    strncpy(db[num_records].name, name, MAX_NAME_LENGTH);
    strncpy(db[num_records].city, city, MAX_CITY_LENGTH);
    num_records++;
}

void printRecord(Record record) {
    printf("ID: %d\n", record.ID);
    printf("Name: %s\n", record.name);
    printf("City: %s\n", record.city);
}

void printAllRecords() {
    for (int i = 0; i < num_records; i++) {
        printf("Record %d:\n", i + 1);
        printRecord(db[i]);
    }
}

void sortRecordsByCity() {
    // bubble sort
    for (int i = 0; i < num_records - 1; i++) {
        for (int j = 0; j < num_records - i - 1; j++) {
            if (strcmp(db[j].city, db[j + 1].city) > 0) {
                Record temp = db[j];
                db[j] = db[j + 1];
                db[j + 1] = temp;
            }
        }
    }
}

int main() {
    addRecord(1, "Alice", "London");
    addRecord(2, "Bob", "New York");
    addRecord(3, "Charlie", "Paris");
    addRecord(4, "David", "Tokyo");
    addRecord(5, "Emily", "London");
    addRecord(6, "Frank", "New York");

    printf("Initial Records:\n");
    printAllRecords();
    printf("\n");

    sortRecordsByCity();

    printf("Records sorted by City:\n");
    printAllRecords();

    return 0;
}