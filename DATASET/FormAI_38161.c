//FormAI DATASET v1.0 Category: Database simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_RECORDS 1000

// Each record will contain a name and age
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Record;

// Database stores multiple records
typedef struct {
    Record records[MAX_RECORDS];
    int numRecords;
} Database;

// Function to print a record
void printRecord(Record record) {
    printf("%s - %d\n", record.name, record.age);
}

// Function to add a record to the database
void addRecord(Database *db, char *name, int age) {
    if (db->numRecords < MAX_RECORDS) {
        // Create a new record and add it to the database
        Record newRecord;
        strcpy(newRecord.name, name);
        newRecord.age = age;
        db->records[db->numRecords] = newRecord;
        db->numRecords++;
    } else {
        // Database is full, cannot add new record
        printf("Error: Database is full, cannot add new record.\n");
    }
}

// Function to search for a record by name
void searchRecord(Database db, char *name) {
    int i;
    for (i = 0; i < db.numRecords; i++) {
        if (strcmp(db.records[i].name, name) == 0) {
            // Record found, print it
            printRecord(db.records[i]);
            return;
        }
    }
    // Record not found
    printf("Record not found.\n");
}

int main() {
    // Create a new database
    Database db;
    db.numRecords = 0;

    // Add some records to the database
    addRecord(&db, "John Smith", 25);
    addRecord(&db, "Jane Doe", 30);
    addRecord(&db, "Bob Johnson", 21);

    // Search for a record by name
    searchRecord(db, "Jane Doe");

    return 0;
}