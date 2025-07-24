//FormAI DATASET v1.0 Category: File handling ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

int main() {
    FILE *fp;
    fp = fopen("students.txt", "w+");
    if(fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    
    int numStudents;
    printf("Enter the number of students to input: ");
    scanf("%d", &numStudents);
    Student *students = (Student *) malloc(numStudents * sizeof(Student));
    for(int i = 0; i < numStudents; i++) {
        printf("Enter the name of student %d: ", i+1);
        scanf("%s", students[i].name);
        printf("Enter the age of student %d: ", i+1);
        scanf("%d", &students[i].age);
        printf("Enter the GPA of student %d: ", i+1);
        scanf("%f", &students[i].gpa);
        fprintf(fp, "%s %d %.2f\n", students[i].name, students[i].age, students[i].gpa);
    }
    
    rewind(fp);
    printf("\nStudents in file:\n");
    char name[50];
    int age;
    float gpa;
    while(fscanf(fp, "%s %d %f", name, &age, &gpa) != EOF) {
        printf("Name: %s \nAge: %d\nGPA: %.2f\n\n", name, age, gpa);
    }
    
    fclose(fp);
    free(students);
    return 0;
}