//FormAI DATASET v1.0 Category: Database querying ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    int id;
    char name[20];
    int age;
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

void addRecord(Database* db, Record record) {
    if (db->count >= MAX_RECORDS) {
        printf("Database is full\n");
        return;
    }
    db->records[db->count] = record;
    db->count++;
}

void printRecord(Record* record) {
    printf("ID: %d\nName: %s\nAge: %d\n\n", record->id, record->name, record->age);
}

void printDatabase(Database* db) {
    printf("Database:\n");
    for (int i = 0; i < db->count; i++) {
        printRecord(&db->records[i]);
    }
}

int main() {
    Database db;
    db.count = 0;

    Record record1 = {1, "John", 25};
    Record record2 = {2, "Alice", 30};
    Record record3 = {3, "Bob", 40};

    addRecord(&db, record1);
    addRecord(&db, record2);
    addRecord(&db, record3);

    printDatabase(&db);

    return 0;
}