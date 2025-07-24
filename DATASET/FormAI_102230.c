//FormAI DATASET v1.0 Category: Database simulation ; Style: grateful
#include <stdio.h>
#include <string.h>

// Define the maximum number of students the database can hold
#define MAX_STUDENTS 50

// Define the Student struct
typedef struct Student {
    int id;
    char name[50];
    float gpa;
} Student;

// Define an array to hold the students
Student students[MAX_STUDENTS];

// Define a variable to hold the number of students currently in the database
int numStudents = 0;

// Define the function to add a student to the database
void addStudent(int id, char* name, float gpa) {
    // Verify that the database is not full
    if (numStudents < MAX_STUDENTS) {
        // Create a new student object and store it in the database
        Student newStudent;
        newStudent.id = id;
        strcpy(newStudent.name, name);
        newStudent.gpa = gpa;
        students[numStudents] = newStudent;
        numStudents++;
        
        // Print a success message
        printf("Student added successfully!\n");
    } else {
        // Print an error message
        printf("Database is full. Cannot add new student.\n");
    }
}

// Define the function to remove a student from the database
void removeStudent(int id) {
    // Iterate through the database to find the student with the given ID
    int found = 0;
    int i;
    for (i = 0; i < numStudents; i++) {
        if (students[i].id == id) {
            // Remove the student from the database
            int j;
            for (j = i; j < numStudents-1; j++) {
                students[j] = students[j+1];
            }
            numStudents--;
            found = 1;
            
            // Print a success message
            printf("Student removed successfully!\n");
            break;
        }
    }
    
    // Print an error message if the student could not be found
    if (!found) {
        printf("Student with ID %d could not be found.\n", id);
    }
}

// Define the function to print all the students in the database
void printStudents() {
    // Iterate through the database and print each student's information
    int i;
    for (i = 0; i < numStudents; i++) {
        printf("ID: %d, Name: %s, GPA: %.2f\n", students[i].id, students[i].name, students[i].gpa);
    }
}

int main() {
    // Add some initial students to the database
    addStudent(1, "John Doe", 3.5);
    addStudent(2, "Jane Smith", 4.0);
    
    // Print all the students in the database
    printf("Initial student database:\n");
    printStudents();
    
    // Remove a student from the database
    removeStudent(2);
    
    // Print all the students in the database again
    printf("Updated student database:\n");
    printStudents();
    
    // Add another student to the database
    addStudent(3, "Bob Johnson", 2.8);
    
    // Print all the students in the database again
    printf("Final student database:\n");
    printStudents();
    
    return 0;
}