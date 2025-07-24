//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORD_LENGTH 100

typedef struct {
    char name[20];
    int age;
    char email[30];
} Person;

int main() {
    FILE *csv_file;
    char buffer[MAX_RECORD_LENGTH];
    char *field;
    Person person;

    // Open the CSV file
    csv_file = fopen("example.csv", "r");
    if (csv_file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Read and ignore the header row
    fgets(buffer, MAX_RECORD_LENGTH, csv_file);

    // Read each record and print its fields
    while (fgets(buffer, MAX_RECORD_LENGTH, csv_file) != NULL) {
        // Extract the fields from the record
        field = strtok(buffer, ",");
        strcpy(person.name, field);
        field = strtok(NULL, ",");
        person.age = atoi(field);
        field = strtok(NULL, ",");
        strcpy(person.email, field);

        // Print the fields
        printf("Name: %s, Age: %d, Email: %s\n", person.name, person.age, person.email);
    }

    // Close the CSV file
    fclose(csv_file);

    return 0;
}