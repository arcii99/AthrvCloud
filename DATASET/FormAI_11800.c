//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: curious
// Welcome to the C Resume Parsing System!
// This code reads information from a resume and extracts relevant details
// Written by a curious programmer who loves to automate tedious tasks

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of each field in the resume
#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 50
#define MAX_EDU_LEN 100
#define MAX_SKILL_LEN 200

// Define the resume struct to hold all the relevant information
struct resume {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    char education[MAX_EDU_LEN];
    char skills[MAX_SKILL_LEN];
};

int main() {
    // Define the resume struct to store all the information
    struct resume r;

    // Ask the user to input the resume details
    printf("Please enter your name: ");
    fgets(r.name, MAX_NAME_LEN, stdin);
    printf("Please enter your email: ");
    fgets(r.email, MAX_EMAIL_LEN, stdin);
    printf("Please enter your education details: ");
    fgets(r.education, MAX_EDU_LEN, stdin);
    printf("Please enter your skills: ");
    fgets(r.skills, MAX_SKILL_LEN, stdin);

    // Remove any trailing newline characters from the fields
    r.name[strcspn(r.name, "\n")] = 0;
    r.email[strcspn(r.email, "\n")] = 0;
    r.education[strcspn(r.education, "\n")] = 0;
    r.skills[strcspn(r.skills, "\n")] = 0;

    // Print the extracted details from the resume
    printf("Name: %s\n", r.name);
    printf("Email: %s\n", r.email);
    printf("Education: %s\n", r.education);
    printf("Skills: %s\n", r.skills);

    // Success!
    return 0;
}