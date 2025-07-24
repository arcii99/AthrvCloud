//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
    char address[50];
    float gpa;
} Student;

void printStudent(Student *s) {
    printf("Name: %s\n", s->name);
    printf("Age: %d\n", s->age);
    printf("Address: %s\n", s->address);
    printf("GPA: %.2f\n", s->gpa);
}

int main() {
    FILE *fp;
    char filename[50];
    printf("Enter name of CSV file: ");
    fgets(filename, 50, stdin);
    strtok(filename, "\n"); // Remove new line character from filename
    
    fp = fopen(filename, "r");
    if (fp == NULL) { // Check if file opening is successful
        printf("Error opening file %s", filename);
        exit(1);
    }
    
    char buffer[100];
    char *field;

    int numStudents = 0;
    while (fgets(buffer, 100, fp)) { // Count number of students from number of lines in file
        numStudents++;
    }
    rewind(fp); // Go back to beginning of file

    Student *students = malloc(sizeof(Student) * numStudents);
    
    int i = 0;
    int fieldCount = 0;
    while (fgets(buffer, 100, fp)) {
        fieldCount = 0;
        field = strtok(buffer, ","); // Extract name field
        strcpy(students[i].name, field);

        while (field != NULL) {
            fieldCount++;
            field = strtok(NULL, ",");
            if (fieldCount == 2) {
                students[i].age = atoi(field); // Convert age field to int
            } else if (fieldCount == 3) {
                strcpy(students[i].address, field);
            } else if (fieldCount == 4) {
                students[i].gpa = atof(field); // Convert GPA field to float
            }
        }
        i++;
    }
    
    for (i = 0; i < numStudents; i++) { // Print all students
        printf("Student %d:\n", i+1);
        printStudent(&students[i]);
        printf("\n");
    }

    fclose(fp);

    return 0;
}