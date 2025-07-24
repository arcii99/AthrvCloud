//FormAI DATASET v1.0 Category: Database querying ; Style: lively
/* This program is a database query example that uses C. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct for storing database entries */
struct Person {
    char name[20];
    int age;
    char occupation[20];
};

/* Prototype for function to print person record */
void printPerson(struct Person person);

/* The main function */
int main() {
    struct Person people[5];
    int i;

    /* Add some sample data */
    strcpy(people[0].name, "John");
    people[0].age = 35;
    strcpy(people[0].occupation, "Programmer");

    strcpy(people[1].name, "Jane");
    people[1].age = 28;
    strcpy(people[1].occupation, "Teacher");

    strcpy(people[2].name, "Bob");
    people[2].age = 46;
    strcpy(people[2].occupation, "Engineer");

    strcpy(people[3].name, "Sarah");
    people[3].age = 26;
    strcpy(people[3].occupation, "Nurse");

    strcpy(people[4].name, "Tom");
    people[4].age = 41;
    strcpy(people[4].occupation, "Lawyer");

    /* Print all people */
    printf("All people in database:\n");
    for (i = 0; i < 5; i++) {
        printPerson(people[i]);
    }
    printf("\n");

    /* Query for people over 30 */
    printf("People over 30:\n");
    for (i = 0; i < 5; i++) {
        if (people[i].age > 30) {
            printPerson(people[i]);
        }
    }
    printf("\n");

    /* Query for programmers */
    printf("Programmers:\n");
    for (i = 0; i < 5; i++) {
        if (strcmp(people[i].occupation, "Programmer") == 0) {
            printPerson(people[i]);
        }
    }
    printf("\n");

    /* Query for nurses under 30 */
    printf("Nurses under 30:\n");
    for (i = 0; i < 5; i++) {
        if (strcmp(people[i].occupation, "Nurse") == 0 && people[i].age < 30) {
            printPerson(people[i]);
        }
    }

    return 0;
}

/* Function to print a person record */
void printPerson(struct Person person) {
    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);
    printf("Occupation: %s\n\n", person.occupation);
}