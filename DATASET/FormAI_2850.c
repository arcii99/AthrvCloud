//FormAI DATASET v1.0 Category: Data mining ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to store information about a student
struct Student {
    char name[20];
    int age;
    float gpa;
};

int main() {

    // Create an array of student structs with 3 elements
    struct Student students[3];

    // Prompt the user to enter data for each student
    for (int i = 0; i < 3; i++) {
        printf("Enter data for Student %d\n", i+1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("GPA: ");
        scanf("%f", &students[i].gpa);
    }

    // Find the student with the highest GPA
    float max_gpa = 0.0;
    int max_gpa_index = -1;
    for (int i = 0; i < 3; i++) {
        if (students[i].gpa > max_gpa) {
            max_gpa = students[i].gpa;
            max_gpa_index = i;
        }
    }

    // Print the data for the student with the highest GPA
    printf("\nStudent with the highest GPA:\n");
    printf("Name: %s\n", students[max_gpa_index].name);
    printf("Age: %d\n", students[max_gpa_index].age);
    printf("GPA: %f\n", students[max_gpa_index].gpa);

    return 0;
}