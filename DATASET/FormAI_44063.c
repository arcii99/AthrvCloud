//FormAI DATASET v1.0 Category: Database simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Declare a struct for the database entry
typedef struct {
    int id;
    char name[50];
    int age;
} Person;

// Declare a struct for the database
typedef struct {
    Person entries[MAX_SIZE];
    int size;
} Database;

// Function to add an entry to the database
void addEntry(Database *db, Person entry) {
    if (db->size >= MAX_SIZE) {
        printf("Error: database is full.\n");
        return;
    }
    db->entries[db->size] = entry;
    db->size++;
}

// Function to remove an entry from the database by ID
void removeEntry(Database *db, int id) {
    int i = 0;
    for (; i < db->size; i++) {
        if (db->entries[i].id == id) {
            // Shift entries after i down by one position
            for (int j = i; j < db->size - 1; j++) {
                db->entries[j] = db->entries[j+1];
            }
            db->size--;
            printf("Entry with ID %d removed.\n", id);
            return;
        }
    }
    printf("Error: entry with ID %d not found.\n", id);
}

// Function to print all entries in the database
void printDatabase(Database *db) {
    for (int i = 0; i < db->size; i++) {
        printf("ID: %d\tName: %s\tAge: %d\n", db->entries[i].id,
                                               db->entries[i].name,
                                               db->entries[i].age);
    }
}

int main() {
    Database db = {.size = 0};

    Person john = {.id = 1, .name = "John Smith", .age = 25};
    addEntry(&db, john);

    Person jane = {.id = 2, .name = "Jane Doe", .age = 35};
    addEntry(&db, jane);

    printDatabase(&db);

    removeEntry(&db, 3);

    removeEntry(&db, 2);

    printDatabase(&db);

    return 0;
}