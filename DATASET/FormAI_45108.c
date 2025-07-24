//FormAI DATASET v1.0 Category: Database querying ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a person
typedef struct Person {
    char name[50];
    int age;
    char occupation[50];
} Person;

// Define a function to search for a person by their name
void search_person_by_name(char* name, Person* people, int num_people) {
    // Loop through all people and print any matches
    for (int i = 0; i < num_people; i++) {
        if (strcmp(name, people[i].name) == 0) {
            printf("Name: %s, Age: %d, Occupation: %s\n", 
                    people[i].name, people[i].age, people[i].occupation);
        }
    }
}

int main() {
    // Define an array of Person structures
    Person people[3];
    strcpy(people[0].name, "Alice");
    people[0].age = 30;
    strcpy(people[0].occupation, "Engineer");
    strcpy(people[1].name, "Bob");
    people[1].age = 25;
    strcpy(people[1].occupation, "Developer");
    strcpy(people[2].name, "Charlie");
    people[2].age = 40;
    strcpy(people[2].occupation, "Manager");

    // Call the search_person_by_name function to find and print Alice's details
    search_person_by_name("Alice", people, 3);

    return 0;
}