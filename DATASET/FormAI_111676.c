//FormAI DATASET v1.0 Category: Database Indexing System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100
#define MAX_RECORDS 100

// Defining a structure that will hold the record information
struct record {
    int id;
    char name[MAX_STRING_LENGTH];
    char email[MAX_STRING_LENGTH];
    char phone[MAX_STRING_LENGTH];
};

// Defining a structure that will hold the indexing information
struct index {
    char name[MAX_STRING_LENGTH];
    int offset;
};

// Global variables
int num_records = 0; // Number of records currently in the database
struct record database[MAX_RECORDS]; // The database array
struct index index_array[MAX_RECORDS]; // The index array
int num_index_entries = 0; // Number of entries in the index array

// Function to add a record to the database
void add_record(int id, char *name, char *email, char *phone) {
    if (num_records >= MAX_RECORDS) {
        printf("Error: Database is full.\n");
        return;
    }
    database[num_records].id = id;
    strncpy(database[num_records].name, name, MAX_STRING_LENGTH);
    strncpy(database[num_records].email, email, MAX_STRING_LENGTH);
    strncpy(database[num_records].phone, phone, MAX_STRING_LENGTH);
    num_records++;
}

// Function to add an entry to the index array
void add_index_entry(char *name, int offset) {
    if (num_index_entries >= MAX_RECORDS) {
        printf("Error: Index array is full.\n");
        return;
    }
    strncpy(index_array[num_index_entries].name, name, MAX_STRING_LENGTH);
    index_array[num_index_entries].offset = offset;
    num_index_entries++;
}

// Function to search for a record by name
void search_by_name(char *name) {
    int i, found = 0;
    for (i = 0; i < num_index_entries; i++) {
        if (strcmp(name, index_array[i].name) == 0) {
            found = 1;
            printf("Record found at offset %d:\n", index_array[i].offset);
            printf("ID: %d\n", database[index_array[i].offset].id);
            printf("Name: %s\n", database[index_array[i].offset].name);
            printf("Email: %s\n", database[index_array[i].offset].email);
            printf("Phone: %s\n", database[index_array[i].offset].phone);
        }
    }
    if (!found) {
        printf("Record not found.\n");
    }
}

// Main function
int main() {
    add_record(1, "John Smith", "john.smith@example.com", "555-1234");
    add_record(2, "Jane Doe", "jane.doe@example.com", "555-5678");
    add_record(3, "Bob Johnson", "bob.johnson@example.com", "555-4321");
    add_record(4, "Alice Peterson", "alice.peterson@example.com", "555-8765");
    add_index_entry("Alice Peterson", 3);
    add_index_entry("Bob Johnson", 2);
    add_index_entry("Jane Doe", 1);
    add_index_entry("John Smith", 0);
    search_by_name("Jane Doe");
    return 0;
}