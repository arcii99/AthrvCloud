//FormAI DATASET v1.0 Category: Database simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 50
#define MAX_NAME_LENGTH 20
#define MAX_PHONE_LENGTH 12

// Struct for a single record
typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Record;

// Struct for the database
typedef struct {
    Record records[MAX_RECORDS];
    int numRecords;
} Database;

// Function to print out a single record
void printRecord(Record *record) {
    printf("%-20s | %-12s\n", record->name, record->phone);
}

// Function to print out the entire database
void printDatabase(Database *db) {
    printf("%-20s | %-12s\n", "Name", "Phone Number");
    printf("---------------------------------\n");
    for (int i = 0; i < db->numRecords; i++) {
        printRecord(&db->records[i]);
    }
}

// Function to add a record to the database
void addRecord(Database *db, char *name, char *phone) {
    if (db->numRecords == MAX_RECORDS) {
        printf("Database is full - cannot add any more records!\n");
        return;
    }
    strcpy(db->records[db->numRecords].name, name);
    strcpy(db->records[db->numRecords].phone, phone);
    db->numRecords++;
}

int main() {
    Database db;
    db.numRecords = 0;

    // Add some sample records
    addRecord(&db, "John Smith", "555-1234");
    addRecord(&db, "Jane Doe", "555-4321");

    // Print out the database
    printDatabase(&db);

    // Add a new record
    addRecord(&db, "Bob Johnson", "555-5678");

    // Print out the database again
    printDatabase(&db);

    return 0;
}