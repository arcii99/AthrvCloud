//FormAI DATASET v1.0 Category: Database Indexing System ; Style: curious
#include <stdio.h>

// Define a struct to hold information about an entry in the database
typedef struct {
    int id;
    char name[20];
    float value;
} DatabaseEntry;

// Define a struct to hold an array of entry pointers, sorted by their IDs
typedef struct {
    DatabaseEntry* entries[100];
    int num_entries;
} IDIndex;

// Define a struct to hold an array of entry pointers, sorted by their values
typedef struct {
    DatabaseEntry* entries[100];
    int num_entries;
} ValueIndex;

int main() {
    // Initialize an array of DatabaseEntry structs
    DatabaseEntry entries[100];

    // Initialize the ID and Value indices
    IDIndex id_index;
    ValueIndex value_index;

    id_index.num_entries = 0;
    value_index.num_entries = 0;

    // Add some entries to the database
    entries[0] = (DatabaseEntry){1, "Entry 1", 10.5};
    entries[1] = (DatabaseEntry){2, "Entry 2", 6.0};
    entries[2] = (DatabaseEntry){3, "Entry 3", 22.4};

    // Add the entries to the ID and Value indices
    for (int i = 0; i < 3; i++) {
        id_index.entries[id_index.num_entries] = &entries[i];
        id_index.num_entries++;

        value_index.entries[value_index.num_entries] = &entries[i];
        value_index.num_entries++;
    }

    // Print out the ID and Value indices
    printf("ID Index:\n");
    for (int i = 0; i < id_index.num_entries; i++) {
        printf("%d: %s (%f)\n", id_index.entries[i]->id, id_index.entries[i]->name, id_index.entries[i]->value);
    }

    printf("Value Index:\n");
    for (int i = 0; i < value_index.num_entries; i++) {
        printf("%f: %s (%d)\n", value_index.entries[i]->value, value_index.entries[i]->name, value_index.entries[i]->id);
    }

    return 0;
}