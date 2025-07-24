//FormAI DATASET v1.0 Category: Database simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Define a structure to hold the data
typedef struct {
    int id;
    char name[50];
    int age;
} Person;

// Define an array to hold the data
Person people[100];

// Define a function to populate the array with some test data
void populateData() {
    people[0].id = 1;
    strcpy(people[0].name, "John");
    people[0].age = 30;

    people[1].id = 2;
    strcpy(people[1].name, "Jane");
    people[1].age = 25;

    people[2].id = 3;
    strcpy(people[2].name, "Bob");
    people[2].age = 42;
}

// Define a function to print the data in the array
void printData() {
    int i;
    for (i = 0; i < 3; i++) {
        printf("ID: %d\n", people[i].id);
        printf("Name: %s\n", people[i].name);
        printf("Age: %d\n", people[i].age);
    }
}

int main() {

    // Call the function to populate the array with test data
    populateData();

    // Call the function to print the data in the array
    printData();

    return 0;
}