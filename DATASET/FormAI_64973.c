//FormAI DATASET v1.0 Category: Database simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATABASE_SIZE 100

typedef struct {
    int id;
    char name[20];
    int age;
} Person;

// Global database
Person database[MAX_DATABASE_SIZE];
int current_size = 0;

// Function to add person to database
void add_person(int id, char *name, int age) {
    Person person;
    person.id = id;
    strcpy(person.name, name);
    person.age = age;
    
    database[current_size++] = person;
}

// Function to print all people in the database
void print_all_people() {
    printf("People in database:\n");
    for (int i = 0; i < current_size; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", database[i].id, database[i].name, database[i].age);
    }
}

int main() {
    // Add some people to the database
    add_person(1, "Alice", 25);
    add_person(2, "Bob", 30);
    add_person(3, "Charlie", 20);
    
    // Print all people in the database
    print_all_people();
    
    return 0;
}