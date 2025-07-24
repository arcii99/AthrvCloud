//FormAI DATASET v1.0 Category: Database querying ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char gender[10];
} Person;

void searchByName(char *name, Person *people, int numPeople) {
    bool found = false;

    for (int i = 0; i < numPeople; i++) {
        if (strcmp(name, people[i].name) == 0) {
            printf("ID: %d\tName: %s\tAge: %d\tGender: %s\n", people[i].id, people[i].name, people[i].age, people[i].gender);
            found = true;
        }
    }

    if (!found) {
        printf("No results found for name '%s'\n", name);
    }
}

int main() {
    int numPeople = 4;
    Person people[numPeople];

    // Create sample data
    people[0].id = 1;
    strcpy(people[0].name, "John");
    people[0].age = 25;
    strcpy(people[0].gender, "Male");

    people[1].id = 2;
    strcpy(people[1].name, "Jane");
    people[1].age = 30;
    strcpy(people[1].gender, "Female");

    people[2].id = 3;
    strcpy(people[2].name, "Alex");
    people[2].age = 40;
    strcpy(people[2].gender, "Non-binary");

    people[3].id = 4;
    strcpy(people[3].name, "Sarah");
    people[3].age = 22;
    strcpy(people[3].gender, "Female");

    printf("===== QUERYING DATABASE =====\n");

    // Search for a person by name
    printf("\nSearching for person named Jane...\n");
    searchByName("Jane", people, numPeople);

    // Search for a person that doesn't exist
    printf("\nSearching for person named Elvis...\n");
    searchByName("Elvis", people, numPeople);

    return 0;
}