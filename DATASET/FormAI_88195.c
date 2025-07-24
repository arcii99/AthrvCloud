//FormAI DATASET v1.0 Category: Data mining ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[20];
    float score;
} Student;

int main() {
    Student students[5];
    int count = 0;
    float min_score;

    printf("Enter data for 5 students:\n");

    for (int i = 0; i < 5; i++) {
        printf("Student %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &students[i].id);
        while (getchar() != '\n');
        printf("Name: ");
        fgets(students[i].name, 20, stdin);
        printf("Score: ");
        scanf("%f", &students[i].score);
        while (getchar() != '\n');
        count++;
    }

    printf("\nEnter the minimum score to filter students: ");
    scanf("%f", &min_score);

    printf("\nStudents with score greater than or equal to %.2f:\n", min_score);

    for (int i = 0; i < count; i++) {
        if (students[i].score >= min_score) {
            printf("ID: %d\n", students[i].id);
            printf("Name: %s", students[i].name);
            printf("Score: %.2f\n", students[i].score);
        }
    }

    return 0;
}