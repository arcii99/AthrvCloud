//FormAI DATASET v1.0 Category: Database simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a struct to hold student information
struct Student {
    int id;
    char name[50];
    int age;
};

int main() {
    int choice;

    // Create an array of students
    struct Student students[100];

    // Initialize variables
    int num_students = 0;
    int id;
    char name[50];
    int age;

    printf("*** Student Database Simulation ***\n");

    while (1) {
        // Display menu
        printf("\n1. Add student\n");
        printf("2. Remove student\n");
        printf("3. View all students\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add a student
                printf("\n*** Add Student ***\n");

                // Get student information
                printf("Enter student ID: ");
                scanf("%d", &id);
                fflush(stdin);  // Flush input buffer

                printf("Enter student name: ");
                fgets(name, 50, stdin);
                // Remove newline character at the end of the string
                name[strcspn(name, "\n")] = 0;

                printf("Enter student age: ");
                scanf("%d", &age);

                // Create a new student struct
                struct Student new_student = {id, name, age};
                students[num_students] = new_student;
                num_students++;

                printf("Student added successfully.\n");

                break;
            case 2:
                // Remove a student
                printf("\n*** Remove Student ***\n");

                printf("Enter student ID: ");
                scanf("%d", &id);

                // Loop through students array to find student with matching ID
                int index_to_remove = -1;
                for (int i = 0; i < num_students; i++) {
                    if (students[i].id == id) {
                        index_to_remove = i;
                        break;
                    }
                }

                if (index_to_remove == -1) {
                    printf("Student with ID %d not found.\n", id);
                } else {
                    // Remove student from array by shifting all elements to the left
                    for (int i = index_to_remove; i < num_students - 1; i++) {
                        students[i] = students[i + 1];
                    }
                    num_students--;
                    printf("Student removed successfully.\n");
                }
    
                break;
            case 3:
                // View all students
                printf("\n*** View All Students ***\n");

                if (num_students == 0) {
                    printf("No students found.\n");
                } else {
                    printf("ID\tName\t\tAge\n");
                    for (int i = 0; i < num_students; i++) {
                        printf("%d\t%s\t\t%d\n", students[i].id, students[i].name, students[i].age);
                    }
                }

                break;
            case 4:
                // Exit program
                printf("\nExiting program.\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}