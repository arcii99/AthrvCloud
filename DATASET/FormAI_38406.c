//FormAI DATASET v1.0 Category: Online Examination System ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

// A structure to hold information of a student
struct Student{
    char name[30];
    int roll;
    float marks;
};

void main(){
    printf("Welcome to the Online Examination System!\n");
    printf("Please enter the number of students to take the exam: ");
    
    int n;
    scanf("%d", &n);

    // Dynamically allocate memory for array of students
    struct Student* students = (struct Student*)malloc(n*sizeof(struct Student));

    // Take input for each student
    for(int i=0; i < n; i++){
        printf("\nEnter name of student %d: ", i+1);
        scanf("%s", (students+i)->name);

        printf("Enter roll number of student %d: ", i+1);
        scanf("%d", &(students+i)->roll);

        printf("Enter marks of student %d: ", i+1);
        scanf("%f", &(students+i)->marks);
    }

    // Show the results
    printf("\n***** Results *****\n");

    for(int i=0; i < n; i++){
        printf("Name: %s\n", (students+i)->name);
        printf("Roll: %d\n", (students+i)->roll);
        printf("Marks: %.2f\n\n", (students+i)->marks);
    }

    // Free dynamically allocated memory
    free(students);
}