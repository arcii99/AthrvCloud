//FormAI DATASET v1.0 Category: Database simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENT_SIZE 50    //maximum size of student database

typedef struct {
    char name[20];
    int id;
    int age;
    float gpa;
} Student;

int main() {
    Student studentDB[MAX_STUDENT_SIZE];   //array to store student objects
    int numStudents = 0;    //number of students currently in the database
    int choice;     //user choice variable

    while (1) {
        printf("\n1. Add Student\n");
        printf("2. Remove Student\n");
        printf("3. View All Students\n");
        printf("4. Search for Student\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:     //add student case
                if (numStudents >= MAX_STUDENT_SIZE) {
                    printf("\nStudent database is full. Cannot add more students.\n");
                    break;
                }

                printf("\nEnter student name: ");
                scanf("%s", studentDB[numStudents].name);

                printf("Enter student ID: ");
                scanf("%d", &studentDB[numStudents].id);

                printf("Enter student age: ");
                scanf("%d", &studentDB[numStudents].age);

                printf("Enter student GPA: ");
                scanf("%f", &studentDB[numStudents].gpa);

                numStudents++;  //increment number of students
                printf("\nStudent added successfully.\n");
                break;

            case 2:     //remove student case
                if (numStudents == 0) {
                    printf("\nStudent database is empty. Cannot remove students.\n");
                    break;
                }

                int idToRemove;
                printf("\nEnter student ID to remove: ");
                scanf("%d", &idToRemove);

                int indexToRemove = -1;
                for (int i=0; i<numStudents; i++) {
                    if (studentDB[i].id == idToRemove) {
                        indexToRemove = i;
                        break;
                    }
                }

                if (indexToRemove == -1) {
                    printf("\nStudent with ID %d not found in database.\n", idToRemove);
                } else {
                    for (int i=indexToRemove; i<numStudents-1; i++) {
                        studentDB[i] = studentDB[i+1];
                    }
                    numStudents--;  //decrement number of students
                    printf("\nStudent removed successfully.\n");
                }

                break;

            case 3:     //view all students case
                if (numStudents == 0) {
                    printf("\nStudent database is empty.\n");
                    break;
                }

                printf("\nStudents in the database:\n");

                printf("%-20s\t%-10s\t%-10s\t%-10s\n", "Name", "ID", "Age", "GPA");
                for (int i=0; i<numStudents; i++) {
                    printf("%-20s\t%-10d\t%-10d\t%-10.2f\n", studentDB[i].name, studentDB[i].id, studentDB[i].age, studentDB[i].gpa);
                }

                break;

            case 4:     //search for student case
                if (numStudents == 0) {
                    printf("\nStudent database is empty. Cannot search for students.\n");
                    break;
                }

                int idToSearch;
                printf("\nEnter student ID to search: ");
                scanf("%d", &idToSearch);

                int indexToSearch = -1;
                for (int i=0; i<numStudents; i++) {
                    if (studentDB[i].id == idToSearch) {
                        indexToSearch = i;
                        break;
                    }
                }

                if (indexToSearch == -1) {
                    printf("\nStudent with ID %d not found in database.\n", idToSearch);
                } else {
                    printf("\nStudent found in the database:\n");
                    printf("%-20s\t%-10s\t%-10s\t%-10s\n", "Name", "ID", "Age", "GPA");
                    printf("%-20s\t%-10d\t%-10d\t%-10.2f\n", studentDB[indexToSearch].name, studentDB[indexToSearch].id, studentDB[indexToSearch].age, studentDB[indexToSearch].gpa);
                }

                break;

            case 5:     //exit case
                printf("\nExiting program.\n");
                exit(0);
                break;

            default:    //invalid choice case
                printf("\nInvalid choice. Please enter a valid choice.\n");
                break;
        }
    }

    return 0;
}