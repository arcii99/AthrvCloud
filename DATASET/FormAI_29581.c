//FormAI DATASET v1.0 Category: Database simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_AGE 120

typedef struct Person{
    char name[30];
    int age;
} Person;

int main(){
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the database
    Person database[MAX_SIZE];
    int num_people = 0;

    // Generate random data
    for(int i = 0; i < MAX_SIZE; i++){
        // Create a new person
        Person new_person;

        // Generate a random name
        char name[30];
        for(int j = 0; j < 30; j++){
            name[j] = rand() % 26 + 'a';
        }

        // Add the name to the person
        strcpy(new_person.name, name);

        // Generate a random age
        new_person.age = rand() % MAX_AGE;

        // Add the person to the database
        database[num_people++] = new_person;
    }

    // Print the number of people in the database
    printf("There are %d people in the database.\n", num_people);

    // Print the data for the first 10 people in the database
    for(int i = 0; i < 10; i++){
        printf("%s, %d\n", database[i].name, database[i].age);
    }

    // Free the memory used by the database
    free(database);

    return 0;
}