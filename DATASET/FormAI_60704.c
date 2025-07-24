//FormAI DATASET v1.0 Category: Database simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    float gpa;
};

void addStudent(struct Student *students, int *numStudents) {
    // Get student details
    char name[50];
    int age;
    float gpa;
    
    printf("Enter name: ");
    scanf("%s", name);
    
    printf("Enter age: ");
    scanf("%d", &age);
    
    printf("Enter GPA: ");
    scanf("%f", &gpa);
    
    // Create new student
    struct Student newStudent;
    strcpy(newStudent.name, name);
    newStudent.age = age;
    newStudent.gpa = gpa;
    
    // Add student to array
    students[*numStudents] = newStudent;
    *numStudents = *numStudents + 1;
    
    printf("Student added successfully!\n");
}

void viewStudents(struct Student *students, int numStudents) {
    printf("Name\tAge\tGPA\n");
    for(int i = 0; i < numStudents; i++) {
        printf("%s\t%d\t%.2f\n", students[i].name, students[i].age, students[i].gpa);
    }
}

int main() {
    int option;
    int numStudents = 0;
    struct Student students[50];

    while(1) {
        printf("\nWelcome to Student Database\n");
        printf("1. Add new student\n");
        printf("2. View all students\n");
        printf("3. Quit\n");

        printf("Enter option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                addStudent(students, &numStudents);
                break;
            case 2:
                viewStudents(students, numStudents);
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    }

    return 0;
}