//FormAI DATASET v1.0 Category: Data mining ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

struct student {
    int id;
    char name[20];
    float gpa;
};

int main() {
    int num_students;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    struct student* students = (struct student*) malloc(num_students * sizeof(struct student));

    for (int i=0; i<num_students; i++) {
        printf("Enter the details of student %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &students[i].id);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("GPA: ");
        scanf("%f", &students[i].gpa);
    }

    printf("\nDetails of all students:\n");
    printf("ID\tName\tGPA\n");
    for (int i=0; i<num_students; i++) {
        printf("%d\t%s\t%.2f\n", students[i].id, students[i].name, students[i].gpa);
    }

    float min_gpa = students[0].gpa;
    int min_gpa_index = 0;
    for (int i=0; i<num_students; i++) {
        if (students[i].gpa < min_gpa) {
            min_gpa = students[i].gpa;
            min_gpa_index = i;
        }
    }

    printf("\nStudent with the lowest GPA:\n");
    printf("ID: %d\n", students[min_gpa_index].id);
    printf("Name: %s\n", students[min_gpa_index].name);
    printf("GPA: %.2f\n", students[min_gpa_index].gpa);

    free(students);
    return 0;
}