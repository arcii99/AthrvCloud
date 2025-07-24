//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Resume {
    char name[20];
    char email[50];
    char phone[15];
    char skills[200];
    char education[50];
    char experience[200];
};

int main() {
    struct Resume person;
    char resume[500];

    printf("Welcome to the C Resume Parsing System!\n\n");
    printf("Please enter your resume:\n");
    fgets(resume, 500, stdin); // read in resume

    char* token = strtok(resume, "\n"); // first line is name
    strcpy(person.name, token);

    token = strtok(NULL, "\n"); // second line is email
    strcpy(person.email, token);

    token = strtok(NULL, "\n"); // third line is phone number
    strcpy(person.phone, token);

    token = strtok(NULL, "\n"); // fourth line is skills
    strcpy(person.skills, token);

    token = strtok(NULL, "\n"); // fifth line is education
    strcpy(person.education, token);

    token = strtok(NULL, "\n"); // sixth line is experience
    strcpy(person.experience, token);

    printf("\nResume parsed successfully! Here is the information we gathered:\n");
    printf("Name: %s\nEmail: %s\nPhone: %s\nSkills: %s\nEducation: %s\nExperience: %s\n", 
            person.name, person.email, person.phone, 
            person.skills, person.education, person.experience);

    return 0;
}