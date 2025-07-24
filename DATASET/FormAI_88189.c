//FormAI DATASET v1.0 Category: Database simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Max Size of the Database
#define MAX_SIZE 10

// Struct to represent a Record in the Database
struct Record {
    int id;
    char name[20];
    float score;
};

// Database that holds the records
struct Record database[MAX_SIZE];

// Function to add a new record to the Database
void addRecord(int id, char name[], float score) {
    int i;
    // Search for the first empty slot in the Database
    for (i = 0; i < MAX_SIZE; i++) {
        if (database[i].id == 0) {
            // Add the record to the Database
            database[i].id = id;
            strncpy(database[i].name, name, 19);
            database[i].score = score;
            printf("Record added successfully.\n");
            return;
        }
    }
    // If the Database is full, print an error message
    printf("Sorry, the Database is full.\n");
}

// Function to find a record with a specific id in the Database
struct Record* findRecord(int id) {
    int i;
    // Search for the record with the specified id
    for (i = 0; i < MAX_SIZE; i++) {
        if (database[i].id == id) {
            return &database[i];
        }
    }
    // If no record is found with the specified id, return NULL
    return NULL;
}

// Function to delete a record with a specific id from the Database
void deleteRecord(int id) {
    int i;
    // Search for the record with the specified id
    for (i = 0; i < MAX_SIZE; i++) {
        if (database[i].id == id) {
            // Delete the record from the Database
            memset(&database[i], 0, sizeof(struct Record));
            printf("Record deleted successfully.\n");
            return;
        }
    }
    // If no record is found with the specified id, print an error message
    printf("Sorry, the record with the specified id was not found.\n");
}

int main() {
    // Initialize the Database with empty records
    memset(database, 0, sizeof(database));
    
    // Add some test records to the Database
    addRecord(1, "John", 85.5);
    addRecord(2, "Mary", 90.0);
    addRecord(3, "Bob", 75.3);
    
    // Find a record by id and print its information
    struct Record *record = findRecord(2);
    if (record != NULL) {
        printf("Record found:\n");
        printf("- ID: %d\n", record->id);
        printf("- Name: %s\n", record->name);
        printf("- Score: %.2f\n", record->score);
    } else {
        printf("Sorry, the record with the specified id was not found.\n");
    }
    
    // Delete a record by id
    deleteRecord(3);
    
    // Print the Database
    printf("Database:\n");
    printf("+----+----------------+-------+\n");
    printf("| ID | Name           | Score |\n");
    printf("+----+----------------+-------+\n");
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        if (database[i].id != 0) {
            printf("| %2d | %-14s | %5.2f |\n", database[i].id, database[i].name, database[i].score);
        }
    }
    printf("+----+----------------+-------+\n");
    
    return 0;
}