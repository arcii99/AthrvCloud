//FormAI DATASET v1.0 Category: Database simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom struct to hold information about a student
typedef struct{
    char name[50];
    int age;
    double gpa;
} Student;

int main(){
    int choice;
    int numStudents = 0;
    printf("Welcome to the Student Database simulation!\n");

    // Dynamically allocate memory for an array of 10 students
    Student* studentArray = (Student*) malloc(sizeof(Student) * 10);

    do{
        // Print the menu options
        printf("\n---------------------------------\n");
        printf("1. Add a new student\n");
        printf("2. Print all students\n");
        printf("3. Delete a student by name\n");
        printf("4. Exit\n");
        printf("---------------------------------\n");

        // Prompt user for choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                // Add a new student
                printf("\nEnter student name: ");
                scanf("%s", studentArray[numStudents].name);
                
                printf("Enter student age: ");
                scanf("%d", &studentArray[numStudents].age);
                
                printf("Enter student GPA: ");
                scanf("%lf", &studentArray[numStudents].gpa);

                printf("New student added successfully!\n");

                numStudents++;
                break;

            case 2:
                // Print all students
                printf("\nAll students:\n");
                for(int i = 0; i < numStudents; i++){
                    printf("%-20s %-5d %-5.2lf\n", studentArray[i].name, studentArray[i].age, studentArray[i].gpa);
                }
                break;

            case 3:
                // Delete a student by name
                char deleteName[50];
                printf("\nEnter student name to delete: ");
                scanf("%s", deleteName);

                int deleteIndex = -1;
                for(int i = 0; i < numStudents; i++){
                    if(strcmp(studentArray[i].name, deleteName) == 0){
                        deleteIndex = i;
                        break;
                    }
                }

                if(deleteIndex != -1){
                    numStudents--;
                    for(int i = deleteIndex; i < numStudents; i++){
                        studentArray[i] = studentArray[i+1];
                    }
                    printf("Student deleted successfully.\n");
                } else {
                    printf("Student name not found.\n");
                }
                break;

            case 4:
                // Exit the program
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice, try again.\n");
        }

    } while(choice != 4);

    // Free the dynamically allocated memory before exiting
    free(studentArray);
    return 0;
}