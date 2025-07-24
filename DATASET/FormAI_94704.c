//FormAI DATASET v1.0 Category: Database querying ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define our struct for the database
typedef struct {
    int id;
    char name[50];
    int age;
    char occupation[50];
} Person;

// Function to query the database by age
void query_database_age(Person database[], int size, int age) {
    printf("Querying database for people with age %d...\n", age);
    for(int i=0; i<size; i++) {
        if(database[i].age == age) {
            printf("ID: %d | Name: %s | Age: %d | Occupation: %s\n", database[i].id, database[i].name, database[i].age, database[i].occupation);
        }
    }
}

int main() {
    // Initialize our database
    Person database[5];
    database[0].id = 1;
    strcpy(database[0].name, "John Smith");
    database[0].age = 30;
    strcpy(database[0].occupation, "Engineer");

    database[1].id = 2;
    strcpy(database[1].name, "Jane Doe");
    database[1].age = 25;
    strcpy(database[1].occupation, "Teacher");

    database[2].id = 3;
    strcpy(database[2].name, "Bob Johnson");
    database[2].age = 35;
    strcpy(database[2].occupation, "Doctor");

    database[3].id = 4;
    strcpy(database[3].name, "Mary Smith");
    database[3].age = 30;
    strcpy(database[3].occupation, "Nurse");

    database[4].id = 5;
    strcpy(database[4].name, "Tom Jones");
    database[4].age = 40;
    strcpy(database[4].occupation, "Lawyer");

    // Query the database by age
    query_database_age(database, 5, 30);

    return 0;
}