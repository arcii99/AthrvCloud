//FormAI DATASET v1.0 Category: Data mining ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define DATA_SIZE 10

struct Student {
    char name[20];
    int age;
    float gpa;
};

int main() {
    struct Student students[DATA_SIZE] = {
        {"Alice", 18, 3.5},
        {"Bob", 20, 3.2},
        {"Charlie", 19, 3.6},
        {"David", 21, 3.8},
        {"Emma", 18, 4.0},
        {"Frank", 22, 3.4},
        {"Grace", 19, 3.7},
        {"Harry", 20, 3.1},
        {"Ivy", 18, 3.9},
        {"John", 21, 3.5}
    };

    printf("Original data:\n");
    for(int i=0; i < DATA_SIZE; i++) {
        printf("%s, %d, %.1f\n", students[i].name, students[i].age, students[i].gpa);
    }

    //Data mining operation
    float average_gpa = 0.0;
    for(int i=0; i < DATA_SIZE; i++) {
        average_gpa += students[i].gpa;
    }
    average_gpa /= DATA_SIZE;

    printf("\nStudents above average GPA:\n");
    for(int i=0; i < DATA_SIZE; i++) {
        if(students[i].gpa > average_gpa) {
            printf("%s, %d, %.1f\n", students[i].name, students[i].age, students[i].gpa);
        }
    }

    return 0;
}