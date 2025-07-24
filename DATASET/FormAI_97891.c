//FormAI DATASET v1.0 Category: Data recovery tool ; Style: calm
#include <stdio.h>

typedef struct {
    int id;
    char name[20];
    float score;
} Student;

void main() {
    FILE *fp;
    Student s[5];

    fp = fopen("students.dat", "rb");
    if (fp == NULL) {
        printf("ERROR: Failed to open file.\n");
        return;
    }

    fseek(fp, 0L, SEEK_END);
    int fileSize = ftell(fp);
    rewind(fp);
    int numStudents = fileSize / sizeof(Student);
    printf("There are %d students in the file.\n", numStudents);

    printf("\n----- RECOVERED DATA -----\n");
    for (int i = 0; i < numStudents; i++) {
        int bytesRead = fread(&s[i], sizeof(Student), 1, fp);
        if (bytesRead != 1) {
            printf("\nERROR: Failed to read student data.\n");
            break;
        }
        printf("Student %d: ID = %d | Name = %s | Score = %.2f\n", i+1, s[i].id, s[i].name, s[i].score);
    }
    fclose(fp);
}