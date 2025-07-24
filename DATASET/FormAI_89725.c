//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_FIELD_LENGTH 20

typedef struct {
    char name[MAX_FIELD_LENGTH];
    int age;
    char email[MAX_FIELD_LENGTH];
} Resume;

void parseLine(char* line, Resume* resume) {
    char* token;
    int i = 0;
    while ((token = strsep(&line, ",")) != NULL) {
        switch(i) {
            case 0:
                strcpy(resume->name, token);
                break;
            case 1:
                resume->age = atoi(token);
                break;
            case 2:
                strcpy(resume->email, token);
                break;
        }
        i++;
    }
}

int main() {
    FILE* file = fopen("resumes.txt", "r");
    if (file == NULL) {
        perror("Error opening file.");
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    Resume resume;
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        parseLine(line, &resume);
        printf("Name: %s\nAge: %d\nEmail: %s\n", resume.name, resume.age, resume.email);
    }

    fclose(file);
    return 0;
}