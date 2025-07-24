//FormAI DATASET v1.0 Category: Sorting ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Define a struct to hold information about a student
typedef struct {
    char name[20];
    int student_id;
    float gpa;
} Student;

// Define a function to sort an array of students based on GPA
void sort_students(Student *students, int num_students) {
    int i, j;
    Student temp;

    for (i = 0; i < num_students - 1; i++) {
        for (j = i + 1; j < num_students; j++) {
            if (students[i].gpa < students[j].gpa) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

// Define a function to print the information for all students in an array
void print_students(Student *students, int num_students) {
    int i;

    for (i = 0; i < num_students; i++) {
        printf("%s (ID: %d) has a GPA of %.2f\n", students[i].name,
               students[i].student_id, students[i].gpa);
    }
}

int main() {
    // Create an array of students
    Student students[5] = {
        {"Alice", 12345, 3.8},
        {"Bob", 23456, 2.7},
        {"Charlie", 34567, 4.0},
        {"David", 45678, 2.9},
        {"Eve", 56789, 3.5}
    };

    // Print the initial list of students
    printf("Initial list of students:\n");
    print_students(students, 5);

    // Sort the array of students based on GPA
    sort_students(students, 5);

    // Print the sorted list of students
    printf("\nSorted list of students:\n");
    print_students(students, 5);

    return 0;
}