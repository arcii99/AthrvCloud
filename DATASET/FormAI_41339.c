//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    int id;
    char name[MAX_LINE_LENGTH];
    float score;
} Student;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s csv_file\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    int num_students = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        num_students++;
    }

    Student *students = malloc(num_students * sizeof(Student));
    if (students == NULL) {
        printf("Error: could not allocate memory for students\n");
        return 1;
    }

    rewind(file);

    int count = 0;
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        char *token = strtok(line, ",");
        students[count].id = atoi(token);

        token = strtok(NULL, ",");
        strcpy(students[count].name, token);

        token = strtok(NULL, ",");
        students[count].score = atof(token);

        count++;
    }

    fclose(file);

    printf("ID\tName\tScore\n");
    for (int i = 0; i < num_students; i++) {
        printf("%d\t%s\t%.2f\n", students[i].id, students[i].name, students[i].score);
    }

    free(students);

    return 0;
}