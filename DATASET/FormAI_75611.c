//FormAI DATASET v1.0 Category: Database simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char firstName[20];
    char lastName[20];
    char email[50];
    int age;
} Person;

int main() {

    FILE *file;
    Person p;

    // Create a new database file
    if ((file = fopen("database.bin", "wb")) == NULL) {
        printf("Error creating database file!\n");
        exit(1);
    }

    // Write a new person record to the database
    strcpy(p.firstName, "John");
    strcpy(p.lastName, "Doe");
    strcpy(p.email, "john.doe@gmail.com");
    p.age = 25;
    fwrite(&p, sizeof(Person), 1, file);

    // Write a second person record to the database
    strcpy(p.firstName, "Jane");
    strcpy(p.lastName, "Smith");
    strcpy(p.email, "jane.smith@gmail.com");
    p.age = 30;
    fwrite(&p, sizeof(Person), 1, file);

    fclose(file);

    // Open the database file for reading
    if ((file = fopen("database.bin", "rb")) == NULL) {
        printf("Error opening database file!\n");
        exit(1);
    }

    // Loop through all records in the database and print them to the console
    while (fread(&p, sizeof(Person), 1, file) == 1) {
        printf("First Name: %s\n", p.firstName);
        printf("Last Name: %s\n", p.lastName);
        printf("Email: %s\n", p.email);
        printf("Age: %d\n", p.age);
        printf("\n");
    }

    fclose(file);

    return 0;
}