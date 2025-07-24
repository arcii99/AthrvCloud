//FormAI DATASET v1.0 Category: Database Indexing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 30
#define MAX_EMAIL_LENGTH 50

// Declare a struct to hold the record information.
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Record;

// Declare a struct to hold the index information.
typedef struct {
    int id;
    int record_index;
} Index;

// Declare an array of Records.
Record records[MAX_RECORDS];

// Declare an array of Indexes.
Index indexes[MAX_RECORDS];

// Declare a function to initialize the indexes array.
void initialize_indexes() {
    int i;

    // Set all the index ids to -1 to indicate they are not yet initialized.
    for (i = 0; i < MAX_RECORDS; i++) {
        indexes[i].id = -1;
    }
}

// Declare a function to add a record to the records array and update the indexes.
void add_record(int id, char* name, char* email) {
    int i;
    int record_index = -1;

    // Find the index of the first empty slot in the records array.
    for (i = 0; i < MAX_RECORDS; i++) {
        if (records[i].id == 0) {
            record_index = i;
            break;
        }
    }

    // If there is no empty slot, exit the function.
    if (record_index == -1) {
        return;
    }

    // Add the record information to the records array.
    records[record_index].id = id;
    strcpy(records[record_index].name, name);
    strcpy(records[record_index].email, email);

    // Add the index information to the indexes array.
    indexes[id].id = id;
    indexes[id].record_index = record_index;
}

// Declare a function to search for a record by id using the indexes array.
Record* search_record(int id) {
    int i;
    int record_index = -1;

    // Find the index of the record with the specified id.
    for (i = 0; i < MAX_RECORDS; i++) {
        if (indexes[i].id == id) {
            record_index = indexes[i].record_index;
            break;
        }
    }

    // If the record was not found, exit the function.
    if (record_index == -1) {
        return NULL;
    }

    // Return a pointer to the record.
    return &records[record_index];
}

// Main function for testing the program.
int main() {
    // Initialize the indexes array.
    initialize_indexes();

    // Add some sample records.
    add_record(1, "John Smith", "john.smith@email.com");
    add_record(2, "Jane Doe", "jane.doe@email.com");

    // Search for a record and print the information.
    Record* record = search_record(1);
    if (record != NULL) {
        printf("Record found:\n");
        printf("ID: %d\n", record->id);
        printf("Name: %s\n", record->name);
        printf("Email: %s\n", record->email);
    } else {
        printf("Record not found.\n");
    }

    return 0;
}