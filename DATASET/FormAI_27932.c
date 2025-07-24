//FormAI DATASET v1.0 Category: Online Examination System ; Style: Alan Touring
#include <stdio.h>

// Define struct for student
struct Student {
    char name[50];
    int id;
    float grade;
};

// Define function for printing student's information
void printStudent(struct Student s) {
    printf("Name: %s\n", s.name);
    printf("ID: %d\n", s.id);
    printf("Grade: %.2f\n", s.grade);
}

int main() {
    // Define array of students
    struct Student students[3];

    // Prompt user to input student details
    printf("Enter details of 3 students:\n");
    for (int i = 0; i < 3; i++) {
        printf("\nStudent %d:\n", i+1);
        printf("Name: ");
        scanf("%s", &students[i].name);
        printf("ID: ");
        scanf("%d", &students[i].id);
        printf("Grade: ");
        scanf("%f", &students[i].grade);
    }

    // Print the details of the students
    printf("\nStudent Details:\n");
    for (int i = 0; i < 3; i++) {
        printStudent(students[i]);
    }

    return 0;
}