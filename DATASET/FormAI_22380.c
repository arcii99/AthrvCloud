//FormAI DATASET v1.0 Category: Database simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

// Define a structure for a record in the database
typedef struct {
    int id;
    char name[50];
    int age;
    char email[50];
} Record;

// Define a structure for the database itself
typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

// Function to add a record to the database
void addRecord(Database *db, Record record) {
    if (db->count < MAX_RECORDS) {
        db->records[db->count++] = record;
        printf("Record added successfully.\n");
    }
    else {
        printf("Error: Database is full.\n");
    }
}

// Function to search for a record in the database by ID
Record *findRecord(Database *db, int id) {
    int i;
    for (i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            return &(db->records[i]);
        }
    }
    return NULL;
}

int main() {
    // Create a new database
    Database db;
    db.count = 0;

    // Add some records to the database
    addRecord(&db, (Record){1, "John Smith", 30, "john.smith@mail.com"});
    addRecord(&db, (Record){2, "Jane Doe", 25, "jane.doe@mail.com"});
    addRecord(&db, (Record){3, "Bob Johnson", 42, "bob.johnson@mail.com"});

    // Search for a record by ID
    Record *record = findRecord(&db, 2);
    if (record == NULL) {
        printf("Record not found.\n");
    }
    else {
        printf("Record found: %s, %d years old, email: %s\n", record->name, record->age, record->email);
    }

    return 0;
}