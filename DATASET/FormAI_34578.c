//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: light-weight
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// Define a structure to represent a resume
typedef struct {
    char name[50];
    char email[50];
    char education[50];
    char experience[100];
} Resume;

// Function to parse a resume
Resume parse_resume(char *resume_text) {
    Resume resume;
    char *delimiter = "\n";
    char *token = strtok(resume_text, delimiter);
    while (token != NULL) {
        if (strstr(token, "Name: ")) {
            strcpy(resume.name, token+strlen("Name: "));
        } else if (strstr(token, "Email: ")) {
            strcpy(resume.email, token+strlen("Email: "));
        } else if (strstr(token, "Education: ")) {
            strcpy(resume.education, token+strlen("Education: "));
        } else if (strstr(token, "Experience: ")) {
            strcpy(resume.experience, token+strlen("Experience: "));
        }
        token = strtok(NULL, delimiter);
    }
    return resume;
}

int main() {
    // Sample resume text
    char *resume_text = "Name: John Doe\nEmail: john.doe@example.com\nEducation: Bachelor of Science in Computer Science\nExperience: 3 years as a software developer";

    // Parse the resume text
    Resume resume = parse_resume(resume_text);

    // Print the details of the resume
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);

    return 0;
}