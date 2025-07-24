//FormAI DATASET v1.0 Category: Database Indexing System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 25  // Maximum length of string entries
#define MAX_NUM_ENTRIES 100    // Maximum number of entries

// Entry structure
struct Entry {
    int id;                   // Entry ID
    char name[MAX_STRING_LENGTH + 1];  // Entry name
    char category[MAX_STRING_LENGTH + 1];  // Entry category
};

// Function to create an entry
struct Entry createEntry(int id, char name[], char category[]) {
    struct Entry entry;
    entry.id = id;
    strncpy(entry.name, name, MAX_STRING_LENGTH);
    strncpy(entry.category, category, MAX_STRING_LENGTH);
    return entry;
}

// Function to print an entry
void printEntry(struct Entry entry) {
    printf("ID: %d\n", entry.id);
    printf("Name: %s\n", entry.name);
    printf("Category: %s\n", entry.category);
}

// Indexing system structure
struct IndexingSystem {
    struct Entry entries[MAX_NUM_ENTRIES];  // Array of entries
    int numEntries;                         // Number of entries
};

// Function to initialize the indexing system
void initIndexingSystem(struct IndexingSystem *indexingSys) {
    indexingSys->numEntries = 0;
}

// Function to add an entry to the indexing system
int addEntryToIndexingSystem(struct IndexingSystem *indexingSys, struct Entry entry) {
    if (indexingSys->numEntries >= MAX_NUM_ENTRIES) {
        // Maximum number of entries reached
        return 0;
    }
    indexingSys->entries[indexingSys->numEntries] = entry;
    indexingSys->numEntries++;
    return 1;
}

// Function to print all entries in the indexing system
void printAllEntries(struct IndexingSystem indexingSys) {
    int i;
    for (i = 0; i < indexingSys.numEntries; i++) {
        printEntry(indexingSys.entries[i]);
        printf("\n");
    }
}

// Function to search for entries by category
void searchEntriesByCategory(struct IndexingSystem indexingSys, char category[]) {
    int i;
    for (i = 0; i < indexingSys.numEntries; i++) {
        if (strcmp(indexingSys.entries[i].category, category) == 0) {
            printEntry(indexingSys.entries[i]);
            printf("\n");
        }
    }
}

// Main function
int main() {
    struct IndexingSystem indexingSys;
    initIndexingSystem(&indexingSys);

    // Add some entries
    struct Entry entry1 = createEntry(1, "Entry 1", "Category 1");
    addEntryToIndexingSystem(&indexingSys, entry1);

    struct Entry entry2 = createEntry(2, "Entry 2", "Category 2");
    addEntryToIndexingSystem(&indexingSys, entry2);

    struct Entry entry3 = createEntry(3, "Entry 3", "Category 1");
    addEntryToIndexingSystem(&indexingSys, entry3);

    // Print all entries
    printf("All Entries:\n");
    printAllEntries(indexingSys);

    // Search for entries by category
    printf("Entries in Category 1:\n");
    searchEntriesByCategory(indexingSys, "Category 1");

    return 0;
}