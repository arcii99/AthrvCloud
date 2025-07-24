//FormAI DATASET v1.0 Category: Data mining ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Define a structure for the data to be mined
struct student {
    int id;
    char name[20];
    int age;
    float gpa;
};

int main() {
    const int NUM_STUDENTS = 5;
    struct student students[NUM_STUDENTS];

    // Fill in some example data for demonstration purposes
    students[0].id = 10001;
    strcpy(students[0].name, "John");
    students[0].age = 20;
    students[0].gpa = 3.4;

    students[1].id = 10002;
    strcpy(students[1].name, "Alice");
    students[1].age = 22;
    students[1].gpa = 3.8;

    students[2].id = 10003;
    strcpy(students[2].name, "Bob");
    students[2].age = 21;
    students[2].gpa = 3.2;

    students[3].id = 10004;
    strcpy(students[3].name, "Jane");
    students[3].age = 19;
    students[3].gpa = 3.9;

    students[4].id = 10005;
    strcpy(students[4].name, "Sam");
    students[4].age = 20;
    students[4].gpa = 3.5;

    // Perform data mining to find the highest GPA and the student with that GPA
    float highest_gpa = 0;
    struct student *top_student = NULL;

    for (int i = 0; i < NUM_STUDENTS; i++) {
        if (students[i].gpa > highest_gpa) {
            highest_gpa = students[i].gpa;
            top_student = &students[i];
        }
    }

    // Print the results
    printf("The highest GPA is %.2f\n", highest_gpa);
    printf("The student with the highest GPA is %s (ID: %d)\n", top_student->name, top_student->id);

    return 0;
}