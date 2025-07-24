//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: high level of detail
#include <stdio.h>
#include <string.h>

// Define global constants for maximum length of name, email and skills
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_SKILLS_LENGTH 100

// Define structure for storing applicant information
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char skills[MAX_SKILLS_LENGTH];
} Applicant;

// Define function for parsing resume and populating applicant structure
Applicant parseResume(char *resume) {
    Applicant applicant;
    char *token;
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char skills[MAX_SKILLS_LENGTH];
    
    // Use strtok function to tokenize the resume string
    // and extract relevant information
    token = strtok(resume, "\n");
    sscanf(token, "%s %s", name, email);
    strcpy(applicant.name, name);
    strcpy(applicant.email, email);
    
    token = strtok(NULL, "\n");
    strcpy(applicant.skills, token);
    
    return applicant;
}

int main() {
    char resume[] = "John Smith\njohn.smith@email.com\nC++, Java, Python";
    Applicant applicant = parseResume(resume);
    
    printf("Name: %s\n", applicant.name);
    printf("Email: %s\n", applicant.email);
    printf("Skills: %s\n", applicant.skills);
    
    return 0;
}