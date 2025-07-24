//FormAI DATASET v1.0 Category: Data mining ; Style: future-proof
#include <stdio.h>

#define MAX_RECORDS 1000

struct Student {
    char name[50];
    int id;
    float score;
};

int main() {
    FILE *fp;
    struct Student students[MAX_RECORDS];
    int num_students = 0;

    fp = fopen("students.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(fp, "%s %d %f", students[num_students].name, &students[num_students].id, &students[num_students].score) == 3) {
        num_students++;
    }

    fclose(fp);

    printf("Total number of records: %d\n", num_students);

    float avg_score = 0;
    int num_passing = 0;

    for (int i = 0; i < num_students; i++) {
        avg_score += students[i].score;
        if (students[i].score >= 60) {
            num_passing++;
        }
    }

    avg_score /= num_students;

    printf("Average score: %.2f\n", avg_score);
    printf("Number of passing students: %d\n", num_passing);

    return 0;
}