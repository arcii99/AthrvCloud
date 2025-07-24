//FormAI DATASET v1.0 Category: Data mining ; Style: careful
#include <stdio.h>
#include <stdlib.h>

/* Define a structure to store information about a student */
struct Student {
    int student_id;
    char name[30];
    float gpa;
};

/* Define a function for sorting students based on their GPA values */
int compare_gpa(const void *a, const void *b) {
    struct Student *s1 = (struct Student *)a;
    struct Student *s2 = (struct Student *)b;
    if (s1->gpa < s2->gpa) {
        return 1;
    }
    else if (s1->gpa > s2->gpa) {
        return -1;
    }
    else {
        return 0;
    }
}

int main() {
    /* Generate some random student data */
    struct Student students[10];
    for (int i = 0; i < 10; i++) {
        students[i].student_id = i + 1;
        sprintf(students[i].name, "Student %d", i + 1);
        students[i].gpa = (float)rand() / RAND_MAX * 4.0f;
    }

    /* Print the unsorted student list */
    printf("Unsorted student list:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\t%s\t%f\n", students[i].student_id, students[i].name, students[i].gpa);
    }

    /* Sort the student list based on their GPA values */
    qsort(students, 10, sizeof(struct Student), compare_gpa);

    /* Print the sorted student list */
    printf("\n\nSorted student list:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\t%s\t%f\n", students[i].student_id, students[i].name, students[i].gpa);
    }

    return 0;
}