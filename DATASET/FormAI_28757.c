//FormAI DATASET v1.0 Category: Database simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_RECORDS 1000
#define MAX_FIELD_LENGTH 50

// Define data types
typedef struct Record {
    char firstName[MAX_FIELD_LENGTH];
    char lastName[MAX_FIELD_LENGTH];
    char phoneNumber[MAX_FIELD_LENGTH];
} Record;

typedef struct Database {
    Record records[MAX_RECORDS];
    int count;
} Database;

// Declare functions
void addRecord(Database *db, Record record);
void deleteRecord(Database *db, int index);
void printDatabase(Database *db);

// Main program
int main() {
    // Initialize database
    Database db;
    db.count = 0;
    
    // Add some records
    Record record1 = {"John", "Doe", "555-1234"};
    addRecord(&db, record1);
    
    Record record2 = {"Jane", "Smith", "555-5678"};
    addRecord(&db, record2);
    
    Record record3 = {"Bob", "Jones", "555-9012"};
    addRecord(&db, record3);
    
    // Print database
    printf("Initial database:\n");
    printDatabase(&db);
    
    // Delete a record
    deleteRecord(&db, 1);
    
    // Print database after deletion
    printf("Database after deletion:\n");
    printDatabase(&db);
    
    return 0;
}

// Function to add a record to the database
void addRecord(Database *db, Record record) {
    // Check if there's space for the record
    if (db->count >= MAX_RECORDS) {
        printf("Error: database is full\n");
        return;
    }
    
    // Add the record
    db->records[db->count] = record;
    db->count++;
}

// Function to delete a record from the database
void deleteRecord(Database *db, int index) {
    // Check if index is valid
    if (index < 0 || index >= db->count) {
        printf("Error: invalid index\n");
        return;
    }
    
    // Shift records down to fill gap
    for (int i = index; i < db->count - 1; i++) {
        db->records[i] = db->records[i + 1];
    }
    db->count--;
}

// Function to print the contents of the database
void printDatabase(Database *db) {
    for (int i = 0; i < db->count; i++) {
        printf("%s %s %s\n", db->records[i].firstName, db->records[i].lastName, db->records[i].phoneNumber);
    }
}