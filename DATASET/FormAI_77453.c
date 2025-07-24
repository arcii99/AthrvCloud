//FormAI DATASET v1.0 Category: Database simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of records that can be stored
#define MAX_RECORDS 100

// Define structure for a record
struct Record {
    int id;
    char name[50];
    char address[100];
};

// Define global array to store records
struct Record database[MAX_RECORDS];

// Define function to add new record to database
void addRecord(int id, char name[], char address[]) {

    // Create new record
    struct Record newRecord;
    newRecord.id = id;
    strcpy(newRecord.name, name);
    strcpy(newRecord.address, address);

    // Add new record to database
    int i;
    for(i=0; i<MAX_RECORDS; i++) {
        if(database[i].id == 0) {
            database[i] = newRecord;
            break;
        }
    }

    if(i == MAX_RECORDS) {
        printf("Error: database is full\n");
    } else {
        printf("Record added successfully\n");
    }
}

// Define function to print all records in database
void printRecords() {

    // Loop through all records and print each one
    printf("\n--------- Records ---------\n");
    int i;
    for(i=0; i<MAX_RECORDS; i++) {
        if(database[i].id != 0) {
            printf("ID: %d\nName: %s\nAddress: %s\n\n", database[i].id, database[i].name, database[i].address);
        }
    }
    printf("---------------------------\n\n");
}

int main() {

    // Initialize database
    int i;
    for(i=0; i<MAX_RECORDS; i++) {
        database[i].id = 0;
    }

    // Add sample records to database
    addRecord(1, "John Smith", "123 Main St.");
    addRecord(2, "Jane Doe", "456 Elm St.");
    addRecord(3, "Bob Johnson", "789 Oak St.");

    // Print all records in database
    printRecords();

    // Add new record to database
    addRecord(4, "Alice Brown", "321 Pine St.");

    // Print all records in database
    printRecords();

    return 0;
}