//FormAI DATASET v1.0 Category: Educational ; Style: innovative
#include <stdio.h>

// Define a struct for a student
typedef struct {
    char name[20];
    int age;
    float gpa;
} Student;

int main() {
    // Declare and initialize a new student
    Student s = {"John Doe", 18, 3.8};

    // Print out the student's information
    printf("Name: %s\n", s.name);
    printf("Age: %d\n", s.age);
    printf("GPA: %.2f\n", s.gpa);

    // Update the student's name and GPA
    strcpy(s.name, "Jane Smith");
    s.gpa = 4.0;

    // Print out the updated information
    printf("Updated Name: %s\n", s.name);
    printf("Updated GPA: %.2f\n", s.gpa);

    return 0;
}