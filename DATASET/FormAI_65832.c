//FormAI DATASET v1.0 Category: Database simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a person
typedef struct {
    char name[50];
    int age;
    char occupation[50];
} Person;

// Define the database
Person db[10];

// Define a function to add a new person to the database
void addPerson(int index) {
    printf("Let's add a happy new person to the database!\n");
    printf("What's their name?\n");
    scanf("%s", db[index].name);
    printf("How old are they?\n");
    scanf("%d", &db[index].age);
    printf("What do they do for a living?\n");
    scanf("%s", db[index].occupation);
}

// Define a function to print all entries in the database
void printDatabase() {
    printf("Here are all the happy people in the database!\n");
    for (int i = 0; i < 10; i++) {
        if (db[i].age > 0) { // Check if there's a person in this index
            printf("Name: %s | Age: %d | Occupation: %s\n", db[i].name, db[i].age, db[i].occupation);
        }
    }
}

int main() {
    // Initialize the database
    memset(db, 0, sizeof(db));

    // Add some people to the database
    addPerson(0);
    addPerson(1);
    addPerson(2);

    // Print the database
    printDatabase();

    return 0;
}