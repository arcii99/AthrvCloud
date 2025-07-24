//FormAI DATASET v1.0 Category: Database Indexing System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int id;
    char name[50];
};

// Compare function for qsort
int cmp(const void *a, const void *b) {
    return (*(struct student*)a).id - (*(struct student*)b).id;
}

int main() {
    int num_students;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);
    struct student *students = (struct student*)malloc(num_students * sizeof(struct student));
    if (students == NULL) {
        printf("Memory allocation error!\n");
        return 1;
    }
    // Input data
    for (int i = 0; i < num_students; i++) {
        printf("Enter the ID and name of student %d: ", i+1);
        scanf("%d %s", &students[i].id, students[i].name);
    }
    // Sort the array using qsort function
    qsort(students, num_students, sizeof(struct student), cmp);
    // Output data
    for (int i = 0; i < num_students; i++) {
        printf("Student %d: ID=%d, name=%s\n", i+1, students[i].id, students[i].name);
    }
    // Free allocated memory
    free(students);
    return 0;
}