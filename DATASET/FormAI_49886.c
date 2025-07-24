//FormAI DATASET v1.0 Category: Database simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records that can be saved in the database
#define MAX_RECORDS 100

// Define the record structure
struct Record {
    int id;
    char name[20];
    int age;
};

// Initialize the database
struct Record database[MAX_RECORDS];
int num_records = 0;

// Function to add a new record to the database
void add_record(int id, char *name, int age) {
    // Check if there is enough space in the database
    if (num_records >= MAX_RECORDS) {
        printf("Error: Database is full!\n");
        return;
    }
    
    // Create a new record
    struct Record new_record = { id, "", age };
    strcpy(new_record.name, name);

    // Add the new record to the database
    database[num_records] = new_record;
    num_records++;
}

// Function to delete a record from the database
void delete_record(int id) {
    int i;
    for (i = 0; i < num_records; i++) {
        if (database[i].id == id) {
            // Shift all the records after this one by one position to the left
            for (int j = i; j < num_records - 1; j++) {
                database[j] = database[j+1];
            }
            num_records--;
            printf("Record with ID %d deleted successfully.\n", id);
            return;
        }
    }

    // If the record was not found
    printf("Error: Record with ID %d not found.\n", id);
}

// Function to print all records in the database
void print_records() {
    int i;
    for (i = 0; i < num_records; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", database[i].id, database[i].name, database[i].age);
    }
}

// Main function to test the database
int main() {
    // Add some initial records
    add_record(1, "John Smith", 30);
    add_record(2, "Jane Doe", 25);
    add_record(3, "Bob Johnson", 40);

    // Print all records
    printf("All Records:\n");
    print_records();

    // Delete a record
    delete_record(2);

    // Print all records again
    printf("\nAfter Deletion:\n");
    print_records();

    return 0;
}