//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: authentic
#include <stdio.h>
#include <string.h>

// Struct for storing resume information
struct Resume {
    char name[50];
    char email[50];
    char education[100];
    char skills[200];
    char experience[300];
};

int main() {
    struct Resume resume;
    
    // Prompt user for their Nane
    printf("Enter your full name: ");
    fgets(resume.name, 50, stdin);
    printf("\n");
    
    // Prompt user for their email
    printf("Enter your email: ");
    fgets(resume.email, 50, stdin);
    printf("\n");
    
    // Prompt user for their educational background
    printf("Enter your education: ");
    fgets(resume.education, 100, stdin);
    printf("\n");
    
    // Prompt user for their skills
    printf("Enter your skills: ");
    fgets(resume.skills, 200, stdin);
    printf("\n");
    
    //Prompt user for their work experience
    printf("Enter your work experience: ");
    fgets(resume.experience, 300, stdin);
    printf("\n");
    
    // Output the parsed information
    printf("Name: %s\n", strtok(resume.name, "\n"));
    printf("Email: %s\n", strtok(resume.email, "\n"));
    printf("Education: %s\n", strtok(resume.education, "\n"));
    printf("Skills: %s\n", strtok(resume.skills, "\n"));
    printf("Experience: %s\n", strtok(resume.experience, "\n"));
    
    return 0;
}