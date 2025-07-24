//FormAI DATASET v1.0 Category: Database simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare struct for database entry
struct Entry {
    int id;
    char name[50];
    int age;
    float score;
};

// Declare and initialize database array
struct Entry database[100] = {
    { 0, "John Doe", 25, 85.5 },
    { 1, "Jane Smith", 32, 92.3 },
    { 2, "Bob Johnson", 41, 77.8 }
};

// Declare function to print a database entry
void printEntry(struct Entry entry) {
    printf("ID: %d\nName: %s\nAge: %d\nScore: %.2f\n", entry.id, entry.name, entry.age, entry.score);
}

// Declare function to add a new entry to the database
void addEntry(int id, char* name, int age, float score) {
    // Check if ID already exists in database
    for (int i = 0; i < 100; i++) {
        if (database[i].id == id) {
            printf("ID already exists in database.\n");
            return;
        }
    }
    
    // Find first available index in database
    int index = 0;
    while (database[index].id != -1) {
        index++;
        if (index == 100) {
            printf("Database is full.\n");
            return;
        }
    }
    
    // Add new entry to database
    database[index].id = id;
    strcpy(database[index].name, name);
    database[index].age = age;
    database[index].score = score;
    printf("New entry added to database:\n");
    printEntry(database[index]);
}

// Declare function to remove an entry from the database
void removeEntry(int id) {
    // Find entry with matching ID and remove it
    for (int i = 0; i < 100; i++) {
        if (database[i].id == id) {
            database[i].id = -1;
            strcpy(database[i].name, "");
            database[i].age = 0;
            database[i].score = 0.0;
            printf("Entry with ID %d removed from database.\n", id);
            return;
        }
    }
    
    printf("Entry with ID %d not found in database.\n", id);
}

int main() {
    // Initialize remaining entries in database array
    for (int i = 3; i < 100; i++) {
        database[i].id = -1;
        strcpy(database[i].name, "");
        database[i].age = 0;
        database[i].score = 0.0;
    }
    
    // Print initial database contents
    printf("Initial database contents:\n");
    for (int i = 0; i < 100; i++) {
        if (database[i].id != -1) {
            printEntry(database[i]);
        }
    }
    
    // Add new entry and print resulting database
    addEntry(3, "Alice Lee", 28, 91.2);
    printf("Database after add:\n");
    for (int i = 0; i < 100; i++) {
        if (database[i].id != -1) {
            printEntry(database[i]);
        }
    }
    
    // Remove entry and print resulting database
    removeEntry(1);
    printf("Database after remove:\n");
    for (int i = 0; i < 100; i++) {
        if (database[i].id != -1) {
            printEntry(database[i]);
        }
    }
    
    return 0;
}