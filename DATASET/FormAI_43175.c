//FormAI DATASET v1.0 Category: Database querying ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a row in the database
struct Person {
    int id;
    char name[50];
    int age;
};

// Define a function to print out a person struct
void print_person(struct Person *p) {
    printf("ID: %d, Name: %s, Age: %d\n", p->id, p->name, p->age);
}

int main() {
    // Define an array of person structs
    struct Person people[3] = {
        {1, "John", 25},
        {2, "Jane", 30},
        {3, "Sam", 22}
    };
    
    // Query the database for all people aged 25 or older
    printf("People aged 25 or older:\n");
    for (int i = 0; i < 3; i++) {
        if (people[i].age >= 25) {
            print_person(&people[i]);
        }
    }
    
    // Query the database for all people with the name "Jane"
    printf("\nPeople with the name Jane:\n");
    for (int i = 0; i < 3; i++) {
        if (strcmp(people[i].name, "Jane") == 0) {
            print_person(&people[i]);
        }
    }
    
    // Query the database for a person with a specific ID
    int search_id = 2;
    printf("\nPerson with ID %d:\n", search_id);
    for (int i = 0; i < 3; i++) {
        if (people[i].id == search_id) {
            print_person(&people[i]);
            break;
        }
    }
    
    return 0;
}