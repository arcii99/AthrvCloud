//FormAI DATASET v1.0 Category: Database simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

// Define a struct to store some data fields in our database
typedef struct {
    int id;
    char name[20];
    char email[30];
} Entry;

// Define our array of entries
Entry entries[MAX_ENTRIES];

// Keep track of the number of entries we have
int num_entries = 0;

// Add a new entry to the database
void add_entry(int id, char name[], char email[]) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: database is full\n");
        return;
    }

    Entry new_entry;
    new_entry.id = id;
    strncpy(new_entry.name, name, sizeof(new_entry.name));
    strncpy(new_entry.email, email, sizeof(new_entry.email));

    entries[num_entries] = new_entry;
    num_entries++;

    printf("Entry added successfully!\n");
}

// Find an entry in the database by ID
Entry* find_entry(int id) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (entries[i].id == id) {
            return &entries[i];
        }
    }

    return NULL;
}

// Print out a specific entry in a human-readable format
void print_entry(int id) {
    Entry* entry = find_entry(id);

    if (entry == NULL) {
        printf("Entry not found\n");
        return;
    }

    printf("ID: %d\n", entry->id);
    printf("Name: %s\n", entry->name);
    printf("Email: %s\n", entry->email);
}

// Remove an entry from the database by ID
void remove_entry(int id) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (entries[i].id == id) {
            entries[i] = entries[num_entries - 1];
            num_entries--;
            printf("Entry removed successfully!\n");
            return;
        }
    }

    printf("Entry not found\n");
}

// Print out all entries in the database
void print_all_entries() {
    if (num_entries == 0) {
        printf("Database is empty\n");
        return;
    }

    printf("ID | Name | Email\n");
    printf("---------------------\n");

    int i;
    for (i = 0; i < num_entries; i++) {
        printf("%d | %s | %s\n", entries[i].id, entries[i].name, entries[i].email);
    }
}

int main() {
    // Test out our database functions
    add_entry(1, "John Smith", "john.smith@gmail.com");
    add_entry(2, "Jane Doe", "jane.doe@gmail.com");
    add_entry(3, "Alex Johnson", "alex.johnson@yahoo.com");

    print_all_entries();

    print_entry(2);

    remove_entry(1);

    print_all_entries();

    return 0;
}