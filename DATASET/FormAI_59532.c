//FormAI DATASET v1.0 Category: Database simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the database and the maximum length of each entry
#define MAX_DB_SIZE 100
#define MAX_ENTRY_LENGTH 50

// Define a struct to store each entry of the database
typedef struct {
    char name[MAX_ENTRY_LENGTH];
    int age;
    int id;
} Entry;

// Define a struct to store the database
typedef struct {
    Entry entries[MAX_DB_SIZE];
    int size;
} Database;

// Function to add an entry to the database
void add_entry(Database *db, char *name, int age, int id) {
    // Check if the database is full
    if (db->size >= MAX_DB_SIZE) {
        printf("Error: Database is full\n");
        return;
    }
    // Create a new entry and add it to the database
    Entry new_entry;
    strcpy(new_entry.name, name);
    new_entry.age = age;
    new_entry.id = id;
    db->entries[db->size] = new_entry;
    db->size++;
}

// Function to search for an entry by name
void search_entry(Database *db, char *name) {
    // Loop through all entries in the database
    for (int i = 0; i < db->size; i++) {
        // Compare the entry's name to the search name
        if (strcmp(db->entries[i].name, name) == 0) {
            // Print the entry's information and return
            printf("Found entry:\nName: %s\nAge: %d\nID: %d\n", db->entries[i].name, db->entries[i].age, db->entries[i].id);
            return;
        }
    }
    // If the search name is not found, print an error
    printf("Error: Entry not found\n");
}

int main() {
    // Initialize the database
    Database db = { .entries = {}, .size = 0 };

    // Add a few entries to the database
    add_entry(&db, "Alice", 25, 12345);
    add_entry(&db, "Bob", 30, 54321);
    add_entry(&db, "Charlie", 35, 67890);
    add_entry(&db, "David", 40, 98765);

    // Search for an entry by name
    search_entry(&db, "Charlie");

    return 0;
}