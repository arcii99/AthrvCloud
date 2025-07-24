//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct resume{
    char name[50];
    char email[50];
    char phone[20];
    char summary[100];
    char education[100];
    char experience[100];
};

int main()
{
    struct resume applicant;

    // Prompt user for input and store in respective fields
    printf("Welcome to the Resume Parsing System\n");
    printf("Please enter your name:");
    fgets(applicant.name, 50, stdin);
    applicant.name[strcspn(applicant.name, "\n")] = '\0';

    printf("Please enter your email:");
    fgets(applicant.email, 50, stdin);
    applicant.email[strcspn(applicant.email, "\n")] = '\0';

    printf("Please enter your phone number:");
    fgets(applicant.phone, 20, stdin);
    applicant.phone[strcspn(applicant.phone, "\n")] = '\0';

    printf("Please enter your summary:");
    fgets(applicant.summary, 100, stdin);
    applicant.summary[strcspn(applicant.summary, "\n")] = '\0';

    printf("Please enter your education:");
    fgets(applicant.education, 100, stdin);
    applicant.education[strcspn(applicant.education, "\n")] = '\0';

    printf("Please enter your experience:");
    fgets(applicant.experience, 100, stdin);
    applicant.experience[strcspn(applicant.experience, "\n")] = '\0';

    // Print out parsed results
    printf("\nParsed Results:\n");
    printf("Name: %s\n", applicant.name);
    printf("Email: %s\n", applicant.email);
    printf("Phone Number: %s\n", applicant.phone);
    printf("Summary: %s\n", applicant.summary);
    printf("Education: %s\n", applicant.education);
    printf("Experience: %s\n", applicant.experience);

    return 0;
}