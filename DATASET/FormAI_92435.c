//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char name[50];
    int age;
    float weight;
};

int main() {
    printf("Welcome to the Happy CSV Reader Program!\n");

    // Open the CSV file
    FILE *file = fopen("people.csv", "r");
    if (file == NULL) {
        printf("Error: Failed to open the file 'people.csv'\n");
        return 1;
    }

    // Allocate memory for the maximum number of people
    int max_people = 100;
    struct Person *people = malloc(sizeof(struct Person) * max_people);
    if (people == NULL) {
        printf("Error: Failed to allocate memory for the people\n");
        fclose(file);
        return 1;
    }

    // Loop through the CSV rows and read the data
    char line[256];
    int count = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        char *name = strtok(line, ",");
        char *age_str = strtok(NULL, ",");
        char *weight_str = strtok(NULL, ",");

        if (name == NULL || age_str == NULL || weight_str == NULL) {
            printf("Error: Invalid CSV row: '%s'\n", line);
            continue;
        }

        // Convert the strings to the correct types
        int age = atoi(age_str);
        float weight = atof(weight_str);

        // Save the person data to the array
        struct Person *person = &people[count];
        strcpy(person->name, name);
        person->age = age;
        person->weight = weight;

        count++;

        if (count == max_people) {
            printf("Warning: Maximum number of people reached\n");
            break;
        }
    }

    // Close the file
    fclose(file);

    // Print out the people data
    printf("Total number of people read: %d\n", count);
    for (int i = 0; i < count; i++) {
        struct Person person = people[i];
        printf("Person %d: Name='%s', Age=%d, Weight=%.2f\n", i+1, person.name, person.age, person.weight);
    }

    // Free the allocated memory
    free(people);

    printf("Thank you for using the Happy CSV Reader Program! We hope you have a nice day!\n");

    return 0;
}