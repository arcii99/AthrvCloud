//FormAI DATASET v1.0 Category: File handling ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[50];
    int age;
    float gpa;
};

void writeToFile() {
    FILE *file;
    file = fopen("students.dat", "wb");

    if (file == NULL) {
        printf("Error creating file");
        exit(1);
    }

    struct student s1 = {"John Doe", 18, 3.5};
    struct student s2 = {"Jane Smith", 20, 3.8};

    fwrite(&s1, sizeof(struct student), 1, file);
    fwrite(&s2, sizeof(struct student), 1, file);

    fclose(file);
}

void readFromFile() {
    FILE *file;
    file = fopen("students.dat", "rb");

    if (file == NULL) {
        printf("Error opening file");
        exit(1);
    }

    struct student s1, s2;

    fread(&s1, sizeof(struct student), 1, file);
    fread(&s2, sizeof(struct student), 1, file);

    printf("Student 1:\n%s\n%d\n%.1f\n\n", s1.name, s1.age, s1.gpa);
    printf("Student 2:\n%s\n%d\n%.1f\n\n", s2.name, s2.age, s2.gpa);

    fclose(file);
}

int main() {
    writeToFile();
    readFromFile();
    return 0;
}