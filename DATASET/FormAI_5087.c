//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 50

// Initialize the struct for a person's information
struct person {
    char name[MAX_NAME_LENGTH];
    int age;
    float height;
};

// Initialize the struct for the index
struct index {
    char name[MAX_NAME_LENGTH];
    int record_number;
};

// Declare the variables for the arrays of people and indexes
struct person people[MAX_RECORDS];
struct index indexes[MAX_RECORDS];

// Declare the variable for the number of records in the database
int num_records = 0;

// Function to add a person to the database
void add_person(char* name, int age, float height) {
    if (num_records < MAX_RECORDS) {
        // Add the person to the array of people
        strcpy(people[num_records].name, name);
        people[num_records].age = age;
        people[num_records].height = height;

        // Add an index for the person
        strcpy(indexes[num_records].name, name);
        indexes[num_records].record_number = num_records;

        // Increment the number of records
        num_records++;
    }
}

// Function to find a person in the database by name using binary search
int find_person(char* name) {
    int low = 0;
    int high = num_records - 1;
    int mid;

    while(low <= high) {
        mid = (low + high) / 2;
        if(strcmp(name, indexes[mid].name) < 0)
            high = mid - 1;
        else if(strcmp(name, indexes[mid].name) > 0)
            low = mid + 1;
        else
            return indexes[mid].record_number;
    }

    return -1;
}

// Function to print a person's information
void print_person(int record_number) {
    printf("Name: %s\n", people[record_number].name);
    printf("Age: %d\n", people[record_number].age);
    printf("Height: %.2f\n", people[record_number].height);
}

// Main function to test the database indexing system
int main() {
    // Add some test people to the database
    add_person("Alice", 25, 1.65);
    add_person("Bob", 30, 1.75);
    add_person("Charlie", 20, 1.80);
    add_person("David", 35, 1.70);

    // Test searching for a person and printing their information
    int record_number = find_person("Bob");
    if(record_number != -1)
        print_person(record_number);
    else
        printf("Person not found.\n");

    return 0;
}