//FormAI DATASET v1.0 Category: Online Examination System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float marks;
} Student;

void display(Student s) {
    printf("Id: %d\n", s.id);
    printf("Name: %s\n", s.name);
    printf("Marks: %0.2f\n", s.marks);
}

void startExam() {
    int n, i, j, choice;
    Student students[50];
    printf("Enter the number of students: ");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        printf("\nStudent %d:\n", i+1);
        students[i].id = i+1;
        printf("Enter the name: ");
        scanf("%s", students[i].name);
        printf("Enter the marks obtained: ");
        scanf("%f", &students[i].marks);
    }

    printf("\n\n");
    printf("Welcome to the Online Examination System\n");
    printf("=======================================\n");
    printf("1. View all students\n");
    printf("2. Search for a student by name\n");
    printf("3. Search for a student by id\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            for(i=0; i<n; i++) {
                printf("\nStudent %d:\n", i+1);
                display(students[i]);
            }
            break;
        case 2:
            char searchName[50];
            printf("\nEnter the name to search: ");
            scanf("%s", searchName);
            for(i=0; i<n; i++) {
                if(strcmp(students[i].name, searchName) == 0) {
                    display(students[i]);
                    break;
                }
            }
            if(i == n) {
                printf("No student found with the name %s", searchName);
            }
            break;
        case 3:
            int searchId;
            printf("\nEnter the id to search: ");
            scanf("%d", &searchId);
            for(i=0; i<n; i++) {
                if(students[i].id == searchId) {
                    display(students[i]);
                    break;
                }
            }
            if(i == n) {
                printf("No student found with the id %d", searchId);
            }
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!");
            break;
    }
}

int main() {
    startExam();

    return 0;
}