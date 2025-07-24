//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct resume {
    char name[50];
    char email[50];
    char phone[20];
    char skills[200];
    char education[100];
    char experience[300];
} r;

void parseResume(struct resume r);

int main() {
    printf("Enter your name: ");
    fgets(r.name, sizeof(r.name), stdin);
    r.name[strcspn(r.name, "\n")] = 0;

    printf("Enter your email: ");
    fgets(r.email, sizeof(r.email), stdin);
    r.email[strcspn(r.email, "\n")] = 0;

    printf("Enter your phone number: ");
    fgets(r.phone, sizeof(r.phone), stdin);
    r.phone[strcspn(r.phone, "\n")] = 0;

    printf("Enter your skills: ");
    fgets(r.skills, sizeof(r.skills), stdin);
    r.skills[strcspn(r.skills, "\n")] = 0;

    printf("Enter your education: ");
    fgets(r.education, sizeof(r.education), stdin);
    r.education[strcspn(r.education, "\n")] = 0;

    printf("Enter your experience: ");
    fgets(r.experience, sizeof(r.experience), stdin);
    r.experience[strcspn(r.experience, "\n")] = 0;

    printf("\nThank you. Your resume has been successfully parsed:\n\n");

    parseResume(r);

    return 0;
}

void parseResume(struct resume r) {
    printf("Name: %s\n", r.name);
    printf("Email: %s\n", r.email);
    printf("Phone: %s\n", r.phone);
    printf("Skills: %s\n", r.skills);
    printf("Education: %s\n", r.education);
    printf("Experience: %s\n", r.experience);
}