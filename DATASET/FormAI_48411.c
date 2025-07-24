//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_SKILLS_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char skills[MAX_SKILLS_LENGTH];
} Resume;

int main() {
    Resume myResume;
    char input[1000];
    char* token;

    printf("Please enter your resume information:\n");
    printf("Name: ");
    fgets(input, 1000, stdin);
    sscanf(input, "%s", myResume.name);

    printf("Address: ");
    fgets(input, 1000, stdin);
    sscanf(input, "%s", myResume.address);

    printf("Skills: ");
    fgets(input, 1000, stdin);
    sscanf(input, "%s", myResume.skills);

    printf("\nYour resume information:\n");
    printf("Name: %s\n", myResume.name);
    printf("Address: %s\n", myResume.address);
    printf("Skills: %s\n", myResume.skills);

    token = strtok(myResume.skills, ",");
    while (token != NULL) {
        printf("Skill: %s\n", token);
        token = strtok(NULL, ",");
    }

    return 0;
}