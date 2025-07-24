//FormAI DATASET v1.0 Category: Database simulation ; Style: random
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DB_SIZE 5
#define STR_SIZE 20

// Struct for a record in the database
typedef struct {
    int id;
    char name[STR_SIZE];
    int age;
} Record;

// Database array
Record db[DB_SIZE];

// Function to insert a record into the database
void insert(int id, char name[], int age) {
    // Find an empty spot in the database
    int index = -1;
    for (int i = 0; i < DB_SIZE; i++) {
        if (db[i].id == 0) {
            index = i;
            break;
        }
    }

    // If there are no empty spots, print an error message
    if (index == -1) {
        printf("Error: database is full\n");
        return;
    }

    // Insert the new record
    db[index].id = id;
    strncpy(db[index].name, name, STR_SIZE);
    db[index].age = age;
}

// Function to delete a record from the database
void delete(int id) {
    // Find the record with the specified ID
    int index = -1;
    for (int i = 0; i < DB_SIZE; i++) {
        if (db[i].id == id) {
            index = i;
            break;
        }
    }

    // If the record isn't found, print an error message
    if (index == -1) {
        printf("Error: record not found\n");
        return;
    }

    // Delete the record
    db[index].id = 0;
    memset(db[index].name, 0, STR_SIZE);
    db[index].age = 0;
}

// Function to print all records in the database
void print_all() {
    for (int i = 0; i < DB_SIZE; i++) {
        if (db[i].id != 0) {
            printf("%d\t%s\t%d\n", db[i].id, db[i].name, db[i].age);
        }
    }
}

int main() {
    // Initialize the database to empty
    memset(db, 0, DB_SIZE * sizeof(Record));

    // Insert some sample records
    insert(1, "John", 25);
    insert(2, "Jane", 30);
    insert(3, "Bob", 40);

    // Print all records
    printf("All records:\n");
    print_all();

    // Delete a record
    printf("Deleting record with ID 2...\n");
    delete(2);

    // Print all records again
    printf("All records after deletion:\n");
    print_all();

    return 0;
}