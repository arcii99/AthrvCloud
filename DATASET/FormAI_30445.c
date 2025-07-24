//FormAI DATASET v1.0 Category: Database simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a student's information
typedef struct {
    int id;
    char name[50];
    char address[100];
    float gpa;
} Student;

// Define the maximum number of students our program can store
#define MAX_STUDENTS 10

// Define a global array of students
Student students[MAX_STUDENTS];

// Define a function to print a student's information
void printStudent(Student s) {
    printf("ID: %d\nName: %s\nAddress: %s\nGPA: %.2f\n", s.id, s.name, s.address, s.gpa);
}

int main() {
    int choice, i, id;
    char name[50], address[100];
    float gpa;

    // Initialize all students in the array to have an ID of -1 (which indicates they are empty)
    for (i = 0; i < MAX_STUDENTS; i++) {
        students[i].id = -1;
    }

    // Main program loop
    do {
        // Print the menu options
        printf("====================\n");
        printf(" 1. Add student\n");
        printf(" 2. Delete student\n");
        printf(" 3. Update student\n");
        printf(" 4. List all students\n");
        printf(" 5. Exit\n");
        printf("====================\n");
        // Get the user's choice
        printf("Enter choice: ");
        scanf("%d", &choice);

        // Handle each menu option
        switch (choice) {
            case 1:
                // Add a new student
                for (i = 0; i < MAX_STUDENTS; i++) {
                    if (students[i].id == -1) {
                        printf("Enter student ID: ");
                        scanf("%d", &students[i].id);
                        printf("Enter student name: ");
                        scanf("%s", students[i].name);
                        printf("Enter student address: ");
                        scanf("%s", students[i].address);
                        printf("Enter student GPA: ");
                        scanf("%f", &students[i].gpa);
                        break;
                    }
                }
                if (i == MAX_STUDENTS) {
                    printf("Error: Reached maximum number of students (%d)\n", MAX_STUDENTS);
                }
                break;
            case 2:
                // Delete a student
                printf("Enter ID of student to delete: ");
                scanf("%d", &id);
                for (i = 0; i < MAX_STUDENTS; i++) {
                    if (students[i].id == id) {
                        students[i].id = -1;
                        break;
                    }
                }
                if (i == MAX_STUDENTS) {
                    printf("Error: Student not found\n");
                }
                break;
            case 3:
                // Update a student's information
                printf("Enter ID of student to update: ");
                scanf("%d", &id);
                for (i = 0; i < MAX_STUDENTS; i++) {
                    if (students[i].id == id) {
                        printf("Enter new name: ");
                        scanf("%s", students[i].name);
                        printf("Enter new address: ");
                        scanf("%s", students[i].address);
                        printf("Enter new GPA: ");
                        scanf("%f", &students[i].gpa);
                        break;
                    }
                }
                if (i == MAX_STUDENTS) {
                    printf("Error: Student not found\n");
                }
                break;
            case 4:
                // List all students
                for (i = 0; i < MAX_STUDENTS; i++) {
                    if (students[i].id != -1) {
                        printf("====================\n");
                        printStudent(students[i]);
                    }
                }
                break;
            case 5:
                // Exit the program
                printf("Goodbye!\n");
                break;
            default:
                // Invalid choice
                printf("Error: Invalid choice\n");
                break;
        }
    } while (choice != 5);

    return 0;
}