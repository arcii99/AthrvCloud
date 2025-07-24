//FormAI DATASET v1.0 Category: Database simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records
#define MAX_RECORDS 100

// Define the record structure
struct Record {
    int id;
    char name[50];
    int age;
};

// Define the database structure
struct Database {
    struct Record records[MAX_RECORDS];
    int count;
};

// Function to add a record to the database
void addRecord(struct Database *database, int id, char name[], int age) {
    // Check if the database is full
    if (database->count >= MAX_RECORDS) {
        printf("Error: database is full\n");
        return;
    }

    // Create a new record
    struct Record newRecord;
    newRecord.id = id;
    strcpy(newRecord.name, name);
    newRecord.age = age;

    // Add the record to the database
    database->records[database->count] = newRecord;
    database->count++;

    printf("Record added: %d %s %d\n", id, name, age);
}

// Function to search for a record by ID
void searchRecord(struct Database *database, int id) {
    // Iterate over all records in the database
    for (int i = 0; i < database->count; i++) {
        // Check if the current record matches the ID
        if (database->records[i].id == id) {
            // Print the record details
            printf("Record found: %d %s %d\n", database->records[i].id, database->records[i].name, database->records[i].age);
            return;
        }
    }

    // If the function hasn't returned yet, the record couldn't be found
    printf("Record not found\n");
}

// Function to delete a record by ID
void deleteRecord(struct Database *database, int id) {
    // Iterate over all records in the database
    for (int i = 0; i < database->count; i++) {
        // Check if the current record matches the ID
        if (database->records[i].id == id) {
            // Shift all records after the current one one index to the left
            for (int j = i + 1; j < database->count; j++) {
                database->records[j - 1] = database->records[j];
            }

            // Decrease the record count
            database->count--;

            printf("Record deleted: %d\n", id);
            return;
        }
    }

    // If the function hasn't returned yet, the record couldn't be found
    printf("Record not found\n");
}

// Main function
int main() {
    // Create a new database
    struct Database database;
    database.count = 0;

    // Add some initial records
    addRecord(&database, 1, "John", 25);
    addRecord(&database, 2, "Mary", 30);
    addRecord(&database, 3, "Bob", 45);

    // Test the searchRecord function
    searchRecord(&database, 2);
    searchRecord(&database, 4);

    // Test the deleteRecord function
    deleteRecord(&database, 2);
    deleteRecord(&database, 4);

    return 0;
}