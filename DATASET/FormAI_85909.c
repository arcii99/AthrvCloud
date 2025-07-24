//FormAI DATASET v1.0 Category: Database simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a database record
typedef struct {
    int id;
    char name[20];
    int age;
} Person;

// Define an array to hold the records
Person people[100];

// Define a function to add a person to the database
void addPerson(int id, char *name, int age) {
    Person p;
    p.id = id;
    strcpy(p.name, name);
    p.age = age;
    people[id] = p;
}

// Define a function to display all the records in the database
void displayDatabase() {
    printf("ID\tName\tAge\n");
    for (int i=0; i<100; i++) {
        if (people[i].id != 0) {
            printf("%d\t%s\t%d\n", people[i].id, people[i].name, people[i].age);
        }
    }
}

// Define a function to delete a person from the database
void deletePerson(int id) {
    people[id].id = 0;
    strcpy(people[id].name, "");
    people[id].age = 0;
}

int main() {
    // Add some people to the database
    addPerson(1, "Alice", 25);
    addPerson(2, "Bob", 30);
    addPerson(3, "Charlie", 35);
    
    // Display the database
    printf("Initial Database:\n");
    displayDatabase();

    // Delete a person from the database
    deletePerson(2);
    
    // Display the database again
    printf("\nDatabase after deleting Bob:\n");
    displayDatabase();

    return 0;
}