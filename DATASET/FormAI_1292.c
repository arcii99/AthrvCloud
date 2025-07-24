//FormAI DATASET v1.0 Category: Database Indexing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for the Index
struct Index {
    int id;
    char name[50];
    char email[50];
};

// Database
struct Index database[100];
int size = 0;

// Function to add an entry to the database
void addEntry(int id, char *name, char *email) {
    struct Index entry = {id, "", ""};
    // Copy name
    strncpy(entry.name, name, sizeof(entry.name) - 1);
    // Copy email
    strncpy(entry.email, email, sizeof(entry.email) - 1);
    // Add to database
    database[size] = entry;
    size++;
}

// Function to search the database by name
void searchByName(char *name) {
    int i, found = 0;
    printf("Search Results:\n");
    for (i = 0; i < size; i++) {
        if (strcmp(database[i].name, name) == 0) {
            printf("%d, %s, %s\n", database[i].id, database[i].name, database[i].email);
            found = 1;
        }
    }
    if (!found) {
        printf("No entry found for %s\n", name);
    }
}

// Function to search the database by email
void searchByEmail(char *email) {
    int i, found = 0;
    printf("Search Results:\n");
    for (i = 0; i < size; i++) {
        if (strcmp(database[i].email, email) == 0) {
            printf("%d, %s, %s\n", database[i].id, database[i].name, database[i].email);
            found = 1;
        }
    }
    if (!found) {
        printf("No entry found for %s\n", email);
    }
}

// Main function
int main() {
    // Add entries to the database
    addEntry(1, "John Smith", "john.smith@email.com");
    addEntry(2, "Jane Doe", "jane.doe@email.com");
    addEntry(3, "Bob Johnson", "bob.johnson@email.com");
    // Search entries by name and email
    searchByName("Jane Doe");
    searchByEmail("bob.johnson@email.com");
    return 0;
}