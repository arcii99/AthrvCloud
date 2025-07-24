//FormAI DATASET v1.0 Category: Database simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct representing a person
typedef struct {
    int id;                 // Unique identifier
    char name[50];          // Name
    int age;                // Age
    char email[50];         // Email address
} Person;

// Define an array to hold people data
Person people[100];

// Define function to insert a new person into the database
void insertPerson(int id, char* name, int age, char* email) {
    // Create new person object
    Person p;
    p.id = id;
    strcpy(p.name, name);
    p.age = age;
    strcpy(p.email, email);

    // Insert person object into the array
    people[id] = p;
    printf("Successfully added person with ID %d to the database!\n", id);
}

// Define function to read a person's details from the database
void readPerson(int id) {
    if (people[id].id == 0) {
        printf("Sorry, person with ID %d does not exist in the database.\n", id);
    } else {
        printf("Person with ID %d:\n", id);
        printf("Name: %s\n", people[id].name);
        printf("Age: %d\n", people[id].age);
        printf("Email: %s\n", people[id].email);
    }
}

// Define function to update a person's details in the database
void updatePerson(int id, char* name, int age, char* email) {
    if (people[id].id == 0) {
        printf("Sorry, person with ID %d does not exist in the database.\n", id);
    } else {
        strcpy(people[id].name, name);
        people[id].age = age;
        strcpy(people[id].email, email);
        printf("Successfully updated person with ID %d in the database!\n", id);
    }
}

// Define function to delete a person from the database
void deletePerson(int id) {
    if (people[id].id == 0) {
        printf("Sorry, person with ID %d does not exist in the database.\n", id);
    } else {
        people[id].id = 0;
        strcpy(people[id].name, "");
        people[id].age = 0;
        strcpy(people[id].email, "");
        printf("Successfully deleted person with ID %d from the database!\n", id);
    }
}

// Define function to display all people in the database
void displayAllPeople() {
    printf("List of all people in the database:\n");
    for (int i = 0; i < 100; i++) {
        if (people[i].id != 0) {
            printf("Person with ID %d:\n", people[i].id);
            printf("Name: %s\n", people[i].name);
            printf("Age: %d\n", people[i].age);
            printf("Email: %s\n", people[i].email);
        }
    }
}

int main() {
    // Initialize people array with empty person objects
    for (int i = 0; i < 100; i++) {
        people[i].id = 0;
        strcpy(people[i].name, "");
        people[i].age = 0;
        strcpy(people[i].email, "");
    }

    // Insert new people into the database
    insertPerson(1, "Alice", 25, "alice@gmail.com");
    insertPerson(2, "Bob", 30, "bob@yahoo.com");

    // Read and update person details in the database
    readPerson(1);
    updatePerson(1, "Alice Smith", 26, "alice.smith@gmail.com");
    readPerson(1);

    // Delete person from the database
    deletePerson(2);

    // Display all people in the database
    displayAllPeople();

    return 0;
}