//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct resume {
    char name[50];
    int age;
    char education[100];
    char skills[100];
};

typedef struct resume Resume;

void printResume(Resume *r) {
    printf("Name: %s\n", r->name);
    printf("Age: %d\n", r->age);
    printf("Education: %s\n", r->education);
    printf("Skills: %s\n", r->skills);
}

int main() {
    char resumeData[] = "Name: John Doe\nAge: 25\nEducation: B.E. in Computer Science\nSkills: C, Java, Python";
    Resume *resume = (Resume*) malloc(sizeof(Resume));
    char *token;

    token = strtok(resumeData, "\n");
    while(token != NULL) {
        if(strncmp(token, "Name:", 5) == 0) {
            strcpy(resume->name, token + 6);
        }
        else if(strncmp(token, "Age:", 4) == 0) {
            resume->age = atoi(token + 5);
        }
        else if(strncmp(token, "Education:", 10) == 0) {
            strcpy(resume->education, token + 11);
        }
        else if(strncmp(token, "Skills:", 7) == 0) {
            strcpy(resume->skills, token + 8);
        }

        token = strtok(NULL, "\n");
    }

    printResume(resume);

    free(resume);
    return 0;
}