//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: random
#include <stdio.h>
#include <stdlib.h>

/* Define maximum limits */
#define MAX_NAME_LENGTH 50
#define MAX_EXPERIENCE_LENGTH 100
#define MAX_EDUCATION_LENGTH 50
#define MAX_SKILL_LENGTH 50

/* Types to hold parsed information */
typedef struct {
    char name[MAX_NAME_LENGTH];
    char experience[MAX_EXPERIENCE_LENGTH];
    char education[MAX_EDUCATION_LENGTH];
    char skills[MAX_SKILL_LENGTH];
} Resume;

/* Function to parse a resume */
void parseResume(char *input, Resume *resume) {
    int i = 0, j = 0;

    /* Parse name */
    while (input[i] != '\n') {
        resume->name[j] = input[i];
        i++;
        j++;
    }
    resume->name[j] = '\0';

    /* Parse experience */
    while (input[i] != '\n') {
        i++;
    }
    i++;
    j = 0;
    while (input[i] != '\n') {
        resume->experience[j] = input[i];
        i++;
        j++;
    }
    resume->experience[j] = '\0';

    /* Parse education */
    while (input[i] != '\n') {
        i++;
    }
    i++;
    j = 0;
    while (input[i] != '\n') {
        resume->education[j] = input[i];
        i++;
        j++;
    }
    resume->education[j] = '\0';

    /* Parse skills */
    while (input[i] != '\n') {
        i++;
    }
    i++;
    j = 0;
    while (input[i] != '\0') {
        resume->skills[j] = input[i];
        i++;
        j++;
    }
    resume->skills[j] = '\0';
}

int main() {
    /* Example input */
    char input[] = "John Doe\nSoftware developer with 5 years of experience\nBachelor's degree in Computer Science\nC++, Java, Python, SQL\n";

    /* Parse input */
    Resume resume;
    parseResume(input, &resume);

    /* Print parsed information */
    printf("Name: %s\n", resume.name);
    printf("Experience: %s\n", resume.experience);
    printf("Education: %s\n", resume.education);
    printf("Skills: %s\n", resume.skills);

    return 0;
}