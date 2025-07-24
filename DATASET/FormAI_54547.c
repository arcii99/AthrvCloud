//FormAI DATASET v1.0 Category: Database simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000

// Define the schema for a record
struct Record {
    int id;
    char name[20];
    int age;
};

// Define the database as a global array of records
struct Record db[MAX_RECORDS];

// Define the size of the database (initially 0)
int db_size = 0;

// Function to add a record to the database
void add_record(int id, const char *name, int age) {
    if (db_size == MAX_RECORDS) {
        // Database is full
        printf("Error: database is full\n");
        return;
    }
    
    // Create a new record with the given fields
    struct Record new_record = { id, "", age };
    strcpy(new_record.name, name);
    
    // Add the new record to the database
    db[db_size] = new_record;
    db_size++;
}

// Function to remove a record from the database
void remove_record(int id) {
    int i, j;
    for (i = 0; i < db_size; i++) {
        if (db[i].id == id) {
            // Found the record to remove, shift all the following records back
            for (j = i; j < db_size - 1; j++) {
                db[j] = db[j+1];
            }
            db_size--;
            printf("Record removed\n");
            return;
        }
    }
    printf("Error: record not found\n");
}

// Function to print all records in the database
void print_all_records() {
    int i;
    for (i = 0; i < db_size; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", db[i].id, db[i].name, db[i].age);
    }
}

int main() {
    // Add some sample records to the database
    add_record(1, "Alice", 25);
    add_record(2, "Bob", 30);
    add_record(3, "Charlie", 35);
    
    // Print all records in the database
    printf("Initial records:\n");
    print_all_records();
    
    // Remove a record from the database
    remove_record(2);
    
    // Print all records in the database again
    printf("Remaining records:\n");
    print_all_records();
    
    return 0;
}