//FormAI DATASET v1.0 Category: Database simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

// Define the struct for a record
typedef struct Record {
    int id;
    char name[50];
    int age;
} Record;

// Declare the array of records
Record records[MAX_RECORDS];

// Declare the number of records currently in the array
int num_records = 0;

// Function to insert a new record
void insertRecord(int id, char *name, int age) {
    // Check if the array is full
    if(num_records >= MAX_RECORDS) {
        printf("The database is full!\n");
        return;
    }
    // Create a new record
    Record new_record;
    new_record.id = id;
    strcpy(new_record.name, name);
    new_record.age = age;
    // Add the new record to the database
    records[num_records] = new_record;
    num_records++;
}

// Function to search for a record by ID
void searchRecord(int id) {
    // Loop through each record in the database
    for(int i = 0; i < num_records; i++) {
        if(records[i].id == id) {
            // Print out the record
            printf("ID: %d\n", records[i].id);
            printf("Name: %s\n", records[i].name);
            printf("Age: %d\n", records[i].age);
            return;
        }
    }
    // If the ID is not found, print an error message
    printf("Record not found!\n");
}

// Function to delete a record by ID
void deleteRecord(int id) {
    // Loop through each record in the database
    for(int i = 0; i < num_records; i++) {
        if(records[i].id == id) {
            // Shift all the records after this one back by one
            for(int j = i; j < num_records - 1; j++) {
                records[j] = records[j+1];
            }
            // Decrement the number of records in the database
            num_records--;
            // Print a message letting the user know the record was deleted
            printf("Record deleted!\n");
            return;
        }
    }
    // If the ID is not found, print an error message
    printf("Record not found!\n");
}

// Function to display all records in the database
void displayRecords() {
    // Loop through each record in the database and print it out
    for(int i = 0; i < num_records; i++) {
        printf("ID: %d\n", records[i].id);
        printf("Name: %s\n", records[i].name);
        printf("Age: %d\n", records[i].age);
        printf("\n");
    }
}

int main() {
    // Insert some test data into the database
    insertRecord(1, "John Smith", 35);
    insertRecord(2, "Jane Doe", 28);
    insertRecord(3, "Bob Johnson", 42);

    // Search for a record by ID
    searchRecord(2);

    // Delete a record by ID
    deleteRecord(3);

    // Display all records in the database
    displayRecords();

    return 0;
}