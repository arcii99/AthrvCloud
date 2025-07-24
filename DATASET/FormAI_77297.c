//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    char education[100];
    char work_experience[500];
};

int main() {
    printf("Welcome to the Resume Parsing System!\n\n");

    // Create a new resume
    struct Resume my_resume;

    // Prompt the user for input
    printf("Please enter your name: ");
    fgets(my_resume.name, 50, stdin);

    printf("Please enter your email: ");
    fgets(my_resume.email, 50, stdin);

    printf("Please enter your phone number: ");
    fgets(my_resume.phone, 20, stdin);

    printf("Please enter your education: ");
    fgets(my_resume.education, 100, stdin);

    printf("Please enter your work experience: ");
    fgets(my_resume.work_experience, 500, stdin);

    // Print out the parsed resume
    printf("\nParsed Resume:\n\n");
    printf("Name: %s", my_resume.name);
    printf("Email: %s", my_resume.email);
    printf("Phone: %s", my_resume.phone);
    printf("Education: %s", my_resume.education);
    printf("Work Experience: %s", my_resume.work_experience);

    return 0;
}