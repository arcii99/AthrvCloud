//FormAI DATASET v1.0 Category: Database simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum size of database
#define MAX_DB_SIZE 100

// Define structure for database entry
struct Entry {
    int id;
    char name[20];
    int age;
};

// Define database as array of entries
struct Entry db[MAX_DB_SIZE];

// Define variable for number of entries in database
int numEntries = 0;

// Function to add an entry to the database
void addEntry(int id, char* name, int age) {
    // Check if maximum database size has been reached
    if (numEntries >= MAX_DB_SIZE) {
        printf("ERROR: Database is full!\n");
        return;
    }
    
    // Create new entry with given values
    struct Entry newEntry;
    newEntry.id = id;
    strcpy(newEntry.name, name);
    newEntry.age = age;
    
    // Add new entry to database and increment number of entries
    db[numEntries] = newEntry;
    numEntries++;
    
    // Print success message
    printf("Added new entry (#%d): %s (%d years old)\n", id, name, age);
}

// Function to print all entries in the database
void printEntries() {
    // Check if database is empty
    if (numEntries == 0) {
        printf("Database is empty!\n");
        return;
    }
    
    printf("List of all entries in the database:\n");
    printf("-----------------------------------\n");
    for (int i = 0; i < numEntries; i++) {
        printf("#%d: %s (%d years old)\n", db[i].id, db[i].name, db[i].age);
    }
    printf("-----------------------------------\n");
}

// Function to find an entry in the database by ID
int findEntryById(int id) {
    for (int i = 0; i < numEntries; i++) {
        if (db[i].id == id) {
            return i;
        }
    }
    return -1;
}

// Function to modify an existing entry in the database
void modifyEntry(int id, char* name, int age) {
    // Find entry in database
    int entryIndex = findEntryById(id);
    if (entryIndex == -1) {
        printf("ERROR: Entry not found!\n");
        return;
    }
    
    // Update entry with new values
    strcpy(db[entryIndex].name, name);
    db[entryIndex].age = age;
    
    // Print success message
    printf("Modified entry (#%d): %s (%d years old)\n", id, name, age);
}

// Function to remove an entry from the database
void removeEntry(int id) {
    // Find entry in database
    int entryIndex = findEntryById(id);
    if (entryIndex == -1) {
        printf("ERROR: Entry not found!\n");
        return;
    }
    
    // Shift all entries after the removed entry one position to the left
    for (int i = entryIndex; i < numEntries - 1; i++) {
        db[i] = db[i+1];
    }
    numEntries--;
    
    // Print success message
    printf("Removed entry (#%d)\n", id);
}

int main() {
    // Add some entries to the database
    addEntry(1, "Alice", 25);
    addEntry(2, "Bob", 30);
    addEntry(3, "Charlie", 40);
    
    // Print all entries in the database
    printEntries();
    
    // Modify an existing entry in the database
    modifyEntry(2, "Bobby", 35);
    printEntries();
    
    // Remove an entry from the database
    removeEntry(1);
    printEntries();
    
    // Add a new entry to the database
    addEntry(4, "David", 20);
    printEntries();
    
    return 0;
}