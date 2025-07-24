//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare a struct for storing the data
struct person {
    int id;
    char name[100];
    char address[100];
};

// Declare an array to store the data
struct person database[100];

// Declare a function to add a person to the database
void add_person(int id, char *name, char *address) {
    struct person p;
    p.id = id;
    strcpy(p.name, name);
    strcpy(p.address, address);
    database[id] = p;
}

// Declare a function to search for a person in the database by name
void search_person(char *name) {
    int found = 0;
    for (int i = 0; i < 100; i++) {
        if (strcmp(database[i].name, name) == 0) {
            printf("Person found with ID %d:\n", database[i].id);
            printf("Name: %s\n", database[i].name);
            printf("Address: %s\n", database[i].address);
            found = 1;
        }
    }
    if (!found) {
        printf("No person found with name '%s'\n", name);
    }
}

// Declare a function to print the entire database
void print_database() {
    printf("Database:\n");
    for (int i = 0; i < 100; i++) {
        if (database[i].id != 0) {
            printf("ID: %d\n", database[i].id);
            printf("Name: %s\n", database[i].name);
            printf("Address: %s\n", database[i].address);
        }
    }
}

int main() {
    printf("Welcome to the C database indexing system!\n");

    // Add some persons to the database
    add_person(1, "John Watson", "221B Baker Street");
    add_person(2, "Sherlock Holmes", "221B Baker Street");
    add_person(3, "Irene Adler", "Briony Lodge");

    // Search for a person by name
    printf("\nSearching for a person by name:\n");
    search_person("Sherlock Holmes");

    // Print the entire database
    printf("\nPrinting the entire database:\n");
    print_database();

    printf("\nEnd of program.\n");

    return 0;
}