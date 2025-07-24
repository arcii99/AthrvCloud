//FormAI DATASET v1.0 Category: Database simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a person
typedef struct Person {
    int id;
    char name[50];
    int age;
} Person;

// Define the length of the database array
#define DATABASE_LEN 10

// Define the database array
Person database[DATABASE_LEN];

// Define a function to add a person to the database
void add_person(int id, char name[], int age) {
    // Find the first available index in the database array
    int index = -1;
    for (int i = 0; i < DATABASE_LEN; i++) {
        if (database[i].id == 0) {
            index = i;
            break;
        }
    }

    // If no available index was found, print an error message and return
    if (index == -1) {
        printf("Error: the database is full\n");
        return;
    }

    // Add the person to the database at the available index
    database[index].id = id;
    strncpy(database[index].name, name, sizeof(database[index].name) - 1);
    database[index].name[sizeof(database[index].name) - 1] = '\0';
    database[index].age = age;

    printf("Added person with id %d, name \"%s\", and age %d\n", id, name, age);
}

// Define a function to remove a person from the database by id number
void remove_person(int id) {
    // Find the person in the database by id number
    int index = -1;
    for (int i = 0; i < DATABASE_LEN; i++) {
        if (database[i].id == id) {
            index = i;
            break;
        }
    }

    // If the person is not found, print an error message and return
    if (index == -1) {
        printf("Error: person with id %d not found in the database\n", id);
        return;
    }

    // Remove the person from the database at the found index by setting their id to 0
    database[index].id = 0;
    memset(database[index].name, 0, sizeof(database[index].name));
    database[index].age = 0;

    printf("Removed person with id %d from the database\n", id);
}

// Define a function to print the contents of the database
void print_database() {
    printf("Database contents:\n");
    for (int i = 0; i < DATABASE_LEN; i++) {
        if (database[i].id != 0) {
            printf("id: %d, name: \"%s\", age: %d\n", database[i].id, database[i].name, database[i].age);
        }
    }
}

// Define the main function
int main() {
    // Initialize the database by setting all id numbers to 0
    for (int i = 0; i < DATABASE_LEN; i++) {
        database[i].id = 0;
    }

    // Add some people to the database
    add_person(1, "Alice", 20);
    add_person(2, "Bob", 25);
    add_person(3, "Charlie", 30);

    // Print the database contents
    print_database();

    // Remove a person from the database
    remove_person(2);

    // Print the database contents again
    print_database();

    // Add another person to the database
    add_person(4, "Dave", 35);

    // Print the database contents again
    print_database();

    return 0;
}