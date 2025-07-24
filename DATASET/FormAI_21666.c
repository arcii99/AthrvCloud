//FormAI DATASET v1.0 Category: Database querying ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of our database schema
struct Person {
    int id;
    char name[50];
    int age;
    char occupation[50];
};

// Create a function to read the contents of the database
// and return a pointer to an array of Person structs
struct Person* read_database(char* filename) {
    // Open the file for reading
    FILE* fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Determine the number of records in the database
    int num_records = 0;
    char line[100];
    while(fgets(line, sizeof(line), fp) != NULL) {
        num_records++;
    }

    // Allocate memory for an array of Person structs
    struct Person* people = (struct Person*) malloc(num_records * sizeof(struct Person));

    // Reset file pointer to beginning of file
    rewind(fp);

    // Read each line of the file and fill in the Person structs
    int i = 0;
    while(fscanf(fp, "%d,%[^,],%d,%s\n", &people[i].id, people[i].name, &people[i].age, people[i].occupation) != EOF) {
        i++;
    }

    // Close the file
    fclose(fp);

    // Return the array of Person structs
    return people;
}

// Create a function to query the database and return a pointer to an array
// of Person structs that match the given occupation
struct Person* find_people(char* filename, char* occupation, int* num_matches) {
    // Read the database into memory
    struct Person* people = read_database(filename);

    // Allocate memory for an array of Person structs that match the given occupation
    struct Person* matches = (struct Person*) malloc(sizeof(struct Person));

    // Initialize variables
    int num_people = 0;
    *num_matches = 0;

    // Search for people with the given occupation and add them to the matches array
    for(int i = 0; i < num_people; i++) {
        if(strcmp(people[i].occupation, occupation) == 0) {
            (*num_matches)++;
            matches = (struct Person*) realloc(matches, (*num_matches) * sizeof(struct Person));
            matches[(*num_matches)-1] = people[i];
        }
    }

    // Free the memory allocated for the people array
    free(people);

    // Return the array of Person structs that match the given occupation
    return matches; 
}

int main() {
    // Query the database for all people with the occupation "teacher"
    int num_matches;
    struct Person* teachers = find_people("database.csv", "teacher", &num_matches);
    if(teachers == NULL) {
        printf("No matches found\n");
        return 1;
    }

    // Print out the results
    printf("Found %d matches:\n", num_matches);
    for(int i = 0; i < num_matches; i++) {
        printf("%d,%s,%d,%s\n", teachers[i].id, teachers[i].name, teachers[i].age, teachers[i].occupation);
    }

    // Free the memory allocated for the matches array
    free(teachers);

    return 0;
}