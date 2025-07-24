//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a resume
typedef struct {
    char name[100];
    char email[100];
    char education[100];
    char experience[100];
} resume_t;

int main() {
    // Create an array to hold up to 10 resumes
    resume_t resumes[10];
    
    // Prompt the user to enter a resume
    printf("Enter your name: ");
    fgets(resumes[0].name, 100, stdin);
    printf("Enter your email: ");
    fgets(resumes[0].email, 100, stdin);
    printf("Enter your education: ");
    fgets(resumes[0].education, 100, stdin);
    printf("Enter your experience: ");
    fgets(resumes[0].experience, 100, stdin);
    
    // Print out the entered information
    printf("\nName: %s", resumes[0].name);
    printf("Email: %s", resumes[0].email);
    printf("Education: %s", resumes[0].education);
    printf("Experience: %s", resumes[0].experience);
    
    return 0;
}