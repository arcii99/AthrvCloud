//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    char skills[200];
    char experience[1000];
};

int main() {
    struct Resume R1;
    printf("Welcome to the C Resume Parsing System!\n");
    printf("Please enter the name of the candidate: ");
    fgets(R1.name, 50, stdin);
    printf("Please enter the email address of the candidate: ");
    fgets(R1.email, 50, stdin);
    printf("Please enter the phone number of the candidate: ");
    fgets(R1.phone, 20, stdin);
    printf("Please enter the skills of the candidate: ");
    fgets(R1.skills, 200, stdin);
    printf("Please enter the experience of the candidate: ");
    fgets(R1.experience, 1000, stdin);

    printf("\n---------------------------------------\n\n");

    printf("Parsing Resume...\n\n");

    char *ptr;
    char *token = strtok_r(R1.skills, ",\n", &ptr);
    while (token != NULL) {
        printf("Skill: %s\n", token);
        token = strtok_r(NULL, ",\n", &ptr);
    }

    printf("\n---------------------------------------\n\n");

    printf("Experience:\n%s\n", R1.experience);
    printf("\n---------------------------------------\n\n");

    printf("Thank you for using the C Resume Parsing System!\n");

    return 0;
}