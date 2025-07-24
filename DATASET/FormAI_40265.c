//FormAI DATASET v1.0 Category: Educational ; Style: interoperable
#include <stdio.h>

// declare a struct to hold student information
struct student {
    int id;
    char name[50];
    float gpa;
};

int main() {
    // declare an array of student structs
    struct student students[4];

    // initialize the student structs
    students[0].id = 1001;
    strcpy(students[0].name, "John Smith");
    students[0].gpa = 3.7;

    students[1].id = 1002;
    strcpy(students[1].name, "Jane Doe");
    students[1].gpa = 3.9;

    students[2].id = 1003;
    strcpy(students[2].name, "Bob Johnson");
    students[2].gpa = 3.5;

    students[3].id = 1004;
    strcpy(students[3].name, "Samantha Lee");
    students[3].gpa = 4.0;

    // print out the student information
    printf("Student Information:\n");
    for (int i = 0; i < 4; i++) {
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("GPA: %.2f\n\n", students[i].gpa);
    }

    // sort the students by GPA using insertion sort algorithm
    for (int i = 1; i < 4; i++) {
        struct student temp = students[i];
        int j = i - 1;
        while (j >= 0 && students[j].gpa < temp.gpa) {
            students[j+1] = students[j];
            j--;
        }
        students[j+1] = temp;
    }

    // print out the student information after sorting
    printf("Student Information Sorted by GPA:\n");
    for (int i = 0; i < 4; i++) {
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("GPA: %.2f\n\n", students[i].gpa);
    }

    return 0;
}