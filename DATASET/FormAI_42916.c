//FormAI DATASET v1.0 Category: Database querying ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the structure for holding the data
typedef struct {
    int id;
    char name[20];
    char address[50];
    int age;
} Person;

// Declare the functions
void insert_person(Person *person);
void print_person(Person *person);
void query_by_name(Person *person, char *name);

// Declare the global variables
int num_persons = 0;
Person persons[10];

// Main function
int main() {
    // Create some sample data
    Person p1 = {1, "John", "123 Main Street", 25};
    Person p2 = {2, "Jane", "456 Elm Street", 30};
    Person p3 = {3, "Bob", "789 Oak Street", 40};
    
    // Insert the sample data into the database
    insert_person(&p1);
    insert_person(&p2);
    insert_person(&p3);
    
    // Query the database by name
    query_by_name(persons, "Bob");
    
    return 0;
}

// Function for inserting a person into the database
void insert_person(Person *person) {
    if(num_persons >= 10) {
        printf("Error: database full\n");
        return;
    }
    persons[num_persons++] = *person;
}

// Function for printing a person's data
void print_person(Person *person) {
    printf("ID: %d\n", person->id);
    printf("Name: %s\n", person->name);
    printf("Address: %s\n", person->address);
    printf("Age: %d\n", person->age);
}

// Function for querying the database by name
void query_by_name(Person *person, char *name) {
    int found = 0;
    for(int i = 0; i < num_persons; i++) {
        if(strcmp(person[i].name, name) == 0) {
            print_person(&person[i]);
            found++;
        }
    }
    if(!found) {
        printf("No results found\n");
    }
}