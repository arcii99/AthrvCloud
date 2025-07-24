//FormAI DATASET v1.0 Category: Database simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20
#define MAX_RECORDS 100

struct Record {
    int id;
    char name[MAX_LENGTH];
    char address[MAX_LENGTH];
    int age;
};

struct Database {
    struct Record records[MAX_RECORDS];
    int count;
};

void addRecord(struct Database* database, struct Record record) {
    database->records[database->count] = record;
    database->count++;
}

void deleteRecord(struct Database* database, int id) {
    int foundIndex = -1;
    for (int i = 0; i < database->count; i++) {
        if (database->records[i].id == id) {
            foundIndex = i;
        }
    }
    if (foundIndex != -1) {
        for (int i = foundIndex; i < database->count-1; i++) {
            database->records[i] = database->records[i+1];
        }
        database->count--;
    }
}

struct Record* searchRecord(struct Database* database, int id) {
    for (int i = 0; i < database->count; i++) {
        if (database->records[i].id == id) {
            return &database->records[i];
        }
    }
    return NULL;
}

void printRecord(struct Record record) {
    printf("ID: %d\n", record.id);
    printf("Name: %s\n", record.name);
    printf("Address: %s\n", record.address);
    printf("Age: %d\n", record.age);
}

void printDatabase(struct Database* database) {
    for (int i = 0; i < database->count; i++) {
        printf("Record %d:\n", i+1);
        printRecord(database->records[i]);
    }
}

int main() {
    struct Database database = { .count = 0 };

    struct Record record1 = { .id = 1, .name = "John Smith", .address = "123 Main St", .age = 30 };
    struct Record record2 = { .id = 2, .name = "Jennifer Garcia", .address = "456 Elm St", .age = 25 };
    struct Record record3 = { .id = 3, .name = "David Lee", .address = "789 Pine St", .age = 40 };

    addRecord(&database, record1);
    addRecord(&database, record2);
    addRecord(&database, record3);

    printf("Database contents:\n");
    printDatabase(&database);

    struct Record* foundRecord = searchRecord(&database, 2);
    if (foundRecord != NULL) {
        printf("Record found:\n");
        printRecord(*foundRecord);
    } else {
        printf("Record not found.\n");
    }

    deleteRecord(&database, 2);
    printf("Database contents after deletion:\n");
    printDatabase(&database);

    return 0;
}