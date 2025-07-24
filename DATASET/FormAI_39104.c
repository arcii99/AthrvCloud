//FormAI DATASET v1.0 Category: Educational ; Style: relaxed
#include <stdio.h>

struct student {
    int id;
    char name[50];
    float grade;
};

int main() {
    struct student students[3];

    // Add details of students
    for(int i=0; i<3; i++) {
        printf("Enter details of student %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &students[i].id); // Get student ID
        printf("Name: ");
        scanf("%s", students[i].name); // Get student name
        printf("Grade: ");
        scanf("%f", &students[i].grade); // Get student grade
    }

    // Display details of all students
    printf("\n\nStudent Details:\n");
    for(int i=0; i<3; i++) {
        printf("Student %d\n", i+1);
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Grade: %.2f\n", students[i].grade);
    }

    return 0;
}