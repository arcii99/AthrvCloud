//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int experience;
    char skills[MAX_SIZE];
    float salary;
} Resume;

void displayResume(Resume r) {
    printf("Name: %s\n", r.name);
    printf("Experience: %d years\n", r.experience);
    printf("Skills: %s\n", r.skills);
    printf("Salary: $%.2f\n", r.salary);
}

int parseResume(char* file_path) {
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    Resume r;

    fp = fopen(file_path, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        if (strncmp(line, "Name:", 5) == 0) {
            strtok(line, ":");
            strcpy(r.name, strtok(NULL, "\n"));
        }
        else if (strncmp(line, "Experience:", 10) == 0) {
            strtok(line, ":");
            r.experience = atoi(strtok(NULL, "\n"));
        }
        else if (strncmp(line, "Skills:", 7) == 0) {
            strtok(line, ":");
            strcpy(r.skills, strtok(NULL, "\n"));
        }
        else if (strncmp(line, "Salary:", 7) == 0) {
            strtok(line, ":");
            r.salary = atof(strtok(NULL, "\n"));
        }
    }

    fclose(fp);
    if (line) free(line);

    displayResume(r);

    return 0;
}

int main() {
    char* file_path = "resume.txt";
    parseResume(file_path);

    return 0;
}