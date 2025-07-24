//FormAI DATASET v1.0 Category: Data structures visualization ; Style: creative
#include <stdio.h>

// define structure student
struct student {
    char name[100];
    int id;
    float gpa;
};

// define function to print a student
void printStudent(struct student s) {
    printf("Name: %s\n", s.name);
    printf("ID: %d\n", s.id);
    printf("GPA: %.2f\n", s.gpa);
    printf("\n");
}

// define function to find the student with the highest GPA
struct student * findHighestGPA(struct student * students, int numStudents) {
    struct student * highest = &students[0];
    for (int i = 1; i < numStudents; i++) {
        if (students[i].gpa > highest->gpa) {
            highest = &students[i];
        }
    }
    return highest;
}

int main() {
    // create array of students
    struct student students[3] = {
        {"Ada Lovelace", 1001, 3.5},
        {"Grace Hopper", 1002, 4.0},
        {"Alan Turing", 1003, 3.8}
    };

    // print each student
    for (int i = 0; i < 3; i++) {
        printStudent(students[i]);
    }

    // find the student with the highest GPA
    struct student * highestGPA = findHighestGPA(students, 3);

    // print the student with the highest GPA
    printf("The student with the highest GPA is:\n");
    printStudent(*highestGPA);

    return 0;
}