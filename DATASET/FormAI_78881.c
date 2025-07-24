//FormAI DATASET v1.0 Category: Educational ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>

/* This program demonstrates the use of structures in C for maintaining student information */
struct student{
    char name[50];
    int roll_no;
    float marks;
};

int main(){
    int n, i;
    printf("How many students do you want to enter?\n");
    scanf("%d", &n);

    // Allocate memory dynamically for student structure objects
    struct student *s = (struct student*)malloc(n * sizeof(struct student));

    for(i=0; i<n; i++){
        printf("Enter name of Student %d:\n", i+1);
        scanf("%s", s[i].name);

        printf("Enter roll number of Student %d:\n", i+1);
        scanf("%d", &s[i].roll_no);

        printf("Enter marks of Student %d:\n", i+1);
        scanf("%f", &s[i].marks);
    }

    printf("\nStudent Information:\n");
    for(i=0; i<n; i++){
        printf("Student %d:\n", i+1);
        printf("Name: %s\n", s[i].name);
        printf("Roll Number: %d\n", s[i].roll_no);
        printf("Marks: %0.2f\n\n", s[i].marks);
    }

    // Free allocated memory
    free(s);
    return 0;
}