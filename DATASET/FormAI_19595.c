//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    int id;
    char name[BUFFER_SIZE];
    int age;
} Person; // Define the Person struct

int main() {
    FILE *fp = fopen("people.csv", "r"); // Open CSV file
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    Person people[BUFFER_SIZE]; // Create array to hold Person structs
    int count = 0; // Keep track of number of Persons read

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, fp)) {
        char *token = strtok(buffer, ","); // Split string by comma
        people[count].id = atoi(token); // Convert ID to integer
        token = strtok(NULL, ",");
        strcpy(people[count].name, token); // Copy name to Person struct
        token = strtok(NULL, ",");
        people[count].age = atoi(token); // Convert age to integer
        count++;
    }

    fclose(fp);

    // Print out all the Persons read from CSV file
    for (int i = 0; i < count; i++) {
        printf("Person %d:\n", i+1);
        printf("ID: %d\n", people[i].id);
        printf("Name: %s\n", people[i].name);
        printf("Age: %d\n", people[i].age);
    }

    return 0;
}