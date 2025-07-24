//FormAI DATASET v1.0 Category: Database simulation ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a struct to represent a person
typedef struct {
    char firstName[20];
    char lastName[20];
    int age;
    int id;
} Person;

// Declare an array of people and a counter for the number of people currently in the database
Person people[50];
int numPeople = 0;

// Function to add a person to the database
void addPerson(char* firstName, char* lastName, int age) {
    // Create a new Person struct with the given information and generate a unique ID
    Person newPerson;
    strcpy(newPerson.firstName, firstName);
    strcpy(newPerson.lastName, lastName);
    newPerson.age = age;
    newPerson.id = numPeople + 1;
    
    // Add the new person to the array of people and increment the counter
    people[numPeople] = newPerson;
    numPeople++;
    
    printf("Added %s %s to the database with ID %d!\n", firstName, lastName, newPerson.id);
}

// Function to print out all of the people in the database
void printDatabase() {
    printf("Current database:\n");
    for (int i = 0; i < numPeople; i++) {
        printf("%s %s, Age: %d, ID: %d\n", people[i].firstName, people[i].lastName, people[i].age, people[i].id);
    }
}

int main() {
    // Welcome message
    printf("Welcome to the People Database!\n");
    
    // Test Case: Add a few people to the database
    addPerson("John", "Smith", 32);
    addPerson("Alice", "Jones", 26);
    addPerson("Bob", "Johnson", 45);
    printDatabase();
    
    // Test Case: Add another person to the database
    addPerson("Emily", "Brown", 19);
    printDatabase();
    
    return 0;
}