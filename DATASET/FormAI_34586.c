//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct to hold CSV data
typedef struct {
    char* name;
    int age;
    float height;
} Person;

// Function to read and parse CSV data
int readCSV(char* filename, Person** people) {
    FILE* file = fopen(filename, "r");

    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return -1;
    }

    int line_count = 0;
    char line_buffer[256];

    // Count the number of lines in the file
    while (fgets(line_buffer, sizeof(line_buffer), file)) {
        line_count++;
    }

    rewind(file);

    // Allocate memory for the array of people
    *people = malloc(line_count * sizeof(Person));

    int index = 0;

    // Loop through each line of the file and parse data
    while (fgets(line_buffer, sizeof(line_buffer), file)) {
        char* name_token = strtok(line_buffer, ",");
        char* age_token = strtok(NULL, ",");
        char* height_token = strtok(NULL, ",");

        // Remove new line character from last token
        if (height_token[strlen(height_token) - 1] == '\n') {
            height_token[strlen(height_token) - 1] = '\0'; 
        }

        // Set values for person struct
        (*people)[index].name = malloc(strlen(name_token) + 1);
        strcpy((*people)[index].name, name_token);
        (*people)[index].age = atoi(age_token);
        (*people)[index].height = atof(height_token);

        index++;
    }

    fclose(file);

    return line_count;
}

int main() {
    Person* people;
    int count = readCSV("people.csv", &people);

    if (count == -1) {
        exit(1);
    }

    // Print out the data for each person
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Age: %d, Height: %.2f\n", 
               people[i].name, 
               people[i].age, 
               people[i].height);

        free(people[i].name);
    }

    free(people);

    return 0;
}