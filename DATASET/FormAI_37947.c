//FormAI DATASET v1.0 Category: Database simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 128

struct Student {
    int id;
    char name[MAX_SIZE];
    float gpa;
};

int main() {
    int num_of_students = 0;
    struct Student *students = NULL;

    printf("Enter the number of students: ");
    scanf("%d", &num_of_students);

    students = (struct Student *)malloc(num_of_students * sizeof(struct Student));

    if (students == NULL) {
        printf("Out of memory!\n");
        return 1;
    }

    for (int i = 0; i < num_of_students; i++) {
        printf("Enter the details for student %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &students[i].id);
        fflush(stdin);
        printf("Name: ");
        fgets(students[i].name, MAX_SIZE, stdin);
        printf("GPA: ");
        scanf("%f", &students[i].gpa);
    }

    printf("The list of students:\n");

    for (int i = 0; i < num_of_students; i++) {
        printf("Student %d:\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Name: %s", students[i].name);
        printf("GPA: %f\n", students[i].gpa);
    }

    free(students);

    return 0;
}