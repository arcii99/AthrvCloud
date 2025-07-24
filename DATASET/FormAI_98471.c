//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EXPERIENCE_LENGTH 100
#define MAX_EDUCATION_LENGTH 100
#define MAX_SKILL_LENGTH 100

struct Resume {
    char name[MAX_NAME_LENGTH];
    char experience[MAX_EXPERIENCE_LENGTH];
    char education[MAX_EDUCATION_LENGTH];
    char skill[MAX_SKILL_LENGTH];
};

int main() {
    struct Resume my_resume;
    char* parsing_system = "CRPS";

    printf("Input your name: ");
    fgets(my_resume.name, MAX_NAME_LENGTH, stdin);
    strtok(my_resume.name, "\n");

    printf("Input your experience: ");
    fgets(my_resume.experience, MAX_EXPERIENCE_LENGTH, stdin);
    strtok(my_resume.experience, "\n");

    printf("Input your education: ");
    fgets(my_resume.education, MAX_EDUCATION_LENGTH, stdin);
    strtok(my_resume.education, "\n");

    printf("Input your skill: ");
    fgets(my_resume.skill, MAX_SKILL_LENGTH, stdin);
    strtok(my_resume.skill, "\n");

    printf("\nCRPS: ");
    if (strlen(my_resume.name) > 0 && strlen(my_resume.experience) > 0 && strlen(my_resume.education) > 0 && strlen(my_resume.skill) > 0) {
        printf("Resume parsing successful.\n\n");
        printf("Name: %s\n", my_resume.name);
        printf("Experience: %s\n", my_resume.experience);
        printf("Education: %s\n", my_resume.education);
        printf("Skill: %s\n", my_resume.skill);
    }
    else {
        printf("Error: Incomplete resume.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}