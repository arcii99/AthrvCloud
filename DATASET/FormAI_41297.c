//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int experience;
    char* skills[10];
    int skillCount;
} Applicant;

typedef struct {
    char* keyword;
    int skillLevel;
} Keyword;

Keyword keywords[5] = {
    {"c#", 2},
    {"java", 3},
    {"python", 2},
    {"teamwork", 4},
    {"communication", 5}
};

int main() {
    char resume[2000];
    printf("Paste your resume here:\n");
    fgets(resume, sizeof(resume), stdin);
    Applicant applicant;
    applicant.skillCount = 0;
    char* token = strtok(resume, " ,\n");
    while (token != NULL) {
        if (strcmp(token, "Name:") == 0) {
            token = strtok(NULL, " ,\n");
            applicant.name = token;
        } else if (strcmp(token, "Experience:") == 0) {
            token = strtok(NULL, " ,\n");
            applicant.experience = atoi(token);
        } else if (strcmp(token, "Skills:") == 0) {
            token = strtok(NULL, " ,\n");
            while (token != NULL) {
                applicant.skills[applicant.skillCount] = token;
                applicant.skillCount++;
                token = strtok(NULL, " ,\n");
            }
        }
        token = strtok(NULL, " ,\n");
    }

    int totalSkillLevel = 0;
    for (int i = 0; i < applicant.skillCount; i++) {
        char* skill = applicant.skills[i];
        for (int j = 0; j < 5; j++) {
            Keyword keyword = keywords[j];
            if (strcmp(skill, keyword.keyword) == 0) {
                totalSkillLevel += keyword.skillLevel;
            }
        }
    }

    printf("Applicant Name: %s\n", applicant.name);
    printf("Experience: %d years\n", applicant.experience);
    printf("Skills:\n");
    for (int i = 0; i < applicant.skillCount; i++) {
        printf("- %s\n", applicant.skills[i]);
    }
    printf("Total Skill Level: %d\n", totalSkillLevel);

    return 0;
}