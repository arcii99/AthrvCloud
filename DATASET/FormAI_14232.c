//FormAI DATASET v1.0 Category: Database simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

struct Record {
    int id;
    char name[50];
    char address[100];
};

struct Database {
    struct Record data[MAX_RECORDS];
    int count;
};

void initialize(struct Database *db) {
    db->count = 0;
}

void addRecord(struct Database *db, int id, char *name, char *address) {
    if (db->count >= MAX_RECORDS) {
        printf("Error: database is full.\n");
        return;
    }
    struct Record *record = &(db->data[db->count]);
    record->id = id;
    strncpy(record->name, name, 50);
    strncpy(record->address, address, 100);
    db->count++;
}

void removeRecord(struct Database *db, int id) {
    int i;
    for (i = 0; i < db->count; i++) {
        if (db->data[i].id == id) {
            break;
        }
    }
    if (i == db->count) {
        printf("Error: record not found.\n");
        return;
    }
    for (; i < db->count - 1; i++) {
        db->data[i] = db->data[i + 1];
    }
    db->count--;
}

void printRecord(struct Record *record) {
    printf("ID: %d\nName: %s\nAddress: %s\n", 
            record->id, record->name, record->address);
}

void printDatabase(struct Database *db) {
    int i;
    for (i = 0; i < db->count; i++) {
        printf("Record %d:\n", i+1);
        printRecord(&(db->data[i]));
    }
}

int main() {
    struct Database db;
    initialize(&db);
    
    addRecord(&db, 1, "John Doe", "123 Main St.");
    addRecord(&db, 2, "Jane Doe", "456 Elm St.");
    printDatabase(&db);
    
    removeRecord(&db, 1);
    printDatabase(&db);
    
    return 0;
}