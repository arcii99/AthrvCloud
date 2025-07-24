//FormAI DATASET v1.0 Category: Data mining ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[50];
    int age;
    float gpa;
};

int main() {
    int num_students = 5;
    struct student* students = malloc(num_students * sizeof(struct student));

    strcpy(students[0].name, "John");
    students[0].age = 18;
    students[0].gpa = 3.8;

    strcpy(students[1].name, "Mary");
    students[1].age = 19;
    students[1].gpa = 3.2;

    strcpy(students[2].name, "Bob");
    students[2].age = 20;
    students[2].gpa = 2.5;

    strcpy(students[3].name, "Sarah");
    students[3].age = 21;
    students[3].gpa = 3.6;

    strcpy(students[4].name, "David");
    students[4].age = 22;
    students[4].gpa = 3.9;

    float avg_gpa = 0.0;
    for (int i = 0; i < num_students; i++) {
        printf("Name: %s, Age: %d, GPA: %.2f\n", students[i].name, students[i].age, students[i].gpa);
        avg_gpa += students[i].gpa;
    }

    avg_gpa /= num_students;
    printf("Average GPA: %.2f\n", avg_gpa);

    return 0;
}