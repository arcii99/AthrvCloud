//FormAI DATASET v1.0 Category: File handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold student details
struct Student {
    char name[50];
    char address[100];
    int age;
    float gpa;
};

void printStudentDetails(struct Student stud) {
    printf("Name: %s\n", stud.name);
    printf("Address: %s\n", stud.address);
    printf("Age: %d\n", stud.age);
    printf("GPA: %.2f\n", stud.gpa);
}

int main() {
    // Define an array of students
    struct Student students[3];

    // Populate the student details
    strcpy(students[0].name, "John Doe");
    strcpy(students[0].address, "123 Main Street, Anytown USA");
    students[0].age = 18;
    students[0].gpa = 3.2;

    strcpy(students[1].name, "Jane Smith");
    strcpy(students[1].address, "456 Elm Street, Anytown USA");
    students[1].age = 19;
    students[1].gpa = 3.7;

    strcpy(students[2].name, "Bob Johnson");
    strcpy(students[2].address, "789 Oak Street, Anytown USA");
    students[2].age = 20;
    students[2].gpa = 3.5;

    // Define a file pointer
    FILE *fptr;

    // Open the file for writing
    fptr = fopen("students.txt", "w");

    // Check if file is successfully opened
    if (fptr == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Write the student details to the file
    for (int i = 0; i < 3; i++) {
        fprintf(fptr, "%s\n", students[i].name);
        fprintf(fptr, "%s\n", students[i].address);
        fprintf(fptr, "%d\n", students[i].age);
        fprintf(fptr, "%.2f\n", students[i].gpa);
    }

    // Close the file
    fclose(fptr);

    // Open the file for reading
    fptr = fopen("students.txt", "r");

    // Check if file is successfully opened
    if (fptr == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Read the student details from the file
    for (int i = 0; i < 3; i++) {
        fgets(students[i].name, 50, fptr);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';
        fgets(students[i].address, 100, fptr);
        students[i].address[strcspn(students[i].address, "\n")] = '\0';
        fscanf(fptr, "%d", &students[i].age);
        fscanf(fptr, "%f", &students[i].gpa);
    }

    // Close the file
    fclose(fptr);

    // Print the student details
    printf("Student Details:\n");
    for (int i = 0; i < 3; i++) {
        printStudentDetails(students[i]);
    }

    return 0;
}