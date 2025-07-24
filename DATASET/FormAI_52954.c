//FormAI DATASET v1.0 Category: Database Indexing System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RECORDS 1000 // Maximum number of records the database can hold
#define MAX_NAME_LENGTH 50 // Maximum length of name field
#define MAX_ADDRESS_LENGTH 100 // Maximum length of address field

// Struct to hold a single database record
struct Record {
    int id;
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
};

// Struct to hold all database records and the current number of records
struct Database {
    int numRecords;
    struct Record records[MAX_RECORDS];
};

// Function to add a new record to the database
void addRecord(struct Database *db, char *name, char *address) {
    // Check if the database is already full
    if (db->numRecords >= MAX_RECORDS) {
        printf("Error: Database is full!\n");
        return;
    }

    // Create new record and assign its ID
    struct Record newRecord;
    newRecord.id = db->numRecords + 1;

    // Copy name and address into new record
    strncpy(newRecord.name, name, MAX_NAME_LENGTH);
    strncpy(newRecord.address, address, MAX_ADDRESS_LENGTH);

    // Add new record to database
    db->records[db->numRecords] = newRecord;
    db->numRecords++;

    printf("Record added:\n");
    printf("ID: %d\n", newRecord.id);
    printf("Name: %s\n", newRecord.name);
    printf("Address: %s\n", newRecord.address);
}

// Function to remove a record from the database by ID
void removeRecord(struct Database *db, int id) {
    // Search for record in database with matching ID
    bool foundRecord = false;
    int indexToRemove = -1;
    for (int i = 0; i < db->numRecords; i++) {
        if (db->records[i].id == id) {
            foundRecord = true;
            indexToRemove = i;
            break;
        }
    }

    if (foundRecord) {
        // Shift remaining records down by one to remove record at indexToRemove
        for (int i = indexToRemove; i < db->numRecords - 1; i++) {
            db->records[i] = db->records[i+1];
        }
        db->numRecords--;

        printf("Record with ID %d removed.\n", id);
    } else {
        printf("Error: Record with ID %d not found!\n", id);
    }
}

// Function to print all records in the database
void printRecords(struct Database *db) {
    for (int i = 0; i < db->numRecords; i++) {
        printf("Record %d:\n", i+1);
        printf("ID: %d\n", db->records[i].id);
        printf("Name: %s\n", db->records[i].name);
        printf("Address: %s\n", db->records[i].address);
        printf("\n");
    }
}

// Main function to test the database
int main() {
    struct Database db = {0};

    addRecord(&db, "John Smith", "123 Main St");
    addRecord(&db, "Jane Doe", "456 Elm St");
    printRecords(&db);

    printf("\nRemoving record with ID 2...\n");
    removeRecord(&db, 2);
    printRecords(&db);

    return 0;
}