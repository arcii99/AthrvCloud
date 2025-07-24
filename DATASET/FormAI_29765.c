//FormAI DATASET v1.0 Category: Database simulation ; Style: content
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the database
#define MAX_LENGTH 50

// Define the structure of the database
typedef struct {
    int id;
    char name[20];
    char email[30];
} Record;

// Define the database as an array of records
Record database[MAX_LENGTH];

// Define the current size of the database
int size = 0;

// Function to add a new record to the database
void addRecord(int id, char* name, char* email) {
    // Check if the database is full
    if (size == MAX_LENGTH) {
        printf("Error: Database is full!\n");
        return;
    }

    // Create a new record with the provided data
    Record newRecord = {id, "", ""};
    strcpy(newRecord.name, name);
    strcpy(newRecord.email, email);

    // Add the new record to the database
    database[size] = newRecord;
    size++;

    printf("Record added successfully!\n");
}

// Function to search for a record by ID
int searchRecord(int id) {
    // Loop through all records in the database
    for (int i = 0; i < size; i++) {
        // Check if the current record matches the provided ID
        if (database[i].id == id) {
            // Print the details of the record
            printf("Record found!\n");
            printf("ID: %d\n", database[i].id);
            printf("Name: %s\n", database[i].name);
            printf("Email: %s\n", database[i].email);
            return i;
        }
    }

    // If the record is not found, return -1
    return -1;
}

// Function to update a record
void updateRecord(int id, char* name, char* email) {
    // Search for the record by ID
    int index = searchRecord(id);

    // If the record is found, update its data
    if (index != -1) {
        strcpy(database[index].name, name);
        strcpy(database[index].email, email);
        printf("Record updated successfully!\n");
    }
}

// Function to delete a record
void deleteRecord(int id) {
    // Search for the record by ID
    int index = searchRecord(id);

    // If the record is found, remove it from the database
    if (index != -1) {
        for (int i = index; i < size - 1; i++) {
            database[i] = database[i+1];
        }
        size--;
        printf("Record deleted successfully!\n");
    }
}

// Main function to demonstrate the database simulation
int main() {
    // Add some sample records to the database
    addRecord(1, "John Doe", "johndoe@email.com");
    addRecord(2, "Jane Smith", "janesmith@email.com");

    // Update a record in the database
    updateRecord(1, "John Smith", "johnsmith@email.com");

    // Delete a record from the database
    deleteRecord(2);

    return 0;
}