//FormAI DATASET v1.0 Category: Database simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records that our database can hold
#define MAX_RECORDS 100

// Define the structure of a single record in the database
typedef struct {
    int id;
    char name[50];
    int age;
} Record;

// Define the database as an array of records
Record database[MAX_RECORDS];

// Define a variable to keep track of the number of records in the database
int num_records = 0;

/**
  * Function to add a new record to the database.
  */
void add_record(int id, char name[], int age) {
    // Check if the database is full
    if (num_records >= MAX_RECORDS) {
        printf("Error: Database is full\n");
        return;
    }
    
    // Create a new record and add it to the database
    Record record = {id, name, age};
    database[num_records] = record;
    num_records++;
}

/**
  * Function to display all the records in the database.
  */
void display_records() {
    // Check if the database is empty
    if (num_records == 0) {
        printf("Database is empty\n");
        return;
    }
    
    // Loop through all the records in the database and display them
    for (int i = 0; i < num_records; i++) {
        Record record = database[i];
        printf("ID: %d, Name: %s, Age: %d\n", record.id, record.name, record.age);
    }
}

/**
  * Function to search for a record by ID.
  */
void search_record(int id) {
    // Loop through all the records in the database and search for the record with the given ID
    for (int i = 0; i < num_records; i++) {
        Record record = database[i];
        if (record.id == id) {
            printf("Record found: ID: %d, Name: %s, Age: %d\n", record.id, record.name, record.age);
            return;
        }
    }
    
    // If the record is not found, display an appropriate message
    printf("Record not found for ID: %d\n", id);
}

int main() {
    // Add some sample records to the database
    add_record(1, "John Smith", 25);
    add_record(2, "Sarah Johnson", 30);
    
    // Display all the records in the database
    display_records();
    
    // Search for a record by ID
    search_record(1);
    
    // Search for a record that does not exist
    search_record(3);
    
    return 0;
}