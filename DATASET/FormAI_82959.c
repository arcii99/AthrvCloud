//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    char experience[100];
} Applicant;

void parseResume(Applicant *applicant, char *resume) {
    char *nameStart = strstr(resume, "Name:") + 6;
    char *nameEnd = strstr(nameStart, "\n");
    strncpy(applicant->name, nameStart, nameEnd - nameStart);
    applicant->name[nameEnd - nameStart] = '\0';

    char *ageStart = strstr(resume, "Age:") + 5;
    char *ageEnd = strstr(ageStart, "\n");
    char ageStr[10];
    strncpy(ageStr, ageStart, ageEnd - ageStart);
    ageStr[ageEnd - ageStart] = '\0';
    applicant->age = atoi(ageStr);

    char *experienceStart = strstr(resume, "Experience:") + 11;
    char *experienceEnd = strstr(experienceStart, "\n");
    strncpy(applicant->experience, experienceStart, experienceEnd - experienceStart);
    applicant->experience[experienceEnd - experienceStart] = '\0';
}

int main() {
    char *resume = "Name: John Doe\nAge: 30\nExperience: 3 years as a software engineer\n";
    Applicant applicant;
    parseResume(&applicant, resume);
    printf("Name: %s\n", applicant.name);
    printf("Age: %d\n", applicant.age);
    printf("Experience: %s\n", applicant.experience);
    return 0;
}