//FormAI DATASET v1.0 Category: Database querying ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// A struct to represent a person with their attributes
typedef struct {
    char name[50];
    int age;
    char gender[10];
} Person;

// A database of persons
Person people[] = {
    {"John", 35, "Male"},
    {"Jane", 28, "Female"},
    {"Alex", 40, "Male"},
    {"Mary", 22, "Female"},
    {"David", 49, "Male"}
};

// Function to search for a person by name in the database
Person *find_person(char *name) {
    for (int i = 0; i < sizeof(people)/sizeof(Person); i++) {
        if (strcmp(people[i].name, name) == 0) {
            return &people[i];
        }
    }
    return NULL;
}

int main() {
    // Let's find a person in the database
    char search_name[50];
    printf("Please enter a name to search for: ");
    scanf("%s", search_name);
    
    Person *person = find_person(search_name);

    if (person == NULL) {
        printf("Sorry, could not find person with name %s\n", search_name);
    } else {
        printf("Name: %s\n", person->name);
        printf("Age: %d\n", person->age);
        printf("Gender: %s\n", person->gender);
    }

    return 0;
}