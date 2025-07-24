//FormAI DATASET v1.0 Category: Memory management ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>

struct student {
    int rollno;
    char name[20];
    float marks;
} *stud;

int main() {

    int n, i;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    stud = (struct student*)malloc(n * sizeof(struct student)); // Memory allocation

    if(stud == NULL) { // Handle allocation error
        printf("Memory allocation failed.");
        return 0;
    }

    for(i=0; i<n; i++) {
        printf("\nEnter details of student %d:\n", i+1);
        printf("Roll No: ");
        scanf("%d", &stud[i].rollno);
        printf("Name: ");
        scanf("%s", stud[i].name);
        printf("Marks: ");
        scanf("%f", &stud[i].marks);
    }

    printf("\nDetails of students:\n");

    for(i=0; i<n; i++) {
        printf("\nStudent %d:", i+1);
        printf("\nRoll No: %d", stud[i].rollno);
        printf("\nName: %s", stud[i].name);
        printf("\nMarks: %.2f", stud[i].marks);
    }

    free(stud); // Memory deallocation

    return 0;
}