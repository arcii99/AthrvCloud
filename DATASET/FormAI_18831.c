//FormAI DATASET v1.0 Category: Sorting ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    double score;
} Student;

int compareScore(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;
    
    if (studentA->score < studentB->score) {
        return -1;
    } else if (studentA->score > studentB->score) {
        return 1;
    } else {
        return 0;
    }
}

int compareName(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;
    
    return strcmp(studentA->name, studentB->name);
}

int main() {
    Student class[] = {
        {1, "Alice", 75.0},
        {2, "Bob", 82.0},
        {3, "Charlie", 68.5},
        {4, "David", 91.5},
        {5, "Emily", 86.0}
    };
    
    int classSize = sizeof(class) / sizeof(Student);
    
    // Sort by score
    qsort(class, classSize, sizeof(Student), compareScore);
    printf("Sort by score:\n");
    for (int i = 0; i < classSize; ++i) {
        printf("Student %d: %s - %.1lf\n", class[i].id, class[i].name, class[i].score);
    }
    printf("\n");
    
    // Sort by name
    qsort(class, classSize, sizeof(Student), compareName);
    printf("Sort by name:\n");
    for (int i = 0; i < classSize; ++i) {
        printf("Student %d: %s - %.1lf\n", class[i].id, class[i].name, class[i].score);
    }
    printf("\n");
    
    return 0;
}