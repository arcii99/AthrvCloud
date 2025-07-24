//FormAI DATASET v1.0 Category: Database querying ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Student {
    char name[25];
    int id;
    float gpa;
};

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    for(int i=0; i<n; i++) {
        printf("Enter details of student %d:\n", i+1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("ID: ");
        scanf("%d", &students[i].id);
        printf("GPA: ");
        scanf("%f", &students[i].gpa);
    }

    printf("\nEnter the minimum GPA to search for: ");
    float min_gpa;
    scanf("%f", &min_gpa);

    printf("\nStudents with a GPA of at least %.2f:\n", min_gpa);
    for(int i=0; i<n; i++) {
        if(students[i].gpa >= min_gpa) {
            printf("%-25s %8d %8.2f\n", students[i].name, students[i].id, students[i].gpa);
        }
    }

    return 0;
}