//FormAI DATASET v1.0 Category: Educational ; Style: scalable
#include <stdio.h>

struct Student {
    char name[50];
    int id;
    float gpa;
};

void print_student(struct Student student) {
    printf("Name: %s\n", student.name);
    printf("ID: %d\n", student.id);
    printf("GPA: %.2f\n", student.gpa);
}

int main() {
    int n;
    printf("How many students do you want to add? ");
    scanf("%d", &n);

    struct Student students[n];

    for (int i = 0; i < n; i++) {
        printf("Enter name for student %d: ", i+1);
        scanf("%s", students[i].name);

        printf("Enter ID for student %d: ", i+1);
        scanf("%d", &students[i].id);

        printf("Enter GPA for student %d: ", i+1);
        scanf("%f", &students[i].gpa);

        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        print_student(students[i]);
        printf("------------\n");
    }

    return 0;
}