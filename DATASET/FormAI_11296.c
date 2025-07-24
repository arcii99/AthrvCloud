//FormAI DATASET v1.0 Category: Database simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for the student records
typedef struct {
    int id;
    char name[50];
    int age;
} Student;

// Define the database as an array of student records
Student database[100];

// Define a function to add a student to the database
void addStudent(int id, char* name, int age) {
    // Create a new student record
    Student newStudent = {id, "", age};
    strcpy(newStudent.name, name);

    // Find the first empty slot in the database
    int i = 0;
    while(database[i].id != 0) {
        i++;
    }

    // Add the new student record to the database
    database[i] = newStudent;

    printf("Added student %s with ID %d to the database.\n", name, id);
}

// Define a function to search for a student by ID
void searchStudent(int id) {
    // Find the student record with the given ID
    int i = 0;
    while(database[i].id != id && database[i].id != 0) {
        i++;
    }

    // Print the student record if found
    if(database[i].id == id) {
        printf("Found student with ID %d:\n", id);
        printf("Name: %s\n", database[i].name);
        printf("Age: %d\n", database[i].age);
    } else {
        printf("Student with ID %d not found.\n", id);
    }
}

int main() {
    // Initialize the database with empty records
    for(int i = 0; i < 100; i++) {
        database[i].id = 0;
        database[i].age = 0;
    }

    // Add some example students to the database
    addStudent(1, "John Doe", 20);
    addStudent(2, "Jane Smith", 19);
    addStudent(3, "Bob Johnson", 21);

    // Search for a student by ID
    searchStudent(2);

    return 0;
}