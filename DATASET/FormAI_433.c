//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    char* degree;
    char* university;
} Education;

typedef struct {
    char* company;
    char* position;
    char* duration;
    char* description;
} WorkExperience;

typedef struct {
    char* name;
    char* email;
    char* phone;
    Education* education;
    WorkExperience* workExp;
} Resume;

void parseEducation(char* text, Education* education) {
    char* token;
    token = strtok(text, "\n");
    education->name = strdup(token);
    token = strtok(NULL, "\n");
    education->degree = strdup(token);
    token = strtok(NULL, "\n");
    education->university = strdup(token);
}

void parseWorkExp(char* text, WorkExperience* workExp) {
    char* token;
    token = strtok(text, "\n");
    workExp->company = strdup(token);
    token = strtok(NULL, "\n");
    workExp->position = strdup(token);
    token = strtok(NULL, "\n");
    workExp->duration = strdup(token);
    token = strtok(NULL, "\n");
    workExp->description = strdup(token);
}

void parseResume(char* filename, Resume* resume) {
    FILE* file;
    char line[256];

    file = fopen(filename, "r");
    if (file) {
        while (fgets(line, sizeof(line), file)) {
            if (strcmp(line, "EDUCATION\n") == 0) {
                Education* education = malloc(sizeof(Education));
                fgets(line, sizeof(line), file);
                parseEducation(line, education);
                resume->education = education;
            } else if (strcmp(line, "WORK EXPERIENCE\n") == 0) {
                WorkExperience* workExp = malloc(sizeof(WorkExperience));
                fgets(line, sizeof(line), file);
                parseWorkExp(line, workExp);
                resume->workExp = workExp;
            } else if (strcmp(line, "NAME\n") == 0) {
                fgets(line, sizeof(line), file);
                resume->name = strdup(line);
            } else if (strcmp(line, "EMAIL\n") == 0) {
                fgets(line, sizeof(line), file);
                resume->email = strdup(line);
            } else if (strcmp(line, "PHONE\n") == 0) {
                fgets(line, sizeof(line), file);
                resume->phone = strdup(line);
            }
        }
        fclose(file);
    } else {
        printf("Error opening file %s\n", filename);
    }
}

int main() {
    Resume* resume = malloc(sizeof(Resume));
    parseResume("resume.txt", resume);
    
    printf("Resume\n");
    printf("------\n");
    printf("Name: %s", resume->name);
    printf("Email: %s", resume->email);
    printf("Phone: %s", resume->phone);
    printf("\n");
    
    printf("Education\n");
    printf("---------\n");
    printf("Name: %s", resume->education->name);
    printf("Degree: %s", resume->education->degree);
    printf("University: %s", resume->education->university);
    printf("\n");
    
    printf("Work Experience\n");
    printf("----------------\n");
    printf("Company: %s", resume->workExp->company);
    printf("Position: %s", resume->workExp->position);
    printf("Duration: %s", resume->workExp->duration);
    printf("Description: %s", resume->workExp->description);
    
    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->education->name);
    free(resume->education->degree);
    free(resume->education->university);
    free(resume->education);
    free(resume->workExp->company);
    free(resume->workExp->position);
    free(resume->workExp->duration);
    free(resume->workExp->description);
    free(resume->workExp);
    free(resume);
    
    return 0;
}