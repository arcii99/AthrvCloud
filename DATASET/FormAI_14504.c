//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for resume information
typedef struct {
    char name[50];
    char email[50];
    char phone[20];
    char education[100];
    char skills[200];
} ResumeInfo;

// Define struct for job requirements
typedef struct {
    char education[20];
    char skills[200];
} JobRequirements;

// Define function to parse resume
ResumeInfo parse_resume(char* resume_text) {
    ResumeInfo resume;
    // Extract name
    char* name = strtok(resume_text, "\n");
    strcpy(resume.name, name);
    // Extract email
    char* email = strtok(NULL, "\n");
    strcpy(resume.email, email);
    // Extract phone number
    char* phone = strtok(NULL, "\n");
    strcpy(resume.phone, phone);
    // Extract education
    char* education = strtok(NULL, "\n");
    strcpy(resume.education, education);
    // Extract skills
    char* skills = strtok(NULL, "\n");
    strcpy(resume.skills, skills);
    return resume;
}

// Define function to compare job requirements with resume
int compare_requirements(ResumeInfo resume, JobRequirements requirements) {
    // Check education requirement
    if (strcmp(resume.education, requirements.education) != 0) {
        return 0;
    }
    // Check skills requirement
    char* skill = strtok(requirements.skills, ",");
    while (skill != NULL) {
        if (strstr(resume.skills, skill) == NULL) {
            return 0;
        }
        skill = strtok(NULL, ",");
    }
    return 1;
}

int main() {
    // Example job requirements
    JobRequirements requirements = {"Bachelor's Degree", "C programming,Python,SQL"};
    // Example resume text
    char* resume_text = "John Doe\njohndoe@email.com\n123-456-7890\nBachelor's Degree in Computer Science\nC programming,Python";
    // Parse resume
    ResumeInfo resume = parse_resume(resume_text);
    // Compare resume with job requirements
    if (compare_requirements(resume, requirements)) {
        printf("Candidate meets job requirements.\n");
    } else {
        printf("Candidate does not meet job requirements.\n");
    }
    return 0;
}