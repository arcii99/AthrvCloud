//FormAI DATASET v1.0 Category: File handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    float gpa;
} Student;

int main() {
    FILE *fp;
    Student s1, s2;
    fp = fopen("students.dat", "wb");
    if (fp == NULL) {
        printf("Failed to open file.\n");
        exit(1);
    }

    // Writing to file
    s1.id = 1;
    strcpy(s1.name, "John");
    s1.age = 20;
    s1.gpa = 3.5;
    fwrite(&s1, sizeof(Student), 1, fp);

    s2.id = 2;
    strcpy(s2.name, "Jane");
    s2.age = 19;
    s2.gpa = 3.8;
    fwrite(&s2, sizeof(Student), 1, fp);

    printf("Wrote data to file successfully!\n");
    fclose(fp);

    // Reading from file
    fp = fopen("students.dat", "rb");
    if (fp == NULL) {
        printf("Failed to open file.\n");
        exit(1);
    }

    printf("Student Details:\n");
    while (fread(&s1, sizeof(Student), 1, fp) == 1) {
        printf("ID: %d, Name: %s, Age: %d, GPA: %.2f\n", s1.id, s1.name, s1.age, s1.gpa);
    }

    fclose(fp);

    return 0;
}