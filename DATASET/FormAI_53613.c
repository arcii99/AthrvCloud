//FormAI DATASET v1.0 Category: Database querying ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold data of each record
typedef struct {
    int id;
    char name[50];
    int age;
} Person;

int main() {
    FILE *file;
    Person person;
    int size = sizeof(person);
    char query[50];

    // Open file in read mode
    file = fopen("people.dat", "rb");

    // Check if file was opened successfully
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Get user input for query
    printf("Enter name to search: ");
    fgets(query, 50, stdin);
    strtok(query, "\n"); // Remove newline character

    // Loop through file to find matching records
    while (fread(&person, size, 1, file) == 1) {
        if (strcmp(person.name, query) == 0) {
            printf("ID: %d\n", person.id);
            printf("Name: %s\n", person.name);
            printf("Age: %d\n\n", person.age);
        }
    }

    // Close file
    fclose(file);

    return 0;
}