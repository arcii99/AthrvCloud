//FormAI DATASET v1.0 Category: Database simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a database
typedef struct {
    char name[20];
    int age;
    char occupation[20];
} Person;

int main() {
    // Create Romeo and Juliet
    Person romeo = {"Romeo", 23, "Student"};
    Person juliet = {"Juliet", 21, "Nurse"};

    // Create an array of Persons to simulate a database
    Person database[10];

    // Add Romeo and Juliet to the database
    database[0] = romeo;
    database[1] = juliet;

    // Print the contents of the database
    printf("Database Contents: \n");

    for(int i = 0; i < 2; i++) {
        printf("Name: %s\n", database[i].name);
        printf("Age: %d\n", database[i].age);
        printf("Occupation: %s\n", database[i].occupation);
    }

    // Update Romeo's occupation
    strcpy(database[0].occupation, "Actor");

    // Print Romeo's updated occupation
    printf("\nRomeo's Updated Occupation: %s\n", database[0].occupation);

    // Remove Juliet from the database
    database[1] = (Person) {0};

    // Print the contents of the updated database
    printf("\nUpdated Database Contents: \n");

    for(int i = 0; i < 2; i++) {
        printf("Name: %s\n", database[i].name);
        printf("Age: %d\n", database[i].age);
        printf("Occupation: %s\n", database[i].occupation);
    }

    return 0;
}