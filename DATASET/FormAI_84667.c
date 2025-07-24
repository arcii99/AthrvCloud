//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Resume {
    char name[30];
    char email[50];
    char phone[20];
    char education[100];
    char skills[200];
    char experience[500];
};

int main() {
    struct Resume resume;
    char parse_option;

    printf("\n\n***** C Resume Parsing System *****\n");
    printf("Enter your name: ");
    fgets(resume.name, sizeof(resume.name), stdin);
    printf("Enter your email: ");
    fgets(resume.email, sizeof(resume.email), stdin);
    printf("Enter your phone number: ");
    fgets(resume.phone, sizeof(resume.phone), stdin);
    printf("Enter your education details: ");
    fgets(resume.education, sizeof(resume.education), stdin);
    printf("Enter your skills: ");
    fgets(resume.skills, sizeof(resume.skills), stdin);
    printf("Enter your experience details: ");
    fgets(resume.experience, sizeof(resume.experience), stdin);

    printf("\n\nParsed Results:\n");

    printf("Name: %s", resume.name);
    printf("Email: %s", resume.email);
    printf("Phone: %s", resume.phone);
    printf("Education Details: %s", resume.education);
    printf("Skills: %s", resume.skills);
    printf("Experience Details: %s", resume.experience);

    return 0;
}