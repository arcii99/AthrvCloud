//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_COMPANY_LENGTH 100
#define MAX_SKILL_LENGTH 100

typedef struct resume {
    char name[MAX_NAME_LENGTH];
    char company[MAX_COMPANY_LENGTH];
    char skill[MAX_SKILL_LENGTH];
} Resume;

void parseResume(FILE *file, Resume *resume) {
    char line[1024];
    fgets(line, 1024, file);
    sscanf(line, "Name: %s\n", resume->name);
    fgets(line, 1024, file);
    sscanf(line, "Company: %s\n", resume->company);
    fgets(line, 1024, file);
    sscanf(line, "Skills: %s\n", resume->skill);
}

void printResume(Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Company: %s\n", resume->company);
    printf("Skills: %s\n\n", resume->skill);
}

int main() {
    FILE *file = fopen("resumes.txt", "r");
    if (file == NULL) {
        printf("Failed to open resumes.txt\n");
        exit(1);
    }

    Resume resume;
    while (!feof(file)) {
        parseResume(file, &resume);
        printResume(&resume);
    }

    fclose(file);
    return 0;
}