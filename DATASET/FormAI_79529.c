//FormAI DATASET v1.0 Category: Database Indexing System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 50

// Define the struct for a person record
typedef struct {
    int id;
    char name[MAX_STRING_LENGTH];
    char email[MAX_STRING_LENGTH];
} Person;

// Define the struct for the database
typedef struct {
    Person data[MAX_STRING_LENGTH];
    int size;
} Database;

// Define the function to search for a person by their name
int searchByName(Database* db, char* name) {
    for (int i = 0; i < db->size; i++) {
        if (strcmp(db->data[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Define the function to search for a person by their email
int searchByEmail(Database* db, char* email) {
    for (int i = 0; i < db->size; i++) {
        if (strcmp(db->data[i].email, email) == 0) {
            return i;
        }
    }
    return -1;
}

// Define the function to insert a person into the database
void insert(Database* db, Person person) {
    db->data[db->size] = person;
    db->size++;
}

// Define the main function
int main() {
    // Create a new database
    Database db = { {}, 0 };

    // Insert some sample data
    insert(&db, (Person){ 1, "Alice", "alice@example.com" });
    insert(&db, (Person){ 2, "Bob", "bob@example.com" });
    insert(&db, (Person){ 3, "Charlie", "charlie@example.com" });

    // Search for a person by name
    int index = searchByName(&db, "Charlie");
    if (index == -1) {
        printf("Person not found\n");
    } else {
        printf("ID: %d\nName: %s\nEmail: %s\n", db.data[index].id, db.data[index].name, db.data[index].email);
    }

    // Search for a person by email
    index = searchByEmail(&db, "bob@example.com");
    if (index == -1) {
        printf("Person not found\n");
    } else {
        printf("ID: %d\nName: %s\nEmail: %s\n", db.data[index].id, db.data[index].name, db.data[index].email);
    }

    // Print the entire database
    printf("Database:\n");
    for (int i = 0; i < db.size; i++) {
        printf("ID: %d\nName: %s\nEmail: %s\n", db.data[i].id, db.data[i].name, db.data[i].email);
    }

    return 0;
}