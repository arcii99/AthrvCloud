//FormAI DATASET v1.0 Category: Database Indexing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Simple Example of a C Database Indexing System
// This program will store student records, and make them searchable by last name

// Define the maximum number of records that can be stored in the database
#define MAX_RECORDS 100

// Define the maximum length of a last name
#define MAX_NAME_LENGTH 25

// Define the structure of a student record
struct StudentRecord {
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    int age;
    int gradeLevel;
};

// Define an array to store the student records
struct StudentRecord studentDatabase[MAX_RECORDS];

// Define an index array that stores the position of each record in the studentDatabase array,
// sorted by last name
int lastNameIndex[MAX_RECORDS];

// Define a helper function to sort the lastNameIndex array by last name
void sortIndexArray(int *arr, int len) {
    int i, j, temp;
    for (i = 0; i < len - 1; i++) {
        for (j = i + 1; j < len; j++) {
            if (strcmp(studentDatabase[arr[i]].lastName, studentDatabase[arr[j]].lastName) > 0) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int numRecords = 0;
    int i, j;

    // Add some sample records to the database
    strcpy(studentDatabase[0].firstName, "John");
    strcpy(studentDatabase[0].lastName, "Doe");
    studentDatabase[0].age = 16;
    studentDatabase[0].gradeLevel = 11;

    strcpy(studentDatabase[1].firstName, "Jane");
    strcpy(studentDatabase[1].lastName, "Smith");
    studentDatabase[1].age = 15;
    studentDatabase[1].gradeLevel = 10;

    strcpy(studentDatabase[2].firstName, "Bob");
    strcpy(studentDatabase[2].lastName, "Jones");
    studentDatabase[2].age = 17;
    studentDatabase[2].gradeLevel = 12;

    // Update the number of records in the database
    numRecords = 3;

    // Fill the lastNameIndex array with the indices of each record
    for (i = 0; i < numRecords; i++) {
        lastNameIndex[i] = i;
    }

    // Sort the lastNameIndex array by last name
    sortIndexArray(lastNameIndex, numRecords);

    // Print out the records in the order of the lastNameIndex array
    printf("Records sorted by last name:\n");
    for (i = 0; i < numRecords; i++) {
        j = lastNameIndex[i];
        printf("%s %s\n", studentDatabase[j].firstName, studentDatabase[j].lastName);
        printf("Age: %d\n", studentDatabase[j].age);
        printf("Grade: %d\n\n", studentDatabase[j].gradeLevel);
    }

    return 0;
}