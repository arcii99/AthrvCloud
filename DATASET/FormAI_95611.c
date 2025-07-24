//FormAI DATASET v1.0 Category: Database querying ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define struct to store data
typedef struct {
    int id;
    char firstName[20];
    char lastName[20];
    int age;
    char phoneNumber[20];
} Person;

// Function to query the database and display results
void queryDatabase(Person* people, int numPeople, char* query) {
    printf("Searching for people with last name \"%s\"...\n", query);
    // loop through each person in the database
    for(int i = 0; i < numPeople; i++) {
        // if the last name matches the query, print out the person's information
        if(strcmp(people[i].lastName, query) == 0) {
            printf("ID: %d\n", people[i].id);
            printf("First Name: %s\n", people[i].firstName);
            printf("Last Name: %s\n", people[i].lastName);
            printf("Age: %d\n", people[i].age);
            printf("Phone Number: %s\n\n", people[i].phoneNumber);
        }
    }
}

int main() {
    // create an array of Person structs
    Person people[5];
    // populate the array with sample data
    people[0].id = 1;
    strcpy(people[0].firstName, "John");
    strcpy(people[0].lastName, "Smith");
    people[0].age = 25;
    strcpy(people[0].phoneNumber, "123-456-7890");
    people[1].id = 2;
    strcpy(people[1].firstName, "Jane");
    strcpy(people[1].lastName, "Doe");
    people[1].age = 30;
    strcpy(people[1].phoneNumber, "555-555-5555");
    people[2].id = 3;
    strcpy(people[2].firstName, "Bob");
    strcpy(people[2].lastName, "Johnson");
    people[2].age = 40;
    strcpy(people[2].phoneNumber, "999-999-9999");
    people[3].id = 4;
    strcpy(people[3].firstName, "Alice");
    strcpy(people[3].lastName, "Williams");
    people[3].age = 22;
    strcpy(people[3].phoneNumber, "111-222-3333");
    people[4].id = 5;
    strcpy(people[4].firstName, "Tom");
    strcpy(people[4].lastName, "Wilson");
    people[4].age = 35;
    strcpy(people[4].phoneNumber, "444-444-4444");
    
    // call queryDatabase function with different query values
    queryDatabase(people, 5, "Smith");
    queryDatabase(people, 5, "Doe");
    queryDatabase(people, 5, "Wilson");
    return 0;
}