//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *name;
    int age;
    double score;
} Student;

int main() {
    FILE *csv_file;
    char line[MAX_LINE_SIZE];
    char *token;
    Student students[100]; // Assuming there are no more than 100 students in the csv file
    int num_students = 0;

    csv_file = fopen("students.csv", "r");
    if (csv_file == NULL) {
        printf("Cannot open file students.csv\n");
        exit(1);
    }

    // Read each line in the csv file and split it into tokens
    while (fgets(line, MAX_LINE_SIZE, csv_file) != NULL) {
        Student student;
        token = strtok(line, ",");
        student.name = strdup(token);
        token = strtok(NULL, ",");
        student.age = atoi(token);
        token = strtok(NULL, ",");
        student.score = atof(token);

        students[num_students++] = student;
    }

    // Print out the students in the order they were read in
    for (int i = 0; i < num_students; i++) {
        printf("Name: %s\tAge: %d\tScore: %.2f\n", students[i].name,
               students[i].age, students[i].score);
    }

    fclose(csv_file);
    return 0;
}