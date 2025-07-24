//FormAI DATASET v1.0 Category: File handling ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 50

// Structure to represent a person
typedef struct {
    char name[MAX_NAME_SIZE];
    int age;
} Person;

// Function to compare two persons by age for sorting
int compare(Person *a, Person *b) {
    return a->age - b->age;
}

int main() {
    FILE *input_file, *output_file;
    char input_filename[] = "input.txt";
    char output_filename[] = "output.txt";

    // Open the input file for reading
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Failed to open input file '%s'\n", input_filename);
        return 1;
    }

    // Count the number of lines in the input file
    int num_lines = 0;
    char line[MAX_NAME_SIZE + 4];
    while (fgets(line, sizeof(line), input_file) != NULL) {
        num_lines++;
    }
    rewind(input_file);

    // Allocate memory for an array of persons
    Person *persons = malloc(num_lines * sizeof(Person));
    if (persons == NULL) {
        printf("Failed to allocate memory for persons\n");
        return 1;
    }

    // Read the persons from the input file
    int i = 0;
    while (fgets(line, sizeof(line), input_file) != NULL) {
        char *name = strtok(line, ",");
        int age = atoi(strtok(NULL, ","));
        if (strlen(name) >= MAX_NAME_SIZE) {
            printf("Name '%s' in input file is too long\n", name);
            return 1;
        }
        strcpy(persons[i].name, name);
        persons[i].age = age;
        i++;
    }
    fclose(input_file);

    // Sort the persons by age
    qsort(persons, num_lines, sizeof(Person), (int (*) (const void*, const void*)) compare);

    // Open the output file for writing
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Failed to open output file '%s'\n", output_filename);
        return 1;
    }

    // Write the sorted persons to the output file
    for (i = 0; i < num_lines; i++) {
        fprintf(output_file, "%s,%d\n", persons[i].name, persons[i].age);
    }
    fclose(output_file);

    // Free the memory used by the array of persons
    free(persons);

    printf("Successfully sorted data from file '%s' and wrote to file '%s'\n", input_filename, output_filename);
    return 0;
}